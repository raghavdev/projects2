<?php
/**
 * @file
 * bmb_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function bmb_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'bmbcrm';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'service/bmbcrm';
  $endpoint->authentication = array(
    'oauth2_server' => array(
      'server' => 'auth_server',
    ),
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'xml' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/xml' => TRUE,
      'text/xml' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'multipart/form-data' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'brand' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
    'brands' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
    'product' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
    'views' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['bmbcrm'] = $endpoint;

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'digitalcore';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'service/digitalcore';
  $endpoint->authentication = array(
    'bluemarble' => 'bluemarble',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
    ),
  );
  $endpoint->resources = array(
    'assets' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'brands' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'categories' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'compute' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'file' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'image_styles' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'products' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user_prefs' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'validate' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['digitalcore'] = $endpoint;

  return $export;
}
