<?php
/**
 * @file
 * bmb_product_details.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bmb_product_details_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bmb_product_details_node_info() {
  $items = array(
    'product_details' => array(
      'name' => t('Product Details'),
      'base' => 'node_content',
      'description' => t('Products fields for Blue Marble '),
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
