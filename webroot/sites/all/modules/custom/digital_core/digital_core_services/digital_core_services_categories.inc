<?php

//resource functions
//////////////////////////////

//Standard taxonomy service doesnt supply parent information
function digital_core_services_categories_index () {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');
  return digital_core_data_categories_read();
}

function digital_core_services_categories_retrieve($tid) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');
  return digital_core_data_categories_read($tid);
}

function digital_core_services_categories_create ($data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');
  return digital_core_data_categories_create($data);
}

function digital_core_services_categories_update($tid, $term) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');
  return digital_core_data_categories_update($tid, $term);
}

function digital_core_services_categories_delete($tid) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_categories');
  return digital_core_data_categories_delete($tid);
}