<?php
/**
 * @file
 * bmb_material_cost_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_material_cost_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in material_cost_type'.
  $permissions['add terms in material_cost_type'] = array(
    'name' => 'add terms in material_cost_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in material_cost_type'.
  $permissions['delete terms in material_cost_type'] = array(
    'name' => 'delete terms in material_cost_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in material_cost_type'.
  $permissions['edit terms in material_cost_type'] = array(
    'name' => 'edit terms in material_cost_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
