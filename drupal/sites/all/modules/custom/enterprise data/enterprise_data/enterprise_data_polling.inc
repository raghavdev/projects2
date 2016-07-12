<?php

//Update this if we ever need more types of polling
function enterprise_data_get_polling_defs() {
  $types = array();

  $types['products_dc'] = array("name" => "Products -> DC",
                                "help" => "Syncronize product and distribution product data from MS SQL to Digital Core",
                                "run_options" => false);
  $types['ubsbrands_dc'] = array("name" => "UBS Brands -> DC",
                                "help" => "Syncronize east brands from MS SQL to Digital Core",
                                "run_options" => false);
  $types['wbsbrands_dc'] = array("name" => "WBS Brands -> DC",
                                "help" => "Syncronize west brands from MS SQL to Digital Core",
                                "run_options" => false);
  $types['rcmcats_eiw'] = array("name" => "RCM Cats -> EIW",
                                "help" => "Push RCM Category data down to the MS SQL Instance",
                                "run_options" => true);
  $types['entbrands_eiw'] = array("name" => "Ent Brands -> EIW",
                                "help" => "Push the enterprise brands down to the MS SQL Instance",
                                "run_options" => true);
  $types['fscats_eiw'] = array("name" => "FS Cats -> EIW",
                                "help" => "Push the food service categories down to the MS SQL Instance",
                                "run_options" => true);
  $types['cmp_export'] = array("name" => "CMP Export",
                                "help" => "Export the XML and image assets for the third party CMP service",
                                "run_options" => true);

  return $types;
}

function enterprise_data_polling_run_task($task) {

}

