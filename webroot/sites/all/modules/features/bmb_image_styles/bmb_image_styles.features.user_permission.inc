<?php
/**
 * @file
 * bmb_image_styles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_image_styles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in color_modes'.
  $permissions['add terms in color_modes'] = array(
    'name' => 'add terms in color_modes',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in color_modes'.
  $permissions['delete terms in color_modes'] = array(
    'name' => 'delete terms in color_modes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in color_modes'.
  $permissions['edit terms in color_modes'] = array(
    'name' => 'edit terms in color_modes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
