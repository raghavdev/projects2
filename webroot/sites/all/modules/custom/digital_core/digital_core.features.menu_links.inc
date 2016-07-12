<?php
/**
 * @file
 * digital_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function digital_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-digital-core-menu_bulk-upload:bulk_upload
  $menu_links['menu-digital-core-menu_bulk-upload:bulk_upload'] = array(
    'menu_name' => 'menu-digital-core-menu',
    'link_path' => 'bulk_upload',
    'router_path' => 'bulk_upload',
    'link_title' => 'Bulk Upload',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-digital-core-menu_bulk-upload:bulk_upload',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bulk Upload');


  return $menu_links;
}
