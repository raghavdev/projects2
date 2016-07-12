<?php
/**
 * @file
 * Contains the MacolaDrupalImporter class.
 */

class MacolaDrupalImporter {

  protected $connector;

  /**
   * @param \MacolaConnector $connector
   *    An instance of a MacolaConnector object.
   */
  public function __construct(MacolaConnector $connector) {
    $this->connector = $connector;
  }

  /**
   * Imports categories from Macola into Drupal.
   */
  public function importCategories() {
    $vocab = 'category';
    $categories = $this->connector->getCategories();
    if (count($categories)) {
      $macola_ids = array();
      foreach ($categories as $category) {
        $macola_ids[] = $category->id;
      }

      // Track which terms were created/updated so others in the vocabulary can
      // be deleted.
      $updated_tids = array();

      $terms = $this->getOrCreateTerms($vocab, $macola_ids);
      foreach ($terms as $key => $term) {
        $category = $categories[$key];
        if ($this->termNeedsUpdated($term, $category)) {
          $this->updateTermFromMacola($term, $category);
        }
        $updated_tids[] = $term->tid;
      }
      // @todo this probably needs to be removed based on the fact that there
      // will probably be more Drupal categories then exist in Macola.
      // However, every Drupal Category needs to have a mapping to a Macola
      // category so that products added in Drupal are created in Macola and
      // the category is a required field.
      $this->deleteMissingTerms($vocab, $updated_tids);
    }
  }

  /**
   * Imports material cost types from Macola into Drupal.
   */
  public function importMaterialCostTypes() {
    $vocab = 'material_cost_type';
    $types = $this->connector->getMaterialCostTypes();
    if (count($types)) {
      $macola_ids = array();
      foreach ($types as $type) {
        $macola_ids[] = $type->id;
      }

      // Track which terms were created/updated so others in the vocabulary can
      // be deleted.
      $updated_tids = array();

      $terms = $this->getOrCreateTerms($vocab, $macola_ids);
      foreach ($terms as $key => $term) {
        $type = $types[$key];
        if ($this->termNeedsUpdated($term, $type)) {
          $this->updateTermFromMacola($term, $type);
        }
        $updated_tids[] = $term->tid;
      }

      $this->deleteMissingTerms($vocab, $updated_tids);
    }
  }

  /**
   * Imports locations from Macola into Drupal.
   */
  public function importLocations() {
    $vocab = 'warehouse';
    $locations = $this->connector->getLocations();
    if (count($locations)) {
      $macola_ids = array();
      foreach ($locations as $location) {
        $macola_ids[] = $location->id;
      }

      // Track which terms were created/updated so others in the vocabulary can
      // be deleted.
      $updated_tids = array();

      $terms = $this->getOrCreateTerms($vocab, $macola_ids);
      foreach ($terms as $key => $term) {
        $location = $locations[$key];
        if ($this->termNeedsUpdated($term, $location)) {
          $this->updateTermFromMacola($term, $location);
        }
        $updated_tids[] = $term->tid;
      }

      $this->deleteMissingTerms($vocab, $updated_tids);
    }
  }

  /**
   * Imports users from Macola into Drupal.
   */
  public function importUsers() {
    $vocab = 'buyer';
    $users = $this->connector->getUsers();
    if (count($users)) {
      $macola_ids = array();
      foreach ($users as $user) {
        $macola_ids[] = $user->id;
      }

      // Track which terms were created/updated so others in the vocabulary can
      // be deleted.
      $updated_tids = array();

      $terms = $this->getOrCreateTerms($vocab, $macola_ids);
      foreach ($terms as $key => $term) {
        $user = $users[$key];
        if ($this->termNeedsUpdated($term, $user)) {
          $this->updateTermFromMacola($term, $user);
        }
        $updated_tids[] = $term->tid;
      }

      $this->deleteMissingTerms($vocab, $updated_tids);
    }
  }

