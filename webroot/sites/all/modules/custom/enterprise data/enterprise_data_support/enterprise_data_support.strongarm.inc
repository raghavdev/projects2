<?php
/**
 * @file
 * enterprise_data_support.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enterprise_data_support_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_rcm_hierarchy';
  $strongarm->value = 0;
  $export['comment_anonymous_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_rcm_hierarchy';
  $strongarm->value = 1;
  $export['comment_default_mode_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_rcm_hierarchy';
  $strongarm->value = '50';
  $export['comment_default_per_page_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_rcm_hierarchy';
  $strongarm->value = 1;
  $export['comment_form_location_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_rcm_hierarchy';
  $strongarm->value = '1';
  $export['comment_preview_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_rcm_hierarchy';
  $strongarm->value = '2';
  $export['comment_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_rcm_hierarchy';
  $strongarm->value = 1;
  $export['comment_subject_field_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__rcm_hierarchy';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_rcm_hierarchy';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_rcm_hierarchy';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_rcm_hierarchy';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
    3 => 'revision_moderation',
  );
  $export['node_options_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_rcm_hierarchy';
  $strongarm->value = '1';
  $export['node_preview_rcm_hierarchy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_rcm_hierarchy';
  $strongarm->value = 1;
  $export['node_submitted_rcm_hierarchy'] = $strongarm;

  return $export;
}
