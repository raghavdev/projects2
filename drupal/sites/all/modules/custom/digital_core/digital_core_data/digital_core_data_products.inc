<?php

function digital_core_data_products_create($data) {

  $data = tom_drupalize_fields("node", "product_details", $data);

  return tom_create_drupal_entity("node", "product_details", $data);
}

//pull up a list of digital core data products based on parameters
function digital_core_data_products_read($parameters, $searched_fields = false, $returned_fields = array(), $returned_renditions = array()) {

  //pull in the brands inc
  module_load_include('inc', 'digital_core_data', 'digital_core_data_brands');
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');

  //if a collection is being queried we need to do special handling
  if(array_key_exists("collection", $parameters)) {

    //$product_ids = digital_core_data_products_read($parameters['collection_id']);
    $data = tom_get_entities("node", array("nid" => $parameters['collection']), "collection");

    unset($parameters['collection']);

    if($data['count'] > 0) {

      $nids = array();
      foreach($data['results'][0]['field_collection_data']['und'] as $nid) {
        $nids[] = $nid['target_id'];
      }

      $parameters['nid'] = $nids;

      if(count($nids) == 0) {
        return array("count" => 0, "total" => 0, "results" => array());
      }

      return digital_core_data_products_read($parameters);
    }

    return array("count" => 0, "total" => 0, "results" => array());
  }

  //categories need to be able to search for all children also
  //so this must convert the category filter into a categories filter
  //where it includes its children
  if(array_key_exists("category", $parameters)) {

    $categories = digital_core_data_categories_parse_category_children($parameters['category']);

    if($categories) {
      $parameters['categories'] = $categories;
      unset($parameters['category']);
    }
  }

  //have to convert the keywords into their tid values or solr wont match them
  if(array_key_exists("search", $parameters)) {

    //need to support a search for upc with dashes
    //assume a UPC code is over 12 characters
    if(!is_array($parameters['search']) && strlen($parameters['search']) > 12 &&  preg_match("/^[0-9-]*$/", $parameters['search'])) {
      $parameters['search'] = preg_replace('/-/', '', $parameters['search']);
    }

    //$vocab = taxonomy_vocabulary_machine_name_load('keyword');
    $vid = db_select("taxonomy_vocabulary")
            ->fields("taxonomy_vocabulary", array("vid"))
            ->condition("machine_name", "keywords")
            ->execute()
            ->fetchField();

    if($vid) {
      //tried to do this, worked locally but did not on staging, so using direct access
      //$term = taxonomy_get_term_by_name($parameters['search'], $vocab->vid);

      //FINISH THIS
      //TODO
      if(!is_array($parameters['search'])) {
        //make it an array to make this easier
        $parameters['search'] = array($parameters['search']);
      }

      $termsUsed = false;
      $searchData = array();
      foreach($parameters['search'] as $termdata) {
        $term = db_select("taxonomy_term_data")
                  ->fields("taxonomy_term_data", array("tid"))
                  ->condition("name", $parameters['search'])
                  ->condition("vid", $vid)
                  ->execute()
                  ->fetchField();

        if($term) {
          //add the id to the search array
          $searchData[] = $term;
          $termsUsed = true;
        }
        else {
          //its not a term add the value to the search array
          $searchData[] = $termdata;
        }
      }

      //only groom the search array if there were some changes made here
      if($termsUsed) {
        //search for the term id also
        $parameters['search'] = $searchData;

        //elimiate id fields so we dont get partial matches on ids since the search here is an id
        $searched_fields = array("body:value", "field_brand", "field_brand_description",
        "field_brand_long_description", "field_consumer_brand_name", "field_consumer_product_name",
        "field_flyer_description", "field_extended_description", "field_html_description",
        "field_feature1", "field_feature2", "field_feature3", "field_feature4",
        "field_keywords", "title");
      }
    }
  }

  if(!$searched_fields) {
    $searched_fields = array("body:value", "field_brand", "field_brand_description",
        "field_brand_long_description", "field_consumer_brand_name", "field_consumer_product_name",
        "field_flyer_description", "field_extended_description", "field_html_description",
        "field_feature1", "field_feature2", "field_feature3", "field_feature4", "field_master_case_upc",
        "field_keywords", "upc", "title", "west_product_id", "east_product_id", "east_product_id_full");
  }

  $product_data = simple_solr_search(array(
    'index_name'       => SOLRINDEX,
    'query_parameters' => $parameters,
    'searched_fields'  => $searched_fields,
    'returned_fields'  => $returned_fields,
    'non_wild_fields'  => array("field_keywords"),
  ));

  // Build a list of file id's to reduce number of database queries.
  $fids = array();
  foreach ($product_data['results'] as $idx => $product) {
    $fids += digital_core_data_product_get_image_fids($product);
    if (array_key_exists("field_primary_image", $product)) {
      $fids[] = $product['field_primary_image'];
    }
  }

  $files = file_load_multiple($fids);
  $files = digital_core_data_product_cleanup_image_objects($files);
  $image_fields = digital_core_data_product_get_image_fields();
  foreach ($product_data['results'] as $idx => $product) {
    if (array_key_exists("field_primary_image", $product)) {
      $url = FALSE;
      $fid = $product['field_primary_image'];

      if (isset($files[$fid])) {
        //if there is a primary image we need a thumbnail for the ui
        //cast to an array since it may be an object
        $files[$fid] = (array)$files[$fid];
        $url = digital_core_assets_get_asset_thumbnail_url($files[$fid]['filename']);

        if ($url) {
          $product_data['results'][$idx]['thumb_url'] = $url;
        }
      }

      if (!$url) {
        //default product image file
        $product_data['results'][$idx]['thumb_url'] = file_create_url(drangular_get_path("unfiDigitalCoreApp") . "/images/default_image.jpg");
      }
    }
    else {
      $product_data['results'][$idx]['thumb_url'] = file_create_url(drangular_get_path("unfiDigitalCoreApp") . "/images/default_image.jpg");
    }

    // Loop through image fields and set image urls
    foreach ($image_fields as $image_field) {

      //limit the renditions processed if we have supplied a list
      if(count($returned_renditions) > 0) {

        //very convoluted way of converting the drupal field into the image name
        $empty = "";

        $list = array_keys(tom_dedrupalize_field($image_field, $empty));

        $renditionname = str_replace("_image", "", array_shift($list));

        //check for straight match
        if(!in_array($renditionname, $returned_renditions)) {
          continue;
        }
      }

      // All fields start with 'field_' and end with '_image' or '_images'
      $short_field = substr_replace($image_field, '', 0, 6);
      $pos = strrpos($short_field, '_image');
      $short_field = substr_replace($short_field, '', $pos);
      $product_data['results'][$idx]['image_urls'][$short_field] = array();
      if (array_key_exists($image_field, $product)) {

        if (is_array($product[$image_field])) {
          foreach ($product[$image_field] as $delta => $fid) {
            if (isset($files[$fid])) {
              $product_data['results'][$idx]['image_urls'][$short_field][] = $files[$fid];
            }
          }
        }
        else {
          $fid = $product[$image_field];
          if (isset($files[$fid])) {
            $product_data['results'][$idx]['image_urls'][$short_field] = $files[$fid];
          }
        }
      }
    }

    //resolve the brand id to an actual object
    if (array_key_exists("field_brand", $product_data['results'][$idx])) {
      //$brand_data = digital_core_data_brands_index(0, 0, array("nid" => $product_data['results'][$idx]['field_brand']), "nid");

      $brand_data = digital_core_data_brands_read(array("perPage" => 0,
                                                        "page" => 0,
                                                        "nid" => $product_data['results'][$idx]['field_brand'],
                                                        "sort" => "nid"));
      if($brand_data['count'] > 0) {
        $product_data['results'][$idx]['brand'] = $brand_data['results'][0];
      }

      unset($product_data['results'][$idx]['field_brand']);
    }
  }

  //clean up the field names
  foreach($product_data['results'] as $idx => $record) {
    $product_data['results'][$idx] = tom_dedrupalize_fields($record, "node", "product_details");

    //convert the id of the user for the indredients modified into the user name
    if(array_key_exists("ingredients_mod_user", $product_data['results'][$idx]) && $product_data['results'][$idx]['ingredients_mod_user'] != "") {

      $u = user_load($product_data['results'][$idx]['ingredients_mod_user']);

      if($u) {
        $product_data['results'][$idx]["ingredients_mod_user"] = $u->name;
      }
    }

    //the recipe url data field can not be a string must be an array
    //the dedrupalize will collapase it into a string if its singular
    //make it back into an array
    if(array_key_exists("recipe_urls", $product_data['results'][$idx]) && !is_array($product_data['results'][$idx]['recipe_urls'])) {
      $product_data['results'][$idx]['recipe_urls'] = array($product_data['results'][$idx]['recipe_urls']);
    }
  }

  return $product_data;
}

