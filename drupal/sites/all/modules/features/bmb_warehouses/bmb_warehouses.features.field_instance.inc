<?php
/**
 * @file
 * bmb_warehouses.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bmb_warehouses_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-warehouse-field_macola_id'.
  $field_instances['taxonomy_term-warehouse-field_macola_id'] = array(
    'bundle' => 'warehouse',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_macola_id',
    'label' => 'Macola ID',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-warehouse-field_macola_name'.
  $field_instances['taxonomy_term-warehouse-field_macola_name'] = array(
    'bundle' => 'warehouse',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_macola_name',
    'label' => 'Macola Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Macola ID');
  t('Macola Name');

  return $field_instances;
}
