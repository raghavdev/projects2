<?php

function bluemarble_data_assets_create($file_data) {
  $file = bluemarble_assets_create_asset($file_data);

  if(!$file) {
    services_error("Error creating asset", 500);
    return FALSE;
  }

  $files = array($file);
  $files = bluemarble_data_assets_cleanup_file_objects($files);

  return array_shift($files);
}

function bluemarble_data_assets_read($parameters, $searched_fields = false) {

  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_categories');

  if(!$searched_fields) {
    $searched_fields = array("name", "field_uploaded_by", "field_creator", "field_copyright_notice",
        "field_color_mode", "field_keywords", "field_description", "field_creator", 'field_model', 'field_title', "field_alt");
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
    'index_name'       => variable_get('bluemarble_data_asset_index_name', 'asset_index'),
    'query_parameters' => $parameters,
    'searched_fields'  => $searched_fields,
    'non_wild_fields'  => array("field_keywords"),
  ));

  //attach the url to the uri for each asset, "kenstowell [1:03 PM] gots to display it yo!"
  foreach($assets['results'] as $idx => $asset) {
    $file_obj = file_load($asset['fid']);

    if($file_obj) {
      $url = file_create_url($file_obj->uri);

      //the amazon module seems to miss the protocol in the create url
      if(!strpos($url, 'http')) {
        $url = "http:" . $url;
      }

      $assets['results'][$idx]['url'] = $url;

      $file = "default_file";

      $assets['results'][$idx] = tom_dedrupalize_fields($assets['results'][$idx], 'file');

      $assets['results'][$idx]['thumb_url'] = bluemarble_assets_get_thumbnail_url($file_obj);

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

      $assets['results'][$idx] = bluemarble_data_assets_adjust_return($asset['type'], $assets['results'][$idx]);
    }
  }

  return $assets;
}

function bluemarble_data_assets_update($id, $data) {
  //need to know what type of file this is
  $type = db_select("file_managed")
          ->fields("file_managed", array("type"))
          ->condition("fid", $id)
          ->execute()
          ->fetchField();

  //if there is an asset change
  if(array_key_exists("file_bytes", $data)) {

    //create the new asset
    $type = bluemarble_assets_get_file_type($data['file_name']);

    //$fid = bluemarble_assets_upload_asset($data);
    $file = bluemarble_assets_create_asset($data);

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
  $return = bluemarble_data_assets_adjust_return($type, $return);

  if(sizeof($return) == 0) {
    services_error("Error updating asset", 500);
    return FALSE;
  }
  else {
    return $return;
  }
}

function bluemarble_data_assets_delete() {

}

//applies a little handling to the data special for assets before the return
function bluemarble_data_assets_adjust_return($type, $return) {

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

function bluemarble_data_assets_relation_asset_product($file, $type, $identifier) {

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


/**
 * Cleans up an array of image objects.
 */
function bluemarble_data_assets_cleanup_file_objects($files) {
  $ret = array();
  $uids = array();

  $styles = image_styles();

  foreach ($files as $fid => $file) {
    $uids[] = $file->uid;
  }

  $user_names = array();
  if (count($uids)) {
    $user_names = db_query('SELECT uid, name FROM {users} WHERE uid IN (:uids)', array(
      ':uids' => $uids))
      ->fetchAllKeyed();
  }

  foreach ($files as $fid => $file) {
    // use the alt field not the alt if it exists
    if(property_exists($file, "alt")) {
      unset($file->alt);
    }

    // url for the raw image
    $url = file_create_url($file->uri);

    //the amazon module seems to miss the protocol in the create url
    if(strpos($url, 'http') !== 0) {
      $url = 'http://' . ltrim($url, '/');
    }

    $file_record = array(
      'fid' => $fid,
      'url' => $url,
      'file_mime' => $file->filemime,
      'uploaded_timestamp' => $file->timestamp,
    );

    // For images add in a few other needed properties
    if ($file->type == 'image') {
      if (array_key_exists("width", $file->metadata)) {
        $file_record['width'] = $file->metadata['width'];
      }

      if (array_key_exists("height", $file->metadata)) {
        $file_record['height'] = $file->metadata['height'];
      }

      //add a thumbnail image
      //$file_record['thumb_url'] = bluemarble_assets_get_thumbnail_url($file);

      if (isset($file->metadata['channels']) && $file->metadata['channels'] == 4) {
        $file_record['color_mode'] = "CMYK";
      }

      $file_record['renditions'] = bluemarble_data_assets_get_image_data($file, $styles);
    }

    //add the exif data to the feed
    foreach ($file as $property => $value) {
      $file_record[$property] = $value;
    }

    $file_record = tom_dedrupalize_fields($file_record);

    // kinda ridiculous but have to add this, for now at least
    if($file_record['internal_only'] == 1) {
      $file_record['internal_only'] = TRUE;
    }
    else if($file_record['internal_only'] == 0) {
      $file_record['internal_only'] = FALSE;
    }

    $file_record["uploaded_by"] = $user_names[$file->uid];

    $ret[$fid] = $file_record;
  }

  return $ret;
}


function bluemarble_data_assets_get_image_data($file, $styles) {
  $style_names_by_path = array();
  $renditions = array();

  if ($file) {
    //need a url to each rendition
    foreach($styles as $style_name => $data) {
      $path = image_style_path($style_name, $file->uri);
      $style_names_by_path[$path] = $style_name;
    }

    if (!empty($style_names_by_path)) {
      $paths = array_keys($style_names_by_path);
      $existing = db_select('amazons3_file', 'a')
        ->fields('a', array('uri'))
        ->condition('a.uri', $paths)
        ->execute()
        ->fetchCol();
      foreach ($existing as $path) {
        $style_name = $style_names_by_path[$path];
        $renditions[$style_name] = file_create_url($path);
      }
    }
  }

  return $renditions;
}
