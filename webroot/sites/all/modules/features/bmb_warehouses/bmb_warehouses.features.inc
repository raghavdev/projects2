<?php
/**
 * @file
 * bmb_warehouses.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bmb_warehouses_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
