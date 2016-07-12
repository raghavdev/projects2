<?php
/**
 * @file
 * bmb_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bmb_services_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_default_oauth2_server().
 */
function bmb_services_default_oauth2_server() {
  $items = array();
  $items['auth_server'] = entity_import('oauth2_server', '{
    "name" : "auth_server",
    "label" : "auth_server",
    "settings" : {
      "enforce_state" : true,
      "default_scope" : "default",
      "allow_implicit" : 0,
      "use_openid_connect" : 0,
      "use_crypto_tokens" : 0,
      "grant_types" : {
        "password" : "password",
        "authorization_code" : 0,
        "client_credentials" : 0,
        "urn:ietf:params:oauth:grant-type:jwt-bearer" : 0,
        "refresh_token" : 0
      },
      "always_issue_new_refresh_token" : 0,
      "access_lifetime" : "3600",
      "id_lifetime" : "3600",
      "refresh_token_lifetime" : "1209600",
      "require_exact_redirect_uri" : 1
    },
    "rdf_mapping" : [],
    "scopes" : [ { "name" : "default", "description" : "default", "rdf_mapping" : [] } ]
  }');
  return $items;
}
