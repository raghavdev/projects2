<?php

//resource functions
//////////////////////////////

//Standard taxonomy service doesnt supply parent information
function bluemarble_services_categories_index () {
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_categories');
  return bluemarble_data_categories_read();
}

function bluemarble_services_categories_retrieve($tid) {
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_categories');
  return bluemarble_data_categories_read($tid);
}
