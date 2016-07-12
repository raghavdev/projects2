<?php
/**
 * @file
 * bmb_product_details.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bmb_product_details_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|product_details|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '8',
    'children' => array(
      0 => 'field_bmb_category',
      1 => 'field_bmb_product_type',
      2 => 'field_spins_category',
      3 => 'field_spins_product_type',
      4 => 'field_web_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categories|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimensions_weights|node|product_details|form';
  $field_group->group_name = 'group_dimensions_weights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions & Weights',
    'weight' => '2',
    'children' => array(
      0 => 'field_case_net_weight_uom',
      1 => 'field_case_weight_uom',
      2 => 'field_high',
      3 => 'field_item_size_uom',
      4 => 'field_item_weight_uom',
      5 => 'field_random_weight',
      6 => 'field_tie',
      7 => 'field_case_cube',
      8 => 'field_case_height',
      9 => 'field_case_length',
      10 => 'field_case_net_weight',
      11 => 'field_case_weight',
      12 => 'field_case_width',
      13 => 'field_cube_height',
      14 => 'field_cube_length',
      15 => 'field_cube_width',
      16 => 'field_item_size',
      17 => 'field_item_weight',
      18 => 'field_pack_height',
      19 => 'field_pack_length',
      20 => 'field_pack_width',
      21 => 'field_pallet_height',
      22 => 'field_pallet_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dimensions & Weights',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_dimensions_weights|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exports|node|product_details|form';
  $field_group->group_name = 'group_exports';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Exports',
    'weight' => '12',
    'children' => array(
      0 => 'field_itrade_export',
      1 => 'field_ix_one_export',
      2 => 'field_target_export',
      3 => 'field_unfi_east',
      4 => 'field_unfi_west',
      5 => 'field_web_export',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Exports',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_exports|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_item_master_basics|node|product_details|form';
  $field_group->group_name = 'group_item_master_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item Master Basics',
    'weight' => '1',
    'children' => array(
      0 => 'field_activity_state',
      1 => 'field_item_description',
      2 => 'field_item_description_2',
      3 => 'field_material_cost_type',
      4 => 'field_stocking_uom',
      5 => 'field_category',
      6 => 'field_activity_date',
      7 => 'field_case_pack',
      8 => 'field_inner_case_pack',
      9 => 'field_manufacturing_method',
      10 => 'field_master_case_pack',
      11 => 'field_upc_code_macola',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_item_master_basics|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_freight|node|product_details|form';
  $field_group->group_name = 'group_location_freight';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location and Freight',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrobed_in_chocolate_',
      1 => 'field_freight_protection_from',
      2 => 'field_freight_protection_level',
      3 => 'field_po_req_fg',
      4 => 'field_primary_location',
      5 => 'field_east_fob_location',
      6 => 'field_grocery_type',
      7 => 'field_west_fob_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_location_freight|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_macola_only_values|node|product_details|form';
  $field_group->group_name = 'group_macola_only_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Macola Only Values',
    'weight' => '13',
    'children' => array(
      0 => 'field_backorderable',
      1 => 'field_contract_number',
      2 => 'field_controlled',
      3 => 'field_cost_end_date',
      4 => 'field_inv_transaction_audit',
      5 => 'field_manufacturing_uom',
      6 => 'field_price_basis_code',
      7 => 'field_price_uom',
      8 => 'field_purchasing_uom',
      9 => 'field_stocked',
      10 => 'field_pur_or_mfg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Macola Only Values',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_macola_only_values|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nutritional_data|node|product_details|form';
  $field_group->group_name = 'group_nutritional_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Nutritional Data',
    'weight' => '11',
    'children' => array(
      0 => 'field_serving_size_uom',
      1 => 'field_added_sugars_value',
      2 => 'field_biotin_value',
      3 => 'field_calcium_value',
      4 => 'field_calories_from_fat_value',
      5 => 'field_calories_value',
      6 => 'field_chloride_value',
      7 => 'field_cholesterol_value',
      8 => 'field_chromium_value',
      9 => 'field_copper_value',
      10 => 'field_dietary_fiber_value',
      11 => 'field_folate_value',
      12 => 'field_insoluble_fiber_value',
      13 => 'field_iodine_value',
      14 => 'field_iron_value',
      15 => 'field_juice_percent',
      16 => 'field_magnesium_value',
      17 => 'field_manganese_value',
      18 => 'field_molybdenum_value',
      19 => 'field_monounsat_fat_value',
      20 => 'field_net_carbohydrate_value',
      21 => 'field_niacin_value',
      22 => 'field_pantothenic_acid_value',
      23 => 'field_phosphorous_value',
      24 => 'field_polyunsat_fat_value',
      25 => 'field_potassium_value',
      26 => 'field_protein_value',
      27 => 'field_riboflavin_value',
      28 => 'field_saturated_fat_value',
      29 => 'field_selenium_value',
      30 => 'field_serving_size_value',
      31 => 'field_servings_per_cont_value',
      32 => 'field_sodium_value',
      33 => 'field_soluble_fiber_value',
      34 => 'field_sugar_value',
      35 => 'field_thiamin_value',
      36 => 'field_total_carbohydrate_value',
      37 => 'field_total_fat_value',
      38 => 'field_trans_fat_value',
      39 => 'field_vitamin_a_value',
      40 => 'field_vitamin_b12_value',
      41 => 'field_vitamin_b6_value',
      42 => 'field_vitamin_c_value',
      43 => 'field_vitamin_d_value',
      44 => 'field_vitamin_e_value',
      45 => 'field_vitamin_k_value',
      46 => 'field_zinc_value',
      47 => 'field_serving_size_string',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Nutritional Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_nutritional_data|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_basics|node|product_details|form';
  $field_group->group_name = 'group_product_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Basics',
    'weight' => '7',
    'children' => array(
      0 => 'field_active_date',
      1 => 'field_additional_images',
      2 => 'field_primary_image',
      3 => 'field_product_intro_date',
      4 => 'field_short_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_product_basics|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_certifications|node|product_details|form';
  $field_group->group_name = 'group_product_certifications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Certifications',
    'weight' => '10',
    'children' => array(
      0 => 'field_alaska_seafood_cert',
      1 => 'field_certified_humane',
      2 => 'field_certified_vegan',
      3 => 'field_fair_trade_certificate',
      4 => 'field_gluten_free',
      5 => 'field_gluten_free_certificate',
      6 => 'field_kosher_certificate',
      7 => 'field_marine_stewardship_agency',
      8 => 'field_marine_stewardship_cert',
      9 => 'field_non_gmo',
      10 => 'field_organic_certificate',
      11 => 'field_organic_certifier',
      12 => 'field_whole_grain_council',
      13 => 'field_kosher_certifying_agency',
      14 => 'field_third_party_certificates',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Product Certifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_product_certifications|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_identifiers|node|product_details|form';
  $field_group->group_name = 'group_product_identifiers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Identifiers',
    'weight' => '0',
    'children' => array(
      0 => 'field_brand',
      1 => 'field_case_gtin',
      2 => 'field_case_upc',
      3 => 'field_gtin',
      4 => 'field_inner_pack_gtin',
      5 => 'field_inner_pack_upc',
      6 => 'field_unfi_east_id',
      7 => 'field_unfi_west_id',
      8 => 'field_upc',
      9 => 'field_item_num',
      10 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_product_identifiers|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_info_attributes|node|product_details|form';
  $field_group->group_name = 'group_product_info_attributes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Info and Attributes',
    'weight' => '9',
    'children' => array(
      0 => 'field_country_of_origin',
      1 => 'field_dietary_preference',
      2 => 'field_ethnic_attributes',
      3 => 'field_free_of_attributes',
      4 => 'field_ingredients',
      5 => 'field_ingredients_print',
      6 => 'field_kosher_daily',
      7 => 'field_kosher_mbuf',
      8 => 'field_kosher_pareve',
      9 => 'field_kosher_passover',
      10 => 'field_major_allergen_attributes',
      11 => 'field_organic_attributes',
      12 => 'field_processing_attributes',
      13 => 'field_salt_content_attributes',
      14 => 'field_state_of_origin',
      15 => 'field_sweetener_attributes',
      16 => 'field_veg_attributes',
      17 => 'field_omega3_value',
      18 => 'field_whole_grain_per_serving',
      19 => 'field_allergens_in_facility',
      20 => 'field_additional_origin',
      21 => 'field_gluten_attributes',
      22 => 'field_secondary_allergen_attr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Product Info and Attributes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_product_info_attributes|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shelf_life_info|node|product_details|form';
  $field_group->group_name = 'group_shelf_life_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shelf Life Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_closed_code_life_dating',
      1 => 'field_open_code_life_dating',
      2 => 'field_shelf_life_days',
      3 => 'field_type_of_code_life_dating',
      4 => 'field_warranty_days',
      5 => 'field_guaranteed_shelf_life',
      6 => 'field_serial_lot',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_shelf_life_info|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supplier_select_fields|node|product_details|form';
  $field_group->group_name = 'group_supplier_select_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplier Portal Select Fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_baltimore_beverage_tax',
      1 => 'field_berkeley_beverage_tax',
      2 => 'field_beverage_container',
      3 => 'field_chicago_water_tax',
      4 => 'field_container_type',
      5 => 'field_product_labels',
      6 => 'field_taxable',
      7 => 'field_paperb_recycle_percent',
      8 => 'field_bottle_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_supplier_select_fields|node|product_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vendor_info|node|product_details|form';
  $field_group->group_name = 'group_vendor_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_details';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vendor Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_buyer',
      1 => 'field_lead_time_customer',
      2 => 'field_lead_time_printing',
      3 => 'field_lead_time_shipping',
      4 => 'field_minimum_order_qty',
      5 => 'field_approved_source',
      6 => 'field_vendor_pricing',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_vendor_info|node|product_details|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Categories');
  t('Dimensions & Weights');
  t('Exports');
  t('Item Master Basics');
  t('Location and Freight');
  t('Macola Only Values');
  t('Nutritional Data');
  t('Product Basics');
  t('Product Certifications');
  t('Product Identifiers');
  t('Product Info and Attributes');
  t('Shelf Life Information');
  t('Supplier Portal Select Fields');
  t('Vendor Info');

  return $field_groups;
}
