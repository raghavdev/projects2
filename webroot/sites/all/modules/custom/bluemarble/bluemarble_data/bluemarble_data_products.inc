<?php

function bluemarble_data_products_create($data) {

  $data = tom_drupalize_fields("node", "product_details", $data);

  return tom_create_drupal_entity("node", "product_details", $data);
}

//pull up a list of blue marble data products based on parameters
function bluemarble_data_products_read($parameters, $searched_fields = false, $returned_fields = array(), $returned_renditions = array()) {

  //pull in the brands inc
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_brands');
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_categories');
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_assets');

  // If the field is a taxonomy term field, the filter needs to also include children.
  foreach ($parameters as $name => $value) {
    if (bluemarble_data_is_taxonomy_field($name)) {
      $new_value = bluemarble_data_categories_parse_category_children($value);
      $paremeters[$name] = $new_value;
    }
  }

  // Search API uses a separate machine name for the actual field in Solr.
  if (array_key_exists('has_primary_image', $parameters)) {
    $parameters['search_api_aggregation_3'] = $parameters['has_primary_image'];
    unset($parameters['has_primary_image']);
  }

  // Search API uses a separate machine name for the actual field in Solr.
  if (array_key_exists('item_numbers', $parameters)) {
    $parameters['search_api_aggregation_4'] = $parameters['item_numbers'];
    unset($parameters['item_numbers']);
  }

  // Search API uses a separate machine name for the actual field in Solr.
  if (array_key_exists('ingredients', $parameters)) {
    $parameters['search_api_aggregation_5'] = $parameters['ingredients'];
    unset($parameters['ingredients']);
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
        $parameters['search'] = explode(',', $parameters['search']);
        foreach ($parameters['search'] as $key => $val) {
          $parameters['search'][$key] = trim($val);
        }
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
        $searched_fields = array("search_api_aggregation_1");
      }
    }
  }

  if(!$searched_fields) {
    $searched_fields = array(
      // Text fields
      "search_api_aggregation_1",
      // Item numbers
      "field_item_num", "field_upc", "field_gtin", "field_unfi_east_id", "field_unfi_west_id",
    );
  }

  $product_data = simple_solr_search(array(
    'index_name'       => variable_get('bluemarble_data_index_name', 'default_node_index'),
    'query_parameters' => $parameters,
    'searched_fields'  => $searched_fields,
    'returned_fields'  => $returned_fields,
    'non_wild_fields'  => array("field_keywords"),
  ));

  // Build a list of file id's to reduce number of database queries.
  $fids = array();
  foreach ($product_data['results'] as $idx => $product) {
    $fids = array_merge($fids, bluemarble_data_product_get_image_fids($product));
    $fids = array_merge($fids, bluemarble_data_product_get_file_fids($product));
  }

  $files = file_load_multiple($fids);
  $files = bluemarble_data_assets_cleanup_file_objects($files);
  $image_fields = bluemarble_data_product_get_image_fields();
  $file_fields = bluemarble_data_product_get_file_fields();
  $date_fields = bluemarble_data_product_get_date_fields();
  foreach ($product_data['results'] as $idx => $product) {
    if (array_key_exists('field_primary_image:file', $product)) {
      $url = FALSE;
      $fid = $product['field_primary_image:file'];

      if (isset($files[$fid])) {
        //if there is a primary image we need a thumbnail for the ui
        //cast to an array since it may be an object
        $files[$fid] = (array)$files[$fid];
        $url = bluemarble_assets_get_asset_thumbnail_url($files[$fid]['uri']);

        if ($url) {
          $product_data['results'][$idx]['thumb_url'] = $url;
        }
      }

      if (!$url) {
        //default product image file
        $product_data['results'][$idx]['thumb_url'] = file_create_url(drangular_get_path("unfiDigitalCoreApp") . "/images/default_image.png");
      }
    }
    else {
      $product_data['results'][$idx]['thumb_url'] = file_create_url(drangular_get_path("unfiDigitalCoreApp") . "/images/default_image.png");
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

      $solr_field = $image_field . ':file';
      if (array_key_exists($solr_field, $product)) {
        if (is_array($product[$solr_field])) {
          $product_data['results'][$idx][$image_field] = array();
          foreach ($product[$solr_field] as $delta => $fid) {
            if (isset($files[$fid])) {
              $product_data['results'][$idx][$image_field][] = $files[$fid];
            }
          }
        }
        else {
          $fid = $product[$solr_field];
          if (isset($files[$fid])) {
            $product_data['results'][$idx][$image_field] = $files[$fid];
          }
        }
        unset($product_data['results'][$idx][$solr_field]);
      }
    }

    // Loop through file fields and set file
    foreach ($file_fields as $file_field) {
      $solr_field = $file_field . ':file';
      if (array_key_exists($solr_field, $product)) {
        if (is_array($product[$solr_field])) {
          $product_data['results'][$idx][$file_field] = array();
          foreach ($product[$solr_field] as $delta => $fid) {
            if (isset($files[$fid])) {
              $product_data['results'][$idx][$file_field][] = $files[$fid];
            }
          }
        }
        else {
          $fid = $product[$solr_field];
          if (isset($files[$fid])) {
            $product_data['results'][$idx][$file_field] = $files[$fid];
          }
        }
        unset($product_data['results'][$idx][$solr_field]);
      }
    }

    // Loop through date fields and set date
    foreach ($date_fields as $date_field) {
      if (isset($product[$date_field])) {
        // Format dates according to ISO-8601
        $product_data['results'][$idx][$date_field] = format_date($product[$date_field], 'custom', 'Y-m-d\TH:i:sP');
      }
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

function bluemarble_data_products_update($product_id, $data) {
  $data = tom_drupalize_fields('node', 'product_details', $data);

  unset($data['nid']);
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
function bluemarble_data_product_get_image_fids($product) {
  $fids = array();
  $image_fields = bluemarble_data_product_get_image_fields();

  foreach ($image_fields as $image_field) {
    $solr_field = $image_field . ':file';
    if (array_key_exists($solr_field, $product)) {
      if (is_array($product[$solr_field])) {
        foreach ($product[$solr_field] as $delta => $fid) {
          if (!empty($fid)) {
            $fids[] = $fid;
          }
        }
      }
      else {
        if (!empty($product[$solr_field])) {
          $fids[] = $product[$solr_field];
        }
      }
    }
  }

  return $fids;
}

function bluemarble_data_product_get_file_fids($product) {
  $fids = array();
  $file_fields = bluemarble_data_product_get_file_fields();

  foreach ($file_fields as $file_field) {
    $solr_field = $file_field . ':file';
    if (array_key_exists($solr_field, $product)) {
      if (is_array($product[$solr_field])) {
        foreach ($product[$solr_field] as $delta => $fid) {
          if (!empty($fid)) {
            $fids[] = $fid;
          }
        }
      }
      else {
        if (!empty($product[$solr_field])) {
          $fids[] = $product[$solr_field];
        }
      }
    }
  }

  return $fids;
}

/**
 * Returns a list of image field names.
 */
function bluemarble_data_product_get_image_fields() {
  static $image_fields = array();

  if (empty($image_fields)) {
    $query = db_select('field_config_instance', 'fci')
      ->fields('fci', array('field_name'));
    $query->innerJoin('field_config', 'fc', 'fci.field_id = fc.id');
    $image_fields = $query->condition('fci.bundle', 'product_details')
      ->condition('fc.type', 'image')
      ->condition('fc.deleted', 0)
      ->condition('fci.deleted', 0)
      ->execute()
      ->fetchCol();
  }
  return $image_fields;
}

/**
 * Returns a list of file field names.
 */
function bluemarble_data_product_get_file_fields() {
  static $file_fields = array();

  if (empty($file_fields)) {
    $query = db_select('field_config_instance', 'fci')
      ->fields('fci', array('field_name'));
    $query->innerJoin('field_config', 'fc', 'fci.field_id = fc.id');
    $file_fields = $query->condition('fci.bundle', 'product_details')
      ->condition('fc.type', 'file')
      ->condition('fc.deleted', 0)
      ->condition('fci.deleted', 0)
      ->execute()
      ->fetchCol();
  }
  return $file_fields;
}

/**
 * Returns a list of date field names.
 */
function bluemarble_data_product_get_date_fields() {
  static $fields = array();

  if (empty($fields)) {
    $query = db_select('field_config_instance', 'fci')
      ->fields('fci', array('field_name'));
    $query->innerJoin('field_config', 'fc', 'fci.field_id = fc.id');
    $fields = $query->condition('fci.bundle', 'product_details')
      ->condition('fc.type', array('datetime', 'date', 'datestamp'))
      ->condition('fc.deleted', 0)
      ->condition('fci.deleted', 0)
      ->execute()
      ->fetchCol();
  }
  return $fields;
}
