<?php
/**
 * @file
 * bmb_buyers.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function bmb_buyers_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Buyers Unique Macola Id';
  $rule->name = 'buyers_unique_macola_id';
  $rule->field_name = 'field_macola_id';
  $rule->col = 'value';
  $rule->entity_type = 'taxonomy_term';
  $rule->bundle = 'buyer';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      17 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = '[value] for [field-name] already exists.';
  $export['buyers_unique_macola_id'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Buyers Unique Macola Name';
  $rule->name = 'buyers_unique_macola_name';
  $rule->field_name = 'field_macola_name';
  $rule->col = 'value';
  $rule->entity_type = 'taxonomy_term';
  $rule->bundle = 'buyer';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      17 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = '[value] for [field-name] already exists.';
  $export['buyers_unique_macola_name'] = $rule;

  return $export;
}