function enterprise_data_admin_form($form, &$form_state) {

  $form['#attributes']['class'][] = 'polling-form';
  // Horizontal tabs container
  $form['group_tabs'] = array(
    '#type'     => 'horizontal_tabs',
    '#attached' => array('library' => array(array('field_group', 'horizontal-tabs'))), // Converts fieldsets into tabs
  );

  //Polling Log form
  //////////////////////////////////////////////////////////////////////////

  $form['polling_log'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Polling Log'),
    '#group' => 'group_tabs',
  );

//  $block = module_invoke('views', 'block', 'enterprise_data_poll_log-block');
//  $block_data = render($block['content']);

  $block = block_load('views', 'enterprise_data_poll_log-block');
  $block_build = _block_render_blocks(array($block));
  $block_data = _block_get_renderable_array($block_build);

  $form['polling_log']['log'] = $block_data;

  //Polling Tasks form
  //////////////////////////////////////////////////////////////////////////

  $form['polling_tasks'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Polling Tasks'),
    '#group' => 'group_tabs',
  );

  $form['polling_tasks']['polling_task_data'] = array (
    '#type' => 'fieldset',
    '#theme' => 'enterprise_data_table',
    '#tree' => TRUE,
  );

  $polling_types = enterprise_data_get_polling_defs();

  foreach($polling_types as $id => $data) {

//    //query the database see if this task is on
    $enabled = db_select("elysia_cron")
                 ->fields("elysia_cron", array("disable"))
                 ->condition("name", $id)
                 ->execute()
                 ->fetchField();

    $form['polling_tasks']['polling_task_data']['task'][$id] = array(
      '#description' => t(""),
      '#markup' => "<div class='polling_task'>{$data['name']}</div><div class='polling_task_help'>{$data['help']}</div>"
    );

    $form['polling_tasks']['polling_task_data']['schedule'][$id] = array(
        '#type' => 'select',
        '#options' => array("*/15 * * * *" => "Every 15 minutes",
                            "*/30 * * * *" => "Every 30 minutes",
                            "0 * * * *" => "Every hour",
                            "0 */6 * * *" => "Every 6 hours",
                            "4 0 * * *" => "Once a day",
                            "4 0 * * 0" => "Once a week",
                            "4 0 1 * *" => "Once a month",
                            "at_hour" => "Every hour at:",
                            "at_day" => "Every day at:",
                            "custom" => "Custom"),
        '#description' => t(""),
        '#default_value' => "",//TODO
        '#required' => TRUE,
        '#maxlength' => 500,
        '#size' => 1,
        '#multiple' => false,
        '#attributes' => array(
          'class' => array('poll-time-select'),
         ),
      );

    $form['polling_tasks']['polling_task_data']['schedule_qualifier_hour'][$id] = array(
      '#description' => t(""),
      '#type' => 'textfield',
      '#title' => t('Min:'),
      '#maxlength' => 3,
      '#size' => 1,
      '#states' => array(
         'visible' => array(
           ':input[name="polling_task_data[schedule][' . $id . ']"]' => array('value' => 'at_hour'),
          ),
       ),
    );

    $form['polling_tasks']['polling_task_data']['schedule_qualifier_day'][$id] = array(
      '#type' => 'fieldset',
      '#attributes' => array(
         'class' => array('poll-time-atday'),
       ),
       '#states' => array(
         'visible' => array(
           ':input[name="polling_task_data[schedule][' . $id . ']"]' => array('value' => 'at_day'),
          ),
       ),
    );
    $form['polling_tasks']['polling_task_data']['schedule_qualifier_day'][$id]['hr'] = array(
      '#description' => t(""),
      '#type' => 'textfield',
      '#title' => t('Hr:'),
      '#maxlength' => 3,
      '#size' => 1,
    );
    $form['polling_tasks']['polling_task_data']['schedule_qualifier_day'][$id]['min'] = array(
      '#description' => t(""),
      '#type' => 'textfield',
      '#title' => t('Min:'),
      '#maxlength' => 3,
      '#size' => 1,
    );
    $form['polling_tasks']['polling_task_data']['schedule_qualifier_day'][$id]['phase'] = array(
      '#type' => 'select',
        '#options' => array("am" => "AM",
                            "pm" => "PM"),
        '#description' => t(""),
        '#default_value' => "",//TODO
        '#required' => TRUE,
        '#maxlength' => 500,
        '#size' => 1,
        '#multiple' => false,
    );
     $form['polling_tasks']['polling_task_data']['schedule_qualifier_custom'][$id] = array(
      '#description' => t(""),
      '#type' => 'textfield',
      '#title' => t(''),
      '#maxlength' => 15,
      '#size' => 19,
      '#states' => array(
         'visible' => array(
           ':input[name="polling_task_data[schedule][' . $id . ']"]' => array('value' => 'custom'),
          ),
       ),
    );
    $form['polling_tasks']['polling_task_data']['status'][$id] = array(
      '#type' => 'radios',
      '#default_value' => 'off', //TODO check db to set default $enabled
      '#options' => array('on' => 'on', 'off'=> 'off'),
      '#title' => t(''),
      '#attributes' => array(
         'class' => array('status-switch'),
       ),
    );

    $lastRun = db_select("enterprise_data_poll_log")
                ->fields("enterprise_data_poll_log", array("start"))
                ->condition("task", $id)
                ->execute()
                ->fetchField();

    if(!$lastRun || $lastRun == "") {
      $lastRun = "never";
    }
    else {
     $lastRun = date('m-d-Y h:iA', $lastRun);
    }

    $form['polling_tasks']['polling_task_data']['lastrun'][$id] = array(
      '#markup' => $lastRun
    );

    $form['polling_tasks']['polling_task_data']['run'][$id] = array(
      '#type' => 'fieldset',
    );

    if($data['run_options']) {
      $form['polling_tasks']['polling_task_data']['run'][$id]['options'] = array(
        '#type' => 'select',
          '#options' => array("incremental" => "Incremental",
                              "initialize_out" => "Initialize Out"),
          '#description' => t(""),
          '#default_value' => "",
          '#required' => TRUE,
          '#maxlength' => 500,
          '#size' => 1,
          '#multiple' => false,
      );
    }

    $form['polling_tasks']['polling_task_data']['run'][$id]['button'] = array(
      "#markup" => "<button><a href='/service/enterprisedata/sync/{$id}'>Run</a></button>"
    );
  }

  //config tag form
  //////////////////////////////////////////////////////////////////////////
  $form['Configuration'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Configuration'),
    '#group' => 'group_tabs',
  );

  $form['Configuration']['mssql_host'] = array(
    '#type' => 'textfield',
    '#title' => t('MS SQL Host IP'),
    '#description' => t('The IP address of the MS SQL Server instance.'),
    '#default_value' => variable_get('mssql_host', ''),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['Configuration']['mssql_port'] = array(
    '#type' => 'textfield',
    '#title' => t('MS SQL Port'),
    '#description' => t('The port for the MS SQL Server instance.'),
    '#default_value' => variable_get('mssql_port', '1433'),
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['Configuration']['mssql_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('MS SQL Domain'),
    '#description' => t('The domain for the MS SQL Server instance.'),
    '#default_value' => variable_get('mssql_domain', ''),
    '#size' => 40,
    '#required' => TRUE,
  );

  $form['Configuration']['mssql_user'] = array(
    '#type' => 'textfield',
    '#title' => t('MS SQL Username'),
    '#description' => t('The username for the MS SQL Server instance.'),
    '#default_value' => variable_get('mssql_user', ''),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['Configuration']['mssql_password'] = array(
    '#type' => 'password',
    '#title' => t('MS SQL Password'),
    '#description' => t('The password for the MS SQL Server instance.'),
    '#default_value' => '',
    '#size' => 60,
  );

  $form['Configuration']['mssql_schema'] = array(
    '#type' => 'textfield',
    '#title' => t('MS SQL Schema'),
    '#description' => t('The database schema to use when querying the MS SQL Server instance.'),
    '#default_value' => variable_get('mssql_schema', ''),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['Configuration']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

function theme_enterprise_data_table($variables) {

  $form = $variables['form'];

  $header = array(t('Task'), t("Schedule"), t("Last Run"), t("Status"), t("Run Task"));

  $rows = array();

  $polling_types = enterprise_data_get_polling_defs();

  foreach ($polling_types as $id => $type) {

    $record = array();

    $record[] = drupal_render($form['task'][$id]);
    $schedule = drupal_render($form['schedule'][$id]);
    $schedule .= drupal_render($form['schedule_qualifier_hour'][$id]);
    $schedule .= drupal_render($form['schedule_qualifier_day'][$id]);
    $schedule .= drupal_render($form['schedule_qualifier_custom'][$id]);
    $record[] = $schedule;

    $record[] = drupal_render($form['lastrun'][$id]);
    $record[] = drupal_render($form['status'][$id]);
    $record[] = drupal_render($form['run'][$id]);


    $rows[] = $record;
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows
  ));

  return $output;
}

/**
 * Validate the form.
 */
function enterprise_data_admin_form_validate($form, &$form_state) {
  // Validate the host IP.
  if (empty($form_state['input']['mssql_host']) || !(preg_match('/^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$/', $form_state['input']['mssql_host']))) {
    form_set_error('mssql_host', 'You must enter an IP address for the server instance ex: 10.0.0.1');
  }
  // Validate the host port.
  if (empty($form_state['input']['mssql_port']) || !(preg_match('/^\d{1,5}$/', $form_state['input']['mssql_port']))) {
    form_set_error('mssql_port', 'You must enter a port for the server instance ex: 42000');
  }
  // Validate the host domain.
  if (empty($form_state['input']['mssql_domain'])) {
    form_set_error('mssql_domain', 'You must enter a domain for the server instance');
  }
  // Validate the host username.
  if (empty($form_state['input']['mssql_user'])) {
    form_set_error('mssql_user', 'You must enter a username for the server instance');
  }
  // Validate the host password.
//  if (empty($form_state['input']['mssql_password'])) {
//    form_set_error('mssql_password', 'You must enter a password for the server instance');
//  }
  // Validate the host password.
  if (empty($form_state['input']['mssql_schema'])) {
    form_set_error('mssql_schema', 'You must enter a schema for the server instance');
  }
}

/**
 * Handle the submission of the form and encrypt the data.
 */
function enterprise_data_admin_form_submit($form, &$form_state) {

  // Save the variable values.
  variable_set('mssql_host', $form_state['input']['mssql_host']);
  variable_set('mssql_port', $form_state['input']['mssql_port']);
  variable_set('mssql_domain', $form_state['input']['mssql_domain']);
  variable_set('mssql_user', $form_state['input']['mssql_user']);

  if($form_state['input']['mssql_password']) {
    variable_set('mssql_password', encrypt($form_state['input']['mssql_password']));
  }

  variable_set('mssql_schema', $form_state['input']['mssql_schema']);
}


