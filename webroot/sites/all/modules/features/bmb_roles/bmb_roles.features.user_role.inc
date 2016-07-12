<?php
/**
 * @file
 * bmb_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bmb_roles_user_default_roles() {
  $roles = array();

  // Exported role: Feed Account.
  $roles['Feed Account'] = array(
    'name' => 'Feed Account',
    'weight' => 7,
  );

  // Exported role: Manager.
  $roles['Manager'] = array(
    'name' => 'Manager',
    'weight' => 4,
  );

  // Exported role: Marketing.
  $roles['Marketing'] = array(
    'name' => 'Marketing',
    'weight' => 5,
  );

  // Exported role: Programmer.
  $roles['Programmer'] = array(
    'name' => 'Programmer',
    'weight' => 2,
  );

  // Exported role: Supply Chain.
  $roles['Supply Chain'] = array(
    'name' => 'Supply Chain',
    'weight' => 6,
  );

  // Exported role: View-Only.
  $roles['View-Only'] = array(
    'name' => 'View-Only',
    'weight' => 8,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  return $roles;
}
