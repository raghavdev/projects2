<?php
/**
 * @file
 * enterprise_data_support.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enterprise_data_support_user_default_roles() {
  $roles = array();

  // Exported role: Enterprise Brand Editing.
  $roles['Enterprise Brand Editing'] = array(
    'name' => 'Enterprise Brand Editing',
    'weight' => 19,
  );

  // Exported role: Enterprise Brand Management.
  $roles['Enterprise Brand Management'] = array(
    'name' => 'Enterprise Brand Management',
    'weight' => 20,
  );

  // Exported role: Enterprise Polling Administration.
  $roles['Enterprise Polling Administration'] = array(
    'name' => 'Enterprise Polling Administration',
    'weight' => 21,
  );

  // Exported role: Food Service Editing.
  $roles['Food Service Editing'] = array(
    'name' => 'Food Service Editing',
    'weight' => 17,
  );

  // Exported role: Food Service Management.
  $roles['Food Service Management'] = array(
    'name' => 'Food Service Management',
    'weight' => 18,
  );

  // Exported role: RCM Editing.
  $roles['RCM Editing'] = array(
    'name' => 'RCM Editing',
    'weight' => 15,
  );

  // Exported role: RCM Management.
  $roles['RCM Management'] = array(
    'name' => 'RCM Management',
    'weight' => 16,
  );

  return $roles;
}
