<?php
/**
 * @file
 * crm_api_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_api_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bmb_crm';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BMB CRM';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'BMB CRM';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['label'] = 'Total';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'PRODUCT_NAME';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['table'] = 'field_data_field_brand';
  $handler->display->display_options['fields']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_brand']['alter']['text'] = '&amp;#039; == \'';
  $handler->display->display_options['fields']['field_brand']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Consumer Brand Name */
  $handler->display->display_options['fields']['field_consumer_brand_name']['id'] = 'field_consumer_brand_name';
  $handler->display->display_options['fields']['field_consumer_brand_name']['table'] = 'field_data_field_consumer_brand_name';
  $handler->display->display_options['fields']['field_consumer_brand_name']['field'] = 'field_consumer_brand_name';
  $handler->display->display_options['fields']['field_consumer_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Country of Origin */
  $handler->display->display_options['fields']['field_country_of_origin']['id'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['table'] = 'field_data_field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['field'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Gluten Attributes */
  $handler->display->display_options['fields']['field_gluten_attributes']['id'] = 'field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['table'] = 'field_data_field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['field'] = 'field_gluten_attributes';
  $handler->display->display_options['fields']['field_gluten_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_gluten_attributes']['delta_offset'] = '0';
  /* Field: Content: Hi */
  $handler->display->display_options['fields']['field_high']['id'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['table'] = 'field_data_field_high';
  $handler->display->display_options['fields']['field_high']['field'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Daily */
  $handler->display->display_options['fields']['field_kosher_daily']['id'] = 'field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['table'] = 'field_data_field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['field'] = 'field_kosher_daily';
  $handler->display->display_options['fields']['field_kosher_daily']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - MBUF */
  $handler->display->display_options['fields']['field_kosher_mbuf']['id'] = 'field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['table'] = 'field_data_field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['field'] = 'field_kosher_mbuf';
  $handler->display->display_options['fields']['field_kosher_mbuf']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Pareve */
  $handler->display->display_options['fields']['field_kosher_pareve']['id'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['table'] = 'field_data_field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['field'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Kosher - Passover Only */
  $handler->display->display_options['fields']['field_kosher_passover']['id'] = 'field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['table'] = 'field_data_field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['field'] = 'field_kosher_passover';
  $handler->display->display_options['fields']['field_kosher_passover']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Height */
  $handler->display->display_options['fields']['field_pack_height']['id'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['table'] = 'field_data_field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['field'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Length */
  $handler->display->display_options['fields']['field_pack_length']['id'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['table'] = 'field_data_field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['field'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Width */
  $handler->display->display_options['fields']['field_pack_width']['id'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['table'] = 'field_data_field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['field'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Height */
  $handler->display->display_options['fields']['field_case_height']['id'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['table'] = 'field_data_field_case_height';
  $handler->display->display_options['fields']['field_case_height']['field'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Length */
  $handler->display->display_options['fields']['field_case_length']['id'] = 'field_case_length';
  $handler->display->display_options['fields']['field_case_length']['table'] = 'field_data_field_case_length';
  $handler->display->display_options['fields']['field_case_length']['field'] = 'field_case_length';
  $handler->display->display_options['fields']['field_case_length']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Width */
  $handler->display->display_options['fields']['field_case_width']['id'] = 'field_case_width';
  $handler->display->display_options['fields']['field_case_width']['table'] = 'field_data_field_case_width';
  $handler->display->display_options['fields']['field_case_width']['field'] = 'field_case_width';
  $handler->display->display_options['fields']['field_case_width']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Net Weight UOM */
  $handler->display->display_options['fields']['field_case_net_weight_uom']['id'] = 'field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['table'] = 'field_data_field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['field'] = 'field_case_net_weight_uom';
  $handler->display->display_options['fields']['field_case_net_weight_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Net Weight */
  $handler->display->display_options['fields']['field_case_net_weight']['id'] = 'field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['table'] = 'field_data_field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['field'] = 'field_case_net_weight';
  $handler->display->display_options['fields']['field_case_net_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Weight Drained */
  $handler->display->display_options['fields']['field_item_weight']['id'] = 'field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['table'] = 'field_data_field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['field'] = 'field_item_weight';
  $handler->display->display_options['fields']['field_item_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Non-GMO Project */
  $handler->display->display_options['fields']['field_non_gmo']['id'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['table'] = 'field_data_field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['field'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Open Code Life Dating */
  $handler->display->display_options['fields']['field_open_code_life_dating']['id'] = 'field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['table'] = 'field_data_field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['field'] = 'field_open_code_life_dating';
  $handler->display->display_options['fields']['field_open_code_life_dating']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Closed Code Life Dating */
  $handler->display->display_options['fields']['field_closed_code_life_dating']['id'] = 'field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['table'] = 'field_data_field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['field'] = 'field_closed_code_life_dating';
  $handler->display->display_options['fields']['field_closed_code_life_dating']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Shelf Life */
  $handler->display->display_options['fields']['field_shelf_life_days']['id'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['table'] = 'field_data_field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['field'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Ti */
  $handler->display->display_options['fields']['field_tie']['id'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['table'] = 'field_data_field_tie';
  $handler->display->display_options['fields']['field_tie']['field'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Type of Code Life Dating */
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['id'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['table'] = 'field_data_field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['field'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: UPC (Product/Unit) */
  $handler->display->display_options['fields']['field_upc']['id'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['table'] = 'field_data_field_upc';
  $handler->display->display_options['fields']['field_upc']['field'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['label'] = 'UPC';
  $handler->display->display_options['fields']['field_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Vegan or Vegetarian */
  $handler->display->display_options['fields']['field_veg_attributes']['id'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['table'] = 'field_data_field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['field'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_veg_attributes']['delta_offset'] = '0';
  /* Field: Field: Macola ID */
  $handler->display->display_options['fields']['field_macola_id']['id'] = 'field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['table'] = 'field_data_field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['field'] = 'field_macola_id';
  $handler->display->display_options['fields']['field_macola_id']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Size */
  $handler->display->display_options['fields']['field_item_size']['id'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['table'] = 'field_data_field_item_size';
  $handler->display->display_options['fields']['field_item_size']['field'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Size UOM */
  $handler->display->display_options['fields']['field_item_size_uom']['id'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['table'] = 'field_data_field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['field'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Free of Substances */
  $handler->display->display_options['fields']['field_free_of_attributes']['id'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['table'] = 'field_data_field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['field'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_free_of_attributes']['delta_offset'] = '0';
  /* Field: Content: Major Allergens */
  $handler->display->display_options['fields']['field_major_allergen_attributes']['id'] = 'field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['table'] = 'field_data_field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['field'] = 'field_major_allergen_attributes';
  $handler->display->display_options['fields']['field_major_allergen_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_major_allergen_attributes']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'modified';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'modified';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    17 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'perPage';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25,50,100,250';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'all';
  $handler->display->display_options['pager']['options']['expose']['offset'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'product_name';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['table'] = 'field_data_field_brand';
  $handler->display->display_options['fields']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['label'] = 'brand';
  $handler->display->display_options['fields']['field_brand']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_brand']['alter']['text'] = '&amp;#039; == \'';
  $handler->display->display_options['fields']['field_brand']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Country of Origin */
  $handler->display->display_options['fields']['field_country_of_origin']['id'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['table'] = 'field_data_field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['field'] = 'field_country_of_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['label'] = 'country_origin';
  $handler->display->display_options['fields']['field_country_of_origin']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Ti */
  $handler->display->display_options['fields']['field_tie']['id'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['table'] = 'field_data_field_tie';
  $handler->display->display_options['fields']['field_tie']['field'] = 'field_tie';
  $handler->display->display_options['fields']['field_tie']['label'] = 'ti';
  $handler->display->display_options['fields']['field_tie']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Hi */
  $handler->display->display_options['fields']['field_high']['id'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['table'] = 'field_data_field_high';
  $handler->display->display_options['fields']['field_high']['field'] = 'field_high';
  $handler->display->display_options['fields']['field_high']['label'] = 'hi';
  $handler->display->display_options['fields']['field_high']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
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
  /* Field: Content: Kosher - Pareve */
  $handler->display->display_options['fields']['field_kosher_pareve']['id'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['table'] = 'field_data_field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['field'] = 'field_kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['label'] = 'kosher_pareve';
  $handler->display->display_options['fields']['field_kosher_pareve']['settings'] = array(
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
  /* Field: Content: Retail Height */
  $handler->display->display_options['fields']['field_pack_height']['id'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['table'] = 'field_data_field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['field'] = 'field_pack_height';
  $handler->display->display_options['fields']['field_pack_height']['label'] = 'retail_height';
  $handler->display->display_options['fields']['field_pack_height']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Length */
  $handler->display->display_options['fields']['field_pack_length']['id'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['table'] = 'field_data_field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['field'] = 'field_pack_length';
  $handler->display->display_options['fields']['field_pack_length']['label'] = 'retail_length';
  $handler->display->display_options['fields']['field_pack_length']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Retail Width */
  $handler->display->display_options['fields']['field_pack_width']['id'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['table'] = 'field_data_field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['field'] = 'field_pack_width';
  $handler->display->display_options['fields']['field_pack_width']['label'] = 'retail_width';
  $handler->display->display_options['fields']['field_pack_width']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case Height */
  $handler->display->display_options['fields']['field_case_height']['id'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['table'] = 'field_data_field_case_height';
  $handler->display->display_options['fields']['field_case_height']['field'] = 'field_case_height';
  $handler->display->display_options['fields']['field_case_height']['label'] = 'case_height';
  $handler->display->display_options['fields']['field_case_height']['settings'] = array(
    'thousand_separator' => ' ',
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
    'thousand_separator' => ' ',
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
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
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
  /* Field: Content: Non-GMO Project */
  $handler->display->display_options['fields']['field_non_gmo']['id'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['table'] = 'field_data_field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['field'] = 'field_non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['label'] = 'non_gmo';
  $handler->display->display_options['fields']['field_non_gmo']['settings'] = array(
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
  /* Field: Content: Shelf Life */
  $handler->display->display_options['fields']['field_shelf_life_days']['id'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['table'] = 'field_data_field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['field'] = 'field_shelf_life_days';
  $handler->display->display_options['fields']['field_shelf_life_days']['label'] = 'shelf_life';
  $handler->display->display_options['fields']['field_shelf_life_days']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Type of Code Life Dating */
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['id'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['table'] = 'field_data_field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['field'] = 'field_type_of_code_life_dating';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['label'] = 'code_life_dating_type';
  $handler->display->display_options['fields']['field_type_of_code_life_dating']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: UPC (Product/Unit) */
  $handler->display->display_options['fields']['field_upc']['id'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['table'] = 'field_data_field_upc';
  $handler->display->display_options['fields']['field_upc']['field'] = 'field_upc';
  $handler->display->display_options['fields']['field_upc']['label'] = 'upc';
  $handler->display->display_options['fields']['field_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Vegan or Vegetarian */
  $handler->display->display_options['fields']['field_veg_attributes']['id'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['table'] = 'field_data_field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['field'] = 'field_veg_attributes';
  $handler->display->display_options['fields']['field_veg_attributes']['label'] = 'vegan';
  $handler->display->display_options['fields']['field_veg_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_veg_attributes']['delta_offset'] = '0';
  /* Field: Content: Net Size */
  $handler->display->display_options['fields']['field_item_size']['id'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['table'] = 'field_data_field_item_size';
  $handler->display->display_options['fields']['field_item_size']['field'] = 'field_item_size';
  $handler->display->display_options['fields']['field_item_size']['label'] = 'net_size';
  $handler->display->display_options['fields']['field_item_size']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Net Size UOM */
  $handler->display->display_options['fields']['field_item_size_uom']['id'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['table'] = 'field_data_field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['field'] = 'field_item_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['label'] = 'net_size_uom';
  $handler->display->display_options['fields']['field_item_size_uom']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Free of Substances */
  $handler->display->display_options['fields']['field_free_of_attributes']['id'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['table'] = 'field_data_field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['field'] = 'field_free_of_attributes';
  $handler->display->display_options['fields']['field_free_of_attributes']['label'] = 'free_of';
  $handler->display->display_options['fields']['field_free_of_attributes']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_free_of_attributes']['delta_offset'] = '0';
  /* Field: Content: Item Number */
  $handler->display->display_options['fields']['field_item_num']['id'] = 'field_item_num';
  $handler->display->display_options['fields']['field_item_num']['table'] = 'field_data_field_item_num';
  $handler->display->display_options['fields']['field_item_num']['field'] = 'field_item_num';
  $handler->display->display_options['fields']['field_item_num']['label'] = 'item_number';
  $handler->display->display_options['fields']['field_item_num']['settings'] = array(
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
  $handler->display->display_options['path'] = 'product';
  $export['bmb_crm'] = $view;

  return $export;
}