function digital_core_data_products_update($product_id, $data) {
  global $user;

  $primary_field = digital_core_data_get_primary_key("product_details", "digital_core_data_products");

    //there is special handling of the modified and by who if we touch ingredients
  if(array_key_exists("ingredients", $data)) {
    $data['ingredients_modified'] = time();
    $data['ingredients_mod_user'] = $user->uid;
  }

  $data = tom_drupalize_fields('node', 'product_details', $data);

  $return_data = tom_update_drupal_entity($product_id, "node", $data);

  $return = tom_dedrupalize_fields($return_data, "node", "product_details");

  if(sizeof($return) == 0) {
    services_error("Error updating product", 500);
    return false;
  }
  else {
    return $return;
  }
}

/**
 * Returns array of file.fid's for a given product.
 *
 * @return array
 */
function digital_core_data_product_get_image_fids($product) {
  $fids = array();
  $image_fields = digital_core_data_product_get_image_fields();

  foreach ($image_fields as $image_field) {
    if (array_key_exists($image_field, $product)) {
      if (is_array($product[$image_field])) {
        foreach ($product[$image_field] as $delta => $fid) {
          if (!empty($fid)) {
            $fids[] = $fid;
          }
        }
      }
      else {
        if (!empty($product[$image_field])) {
          $fids[] = $product[$image_field];
        }
      }
    }
  }

  return $fids;
}

