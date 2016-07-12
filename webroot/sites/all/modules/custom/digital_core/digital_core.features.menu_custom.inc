<?php
/**
 * @file
 * digital_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function digital_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-digital-core-menu.
  $menus['menu-digital-core-menu'] = array(
    'menu_name' => 'menu-digital-core-menu',
    'title' => 'Digital Core Menu',
    'description' => 'Main Menu for the Digital Core',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Core Menu');
  t('Main Menu for the Digital Core');


  return $menus;
}
