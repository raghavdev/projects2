<?php
/**
 * @file
 * crm_api_view.features.inc
 */

/**
 * Implements hook_views_api().
 */
function crm_api_view_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
