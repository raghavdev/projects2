<?php
/**
 * @file
 * bmb_buyers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bmb_buyers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
