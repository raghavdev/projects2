<?php

function digital_core_data_collections_create($parameters) {

  $collectionData = array();

  if(array_key_exists("items", $parameters)) {
    //decode the item data
    $item_ids = json_decode($parameters['items']);
    $collectionData['field_collection_data'] = $item_ids;
  }

  if(!array_key_exists("title", $parameters)) {
    return "Error: Title missing";
  }

  if(!array_key_exists("uid", $parameters)) {
    return "Error: User Id (uid) missing";
  }

  if(!array_key_exists("user_bin", $parameters)) {
    $parameters['user_bin'] = 0;
  }

  $collectionData['field_user_bin'] = $parameters['user_bin'];
  $collectionData['title'] = $parameters['title'];
  $collectionData['uid'] = $parameters['uid'];

  $entity = tom_create_drupal_entity('node', $parameters['type'],
          $collectionData);

  return tom_dedrupalize_fields($entity);
}

function digital_core_data_collections_read($parameters) {

  if(array_key_exists("collection_id", $parameters)) {
    $entity = array_values(entity_load('node', array($parameters['collection_id'])));
    return tom_dedrupalize_fields($entity);
  }
  else if(array_key_exists ("user_id", $parameters)) {

    if(array_key_exists("bin", $parameters)) {
      $user_bin_id = digital_core_data_collections_get_user_bin_id($parameters['type'], $parameters['user_id']);

      $bin = array_values(entity_load('node', array($user_bin_id)));

      $bin = tom_dedrupalize_fields($bin[0]);

      //the collection data field can not be a string must be an array
      //the dedrupalize will collapase it into a string if its singular
      //make it back into an array
      if(array_key_exists("asset_collection_data", $bin) && !is_array($bin['asset_collection_data'])) {
        $bin['asset_collection_data'] = array($bin['asset_collection_data']);

        //its causing empty values to make their way in, clean those
        foreach($bin['asset_collection_data'] as $id => $bindata) {
          if($bindata == "") {
            unset($bin['asset_collection_data'][$id]);
          }
        }
      }
      else if(array_key_exists("collection_data", $bin) && !is_array($bin['collection_data'])) {
        $bin['collection_data'] = array($bin['collection_data']);
        foreach($bin['collection_data'] as $id => $bindata) {
          if($bindata == "") {
            unset($bin['collection_data'][$id]);
          }
        }
      }

      //if data is included remove it, its unndeded
      if(array_key_exists("data", $bin)) {
        unset($bin['data']);
      }

      return array("total" => 1, "count" => 1, "results" => array($bin));
    }
    else {

      $entities = array_values(digital_core_data_collections_get_user_collections($parameters['type'], $parameters['user_id']));

      foreach($entities as $idx => $entity) {
        $entities[$idx] = tom_dedrupalize_fields($entity);

        if($entities[$idx]['user_bin'] == 1) {
          unset($entities[$idx]);
        }

        if(array_key_exists("data", $entities[$idx])) {
          unset($entities[$idx]['data']);
        }
      }

      return array("total" => count($entities), "count" => count($entities), "results" => $entities);
    }
  }

  return array();
}

function digital_core_data_collections_update($id, $parameters) {

  //remove nid if its in the parameters
  if(array_key_exists("nid", $parameters)) {
    unset($parameters['nid']);
  }

  //remove the asset data if its empty this causes an error
  if(array_key_exists("asset_collection_data", $parameters) && $parameters['asset_collection_data'] == "") {
    unset($parameters['asset_collection_data']);
  }

  $data = tom_drupalize_fields('node', $parameters['type'], $parameters);

  $return_data = tom_update_drupal_entity($id, "node", $data);

  $return = tom_dedrupalize_fields($return_data, "node", $parameters['type']);

  if(sizeof($return) == 0) {
    services_error("Error updating collections", 500);
    return false;
  }
  else {
    return $return;
  }
}

function digital_core_data_collections_delete($id) {
  return tom_delete_drupal_entity($id, "node", "collection");
}

//get the collections entities that the user is the author of
function digital_core_data_collections_get_user_collections($type, $uid) {
  //use the author of the collection node as the signal that this is their collection

  //TODO remove the bin from this list!

//  $collection_ids = db_select("node")
//                      ->fields("node", array("nid"))
//                      ->condition("uid", $uid)
//                      ->condition("type", $type)
//                      ->execute()
//                      ->fetchCol();

  $query = db_select("node")
          ->fields("node", array("nid"));
  $query->addJoin("inner", "field_data_field_user_bin", "ub", "node.nid = ub.entity_id");
  $query->condition("ub.field_user_bin_value", 0);
  $query->condition("uid", $uid);
  $query->condition("type", $type);
  $collection_ids = $query->execute()
                      ->fetchCol();

  return node_load_multiple($collection_ids);
}

function digital_core_data_collections_get_shared_collections($uid) {

}

function digital_core_data_collections_get_user_bin_id($type, $uid) {
  $query = db_select("node")
            ->fields("node", array("nid"));

  $query->addJoin("inner", "field_data_field_user_bin", "ub", "node.nid = ub.entity_id");
  $query->condition("ub.field_user_bin_value", 1);
  $query->condition("node.uid", $uid);
  $query->condition("node.type", $type);

  $binid = $query->execute()->fetchField();

  if(!$binid) {
    //create the bin
    //there should always be a bin for the user
    $data = digital_core_data_collections_create(array("user_bin" => 1, "title" => "bin", "uid" => $uid, "type" => $type));

    if(array_key_exists("nid", $data)) {
      return $data['nid'];
    }
    return false;
  }

  return $binid;
}