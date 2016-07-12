<?php
/**
 * @file
 * bmb_brands.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_brands_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create brand content'.
  $permissions['create brand content'] = array(
    'name' => 'create brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any brand content'.
  $permissions['delete any brand content'] = array(
    'name' => 'delete any brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own brand content'.
  $permissions['delete own brand content'] = array(
    'name' => 'delete own brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any brand content'.
  $permissions['edit any brand content'] = array(
    'name' => 'edit any brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own brand content'.
  $permissions['edit own brand content'] = array(
    'name' => 'edit own brand content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
