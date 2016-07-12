<?php

function digital_core_data_assets_create($file_data) {

  //check if this file actually already exists on the server
  //we will just pass the file reference if it already exists
  $fid = db_select("file_managed")
          ->fields("file_managed", array('fid'))
          ->condition("filename", $file_data['file_name'])
          ->execute()
          ->fetchField();

  if($fid) {
    $file = file_load($fid);
  }
  else {
    $file = digital_core_assets_create_asset($file_data);
  }

  //if there is an nid, then reference this asset to that product
  if(array_key_exists("nid", $file_data)) {
    digital_core_data_assets_relation_asset_product($file, $file_data['image_type'], $file_data['nid']);
  }

  //invoke rules that can hook into here
//  rules_invoke_event('digital_core_assets_upload_asset', $file_data['image_type'],
//          $file->fid, $file_data['ein'], digital_core_assets_get_image_type($file));

  if(!$file) {
    return false;
  }
  return array("count" => 1, "total" => 1, "results" => array($file));
}

function digital_core_data_assets_read($parameters, $searched_fields = false) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');

  if(!$searched_fields) {
    $searched_fields = array("name", "field_uploaded_by", "field_creator", "field_copyright_notice",
        "field_color_mode", "field_keywords", "field_description", "field_creator", 'field_model', 'field_title', "field_alt");
  }

  //if a collection is being queried we need to do special handling
  if(array_key_exists("collection", $parameters)) {

    //$product_ids = digital_core_data_products_read($parameters['collection_id']);
    $data = tom_get_entities("node", array("nid" => $parameters['collection']), "asset_collection");

    unset($parameters['collection']);

    if($data['count'] > 0) {

      $fids = array();
      if(array_key_exists('und', $data['results'][0]['field_asset_collection_data'])) {
        foreach($data['results'][0]['field_asset_collection_data']['und'] as $fid) {
          $fids[] = $fid['target_id'];
        }
      }

      $parameters['fid'] = $fids;

      if(count($fids) == 0) {
        return array("count" => 0, "total" => 0, "results" => array());
      }

      return digital_core_data_assets_read($parameters);
    }

    return array("count" => 0, "total" => 0, "results" => array());
  }

  //categories need to be able to search for all children also
  //so this must convert the category filter into a categories filter
  //where it includes its children
  if(array_key_exists("asset_category", $parameters)) {

    $categories = digital_core_data_categories_parse_category_children($parameters['asset_category']);

    if($categories) {
      $parameters['asset_categories'] = $categories;
      unset($parameters['asset_category']);
    }
  }

  //have to convert the keywords into their tid values or solr wont match them
  if(array_key_exists("search", $parameters)) {

    //$vocab = taxonomy_vocabulary_machine_name_load('keyword');
    $vid = db_select("taxonomy_vocabulary")
            ->fields("taxonomy_vocabulary", array("vid"))
            ->condition("machine_name", "keywords")
            ->execute()
            ->fetchField();

    if($vid) {
      //tried to do this, worked locally but did not on staging, so using direct access
      //$term = taxonomy_get_term_by_name($parameters['search'], $vocab->vid);

      $term = db_select("taxonomy_term_data")
                ->fields("taxonomy_term_data", array("tid"))
                ->condition("name", $parameters['search'])
                ->condition("vid", $vid)
                ->execute()
                ->fetchField();

      if($term) {
        //search for the term id also
        $parameters['search'] = array($parameters['search'], $term);
      }
    }
  }

  //field keyword has to go on to a non wild card list, preventing the *KEYWORD* since it has to be a direct match to work
  $assets = simple_solr_search(array(
    'index_name'       => SOLRASSETINDEX,
    'query_parameters' => $parameters,
    'searched_fields'  => $searched_fields,
    'non_wild_fields'  => array("field_keywords"),
  ));

  //attach the url to the uri for each asset, "kenstowell [1:03 PM] gots to display it yo!"
  foreach($assets['results'] as $idx => $asset) {


    //if there isnt a assets_category key because there isnt any assignments
    //add the empty key, or the javascript freaks out
    if(!array_key_exists("asset_category", $assets['results'][$idx])) {
      $assets['results'][$idx]['asset_category'] = array();
    }

    $file_obj = file_load($asset['fid']);

    if($file_obj) {
      $url = file_create_url($file_obj->uri);

      //the amazon module seems to miss the protocol in the create url
      if(!strpos($url, 'http')) {
        $url = "http:" . $url;
      }

      $assets['results'][$idx]['url'] = $url;

      $file = "default_file";

      $cats = array();

      if(array_key_exists("field_asset_category", $assets['results'][$idx])) {
        $cats = $assets['results'][$idx]["field_asset_category"];
      }

      $assets['results'][$idx] = tom_dedrupalize_fields($assets['results'][$idx], 'file');

      //somehow the ^^^^^ function kills this key, so preserving it, and initializing if its empty
      $assets['results'][$idx]['asset_category'] = $cats;

      $assets['results'][$idx]['thumb_url'] = digital_core_assets_get_thumbnail_url($file_obj);

      if($asset['type'] == "image") {
        //look up the height and width for this image
          $meta = db_select("file_metadata")
                    ->fields("file_metadata", array("value", "name"))
                    ->condition("fid", $file_obj->fid)
                    ->execute()
                    ->fetchAllAssoc("name");

          if(array_key_exists("width", $meta)) {
            $w = unserialize($meta['width']->value);

            $assets['results'][$idx]['width'] = $w;
          }

          if(array_key_exists("height", $meta)) {
            $h = unserialize($meta['height']->value);

            $assets['results'][$idx]['height'] = $h;
          }
      }

      $assets['results'][$idx] = digital_core_data_assets_adjust_return($asset['type'], $assets['results'][$idx]);
    }
  }

  return $assets;
}

