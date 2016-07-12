<?php
/**
 * @file
 * bmb_roles.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bmb_roles_default_rules_configuration() {
  $items = array();
  $items['rules_edit_user'] = entity_import('rules_config', '{ "rules_edit_user" : {
      "LABEL" : "Edit user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_view" : [] },
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]\\/edit" } } ]
    }
  }');
  $items['rules_log_in_redirect'] = entity_import('rules_config', '{ "rules_log_in_redirect" : {
      "LABEL" : "log in redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "6" : "6" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "admin\\/settings\\/browse" } } ]
    }
  }');
  return $items;
}
