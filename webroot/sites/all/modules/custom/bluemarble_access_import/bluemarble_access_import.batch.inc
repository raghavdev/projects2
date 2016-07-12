<?php

/**
 * Batch Operation: Bluemarble Access Import Support Entities.
 */
function bluemarble_access_import_batch_process_support_entities(&$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['limit']    = 5;
    $context['sandbox']['max']      = (int) db_select('bluemarble_access_products', 'bap')
      ->countQuery()
      ->execute()
      ->fetchField();
  }
  $sandbox = &$context['sandbox'];

  $query = db_select('bluemarble_access_products', 'bap');
  $query->fields('bap');
  $query->range($sandbox['progress'], $sandbox['limit']);

  $results = $query->execute();

  $entity_maps = variable_get('bluemarble_access_import_support_entity_maps', array(
    'OrgCertifier' => array(
      'entity_type' => 'taxonomy_term',
      'bundle'      => 'agency_organic',
      'field'       => 'name',
      'field_table' => 'taxonomy_term_data',
    ),
  ));

  while (($row = $results->fetchAssoc())) {
    foreach ($entity_maps as $csv_column => $entity_map) {
      if (
        !empty($row[$csv_column])
        && drupal_strtolower($row[$csv_column]) != 'null'
      ) {
        $created = _bluemarble_access_import_batch_create_support_entity($row[$csv_column], $entity_map, array(
          'column' => $csv_column,
          'record' => $row,
        ));

        if ($created) {
          if (!isset($context['results']['support_entities']['created'][$entity_map['entity_type']][$entity_map['bundle']])) {
            $context['results']['support_entities']['created'][$entity_map['entity_type']][$entity_map['bundle']] = 0;
          }
          $context['results']['support_entities']['created'][$entity_map['entity_type']][$entity_map['bundle']]++;
        }
      }
    }
    $sandbox['progress']++;
  }

  if (empty($sandbox['max'])) {
    $context['finished'] = 1;
  }
  else {
    $context['finished'] = $sandbox['progress'] / $sandbox['max'];
  }
}

/**
 * Batch Operation: Bluemarble Access Import Products.
 */
function bluemarble_access_import_batch_process_products(&$context) {
  if (!isset($context['sandbox']['max'])) {
    $context['results'] = array();
    $context['sandbox']['max'] = (int) db_select('bluemarble_access_products', 'bap')
      ->countQuery()
      ->execute()
      ->fetchField();
    $context['sandbox']['pos'] = 0;
  }

  $limit = 30;
  // We select the first 30 records, we don't order them because our columns
  // are not indexed. We delete these records at the end, so our next iteration
  // will have 30 new records.
  $records = db_select('bluemarble_access_products', 'bap')
    ->fields('bap')
    ->range(0, $limit)
    ->execute();
  $upcs = array();
  $rows = array();
  foreach ($records as $row) {
    $rows[] = $row;
    $upcs[] = preg_replace('/[^0-9]/', '', $row->UPC);

    $context['sandbox']['pos']++;
  }

  if (!empty($upcs)) {
    $nodes         = bluemarble_access_import_get_or_create_products($upcs);
    $updated_nodes = array();

    foreach ($nodes as $key => $node) {
      if ($node && isset($rows[$key])) {
        $row = $rows[$key];
        bluemarble_access_import_update_product($node, $row);
        $updated_nodes[] = $node->nid;
      }
    }

    $context['message'] = t('Updated @count of @total products.', array(
      '@count' => $context['sandbox']['pos'],
      '@total' => $context['sandbox']['max'],
    ));

    // Remove the imported records.
    db_delete('bluemarble_access_products')
      ->condition('UPC', $upcs)
      ->execute();
  }

  if ($context['sandbox']['pos'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['pos'] / $context['sandbox']['max'];
  }
}

/**
 * Batch Finished callback: Bluemarble Access Import Products.
 */
function bluemarble_access_import_batch_finished($success, $results, $operations) {
  if ($success) {

    if (!empty($results['support_entities']['created'])) {
      $message    = t('Created support entities:');
      $list_items = [];
      foreach ($results['support_entities']['created'] as $entity_type => $bundles) {
        foreach ($bundles as $bundle => $entity_count) {
          $list_items[] = t('@e.@b: @c', array(
            '@e' => $entity_type,
            '@b' => $bundle,
            '@c' => $entity_count,
          ));
        }
      }
      drupal_set_message($message . theme('item_list', array('items' => $list_items)));
    }

    drupal_set_message(t('Completed updates.'));
  }
  else {
    drupal_set_message(t('Import failed.'), 'error');
  }
}

function _bluemarble_access_import_batch_create_support_entity($value, $map, $context) {
  $query = db_select($map['field_table'], 'tbl');
  $query->condition('tbl.' . $map['field'], $value);

  drupal_alter('bmb_csv_import_support_entity_search_query', $query, $value, $map, $context);

  if (empty($query)) {
    return FALSE;
  }

  $existing = (int) $query->countQuery()->execute()->fetchField();

  if (empty($existing)) {
    // Create stuff here
    $entity_info = entity_get_info($map['entity_type']);

    $bundle_key = 'bundle';
    if (!empty($entity_info['entity keys']['bundle'])) {
      $bundle_key = $entity_info['entity keys']['bundle'];
    }

    $init_values = array(
      $map['field'] => $value,
      $bundle_key => $map['bundle'],
    );

    if (strpos($map['field_table'], 'field_data_') === 0) {
      $init_values[$map['field']] = array(LANGUAGE_NONE => array($value));
    }

    drupal_alter('bmb_csv_import_support_entity_create_init_values', $init_values, $value, $map, $context);

    $entity = entity_create($map['entity_type'], $init_values);
    $wrapper = entity_metadata_wrapper($map['entity_type'], $entity);
    $wrapper->save();
  }
  elseif ($existing > 1) {
    // Warn something here
  }

  return empty($existing) && !empty($entity);
}
