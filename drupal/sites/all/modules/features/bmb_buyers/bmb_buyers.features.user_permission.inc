<?php
/**
 * @file
 * bmb_buyers.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_buyers_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in buyer'.
  $permissions['add terms in buyer'] = array(
    'name' => 'add terms in buyer',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in buyer'.
  $permissions['delete terms in buyer'] = array(
    'name' => 'delete terms in buyer',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in buyer'.
  $permissions['edit terms in buyer'] = array(
    'name' => 'edit terms in buyer',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
