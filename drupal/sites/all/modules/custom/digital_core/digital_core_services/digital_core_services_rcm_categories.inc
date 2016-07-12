<?php

//resource functions
//////////////////////////////

//Standard taxonomy service doesnt supply parent information
function digital_core_services_rcm_categories_index () {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_rcm_categories');
  return digital_core_data_rcm_categories_read();
}