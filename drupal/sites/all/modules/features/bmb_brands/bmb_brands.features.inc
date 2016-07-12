<?php
/**
 * @file
 * bmb_brands.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bmb_brands_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bmb_brands_node_info() {
  $items = array(
    'brand' => array(
      'name' => t('Brand'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
