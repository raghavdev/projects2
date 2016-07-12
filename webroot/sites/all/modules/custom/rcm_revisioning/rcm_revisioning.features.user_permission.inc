<?php
/**
 * @file
 * rcm_revisioning.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rcm_revisioning_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit revisions'.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions'.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'unpublish current revision'.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revision status messages'.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
