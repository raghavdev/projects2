<?php
/**
 * @file
 * bmb_single_product_data.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bmb_single_product_data_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bmb_single_product_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Single Product Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Single Product Data Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'products';
  $handler->display->display_options['style_options']['top_child_object'] = 'product';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Item Number */
  $handler->display->display_options['fields']['field_item_num']['id'] = 'field_item_num';
  $handler->display->display_options['fields']['field_item_num']['table'] = 'field_data_field_item_num';
  $handler->display->display_options['fields']['field_item_num']['field'] = 'field_item_num';
  $handler->display->display_options['fields']['field_item_num']['label'] = 'item_num';
  $handler->display->display_options['fields']['field_item_num']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'node_id';
  /* Field: Content: UPC (Product/Unit) */
  $handler->display->display_options['fields']['field_upc']['id'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['table'] = 'field_data_field_upc';
  $handler->display->display_options['fields']['field_upc']['field'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['label'] = 'upc';
  $handler->display->display_options['fields']['field_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: GTIN */
  $handler->display->display_options['fields']['field_gtin']['id'] = 'field_gtin';
  $handler->display->display_options['fields']['field_gtin']['table'] = 'field_data_field_gtin';
  $handler->display->display_options['fields']['field_gtin']['field'] = 'field_gtin';
  $handler->display->display_options['fields']['field_gtin']['label'] = 'gtin';
  $handler->display->display_options['fields']['field_gtin']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: GTIN Type */
  $handler->display->display_options['fields']['field_gtin_type']['id'] = 'field_gtin_type';
  $handler->display->display_options['fields']['field_gtin_type']['table'] = 'field_data_field_gtin_type';
  $handler->display->display_options['fields']['field_gtin_type']['field'] = 'field_gtin_type';
  $handler->display->display_options['fields']['field_gtin_type']['label'] = 'gtin_type';
  $handler->display->display_options['fields']['field_gtin_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: UBS ID */
  $handler->display->display_options['fields']['field_unfi_east_id']['id'] = 'field_unfi_east_id';
  $handler->display->display_options['fields']['field_unfi_east_id']['table'] = 'field_data_field_unfi_east_id';
  $handler->display->display_options['fields']['field_unfi_east_id']['field'] = 'field_unfi_east_id';
  $handler->display->display_options['fields']['field_unfi_east_id']['label'] = 'unfi_east_id';
  $handler->display->display_options['fields']['field_unfi_east_id']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: WBS ID */
  $handler->display->display_options['fields']['field_unfi_west_id']['id'] = 'field_unfi_west_id';
  $handler->display->display_options['fields']['field_unfi_west_id']['table'] = 'field_data_field_unfi_west_id';
  $handler->display->display_options['fields']['field_unfi_west_id']['field'] = 'field_unfi_west_id';
  $handler->display->display_options['fields']['field_unfi_west_id']['label'] = 'unfi_west_id';
  $handler->display->display_options['fields']['field_unfi_west_id']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Macola ID */
  $handler->display->display_options['fields']['field_macola_id']['id'] = 'field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['table'] = 'field_data_field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['field'] = 'field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['label'] = 'macola_id';
  $handler->display->display_options['fields']['field_macola_id']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Activity Code */
  $handler->display->display_options['fields']['field_activity_state']['id'] = 'field_activity_state';
  $handler->display->display_options['fields']['field_activity_state']['table'] = 'field_data_field_activity_state';
  $handler->display->display_options['fields']['field_activity_state']['field'] = 'field_activity_state';
  $handler->display->display_options['fields']['field_activity_state']['label'] = 'activity_state';
  $handler->display->display_options['fields']['field_activity_state']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Product Intro Date */
  $handler->display->display_options['fields']['field_product_intro_date']['id'] = 'field_product_intro_date';
  $handler->display->display_options['fields']['field_product_intro_date']['table'] = 'field_data_field_product_intro_date';
  $handler->display->display_options['fields']['field_product_intro_date']['field'] = 'field_product_intro_date';
  $handler->display->display_options['fields']['field_product_intro_date']['label'] = 'product_intro_date';
  $handler->display->display_options['fields']['field_product_intro_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: First Sale Date */
  $handler->display->display_options['fields']['field_active_date']['id'] = 'field_active_date';
  $handler->display->display_options['fields']['field_active_date']['table'] = 'field_data_field_active_date';
  $handler->display->display_options['fields']['field_active_date']['field'] = 'field_active_date';
  $handler->display->display_options['fields']['field_active_date']['label'] = 'active_date';
  $handler->display->display_options['fields']['field_active_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['table'] = 'field_data_field_brand';
  $handler->display->display_options['fields']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['label'] = 'brand';
  $handler->display->display_options['fields']['field_brand']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Product Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = 'short_description';
  $handler->display->display_options['fields']['field_short_description']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['label'] = 'primary_image';
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Additional Images */
  $handler->display->display_options['fields']['field_additional_images']['id'] = 'field_additional_images';
  $handler->display->display_options['fields']['field_additional_images']['table'] = 'field_data_field_additional_images';
  $handler->display->display_options['fields']['field_additional_images']['field'] = 'field_additional_images';
  $handler->display->display_options['fields']['field_additional_images']['label'] = 'additional_images';
  $handler->display->display_options['fields']['field_additional_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_additional_images']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_additional_images']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_additional_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_additional_images']['separator'] = '],[';
  /* Field: Content: Item Description */
  $handler->display->display_options['fields']['field_item_description']['id'] = 'field_item_description';
  $handler->display->display_options['fields']['field_item_description']['table'] = 'field_data_field_item_description';
  $handler->display->display_options['fields']['field_item_description']['field'] = 'field_item_description';
  $handler->display->display_options['fields']['field_item_description']['label'] = 'item_description';
  $handler->display->display_options['fields']['field_item_description']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Item Description 2 */
  $handler->display->display_options['fields']['field_item_description_2']['id'] = 'field_item_description_2';
  $handler->display->display_options['fields']['field_item_description_2']['table'] = 'field_data_field_item_description_2';
  $handler->display->display_options['fields']['field_item_description_2']['field'] = 'field_item_description_2';
  $handler->display->display_options['fields']['field_item_description_2']['label'] = 'item_description_2';
  $handler->display->display_options['fields']['field_item_description_2']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Secondary Web Category */
  $handler->display->display_options['fields']['field_web_category']['id'] = 'field_web_category';
  $handler->display->display_options['fields']['field_web_category']['table'] = 'field_data_field_web_category';
  $handler->display->display_options['fields']['field_web_category']['field'] = 'field_web_category';
  $handler->display->display_options['fields']['field_web_category']['label'] = 'web_category';
  $handler->display->display_options['fields']['field_web_category']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Web Export */
  $handler->display->display_options['fields']['field_web_export']['id'] = 'field_web_export';
  $handler->display->display_options['fields']['field_web_export']['table'] = 'field_data_field_web_export';
  $handler->display->display_options['fields']['field_web_export']['field'] = 'field_web_export';
  $handler->display->display_options['fields']['field_web_export']['label'] = 'web_export';
  $handler->display->display_options['fields']['field_web_export']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: BMB Category */
  $handler->display->display_options['fields']['field_bmb_category']['id'] = 'field_bmb_category';
  $handler->display->display_options['fields']['field_bmb_category']['table'] = 'field_data_field_bmb_category';
  $handler->display->display_options['fields']['field_bmb_category']['field'] = 'field_bmb_category';
  $handler->display->display_options['fields']['field_bmb_category']['label'] = 'bmb_category';
  $handler->display->display_options['fields']['field_bmb_category']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: BMB Product Type */
  $handler->display->display_options['fields']['field_bmb_product_type']['id'] = 'field_bmb_product_type';
  $handler->display->display_options['fields']['field_bmb_product_type']['table'] = 'field_data_field_bmb_product_type';
  $handler->display->display_options['fields']['field_bmb_product_type']['field'] = 'field_bmb_product_type';
  $handler->display->display_options['fields']['field_bmb_product_type']['label'] = 'bmb_product_type';
  $handler->display->display_options['fields']['field_bmb_product_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: SPINS Category */
  $handler->display->display_options['fields']['field_spins_category']['id'] = 'field_spins_category';
  $handler->display->display_options['fields']['field_spins_category']['table'] = 'field_data_field_spins_category';
  $handler->display->display_options['fields']['field_spins_category']['field'] = 'field_spins_category';
  $handler->display->display_options['fields']['field_spins_category']['label'] = 'spins_category';
  $handler->display->display_options['fields']['field_spins_category']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: SPINS Product Type */
  $handler->display->display_options['fields']['field_spins_product_type']['id'] = 'field_spins_product_type';
  $handler->display->display_options['fields']['field_spins_product_type']['table'] = 'field_data_field_spins_product_type';
  $handler->display->display_options['fields']['field_spins_product_type']['field'] = 'field_spins_product_type';
  $handler->display->display_options['fields']['field_spins_product_type']['label'] = 'spins_product_type';
  $handler->display->display_options['fields']['field_spins_product_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Size */
  $handler->display->display_options['fields']['field_item_size']['id'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['table'] = 'field_data_field_item_size';
  $handler->display->display_options['fields']['field_item_size']['field'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['label'] = 'item_size';
  $handler->display->display_options['fields']['field_item_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Size UOM */
  $handler->display->display_options['fields']['field_item_size_uom']['id'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['table'] = 'field_data_field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['field'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['label'] = 'item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Weight Drained */
  $handler->display->display_options['fields']['field_item_weight']['id'] = 'field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['table'] = 'field_data_field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['field'] = 'field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['label'] = 'item_weight';
  $handler->display->display_options['fields']['field_item_weight']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Weight Drained UOM */
  $handler->display->display_options['fields']['field_item_weight_uom']['id'] = 'field_item_weight_uom';
  $handler->display->display_options['fields']['field_item_weight_uom']['table'] = 'field_data_field_item_weight_uom';
  $handler->display->display_options['fields']['field_item_weight_uom']['field'] = 'field_item_weight_uom';
  $handler->display->display_options['fields']['field_item_weight_uom']['label'] = 'item_weight_uom';
  $handler->display->display_options['fields']['field_item_weight_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Ingredients List (Full) */
  $handler->display->display_options['fields']['field_ingredients']['id'] = 'field_ingredients';
  $handler->display->display_options['fields']['field_ingredients']['table'] = 'field_data_field_ingredients';
  $handler->display->display_options['fields']['field_ingredients']['field'] = 'field_ingredients';
  $handler->display->display_options['fields']['field_ingredients']['label'] = 'ingredients';
  $handler->display->display_options['fields']['field_ingredients']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Ingredients List (Printed & Displayed) */
  $handler->display->display_options['fields']['field_ingredients_print']['id'] = 'field_ingredients_print';
  $handler->display->display_options['fields']['field_ingredients_print']['table'] = 'field_data_field_ingredients_print';
  $handler->display->display_options['fields']['field_ingredients_print']['field'] = 'field_ingredients_print';
  $handler->display->display_options['fields']['field_ingredients_print']['label'] = 'ingredients_print';
  $handler->display->display_options['fields']['field_ingredients_print']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Major Allergens */
  $handler->display->display_options['fields']['field_major_allergen_attributes']['id'] = 'field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['table'] = 'field_data_field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['field'] = 'field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['label'] = 'major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_major_allergen_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['separator'] = '],[';
  /* Field: Content: Additional Allergens */
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['id'] = 'field_secondary_allergen_attr';
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['table'] = 'field_data_field_secondary_allergen_attr';
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['field'] = 'field_secondary_allergen_attr';
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['label'] = 'secondary_allergen_attr';
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_secondary_allergen_attr']['separator'] = '],[';
  /* Field: Content: Gluten Attributes */
  $handler->display->display_options['fields']['field_gluten_attributes']['id'] = 'field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['table'] = 'field_data_field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['field'] = 'field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['label'] = 'gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_gluten_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gluten_attributes']['separator'] = '],[';
  /* Field: Content: Free of Substances */
  $handler->display->display_options['fields']['field_free_of_attributes']['id'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['table'] = 'field_data_field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['field'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['label'] = 'free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_free_of_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_free_of_attributes']['separator'] = '],[';
  /* Field: Content: Allergens in Facility */
  $handler->display->display_options['fields']['field_processing_attributes']['id'] = 'field_processing_attributes';
  $handler->display->display_options['fields']['field_processing_attributes']['table'] = 'field_data_field_processing_attributes';
  $handler->display->display_options['fields']['field_processing_attributes']['field'] = 'field_processing_attributes';
  $handler->display->display_options['fields']['field_processing_attributes']['label'] = 'processing_attributes';
  $handler->display->display_options['fields']['field_processing_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_processing_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_processing_attributes']['separator'] = '],[';
  /* Field: Content: Vegan or Vegetarian */
  $handler->display->display_options['fields']['field_veg_attributes']['id'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['table'] = 'field_data_field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['field'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['label'] = 'veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_veg_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_veg_attributes']['separator'] = '],[';
  /* Field: Content: Organic % */
  $handler->display->display_options['fields']['field_organic_attributes']['id'] = 'field_organic_attributes';
  $handler->display->display_options['fields']['field_organic_attributes']['table'] = 'field_data_field_organic_attributes';
  $handler->display->display_options['fields']['field_organic_attributes']['field'] = 'field_organic_attributes';
  $handler->display->display_options['fields']['field_organic_attributes']['label'] = 'organic_attributes';
  $handler->display->display_options['fields']['field_organic_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_organic_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organic_attributes']['separator'] = '],[';
  /* Field: Content: Omega-3 Content */
  $handler->display->display_options['fields']['field_omega3_value']['id'] = 'field_omega3_value';
  $handler->display->display_options['fields']['field_omega3_value']['table'] = 'field_data_field_omega3_value';
  $handler->display->display_options['fields']['field_omega3_value']['field'] = 'field_omega3_value';
  $handler->display->display_options['fields']['field_omega3_value']['label'] = 'omega3_value';
  $handler->display->display_options['fields']['field_omega3_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Whole Grains per Serving */
  $handler->display->display_options['fields']['field_whole_grain_per_serving']['id'] = 'field_whole_grain_per_serving';
  $handler->display->display_options['fields']['field_whole_grain_per_serving']['table'] = 'field_data_field_whole_grain_per_serving';
  $handler->display->display_options['fields']['field_whole_grain_per_serving']['field'] = 'field_whole_grain_per_serving';
  $handler->display->display_options['fields']['field_whole_grain_per_serving']['label'] = 'whole_grain_per_serving';
  $handler->display->display_options['fields']['field_whole_grain_per_serving']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Ethnic */
  $handler->display->display_options['fields']['field_ethnic_attributes']['id'] = 'field_ethnic_attributes';
  $handler->display->display_options['fields']['field_ethnic_attributes']['table'] = 'field_data_field_ethnic_attributes';
  $handler->display->display_options['fields']['field_ethnic_attributes']['field'] = 'field_ethnic_attributes';
  $handler->display->display_options['fields']['field_ethnic_attributes']['label'] = 'ethnic_attributes';
  $handler->display->display_options['fields']['field_ethnic_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_ethnic_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ethnic_attributes']['separator'] = '],[';
  /* Field: Content: Sweetener */
  $handler->display->display_options['fields']['field_sweetener_attributes']['id'] = 'field_sweetener_attributes';
  $handler->display->display_options['fields']['field_sweetener_attributes']['table'] = 'field_data_field_sweetener_attributes';
  $handler->display->display_options['fields']['field_sweetener_attributes']['field'] = 'field_sweetener_attributes';
  $handler->display->display_options['fields']['field_sweetener_attributes']['label'] = 'sweetener_attributes';
  $handler->display->display_options['fields']['field_sweetener_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_sweetener_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sweetener_attributes']['separator'] = '],[';
  /* Field: Content: Dietary Preference */
  $handler->display->display_options['fields']['field_dietary_preference']['id'] = 'field_dietary_preference';
  $handler->display->display_options['fields']['field_dietary_preference']['table'] = 'field_data_field_dietary_preference';
  $handler->display->display_options['fields']['field_dietary_preference']['field'] = 'field_dietary_preference';
  $handler->display->display_options['fields']['field_dietary_preference']['label'] = 'dietary_preference';
  $handler->display->display_options['fields']['field_dietary_preference']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_dietary_preference']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_dietary_preference']['separator'] = '],[';
  /* Field: Content: Salt Content */
  $handler->display->display_options['fields']['field_salt_content_attributes']['id'] = 'field_salt_content_attributes';
  $handler->display->display_options['fields']['field_salt_content_attributes']['table'] = 'field_data_field_salt_content_attributes';
  $handler->display->display_options['fields']['field_salt_content_attributes']['field'] = 'field_salt_content_attributes';
  $handler->display->display_options['fields']['field_salt_content_attributes']['label'] = 'salt_content_attributes';
  $handler->display->display_options['fields']['field_salt_content_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_salt_content_attributes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_salt_content_attributes']['separator'] = '],[';
  /* Field: Content: Country of Origin */
  $handler->display->display_options['fields']['field_country_of_origin']['id'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['table'] = 'field_data_field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['field'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['label'] = 'country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: State of Origin */
  $handler->display->display_options['fields']['field_state_of_origin']['id'] = 'field_state_of_origin';
  $handler->display->display_options['fields']['field_state_of_origin']['table'] = 'field_data_field_state_of_origin';
  $handler->display->display_options['fields']['field_state_of_origin']['field'] = 'field_state_of_origin';
  $handler->display->display_options['fields']['field_state_of_origin']['label'] = 'state_of_origin';
  $handler->display->display_options['fields']['field_state_of_origin']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Additional Origin Locations */
  $handler->display->display_options['fields']['field_additional_origin']['id'] = 'field_additional_origin';
  $handler->display->display_options['fields']['field_additional_origin']['table'] = 'field_data_field_additional_origin';
  $handler->display->display_options['fields']['field_additional_origin']['field'] = 'field_additional_origin';
  $handler->display->display_options['fields']['field_additional_origin']['label'] = 'additional_origin';
  $handler->display->display_options['fields']['field_additional_origin']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Daily */
  $handler->display->display_options['fields']['field_kosher_daily']['id'] = 'field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['table'] = 'field_data_field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['field'] = 'field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['label'] = 'kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - MBUF */
  $handler->display->display_options['fields']['field_kosher_mbuf']['id'] = 'field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['table'] = 'field_data_field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['field'] = 'field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['label'] = 'kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Passover Only */
  $handler->display->display_options['fields']['field_kosher_passover']['id'] = 'field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['table'] = 'field_data_field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['field'] = 'field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['label'] = 'kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Pareve */
  $handler->display->display_options['fields']['field_kosher_pareve']['id'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['table'] = 'field_data_field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['field'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['label'] = 'kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Non-GMO Project */
  $handler->display->display_options['fields']['field_non_gmo']['id'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['table'] = 'field_data_field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['field'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['label'] = 'non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vegan Certificate */
  $handler->display->display_options['fields']['field_certified_vegan']['id'] = 'field_certified_vegan';
  $handler->display->display_options['fields']['field_certified_vegan']['table'] = 'field_data_field_certified_vegan';
  $handler->display->display_options['fields']['field_certified_vegan']['field'] = 'field_certified_vegan';
  $handler->display->display_options['fields']['field_certified_vegan']['label'] = 'certified_vegan';
  $handler->display->display_options['fields']['field_certified_vegan']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_certified_vegan']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Gluten Free Certificate */
  $handler->display->display_options['fields']['field_gluten_free_certificate']['id'] = 'field_gluten_free_certificate';
  $handler->display->display_options['fields']['field_gluten_free_certificate']['table'] = 'field_data_field_gluten_free_certificate';
  $handler->display->display_options['fields']['field_gluten_free_certificate']['field'] = 'field_gluten_free_certificate';
  $handler->display->display_options['fields']['field_gluten_free_certificate']['label'] = 'gluten_free_certificate';
  $handler->display->display_options['fields']['field_gluten_free_certificate']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gluten_free_certificate']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Gluten Free Certification Agency */
  $handler->display->display_options['fields']['field_gluten_free']['id'] = 'field_gluten_free';
  $handler->display->display_options['fields']['field_gluten_free']['table'] = 'field_data_field_gluten_free';
  $handler->display->display_options['fields']['field_gluten_free']['field'] = 'field_gluten_free';
  $handler->display->display_options['fields']['field_gluten_free']['label'] = 'gluten_free';
  $handler->display->display_options['fields']['field_gluten_free']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Whole Grain Stamp */
  $handler->display->display_options['fields']['field_whole_grain_council']['id'] = 'field_whole_grain_council';
  $handler->display->display_options['fields']['field_whole_grain_council']['table'] = 'field_data_field_whole_grain_council';
  $handler->display->display_options['fields']['field_whole_grain_council']['field'] = 'field_whole_grain_council';
  $handler->display->display_options['fields']['field_whole_grain_council']['label'] = 'whole_grain_council';
  $handler->display->display_options['fields']['field_whole_grain_council']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Humane Certificate */
  $handler->display->display_options['fields']['field_certified_humane']['id'] = 'field_certified_humane';
  $handler->display->display_options['fields']['field_certified_humane']['table'] = 'field_data_field_certified_humane';
  $handler->display->display_options['fields']['field_certified_humane']['field'] = 'field_certified_humane';
  $handler->display->display_options['fields']['field_certified_humane']['label'] = 'certified_humane';
  $handler->display->display_options['fields']['field_certified_humane']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_certified_humane']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Fair Trade Certificate */
  $handler->display->display_options['fields']['field_fair_trade_certificate']['id'] = 'field_fair_trade_certificate';
  $handler->display->display_options['fields']['field_fair_trade_certificate']['table'] = 'field_data_field_fair_trade_certificate';
  $handler->display->display_options['fields']['field_fair_trade_certificate']['field'] = 'field_fair_trade_certificate';
  $handler->display->display_options['fields']['field_fair_trade_certificate']['label'] = 'fair_trade_certificate';
  $handler->display->display_options['fields']['field_fair_trade_certificate']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fair_trade_certificate']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Alaska Seafood Certificate */
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['id'] = 'field_alaska_seafood_cert';
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['table'] = 'field_data_field_alaska_seafood_cert';
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['field'] = 'field_alaska_seafood_cert';
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['label'] = 'alaska_seafood_cert';
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_alaska_seafood_cert']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Marine Stewardship Certificate */
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['id'] = 'field_marine_stewardship_cert';
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['table'] = 'field_data_field_marine_stewardship_cert';
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['field'] = 'field_marine_stewardship_cert';
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['label'] = 'marine_stewardship_cert';
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_marine_stewardship_cert']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Marine Stewardship Certifying Agency */
  $handler->display->display_options['fields']['field_marine_stewardship_agency']['id'] = 'field_marine_stewardship_agency';
  $handler->display->display_options['fields']['field_marine_stewardship_agency']['table'] = 'field_data_field_marine_stewardship_agency';
  $handler->display->display_options['fields']['field_marine_stewardship_agency']['field'] = 'field_marine_stewardship_agency';
  $handler->display->display_options['fields']['field_marine_stewardship_agency']['label'] = 'marine_stewardship_agency';
  $handler->display->display_options['fields']['field_marine_stewardship_agency']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Organic Certificate */
  $handler->display->display_options['fields']['field_organic_certificate']['id'] = 'field_organic_certificate';
  $handler->display->display_options['fields']['field_organic_certificate']['table'] = 'field_data_field_organic_certificate';
  $handler->display->display_options['fields']['field_organic_certificate']['field'] = 'field_organic_certificate';
  $handler->display->display_options['fields']['field_organic_certificate']['label'] = 'organic_certificate';
  $handler->display->display_options['fields']['field_organic_certificate']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_organic_certificate']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_organic_certificate']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Organic Certifying Agency */
  $handler->display->display_options['fields']['field_organic_certifier']['id'] = 'field_organic_certifier';
  $handler->display->display_options['fields']['field_organic_certifier']['table'] = 'field_data_field_organic_certifier';
  $handler->display->display_options['fields']['field_organic_certifier']['field'] = 'field_organic_certifier';
  $handler->display->display_options['fields']['field_organic_certifier']['label'] = 'organic_certifier';
  $handler->display->display_options['fields']['field_organic_certifier']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher Certificate */
  $handler->display->display_options['fields']['field_kosher_certificate']['id'] = 'field_kosher_certificate';
  $handler->display->display_options['fields']['field_kosher_certificate']['table'] = 'field_data_field_kosher_certificate';
  $handler->display->display_options['fields']['field_kosher_certificate']['field'] = 'field_kosher_certificate';
  $handler->display->display_options['fields']['field_kosher_certificate']['label'] = 'kosher_certificate';
  $handler->display->display_options['fields']['field_kosher_certificate']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_kosher_certificate']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_kosher_certificate']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher Certifying Agency */
  $handler->display->display_options['fields']['field_kosher_agency']['id'] = 'field_kosher_agency';
  $handler->display->display_options['fields']['field_kosher_agency']['table'] = 'field_data_field_kosher_agency';
  $handler->display->display_options['fields']['field_kosher_agency']['field'] = 'field_kosher_agency';
  $handler->display->display_options['fields']['field_kosher_agency']['label'] = 'kosher_agency';
  $handler->display->display_options['fields']['field_kosher_agency']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Serving Size */
  $handler->display->display_options['fields']['field_serving_size_value']['id'] = 'field_serving_size_value';
  $handler->display->display_options['fields']['field_serving_size_value']['table'] = 'field_data_field_serving_size_value';
  $handler->display->display_options['fields']['field_serving_size_value']['field'] = 'field_serving_size_value';
  $handler->display->display_options['fields']['field_serving_size_value']['label'] = 'serving_size_value';
  $handler->display->display_options['fields']['field_serving_size_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Serving Size UOM */
  $handler->display->display_options['fields']['field_serving_size_uom']['id'] = 'field_serving_size_uom';
  $handler->display->display_options['fields']['field_serving_size_uom']['table'] = 'field_data_field_serving_size_uom';
  $handler->display->display_options['fields']['field_serving_size_uom']['field'] = 'field_serving_size_uom';
  $handler->display->display_options['fields']['field_serving_size_uom']['label'] = 'serving_size_uom';
  $handler->display->display_options['fields']['field_serving_size_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Servings Per Container */
  $handler->display->display_options['fields']['field_servings_per_cont_value']['id'] = 'field_servings_per_cont_value';
  $handler->display->display_options['fields']['field_servings_per_cont_value']['table'] = 'field_data_field_servings_per_cont_value';
  $handler->display->display_options['fields']['field_servings_per_cont_value']['field'] = 'field_servings_per_cont_value';
  $handler->display->display_options['fields']['field_servings_per_cont_value']['label'] = 'servings_per_cont_value';
  $handler->display->display_options['fields']['field_servings_per_cont_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Calories */
  $handler->display->display_options['fields']['field_calories_value']['id'] = 'field_calories_value';
  $handler->display->display_options['fields']['field_calories_value']['table'] = 'field_data_field_calories_value';
  $handler->display->display_options['fields']['field_calories_value']['field'] = 'field_calories_value';
  $handler->display->display_options['fields']['field_calories_value']['label'] = 'calories_value';
  $handler->display->display_options['fields']['field_calories_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Calories From Fat */
  $handler->display->display_options['fields']['field_calories_from_fat_value']['id'] = 'field_calories_from_fat_value';
  $handler->display->display_options['fields']['field_calories_from_fat_value']['table'] = 'field_data_field_calories_from_fat_value';
  $handler->display->display_options['fields']['field_calories_from_fat_value']['field'] = 'field_calories_from_fat_value';
  $handler->display->display_options['fields']['field_calories_from_fat_value']['label'] = 'calories_from_fat_value';
  $handler->display->display_options['fields']['field_calories_from_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Total Fat */
  $handler->display->display_options['fields']['field_total_fat_value']['id'] = 'field_total_fat_value';
  $handler->display->display_options['fields']['field_total_fat_value']['table'] = 'field_data_field_total_fat_value';
  $handler->display->display_options['fields']['field_total_fat_value']['field'] = 'field_total_fat_value';
  $handler->display->display_options['fields']['field_total_fat_value']['label'] = 'total_fat_value';
  $handler->display->display_options['fields']['field_total_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Saturated Fat */
  $handler->display->display_options['fields']['field_saturated_fat_value']['id'] = 'field_saturated_fat_value';
  $handler->display->display_options['fields']['field_saturated_fat_value']['table'] = 'field_data_field_saturated_fat_value';
  $handler->display->display_options['fields']['field_saturated_fat_value']['field'] = 'field_saturated_fat_value';
  $handler->display->display_options['fields']['field_saturated_fat_value']['label'] = 'saturated_fat_value';
  $handler->display->display_options['fields']['field_saturated_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Trans Fat */
  $handler->display->display_options['fields']['field_trans_fat_value']['id'] = 'field_trans_fat_value';
  $handler->display->display_options['fields']['field_trans_fat_value']['table'] = 'field_data_field_trans_fat_value';
  $handler->display->display_options['fields']['field_trans_fat_value']['field'] = 'field_trans_fat_value';
  $handler->display->display_options['fields']['field_trans_fat_value']['label'] = 'trans_fat_value';
  $handler->display->display_options['fields']['field_trans_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Polyunsaturated Fat */
  $handler->display->display_options['fields']['field_polyunsat_fat_value']['id'] = 'field_polyunsat_fat_value';
  $handler->display->display_options['fields']['field_polyunsat_fat_value']['table'] = 'field_data_field_polyunsat_fat_value';
  $handler->display->display_options['fields']['field_polyunsat_fat_value']['field'] = 'field_polyunsat_fat_value';
  $handler->display->display_options['fields']['field_polyunsat_fat_value']['label'] = 'polyunsat_fat_value';
  $handler->display->display_options['fields']['field_polyunsat_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Monounsaturated Fat */
  $handler->display->display_options['fields']['field_monounsat_fat_value']['id'] = 'field_monounsat_fat_value';
  $handler->display->display_options['fields']['field_monounsat_fat_value']['table'] = 'field_data_field_monounsat_fat_value';
  $handler->display->display_options['fields']['field_monounsat_fat_value']['field'] = 'field_monounsat_fat_value';
  $handler->display->display_options['fields']['field_monounsat_fat_value']['label'] = 'monounsat_fat_value';
  $handler->display->display_options['fields']['field_monounsat_fat_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Cholesterol */
  $handler->display->display_options['fields']['field_cholesterol_value']['id'] = 'field_cholesterol_value';
  $handler->display->display_options['fields']['field_cholesterol_value']['table'] = 'field_data_field_cholesterol_value';
  $handler->display->display_options['fields']['field_cholesterol_value']['field'] = 'field_cholesterol_value';
  $handler->display->display_options['fields']['field_cholesterol_value']['label'] = 'cholesterol_value';
  $handler->display->display_options['fields']['field_cholesterol_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Sodium */
  $handler->display->display_options['fields']['field_sodium_value']['id'] = 'field_sodium_value';
  $handler->display->display_options['fields']['field_sodium_value']['table'] = 'field_data_field_sodium_value';
  $handler->display->display_options['fields']['field_sodium_value']['field'] = 'field_sodium_value';
  $handler->display->display_options['fields']['field_sodium_value']['label'] = 'sodium_value';
  $handler->display->display_options['fields']['field_sodium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Potassium */
  $handler->display->display_options['fields']['field_potassium_value']['id'] = 'field_potassium_value';
  $handler->display->display_options['fields']['field_potassium_value']['table'] = 'field_data_field_potassium_value';
  $handler->display->display_options['fields']['field_potassium_value']['field'] = 'field_potassium_value';
  $handler->display->display_options['fields']['field_potassium_value']['label'] = 'potassium_value';
  $handler->display->display_options['fields']['field_potassium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Total Carbohydrates */
  $handler->display->display_options['fields']['field_total_carbohydrate_value']['id'] = 'field_total_carbohydrate_value';
  $handler->display->display_options['fields']['field_total_carbohydrate_value']['table'] = 'field_data_field_total_carbohydrate_value';
  $handler->display->display_options['fields']['field_total_carbohydrate_value']['field'] = 'field_total_carbohydrate_value';
  $handler->display->display_options['fields']['field_total_carbohydrate_value']['label'] = 'total_carbohydrate_value';
  $handler->display->display_options['fields']['field_total_carbohydrate_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Dietary Fiber */
  $handler->display->display_options['fields']['field_dietary_fiber_value']['id'] = 'field_dietary_fiber_value';
  $handler->display->display_options['fields']['field_dietary_fiber_value']['table'] = 'field_data_field_dietary_fiber_value';
  $handler->display->display_options['fields']['field_dietary_fiber_value']['field'] = 'field_dietary_fiber_value';
  $handler->display->display_options['fields']['field_dietary_fiber_value']['label'] = 'dietary_fiber_value';
  $handler->display->display_options['fields']['field_dietary_fiber_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Soluble Fiber */
  $handler->display->display_options['fields']['field_soluble_fiber_value']['id'] = 'field_soluble_fiber_value';
  $handler->display->display_options['fields']['field_soluble_fiber_value']['table'] = 'field_data_field_soluble_fiber_value';
  $handler->display->display_options['fields']['field_soluble_fiber_value']['field'] = 'field_soluble_fiber_value';
  $handler->display->display_options['fields']['field_soluble_fiber_value']['label'] = 'soluble_fiber_value';
  $handler->display->display_options['fields']['field_soluble_fiber_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Insoluble Fiber */
  $handler->display->display_options['fields']['field_insoluble_fiber_value']['id'] = 'field_insoluble_fiber_value';
  $handler->display->display_options['fields']['field_insoluble_fiber_value']['table'] = 'field_data_field_insoluble_fiber_value';
  $handler->display->display_options['fields']['field_insoluble_fiber_value']['field'] = 'field_insoluble_fiber_value';
  $handler->display->display_options['fields']['field_insoluble_fiber_value']['label'] = 'insoluble_fiber_value';
  $handler->display->display_options['fields']['field_insoluble_fiber_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Carbohydrates */
  $handler->display->display_options['fields']['field_net_carbohydrate_value']['id'] = 'field_net_carbohydrate_value';
  $handler->display->display_options['fields']['field_net_carbohydrate_value']['table'] = 'field_data_field_net_carbohydrate_value';
  $handler->display->display_options['fields']['field_net_carbohydrate_value']['field'] = 'field_net_carbohydrate_value';
  $handler->display->display_options['fields']['field_net_carbohydrate_value']['label'] = 'net_carbohydrates_value';
  $handler->display->display_options['fields']['field_net_carbohydrate_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Sugars */
  $handler->display->display_options['fields']['field_sugar_value']['id'] = 'field_sugar_value';
  $handler->display->display_options['fields']['field_sugar_value']['table'] = 'field_data_field_sugar_value';
  $handler->display->display_options['fields']['field_sugar_value']['field'] = 'field_sugar_value';
  $handler->display->display_options['fields']['field_sugar_value']['label'] = 'sugar_value';
  $handler->display->display_options['fields']['field_sugar_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Added Sugars */
  $handler->display->display_options['fields']['field_added_sugars_value']['id'] = 'field_added_sugars_value';
  $handler->display->display_options['fields']['field_added_sugars_value']['table'] = 'field_data_field_added_sugars_value';
  $handler->display->display_options['fields']['field_added_sugars_value']['field'] = 'field_added_sugars_value';
  $handler->display->display_options['fields']['field_added_sugars_value']['label'] = 'added_sugars_value';
  $handler->display->display_options['fields']['field_added_sugars_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Protein */
  $handler->display->display_options['fields']['field_protein_value']['id'] = 'field_protein_value';
  $handler->display->display_options['fields']['field_protein_value']['table'] = 'field_data_field_protein_value';
  $handler->display->display_options['fields']['field_protein_value']['field'] = 'field_protein_value';
  $handler->display->display_options['fields']['field_protein_value']['label'] = 'protein_value';
  $handler->display->display_options['fields']['field_protein_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin A */
  $handler->display->display_options['fields']['field_vitamin_a_value']['id'] = 'field_vitamin_a_value';
  $handler->display->display_options['fields']['field_vitamin_a_value']['table'] = 'field_data_field_vitamin_a_value';
  $handler->display->display_options['fields']['field_vitamin_a_value']['field'] = 'field_vitamin_a_value';
  $handler->display->display_options['fields']['field_vitamin_a_value']['label'] = 'vitamin_a_value';
  $handler->display->display_options['fields']['field_vitamin_a_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin C */
  $handler->display->display_options['fields']['field_vitamin_c_value']['id'] = 'field_vitamin_c_value';
  $handler->display->display_options['fields']['field_vitamin_c_value']['table'] = 'field_data_field_vitamin_c_value';
  $handler->display->display_options['fields']['field_vitamin_c_value']['field'] = 'field_vitamin_c_value';
  $handler->display->display_options['fields']['field_vitamin_c_value']['label'] = 'vitamin_c_value';
  $handler->display->display_options['fields']['field_vitamin_c_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Calcium */
  $handler->display->display_options['fields']['field_calcium_value']['id'] = 'field_calcium_value';
  $handler->display->display_options['fields']['field_calcium_value']['table'] = 'field_data_field_calcium_value';
  $handler->display->display_options['fields']['field_calcium_value']['field'] = 'field_calcium_value';
  $handler->display->display_options['fields']['field_calcium_value']['label'] = 'calcium_value';
  $handler->display->display_options['fields']['field_calcium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Iron */
  $handler->display->display_options['fields']['field_iron_value']['id'] = 'field_iron_value';
  $handler->display->display_options['fields']['field_iron_value']['table'] = 'field_data_field_iron_value';
  $handler->display->display_options['fields']['field_iron_value']['field'] = 'field_iron_value';
  $handler->display->display_options['fields']['field_iron_value']['label'] = 'iron_value';
  $handler->display->display_options['fields']['field_iron_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin D */
  $handler->display->display_options['fields']['field_vitamin_d_value']['id'] = 'field_vitamin_d_value';
  $handler->display->display_options['fields']['field_vitamin_d_value']['table'] = 'field_data_field_vitamin_d_value';
  $handler->display->display_options['fields']['field_vitamin_d_value']['field'] = 'field_vitamin_d_value';
  $handler->display->display_options['fields']['field_vitamin_d_value']['label'] = 'vitamin_d_value';
  $handler->display->display_options['fields']['field_vitamin_d_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin E */
  $handler->display->display_options['fields']['field_vitamin_e_value']['id'] = 'field_vitamin_e_value';
  $handler->display->display_options['fields']['field_vitamin_e_value']['table'] = 'field_data_field_vitamin_e_value';
  $handler->display->display_options['fields']['field_vitamin_e_value']['field'] = 'field_vitamin_e_value';
  $handler->display->display_options['fields']['field_vitamin_e_value']['label'] = 'vitamin_e_value';
  $handler->display->display_options['fields']['field_vitamin_e_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin K */
  $handler->display->display_options['fields']['field_vitamin_k_value']['id'] = 'field_vitamin_k_value';
  $handler->display->display_options['fields']['field_vitamin_k_value']['table'] = 'field_data_field_vitamin_k_value';
  $handler->display->display_options['fields']['field_vitamin_k_value']['field'] = 'field_vitamin_k_value';
  $handler->display->display_options['fields']['field_vitamin_k_value']['label'] = 'vitamin_k_value';
  $handler->display->display_options['fields']['field_vitamin_k_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Thiamin */
  $handler->display->display_options['fields']['field_thiamin_value']['id'] = 'field_thiamin_value';
  $handler->display->display_options['fields']['field_thiamin_value']['table'] = 'field_data_field_thiamin_value';
  $handler->display->display_options['fields']['field_thiamin_value']['field'] = 'field_thiamin_value';
  $handler->display->display_options['fields']['field_thiamin_value']['label'] = 'thiamin_value';
  $handler->display->display_options['fields']['field_thiamin_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Riboflavin */
  $handler->display->display_options['fields']['field_riboflavin_value']['id'] = 'field_riboflavin_value';
  $handler->display->display_options['fields']['field_riboflavin_value']['table'] = 'field_data_field_riboflavin_value';
  $handler->display->display_options['fields']['field_riboflavin_value']['field'] = 'field_riboflavin_value';
  $handler->display->display_options['fields']['field_riboflavin_value']['label'] = 'riboflavin_value';
  $handler->display->display_options['fields']['field_riboflavin_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Niacin */
  $handler->display->display_options['fields']['field_niacin_value']['id'] = 'field_niacin_value';
  $handler->display->display_options['fields']['field_niacin_value']['table'] = 'field_data_field_niacin_value';
  $handler->display->display_options['fields']['field_niacin_value']['field'] = 'field_niacin_value';
  $handler->display->display_options['fields']['field_niacin_value']['label'] = 'niacin_value';
  $handler->display->display_options['fields']['field_niacin_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin B6 */
  $handler->display->display_options['fields']['field_vitamin_b6_value']['id'] = 'field_vitamin_b6_value';
  $handler->display->display_options['fields']['field_vitamin_b6_value']['table'] = 'field_data_field_vitamin_b6_value';
  $handler->display->display_options['fields']['field_vitamin_b6_value']['field'] = 'field_vitamin_b6_value';
  $handler->display->display_options['fields']['field_vitamin_b6_value']['label'] = 'vitamin_b6_value';
  $handler->display->display_options['fields']['field_vitamin_b6_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Folate */
  $handler->display->display_options['fields']['field_folate_value']['id'] = 'field_folate_value';
  $handler->display->display_options['fields']['field_folate_value']['table'] = 'field_data_field_folate_value';
  $handler->display->display_options['fields']['field_folate_value']['field'] = 'field_folate_value';
  $handler->display->display_options['fields']['field_folate_value']['label'] = 'folate_value';
  $handler->display->display_options['fields']['field_folate_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vitamin B12 */
  $handler->display->display_options['fields']['field_vitamin_b12_value']['id'] = 'field_vitamin_b12_value';
  $handler->display->display_options['fields']['field_vitamin_b12_value']['table'] = 'field_data_field_vitamin_b12_value';
  $handler->display->display_options['fields']['field_vitamin_b12_value']['field'] = 'field_vitamin_b12_value';
  $handler->display->display_options['fields']['field_vitamin_b12_value']['label'] = 'vitamin_b12_value';
  $handler->display->display_options['fields']['field_vitamin_b12_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Biotin */
  $handler->display->display_options['fields']['field_biotin_value']['id'] = 'field_biotin_value';
  $handler->display->display_options['fields']['field_biotin_value']['table'] = 'field_data_field_biotin_value';
  $handler->display->display_options['fields']['field_biotin_value']['field'] = 'field_biotin_value';
  $handler->display->display_options['fields']['field_biotin_value']['label'] = 'biotin_value';
  $handler->display->display_options['fields']['field_biotin_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Pantothenic Acid */
  $handler->display->display_options['fields']['field_pantothenic_acid_value']['id'] = 'field_pantothenic_acid_value';
  $handler->display->display_options['fields']['field_pantothenic_acid_value']['table'] = 'field_data_field_pantothenic_acid_value';
  $handler->display->display_options['fields']['field_pantothenic_acid_value']['field'] = 'field_pantothenic_acid_value';
  $handler->display->display_options['fields']['field_pantothenic_acid_value']['label'] = 'pantothenic_acid_value';
  $handler->display->display_options['fields']['field_pantothenic_acid_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Phosphorous */
  $handler->display->display_options['fields']['field_phosphorous_value']['id'] = 'field_phosphorous_value';
  $handler->display->display_options['fields']['field_phosphorous_value']['table'] = 'field_data_field_phosphorous_value';
  $handler->display->display_options['fields']['field_phosphorous_value']['field'] = 'field_phosphorous_value';
  $handler->display->display_options['fields']['field_phosphorous_value']['label'] = 'phosphorous_value';
  $handler->display->display_options['fields']['field_phosphorous_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Iodine */
  $handler->display->display_options['fields']['field_iodine_value']['id'] = 'field_iodine_value';
  $handler->display->display_options['fields']['field_iodine_value']['table'] = 'field_data_field_iodine_value';
  $handler->display->display_options['fields']['field_iodine_value']['field'] = 'field_iodine_value';
  $handler->display->display_options['fields']['field_iodine_value']['label'] = 'iodine_value';
  $handler->display->display_options['fields']['field_iodine_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Magnesium */
  $handler->display->display_options['fields']['field_magnesium_value']['id'] = 'field_magnesium_value';
  $handler->display->display_options['fields']['field_magnesium_value']['table'] = 'field_data_field_magnesium_value';
  $handler->display->display_options['fields']['field_magnesium_value']['field'] = 'field_magnesium_value';
  $handler->display->display_options['fields']['field_magnesium_value']['label'] = 'magnesium_value';
  $handler->display->display_options['fields']['field_magnesium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Zinc */
  $handler->display->display_options['fields']['field_zinc_value']['id'] = 'field_zinc_value';
  $handler->display->display_options['fields']['field_zinc_value']['table'] = 'field_data_field_zinc_value';
  $handler->display->display_options['fields']['field_zinc_value']['field'] = 'field_zinc_value';
  $handler->display->display_options['fields']['field_zinc_value']['label'] = 'zinc_value';
  $handler->display->display_options['fields']['field_zinc_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Selenium */
  $handler->display->display_options['fields']['field_selenium_value']['id'] = 'field_selenium_value';
  $handler->display->display_options['fields']['field_selenium_value']['table'] = 'field_data_field_selenium_value';
  $handler->display->display_options['fields']['field_selenium_value']['field'] = 'field_selenium_value';
  $handler->display->display_options['fields']['field_selenium_value']['label'] = 'selenium_value';
  $handler->display->display_options['fields']['field_selenium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Copper */
  $handler->display->display_options['fields']['field_copper_value']['id'] = 'field_copper_value';
  $handler->display->display_options['fields']['field_copper_value']['table'] = 'field_data_field_copper_value';
  $handler->display->display_options['fields']['field_copper_value']['field'] = 'field_copper_value';
  $handler->display->display_options['fields']['field_copper_value']['label'] = 'copper_value';
  $handler->display->display_options['fields']['field_copper_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Manganese */
  $handler->display->display_options['fields']['field_manganese_value']['id'] = 'field_manganese_value';
  $handler->display->display_options['fields']['field_manganese_value']['table'] = 'field_data_field_manganese_value';
  $handler->display->display_options['fields']['field_manganese_value']['field'] = 'field_manganese_value';
  $handler->display->display_options['fields']['field_manganese_value']['label'] = 'manganese_value';
  $handler->display->display_options['fields']['field_manganese_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Chromium */
  $handler->display->display_options['fields']['field_chromium_value']['id'] = 'field_chromium_value';
  $handler->display->display_options['fields']['field_chromium_value']['table'] = 'field_data_field_chromium_value';
  $handler->display->display_options['fields']['field_chromium_value']['field'] = 'field_chromium_value';
  $handler->display->display_options['fields']['field_chromium_value']['label'] = 'chromium_value';
  $handler->display->display_options['fields']['field_chromium_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Molybdenum */
  $handler->display->display_options['fields']['field_molybdenum_value']['id'] = 'field_molybdenum_value';
  $handler->display->display_options['fields']['field_molybdenum_value']['table'] = 'field_data_field_molybdenum_value';
  $handler->display->display_options['fields']['field_molybdenum_value']['field'] = 'field_molybdenum_value';
  $handler->display->display_options['fields']['field_molybdenum_value']['label'] = 'molybdenum_value';
  $handler->display->display_options['fields']['field_molybdenum_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Chloride */
  $handler->display->display_options['fields']['field_chloride_value']['id'] = 'field_chloride_value';
  $handler->display->display_options['fields']['field_chloride_value']['table'] = 'field_data_field_chloride_value';
  $handler->display->display_options['fields']['field_chloride_value']['field'] = 'field_chloride_value';
  $handler->display->display_options['fields']['field_chloride_value']['label'] = 'chloride_value';
  $handler->display->display_options['fields']['field_chloride_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: % Juice */
  $handler->display->display_options['fields']['field_juice_percent']['id'] = 'field_juice_percent';
  $handler->display->display_options['fields']['field_juice_percent']['table'] = 'field_data_field_juice_percent';
  $handler->display->display_options['fields']['field_juice_percent']['field'] = 'field_juice_percent';
  $handler->display->display_options['fields']['field_juice_percent']['label'] = 'juice_percent';
  $handler->display->display_options['fields']['field_juice_percent']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Height */
  $handler->display->display_options['fields']['field_pack_height']['id'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['table'] = 'field_data_field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['field'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['label'] = 'pack_height';
  $handler->display->display_options['fields']['field_pack_height']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Width */
  $handler->display->display_options['fields']['field_pack_width']['id'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['table'] = 'field_data_field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['field'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['label'] = 'pack_width';
  $handler->display->display_options['fields']['field_pack_width']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Length */
  $handler->display->display_options['fields']['field_pack_length']['id'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['table'] = 'field_data_field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['field'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['label'] = 'pack_length';
  $handler->display->display_options['fields']['field_pack_length']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: % Paperboard Recyclable */
  $handler->display->display_options['fields']['field_paperb_recycle_percent']['id'] = 'field_paperb_recycle_percent';
  $handler->display->display_options['fields']['field_paperb_recycle_percent']['table'] = 'field_data_field_paperb_recycle_percent';
  $handler->display->display_options['fields']['field_paperb_recycle_percent']['field'] = 'field_paperb_recycle_percent';
  $handler->display->display_options['fields']['field_paperb_recycle_percent']['label'] = 'paperb_recycle_percent';
  $handler->display->display_options['fields']['field_paperb_recycle_percent']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Beverage Container */
  $handler->display->display_options['fields']['field_beverage_container']['id'] = 'field_beverage_container';
  $handler->display->display_options['fields']['field_beverage_container']['table'] = 'field_data_field_beverage_container';
  $handler->display->display_options['fields']['field_beverage_container']['field'] = 'field_beverage_container';
  $handler->display->display_options['fields']['field_beverage_container']['label'] = 'beverage_container';
  $handler->display->display_options['fields']['field_beverage_container']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Bottle Color */
  $handler->display->display_options['fields']['field_bottle_color']['id'] = 'field_bottle_color';
  $handler->display->display_options['fields']['field_bottle_color']['table'] = 'field_data_field_bottle_color';
  $handler->display->display_options['fields']['field_bottle_color']['field'] = 'field_bottle_color';
  $handler->display->display_options['fields']['field_bottle_color']['label'] = 'bottle_color';
  $handler->display->display_options['fields']['field_bottle_color']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Container Type */
  $handler->display->display_options['fields']['field_container_type']['id'] = 'field_container_type';
  $handler->display->display_options['fields']['field_container_type']['table'] = 'field_data_field_container_type';
  $handler->display->display_options['fields']['field_container_type']['field'] = 'field_container_type';
  $handler->display->display_options['fields']['field_container_type']['label'] = 'container_type';
  $handler->display->display_options['fields']['field_container_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Product Labels */
  $handler->display->display_options['fields']['field_product_labels']['id'] = 'field_product_labels';
  $handler->display->display_options['fields']['field_product_labels']['table'] = 'field_data_field_product_labels';
  $handler->display->display_options['fields']['field_product_labels']['field'] = 'field_product_labels';
  $handler->display->display_options['fields']['field_product_labels']['label'] = 'product_label';
  $handler->display->display_options['fields']['field_product_labels']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_labels']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_product_labels']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_product_labels']['delta_offset'] = '0';
  /* Field: Content: Inner Pack UPC */
  $handler->display->display_options['fields']['field_inner_pack_upc']['id'] = 'field_inner_pack_upc';
  $handler->display->display_options['fields']['field_inner_pack_upc']['table'] = 'field_data_field_inner_pack_upc';
  $handler->display->display_options['fields']['field_inner_pack_upc']['field'] = 'field_inner_pack_upc';
  $handler->display->display_options['fields']['field_inner_pack_upc']['label'] = 'inner_pack_upc';
  $handler->display->display_options['fields']['field_inner_pack_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Inner Pack GTIN */
  $handler->display->display_options['fields']['field_inner_pack_gtin']['id'] = 'field_inner_pack_gtin';
  $handler->display->display_options['fields']['field_inner_pack_gtin']['table'] = 'field_data_field_inner_pack_gtin';
  $handler->display->display_options['fields']['field_inner_pack_gtin']['field'] = 'field_inner_pack_gtin';
  $handler->display->display_options['fields']['field_inner_pack_gtin']['label'] = 'inner_pack_gitn';
  $handler->display->display_options['fields']['field_inner_pack_gtin']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Inner Pack GTIN Type */
  $handler->display->display_options['fields']['field_inner_pack_gtin_type']['id'] = 'field_inner_pack_gtin_type';
  $handler->display->display_options['fields']['field_inner_pack_gtin_type']['table'] = 'field_data_field_inner_pack_gtin_type';
  $handler->display->display_options['fields']['field_inner_pack_gtin_type']['field'] = 'field_inner_pack_gtin_type';
  $handler->display->display_options['fields']['field_inner_pack_gtin_type']['label'] = 'inner_pack_gtin_type';
  $handler->display->display_options['fields']['field_inner_pack_gtin_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Inner Pack Height */
  $handler->display->display_options['fields']['field_cube_height']['id'] = 'field_cube_height';
  $handler->display->display_options['fields']['field_cube_height']['table'] = 'field_data_field_cube_height';
  $handler->display->display_options['fields']['field_cube_height']['field'] = 'field_cube_height';
  $handler->display->display_options['fields']['field_cube_height']['label'] = 'cube_height';
  $handler->display->display_options['fields']['field_cube_height']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Inner Pack Width */
  $handler->display->display_options['fields']['field_cube_width']['id'] = 'field_cube_width';
  $handler->display->display_options['fields']['field_cube_width']['table'] = 'field_data_field_cube_width';
  $handler->display->display_options['fields']['field_cube_width']['field'] = 'field_cube_width';
  $handler->display->display_options['fields']['field_cube_width']['label'] = 'cube_width';
  $handler->display->display_options['fields']['field_cube_width']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Inner Pack Length */
  $handler->display->display_options['fields']['field_cube_length']['id'] = 'field_cube_length';
  $handler->display->display_options['fields']['field_cube_length']['table'] = 'field_data_field_cube_length';
  $handler->display->display_options['fields']['field_cube_length']['field'] = 'field_cube_length';
  $handler->display->display_options['fields']['field_cube_length']['label'] = 'cube_length';
  $handler->display->display_options['fields']['field_cube_length']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case UPC */
  $handler->display->display_options['fields']['field_case_upc']['id'] = 'field_case_upc';
  $handler->display->display_options['fields']['field_case_upc']['table'] = 'field_data_field_case_upc';
  $handler->display->display_options['fields']['field_case_upc']['field'] = 'field_case_upc';
  $handler->display->display_options['fields']['field_case_upc']['label'] = 'case_upc';
  $handler->display->display_options['fields']['field_case_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case GTIN */
  $handler->display->display_options['fields']['field_case_gtin']['id'] = 'field_case_gtin';
  $handler->display->display_options['fields']['field_case_gtin']['table'] = 'field_data_field_case_gtin';
  $handler->display->display_options['fields']['field_case_gtin']['field'] = 'field_case_gtin';
  $handler->display->display_options['fields']['field_case_gtin']['label'] = 'case_gtin';
  $handler->display->display_options['fields']['field_case_gtin']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case GTIN Type */
  $handler->display->display_options['fields']['field_case_gtin_type']['id'] = 'field_case_gtin_type';
  $handler->display->display_options['fields']['field_case_gtin_type']['table'] = 'field_data_field_case_gtin_type';
  $handler->display->display_options['fields']['field_case_gtin_type']['field'] = 'field_case_gtin_type';
  $handler->display->display_options['fields']['field_case_gtin_type']['label'] = 'case_gtin_type';
  $handler->display->display_options['fields']['field_case_gtin_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Height */
  $handler->display->display_options['fields']['field_case_height']['id'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['table'] = 'field_data_field_case_height';
  $handler->display->display_options['fields']['field_case_height']['field'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['label'] = 'case_height';
  $handler->display->display_options['fields']['field_case_height']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Width */
  $handler->display->display_options['fields']['field_case_width']['id'] = 'field_case_width';
  $handler->display->display_options['fields']['field_case_width']['table'] = 'field_data_field_case_width';
  $handler->display->display_options['fields']['field_case_width']['field'] = 'field_case_width';
  $handler->display->display_options['fields']['field_case_width']['label'] = 'case_width';
  $handler->display->display_options['fields']['field_case_width']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Length */
  $handler->display->display_options['fields']['field_case_length']['id'] = 'field_case_length';
  $handler->display->display_options['fields']['field_case_length']['table'] = 'field_data_field_case_length';
  $handler->display->display_options['fields']['field_case_length']['field'] = 'field_case_length';
  $handler->display->display_options['fields']['field_case_length']['label'] = 'case_length';
  $handler->display->display_options['fields']['field_case_length']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Weight UOM */
  $handler->display->display_options['fields']['field_case_weight_uom']['id'] = 'field_case_weight_uom';
  $handler->display->display_options['fields']['field_case_weight_uom']['table'] = 'field_data_field_case_weight_uom';
  $handler->display->display_options['fields']['field_case_weight_uom']['field'] = 'field_case_weight_uom';
  $handler->display->display_options['fields']['field_case_weight_uom']['label'] = 'case_weight_uom';
  $handler->display->display_options['fields']['field_case_weight_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Gross Weight */
  $handler->display->display_options['fields']['field_case_weight']['id'] = 'field_case_weight';
  $handler->display->display_options['fields']['field_case_weight']['table'] = 'field_data_field_case_weight';
  $handler->display->display_options['fields']['field_case_weight']['field'] = 'field_case_weight';
  $handler->display->display_options['fields']['field_case_weight']['label'] = 'case_weight';
  $handler->display->display_options['fields']['field_case_weight']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Net Weight UOM */
  $handler->display->display_options['fields']['field_case_net_weight_uom']['id'] = 'field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['table'] = 'field_data_field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['field'] = 'field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['label'] = 'case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Net Weight */
  $handler->display->display_options['fields']['field_case_net_weight']['id'] = 'field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['table'] = 'field_data_field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['field'] = 'field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['label'] = 'case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Quantity Per Cube */
  $handler->display->display_options['fields']['field_case_cube']['id'] = 'field_case_cube';
  $handler->display->display_options['fields']['field_case_cube']['table'] = 'field_data_field_case_cube';
  $handler->display->display_options['fields']['field_case_cube']['field'] = 'field_case_cube';
  $handler->display->display_options['fields']['field_case_cube']['label'] = 'case_cube';
  $handler->display->display_options['fields']['field_case_cube']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Random Weight Item */
  $handler->display->display_options['fields']['field_random_weight']['id'] = 'field_random_weight';
  $handler->display->display_options['fields']['field_random_weight']['table'] = 'field_data_field_random_weight';
  $handler->display->display_options['fields']['field_random_weight']['field'] = 'field_random_weight';
  $handler->display->display_options['fields']['field_random_weight']['label'] = 'random_weight';
  $handler->display->display_options['fields']['field_random_weight']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Pallet Height */
  $handler->display->display_options['fields']['field_pallet_height']['id'] = 'field_pallet_height';
  $handler->display->display_options['fields']['field_pallet_height']['table'] = 'field_data_field_pallet_height';
  $handler->display->display_options['fields']['field_pallet_height']['field'] = 'field_pallet_height';
  $handler->display->display_options['fields']['field_pallet_height']['label'] = 'pallet_height';
  $handler->display->display_options['fields']['field_pallet_height']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Pallet Weight */
  $handler->display->display_options['fields']['field_pallet_weight']['id'] = 'field_pallet_weight';
  $handler->display->display_options['fields']['field_pallet_weight']['table'] = 'field_data_field_pallet_weight';
  $handler->display->display_options['fields']['field_pallet_weight']['field'] = 'field_pallet_weight';
  $handler->display->display_options['fields']['field_pallet_weight']['label'] = 'pallet_weight';
  $handler->display->display_options['fields']['field_pallet_weight']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Ti */
  $handler->display->display_options['fields']['field_tie']['id'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['table'] = 'field_data_field_tie';
  $handler->display->display_options['fields']['field_tie']['field'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['label'] = 'ti';
  $handler->display->display_options['fields']['field_tie']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Hi */
  $handler->display->display_options['fields']['field_high']['id'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['table'] = 'field_data_field_high';
  $handler->display->display_options['fields']['field_high']['field'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['label'] = 'hi';
  $handler->display->display_options['fields']['field_high']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Buyer/Planner */
  $handler->display->display_options['fields']['field_buyer']['id'] = 'field_buyer';
  $handler->display->display_options['fields']['field_buyer']['table'] = 'field_data_field_buyer';
  $handler->display->display_options['fields']['field_buyer']['field'] = 'field_buyer';
  $handler->display->display_options['fields']['field_buyer']['label'] = 'buyer';
  $handler->display->display_options['fields']['field_buyer']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Stocking Units */
  $handler->display->display_options['fields']['field_stocking_uom']['id'] = 'field_stocking_uom';
  $handler->display->display_options['fields']['field_stocking_uom']['table'] = 'field_data_field_stocking_uom';
  $handler->display->display_options['fields']['field_stocking_uom']['field'] = 'field_stocking_uom';
  $handler->display->display_options['fields']['field_stocking_uom']['label'] = 'stocking_uom';
  $handler->display->display_options['fields']['field_stocking_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Material Cost Type */
  $handler->display->display_options['fields']['field_material_cost_type']['id'] = 'field_material_cost_type';
  $handler->display->display_options['fields']['field_material_cost_type']['table'] = 'field_data_field_material_cost_type';
  $handler->display->display_options['fields']['field_material_cost_type']['field'] = 'field_material_cost_type';
  $handler->display->display_options['fields']['field_material_cost_type']['label'] = 'material_cost_type';
  $handler->display->display_options['fields']['field_material_cost_type']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Use OE to PO */
  $handler->display->display_options['fields']['field_backorderable']['id'] = 'field_backorderable';
  $handler->display->display_options['fields']['field_backorderable']['table'] = 'field_data_field_backorderable';
  $handler->display->display_options['fields']['field_backorderable']['field'] = 'field_backorderable';
  $handler->display->display_options['fields']['field_backorderable']['label'] = 'backorderable';
  $handler->display->display_options['fields']['field_backorderable']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Payment Terms */
  $handler->display->display_options['fields']['field_terms']['id'] = 'field_terms';
  $handler->display->display_options['fields']['field_terms']['table'] = 'field_data_field_terms';
  $handler->display->display_options['fields']['field_terms']['field'] = 'field_terms';
  $handler->display->display_options['fields']['field_terms']['label'] = 'terms';
  $handler->display->display_options['fields']['field_terms']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Manufacturing Method */
  $handler->display->display_options['fields']['field_pur_or_mfg']['id'] = 'field_pur_or_mfg';
  $handler->display->display_options['fields']['field_pur_or_mfg']['table'] = 'field_data_field_pur_or_mfg';
  $handler->display->display_options['fields']['field_pur_or_mfg']['field'] = 'field_pur_or_mfg';
  $handler->display->display_options['fields']['field_pur_or_mfg']['label'] = 'pur_or_mfg';
  $handler->display->display_options['fields']['field_pur_or_mfg']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Minimum Order Quantity */
  $handler->display->display_options['fields']['field_minimum_order_qty']['id'] = 'field_minimum_order_qty';
  $handler->display->display_options['fields']['field_minimum_order_qty']['table'] = 'field_data_field_minimum_order_qty';
  $handler->display->display_options['fields']['field_minimum_order_qty']['field'] = 'field_minimum_order_qty';
  $handler->display->display_options['fields']['field_minimum_order_qty']['label'] = 'minimum_order_qty';
  $handler->display->display_options['fields']['field_minimum_order_qty']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Unit SRP */
  $handler->display->display_options['fields']['field_unit_srp']['id'] = 'field_unit_srp';
  $handler->display->display_options['fields']['field_unit_srp']['table'] = 'field_data_field_unit_srp';
  $handler->display->display_options['fields']['field_unit_srp']['field'] = 'field_unit_srp';
  $handler->display->display_options['fields']['field_unit_srp']['label'] = 'unit_srp';
  $handler->display->display_options['fields']['field_unit_srp']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Supplier Cost */
  $handler->display->display_options['fields']['field_supplier_cost']['id'] = 'field_supplier_cost';
  $handler->display->display_options['fields']['field_supplier_cost']['table'] = 'field_data_field_supplier_cost';
  $handler->display->display_options['fields']['field_supplier_cost']['field'] = 'field_supplier_cost';
  $handler->display->display_options['fields']['field_supplier_cost']['label'] = 'supplier_cost';
  $handler->display->display_options['fields']['field_supplier_cost']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Cost Effective Date */
  $handler->display->display_options['fields']['field_cost_effective_date']['id'] = 'field_cost_effective_date';
  $handler->display->display_options['fields']['field_cost_effective_date']['table'] = 'field_data_field_cost_effective_date';
  $handler->display->display_options['fields']['field_cost_effective_date']['field'] = 'field_cost_effective_date';
  $handler->display->display_options['fields']['field_cost_effective_date']['label'] = 'cost_effective_date';
  $handler->display->display_options['fields']['field_cost_effective_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Price Sheet */
  $handler->display->display_options['fields']['field_pricing_sheet']['id'] = 'field_pricing_sheet';
  $handler->display->display_options['fields']['field_pricing_sheet']['table'] = 'field_data_field_pricing_sheet';
  $handler->display->display_options['fields']['field_pricing_sheet']['field'] = 'field_pricing_sheet';
  $handler->display->display_options['fields']['field_pricing_sheet']['label'] = 'pricing_sheet';
  $handler->display->display_options['fields']['field_pricing_sheet']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pricing_sheet']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_pricing_sheet']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_pricing_sheet']['delta_offset'] = '0';
  /* Field: Content: Chicago Water Tax */
  $handler->display->display_options['fields']['field_chicago_water_tax']['id'] = 'field_chicago_water_tax';
  $handler->display->display_options['fields']['field_chicago_water_tax']['table'] = 'field_data_field_chicago_water_tax';
  $handler->display->display_options['fields']['field_chicago_water_tax']['field'] = 'field_chicago_water_tax';
  $handler->display->display_options['fields']['field_chicago_water_tax']['label'] = 'chicago_water_tax';
  $handler->display->display_options['fields']['field_chicago_water_tax']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Baltimore Beverage Tax */
  $handler->display->display_options['fields']['field_baltimore_beverage_tax']['id'] = 'field_baltimore_beverage_tax';
  $handler->display->display_options['fields']['field_baltimore_beverage_tax']['table'] = 'field_data_field_baltimore_beverage_tax';
  $handler->display->display_options['fields']['field_baltimore_beverage_tax']['field'] = 'field_baltimore_beverage_tax';
  $handler->display->display_options['fields']['field_baltimore_beverage_tax']['label'] = 'baltimore_beverage_tax';
  $handler->display->display_options['fields']['field_baltimore_beverage_tax']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Berkeley Beverage Tax */
  $handler->display->display_options['fields']['field_berkeley_beverage_tax']['id'] = 'field_berkeley_beverage_tax';
  $handler->display->display_options['fields']['field_berkeley_beverage_tax']['table'] = 'field_data_field_berkeley_beverage_tax';
  $handler->display->display_options['fields']['field_berkeley_beverage_tax']['field'] = 'field_berkeley_beverage_tax';
  $handler->display->display_options['fields']['field_berkeley_beverage_tax']['label'] = 'berkeley_beverage_tax';
  $handler->display->display_options['fields']['field_berkeley_beverage_tax']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Freight Protection From */
  $handler->display->display_options['fields']['field_freight_protection_from']['id'] = 'field_freight_protection_from';
  $handler->display->display_options['fields']['field_freight_protection_from']['table'] = 'field_data_field_freight_protection_from';
  $handler->display->display_options['fields']['field_freight_protection_from']['field'] = 'field_freight_protection_from';
  $handler->display->display_options['fields']['field_freight_protection_from']['label'] = 'freight_protection_from';
  $handler->display->display_options['fields']['field_freight_protection_from']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Enrobed in Chocolate */
  $handler->display->display_options['fields']['field_enrobed_in_chocolate_']['id'] = 'field_enrobed_in_chocolate_';
  $handler->display->display_options['fields']['field_enrobed_in_chocolate_']['table'] = 'field_data_field_enrobed_in_chocolate_';
  $handler->display->display_options['fields']['field_enrobed_in_chocolate_']['field'] = 'field_enrobed_in_chocolate_';
  $handler->display->display_options['fields']['field_enrobed_in_chocolate_']['label'] = 'enrobed_in_chocolate';
  $handler->display->display_options['fields']['field_enrobed_in_chocolate_']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Customer Order Lead Time */
  $handler->display->display_options['fields']['field_lead_time_customer']['id'] = 'field_lead_time_customer';
  $handler->display->display_options['fields']['field_lead_time_customer']['table'] = 'field_data_field_lead_time_customer';
  $handler->display->display_options['fields']['field_lead_time_customer']['field'] = 'field_lead_time_customer';
  $handler->display->display_options['fields']['field_lead_time_customer']['label'] = 'lead_time_customer';
  $handler->display->display_options['fields']['field_lead_time_customer']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Shipping Lead Time */
  $handler->display->display_options['fields']['field_lead_time_shipping']['id'] = 'field_lead_time_shipping';
  $handler->display->display_options['fields']['field_lead_time_shipping']['table'] = 'field_data_field_lead_time_shipping';
  $handler->display->display_options['fields']['field_lead_time_shipping']['field'] = 'field_lead_time_shipping';
  $handler->display->display_options['fields']['field_lead_time_shipping']['label'] = 'lead_time_shipping';
  $handler->display->display_options['fields']['field_lead_time_shipping']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Printing Lead Time */
  $handler->display->display_options['fields']['field_lead_time_printing']['id'] = 'field_lead_time_printing';
  $handler->display->display_options['fields']['field_lead_time_printing']['table'] = 'field_data_field_lead_time_printing';
  $handler->display->display_options['fields']['field_lead_time_printing']['field'] = 'field_lead_time_printing';
  $handler->display->display_options['fields']['field_lead_time_printing']['label'] = 'lead_time_printing';
  $handler->display->display_options['fields']['field_lead_time_printing']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Guaranteed Shelf Life */
  $handler->display->display_options['fields']['field_warranty_days']['id'] = 'field_warranty_days';
  $handler->display->display_options['fields']['field_warranty_days']['table'] = 'field_data_field_warranty_days';
  $handler->display->display_options['fields']['field_warranty_days']['field'] = 'field_warranty_days';
  $handler->display->display_options['fields']['field_warranty_days']['label'] = 'warranty_days';
  $handler->display->display_options['fields']['field_warranty_days']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Shelf Life */
  $handler->display->display_options['fields']['field_shelf_life_days']['id'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['table'] = 'field_data_field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['field'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['label'] = 'shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Type of Code Life Dating */
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['id'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['table'] = 'field_data_field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['field'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['label'] = 'type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Open Code Life Dating */
  $handler->display->display_options['fields']['field_open_code_life_dating']['id'] = 'field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['table'] = 'field_data_field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['field'] = 'field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['label'] = 'open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Closed Code Life Dating */
  $handler->display->display_options['fields']['field_closed_code_life_dating']['id'] = 'field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['table'] = 'field_data_field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['field'] = 'field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['label'] = 'closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Grocery Type (Freight Protection Level) */
  $handler->display->display_options['fields']['field_freight_protection_level']['id'] = 'field_freight_protection_level';
  $handler->display->display_options['fields']['field_freight_protection_level']['table'] = 'field_data_field_freight_protection_level';
  $handler->display->display_options['fields']['field_freight_protection_level']['field'] = 'field_freight_protection_level';
  $handler->display->display_options['fields']['field_freight_protection_level']['label'] = 'freight_protection_level';
  $handler->display->display_options['fields']['field_freight_protection_level']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Primary Location */
  $handler->display->display_options['fields']['field_primary_location']['id'] = 'field_primary_location';
  $handler->display->display_options['fields']['field_primary_location']['table'] = 'field_data_field_primary_location';
  $handler->display->display_options['fields']['field_primary_location']['field'] = 'field_primary_location';
  $handler->display->display_options['fields']['field_primary_location']['label'] = 'primary_location';
  $handler->display->display_options['fields']['field_primary_location']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: East FOB Location */
  $handler->display->display_options['fields']['field_east_fob_location']['id'] = 'field_east_fob_location';
  $handler->display->display_options['fields']['field_east_fob_location']['table'] = 'field_data_field_east_fob_location';
  $handler->display->display_options['fields']['field_east_fob_location']['field'] = 'field_east_fob_location';
  $handler->display->display_options['fields']['field_east_fob_location']['label'] = 'east_fob_location';
  $handler->display->display_options['fields']['field_east_fob_location']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: West FOB Location */
  $handler->display->display_options['fields']['field_west_fob_location']['id'] = 'field_west_fob_location';
  $handler->display->display_options['fields']['field_west_fob_location']['table'] = 'field_data_field_west_fob_location';
  $handler->display->display_options['fields']['field_west_fob_location']['field'] = 'field_west_fob_location';
  $handler->display->display_options['fields']['field_west_fob_location']['label'] = 'west_fob_location';
  $handler->display->display_options['fields']['field_west_fob_location']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vendor ID(s) */
  $handler->display->display_options['fields']['field_vendors']['id'] = 'field_vendors';
  $handler->display->display_options['fields']['field_vendors']['table'] = 'field_data_field_vendors';
  $handler->display->display_options['fields']['field_vendors']['field'] = 'field_vendors';
  $handler->display->display_options['fields']['field_vendors']['label'] = 'vendor_id';
  $handler->display->display_options['fields']['field_vendors']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Vendor Item Number */
  $handler->display->display_options['fields']['field_vendor_item_number']['id'] = 'field_vendor_item_number';
  $handler->display->display_options['fields']['field_vendor_item_number']['table'] = 'field_data_field_vendor_item_number';
  $handler->display->display_options['fields']['field_vendor_item_number']['field'] = 'field_vendor_item_number';
  $handler->display->display_options['fields']['field_vendor_item_number']['label'] = 'vendor_item_number';
  $handler->display->display_options['fields']['field_vendor_item_number']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Target Export */
  $handler->display->display_options['fields']['field_target_export']['id'] = 'field_target_export';
  $handler->display->display_options['fields']['field_target_export']['table'] = 'field_data_field_target_export';
  $handler->display->display_options['fields']['field_target_export']['field'] = 'field_target_export';
  $handler->display->display_options['fields']['field_target_export']['label'] = 'target_export';
  $handler->display->display_options['fields']['field_target_export']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: UNFI East Export */
  $handler->display->display_options['fields']['field_unfi_east']['id'] = 'field_unfi_east';
  $handler->display->display_options['fields']['field_unfi_east']['table'] = 'field_data_field_unfi_east';
  $handler->display->display_options['fields']['field_unfi_east']['field'] = 'field_unfi_east';
  $handler->display->display_options['fields']['field_unfi_east']['label'] = 'unfi_east';
  $handler->display->display_options['fields']['field_unfi_east']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: UNFI West Export */
  $handler->display->display_options['fields']['field_unfi_west']['id'] = 'field_unfi_west';
  $handler->display->display_options['fields']['field_unfi_west']['table'] = 'field_data_field_unfi_west';
  $handler->display->display_options['fields']['field_unfi_west']['field'] = 'field_unfi_west';
  $handler->display->display_options['fields']['field_unfi_west']['label'] = 'unfi_west';
  $handler->display->display_options['fields']['field_unfi_west']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: iTrade Export */
  $handler->display->display_options['fields']['field_itrade_export']['id'] = 'field_itrade_export';
  $handler->display->display_options['fields']['field_itrade_export']['table'] = 'field_data_field_itrade_export';
  $handler->display->display_options['fields']['field_itrade_export']['field'] = 'field_itrade_export';
  $handler->display->display_options['fields']['field_itrade_export']['label'] = 'itrade_export';
  $handler->display->display_options['fields']['field_itrade_export']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: IX-One Export */
  $handler->display->display_options['fields']['field_ix_one_export']['id'] = 'field_ix_one_export';
  $handler->display->display_options['fields']['field_ix_one_export']['table'] = 'field_data_field_ix_one_export';
  $handler->display->display_options['fields']['field_ix_one_export']['field'] = 'field_ix_one_export';
  $handler->display->display_options['fields']['field_ix_one_export']['label'] = 'ix_one_export';
  $handler->display->display_options['fields']['field_ix_one_export']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Taxable */
  $handler->display->display_options['fields']['field_taxable']['id'] = 'field_taxable';
  $handler->display->display_options['fields']['field_taxable']['table'] = 'field_data_field_taxable';
  $handler->display->display_options['fields']['field_taxable']['field'] = 'field_taxable';
  $handler->display->display_options['fields']['field_taxable']['label'] = 'taxable';
  $handler->display->display_options['fields']['field_taxable']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Controlled */
  $handler->display->display_options['fields']['field_controlled']['id'] = 'field_controlled';
  $handler->display->display_options['fields']['field_controlled']['table'] = 'field_data_field_controlled';
  $handler->display->display_options['fields']['field_controlled']['field'] = 'field_controlled';
  $handler->display->display_options['fields']['field_controlled']['label'] = 'controlled';
  $handler->display->display_options['fields']['field_controlled']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Inventory Transaction Audit */
  $handler->display->display_options['fields']['field_inv_transaction_audit']['id'] = 'field_inv_transaction_audit';
  $handler->display->display_options['fields']['field_inv_transaction_audit']['table'] = 'field_data_field_inv_transaction_audit';
  $handler->display->display_options['fields']['field_inv_transaction_audit']['field'] = 'field_inv_transaction_audit';
  $handler->display->display_options['fields']['field_inv_transaction_audit']['label'] = 'inv_transaction_audit';
  $handler->display->display_options['fields']['field_inv_transaction_audit']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Stocked */
  $handler->display->display_options['fields']['field_stocked']['id'] = 'field_stocked';
  $handler->display->display_options['fields']['field_stocked']['table'] = 'field_data_field_stocked';
  $handler->display->display_options['fields']['field_stocked']['field'] = 'field_stocked';
  $handler->display->display_options['fields']['field_stocked']['label'] = 'stocked';
  $handler->display->display_options['fields']['field_stocked']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Cost End Date */
  $handler->display->display_options['fields']['field_cost_end_date']['id'] = 'field_cost_end_date';
  $handler->display->display_options['fields']['field_cost_end_date']['table'] = 'field_data_field_cost_end_date';
  $handler->display->display_options['fields']['field_cost_end_date']['field'] = 'field_cost_end_date';
  $handler->display->display_options['fields']['field_cost_end_date']['label'] = 'cost_end_date';
  $handler->display->display_options['fields']['field_cost_end_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Purchasing Units */
  $handler->display->display_options['fields']['field_purchasing_uom']['id'] = 'field_purchasing_uom';
  $handler->display->display_options['fields']['field_purchasing_uom']['table'] = 'field_data_field_purchasing_uom';
  $handler->display->display_options['fields']['field_purchasing_uom']['field'] = 'field_purchasing_uom';
  $handler->display->display_options['fields']['field_purchasing_uom']['label'] = 'purchasing_uom';
  $handler->display->display_options['fields']['field_purchasing_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Selling Units */
  $handler->display->display_options['fields']['field_price_uom']['id'] = 'field_price_uom';
  $handler->display->display_options['fields']['field_price_uom']['table'] = 'field_data_field_price_uom';
  $handler->display->display_options['fields']['field_price_uom']['field'] = 'field_price_uom';
  $handler->display->display_options['fields']['field_price_uom']['label'] = 'price_uom';
  $handler->display->display_options['fields']['field_price_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Manufacturing Units */
  $handler->display->display_options['fields']['field_manufacturing_uom']['id'] = 'field_manufacturing_uom';
  $handler->display->display_options['fields']['field_manufacturing_uom']['table'] = 'field_data_field_manufacturing_uom';
  $handler->display->display_options['fields']['field_manufacturing_uom']['field'] = 'field_manufacturing_uom';
  $handler->display->display_options['fields']['field_manufacturing_uom']['label'] = 'manufacturing_uom';
  $handler->display->display_options['fields']['field_manufacturing_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Price Basis Code */
  $handler->display->display_options['fields']['field_price_basis_code']['id'] = 'field_price_basis_code';
  $handler->display->display_options['fields']['field_price_basis_code']['table'] = 'field_data_field_price_basis_code';
  $handler->display->display_options['fields']['field_price_basis_code']['field'] = 'field_price_basis_code';
  $handler->display->display_options['fields']['field_price_basis_code']['label'] = 'price_basis_code';
  $handler->display->display_options['fields']['field_price_basis_code']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Contract Number */
  $handler->display->display_options['fields']['field_contract_number']['id'] = 'field_contract_number';
  $handler->display->display_options['fields']['field_contract_number']['table'] = 'field_data_field_contract_number';
  $handler->display->display_options['fields']['field_contract_number']['field'] = 'field_contract_number';
  $handler->display->display_options['fields']['field_contract_number']['label'] = 'contract_number';
  $handler->display->display_options['fields']['field_contract_number']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Manufacturing Method */
  $handler->display->display_options['fields']['field_manufacturing_method']['id'] = 'field_manufacturing_method';
  $handler->display->display_options['fields']['field_manufacturing_method']['table'] = 'field_data_field_manufacturing_method';
  $handler->display->display_options['fields']['field_manufacturing_method']['field'] = 'field_manufacturing_method';
  $handler->display->display_options['fields']['field_manufacturing_method']['label'] = 'manufacturing_method';
  $handler->display->display_options['fields']['field_manufacturing_method']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Backorderable */
  $handler->display->display_options['fields']['field_po_req_fg']['id'] = 'field_po_req_fg';
  $handler->display->display_options['fields']['field_po_req_fg']['table'] = 'field_data_field_po_req_fg';
  $handler->display->display_options['fields']['field_po_req_fg']['field'] = 'field_po_req_fg';
  $handler->display->display_options['fields']['field_po_req_fg']['label'] = 'po_req_fg';
  $handler->display->display_options['fields']['field_po_req_fg']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Contextual filter: Content: Item Number (field_item_num) */
  $handler->display->display_options['arguments']['field_item_num_value']['id'] = 'field_item_num_value';
  $handler->display->display_options['arguments']['field_item_num_value']['table'] = 'field_data_field_item_num';
  $handler->display->display_options['arguments']['field_item_num_value']['field'] = 'field_item_num_value';
  $handler->display->display_options['arguments']['field_item_num_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_item_num_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_item_num_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_item_num_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_item_num_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_item_num_value']['limit'] = '0';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_details' => 'product_details',
  );

  /* Display: JSON */
  $handler = $view->new_display('page', 'JSON', 'bmb_single_product_data_json');
  $handler->display->display_options['path'] = 'bmbpim/product/%/details.json';

  /* Display: XML */
  $handler = $view->new_display('page', 'XML', 'bmb_single_product_data_xml');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_xml_style';
  $handler->display->display_options['style_options']['root_element'] = 'products';
  $handler->display->display_options['style_options']['top_child_object'] = 'product';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['header'] = '';
  $handler->display->display_options['style_options']['author'] = 'mbernal';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'bmbpim/product/%/details.xml';

  /* Display: CSV */
  $handler = $view->new_display('views_data_export', 'CSV', 'bmb_single_product_data_csv');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%1-value-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'bmbpim/product/%/details.csv';
  $export['bmb_single_product_data'] = $view;

  return $export;
}
