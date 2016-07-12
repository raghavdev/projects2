<?php

//TODO this is all just boilerplate,  fill in the blanks when the user prefs module is ready


//resource functions
//////////////////////////////

function bluemarble_services_user_prefs_retrieve ($uid) {
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_user_prefs');
  return bluemarble_data_user_prefs_read($uid);
}

function bluemarble_services_user_prefs_update($uid, $user_prefs) {
  module_load_include('inc', 'bluemarble_data', 'bluemarble_data_user_prefs');
  return bluemarble_data_user_prefs_update($uid, $user_prefs);
}