<?php
/**
 * @file
 * digital_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function digital_core_user_default_roles() {
  $roles = array();

  // Exported role: Bulk Ops.
  $roles['Bulk Ops'] = array(
    'name' => 'Bulk Ops',
    'weight' => 10,
  );

  // Exported role: CMP Admin.
  $roles['CMP Admin'] = array(
    'name' => 'CMP Admin',
    'weight' => 11,
  );

  // Exported role: DAM Admin.
  $roles['DAM Admin'] = array(
    'name' => 'DAM Admin',
    'weight' => 9,
  );

  // Exported role: DAM Viewer.
  $roles['DAM Viewer'] = array(
    'name' => 'DAM Viewer',
    'weight' => 8,
  );

  // Exported role: DigitalCore User.
  $roles['DigitalCore User'] = array(
    'name' => 'DigitalCore User',
    'weight' => 5,
  );

  // Exported role: Feed Account.
  $roles['Feed Account'] = array(
    'name' => 'Feed Account',
    'weight' => 15,
  );

  // Exported role: Honest Green Admin.
  $roles['Honest Green Admin'] = array(
    'name' => 'Honest Green Admin',
    'weight' => 12,
  );

  // Exported role: PIM Admin.
  $roles['PIM Admin'] = array(
    'name' => 'PIM Admin',
    'weight' => 7,
  );

  // Exported role: PIM Viewer.
  $roles['PIM Viewer'] = array(
    'name' => 'PIM Viewer',
    'weight' => 6,
  );

  // Exported role: Programmer.
  $roles['Programmer'] = array(
    'name' => 'Programmer',
    'weight' => 2,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: management.
  $roles['management'] = array(
    'name' => 'management',
    'weight' => 4,
  );

  return $roles;
}
