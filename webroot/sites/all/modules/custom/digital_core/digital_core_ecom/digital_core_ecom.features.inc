<?php
/**
 * @file
 * digital_core_ecom.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function digital_core_ecom_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function digital_core_ecom_image_default_styles() {
  $styles = array();

  // Exported image style: ecommerce.
  $styles['ecommerce'] = array(
    'name' => 'ecommerce',
    'label' => 'ecommerce',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => 500,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function digital_core_ecom_node_info() {
  $items = array(
    'apl' => array(
      'name' => t('APL'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Customer Name'),
      'help' => '',
    ),
  );
  return $items;
}
