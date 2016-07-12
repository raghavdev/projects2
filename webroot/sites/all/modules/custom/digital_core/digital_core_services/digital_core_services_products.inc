<?php

//resource functions
//////////////////////////////

function digital_core_services_products_index ($perPage, $page, $query_parameters, $sort) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_products');

  //convert the sort value into the drupalized version of the field
  $newsort = array_keys(tom_drupalize_fields("node", "product_details", array($sort => $sort)));

  if($newsort) {
    $sort = array_shift($newsort);
  }

  $sort_dir = "ASC";

  if(array_key_exists("sort_dir", $query_parameters)) {
    $sort_dir = $query_parameters["sort_dir"];
  }

  $parameters = array("type" => "product_details",
                      "sort"=> $sort,
                      "perPage" => $perPage,
                      "sort_dir" => $sort_dir,
                      "page" => $page);

  //since search is not a valid field, it will be filtered out below, so just set it here
  if(array_key_exists("search", $query_parameters)) {
    $parameters['search'] = $query_parameters['search'];
  }

  if(array_key_exists("collection", $query_parameters)) {
    $parameters['collection'] = $query_parameters['collection'];
  }

  //only problem with this is it will break the category and brand multi filter
  //BE AWARE that any boolean must be added to the ignore list or its name will be rewrote and break processing
  $query_parameters = tom_drupalize_fields("node", "product_details", $query_parameters, array("product_name",
                                                                                                             "category",
                                                                                                             "primary_image",
                                                                                                             "flyer_description",
                                                                                                             "planogram_image",
                                                                                                             "west_product_id",
                                                                                                             "east_product_id",
                                                                                                             "modified",
                                                                                                             "upc",
                                                                                                             "available"));

  //its possible for these that you can send just the single value without the must or must not
  //this handling will support that
  //ie could say category=TID
  //or could say category=1|TID
  //both technically say the same thing
  //but its optional based on the need

  //Dont complain about the comment, out of sight out of mind, need to research this
  //do a special check for use of category or brand multifilter
//  if(array_key_exists("field_category", $query_parameters)) {
//    $data = explode("|", $query_parameters['field_category']);
//
//    if(is_array($data)) {
//      //revert the key change
//      $query_parameters['category'] = $data;
//      unset($query_parameters['field_category']);
//    }
//  }

  if(array_key_exists("field_brand", $query_parameters)) {
    $data = explode("|", $query_parameters['field_brand']);

    if(is_array($data)) {
      //revert the key change
      $query_parameters['brand'] = $query_parameters['field_brand'];
      unset($query_parameters['field_brand']);
    }
  }

  if(count($query_parameters) > 0) {
    foreach($query_parameters as $key => $value) {
      if(!array_key_exists($key, $parameters) && $key != "q") {
        $parameters[$key] = $value;
      }
    }
  }

  return digital_core_data_products_read($parameters);
}

function digital_core_services_products_retrieve ($product_id) {

  $product_data = digital_core_services_products_index(0, 0, array("nid" => $product_id), "nid");

  return $product_data['results'];
}

function digital_core_services_products_update($product_id, $data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_products');

  if($product_id == -1) {
    //there can never be a -1
    //will use this as a range flag
    if(array_key_exists("product_ids", $data)) {
      $product_ids = array();

      if($data['product_ids'] == "all") {
        //populate product_ids with a list of all of the ids
        $product_ids = db_select("node")
                  ->fields("node", array("nid"))
                  ->condition("type", "product_details")
                  ->execute()
                  ->fetchCol();
      }
      else if($data['product_ids'] == "filter") {
        //failsafe
        if(!array_key_exists("filter_data", $data)) {
          $product_ids = db_select("node")
                  ->fields("node", array("nid"))
                  ->condition("type", "product_details")
                  ->execute()
                  ->fetchCol();
        }
        else {
          //pull back a list of products that match this criteria

          //going to use existing methods to get this list
          //basically recreate the same query that the ui would have used

          $parameters = array();

          foreach($data['filter_data']['products'] as $filter_key => $values) {
            if(is_array($values)) {
              if(array_key_exists("enabled", $values)) {
                if($values['enabled']) {
                  $parameters[$filter_key] = $values['qualifier'];
                }
              }
              else if($filter_key == "brand"){
                if(count($values['brands']) > 0) {
                  $parameters['brand'] = $values['brands'];
                }
              }
              else if($filter_key == "category") {
                //only supports a single, since ui does too,

                $categoryid = array_shift($values['categories']);

                if($categoryid) {
                  $parameters['category'] = $values['qualifier'].'|'.$categoryid;
                }
              }
              else if($filter_key == "search") {
                $parameters['search'] = $values;
              }
            }
          }

          $parameters['perPage'] = 100;
          $parameters['type'] = "product_details";

          $pages = 0;
          do {
            $parameters['page'] = $pages;
            $p = digital_core_data_products_read($parameters);

            if($p['count'] > 0) {
              foreach($p['results'] as $product) {
                $product_ids[] = $product['nid'];
              }
            }

            $pages++;

            $x = ceil($p['total'] / 100);

            if($pages == ceil($p['total'] / 100)) {
              $pages = false;
            }
          }while($pages != false);

          unset($data['filter_data']);
        }
      }
      else {
        $product_ids = explode(',', $data['product_ids']);
      }

      unset($data['product_ids']);

      $data = tom_drupalize_fields("node", "product_details", $data);

      //run through each of the specified ids and apply the contents of the update
      foreach($product_ids as $id) {
        if($id != "" && is_numeric($id)) {
          //digital_core_services_products_update($id, $data);
          digital_core_data_update_direct("node", "product_details", $id, $data);
        }
      }
    }

    return;
  }

  return digital_core_data_products_update($product_id, $data);
}