/**
 * Returns a list of image field names.
 */
function digital_core_data_product_get_image_fields() {
  static $image_fields = array();

  if (empty($image_fields)) {
    $query = db_select('field_config_instance', 'fci')
      ->fields('fci', array('field_name'));
    $query->innerJoin('field_config', 'fc', 'fci.field_id = fc.id');
    $image_fields = $query->condition('fci.bundle', 'product_details')
      ->condition('fc.type', 'entityreference')
      ->execute()
      ->fetchCol();
  }

  //remove the extra fields
  //all images contain _image
  $ret = array();
  foreach($image_fields as $field) {
    if(strpos($field, "_image") !== false) {
      $ret[] = $field;
    }
  }

  return $ret;
}

/**
 * Cleans up an array of image objects.
 */
function digital_core_data_product_cleanup_image_objects($files) {
  $images = array();
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

    $img_record = array(
      'fid' => $fid,
      'url' => $url,
      'file_mime' => $file->filemime,
      'color_mode' => 'RGB',
      'uploaded_timestamp' => $file->timestamp,
    );

    // add in a few other needed properties

    if(array_key_exists("width", $file->metadata)) {
      $img_record['width'] = $file->metadata['width'];
    }

    if(array_key_exists("height", $file->metadata)) {
      $img_record['height'] = $file->metadata['height'];
    }

    //add a thumbnail image
    //$img_record['thumb_url'] = digital_core_assets_get_thumbnail_url($file);

    if (isset($file->metadata['channels']) && $file->metadata['channels'] == 4) {
      $img_record['color_mode'] = "CMYK";
    }

    //add the exif data to the feed
    foreach($file as $property => $value) {
      $img_record[$property] = $value;
    }

    $img_record['renditions'] = digital_core_data_products_get_image_data($file, $styles);

    $img_record = tom_dedrupalize_fields($img_record);

    // kinda ridiculous but have to add this, for now at least
    if($img_record['internal_only'] == 1) {
      $img_record['internal_only'] = TRUE;
    }
    else if($img_record['internal_only'] == 0) {
      $img_record['internal_only'] = FALSE;
    }

    $img_record["uploaded_by"] = $user_names[$file->uid];

    $images[$fid] = $img_record;
  }

  return $images;
}

function digital_core_data_products_get_image_data($file, $styles) {
  global $base_url;

  $renditions = array();

  if ($file) {

    //check that this file actually exists
    $url = file_create_url($file->uri);
    $h = get_headers($url, 1);

    $u = true;

    if($h[0] == "HTTP/1.1 404 Not Found") {
      $u = false;
    }

    if($u) {
      //need a url to each rendition
      foreach($styles as $style_name => $data) {
        //need a token
        $token_query = array(IMAGE_DERIVATIVE_TOKEN => image_style_path_token($style_name, $file->uri));
        $token = drupal_http_build_query($token_query);
        //we are assuming the file has not been generated for a rendition, let drupal sort it on request. its faster to generate the feed this way
        $renditions[$style_name] = $base_url . "/system/files/styles/" . $style_name . "/s3/" . $file->filename . "?" . $token;
      }
    }
  }

  return $renditions;
}

//get a list of products from the specified colleciton
function digital_core_data_products_get_collection_products($collection_id) {
  return db_select("field_data_field_collection_data")
          ->fields("field_data_field_collection_data", array("field_collection_data_target_id"))
          ->condition("entity_id", $collection_id)
          ->execute()
          ->fetchCol();
}

function digital_core_data_get_nid_from_ein($ein) {
  return db_select("field_data_field_ein")
          ->fields("field_data_field_ein", array("entity_id"))
          ->condition("field_ein_value", $ein)
          ->execute()
          ->fetchField();
}

function digital_core_data_products_nid_from_east_id($east_product_id)
{
  $query = db_select("field_data_field_productsid");
  $query->addJoin("inner", "digital_core_data_products", "digital_core_data_products", "digital_core_data_products.productsid = field_data_field_productsid.field_productsid_value");
  $query->condition("digital_core_data_products.east_product_id", $east_product_id);
  return $query->fields("field_data_field_productsid", array("entity_id"))
    ->execute()
    ->fetchField();
}
