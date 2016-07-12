<?php
/**
 * @file
 * enterprise_data_brands.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enterprise_data_brands_user_default_roles() {
  $roles = array();

  // Exported role: Enterprise Brand Editor.
  $roles['Enterprise Brand Editor'] = array(
    'name' => 'Enterprise Brand Editor',
    'weight' => 15,
  );

  // Exported role: Enterprise Brand Manager.
  $roles['Enterprise Brand Manager'] = array(
    'name' => 'Enterprise Brand Manager',
    'weight' => 16,
  );

  return $roles;
}
