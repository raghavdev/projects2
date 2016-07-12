<?php
/**
 * @file
 * digital_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function digital_core_default_rules_configuration() {
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
  return $items;
}
