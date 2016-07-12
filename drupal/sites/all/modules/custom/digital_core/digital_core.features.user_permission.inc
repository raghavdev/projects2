<?php
/**
 * @file
 * digital_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function digital_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access bulk search'.
  $permissions['access bulk search'] = array(
    'name' => 'access bulk search',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'bulk_search_wizard',
  );

  // Exported permission: 'access bulk uploads'.
  $permissions['access bulk uploads'] = array(
    'name' => 'access bulk uploads',
    'roles' => array(
      'Bulk Ops' => 'Bulk Ops',
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'bulk_upload_wizard',
  );

  // Exported permission: 'access content uri endpoints'.
  $permissions['access content uri endpoints'] = array(
    'name' => 'access content uri endpoints',
    'roles' => array(
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'content_uri',
  );

  // Exported permission: 'access digital core'.
  $permissions['access digital core'] = array(
    'name' => 'access digital core',
    'roles' => array(
      'DigitalCore User' => 'DigitalCore User',
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'access eiw csv upload'.
  $permissions['access eiw csv upload'] = array(
    'name' => 'access eiw csv upload',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'eiw_connect',
  );

  // Exported permission: 'add content uri addresses'.
  $permissions['add content uri addresses'] = array(
    'name' => 'add content uri addresses',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'content_uri',
  );

  // Exported permission: 'add drangular app'.
  $permissions['add drangular app'] = array(
    'name' => 'add drangular app',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'add drangular app path'.
  $permissions['add drangular app path'] = array(
    'name' => 'add drangular app path',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'administer angularjs'.
  $permissions['administer angularjs'] = array(
    'name' => 'administer angularjs',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'angularjs',
  );

  // Exported permission: 'administer content uri'.
  $permissions['administer content uri'] = array(
    'name' => 'administer content uri',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'content_uri',
  );

  // Exported permission: 'administer digitalcore staging'.
  $permissions['administer digitalcore staging'] = array(
    'name' => 'administer digitalcore staging',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'digital_core_staging',
  );

  // Exported permission: 'administer drangular'.
  $permissions['administer drangular'] = array(
    'name' => 'administer drangular',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'administer eiw connection'.
  $permissions['administer eiw connection'] = array(
    'name' => 'administer eiw connection',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'eiw_connect',
  );

  // Exported permission: 'administer eiw field mapping'.
  $permissions['administer eiw field mapping'] = array(
    'name' => 'administer eiw field mapping',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'eiw_connect',
  );

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'administer image metadata'.
  $permissions['administer image metadata'] = array(
    'name' => 'administer image metadata',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'exif_custom',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'clear drangular cache'.
  $permissions['clear drangular cache'] = array(
    'name' => 'clear drangular cache',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'create digital core assets'.
  $permissions['create digital core assets'] = array(
    'name' => 'create digital core assets',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'create digital core categories'.
  $permissions['create digital core categories'] = array(
    'name' => 'create digital core categories',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'create digital core collections'.
  $permissions['create digital core collections'] = array(
    'name' => 'create digital core collections',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'delete content uri addresses'.
  $permissions['delete content uri addresses'] = array(
    'name' => 'delete content uri addresses',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'content_uri',
  );

  // Exported permission: 'delete digital core assets'.
  $permissions['delete digital core assets'] = array(
    'name' => 'delete digital core assets',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'delete digital core categories'.
  $permissions['delete digital core categories'] = array(
    'name' => 'delete digital core categories',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'delete digital core collections'.
  $permissions['delete digital core collections'] = array(
    'name' => 'delete digital core collections',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'delete drangular app'.
  $permissions['delete drangular app'] = array(
    'name' => 'delete drangular app',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'delete drangular app path'.
  $permissions['delete drangular app path'] = array(
    'name' => 'delete drangular app path',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'edit content uri addresses'.
  $permissions['edit content uri addresses'] = array(
    'name' => 'edit content uri addresses',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'content_uri',
  );

  // Exported permission: 'edit drangular app'.
  $permissions['edit drangular app'] = array(
    'name' => 'edit drangular app',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'edit drangular app path'.
  $permissions['edit drangular app path'] = array(
    'name' => 'edit drangular app path',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'edit drangular app status'.
  $permissions['edit drangular app status'] = array(
    'name' => 'edit drangular app status',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'edit drangular cache'.
  $permissions['edit drangular cache'] = array(
    'name' => 'edit drangular cache',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'have default image metadata profile'.
  $permissions['have default image metadata profile'] = array(
    'name' => 'have default image metadata profile',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'exif_custom',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'process eiw data'.
  $permissions['process eiw data'] = array(
    'name' => 'process eiw data',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'eiw_connect',
  );

  // Exported permission: 'read digital core assets'.
  $permissions['read digital core assets'] = array(
    'name' => 'read digital core assets',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core brands'.
  $permissions['read digital core brands'] = array(
    'name' => 'read digital core brands',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core categories'.
  $permissions['read digital core categories'] = array(
    'name' => 'read digital core categories',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core collections'.
  $permissions['read digital core collections'] = array(
    'name' => 'read digital core collections',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core image styles'.
  $permissions['read digital core image styles'] = array(
    'name' => 'read digital core image styles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core products'.
  $permissions['read digital core products'] = array(
    'name' => 'read digital core products',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core rcm categories'.
  $permissions['read digital core rcm categories'] = array(
    'name' => 'read digital core rcm categories',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'read digital core user prefs'.
  $permissions['read digital core user prefs'] = array(
    'name' => 'read digital core user prefs',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'update digital core assets'.
  $permissions['update digital core assets'] = array(
    'name' => 'update digital core assets',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'update digital core brands'.
  $permissions['update digital core brands'] = array(
    'name' => 'update digital core brands',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'update digital core collections'.
  $permissions['update digital core collections'] = array(
    'name' => 'update digital core collections',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'update digital core products'.
  $permissions['update digital core products'] = array(
    'name' => 'update digital core products',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'update digital core user prefs'.
  $permissions['update digital core user prefs'] = array(
    'name' => 'update digital core user prefs',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'digital_core_services',
  );

  // Exported permission: 'view image metadata'.
  $permissions['view image metadata'] = array(
    'name' => 'view image metadata',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'exif_custom',
  );

  return $permissions;
}