function digital_core_data_assets_update($id, $data) {
  //need to know what type of file this is
  $type = db_select("file_managed")
          ->fields("file_managed", array("type"))
          ->condition("fid", $id)
          ->execute()
          ->fetchField();

  //if there is an asset change
  if(array_key_exists("file_bytes", $data)) {

    //create the new asset
    $type = digital_core_assets_get_file_type($data['file_name']);

    //$fid = digital_core_assets_upload_asset($data);
    $file = digital_core_assets_create_asset($data);

    if($file) {
      //delete the old one
      db_delete("file_managed")
        ->condition("fid", $id)
        ->execute();

      //change the id on the new asset, switching the new id with the old one
      //kinda strange but will serve the purpose to swap the file cleanly
      db_update("file_managed")
        ->fields(array("fid" => $id))
        ->condition("fid", $file->fid)
        ->execute();
      }

      unset($data['file_name']);
      unset($data['file_bytes']);
  }

  //if there is an associated node need to update the time stamp on it that the image was changed
  if(array_key_exists("nid", $data)) {
    db_update("node")
      ->fields("changed", time())
      ->condition("nid", $data['nid'])
      ->execute();
  }

  //Ken!! keeps sending fid through as a field to update, but not updatable
  //remove it if he has, naughty ken...
  if(array_key_exists("fid", $data)) {
    unset($data['fid']);
  }

  //uid comes thru sometimes and isnt a valid for update field so remove it
  if(array_key_exists("uid", $data)) {
    unset($data['uid']);
  }

  //kinda rediculous but have to add this, for now atleast
  if($data['internal_only'] == "on") {
    $data['internal_only'] = 1;
  }
  else {
    $data['internal_only'] = 0;
  }

  //need to redrupalize the the data provided so we can save it
  $data = tom_drupalize_fields('file', $type, $data);

  $return = tom_update_drupal_entity($id, "file", $data);

  $return = tom_dedrupalize_fields($return, 'file', $type);

  //handle the strange format of the title and alt fields
  $return = digital_core_data_assets_adjust_return($type, $return);

  if(sizeof($return) == 0) {
    services_error("Error updating asset", 500);
    return false;
  }
  else {
    return array("count" => 1, "total" => 1, "results" => array($return));
  }
}

function digital_core_data_assets_delete() {

}

//applies a little handling to the data special for assets before the return
function digital_core_data_assets_adjust_return($type, $return) {

  if(is_array($return)) {
    //set the upload by
    if(array_key_exists("owner", $return)) {
      $uploader = user_load($return['owner']);
      $return['uploaded_by'] = $uploader->name;
    }

    //move the metadata up a level and remove the metadata tag
    if(array_key_exists('metadata', $return) && is_array($return['metadata'])) {
      foreach($return['metadata'] as $field => $value) {
        $return[$field] = $value;
      }

      unset($return['metadata']);
    }
  }

  return $return;
}

function digital_core_data_assets_relation_asset_product($file, $type, $identifier) {

  //set the relation
  $product = node_load($identifier);

  if($product) {

    if($type == "additional") {
      $product->field_additional_images['und'][] = array('target_id' => $file->fid);
    }
    else {
      $field = "field_{$type}_image";

      $image_data = array("und" => array(0 => array("target_id" => $file->fid)));

      $product->$field = $image_data;
    }

    node_save($product);
  }
}
