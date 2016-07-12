<?php
/**
 * @file
 * digital_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function digital_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "password_policy" && $api == "default_password_policy") {
    return array("version" => "1");
  }
  if ($module == "password_policy" && $api == "default_password_policy_role") {
    return array("version" => "1");
  }
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function digital_core_image_default_styles() {
  $styles = array();

  // Exported image style: watermarked.
  $styles['watermarked'] = array(
    'name' => 'watermarked',
    'label' => 'watermarked',
    'effects' => array(
      4 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => '00',
          'alpha' => 100,
          'path' => 'module://digital_core/watermark.png',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: web_thumbnail.
  $styles['web_thumbnail'] = array(
    'name' => 'web_thumbnail',
    'label' => 'Web Thumbnail (216x216)',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 216,
          'height' => 216,
          'upscale' => 1,
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
function digital_core_node_info() {
  $items = array(
    'asset_collection' => array(
      'name' => t('Asset Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'brand' => array(
      'name' => t('Brand'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_details' => array(
      'name' => t('Product Details'),
      'base' => 'node_content',
      'description' => t('Extended product information that is managed in drupal. Data that does not come from EIW'),
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
    'product_feed' => array(
      'name' => t('Product Feed'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
