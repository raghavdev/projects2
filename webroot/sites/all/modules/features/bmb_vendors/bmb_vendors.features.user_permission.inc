<?php
/**
 * @file
 * bmb_vendors.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_vendors_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in vendor'.
  $permissions['add terms in vendor'] = array(
    'name' => 'add terms in vendor',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in vendor'.
  $permissions['delete terms in vendor'] = array(
    'name' => 'delete terms in vendor',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in vendor'.
  $permissions['edit terms in vendor'] = array(
    'name' => 'edit terms in vendor',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