  /**
   * Queue updates to products from Macola.
   *
   * @param int
   *   A unix timestamp
   */
  public function queueProductUpdates() {
    $page = 1;

    do {
      $products = $this->connector->searchProducts($page);

      // Log results
      if ($page == 1) {
        $message  = 'Started queuing @c Macola product(s). Pages @p. Per page @i';
        $msg_vars = array(
          '@c' => $products->getTotal(),
          '@p' => $products->getPageCount(),
          '@i' => count($products),
        );
        watchdog('macola_connect', $message, $msg_vars);
      }

      if (count($products)) {
        foreach ($products as $product) {
          // TODO: products that have the same item numbers could "fall through
          // the cracks" here
          db_merge('macola_connect_products')
            ->key(array('id' => $product->id))
            ->fields((array) $product)
            ->execute();
        }
      }

      $page++;
    } while ($products->getPageCount() >= $page);

    $count    = db_select('macola_connect_products', 'mcp')
      ->countQuery()
      ->execute()
      ->fetchField();
    $message  = 'Queued @c Macola product(s).';
    $msg_vars = array('@c' => $count);
    watchdog('macola_connect', $message, $msg_vars);

    $this->startBackgroundProcess();
  }

  private function startBackgroundProcess() {
    $bgp_handle = variable_get('macola_connect_background_process_sync_products_running_handle', FALSE);
    if (!empty($bgp_handle)) {
      $running = db_select('background_process', 'bgp')
        ->condition('bgp.handle', $bgp_handle)
        ->countQuery()
        ->execute()
        ->fetchField();
      if (empty($running)) {
        $bgp_handle = FALSE;
      }
    }
    if (empty($bgp_handle)) {
      background_process_start('macola_connect_background_process_sync_products');
    }
  }

  /**
   * Import a given product from Macola into Drupal.
   *
   * @param int $item_num
   *    The Item Number for the product to be imported.
   */
  public function importProduct($item_num) {
    $type = 'product_details';
    $nodes = $this->getOrCreateNodes($type, array($item_num));
    $node = $nodes[0];
    $product = db_select('macola_connect_products', 'p')
      ->fields('p')
      ->condition('p.item_no', $item_num)
      ->execute()
      ->fetchObject();
    $this->updateProductFromMacola($node, $product);
  }

