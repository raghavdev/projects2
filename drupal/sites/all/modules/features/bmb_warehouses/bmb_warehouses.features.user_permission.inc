<?php
/**
 * @file
 * bmb_warehouses.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_warehouses_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in warehouse'.
  $permissions['add terms in warehouse'] = array(
    'name' => 'add terms in warehouse',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in warehouse'.
  $permissions['delete terms in warehouse'] = array(
    'name' => 'delete terms in warehouse',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in warehouse'.
  $permissions['edit terms in warehouse'] = array(
    'name' => 'edit terms in warehouse',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
