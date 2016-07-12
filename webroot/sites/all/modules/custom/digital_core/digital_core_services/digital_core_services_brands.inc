<?php

//resource functions
//////////////////////////////

function digital_core_services_brands_index ($perPage, $page, $query_parameters, $sort) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_brands');

  $parameters = array("sort"=> $sort,
                      "perPage" => $perPage,
                      "page" => $page);

  $sort = array_keys(tom_drupalize_fields("node", "brand", array($sort => $sort)));
  $sort = array_shift($sort);

  //this will let us use ein, vs field_ein
  $query_parameters = tom_drupalize_fields("node", "brand", $query_parameters);

  if(count($query_parameters) > 0) {
    foreach($query_parameters as $key => $value) {
      if(!array_key_exists($key, $parameters) && $key != "q") {
        $parameters[$key] = $value;
      }
    }
  }

  return digital_core_data_brands_read($parameters);
}

function digital_core_services_brands_retrieve($brand_id) {
  $brand_data = digital_core_services_brands_index(0, 0, array("nid" => $brand_id), "nid");
  return $brand_data['results'];
}

function digital_core_services_brands_update($id, $data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_brands');

  return digital_core_data_brands_update($id, $data);
}