  /**
   * Creates a product from Drupal in Macola.
   *
   * @param object $node
   *   The Drupal product node.
   *
   * @return boolean
   */
  public function createProduct($node) {
    $product = $this->buildProductForMacola($node);
    $result = $this->connector->createProduct($product);
    if ($result) {
      $node->field_macola_id[LANGUAGE_NONE][0]['value'] = $product->id;
      $node->macola_connect_export = TRUE;
      node_save($node);
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Updates a product from Drupal in Macola.
   *
   * @param object $node
   *   The Drupal product node.
   *
   * @return boolean
   */
  public function updateProduct($node) {
    $product = $this->buildProductForMacola($node);
    return $this->connector->updateProduct($product);
  }

  /**
   * Gets existing nodes by Item Number and creates stub nodes for missing ones.
   *
   * @param $type string
   *    The content type machine name to get or create nodes.
   * @param $item_nums array
   *    The unique item numbers to lookup nodes by.
   *
   * @return array
   *    An array of node objects, in the same order as the list of Macola ids.
   */
  public function getOrCreateNodes($type, $item_nums) {
    $ret = array();

    // Find existing nodes by the Macola id.
    $nids_by_item_num = $this->findEntitiesByItemNumber('node', $type, $item_nums);
    $nids = array_values($nids_by_item_num);
    $nodes = node_load_multiple($nids);

    // Loop through the original Macola ids, so our resulting array is in the
    // same order.
    foreach ($item_nums as $item_num) {
      if (isset($nids_by_item_num[$item_num])) {
        $nid = $nids_by_item_num[$item_num];
        $ret[] = $nodes[$nid];
      }
      else {
        $ret[] = entity_create('node', array(
          'is_new' => TRUE,
          'title' => '',
          'type' => $type,
          'language' => LANGUAGE_NONE,
          'uid' => 0, // TODO: should be owned by Anonymous?
        ));
      }
    }

    return $ret;
  }

  /**
   * Gets existing terms by Macola id and creates stub terms for missing ones.
   *
   * @param $vocab string
   *    The vocabulary machine name to get or create terms in.
   * @param $macola_ids array
   *    The Macola unique ids to lookup terms by.
   *
   * @return array
   *    An array of term objects, in the same order as the list of Macola ids.
   */
  public function getOrCreateTerms($vocab, $macola_ids) {
    $ret = array();

    // Get the vocabularies id.
    $all_vocabularies = taxonomy_vocabulary_get_names();
    $vid = $all_vocabularies[$vocab]->vid;

    // Find existing terms by the Macola id.
    $tids_by_macola_id = $this->findEntitiesByMacolaId('taxonomy_term', $vocab, $macola_ids);
    $tids = array_values($tids_by_macola_id);
    $terms = taxonomy_term_load_multiple($tids);

    // Loop through the original Macola ids, so our resulting array is in the
    // same order.
    foreach ($macola_ids as $macola_id) {
      if (isset($tids_by_macola_id[$macola_id])) {
        $tid = $tids_by_macola_id[$macola_id];
        $ret[] = $terms[$tid];
      }
      else {
        $ret[] = (object) array(
          'is_new' => TRUE,
          'name' => '',
          'description' => '',
          'vid' => $vid,
        );
      }
    }

    return $ret;
  }

  /**
   * Cleanup any terms that are not in the provided list for a vocabulary.
   *
   * @param $vocab string
   *    The vocabulary machine name to get or create terms in.
   * @param $tids array
   *    List of terms ids that should not be deleted.
   */
  public function deleteMissingTerms($vocab, $tids) {
    // Get the vocabularies id.
    $all_vocabularies = taxonomy_vocabulary_get_names();
    $vid = $all_vocabularies[$vocab]->vid;

    $missing_tids = db_select('taxonomy_term_data', 'td')
      ->fields('td', array('tid'))
      ->condition('td.vid', $vid)
      ->condition('td.tid', $tids, 'NOT IN')
      ->execute()
      ->fetchCol();
    foreach ($missing_tids as $tid) {
      try {
        taxonomy_term_delete($tid);
      }
      catch (Exception $e) {
        // Do nothing, the error has already been logged.
      }
    }
  }

  /**
   * Determine if the term needs to be saved.
   *
   * @param $term object
   *    The Drupal taxonomy term object. This could be a stub without a tid yet.
   * @param $apiEntity object
   *    An object representing the entity from Macola.
   *
   * @return bool
   *    TRUE if the term needs to be saved, otherwise FALSE.
   */
  public function termNeedsUpdated($term, $apiEntity) {
    // The term needs updated if:
    // - it hasn't been saved yet
    // - the name doesn't match
    // - the description doesn't match
    // - the term doesn't have a macola id
    $ret = FALSE;
    if (isset($term->is_new) && $term->is_new) {
      $ret = TRUE;
    }
    if ($term->name != $apiEntity->description) {
      $ret = TRUE;
    }
    if (!isset($term->field_macola_id[LANGUAGE_NONE][0]['value'])) {
      $ret = TRUE;
    }
    if (
      !isset($term->field_macola_name[LANGUAGE_NONE][0]['value'])
      || $term->field_macola_name[LANGUAGE_NONE][0]['value'] != $apiEntity->name
    ) {
      $ret = TRUE;
    }

    return $ret;
  }

  /**
   * Updates term data using data from Macola.
   *
   * @param $term object
   *    The Drupal taxonomy term object. This could be a stub without a tid yet.
   * @param $apiEntity object
   *    An object representing the entity from Macola.
   *
   * @return int
   *    Status constant indicating whether term was inserted (SAVED_NEW) or updated
   *    (SAVED_UPDATED). When inserting a new term, $term->tid will contain the
   *    term ID of the newly created term.
   */
  public function updateTermFromMacola($term, $apiEntity) {
    if (isset($apiEntity->name)) {
      $term->field_macola_name[LANGUAGE_NONE][0]['value'] = $apiEntity->name;
    }
    if (isset($apiEntity->description)) {
      $term->name = $apiEntity->description;
    }
    if (isset($apiEntity->id)) {
      $term->field_macola_id[LANGUAGE_NONE][0]['value'] = $apiEntity->id;
    }
    return taxonomy_term_save($term);
  }

  /**
   * @param $node object
   *    The Drupal node object. This could be a stub without a nid yet.
   * @param $apiEntity object
   *    An object representing the entity from Macola.
   *
   * @return int
   *    Status constant indicating whether node was inserted (SAVED_NEW) or updated
   *    (SAVED_UPDATED). When inserting a new node, $node->nid will contain the
   *    node ID of the newly created node.
   */
  public function updateProductFromMacola($node, $apiEntity) {
    $mappings = bluemarble_staging_field_mappings_load('macola_connect', $node->type);
    $node->macola_connect_import = TRUE;
    $wrapper = entity_metadata_wrapper('node', $node);

    $workflow_mappings = array();
    $workflow_fields = array();

    if (module_exists('workflow')) {
      $workflow_fields = array_keys(_workflow_info_fields($node, 'node', 'product_details'));
    }

    foreach ($mappings as $mapping) {
      if (!empty($mapping->customProcessingArgs)) {
        $mapping->customProcessingArgs = unserialize($mapping->customProcessingArgs);
      }

      $fromField = $mapping->fromField;
      $toField = $mapping->toField;
      // Skip workflow fields, those are handled last.
      if (in_array($toField, $workflow_fields)) {
        $workflow_mappings[$toField] = $mapping;
        continue;
      }
      $fromAlt = $mapping->fromAlt;

      $value = NULL;
      if (isset($apiEntity->{$fromField})) {
        $value = $apiEntity->{$fromField};
      }
      else if (isset($apiEntity->{$fromAlt})) {
        $value = $apiEntity->{$fromAlt};
      }

      $function = $mapping->customProcessing;
      if (function_exists($function)) {
        $context = array(
          'mapping'   => $mapping,
          'apiEntity' => $apiEntity,
          'importer'  => $this,
        );
        $value = $function($value, 'import', $wrapper, $context);
      }

      if ($value) {
        try {
          $wrapper->{$toField}->set($value);
        }
        catch(Exception $e) {
          $message  = 'Failed to set value for @f (Macola ID: @m, Item No.: @i). <br /> Value = <pre>@v</pre>';
          $msg_vars = array(
            '@f' => $toField,
            '@m' => $apiEntity->id,
            '@i' => $apiEntity->item_no,
            '@v' => print_r($value, TRUE),
          );
          watchdog('macola_connect', $message, $msg_vars, WATCHDOG_ERROR);
          watchdog_exception('macola_connect', $e);
          if (in_array($fromField, array('id', 'item_no'))) {
            throw $e;
          }
        }
      }
    }

    $wrapper->save();

    // Workflow transitions should be done after the entity has been created.
    foreach ($workflow_fields as $toField) {
      $mapping = $workflow_mappings[$toField];
      $fromField = $mapping->fromField;
      $fromAlt = $mapping->fromAlt;

      if (!empty($mapping->customProcessingArgs)) {
        $mapping->customProcessingArgs = unserialize($mapping->customProcessingArgs);
      }

      $value = NULL;
      if (isset($apiEntity->{$fromField})) {
        $value = $apiEntity->{$fromField};
      }
      else if (isset($apiEntity->{$fromAlt})) {
        $value = $apiEntity->{$fromAlt};
      }

      $function = $mapping->customProcessing;
      if (function_exists($function)) {
        $context = array(
          'mapping'   => $mapping,
          'apiEntity' => $apiEntity,
          'importer'  => $this,
        );
        $value = $function($value, 'import', $wrapper, $context);
      }

      if ($value) {
        sudo_workflow_transition_to_state('node', $node, $toField, $value, 'Update from Macola');
      }
    }
  }

  /**
   * Find entities by their Macola id.
   *
   * @param string $entity_type
   *   The entity type. 'node'
   * @param $bundle
   * @param $macola_ids
   *
   * @return array
   */
  public function findEntitiesByMacolaId($entity_type, $bundle, $macola_ids) {
    if (empty($macola_ids)) {
      return array();
    }

    $query = db_select('field_data_field_macola_id', 'mi')
      ->condition('mi.entity_type', $entity_type)
      ->condition('mi.bundle', $bundle)
      ->condition('mi.deleted', 0)
      ->condition('mi.field_macola_id_value', $macola_ids);
    $query->addField('mi', 'field_macola_id_value', 'macola_id');
    $query->addField('mi', 'entity_id');

    // Get the entity id keyed by Macola id.
    return $query->execute()->fetchAllKeyed();
  }

  /**
   * Find entities by their Item Number.
   *
   * @param string $entity_type
   *   The entity type. 'node'
   * @param $bundle
   * @param $item_nums
   *
   * @return array
   */
  public function findEntitiesByItemNumber($entity_type, $bundle, $item_nums) {
    if (empty($item_nums)) {
      return array();
    }

    $query = db_select('field_data_field_item_num', 'item_num')
      ->condition('item_num.entity_type', $entity_type)
      ->condition('item_num.bundle', $bundle)
      ->condition('item_num.deleted', 0)
      ->condition('item_num.field_item_num_value', $item_nums);
    $query->addField('item_num', 'field_item_num_value');
    $query->addField('item_num', 'entity_id');

    // Get the entity id keyed by Item Number.
    return $query->execute()->fetchAllKeyed();
  }

  /**
   * @param $node object
   *   The Drupal node object.
   * @param $update_fields array
   *   Optional. The fields to update. Defaults to an
   *
   * @return object
   *   A representation of the Macola product.
   */
  public function buildProductForMacola($node, $update_fields = array()) {
    $product = (object) array();

    $mappings = bluemarble_staging_field_mappings_load('macola_connect', $node->type);
    $wrapper = entity_metadata_wrapper('node', $node);

    $limit_fields = FALSE;
    if (!empty($update_fields)) {
      $limit_fields = TRUE;
      // We always need the macola id
      $update_fields[] = 'field_macola_id';
      // We always need the item number
      $update_fields[] = 'field_item_num';
    }

    foreach ($mappings as $mapping) {
      if (!empty($mapping->customProcessingArgs)) {
        $mapping->customProcessingArgs = unserialize($mapping->customProcessingArgs);
      }

      $fromField = $mapping->fromField;
      $toField = $mapping->toField;

      if ($limit_fields && !in_array($toField, $update_fields)) {
        continue;
      }

      try {
        $value = $wrapper->{$toField}->value(array('identifier' => TRUE));

        $function = $mapping->customProcessing;
        if (function_exists($function)) {
          $context = array(
            'mapping'   => $mapping,
            'node'      => $node,
            'importer'  => $this,
          );
          $value = $function($value, 'export', $wrapper, $context);
        }
      }
      catch (Exception $e) {
        watchdog_exception('macola_connect', $e);
        // Just skip this field. It could just be a bad mapping.
        continue;
      }

      if ($value) {
        try {
          $product->{$fromField} = $value;
        }
        catch(Exception $e) {
          watchdog_exception('macola_connect', $e);
          throw $e;
        }
      }
    }

    return $product;
  }

  /**
   * Exposing connector method for mapping purposes.
   *
   * @param string $item_num
   * @return \MacolaResultSet
   */
  public function getProductVendorPrices($item_num) {
    return $this->connector->getProductVendorPrices($item_num);
  }

  /**
   * Exposing connector method for mapping purposes.
   *
   * @param string $item_num
   * @param string $vendor_num
   * @return \MacolaResultSet
   */
  public function getProductVendorPrice($item_num, $vendor_num) {
    return $this->connector->getProductVendorPrice($item_num, $vendor_num);
  }

  /**
   * Exposing connector method for mapping purposes.
   */
  public function createProductVendorPrice($product_vendor_price) {
    return $this->connector->createProductVendorPrice($product_vendor_price);
  }

  /**
   * Exposing connector method for mapping purposes.
   */
  public function updateProductVendorPrice($product_vendor_price) {
    return $this->connector->updateProductVendorPrice($product_vendor_price);
  }
}
