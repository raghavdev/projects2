<?php
/**
 * @file
 * enterprise_data_polling.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enterprise_data_polling_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enterprise_data_poll_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'enterprise_data_poll_log';
  $view->human_name = 'Enterprise Data Poll Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'start' => 'start',
    'DataExtractSid' => 'DataExtractSid',
    'finish' => 'finish',
    'JobExecSid' => 'JobExecSid',
    'message' => 'message',
    'status' => 'status',
    'task' => 'task',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'DataExtractSid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finish' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'JobExecSid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'task' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: start */
  $handler->display->display_options['fields']['start']['id'] = 'start';
  $handler->display->display_options['fields']['start']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['start']['field'] = 'start';
  $handler->display->display_options['fields']['start']['date_format'] = 'short';
  /* Field: Content: finish */
  $handler->display->display_options['fields']['finish']['id'] = 'finish';
  $handler->display->display_options['fields']['finish']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['finish']['field'] = 'finish';
  $handler->display->display_options['fields']['finish']['date_format'] = 'short';
  /* Field: Content: task */
  $handler->display->display_options['fields']['task']['id'] = 'task';
  $handler->display->display_options['fields']['task']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['task']['field'] = 'task';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Content: message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  /* Field: Content: Data Extract SID */
  $handler->display->display_options['fields']['DataExtractSid']['id'] = 'DataExtractSid';
  $handler->display->display_options['fields']['DataExtractSid']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['DataExtractSid']['field'] = 'DataExtractSid';
  /* Field: Content: Job Exec Sid */
  $handler->display->display_options['fields']['JobExecSid']['id'] = 'JobExecSid';
  $handler->display->display_options['fields']['JobExecSid']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['fields']['JobExecSid']['field'] = 'JobExecSid';
  /* Filter criterion: Content: start */
  $handler->display->display_options['filters']['start']['id'] = 'start';
  $handler->display->display_options['filters']['start']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['filters']['start']['field'] = 'start';
  $handler->display->display_options['filters']['start']['group'] = 1;
  $handler->display->display_options['filters']['start']['exposed'] = TRUE;
  $handler->display->display_options['filters']['start']['expose']['operator_id'] = 'start_op';
  $handler->display->display_options['filters']['start']['expose']['operator'] = 'start_op';
  $handler->display->display_options['filters']['start']['expose']['identifier'] = 'start';
  $handler->display->display_options['filters']['start']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['start']['group_info']['label'] = 'start';
  $handler->display->display_options['filters']['start']['group_info']['identifier'] = 'start';
  $handler->display->display_options['filters']['start']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: finish */
  $handler->display->display_options['filters']['finish']['id'] = 'finish';
  $handler->display->display_options['filters']['finish']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['filters']['finish']['field'] = 'finish';
  $handler->display->display_options['filters']['finish']['group'] = 1;
  $handler->display->display_options['filters']['finish']['exposed'] = TRUE;
  $handler->display->display_options['filters']['finish']['expose']['operator_id'] = 'finish_op';
  $handler->display->display_options['filters']['finish']['expose']['operator'] = 'finish_op';
  $handler->display->display_options['filters']['finish']['expose']['identifier'] = 'finish';
  $handler->display->display_options['filters']['finish']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['finish']['group_info']['label'] = 'finish';
  $handler->display->display_options['filters']['finish']['group_info']['identifier'] = 'finish';
  $handler->display->display_options['filters']['finish']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => array(
        'type' => 'date',
        'value' => '',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Active',
      'operator' => '=',
      'value' => '1',
    ),
    2 => array(
      'title' => 'Not Active',
      'operator' => '=',
      'value' => '0',
    ),
  );
  /* Filter criterion: Content: task */
  $handler->display->display_options['filters']['task']['id'] = 'task';
  $handler->display->display_options['filters']['task']['table'] = 'enterprise_data_poll_log';
  $handler->display->display_options['filters']['task']['field'] = 'task';
  $handler->display->display_options['filters']['task']['group'] = 1;
  $handler->display->display_options['filters']['task']['exposed'] = TRUE;
  $handler->display->display_options['filters']['task']['expose']['operator_id'] = 'task_op';
  $handler->display->display_options['filters']['task']['expose']['label'] = 'task';
  $handler->display->display_options['filters']['task']['expose']['operator'] = 'task_op';
  $handler->display->display_options['filters']['task']['expose']['identifier'] = 'task';
  $handler->display->display_options['filters']['task']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['task']['group_info']['label'] = 'task';
  $handler->display->display_options['filters']['task']['group_info']['identifier'] = 'task';
  $handler->display->display_options['filters']['task']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Products -> DC',
      'operator' => '=',
      'value' => 'products_dc',
    ),
    2 => array(
      'title' => 'UBS Brands -> DC',
      'operator' => '=',
      'value' => 'ubsbrands_dc',
    ),
    3 => array(
      'title' => 'WBS Brands -> DC',
      'operator' => '=',
      'value' => 'wbsbrands_dc',
    ),
    4 => array(
      'title' => 'RCM Cats -> EIW',
      'operator' => '=',
      'value' => 'rcmcats_eiw',
    ),
    5 => array(
      'title' => 'Ent Brands -> EIW',
      'operator' => '=',
      'value' => 'entbrands_eiw',
    ),
    6 => array(
      'title' => 'FS Cats -> EIW',
      'operator' => '=',
      'value' => 'fscats_eiw',
    ),
    7 => array(
      'title' => 'CMP Export',
      'operator' => '=',
      'value' => 'cmp_export',
    ),
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['enterprise_data_poll_log'] = $view;

  return $export;
}
