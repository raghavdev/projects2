<?php
/**
 * @file
 * enterprise_data_support.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enterprise_data_support_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function enterprise_data_support_node_info() {
  $items = array(
    'rcm_hierarchy' => array(
      'name' => t('RCM Hierarchy'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
