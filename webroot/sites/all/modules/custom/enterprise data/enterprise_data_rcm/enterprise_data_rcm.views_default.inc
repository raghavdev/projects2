<?php
/**
 * @file
 * enterprise_data_rcm.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_data_rcm_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rcm_hierarchy_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'RCM Hierarchy Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer rcm hierarchy items';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: ProductSID */
  $handler->display->display_options['fields']['field_productsid']['id'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['table'] = 'field_data_field_productsid';
  $handler->display->display_options['fields']['field_productsid']['field'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['label'] = 'Item #';
  $handler->display->display_options['fields']['field_productsid']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Enterprise Brand */
  $handler->display->display_options['fields']['field_enterprise_brand']['id'] = 'field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['table'] = 'field_data_field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['field'] = 'field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['label'] = 'Brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enterprise_brand']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Description';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Unit Weight */
  $handler->display->display_options['fields']['field_unit_weight']['id'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['table'] = 'field_data_field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['field'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['label'] = 'Size';
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="item-edit" href="#[nid]">Edit</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: ProductSID (field_productsid) */
  $handler->display->display_options['sorts']['field_productsid_value']['id'] = 'field_productsid_value';
  $handler->display->display_options['sorts']['field_productsid_value']['table'] = 'field_data_field_productsid';
  $handler->display->display_options['sorts']['field_productsid_value']['field'] = 'field_productsid_value';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
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
  /* Filter criterion: Content: Enterprise Brand (field_enterprise_brand) */
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['id'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['table'] = 'field_data_field_enterprise_brand';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['field'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator_id'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['label'] = 'Enterprise Brand (field_enterprise_brand)';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['remember_roles'] = array(
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
    23 => 0,
    16 => 0,
    24 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
  );
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['label'] = 'Show Only';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'TEST',
      'operator' => '=',
      'value' => array(
        'value' => 'TEST1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: RCM Hierarchy Items Page */
  $handler = $view->new_display('page', 'RCM Hierarchy Items Page', 'rcm_hierarchy_items_page');
  $handler->display->display_options['path'] = 'admin/enterprisedata/rcm/items';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Items';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: RCM Hierarchy Items Glossary */
  $handler = $view->new_display('attachment', 'RCM Hierarchy Items Glossary', 'rcm_items_glossary');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['displays'] = array(
    'rcm_hierarchy_items_page' => 'rcm_hierarchy_items_page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: RCM Hierarchy Unassigned Items */
  $handler = $view->new_display('page', 'RCM Hierarchy Unassigned Items', 'rcm_hierarchy_unassigned_items');
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
    'product_details' => 'product_details',
  );
  /* Filter criterion: Content: Enterprise Brand (field_enterprise_brand) */
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['id'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['table'] = 'field_data_field_enterprise_brand';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['field'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator_id'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['label'] = 'Enterprise Brand (field_enterprise_brand)';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['label'] = 'Show Only';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: RCM Hierarchy (field_rcm_hierarchy) */
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['id'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['table'] = 'field_data_field_rcm_hierarchy';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['field'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'admin/enterprisedata/rcm/items/unassigned';

  /* Display: RCM Hierarchy Unassigned Glossary */
  $handler = $view->new_display('attachment', 'RCM Hierarchy Unassigned Glossary', 'rcm_hierarchy_unassigned_glossary');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
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
    'product_details' => 'product_details',
  );
  /* Filter criterion: Content: RCM Hierarchy (field_rcm_hierarchy) */
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['id'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['table'] = 'field_data_field_rcm_hierarchy';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['field'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['filters']['field_rcm_hierarchy_target_id']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'rcm_hierarchy_unassigned_items' => 'rcm_hierarchy_unassigned_items',
    'default' => 0,
    'rcm_hierarchy_items_page' => 0,
  );
  $export['rcm_hierarchy_items'] = $view;

  $view = new view();
  $view->name = 'rcm_item_assignment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'rcm item assignment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_productsid' => 'field_productsid',
    'field_enterprise_brand' => 'field_enterprise_brand',
    'title' => 'title',
    'field_unit_weight' => 'field_unit_weight',
    'field_master_case_upc' => 'field_master_case_upc',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_productsid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enterprise_brand' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_rcm_hierarchy_target_id']['id'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['relationships']['field_rcm_hierarchy_target_id']['table'] = 'field_data_field_rcm_hierarchy';
  $handler->display->display_options['relationships']['field_rcm_hierarchy_target_id']['field'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['relationships']['field_rcm_hierarchy_target_id']['required'] = TRUE;
  /* Field: Content: ProductSID */
  $handler->display->display_options['fields']['field_productsid']['id'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['table'] = 'field_data_field_productsid';
  $handler->display->display_options['fields']['field_productsid']['field'] = 'field_productsid';
  $handler->display->display_options['fields']['field_productsid']['label'] = 'Item #';
  $handler->display->display_options['fields']['field_productsid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_productsid']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Enterprise Brand */
  $handler->display->display_options['fields']['field_enterprise_brand']['id'] = 'field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['table'] = 'field_data_field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['field'] = 'field_enterprise_brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['label'] = 'Brand';
  $handler->display->display_options['fields']['field_enterprise_brand']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enterprise_brand']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Description';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Unit Weight */
  $handler->display->display_options['fields']['field_unit_weight']['id'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['table'] = 'field_data_field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['field'] = 'field_unit_weight';
  $handler->display->display_options['fields']['field_unit_weight']['label'] = 'Size';
  $handler->display->display_options['fields']['field_unit_weight']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_master_case_upc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_case_upc']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="">Edit</a>
<a href="">Remove</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_rcm_hierarchy_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Enterprise Brand (field_enterprise_brand) */
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['id'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['table'] = 'field_data_field_enterprise_brand';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['field'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator_id'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['label'] = 'Show Only';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['operator'] = 'field_enterprise_brand_target_id_op';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['expose']['remember_roles'] = array(
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
    23 => 0,
    16 => 0,
    24 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
  );
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['label'] = 'Show Only';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['identifier'] = 'field_enterprise_brand_target_id';
  $handler->display->display_options['filters']['field_enterprise_brand_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search Current Items For';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    23 => 0,
    16 => 0,
    24 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_productsid' => 'field_productsid',
    'field_enterprise_brand' => 'field_enterprise_brand',
    'title' => 'title',
    'field_unit_weight' => 'field_unit_weight',
    'field_master_case_upc' => 'field_master_case_upc',
  );

  /* Display: RCM Items Assignment */
  $handler = $view->new_display('block', 'RCM Items Assignment', 'rcm_items_assignment');
  $handler->display->display_options['block_description'] = 'rcm_item_assignment';
  $export['rcm_item_assignment'] = $view;

  return $export;
}
