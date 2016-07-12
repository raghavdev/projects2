<?php
/**
 * @file
 * bmb_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access blue marble product tab'.
  $permissions['access blue marble product tab'] = array(
    'name' => 'access blue marble product tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
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
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
    ),
    'module' => 'drangular',
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

  // Exported permission: 'administer drangular'.
  $permissions['administer drangular'] = array(
    'name' => 'administer drangular',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
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

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'clear drangular cache'.
  $permissions['clear drangular cache'] = array(
    'name' => 'clear drangular cache',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'drangular',
  );

  // Exported permission: 'create blue marble products'.
  $permissions['create blue marble products'] = array(
    'name' => 'create blue marble products',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'delete content uri addresses'.
  $permissions['delete content uri addresses'] = array(
    'name' => 'delete content uri addresses',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'content_uri',
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

  // Exported permission: 'edit blue marble products categories tab'.
  $permissions['edit blue marble products categories tab'] = array(
    'name' => 'edit blue marble products categories tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products certification tab'.
  $permissions['edit blue marble products certification tab'] = array(
    'name' => 'edit blue marble products certification tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products dimensions-weights tab'.
  $permissions['edit blue marble products dimensions-weights tab'] = array(
    'name' => 'edit blue marble products dimensions-weights tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products exports tab'.
  $permissions['edit blue marble products exports tab'] = array(
    'name' => 'edit blue marble products exports tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products identifiers tab'.
  $permissions['edit blue marble products identifiers tab'] = array(
    'name' => 'edit blue marble products identifiers tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products item-master-basics tab'.
  $permissions['edit blue marble products item-master-basics tab'] = array(
    'name' => 'edit blue marble products item-master-basics tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products location-freight tab'.
  $permissions['edit blue marble products location-freight tab'] = array(
    'name' => 'edit blue marble products location-freight tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products macola-transmit tab'.
  $permissions['edit blue marble products macola-transmit tab'] = array(
    'name' => 'edit blue marble products macola-transmit tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products nutrition tab'.
  $permissions['edit blue marble products nutrition tab'] = array(
    'name' => 'edit blue marble products nutrition tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products product-basics tab'.
  $permissions['edit blue marble products product-basics tab'] = array(
    'name' => 'edit blue marble products product-basics tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products product-info-and-attrib tab'.
  $permissions['edit blue marble products product-info-and-attrib tab'] = array(
    'name' => 'edit blue marble products product-info-and-attrib tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products shelf-life-info tab'.
  $permissions['edit blue marble products shelf-life-info tab'] = array(
    'name' => 'edit blue marble products shelf-life-info tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products supplier-portal-select-fields tab'.
  $permissions['edit blue marble products supplier-portal-select-fields tab'] = array(
    'name' => 'edit blue marble products supplier-portal-select-fields tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
  );

  // Exported permission: 'edit blue marble products vendor-info tab'.
  $permissions['edit blue marble products vendor-info tab'] = array(
    'name' => 'edit blue marble products vendor-info tab',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'View-Only' => 'View-Only',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble',
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

  // Exported permission: 'edit workflow comment'.
  $permissions['edit workflow comment'] = array(
    'name' => 'edit workflow comment',
    'roles' => array(
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workflow',
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

  // Exported permission: 'participate in workflow'.
  $permissions['participate in workflow'] = array(
    'name' => 'participate in workflow',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'read blue marble brands'.
  $permissions['read blue marble brands'] = array(
    'name' => 'read blue marble brands',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'read blue marble categories'.
  $permissions['read blue marble categories'] = array(
    'name' => 'read blue marble categories',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'read blue marble image styles'.
  $permissions['read blue marble image styles'] = array(
    'name' => 'read blue marble image styles',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'read blue marble products'.
  $permissions['read blue marble products'] = array(
    'name' => 'read blue marble products',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'read blue marble user prefs'.
  $permissions['read blue marble user prefs'] = array(
    'name' => 'read blue marble user prefs',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'schedule workflow transitions'.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'show workflow state form'.
  $permissions['show workflow state form'] = array(
    'name' => 'show workflow state form',
    'roles' => array(
      'Programmer' => 'Programmer',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'update blue marble brands'.
  $permissions['update blue marble brands'] = array(
    'name' => 'update blue marble brands',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'update blue marble products'.
  $permissions['update blue marble products'] = array(
    'name' => 'update blue marble products',
    'roles' => array(
      'Manager' => 'Manager',
      'Marketing' => 'Marketing',
      'Programmer' => 'Programmer',
      'Supply Chain' => 'Supply Chain',
      'administrator' => 'administrator',
    ),
    'module' => 'bluemarble_services',
  );

  // Exported permission: 'update blue marble user prefs'.
  $permissions['update blue marble user prefs'] = array(
    'name' => 'update blue marble user prefs',
    'roles' => array(
      'Manager' => 'Manager',
      'Programmer' => 'Programmer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bluemarble_services',
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
