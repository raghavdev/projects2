<?php
/**
 * @file
 * digital_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function digital_core_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_desc_ext_desc|node|product_details|form';
  $field_group->group_name = 'group_desc_ext_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_descriptions';
  $field_group->data = array(
    'label' => 'Extended Description',
    'weight' => '71',
    'children' => array(
      0 => 'field_extended_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-desc-ext-desc field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_desc_ext_desc|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_desc_flyer_desc|node|product_details|form';
  $field_group->group_name = 'group_desc_flyer_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_descriptions';
  $field_group->data = array(
    'label' => 'Flyer Description',
    'weight' => '70',
    'children' => array(
      0 => 'field_flyer_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-desc-flyer-desc field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_desc_flyer_desc|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_desc_html_desc|node|product_details|form';
  $field_group->group_name = 'group_desc_html_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_descriptions';
  $field_group->data = array(
    'label' => 'Detailed HTML Description',
    'weight' => '72',
    'children' => array(
      0 => 'field_html_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-desc-html-desc field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_desc_html_desc|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descriptions|node|product_details|form';
  $field_group->group_name = 'group_descriptions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Descriptions',
    'weight' => '79',
    'children' => array(
      0 => 'group_desc_ext_desc',
      1 => 'group_desc_flyer_desc',
      2 => 'group_desc_html_desc',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-descriptions field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_descriptions|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|product_details|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '78',
    'children' => array(
      0 => 'field_primary_image',
      1 => 'field_planogram_front_image',
      2 => 'field_planogram_side_image',
      3 => 'field_planogram_top_image',
      4 => 'field_nutritional_label_image',
      5 => 'field_print_image',
      6 => 'field_additional_images',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_images|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marketing_bullets|node|product_details|form';
  $field_group->group_name = 'group_marketing_bullets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_marketing';
  $field_group->data = array(
    'label' => 'Bullets',
    'weight' => '62',
    'children' => array(
      0 => 'field_feature1',
      1 => 'field_feature2',
      2 => 'field_feature3',
      3 => 'field_feature4',
      4 => 'field_feature5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-marketing-bullets field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_marketing_bullets|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marketing_keywords|node|product_details|form';
  $field_group->group_name = 'group_marketing_keywords';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_marketing';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '61',
    'children' => array(
      0 => 'field_keywords',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-marketing-keywords field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_marketing_keywords|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marketing_man_info|node|product_details|form';
  $field_group->group_name = 'group_marketing_man_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_marketing';
  $field_group->data = array(
    'label' => 'Manufacturer Information',
    'weight' => '59',
    'children' => array(
      0 => 'field_manufacturer_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-marketing-man-info field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_marketing_man_info|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marketing|node|product_details|form';
  $field_group->group_name = 'group_marketing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Marketing',
    'weight' => '77',
    'children' => array(
      0 => 'group_marketing_recipes',
      1 => 'group_marketing_bullets',
      2 => 'group_marketing_keywords',
      3 => 'group_marketing_man_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-marketing field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_marketing|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nutritional_allergens|node|product_details|form';
  $field_group->group_name = 'group_nutritional_allergens';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nutritional';
  $field_group->data = array(
    'label' => 'Allergens',
    'weight' => '66',
    'children' => array(
      0 => 'field_alergens',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nutritional-allergens field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_nutritional_allergens|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nutritional_information|node|product_details|form';
  $field_group->group_name = 'group_nutritional_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nutritional';
  $field_group->data = array(
    'label' => 'Nutritional Information',
    'weight' => '67',
    'children' => array(
      0 => 'field_serving_size',
      1 => 'field_servings_per_container',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nutritional-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_nutritional_information|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nutritional_ingredients|node|product_details|form';
  $field_group->group_name = 'group_nutritional_ingredients';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nutritional';
  $field_group->data = array(
    'label' => 'Ingredients',
    'weight' => '65',
    'children' => array(
      0 => 'field_ingredients',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nutritional-ingredients field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_nutritional_ingredients|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nutritional|node|product_details|form';
  $field_group->group_name = 'group_nutritional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Nutritional',
    'weight' => '81',
    'children' => array(
      0 => 'group_nutritional_allergens',
      1 => 'group_nutritional_information',
      2 => 'group_nutritional_ingredients',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nutritional field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_nutritional|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other_video_urls|node|product_details|form';
  $field_group->group_name = 'group_other_video_urls';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_other';
  $field_group->data = array(
    'label' => 'Video URLs',
    'weight' => '67',
    'children' => array(
      0 => 'field_video_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-other-video-urls field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_other_video_urls|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|product_details|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '83',
    'children' => array(
      0 => 'group_other_video_urls',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-other field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_other|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_detail_tabs|node|product_details|form';
  $field_group->group_name = 'group_product_detail_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Detail Tabs',
    'weight' => '17',
    'children' => array(
      0 => 'group_attributes',
      1 => 'group_descriptions',
      2 => 'group_images',
      3 => 'group_marketing',
      4 => 'group_nutritional',
      5 => 'group_other',
      6 => 'group_product',
      7 => 'group_specs',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-product-detail-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_product_detail_tabs|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_extended_data|node|product_details|form';
  $field_group->group_name = 'group_product_extended_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product';
  $field_group->data = array(
    'label' => 'Extended Data',
    'weight' => '66',
    'children' => array(
      0 => 'field_consumer_product_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product-extended-data field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_product_extended_data|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product|node|product_details|form';
  $field_group->group_name = 'group_product';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Product',
    'weight' => '76',
    'children' => array(
      0 => 'group_product_core_business_data',
      1 => 'group_product_extended_data',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_product|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specs_unit_specs|node|product_details|form';
  $field_group->group_name = 'group_specs_unit_specs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_specs';
  $field_group->data = array(
    'label' => 'Unit Specs',
    'weight' => '72',
    'children' => array(
      0 => 'field_unit_length',
      1 => 'field_unit_width',
      2 => 'field_unit_height',
      3 => 'field_unit_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-specs-unit-specs field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_specs_unit_specs|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specs|node|product_details|form';
  $field_group->group_name = 'group_specs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_product_detail_tabs';
  $field_group->data = array(
    'label' => 'Specs',
    'weight' => '82',
    'children' => array(
      0 => 'group_specs_case_specs',
      1 => 'group_specs_other',
      2 => 'group_specs_unit_specs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-specs field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_specs|node|product_details|form'] = $field_group;

  return $export;
}
