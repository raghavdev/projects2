<?php
/**
 * @file
 * enterprise_data_brands.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_data_brands_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'brand_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Brand Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit enterprise data brands';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_productsid' => 'field_productsid',
    'field_description4' => 'field_description4',
    'field_unit_weight' => 'field_unit_weight',
    'field_master_case_upc' => 'field_master_case_upc',
  );
  $handler->display->display_options['style_options']['default'] = 'field_productsid';
  $handler->display->display_options['style_options']['info'] = array(
    'field_productsid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_weight' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_master_case_upc' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: ProductSID */
  $handler->display->display_options['fields']['field_productsid']['id'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['table'] = 'field_data_field_productsid';
  $handler->display->display_options['fields']['field_productsid']['field'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['label'] = 'Item #';
  $handler->display->display_options['fields']['field_productsid']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Description4 */
  $handler->display->display_options['fields']['field_description4']['id'] = 'field_description4';
  $handler->display->display_options['fields']['field_description4']['table'] = 'field_data_field_description4';
  $handler->display->display_options['fields']['field_description4']['field'] = 'field_description4';
  $handler->display->display_options['fields']['field_description4']['label'] = 'Item Description';
  $handler->display->display_options['fields']['field_description4']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Unit Weight */
  $handler->display->display_options['fields']['field_unit_weight']['id'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['table'] = 'field_data_field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['field'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['label'] = 'Size?';
  $handler->display->display_options['fields']['field_unit_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Master Case UPC */
  $handler->display->display_options['fields']['field_master_case_upc']['id'] = 'field_master_case_upc';
  $handler->display->display_options['fields']['field_master_case_upc']['table'] = 'field_data_field_master_case_upc';
  $handler->display->display_options['fields']['field_master_case_upc']['field'] = 'field_master_case_upc';
  $handler->display->display_options['fields']['field_master_case_upc']['label'] = 'UPC';
  $handler->display->display_options['fields']['field_master_case_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: ProductSID (field_productsid) */
  $handler->display->display_options['sorts']['field_productsid_value']['id'] = 'field_productsid_value';
  $handler->display->display_options['sorts']['field_productsid_value']['table'] = 'field_data_field_productsid';
  $handler->display->display_options['sorts']['field_productsid_value']['field'] = 'field_productsid_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_details' => 'product_details',
  );

  /* Display: Brand Items Page */
  $handler = $view->new_display('page', 'Brand Items Page', 'brand_items_page');
  $handler->display->display_options['path'] = 'admin/config/enterprisedata/brands/items';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Items';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['brand_items'] = $view;

  $view = new view();
  $view->name = 'east_brands';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'East Brands';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'East Brands';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit enterprise data brands';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_east_short_brand_name' => 'field_east_short_brand_name',
    'field_short_brand_name' => 'field_short_brand_name',
    'field_ent_long_brand_name' => 'field_ent_long_brand_name',
  );
  $handler->display->display_options['style_options']['default'] = 'field_east_short_brand_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_east_short_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ent_long_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['id'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['field'] = 'reverse_field_east_brands_node';
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_east_short_brand_name']['id'] = 'field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['field'] = 'field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['label'] = 'Short Brand Name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_short_brand_name']['id'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['field'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['relationship'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['fields']['field_short_brand_name']['label'] = 'Enterprise Short Brand Name';
  $handler->display->display_options['fields']['field_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Long brand name */
  $handler->display->display_options['fields']['field_ent_long_brand_name']['id'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['table'] = 'field_data_field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['field'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['relationship'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['label'] = 'Enterprise Long Brand Name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  /* Contextual filter: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['limit'] = '1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'east_brand' => 'east_brand',
  );
  /* Filter criterion: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['operator_id'] = 'field_east_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['label'] = 'Search Short Name';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['operator'] = 'field_east_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['identifier'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );

  /* Display: East Brands Page */
  $handler = $view->new_display('page', 'East Brands Page', 'east_brands_page');
  $handler->display->display_options['path'] = 'admin/config/enterprisedata/brands/east';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'East Brands';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Unassigned Page */
  $handler = $view->new_display('page', 'Unassigned Page', 'unassigned_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'east_brand' => 'east_brand',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  /* Filter criterion: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['operator_id'] = 'field_east_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['label'] = 'Search Short Name';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['operator'] = 'field_east_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['identifier'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['filters']['field_east_short_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  $handler->display->display_options['path'] = 'admin/config/enterprisedata/brands/east/unassigned';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unassigned';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: East Brands Glossary */
  $handler = $view->new_display('attachment', 'East Brands Glossary', 'east_brands_glossary');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['displays'] = array(
    'east_brands_page' => 'east_brands_page',
    'default' => 0,
    'unassigned_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Unassigned Glossary */
  $handler = $view->new_display('attachment', 'Unassigned Glossary', 'unassigned_glossary');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['base_path'] = 'admin/config/enterprisedata/brands/east/unassigned';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_east_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'east_brand' => 'east_brand',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'unassigned_page' => 'unassigned_page',
    'default' => 0,
    'east_brands_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['east_brands'] = $view;

  $view = new view();
  $view->name = 'east_brands_field';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'East Brands Field';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['id'] = 'reverse_field_east_brands_node';
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_east_brands_node']['field'] = 'reverse_field_east_brands_node';
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_east_short_brand_name']['id'] = 'field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['field'] = 'field_east_short_brand_name';
  $handler->display->display_options['fields']['field_east_short_brand_name']['label'] = '';
  $handler->display->display_options['fields']['field_east_short_brand_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_east_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Short brand name (field_east_short_brand_name) */
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['id'] = 'field_east_short_brand_name_value';
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['table'] = 'field_data_field_east_short_brand_name';
  $handler->display->display_options['sorts']['field_east_short_brand_name_value']['field'] = 'field_east_short_brand_name_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'east_brand' => 'east_brand',
  );

  /* Display: East Brands Field Reference */
  $handler = $view->new_display('entityreference', 'East Brands Field Reference', 'east_brands_field_reference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_east_short_brand_name' => 'field_east_short_brand_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['east_brands_field'] = $view;

  $view = new view();
  $view->name = 'enterprise_brands';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Enterprise Brands';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Enterprise Brands';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit enterprise data brands';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_ent_long_brand_name' => 'field_ent_long_brand_name',
    'field_short_brand_name' => 'field_short_brand_name',
    'field_customer_name' => 'field_customer_name',
  );
  $handler->display->display_options['style_options']['default'] = 'field_ent_long_brand_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_ent_long_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Long brand name */
  $handler->display->display_options['fields']['field_ent_long_brand_name']['id'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['table'] = 'field_data_field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['field'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['label'] = 'Long Brand Name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_short_brand_name']['id'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['field'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['label'] = 'Short Brand Name';
  $handler->display->display_options['fields']['field_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Customer name */
  $handler->display->display_options['fields']['field_customer_name']['id'] = 'field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['table'] = 'field_data_field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['field'] = 'field_customer_name';
  $handler->display->display_options['fields']['field_customer_name']['label'] = 'Customer Name';
  $handler->display->display_options['fields']['field_customer_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_short_brand_name) */
  $handler->display->display_options['arguments']['field_short_brand_name_value']['id'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['field'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['limit'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_brand' => 'enterprise_brand',
  );
  /* Filter criterion: Content: Active (field_ent_active) */
  $handler->display->display_options['filters']['field_ent_active_value']['id'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['table'] = 'field_data_field_ent_active';
  $handler->display->display_options['filters']['field_ent_active_value']['field'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ent_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator_id'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['label'] = 'Show';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['label'] = 'Active (field_ent_active)';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Enterprise Brands Page */
  $handler = $view->new_display('page', 'Enterprise Brands Page', 'enterprise_brands_page');
  $handler->display->display_options['path'] = 'admin/enterprisedata/brands';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Enterprise Brands';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Enterprise Brands';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Missing East Page */
  $handler = $view->new_display('page', 'Missing East Page', 'missing_east_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_brand' => 'enterprise_brand',
  );
  /* Filter criterion: Content: Active (field_ent_active) */
  $handler->display->display_options['filters']['field_ent_active_value']['id'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['table'] = 'field_data_field_ent_active';
  $handler->display->display_options['filters']['field_ent_active_value']['field'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ent_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator_id'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['label'] = 'Show';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['label'] = 'Active (field_ent_active)';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: East brands (field_east_brands) */
  $handler->display->display_options['filters']['field_east_brands_target_id']['id'] = 'field_east_brands_target_id';
  $handler->display->display_options['filters']['field_east_brands_target_id']['table'] = 'field_data_field_east_brands';
  $handler->display->display_options['filters']['field_east_brands_target_id']['field'] = 'field_east_brands_target_id';
  $handler->display->display_options['filters']['field_east_brands_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['operator_id'] = 'field_east_brands_target_id_op';
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['label'] = 'East brands (field_east_brands)';
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['operator'] = 'field_east_brands_target_id_op';
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['identifier'] = 'field_east_brands_target_id';
  $handler->display->display_options['filters']['field_east_brands_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'admin/enterprisedata/brands/enterprise/missing-east';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Missing East';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Missing West Page */
  $handler = $view->new_display('page', 'Missing West Page', 'missing_west_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_brand' => 'enterprise_brand',
  );
  /* Filter criterion: Content: Active (field_ent_active) */
  $handler->display->display_options['filters']['field_ent_active_value']['id'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['table'] = 'field_data_field_ent_active';
  $handler->display->display_options['filters']['field_ent_active_value']['field'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ent_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator_id'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['label'] = 'Show';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['label'] = 'Active (field_ent_active)';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: West brands (field_west_brands) */
  $handler->display->display_options['filters']['field_west_brands_target_id']['id'] = 'field_west_brands_target_id';
  $handler->display->display_options['filters']['field_west_brands_target_id']['table'] = 'field_data_field_west_brands';
  $handler->display->display_options['filters']['field_west_brands_target_id']['field'] = 'field_west_brands_target_id';
  $handler->display->display_options['filters']['field_west_brands_target_id']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'admin/enterprisedata/brands/enterprise/missing-west';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Missing West';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Enterprise Brands Glossary */
  $handler = $view->new_display('attachment', 'Enterprise Brands Glossary', 'enterprise_brands_glossary');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_short_brand_name) */
  $handler->display->display_options['arguments']['field_short_brand_name_value']['id'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['field'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['displays'] = array(
    'enterprise_brands_page' => 'enterprise_brands_page',
    'default' => 0,
    'missing_east_page' => 0,
    'missing_west_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Missing East Glossary */
  $handler = $view->new_display('attachment', 'Missing East Glossary', 'missing_east_glossary');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_short_brand_name) */
  $handler->display->display_options['arguments']['field_short_brand_name_value']['id'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['field'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['base_path'] = 'admin/enterprisedata/brands/enterprise/missing-east';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_brand' => 'enterprise_brand',
  );
  /* Filter criterion: Content: Active (field_ent_active) */
  $handler->display->display_options['filters']['field_ent_active_value']['id'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['table'] = 'field_data_field_ent_active';
  $handler->display->display_options['filters']['field_ent_active_value']['field'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ent_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator_id'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['label'] = 'Show';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['label'] = 'Active (field_ent_active)';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: East brands (field_east_brands) */
  $handler->display->display_options['filters']['field_east_brands_target_id']['id'] = 'field_east_brands_target_id';
  $handler->display->display_options['filters']['field_east_brands_target_id']['table'] = 'field_data_field_east_brands';
  $handler->display->display_options['filters']['field_east_brands_target_id']['field'] = 'field_east_brands_target_id';
  $handler->display->display_options['filters']['field_east_brands_target_id']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'missing_east_page' => 'missing_east_page',
    'default' => 0,
    'enterprise_brands_page' => 0,
    'missing_west_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Missing West Glossary */
  $handler = $view->new_display('attachment', 'Missing West Glossary', 'missing_west_glossary');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_short_brand_name) */
  $handler->display->display_options['arguments']['field_short_brand_name_value']['id'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['field'] = 'field_short_brand_name_value';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['base_path'] = 'admin/enterprisedata/brands/enterprise/missing-west';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enterprise_brand' => 'enterprise_brand',
  );
  /* Filter criterion: Content: Active (field_ent_active) */
  $handler->display->display_options['filters']['field_ent_active_value']['id'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['table'] = 'field_data_field_ent_active';
  $handler->display->display_options['filters']['field_ent_active_value']['field'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ent_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator_id'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['label'] = 'Show';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['operator'] = 'field_ent_active_value_op';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['label'] = 'Active (field_ent_active)';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['identifier'] = 'field_ent_active_value';
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_ent_active_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: West brands (field_west_brands) */
  $handler->display->display_options['filters']['field_west_brands_target_id']['id'] = 'field_west_brands_target_id';
  $handler->display->display_options['filters']['field_west_brands_target_id']['table'] = 'field_data_field_west_brands';
  $handler->display->display_options['filters']['field_west_brands_target_id']['field'] = 'field_west_brands_target_id';
  $handler->display->display_options['filters']['field_west_brands_target_id']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'missing_west_page' => 'missing_west_page',
    'default' => 0,
    'enterprise_brands_page' => 0,
    'missing_east_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['enterprise_brands'] = $view;

  $view = new view();
  $view->name = 'west_brands';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'West Brands';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'West Brands';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit enterprise data brands';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_west_short_brand_name' => 'field_west_short_brand_name',
    'field_west_long_brand_name' => 'field_west_long_brand_name',
    'field_short_brand_name' => 'field_short_brand_name',
    'field_ent_long_brand_name' => 'field_ent_long_brand_name',
  );
  $handler->display->display_options['style_options']['default'] = 'field_west_short_brand_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_west_short_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_west_long_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ent_long_brand_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['id'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['field'] = 'reverse_field_west_brands_node';
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_west_short_brand_name']['id'] = 'field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['field'] = 'field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['label'] = 'West Short Brand Name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Long brand name */
  $handler->display->display_options['fields']['field_west_long_brand_name']['id'] = 'field_west_long_brand_name';
  $handler->display->display_options['fields']['field_west_long_brand_name']['table'] = 'field_data_field_west_long_brand_name';
  $handler->display->display_options['fields']['field_west_long_brand_name']['field'] = 'field_west_long_brand_name';
  $handler->display->display_options['fields']['field_west_long_brand_name']['label'] = 'West Long Brand Name';
  $handler->display->display_options['fields']['field_west_long_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_short_brand_name']['id'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['table'] = 'field_data_field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['field'] = 'field_short_brand_name';
  $handler->display->display_options['fields']['field_short_brand_name']['relationship'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['fields']['field_short_brand_name']['label'] = 'Enterprise Short Brand Name';
  $handler->display->display_options['fields']['field_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Long brand name */
  $handler->display->display_options['fields']['field_ent_long_brand_name']['id'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['table'] = 'field_data_field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['field'] = 'field_ent_long_brand_name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['relationship'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['label'] = 'Enterprise Long Brand Name';
  $handler->display->display_options['fields']['field_ent_long_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/edit/enterprise_brand';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Long brand name (field_west_long_brand_name) */
  $handler->display->display_options['sorts']['field_west_long_brand_name_value']['id'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['sorts']['field_west_long_brand_name_value']['table'] = 'field_data_field_west_long_brand_name';
  $handler->display->display_options['sorts']['field_west_long_brand_name_value']['field'] = 'field_west_long_brand_name_value';
  /* Contextual filter: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['limit'] = '1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'west_brand' => 'west_brand',
  );
  /* Filter criterion: Content: Long brand name (field_west_long_brand_name) */
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['id'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['table'] = 'field_data_field_west_long_brand_name';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['field'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['operator_id'] = 'field_west_long_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['label'] = 'Search Long Name';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['operator'] = 'field_west_long_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['identifier'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['operator_id'] = 'field_west_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['label'] = 'Search Short Name';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['operator'] = 'field_west_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['identifier'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );

  /* Display: West Brands Page */
  $handler = $view->new_display('page', 'West Brands Page', 'west_brands_page');
  $handler->display->display_options['path'] = 'admin/config/enterprisedata/brands/west';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'West Brands';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Unassigned Page */
  $handler = $view->new_display('page', 'Unassigned Page', 'unassigned_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'west_brand' => 'west_brand',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  /* Filter criterion: Content: Long brand name (field_west_long_brand_name) */
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['id'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['table'] = 'field_data_field_west_long_brand_name';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['field'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['operator_id'] = 'field_west_long_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['label'] = 'Search Long Name';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['operator'] = 'field_west_long_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['identifier'] = 'field_west_long_brand_name_value';
  $handler->display->display_options['filters']['field_west_long_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['operator_id'] = 'field_west_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['label'] = 'Search Short Name';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['operator'] = 'field_west_short_brand_name_value_op';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['identifier'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['filters']['field_west_short_brand_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    23 => 0,
    17 => 0,
    24 => 0,
    21 => 0,
    22 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  $handler->display->display_options['path'] = 'admin/config/enterprisedata/brands/west/unassigned';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unassigned';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: West Brands Glossary */
  $handler = $view->new_display('attachment', 'West Brands Glossary', 'west_brands_glossary');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['displays'] = array(
    'west_brands_page' => 'west_brands_page',
    'default' => 0,
    'unassigned_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Unassigned Glossary */
  $handler = $view->new_display('attachment', 'Unassigned Glossary', 'unassigned_glossary');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['base_path'] = 'admin/config/enterprisedata/brands/west/unassigned';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_west_short_brand_name_value']['limit'] = '1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'west_brand' => 'west_brand',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'unassigned_page' => 'unassigned_page',
    'default' => 0,
    'west_brands_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['west_brands'] = $view;

  $view = new view();
  $view->name = 'west_brands_field';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'West Brands Field';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['id'] = 'reverse_field_west_brands_node';
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_west_brands_node']['field'] = 'reverse_field_west_brands_node';
  /* Field: Content: Short brand name */
  $handler->display->display_options['fields']['field_west_short_brand_name']['id'] = 'field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['field'] = 'field_west_short_brand_name';
  $handler->display->display_options['fields']['field_west_short_brand_name']['label'] = '';
  $handler->display->display_options['fields']['field_west_short_brand_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_west_short_brand_name']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Short brand name (field_west_short_brand_name) */
  $handler->display->display_options['sorts']['field_west_short_brand_name_value']['id'] = 'field_west_short_brand_name_value';
  $handler->display->display_options['sorts']['field_west_short_brand_name_value']['table'] = 'field_data_field_west_short_brand_name';
  $handler->display->display_options['sorts']['field_west_short_brand_name_value']['field'] = 'field_west_short_brand_name_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'west_brand' => 'west_brand',
  );

  /* Display: West Brands Field Reference */
  $handler = $view->new_display('entityreference', 'West Brands Field Reference', 'west_brands_field_reference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_west_short_brand_name' => 'field_west_short_brand_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['west_brands_field'] = $view;

  return $export;
}
