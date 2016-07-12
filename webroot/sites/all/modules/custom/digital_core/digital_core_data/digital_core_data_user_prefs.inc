<?php

function digital_core_data_user_prefs_read($uid) {
 $account = user_load($uid);

  //if there is a data, and the user prefs then use them
  if($account->data) {
    return $account->data['digital_core_user_prefs'];
  }

  return false;
}

function digital_core_data_user_prefs_update($uid, $user_prefs) {
  // Make sure you are working with the fully loaded user object.
  $account = user_load($uid);
  $edit['data']['digital_core_user_prefs'] = $user_prefs;
  user_save($account, $edit);
  $user = user_load($uid);
  return $user->data['digital_core_user_prefs'];
}