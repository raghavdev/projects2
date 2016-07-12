<?php

//resource functions
//////////////////////////////

function digital_core_services_collections_index ($perPage, $page, $parameters, $sort, $user_id) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_collections');

  //TODO Paginiation if required

  if(array_key_exists("q", $parameters)) {
    unset($parameters['q']);
  }

  if(!array_key_exists("type", $parameters)) {
    $parameters['type'] = "collection";
  }

  $parameters["user_id"] = $user_id;

  return digital_core_data_collections_read($parameters);
}

function digital_core_services_collections_retrieve($user_id, $collection_id) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_collections');
  $parameters = array("collection_id" => $collection_id);
  return digital_core_data_collections_read($parameters);
}

function digital_core_services_collections_create($data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_collections');
  return digital_core_data_collections_create($data);
}

function digital_core_services_collections_update($id, $parameters) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_collections');
  return digital_core_data_collections_update($id, $parameters);
}

function digital_core_services_collections_delete($id) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_collections');
  return digital_core_data_collections_delete($id);
}
