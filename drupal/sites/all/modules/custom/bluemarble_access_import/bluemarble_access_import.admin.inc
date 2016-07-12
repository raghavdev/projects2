<?php
/**
 * @file
 * Blue Marble Access Import admin pages.
 */

/**
 * Form builder: Blue Marble Access Import CSV form.
 */
function bluemarble_access_import_admin_form($form, &$form_state) {
  ini_set('memory_limit','256M');

  $form_state['build_info']['args'][0] = 'bluemarble_access_products';

  module_load_include('inc', 'bluemarble_staging', 'bluemarble_staging_csv_import');
  return drupal_get_form('bluemarble_staging_csv_upload_form', 'bluemarble_access_products');
}

/**
 * Page callback: Blue Marble Access Import field mappings form.
 */
function bluemarble_access_import_admin_field_mappings() {
  module_load_include('inc', 'bluemarble_staging', 'bluemarble_staging_field_mapping');

  $options = array(
    'alt' => FALSE,
    'primary_key' => TRUE,
    'toType' => 'select',
  );

  return drupal_get_form('bluemarble_staging_field_mapping_form', 'bluemarble_access_import', 'bluemarble_access_products', array('product_details'), array(), 'csv', $options);
}
