<?php
/**
 * @file
 * Macola Connect admin pages.
 */

/**
 * Form builder: Macola Connect configuration form.
 */
function macola_connect_admin_form($form, &$form_state) {
  $form['macola_connect_api_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('API URL'),
    '#default_value' => variable_get('macola_connect_api_url', ''),
  );

  $form['macola_connect_update_frequency'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Related info update frequency'),
    '#description'   => t('How often should the API update related information from Macola? Note: This is dependent on crons frequency.'),
    '#default_value' => variable_get('macola_connect_update_frequency', 360),
    '#size'          => 4,
    '#suffix'        => ' ' . t('minutes'),
  );

  $form['macola_connect_background_process_sync_products_limit'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Product Sync Iteration Limit'),
    '#size'          => 4,
    '#default_value' => variable_get('macola_connect_background_process_sync_products_limit', 10),
    '#description'   => t('The number of products to sync per step.'),
  );

  $form['macola_connect_read'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Read data from Macola'),
    '#description'   => t('When enabled, data will be read from Macola on a periodic basis.'),
    '#return_value'  => TRUE,
    '#default_value' => variable_get('macola_connect_read', TRUE),
  );

  $form['macola_connect_write'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Write data to Macola'),
    '#description'   => t('When enabled, product data will be sent to Macola.'),
    '#return_value'  => TRUE,
    '#default_value' => variable_get('macola_connect_write', TRUE),
  );

  $form['reset_macola_updated_since_timestamp'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Reset updatedSince Timestamp'),
    '#description'   => t('Will revert the timestamp back to 0, so that, essentially, the all of product data is pulled next cron run.'),
    '#default_value' => FALSE,
  );

  // TODO: WIP: see todo in macola_connect_cron().
  $form = system_settings_form($form);

  $form['#submit'][] = 'macola_connect_admin_form_validate';
  $form['#submit'][] = 'macola_connect_admin_form_submit';

  return $form;
}

function macola_connect_admin_form_validate($form, &$form_state) {
  if (isset($form_state['values']['reset_macola_updated_since_timestamp'])) {
    $form_state['non_conf_values']['reset_macola_updated_since_timestamp'] = $form_state['values']['reset_macola_updated_since_timestamp'];
    unset($form_state['values']['reset_macola_updated_since_timestamp']);
    unset($form_state['input']['reset_macola_updated_since_timestamp']);
  }
}

function macola_connect_admin_form_submit($form, &$form_state) {
  if (!empty($form_state['non_conf_values']['reset_macola_updated_since_timestamp'])) {
    variable_set('macola_connect_products_updated_since', 0);
  }
}


/**
 * Page callback: Macola Connect field mappings form.
 */
function macola_connect_admin_field_mappings() {
  module_load_include('inc', 'bluemarble_staging', 'bluemarble_staging_field_mapping');

  $options = array(
    'alt' => FALSE,
    'primary_key' => TRUE,
    'toType' => 'select',
  );

  return drupal_get_form('bluemarble_staging_field_mapping_form', 'macola_connect', 'macola_connect_products', array('product_details'), array(), 'macola_connect', $options);
}