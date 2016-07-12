<?php
/**
 * @file
 * bmb_categories.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_categories_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in bmb_category'.
  $permissions['add terms in bmb_category'] = array(
    'name' => 'add terms in bmb_category',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bmb_product_type'.
  $permissions['add terms in bmb_product_type'] = array(
    'name' => 'add terms in bmb_product_type',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in category'.
  $permissions['add terms in category'] = array(
    'name' => 'add terms in category',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in spins_category'.
  $permissions['add terms in spins_category'] = array(
    'name' => 'add terms in spins_category',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in spins_product_type'.
  $permissions['add terms in spins_product_type'] = array(
    'name' => 'add terms in spins_product_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in web_category'.
  $permissions['add terms in web_category'] = array(
    'name' => 'add terms in web_category',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in bmb_category'.
  $permissions['delete terms in bmb_category'] = array(
    'name' => 'delete terms in bmb_category',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bmb_product_type'.
  $permissions['delete terms in bmb_product_type'] = array(
    'name' => 'delete terms in bmb_product_type',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in category'.
  $permissions['delete terms in category'] = array(
    'name' => 'delete terms in category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in spins_category'.
  $permissions['delete terms in spins_category'] = array(
    'name' => 'delete terms in spins_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in spins_product_type'.
  $permissions['delete terms in spins_product_type'] = array(
    'name' => 'delete terms in spins_product_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in web_category'.
  $permissions['delete terms in web_category'] = array(
    'name' => 'delete terms in web_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bmb_category'.
  $permissions['edit terms in bmb_category'] = array(
    'name' => 'edit terms in bmb_category',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bmb_product_type'.
  $permissions['edit terms in bmb_product_type'] = array(
    'name' => 'edit terms in bmb_product_type',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in category'.
  $permissions['edit terms in category'] = array(
    'name' => 'edit terms in category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in spins_category'.
  $permissions['edit terms in spins_category'] = array(
    'name' => 'edit terms in spins_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in spins_product_type'.
  $permissions['edit terms in spins_product_type'] = array(
    'name' => 'edit terms in spins_product_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in web_category'.
  $permissions['edit terms in web_category'] = array(
    'name' => 'edit terms in web_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
