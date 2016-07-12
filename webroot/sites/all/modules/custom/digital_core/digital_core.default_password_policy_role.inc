<?php
/**
 * @file
 * digital_core.default_password_policy_role.inc
 */

/**
 * Implements hook_default_password_policy_role().
 */
function digital_core_default_password_policy_role() {
  $export = array();

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 2;
  $export['2'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 3;
  $export['3'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 4;
  $export['4'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 5;
  $export['5'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 6;
  $export['6'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 7;
  $export['7'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 8;
  $export['8'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 9;
  $export['9'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 10;
  $export['10'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 11;
  $export['11'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 12;
  $export['12'] = $password_policy_role;

  $password_policy_role = new stdClass();
  $password_policy_role->disabled = FALSE; /* Edit this to true to make a default password_policy_role disabled initially */
  $password_policy_role->api_version = 1;
  $password_policy_role->rid = 13;
  $export['13'] = $password_policy_role;

  return $export;
}
