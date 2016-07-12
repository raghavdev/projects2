<?php
/**
 * @file
 * enterprise_data_brands.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function enterprise_data_brands_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'East Brand Short Name Alphanumeric';
  $rule->name = 'east_short_name_alphanumeric';
  $rule->field_name = 'field_east_short_brand_name';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'east_brand';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[[:alnum:]]+$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      23 => 0,
      17 => 0,
      24 => 0,
      21 => 0,
      22 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must contain only alphanumeric characters.';
  $export['east_short_name_alphanumeric'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Enterprise Short Name Alphanumeric';
  $rule->name = 'ent_short_name_alphanumeric';
  $rule->field_name = 'field_short_brand_name';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'enterprise_brand';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[[:alnum:]]+$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      23 => 0,
      17 => 0,
      24 => 0,
      21 => 0,
      22 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must contain only alphanumeric characters.';
  $export['ent_short_name_alphanumeric'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Enterprise Long Name ASCII';
  $rule->name = 'enterprise_long_name_ascii';
  $rule->field_name = 'field_ent_long_brand_name';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'enterprise_brand';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[[:ascii:]]+$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      23 => 0,
      17 => 0,
      24 => 0,
      21 => 0,
      22 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must contain only alphanumeric characters, single spaces, and simple punctuation.';
  $export['enterprise_long_name_ascii'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'West Brand Long Name ASCII';
  $rule->name = 'west_brand_long_name_ascii';
  $rule->field_name = 'field_west_long_brand_name';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'west_brand';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[[:ascii:]]+$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      23 => 0,
      17 => 0,
      24 => 0,
      21 => 0,
      22 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must contain only alphanumeric characters, single spaces, and simple punctuation.';
  $export['west_brand_long_name_ascii'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'West Brand Short Name Alphanumeric';
  $rule->name = 'west_short_name_alphanumeric';
  $rule->field_name = 'field_west_short_brand_name';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'west_brand';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '^[[:alnum:]]+$',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      23 => 0,
      17 => 0,
      24 => 0,
      21 => 0,
      22 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must contain only alphanumeric characters.';
  $export['west_short_name_alphanumeric'] = $rule;

  return $export;
}
