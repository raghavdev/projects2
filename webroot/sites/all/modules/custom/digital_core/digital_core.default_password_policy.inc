<?php
/**
 * @file
 * digital_core.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function digital_core_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'Standard Policy';
  $password_policy->description = '';
  $password_policy->enabled = TRUE;
  $password_policy->policy = array(
    'length' => '8',
    'digit' => '1',
    'history' => '4',
    'lowercase' => '1',
    'username' => '1',
    'uppercase' => '1',
  );
  $password_policy->created = 1395876156;
  $password_policy->expiration = 0;
  $password_policy->warning = '';
  $password_policy->weight = FALSE;
  $export['Standard Policy'] = $password_policy;

  return $export;
}
