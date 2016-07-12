<?php
/**
 * @file
 * enterprise_data_brands.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enterprise_data_brands_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create east_brand content'.
  $permissions['create east_brand content'] = array(
    'name' => 'create east_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create enterprise_brand content'.
  $permissions['create enterprise_brand content'] = array(
    'name' => 'create enterprise_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create west_brand content'.
  $permissions['create west_brand content'] = array(
    'name' => 'create west_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any east_brand content'.
  $permissions['delete any east_brand content'] = array(
    'name' => 'delete any east_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any enterprise_brand content'.
  $permissions['delete any enterprise_brand content'] = array(
    'name' => 'delete any enterprise_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any west_brand content'.
  $permissions['delete any west_brand content'] = array(
    'name' => 'delete any west_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own east_brand content'.
  $permissions['delete own east_brand content'] = array(
    'name' => 'delete own east_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own enterprise_brand content'.
  $permissions['delete own enterprise_brand content'] = array(
    'name' => 'delete own enterprise_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own west_brand content'.
  $permissions['delete own west_brand content'] = array(
    'name' => 'delete own west_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in brand_customer_name'.
  $permissions['delete terms in brand_customer_name'] = array(
    'name' => 'delete terms in brand_customer_name',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any east_brand content'.
  $permissions['edit any east_brand content'] = array(
    'name' => 'edit any east_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any enterprise_brand content'.
  $permissions['edit any enterprise_brand content'] = array(
    'name' => 'edit any enterprise_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any west_brand content'.
  $permissions['edit any west_brand content'] = array(
    'name' => 'edit any west_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own east_brand content'.
  $permissions['edit own east_brand content'] = array(
    'name' => 'edit own east_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own enterprise_brand content'.
  $permissions['edit own enterprise_brand content'] = array(
    'name' => 'edit own enterprise_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own west_brand content'.
  $permissions['edit own west_brand content'] = array(
    'name' => 'edit own west_brand content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in brand_customer_name'.
  $permissions['edit terms in brand_customer_name'] = array(
    'name' => 'edit terms in brand_customer_name',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
