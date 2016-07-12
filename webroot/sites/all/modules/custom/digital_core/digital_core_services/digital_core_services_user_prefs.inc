<?php

//TODO this is all just boilerplate,  fill in the blanks when the user prefs module is ready


//resource functions
//////////////////////////////

function digital_core_services_user_prefs_retrieve ($uid) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_user_prefs');
  return digital_core_data_user_prefs_read($uid);
}

function digital_core_services_user_prefs_update($uid, $user_prefs) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_user_prefs');
  return digital_core_data_user_prefs_update($uid, $user_prefs);
}