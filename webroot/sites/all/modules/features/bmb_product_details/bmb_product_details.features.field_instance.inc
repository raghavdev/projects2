<?php
/**
 * @file
 * bmb_product_details.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bmb_product_details_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_vendor_pricing-field_approved_source'
  $field_instances['field_collection_item-field_vendor_pricing-field_approved_source'] = array(
    'bundle' => 'field_vendor_pricing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_approved_source',
    'label' => 'Approved Source',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_vendor_pricing-field_terms'
  $field_instances['field_collection_item-field_vendor_pricing-field_terms'] = array(
    'bundle' => 'field_vendor_pricing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'View Only from Macola',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_terms',
    'label' => 'Payment Terms',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_vendor_pricing-field_vendor_item_number'
  $field_instances['field_collection_item-field_vendor_pricing-field_vendor_item_number'] = array(
    'bundle' => 'field_vendor_pricing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Entered if we know it but not essential',
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
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_vendor_item_number',
    'label' => 'Vendor Item Number',
    'required' => 0,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_vendor_pricing-field_vendors'
  $field_instances['field_collection_item-field_vendor_pricing-field_vendors'] = array(
    'bundle' => 'field_vendor_pricing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Abbreviation of vendor (supplier) name',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_vendors',
    'label' => 'Vendor ID Number',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-product_details-field_active_date'
  $field_instances['node-product_details-field_active_date'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => 'Date of first actual sale',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_formatter_class' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_active_date',
    'label' => 'First Sale Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-product_details-field_activity_date'
  $field_instances['node-product_details-field_activity_date'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 230,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_date',
    'label' => 'Activity Date',
    'required' => FALSE,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 186,
    ),
  );

  // Exported field_instance: 'node-product_details-field_activity_state'
  $field_instances['node-product_details-field_activity_state'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The current activity state of the product.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_state',
    'label' => 'Activity Code',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'workflowfield',
      'settings' => array(
        'comment' => 1,
        'name_as_title' => 1,
      ),
      'type' => 'workflow_default',
      'weight' => 185,
    ),
  );

  // Exported field_instance: 'node-product_details-field_added_sugars_value'
  $field_instances['node-product_details-field_added_sugars_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 97,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_added_sugars_value',
    'label' => 'Added Sugars',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-product_details-field_additional_images'
  $field_instances['node-product_details-field_additional_images'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => 'Allows multiple image uploads',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'field_formatter_class' => '',
          'image_link' => '',
          'image_style' => 'thumbnail',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_additional_images',
    'label' => 'Additional Images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'primary_image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-product_details-field_additional_origin'
  $field_instances['node-product_details-field_additional_origin'] = array(
    'bundle' => 'product_details',
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
        'weight' => 240,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_additional_origin',
    'label' => 'Additional Origin Locations',
    'required' => 0,
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
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-product_details-field_alaska_seafood_cert'
  $field_instances['node-product_details-field_alaska_seafood_cert'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'file_default',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_alaska_seafood_cert',
    'label' => 'Alaska Seafood Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-product_details-field_allergens_in_facility'
  $field_instances['node-product_details-field_allergens_in_facility'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 182,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_allergens_in_facility',
    'label' => 'Allergens in Facility',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-product_details-field_approved_source'
  $field_instances['node-product_details-field_approved_source'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 236,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_approved_source',
    'label' => 'Approved Source',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 134,
    ),
  );

  // Exported field_instance: 'node-product_details-field_backorderable'
  $field_instances['node-product_details-field_backorderable'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 169,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 169,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_backorderable',
    'label' => 'Backorderable',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_backorderable',
      ),
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_baltimore_beverage_tax'
  $field_instances['node-product_details-field_baltimore_beverage_tax'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 147,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 180,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_baltimore_beverage_tax',
    'label' => 'Baltimore Beverage Tax',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 110,
    ),
  );

  // Exported field_instance: 'node-product_details-field_berkeley_beverage_tax'
  $field_instances['node-product_details-field_berkeley_beverage_tax'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 148,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 181,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_berkeley_beverage_tax',
    'label' => 'Berkeley Beverage Tax',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 111,
    ),
  );

  // Exported field_instance: 'node-product_details-field_beverage_container'
  $field_instances['node-product_details-field_beverage_container'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 115,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 132,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_beverage_container',
    'label' => 'Beverage Container',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 108,
    ),
  );

  // Exported field_instance: 'node-product_details-field_biotin_value'
  $field_instances['node-product_details-field_biotin_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 112,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 112,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_biotin_value',
    'label' => 'Biotin',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 54,
    ),
  );

  // Exported field_instance: 'node-product_details-field_bmb_category'
  $field_instances['node-product_details-field_bmb_category'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Example: Frozen',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bmb_category',
    'label' => 'BMB Category',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-product_details-field_bmb_product_type'
  $field_instances['node-product_details-field_bmb_product_type'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Example: Flavor "Blueberry / Pomegranate Blend" or type "Juice Blend"',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bmb_product_type',
    'label' => 'BMB Product Type',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-product_details-field_bottle_color'
  $field_instances['node-product_details-field_bottle_color'] = array(
    'bundle' => 'product_details',
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
        'weight' => 241,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bottle_color',
    'label' => 'Bottle Color',
    'required' => 0,
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
      'weight' => 112,
    ),
  );

  // Exported field_instance: 'node-product_details-field_brand'
  $field_instances['node-product_details-field_brand'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Brand',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required sp-required cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_brand',
    'label' => 'Brand',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-product_details-field_buyer'
  $field_instances['node-product_details-field_buyer'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Reference to BMB employee who purchases product',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 139,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 166,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_buyer',
    'label' => 'Buyer/Planner',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 128,
    ),
  );

  // Exported field_instance: 'node-product_details-field_calcium_value'
  $field_instances['node-product_details-field_calcium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 87,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 101,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_calcium_value',
    'label' => 'Calcium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 43,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_calories_from_fat_value'
  $field_instances['node-product_details-field_calories_from_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 68,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 82,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_calories_from_fat_value',
    'label' => 'Calories From Fat',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-product_details-field_calories_value'
  $field_instances['node-product_details-field_calories_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 67,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 81,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_calories_value',
    'label' => 'Calories',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_cube'
  $field_instances['node-product_details-field_case_cube'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Case size in cu. ft.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 133,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 156,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_cube',
    'label' => 'Quantity Per Cube',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_compute_field_case_cube',
      ),
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 114,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_gtin'
  $field_instances['node-product_details-field_case_gtin'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Linked to Product GTIN?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required',
        ),
        'type' => 'text_default',
        'weight' => 125,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 147,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_gtin',
    'label' => 'Master Case GTIN',
    'required' => 0,
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_height'
  $field_instances['node-product_details-field_case_height'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '&gt;0, &lt;999.999',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 126,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 149,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_height',
    'label' => 'Master Case Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 113,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_length'
  $field_instances['node-product_details-field_case_length'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '&gt;0, &lt;999.999',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 128,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 151,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_length',
    'label' => 'Master Case Length',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 111,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_net_weight'
  $field_instances['node-product_details-field_case_net_weight'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '&gt;0, &lt;999.999',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 155,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 155,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_net_weight',
    'label' => 'Net Case Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 123,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_net_weight_uom'
  $field_instances['node-product_details-field_case_net_weight_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Default LB',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'crm-required',
        ),
        'type' => 'list_default',
        'weight' => 154,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 154,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_net_weight_uom',
    'label' => 'Net Case Weight UOM',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 124,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_pack'
  $field_instances['node-product_details-field_case_pack'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Quantity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22.1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_pack',
    'label' => 'Case Pack',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 182,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_upc'
  $field_instances['node-product_details-field_case_upc'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Copy from product UPC option',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 124,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 146,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_upc',
    'label' => 'Master Case UPC',
    'required' => 0,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_weight'
  $field_instances['node-product_details-field_case_weight'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '&gt;0, &lt;999.999',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 130,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 153,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_weight',
    'label' => 'Gross Case Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 121,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_weight_uom'
  $field_instances['node-product_details-field_case_weight_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Default LB',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 129,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 152,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_weight_uom',
    'label' => 'Gross Case Weight UOM',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 122,
    ),
  );

  // Exported field_instance: 'node-product_details-field_case_width'
  $field_instances['node-product_details-field_case_width'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '&gt;0, &lt;999.999',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 127,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 150,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_case_width',
    'label' => 'Master Case Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 112,
    ),
  );

  // Exported field_instance: 'node-product_details-field_category'
  $field_instances['node-product_details-field_category'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Macola Category',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22.9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category',
    'label' => 'Product Category',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 189,
    ),
  );

  // Exported field_instance: 'node-product_details-field_certified_humane'
  $field_instances['node-product_details-field_certified_humane'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'file_default',
        'weight' => 55,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_certified_humane',
    'label' => 'Humane Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-product_details-field_certified_vegan'
  $field_instances['node-product_details-field_certified_vegan'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'file_default',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_certified_vegan',
    'label' => 'Vegan Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-product_details-field_chicago_water_tax'
  $field_instances['node-product_details-field_chicago_water_tax'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 146,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 179,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chicago_water_tax',
    'label' => 'Chicago Water Tax',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 109,
    ),
  );

  // Exported field_instance: 'node-product_details-field_chloride_value'
  $field_instances['node-product_details-field_chloride_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 123,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 123,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chloride_value',
    'label' => 'Chloride',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 65,
    ),
  );

  // Exported field_instance: 'node-product_details-field_cholesterol_value'
  $field_instances['node-product_details-field_cholesterol_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 74,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 88,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cholesterol_value',
    'label' => 'Cholesterol',
    'required' => 0,
    'settings' => array(
      'max' => 1000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-product_details-field_chromium_value'
  $field_instances['node-product_details-field_chromium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 121,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 121,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chromium_value',
    'label' => 'Chromium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 63,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_closed_code_life_dating'
  $field_instances['node-product_details-field_closed_code_life_dating'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'sp-required',
        ),
        'type' => 'text_default',
        'weight' => 158,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 193,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_closed_code_life_dating',
    'label' => 'Closed Code Life Dating',
    'required' => 0,
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
      'weight' => 181,
    ),
  );

  // Exported field_instance: 'node-product_details-field_container_type'
  $field_instances['node-product_details-field_container_type'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'See comment',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 117,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 134,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_container_type',
    'label' => 'Container Type',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 113,
    ),
  );

  // Exported field_instance: 'node-product_details-field_contract_number'
  $field_instances['node-product_details-field_contract_number'] = array(
    'bundle' => 'product_details',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'text_default',
        'weight' => 222,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 222,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_contract_number',
    'label' => 'Contract Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_contract_number',
      ),
      'module' => 'text',
      'settings' => array(
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-product_details-field_controlled'
  $field_instances['node-product_details-field_controlled'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 214,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 214,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_controlled',
    'label' => 'Controlled',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_controlled',
      ),
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-product_details-field_copper_value'
  $field_instances['node-product_details-field_copper_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 119,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 119,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_copper_value',
    'label' => 'Copper',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 61,
    ),
  );

  // Exported field_instance: 'node-product_details-field_cost_end_date'
  $field_instances['node-product_details-field_cost_end_date'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 217,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 217,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cost_end_date',
    'label' => 'Cost End Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'strtotime',
      'default_value2' => 'same',
      'default_value_code' => '2025-12-31 00:00:00',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_cost_end_date',
      ),
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-product_details-field_country_of_origin'
  $field_instances['node-product_details-field_country_of_origin'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'See comment',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_country_of_origin',
    'label' => 'Primary Country of Origin',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-product_details-field_cube_height'
  $field_instances['node-product_details-field_cube_height'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 121,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 141,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cube_height',
    'label' => 'Inner Pack Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'in',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 120,
    ),
  );

  // Exported field_instance: 'node-product_details-field_cube_length'
  $field_instances['node-product_details-field_cube_length'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 123,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 143,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cube_length',
    'label' => 'Inner Pack Length',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'in',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 118,
    ),
  );

  // Exported field_instance: 'node-product_details-field_cube_width'
  $field_instances['node-product_details-field_cube_width'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 122,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 142,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cube_width',
    'label' => 'Inner Pack Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'in',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 119,
    ),
  );

  // Exported field_instance: 'node-product_details-field_dietary_fiber_value'
  $field_instances['node-product_details-field_dietary_fiber_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 78,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 92,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dietary_fiber_value',
    'label' => 'Dietary Fiber',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-product_details-field_dietary_preference'
  $field_instances['node-product_details-field_dietary_preference'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dietary_preference',
    'label' => 'Dietary Preference',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-product_details-field_east_fob_location'
  $field_instances['node-product_details-field_east_fob_location'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 234,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_east_fob_location',
    'label' => 'East FOB Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 145,
    ),
  );

  // Exported field_instance: 'node-product_details-field_enrobed_in_chocolate_'
  $field_instances['node-product_details-field_enrobed_in_chocolate_'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'sp-required unfi-required',
        ),
        'type' => 'list_default',
        'weight' => 150,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 185,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_enrobed_in_chocolate_',
    'label' => 'Enrobed in Chocolate',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 150,
    ),
  );

  // Exported field_instance: 'node-product_details-field_ethnic_attributes'
  $field_instances['node-product_details-field_ethnic_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is limited to the supplier portal',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ethnic_attributes',
    'label' => 'Ethnic',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_fair_trade_certificate'
  $field_instances['node-product_details-field_fair_trade_certificate'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'file_default',
        'weight' => 56,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fair_trade_certificate',
    'label' => 'Fair Trade Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-product_details-field_folate_value'
  $field_instances['node-product_details-field_folate_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 110,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 110,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_folate_value',
    'label' => 'Folate',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 52,
    ),
  );

  // Exported field_instance: 'node-product_details-field_forecast_number'
  $field_instances['node-product_details-field_forecast_number'] = array(
    'bundle' => 'product_details',
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
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 225,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_forecast_number',
    'label' => 'Forecast Number',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-product_details-field_free_of_attributes'
  $field_instances['node-product_details-field_free_of_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Gluten, BPA, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_free_of_attributes',
    'label' => 'Free of Substances',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_freight_protection_from'
  $field_instances['node-product_details-field_freight_protection_from'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required unfi-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 149,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 184,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_freight_protection_from',
    'label' => 'Freight Protection From',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 149,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_freight_protection_level'
  $field_instances['node-product_details-field_freight_protection_level'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Chill, Dry, Frozen, Grain room',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 159,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 194,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_freight_protection_level',
    'label' => 'Freight Protection Level',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 148,
    ),
  );

  // Exported field_instance: 'node-product_details-field_gluten_attributes'
  $field_instances['node-product_details-field_gluten_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'crm-required',
        ),
        'type' => 'text_default',
        'weight' => 239,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gluten_attributes',
    'label' => 'Gluten Attributes',
    'required' => 0,
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
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-product_details-field_gluten_free'
  $field_instances['node-product_details-field_gluten_free'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gluten_free',
    'label' => 'Gluten Free Certification Agency',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_gluten_free_certificate'
  $field_instances['node-product_details-field_gluten_free_certificate'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'file_default',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gluten_free_certificate',
    'label' => 'Gluten Free Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-product_details-field_grocery_type'
  $field_instances['node-product_details-field_grocery_type'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 185,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_grocery_type',
    'label' => 'Grocery Type',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 144,
    ),
  );

  // Exported field_instance: 'node-product_details-field_gtin'
  $field_instances['node-product_details-field_gtin'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '14 Digit #',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'sp-required ',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtin',
    'label' => 'GTIN',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-product_details-field_guaranteed_shelf_life'
  $field_instances['node-product_details-field_guaranteed_shelf_life'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 184,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_guaranteed_shelf_life',
    'label' => 'Guaranteed Shelf Life',
    'required' => 0,
    'settings' => array(
      'max' => 999,
      'min' => 1,
      'prefix' => '',
      'suffix' => 'days',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_compute_guaranteed_shelf_life',
      ),
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 183,
    ),
  );

  // Exported field_instance: 'node-product_details-field_high'
  $field_instances['node-product_details-field_high'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Layers per pallet',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 138,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 163,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_high',
    'label' => 'Hi',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 127,
    ),
  );

  // Exported field_instance: 'node-product_details-field_ingredients'
  $field_instances['node-product_details-field_ingredients'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required',
        ),
        'type' => 'text_default',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ingredients',
    'label' => 'Ingredients List (Full)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-product_details-field_ingredients_print'
  $field_instances['node-product_details-field_ingredients_print'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required',
        ),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ingredients_print',
    'label' => 'Ingredients List (Printed & Displayed)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-product_details-field_inner_case_pack'
  $field_instances['node-product_details-field_inner_case_pack'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Quantity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22.2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inner_case_pack',
    'label' => 'Inner Case Pack',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 183,
    ),
  );

  // Exported field_instance: 'node-product_details-field_inner_pack_gtin'
  $field_instances['node-product_details-field_inner_pack_gtin'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Linked to Product GTIN?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required',
        ),
        'type' => 'text_default',
        'weight' => 120,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 139,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inner_pack_gtin',
    'label' => 'Inner Pack GTIN',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-product_details-field_inner_pack_upc'
  $field_instances['node-product_details-field_inner_pack_upc'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Always needed but may or may not be the same as UNIT UPC',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required activation-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 119,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 138,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inner_pack_upc',
    'label' => 'Inner Pack UPC',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-product_details-field_insoluble_fiber_value'
  $field_instances['node-product_details-field_insoluble_fiber_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 80,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 94,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_insoluble_fiber_value',
    'label' => 'Insoluble Fiber',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-product_details-field_inv_transaction_audit'
  $field_instances['node-product_details-field_inv_transaction_audit'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 215,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 215,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inv_transaction_audit',
    'label' => 'Inventory Transaction Audit',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_inv_transaction_audit',
      ),
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product_details-field_iodine_value'
  $field_instances['node-product_details-field_iodine_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 115,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 115,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_iodine_value',
    'label' => 'Iodine',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 57,
    ),
  );

  // Exported field_instance: 'node-product_details-field_iron_value'
  $field_instances['node-product_details-field_iron_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 88,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 102,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_iron_value',
    'label' => 'Iron',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_description'
  $field_instances['node-product_details-field_item_description'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Macola Description',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required macola-required sp-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_description',
    'label' => 'Item Description',
    'required' => 0,
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
      'weight' => 180,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_description_2'
  $field_instances['node-product_details-field_item_description_2'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Overflow Description + Brand',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required macola-required sp-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_description_2',
    'label' => 'Item Description 2',
    'required' => 0,
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
      'weight' => 181,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_num'
  $field_instances['node-product_details-field_item_num'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'macola-required activation-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_num',
    'label' => 'Macola Item Number',
    'required' => 0,
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_size'
  $field_instances['node-product_details-field_item_size'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required sp-required cloud-web-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_size',
    'label' => 'Retail Size Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 130,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_size_uom'
  $field_instances['node-product_details-field_item_size_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select from List',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_size_uom',
    'label' => 'Retail Size Weight UOM',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 131,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_weight'
  $field_instances['node-product_details-field_item_weight'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'See Comment',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_weight',
    'label' => 'Retail Unit Weight Drained',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 132,
    ),
  );

  // Exported field_instance: 'node-product_details-field_item_weight_uom'
  $field_instances['node-product_details-field_item_weight_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'ounces',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'list_default',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_item_weight_uom',
    'label' => 'Retail Unit Weight Drained UOM',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 133,
    ),
  );

  // Exported field_instance: 'node-product_details-field_itrade_export'
  $field_instances['node-product_details-field_itrade_export'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included in export to this customer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 209,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 209,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_itrade_export',
    'label' => 'iTrade Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-product_details-field_ix_one_export'
  $field_instances['node-product_details-field_ix_one_export'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included in export to this customer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 210,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 210,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ix_one_export',
    'label' => 'IX-One Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-product_details-field_juice_percent'
  $field_instances['node-product_details-field_juice_percent'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'number',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 124,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 124,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_juice_percent',
    'label' => '% Juice',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 66,
    ),
  );

  // Exported field_instance: 'node-product_details-field_kosher_certificate'
  $field_instances['node-product_details-field_kosher_certificate'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'sp-required cloud-web-required',
        ),
        'type' => 'file_default',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_certificate',
    'label' => 'Kosher Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_kosher_certifying_agency'
  $field_instances['node-product_details-field_kosher_certifying_agency'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 188,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_certifying_agency',
    'label' => 'Kosher Certifying Agency',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-product_details-field_kosher_daily'
  $field_instances['node-product_details-field_kosher_daily'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_daily',
    'label' => 'Kosher - Daily',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-product_details-field_kosher_mbuf'
  $field_instances['node-product_details-field_kosher_mbuf'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '"May Be Used For" Will never be used',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_mbuf',
    'label' => 'Kosher - MBUF',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-product_details-field_kosher_pareve'
  $field_instances['node-product_details-field_kosher_pareve'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 49,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_pareve',
    'label' => 'Kosher - Pareve',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-product_details-field_kosher_passover'
  $field_instances['node-product_details-field_kosher_passover'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_kosher_passover',
    'label' => 'Kosher - Passover Only',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-product_details-field_lead_time_customer'
  $field_instances['node-product_details-field_lead_time_customer'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'weeks',
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
        'weight' => 186,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 186,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lead_time_customer',
    'label' => 'Customer Order Lead Time',
    'required' => 0,
    'settings' => array(
      'max' => 99,
      'min' => 1,
      'prefix' => '',
      'suffix' => 'weeks',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 135,
    ),
  );

  // Exported field_instance: 'node-product_details-field_lead_time_printing'
  $field_instances['node-product_details-field_lead_time_printing'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'weeks',
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
        'weight' => 188,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 188,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lead_time_printing',
    'label' => 'Printing Lead Time',
    'required' => 0,
    'settings' => array(
      'max' => 99,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 137,
    ),
  );

  // Exported field_instance: 'node-product_details-field_lead_time_shipping'
  $field_instances['node-product_details-field_lead_time_shipping'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'weeks',
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
        'weight' => 187,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 187,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_lead_time_shipping',
    'label' => 'Shipping Lead Time',
    'required' => 0,
    'settings' => array(
      'max' => 99,
      'min' => 1,
      'prefix' => '',
      'suffix' => 'weeks',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 136,
    ),
  );

  // Exported field_instance: 'node-product_details-field_macola_id'
  $field_instances['node-product_details-field_macola_id'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'UPC-12 less check digit',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_macola_id',
    'label' => 'Macola ID',
    'required' => 0,
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
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-product_details-field_magnesium_value'
  $field_instances['node-product_details-field_magnesium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 116,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 116,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_magnesium_value',
    'label' => 'Magnesium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 58,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_major_allergen_attributes'
  $field_instances['node-product_details-field_major_allergen_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Big 8',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_major_allergen_attributes',
    'label' => 'Major Allergens',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-product_details-field_manganese_value'
  $field_instances['node-product_details-field_manganese_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 120,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 120,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_manganese_value',
    'label' => 'Manganese',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 62,
    ),
  );

  // Exported field_instance: 'node-product_details-field_manufacturing_method'
  $field_instances['node-product_details-field_manufacturing_method'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 223,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 223,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_manufacturing_method',
    'label' => 'Manufacturing Method',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'label_field' => 'field_enum_id',
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 187,
    ),
  );

  // Exported field_instance: 'node-product_details-field_manufacturing_uom'
  $field_instances['node-product_details-field_manufacturing_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 220,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 220,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_manufacturing_uom',
    'label' => 'Manufacturing Units',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_manufacturing_uom',
      ),
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_marine_stewardship_agency'
  $field_instances['node-product_details-field_marine_stewardship_agency'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Certification code assigned by MSC in Row 74',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'text_default',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 71,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marine_stewardship_agency',
    'label' => 'Marine Stewardship Certifying Agency',
    'required' => 0,
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
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_marine_stewardship_cert'
  $field_instances['node-product_details-field_marine_stewardship_cert'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
        ),
        'type' => 'file_default',
        'weight' => 58,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marine_stewardship_cert',
    'label' => 'Marine Stewardship Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-product_details-field_master_case_pack'
  $field_instances['node-product_details-field_master_case_pack'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Quantity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22.3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_master_case_pack',
    'label' => 'Master Case Pack',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 184,
    ),
  );

  // Exported field_instance: 'node-product_details-field_material_cost_type'
  $field_instances['node-product_details-field_material_cost_type'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'See comment',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 141,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 168,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_material_cost_type',
    'label' => 'Material Cost Type',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 188,
    ),
  );

  // Exported field_instance: 'node-product_details-field_minimum_order_qty'
  $field_instances['node-product_details-field_minimum_order_qty'] = array(
    'bundle' => 'product_details',
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
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 172,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 172,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_minimum_order_qty',
    'label' => 'Vendor Minimum Order Quantity',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 133,
    ),
  );

  // Exported field_instance: 'node-product_details-field_molybdenum_value'
  $field_instances['node-product_details-field_molybdenum_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 122,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 122,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_molybdenum_value',
    'label' => 'Molybdenum',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 64,
    ),
  );

  // Exported field_instance: 'node-product_details-field_monounsat_fat_value'
  $field_instances['node-product_details-field_monounsat_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 87,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 87,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_monounsat_fat_value',
    'label' => 'Monounsaturated Fat',
    'required' => 0,
    'settings' => array(
      'max' => 40,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_net_carbohydrate_value'
  $field_instances['node-product_details-field_net_carbohydrate_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 95,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 95,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_net_carbohydrate_value',
    'label' => 'Net Carbohydrates',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-product_details-field_niacin_value'
  $field_instances['node-product_details-field_niacin_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 108,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 108,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_niacin_value',
    'label' => 'Niacin',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 50,
    ),
  );

  // Exported field_instance: 'node-product_details-field_non_gmo'
  $field_instances['node-product_details-field_non_gmo'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If Applicable',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_non_gmo',
    'label' => 'Non-GMO Project',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-product_details-field_omega3_value'
  $field_instances['node-product_details-field_omega3_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_omega3_value',
    'label' => 'Omega-3 Content',
    'required' => 0,
    'settings' => array(
      'max' => 25000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-product_details-field_open_code_life_dating'
  $field_instances['node-product_details-field_open_code_life_dating'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 157,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 192,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_open_code_life_dating',
    'label' => 'Open Code Life Dating',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 180,
    ),
  );

  // Exported field_instance: 'node-product_details-field_organic_attributes'
  $field_instances['node-product_details-field_organic_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '>70%, >95%, =100%',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organic_attributes',
    'label' => 'Organic %',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-product_details-field_organic_certificate'
  $field_instances['node-product_details-field_organic_certificate'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'sp-required cloud-web-required crm-required',
        ),
        'type' => 'file_default',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 72,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organic_certificate',
    'label' => 'Organic Certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx png gif jpg jpeg txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-product_details-field_organic_certifier'
  $field_instances['node-product_details-field_organic_certifier'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 61,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organic_certifier',
    'label' => 'Organic Certifying Agency',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pack_height'
  $field_instances['node-product_details-field_pack_height'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 111,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 128,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pack_height',
    'label' => 'Retail Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'inches',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 117,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pack_length'
  $field_instances['node-product_details-field_pack_length'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 113,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 130,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pack_length',
    'label' => 'Retail Length',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'inches',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 115,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pack_width'
  $field_instances['node-product_details-field_pack_width'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 112,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 129,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pack_width',
    'label' => 'Retail Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'inches',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 116,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pallet_height'
  $field_instances['node-product_details-field_pallet_height'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 160,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 160,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pallet_height',
    'label' => 'Pallet Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'in',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 128,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pallet_weight'
  $field_instances['node-product_details-field_pallet_weight'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'lbs',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 3,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 161,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 161,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pallet_weight',
    'label' => 'Pallet Weight',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'lb',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 129,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_pantothenic_acid_value'
  $field_instances['node-product_details-field_pantothenic_acid_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 113,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 113,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pantothenic_acid_value',
    'label' => 'Pantothenic Acid',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 55,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_paperb_recycle_percent'
  $field_instances['node-product_details-field_paperb_recycle_percent'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 114,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 131,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_paperb_recycle_percent',
    'label' => '% Paperboard Recyclable',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 106,
    ),
  );

  // Exported field_instance: 'node-product_details-field_phosphorous_value'
  $field_instances['node-product_details-field_phosphorous_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 114,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 114,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_phosphorous_value',
    'label' => 'Phosphorous',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 56,
    ),
  );

  // Exported field_instance: 'node-product_details-field_po_req_fg'
  $field_instances['node-product_details-field_po_req_fg'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 180,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 224,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_po_req_fg',
    'label' => 'Use OE to PO',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 147,
    ),
  );

  // Exported field_instance: 'node-product_details-field_polyunsat_fat_value'
  $field_instances['node-product_details-field_polyunsat_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => '',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 86,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 86,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_polyunsat_fat_value',
    'label' => 'Polyunsaturated Fat',
    'required' => 0,
    'settings' => array(
      'max' => 40,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product_details-field_potassium_value'
  $field_instances['node-product_details-field_potassium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 76,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 90,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_potassium_value',
    'label' => 'Potassium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-product_details-field_price_basis_code'
  $field_instances['node-product_details-field_price_basis_code'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 'P',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'text_default',
        'weight' => 221,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 221,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_price_basis_code',
    'label' => 'Price Basis Code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_price_basis_code',
      ),
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-product_details-field_price_uom'
  $field_instances['node-product_details-field_price_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 219,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 219,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_price_uom',
    'label' => 'Selling Units',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_price_uom',
      ),
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-product_details-field_primary_image'
  $field_instances['node-product_details-field_primary_image'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => 'Used for web',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'field_formatter_class' => '',
          'image_link' => '',
          'image_style' => 'thumbnail',
        ),
        'type' => 'image',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_primary_image',
    'label' => 'Primary Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'primary_image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-product_details-field_primary_location'
  $field_instances['node-product_details-field_primary_location'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Primary Warehouse',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 160,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 195,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_primary_location',
    'label' => 'Primary Location',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 143,
    ),
  );

  // Exported field_instance: 'node-product_details-field_processing_attributes'
  $field_instances['node-product_details-field_processing_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Allergens handled in the facility',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_processing_attributes',
    'label' => 'Processing Attributes',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-product_details-field_product_intro_date'
  $field_instances['node-product_details-field_product_intro_date'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => 'UNFI Published Launch Month',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_formatter_class' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_intro_date',
    'label' => 'Product Intro Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-product_details-field_product_labels'
  $field_instances['node-product_details-field_product_labels'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => 'Allowed file types PDF, PNG, JPEG, GIF',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => 'unfi-required sp-required',
        ),
        'type' => 'file_default',
        'weight' => 118,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 135,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_labels',
    'label' => 'Product Labels',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf png jpg jpeg gif',
      'max_filesize' => '100mb',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 114,
    ),
  );

  // Exported field_instance: 'node-product_details-field_protein_value'
  $field_instances['node-product_details-field_protein_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 84,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 98,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_protein_value',
    'label' => 'Protein',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-product_details-field_pur_or_mfg'
  $field_instances['node-product_details-field_pur_or_mfg'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 144,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 171,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pur_or_mfg',
    'label' => 'Manufacturing Method',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_pur_or_mfg',
      ),
      'label_field' => 'field_macola_name',
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-product_details-field_purchasing_uom'
  $field_instances['node-product_details-field_purchasing_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 218,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 218,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_purchasing_uom',
    'label' => 'Purchasing Units',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_purchasing_uom',
      ),
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-product_details-field_random_weight'
  $field_instances['node-product_details-field_random_weight'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'sp-required',
        ),
        'type' => 'list_default',
        'weight' => 134,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 157,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_random_weight',
    'label' => 'Random Weight Item',
    'required' => 0,
    'settings' => array(
      'required_by_role' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 125,
    ),
  );

  // Exported field_instance: 'node-product_details-field_riboflavin_value'
  $field_instances['node-product_details-field_riboflavin_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 107,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 107,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_riboflavin_value',
    'label' => 'Riboflavin',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 49,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_salt_content_attributes'
  $field_instances['node-product_details-field_salt_content_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_salt_content_attributes',
    'label' => 'Salt Content',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-product_details-field_saturated_fat_value'
  $field_instances['node-product_details-field_saturated_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 70,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 84,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_saturated_fat_value',
    'label' => 'Saturated Fat',
    'required' => 0,
    'settings' => array(
      'max' => 80,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_secondary_allergen_attr'
  $field_instances['node-product_details-field_secondary_allergen_attr'] = array(
    'bundle' => 'product_details',
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
        'weight' => 238,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_secondary_allergen_attr',
    'label' => 'Additional Allergens',
    'required' => 0,
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
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-product_details-field_selenium_value'
  $field_instances['node-product_details-field_selenium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 118,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 118,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_selenium_value',
    'label' => 'Selenium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 60,
    ),
  );

  // Exported field_instance: 'node-product_details-field_serial_lot'
  $field_instances['node-product_details-field_serial_lot'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 183,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_serial_lot',
    'label' => 'Serial/Lot',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 177,
    ),
  );

  // Exported field_instance: 'node-product_details-field_serving_size_string'
  $field_instances['node-product_details-field_serving_size_string'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Colloquial, Human-Readable',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required',
        ),
        'type' => 'text_default',
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 77.999,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_serving_size_string',
    'label' => 'Serving Size',
    'required' => 0,
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
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-product_details-field_serving_size_uom'
  $field_instances['node-product_details-field_serving_size_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Units',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 79,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 79,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_serving_size_uom',
    'label' => 'Serving Size UOM',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-product_details-field_serving_size_value'
  $field_instances['node-product_details-field_serving_size_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Number',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 64,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 78,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_serving_size_value',
    'label' => 'Serving Size',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_servings_per_cont_value'
  $field_instances['node-product_details-field_servings_per_cont_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 66,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 80,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_servings_per_cont_value',
    'label' => 'Servings Per Container',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => 'About ',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-product_details-field_shelf_life_days'
  $field_instances['node-product_details-field_shelf_life_days'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required cloud-web-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 155,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 190,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_shelf_life_days',
    'label' => 'Shelf Life Days',
    'required' => 0,
    'settings' => array(
      'max' => 999,
      'min' => 1,
      'prefix' => '',
      'suffix' => 'days',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 178,
    ),
  );

  // Exported field_instance: 'node-product_details-field_short_description'
  $field_instances['node-product_details-field_short_description'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Marketing Description',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_short_description',
    'label' => 'Product Description',
    'required' => 0,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-product_details-field_sodium_value'
  $field_instances['node-product_details-field_sodium_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 75,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 89,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sodium_value',
    'label' => 'Sodium',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-product_details-field_soluble_fiber_value'
  $field_instances['node-product_details-field_soluble_fiber_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 79,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 93,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_soluble_fiber_value',
    'label' => 'Soluble Fiber',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-product_details-field_spins_category'
  $field_instances['node-product_details-field_spins_category'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'As defined by SPINS',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_spins_category',
    'label' => 'SPINS Category',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-product_details-field_spins_product_type'
  $field_instances['node-product_details-field_spins_product_type'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'As defined by SPINS',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_spins_product_type',
    'label' => 'SPINS Product Type',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-product_details-field_state_of_origin'
  $field_instances['node-product_details-field_state_of_origin'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_state_of_origin',
    'label' => 'Primary State of Origin',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-product_details-field_stocked'
  $field_instances['node-product_details-field_stocked'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 216,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 216,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stocked',
    'label' => 'Stocked',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_stocked',
      ),
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-product_details-field_stocking_uom'
  $field_instances['node-product_details-field_stocking_uom'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Cases, Each, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required',
        ),
        'type' => 'list_default',
        'weight' => 140,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 167,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stocking_uom',
    'label' => 'Stocking Units',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 190,
    ),
  );

  // Exported field_instance: 'node-product_details-field_sugar_value'
  $field_instances['node-product_details-field_sugar_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 82,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 96,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sugar_value',
    'label' => 'Sugars',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-product_details-field_sweetener_attributes'
  $field_instances['node-product_details-field_sweetener_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required sp-required cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sweetener_attributes',
    'label' => 'Sweetener',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product_details-field_target_export'
  $field_instances['node-product_details-field_target_export'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included in export to this customer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 206,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 206,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_target_export',
    'label' => 'Target Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-product_details-field_taxable'
  $field_instances['node-product_details-field_taxable'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'unfi-required macola-required sp-required',
        ),
        'type' => 'list_default',
        'weight' => 169,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 213,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_taxable',
    'label' => 'Taxable',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'computation_callbacks' => array(
        0 => '_bmb_product_details_update_macola_only_field_taxable',
      ),
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 107,
    ),
  );

  // Exported field_instance: 'node-product_details-field_thiamin_value'
  $field_instances['node-product_details-field_thiamin_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 106,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 106,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_thiamin_value',
    'label' => 'Thiamin',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 48,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_third_party_certificates'
  $field_instances['node-product_details-field_third_party_certificates'] = array(
    'bundle' => 'product_details',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'file_default',
        'weight' => 242,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_third_party_certificates',
    'label' => 'Third Party Certificates',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf png jpg jpeg gif',
      'max_filesize' => '100mb',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-product_details-field_tie'
  $field_instances['node-product_details-field_tie'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Cases per layer',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required sp-required crm-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 137,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 162,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tie',
    'label' => 'Ti',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 126,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_total_carbohydrate_value'
  $field_instances['node-product_details-field_total_carbohydrate_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 77,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 91,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_total_carbohydrate_value',
    'label' => 'Total Carbohydrates',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-product_details-field_total_fat_value'
  $field_instances['node-product_details-field_total_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 69,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 83,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_total_fat_value',
    'label' => 'Total Fat',
    'required' => 0,
    'settings' => array(
      'max' => 1000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-product_details-field_trans_fat_value'
  $field_instances['node-product_details-field_trans_fat_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 71,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 85,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_trans_fat_value',
    'label' => 'Trans Fat',
    'required' => 0,
    'settings' => array(
      'max' => 40,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_type_of_code_life_dating'
  $field_instances['node-product_details-field_type_of_code_life_dating'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'sp-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 156,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 191,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_type_of_code_life_dating',
    'label' => 'Type of Code Life Dating',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 179,
    ),
  );

  // Exported field_instance: 'node-product_details-field_unfi_east'
  $field_instances['node-product_details-field_unfi_east'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included in export to this customer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 207,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 207,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unfi_east',
    'label' => 'UNFI East Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product_details-field_unfi_east_id'
  $field_instances['node-product_details-field_unfi_east_id'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is UNFI East Item #',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'sp-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unfi_east_id',
    'label' => 'UBS ID',
    'required' => 0,
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-product_details-field_unfi_west'
  $field_instances['node-product_details-field_unfi_west'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included in export to this customer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 208,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 208,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unfi_west',
    'label' => 'UNFI West Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-product_details-field_unfi_west_id'
  $field_instances['node-product_details-field_unfi_west_id'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is UNFI West Item #',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'sp-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unfi_west_id',
    'label' => 'WBS ID',
    'required' => 0,
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-product_details-field_upc'
  $field_instances['node-product_details-field_upc'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'GTIN-12',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => 'sp-required cloud-web-required crm-required',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_upc',
    'label' => 'UPC (Product/Unit)',
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

  // Exported field_instance: 'node-product_details-field_upc_code_macola'
  $field_instances['node-product_details-field_upc_code_macola'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 'field_case_upc',
      ),
    ),
    'deleted' => 0,
    'description' => 'For EDI.<br />If the UPC field you are looking for is not listed here, then that means it is missing data.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => 'macola-required crm-required',
        ),
        'type' => 'list_default',
        'weight' => 231,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_upc_code_macola',
    'label' => 'UPC Code - Macola',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 191,
    ),
  );

  // Exported field_instance: 'node-product_details-field_veg_attributes'
  $field_instances['node-product_details-field_veg_attributes'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'activation-required cloud-web-required crm-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_veg_attributes',
    'label' => 'Vegan or Vegetarian',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vendor_pricing'
  $field_instances['node-product_details-field_vendor_pricing'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'field_formatter_class' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 237,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vendor_pricing',
    'label' => 'Vendor Pricing Info',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 129,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_a_value'
  $field_instances['node-product_details-field_vitamin_a_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'IU',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 85,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 99,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_a_value',
    'label' => 'Vitamin A',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'IU',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_b12_value'
  $field_instances['node-product_details-field_vitamin_b12_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 111,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 111,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_b12_value',
    'label' => 'Vitamin B12',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 53,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_b6_value'
  $field_instances['node-product_details-field_vitamin_b6_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 109,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 109,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_b6_value',
    'label' => 'Vitamin B6',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 51,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_c_value'
  $field_instances['node-product_details-field_vitamin_c_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 86,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 100,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_c_value',
    'label' => 'Vitamin C',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_d_value'
  $field_instances['node-product_details-field_vitamin_d_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'IU',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 89,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 103,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_d_value',
    'label' => 'Vitamin D',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'IU',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_e_value'
  $field_instances['node-product_details-field_vitamin_e_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'IU',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 104,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 104,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_e_value',
    'label' => 'Vitamin E',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'IU',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-product_details-field_vitamin_k_value'
  $field_instances['node-product_details-field_vitamin_k_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'micrograms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 105,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 105,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_vitamin_k_value',
    'label' => 'Vitamin K',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mcg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-product_details-field_warranty_days'
  $field_instances['node-product_details-field_warranty_days'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 60,
      ),
    ),
    'deleted' => 0,
    'description' => 'days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'macola-required',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 154,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 189,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_warranty_days',
    'label' => 'Warranty Days',
    'required' => 0,
    'settings' => array(
      'max' => 60,
      'min' => 60,
      'prefix' => '',
      'suffix' => 'days',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 182,
    ),
  );

  // Exported field_instance: 'node-product_details-field_web_category'
  $field_instances['node-product_details-field_web_category'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Tagging for Web',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_web_category',
    'label' => 'Secondary Web Category',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-product_details-field_web_export'
  $field_instances['node-product_details-field_web_export'] = array(
    'bundle' => 'product_details',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Yes/No. Indicates if product will be included for BMB websites.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 205,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 205,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_web_export',
    'label' => 'Web Export',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-product_details-field_west_fob_location'
  $field_instances['node-product_details-field_west_fob_location'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 235,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_west_fob_location',
    'label' => 'West FOB Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 146,
    ),
  );

  // Exported field_instance: 'node-product_details-field_whole_grain_council'
  $field_instances['node-product_details-field_whole_grain_council'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_formatter_class' => 'cloud-web-required',
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_whole_grain_council',
    'label' => 'Whole Grain Stamp',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'node-product_details-field_whole_grain_per_serving'
  $field_instances['node-product_details-field_whole_grain_per_serving'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'grams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'activation-required cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_whole_grain_per_serving',
    'label' => 'Whole Grains per Serving',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'g',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-product_details-field_zinc_value'
  $field_instances['node-product_details-field_zinc_value'] = array(
    'bundle' => 'product_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'milligrams',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_class' => 'cloud-web-required',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 117,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 117,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_zinc_value',
    'label' => 'Zinc',
    'required' => 0,
    'settings' => array(
      'max' => 10000,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'mg',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 59,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('"May Be Used For" Will never be used');
  t('% Juice');
  t('% Paperboard Recyclable');
  t('&gt;0, &lt;999.999');
  t('14 Digit #');
  t('>70%, >95%, =100%');
  t('Abbreviation of vendor (supplier) name');
  t('Activity Code');
  t('Activity Date');
  t('Added Sugars');
  t('Additional Allergens');
  t('Additional Images');
  t('Additional Origin Locations');
  t('Alaska Seafood Certificate');
  t('Allergens handled in the facility');
  t('Allergens in Facility');
  t('Allowed file types PDF, PNG, JPEG, GIF');
  t('Allows multiple image uploads');
  t('Always needed but may or may not be the same as UNIT UPC');
  t('Approved Source');
  t('As defined by SPINS');
  t('BMB Category');
  t('BMB Product Type');
  t('Backorderable');
  t('Baltimore Beverage Tax');
  t('Berkeley Beverage Tax');
  t('Beverage Container');
  t('Big 8');
  t('Biotin');
  t('Bottle Color');
  t('Brand');
  t('Buyer/Planner');
  t('Calcium');
  t('Calories');
  t('Calories From Fat');
  t('Case Pack');
  t('Case size in cu. ft.');
  t('Cases per layer');
  t('Cases, Each, etc.');
  t('Certification code assigned by MSC in Row 74');
  t('Chicago Water Tax');
  t('Chill, Dry, Frozen, Grain room');
  t('Chloride');
  t('Cholesterol');
  t('Chromium');
  t('Closed Code Life Dating');
  t('Colloquial, Human-Readable');
  t('Container Type');
  t('Contract Number');
  t('Controlled');
  t('Copper');
  t('Copy from product UPC option');
  t('Cost End Date');
  t('Customer Order Lead Time');
  t('Date of first actual sale');
  t('Default LB');
  t('Dietary Fiber');
  t('Dietary Preference');
  t('East FOB Location');
  t('Enrobed in Chocolate');
  t('Entered if we know it but not essential');
  t('Ethnic');
  t('Example: Flavor "Blueberry / Pomegranate Blend" or type "Juice Blend"');
  t('Example: Frozen');
  t('Fair Trade Certificate');
  t('First Sale Date');
  t('Folate');
  t('For EDI.<br />If the UPC field you are looking for is not listed here, then that means it is missing data.');
  t('Forecast Number');
  t('Free of Substances');
  t('Freight Protection From');
  t('Freight Protection Level');
  t('GTIN');
  t('GTIN-12');
  t('Gluten Attributes');
  t('Gluten Free Certificate');
  t('Gluten Free Certification Agency');
  t('Gluten, BPA, etc.');
  t('Grocery Type');
  t('Gross Case Weight');
  t('Gross Case Weight UOM');
  t('Guaranteed Shelf Life');
  t('Hi');
  t('Humane Certificate');
  t('IU');
  t('IX-One Export');
  t('If Applicable');
  t('Ingredients List (Full)');
  t('Ingredients List (Printed & Displayed)');
  t('Inner Case Pack');
  t('Inner Pack GTIN');
  t('Inner Pack Height');
  t('Inner Pack Length');
  t('Inner Pack UPC');
  t('Inner Pack Width');
  t('Insoluble Fiber');
  t('Inventory Transaction Audit');
  t('Iodine');
  t('Iron');
  t('Item Description');
  t('Item Description 2');
  t('Kosher - Daily');
  t('Kosher - MBUF');
  t('Kosher - Pareve');
  t('Kosher - Passover Only');
  t('Kosher Certificate');
  t('Kosher Certifying Agency');
  t('Layers per pallet');
  t('Linked to Product GTIN?');
  t('Macola Category');
  t('Macola Description');
  t('Macola ID');
  t('Macola Item Number');
  t('Magnesium');
  t('Major Allergens');
  t('Manganese');
  t('Manufacturing Method');
  t('Manufacturing Units');
  t('Marine Stewardship Certificate');
  t('Marine Stewardship Certifying Agency');
  t('Marketing Description');
  t('Master Case GTIN');
  t('Master Case Height');
  t('Master Case Length');
  t('Master Case Pack');
  t('Master Case UPC');
  t('Master Case Width');
  t('Material Cost Type');
  t('Molybdenum');
  t('Monounsaturated Fat');
  t('Net Carbohydrates');
  t('Net Case Weight');
  t('Net Case Weight UOM');
  t('Niacin');
  t('Non-GMO Project');
  t('Number');
  t('Omega-3 Content');
  t('Open Code Life Dating');
  t('Organic %');
  t('Organic Certificate');
  t('Organic Certifying Agency');
  t('Overflow Description + Brand');
  t('Pallet Height');
  t('Pallet Weight');
  t('Pantothenic Acid');
  t('Payment Terms');
  t('Phosphorous');
  t('Polyunsaturated Fat');
  t('Potassium');
  t('Price Basis Code');
  t('Primary Country of Origin');
  t('Primary Image');
  t('Primary Location');
  t('Primary State of Origin');
  t('Primary Warehouse');
  t('Printing Lead Time');
  t('Processing Attributes');
  t('Product Category');
  t('Product Description');
  t('Product Intro Date');
  t('Product Labels');
  t('Protein');
  t('Purchasing Units');
  t('Quantity');
  t('Quantity Per Cube');
  t('Random Weight Item');
  t('Reference to BMB employee who purchases product');
  t('Retail Height');
  t('Retail Length');
  t('Retail Size Weight');
  t('Retail Size Weight UOM');
  t('Retail Unit Weight Drained');
  t('Retail Unit Weight Drained UOM');
  t('Retail Width');
  t('Riboflavin');
  t('SPINS Category');
  t('SPINS Product Type');
  t('Salt Content');
  t('Saturated Fat');
  t('Secondary Web Category');
  t('See Comment');
  t('See comment');
  t('Select from List');
  t('Selenium');
  t('Selling Units');
  t('Serial/Lot');
  t('Serving Size');
  t('Serving Size UOM');
  t('Servings Per Container');
  t('Shelf Life Days');
  t('Shipping Lead Time');
  t('Sodium');
  t('Soluble Fiber');
  t('Stocked');
  t('Stocking Units');
  t('Sugars');
  t('Sweetener');
  t('Tagging for Web');
  t('Target Export');
  t('Taxable');
  t('The current activity state of the product.');
  t('Thiamin');
  t('Third Party Certificates');
  t('This is UNFI East Item #');
  t('This is UNFI West Item #');
  t('This is limited to the supplier portal');
  t('Ti');
  t('Total Carbohydrates');
  t('Total Fat');
  t('Trans Fat');
  t('Type of Code Life Dating');
  t('UBS ID');
  t('UNFI East Export');
  t('UNFI Published Launch Month');
  t('UNFI West Export');
  t('UPC (Product/Unit)');
  t('UPC Code - Macola');
  t('UPC-12 less check digit');
  t('Units');
  t('Use OE to PO');
  t('Used for web');
  t('Vegan Certificate');
  t('Vegan or Vegetarian');
  t('Vendor ID Number');
  t('Vendor Item Number');
  t('Vendor Minimum Order Quantity');
  t('Vendor Pricing Info');
  t('View Only from Macola');
  t('Vitamin A');
  t('Vitamin B12');
  t('Vitamin B6');
  t('Vitamin C');
  t('Vitamin D');
  t('Vitamin E');
  t('Vitamin K');
  t('WBS ID');
  t('Warranty Days');
  t('Web Export');
  t('West FOB Location');
  t('Whole Grain Stamp');
  t('Whole Grains per Serving');
  t('Yes/No');
  t('Yes/No. Indicates if product will be included for BMB websites.');
  t('Yes/No. Indicates if product will be included in export to this customer.');
  t('Zinc');
  t('days');
  t('grams');
  t('iTrade Export');
  t('inches');
  t('lbs');
  t('micrograms');
  t('milligrams');
  t('number');
  t('ounces');
  t('weeks');

  return $field_instances;
}
