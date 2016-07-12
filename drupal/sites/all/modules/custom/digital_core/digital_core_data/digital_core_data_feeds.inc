<?php

function digital_core_data_feeds_create($feed_name, $owner, $data) {
  $node = new stdClass();
  $node->title = $feed_name;
  $node->type = "product_feed";
  node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
  $node->uid = $owner->uid;
  $node->field_feed_owner['und'][0] = $owner->uid;
  $node = node_submit($node);
  node_save($node);

  return $node;
}

function digital_core_data_feeds_read($feed_id_data, $parameters) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_products');

  $feed = digital_core_data_feeds_get_feed($feed_id_data);

  //get the list of fields that are to be returned
  $returned_fields = array();
  if(count($feed->field_included_fields) > 0) {
    foreach ($feed->field_included_fields['und'] as $field) {
      $returned_fields[] = $field['value'];
    }
  }

  //get the list of renditions to return for this feed
  $returned_renditions = array();
  if(count($feed->field_included_renditions) > 0) {
    foreach ($feed->field_included_renditions['und'] as $field) {
      $returned_renditions[] = $field['value'];
    }
  }

  //split off the section from the product list that corresponds to this page

  //compile the list for the product data that is going to be sent along
  $product_ids = array();
  if(array_key_exists("und", $feed->field_product_filter)){
    foreach ($feed->field_product_filter['und'] as $id) {
      $product_ids[] = $id['target_id'];
    }
  }

  //break the list up into the pages specified by the size
  $pages = array_chunk($product_ids, $parameters['perPage']);

  //cant get an actual total off a filtered list due to how its requested
  //return the count from the list of products allowed
  $total = count($product_ids);

  $searchParams = array();
  if(count($product_ids) > 0) {
    $searchParams = array("nid" => $pages[$parameters['page']],
                          "type" => "product_details");
  }
  else {
    $searchParams = array("page" => $parameters['page'],
                        "perPage" => $parameters['perPage'],
                        "type" => "product_details"
    );

    //get a total from drupal
    $total = db_select("node")
      ->fields("node", array('nid'))
      ->condition("type", "product_details")
      ->execute()
      ->rowCount();
  }
  
  //send off the page we are on of ids to the read process
  $returned = digital_core_data_products_read($searchParams, array("nid"), $returned_fields, $returned_renditions);

  $returned['total'] = $total;

  return $returned;
}

function digital_core_data_feeds_update($feed_id_data, $op, $nid, $data) {
  $feed = digital_core_data_feeds_get_feed($feed_id_data);

  //get the feed name, the standard is name_feed
  preg_match("/(.*?)_feed/", $feed->title, $matches);

  if($matches) {
    $feed_name = $matches[1];
  }

  if(!$feed) {
    return false;
  }

  //do a little manipulation of the vlaue
  if($op == "set") {
    if($data[$feed_name . "_include"]) {
      $op = 'add';
    }
    else {
      $op = "remove";
    }

    $data = $nid;
  }


  switch($op) {
    case "add": {
      if(!is_array($data)) {
        $data = array($data);
      }

      foreach($data as $nid) {
        //add the item to the reference
        $feed->field_product_filter['und'][] = array("target_id" => $nid);

        digital_core_data_update_solr_direct("node", $feed_name . '_include', $nid, true);
      }
      node_save($feed);
      break;
    }
    case "remove": {
      //remove the item from the reference

      if(!is_array($data)) {
        $data = array($data);
      }

      foreach($data as $nid) {
        //much more efficient removing this from the database directly
        db_delete("field_data_field_product_filter")
          ->condition($nid)
          ->execute();

        db_delete("field_revision_field_product_filter")
          ->condition($nid)
          ->execute();


        digital_core_data_update_solr_direct("node", $feed_name . '_include', $nid, false);
      }

      break;
    }
    case "setall": {
      //set the set to what is specified
      $nids = array();
      foreach($data as $nid) {
        $nids[]['target_id'] = $nid;
      }

      $feed->field_product_filter['und'] = $nids;
      node_save($feed);
      break;
    }
  }
}

function digital_core_data_feeds_get_feed($feed_id_data) {
  //find the entity id from the feed owner name passed
  if(!is_numeric($feed_id_data)) {
    //the id is the name of the user that owns the feed
    $owner = user_load_by_name($feed_id_data);

    //find the feed this owner is related to
    $feed_id_data = db_select("field_data_field_feed_owner")
              ->fields("field_data_field_feed_owner", array("entity_id"))
              ->condition("field_feed_owner_uid", $owner->uid)
              ->execute()
              ->fetchField();
  }

  if(!$feed_id_data) {
    return false;
  }

  //load the feed object
  $feed = node_load($feed_id_data);

  return $feed;
}
