<?php

function drangular_admin_page() {
  return drupal_get_form("drangular_admin_form");
}

function drangular_admin_form($form, $form_state) {

  $form = array();

  $form['apps_table'] = array (
    '#type' => 'fieldset',
    '#title' => 'Detected Apps',
    '#theme' => 'drangular_admin_table',
    '#tree' => TRUE,
    '#collapsible' => TRUE
  );

  $form['app_paths_table'] = array (
    '#type' => 'fieldset',
    '#title' => 'Defined Paths',
    '#theme' => 'drangular_admin_paths_table',
    '#tree' => TRUE,
    '#collapsible' => TRUE
  );

  $detected_apps = drangular_get_drangular_apps();

  $apps = drangular_get_apps("*");

  foreach($detected_apps as $app_name => $app_path) {

    $app_status = false;

    if(array_key_exists($app_name, $apps)) {
      $app_status = ($apps[$app_name]->active == 0 ? false : true);
    }

    $form['apps_table']['app_name'][$app_name] = array(
      '#markup' => $app_name
    );

    $form['apps_table']['app_status'][$app_name] = array(
      '#markup' => ($app_status ? "Enabled" : "Disabled")
    );

    $form['apps_table']['actions'][$app_name]['edit'] = array(
      '#markup' => l("App Settings", "admin/config/development/drangular/edit/{$app_name}") . "<br>"
    );

    $form['apps_table']['actions'][$app_name]['active_toggle'] = array(
      '#markup' => l(($app_status ? "Disable App" : "Enable App"), "admin/config/development/drangular/active_toggle/{$app_name}/" . ($app_status ? "0" : "1"),
              array("query" => array("token" => drupal_get_token("admin/config/development/drangular/active_toggle/{$app_name}/" . ($app_status ? "0" : "1"))))) . "<br>"
    );

    $form['apps_table']['actions'][$app_name]['edit-cache'] = array(
      '#markup' => l("View / Edit File List", "admin/config/development/drangular/edit-cache/{$app_name}") . "<br>"
    );

    $form['apps_table']['actions'][$app_name]['clear'] = array(
      '#markup' => l("Clear File List", "admin/config/development/drangular/clear/{$app_name}",
              array("query" => array("token" => drupal_get_token("admin/config/development/drangular/clear/{$app_name}")))) . "<br>"
    );

    $form['apps_table']['actions'][$app_name]['edit_paths'] = array(
      '#markup' => l("Add Path", "admin/config/development/drangular/edit/{$app_name}/paths/add")
    );

    if($app_status) {

      foreach($apps[$app_name]->paths as $path) {

        $form['app_paths_table']['app_name'][$app_name] = array(
          '#markup' => $app_name
        );

        $form['app_paths_table']['app_path'][$app_name] = array(
          '#markup' => $path->path
        );

        $form['app_paths_table']['callback_created'][$app_name] = array(
          '#markup' => ($path->create_link == 0 ? "False" : "True")
        );

        $form['app_paths_table']['menu_title'][$app_name] = array(
          '#markup' => $path->title
        );

        $form['app_paths_table']['menu_description'][$app_name] = array(
          '#markup' => $path->description
        );

        $form['app_paths_table']['template'][$app_name] = array(
          '#markup' => $path->template
        );

        $actions = l('Edit Path', "admin/config/development/drangular/edit/{$app_name}/paths/edit/{$path->path_id}");
        $actions .= "<br>" . l('Delete Path', "admin/config/development/drangular/edit/{$app_name}/paths/delete/{$path->path_id}",
                array("query" => array("token" => drupal_get_token("admin/config/development/drangular/edit/{$app_name}/paths/delete/{$path->path_id}"))));

        $form['app_paths_table']['actions'][$app_name] = array(
          '#markup' => $actions
        );

      }
    }
  }

  return $form;
}

function drangular_admin_form_submit($form, $form_state) {

}

function theme_drangular_admin_table($variables) {

  $form = $variables['form'];

  $header = array(t('App Name'), t('App Status'), t('Actions'));

  $rows = array();

  foreach (element_children($form['app_name']) as $key) {

    $record = array();
    $record[] = drupal_render($form['app_name'][$key]);
    $record[] = drupal_render($form['app_status'][$key]);
    $record[] = drupal_render($form['actions'][$key]);
    $rows[] = $record;
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows
  ));

  return $output;
}

function theme_drangular_admin_paths_table($variables) {

  $form = $variables['form'];

  $header = array(t('App Name'), t('Path'), t('Callback Created'), t('Menu Title'),
      t('Menu Description'), t('Template'), t('Actions'));

  $rows = array();

  if(count(element_children($form['app_name'])) > 0) {
    foreach (element_children($form['app_name']) as $key) {

      $record = array();
      $record[] = drupal_render($form['app_name'][$key]);
      $record[] = drupal_render($form['app_path'][$key]);
      $record[] = drupal_render($form['callback_created'][$key]);
      $record[] = drupal_render($form['menu_title'][$key]);
      $record[] = drupal_render($form['menu_description'][$key]);
      $record[] = drupal_render($form['template'][$key]);
      $record[] = drupal_render($form['actions'][$key]);

      $rows[] = $record;
    }
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows
  ));

  return $output;
}

function theme_drangular_cache_table($variables) {
  $form = $variables['form'];

  drupal_add_tabledrag($form['#table-id'], 'order', 'sibling', 'rank-weight');

  $header = array(t('Script'), t('Remove'), t('Weight'));

  $rows = array();

  if(count(element_children($form['rows'])) > 0) {
    foreach (element_children($form['rows']) as $key) {

      $record = array();
      $record['data'][] = drupal_render($form['rows'][$key]['name']);
      $record['data'][] = drupal_render($form['rows'][$key]['remove']);
      $record['data'][] = drupal_render($form['rows'][$key]['weight']);
      $record['id'] = $form['#table-id'] . "_row_{$key}";
      $record['class'] = array('draggable');
      $rows[] = $record;
    }
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array('id' => $form['#table-id'])
  ));

  return $output;
}

function drangular_add_page() {
  return drupal_get_form("drangular_admin_edit_form");
}

function drangular_edit_page($app_name) {
  return drupal_get_form("drangular_admin_edit_form", $app_name);
}

function drangular_admin_edit_form($form, $form_state, $app_name = null) {

  if($app_name != null) {
    $app = drangular_get_apps("*", $app_name);
    $app = array_shift($app);
  }

  //App name
  $form['app_name'] = array(
    '#title' => t('App Name'),
    '#type' => 'textfield',
    '#description' => t("Name of the angular app as its defined in the app."),
    '#default_value' => (isset($app->app_name) ? $app->app_name : ""),
    '#required' => true,
    '#size' => 50,
  );

  //script folder
  $form['scripts_folder'] = array(
    '#title' => t('Script Folder'),
    '#type' => 'textfield',
    '#description' => t("The folder inside the app folder that contains the script files."),
    '#default_value' => (isset($app->scripts_folder) ? $app->scripts_folder : ""),
    '#required' => true,
    '#size' => 50,
  );

  //styles folder
  $form['styles_folder'] = array(
    '#title' => t('Styles Folder'),
    '#type' => 'textfield',
    '#description' => t("Optional folder inside the app folder that contains the style files."),
    '#default_value' => (isset($app->styles_folder) ? $app->styles_folder : ""),
    '#required' => false,
    '#size' => 50,
  );

  $form['script_load_scope'] = array(
    '#type' => 'select',
    "#title" => "Script Include Location",
    '#options' => array("header" => "Header", "footer" => "Footer"),
    '#description' => t("Location to include the scripts at"),
    '#default_value' => (isset($app->script_load_scope) ? $app->script_load_scope : "header"),
    '#required' => TRUE,
  );

 $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 99,
  );

  return $form;
}

function drangular_admin_edit_form_submit($form, $form_state) {


  $app_name = isset($form_state['build_info']['args'][0]) ? $form_state['build_info']['args'][0] : false;

  if($app_name) {
    db_update("drangular_apps")
      ->condition("app_name", $app_name)
      ->fields(array("app_name" => $form_state['values']['app_name'],
          "scripts_folder" => $form_state['values']['scripts_folder'],
          "script_load_scope" => $form_state['values']['script_load_scope'],
          "styles_folder" => $form_state['values']['styles_folder']))
      ->execute();

    drupal_set_message(t("App Updated"));
  }
  else {
    db_insert("drangular_apps")
      ->fields(array("app_name" => $form_state['values']['app_name'],
          "scripts_folder" => $form_state['values']['scripts_folder'],
          "styles_cache" => "",
          "scripts_cache" => "",
          "script_load_scope" => $form_state['values']['script_load_scope'],
          "styles_folder" => $form_state['values']['styles_folder']))
      ->execute();

    //add the default path
    db_insert("drangular_apps_paths")
      ->fields(array("path" => "*",
          "title" => "",
          "description" => "",
          "template" => "default",
          "create_link" => "0",
          "app_name" => $form_state['values']['app_name']))
      ->execute();
  }

  drupal_goto("admin/config/development/drangular");
}

function drangular_edit_paths_add($app_name) {
  return drupal_get_form("drangular_edit_path_form", $app_name);
}

function drangular_edit_path($app_name, $path) {
  return drupal_get_form("drangular_edit_path_form", $app_name, $path);
}

function drangular_edit_path_form($form, $form_state, $app_name, $path_id = null) {

  $path_data = array();

  if($path_id != null) {
    $query = db_select("drangular_apps_paths", "dp")
      ->fields("dp");
    $query->condition("app_name", $app_name);
    $query->condition("path_id", $path_id);
    $path_data = $query->execute()->fetchAssoc();
  }

  $form = array();

  $form['path'] = array(
    '#title' => t('Path'),
    '#type' => 'textfield',
    '#description' => t("Path the app will be loaded on."),
    '#default_value' => (array_key_exists("path", $path_data) ? $path_data['path'] : ""),
    '#required' => true,
    '#size' => 50,
  );

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#description' => t("If using a template, this is the menu title of the page."),
    '#default_value' => (array_key_exists("title", $path_data) ? $path_data['title'] : ""),
    '#required' => FALSE,
    '#size' => 50,
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#description' => t("If using a template, the is the description of the page."),
    '#default_value' => (array_key_exists("description", $path_data) ? $path_data['description'] : ""),
    '#required' => FALSE,
    '#size' => 50,
  );

  $form['template'] = array(
    '#title' => t('Template'),
    '#type' => 'textfield',
    '#description' => t("Template file name used. If you are not using a custom one 'default' is required."),
    '#default_value' => (array_key_exists("template", $path_data) ? $path_data['template'] : "default"),
    '#required' => true,
    '#size' => 50,
  );

  //permissions that the path uses
  $form['permissions'] = array(
    '#title' => t('Permissions'),
    '#type' => 'textfield',
    '#description' => t("Permissions this path uses."),
    '#default_value' => (array_key_exists("permissions", $path_data) ? $path_data['permissions'] : "access content"),
    '#required' => true,
    '#size' => 50,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 99,
  );

 return $form;
}

function drangular_edit_path_form_submit($form, $form_state) {
  $app_name = $form_state['build_info']['args'][0];
  $path_id = (isset($form_state['build_info']['args'][1]) ? $form_state['build_info']['args'][1] : false);

  if($path_id) {
    db_update("drangular_apps_paths")
      ->condition("path_id", $path_id)
      ->fields(array("path" => $form_state['values']['path'],
          "title" => $form_state['values']['title'],
          "description" => $form_state['values']['description'],
          "template" => $form_state['values']['template'],
          "permissions" => $form_state['values']['permissions']))
      ->execute();

    drupal_set_message(t("Path Updated"));
  }
  else {
    $valid = drupal_valid_path($form_state['values']['path']);

    db_insert("drangular_apps_paths")
      ->fields(array("path" => $form_state['values']['path'],
          "app_name" => $app_name,
          "title" => $form_state['values']['title'],
          "description" => $form_state['values']['description'],
          "create_link" => (int)!$valid,
          "template" => $form_state['values']['template'],
          "permissions" => $form_state['values']['permissions']))
      ->execute();

    drupal_set_message(t("Path Added"));
  }

  //force a cache clear to enable the menu link
  cache_clear_all();
  menu_rebuild();

  drupal_goto("admin/config/development/drangular");
}

function drangular_delete_path($app_name, $path_id) {

  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], "admin/config/development/drangular/edit/{$app_name}/paths/delete/{$path_id}")) {
    return MENU_ACCESS_DENIED;
  }

  db_delete("drangular_apps_paths")
    ->condition("path_id", $path_id)
    ->execute();

  drupal_set_message(t("Path Deleted"));
  drupal_goto("admin/config/development/drangular");
}

function drangular_edit_cache_page($app_name) {
  return drupal_get_form("drangular_edit_cache_page_form", $app_name);
}

function drangular_edit_cache_page_form($form, $form_state, $app_name) {

  $form = array();

  drupal_add_js(drupal_get_path("module", 'drangular') . '/admin.js');

  $app = drangular_get_apps("*", $app_name);

  $app = array_shift($app);

  $form['app_name'] = array(
    '#type' => 'hidden',
    '#value' => $app_name
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('< Back'),
  );

  $form['save_changes'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
  );

  $form['rebuild_script_cache'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild Script Cache'),
  );

  $form['rebuild_style_cache'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild Style Cache'),
  );

  //table of current cache
  $form['script_table'] = array (
    '#title' => 'Scripts Loaded',
    '#type' => 'fieldset',
    '#theme' => 'drangular_cache_table',
    '#tree' => TRUE,
    '#table-id' => 'script_table',
    '#collapsible' => TRUE
  );

  $scripts = array();
  $styles = array();

  if($app->scripts_cache != "") {
    $scripts = unserialize($app->scripts_cache);
  }

  if($app->styles_cache != "") {
    $styles = unserialize($app->styles_cache);
  }

  if(count($scripts) > 0) {
    foreach($scripts as $idx => $script) {
      $form['script_table']['rows'][$idx]['name'] = array(
        '#markup' => check_plain($script),
      );

      $form['script_table']['rows'][$idx]['value'] = array(
        '#type' => "hidden",
        '#value' => $script
      );

      $form['script_table']['rows'][$idx]['weight'] = array(
        '#type' => 'textfield',
        '#default_value' => $idx,
        '#size' => 3,
        '#attributes' => array('class' => array('rank-weight')),
      );
      $form['script_table']['rows'][$idx]['remove'] = array(
        '#type' => 'button',
        '#attributes' => array('onclick' => "removeRow('script', '{$idx}'); return (false);"),
        '#value' => 'Remove',
        '#size' => 3,
      );
    }
  }

  $form['add_script_fieldset'] = array (
    '#title' => 'Add script to cache',
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  //add file to cache
  $form['add_script_fieldset']['script_file'] = array(
    '#title' => t('Script File Path'),
    '#type' => 'textfield',
    '#description' => t("Full path to the file to include relative to the app folder"),
    '#default_value' => "",
    '#required' => false,
    '#size' => 50,
  );

  $form['add_script_fieldset']['add_script'] = array(
    '#type' => 'submit',
    '#value' => t('Add Script'),
    '#weight' => 99,
  );

  $form['spacer'] = array(
    '#markup' => "<br><hr><br>"
  );

  $form['style_table'] = array (
    '#title' => 'Styles Loaded',
    '#type' => 'fieldset',
    '#theme' => 'drangular_cache_table',
    '#tree' => TRUE,
    '#table-id' => 'style_table',
    '#collapsible' => TRUE
  );

  if(count($styles) > 0) {
    foreach($styles as $idx => $style) {
      $form['style_table']['rows'][$idx]['name'] = array(
        '#markup' => check_plain($style),
      );

      $form['style_table']['rows'][$idx]['value'] = array(
        '#type' => "hidden",
        '#value' => $style
      );

      $form['style_table']['rows'][$idx]['weight'] = array(
        '#type' => 'textfield',
        '#default_value' => $idx,
        '#size' => 3,
        '#attributes' => array('class' => array('rank-weight')),
      );
      $form['style_table']['rows'][$idx]['remove'] = array(
        '#type' => 'button',
        '#attributes' => array('onclick' => "removeRow('style', '{$idx}')"),
        '#value' => 'Remove',
        '#size' => 3,
      );
    }
  }

  //add file to cache
  $form['add_style_fieldset'] = array (
    '#title' => 'Add style to cache',
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  //add file to cache
  $form['add_style_fieldset']['style_file'] = array(
    '#title' => t('Style File Path'),
    '#type' => 'textfield',
    '#description' => t("Full path to the file to include relative to the app folder"),
    '#default_value' => "",
    '#required' => false,
    '#size' => 50,
  );

  $form['add_style_fieldset']['add_style'] = array(
    '#type' => 'submit',
    '#value' => t('Add Style'),
    '#weight' => 99,
  );

  return $form;
}

function drangular_edit_cache_page_form_submit($form, $form_state) {
  switch($form_state['values']['op']) {
    case "< Back": {
      drupal_goto("/admin/config/development/drangular");
      break;
    }
    case "Save Changes": {
      $scripts = array();
      if(array_key_exists("script_table", $form_state['values'])) {
        foreach($form_state['values']['script_table']['rows'] as $row) {
          //-1 will signify delete
          if($row['weight'] != -1) {
            $scripts[$row['weight']] = $row['value'];
          }
        }
      }

      $styles = array();
      if(array_key_exists("style_table", $form_state['values'])) {
        foreach($form_state['values']['style_table']['rows'] as $row) {
          $styles[$row['weight']] = $row['value'];
        }
      }

      ksort($scripts);
      ksort($styles);

      db_update("drangular_apps")
        ->fields(array("styles_cache" => serialize($styles),
                      "scripts_cache" => serialize($scripts)))
        ->condition("app_name", $form_state['values']['app_name'])
        ->execute();


      drupal_set_message(t("Changes saved."));
      break;
    }
    case "Rebuild Script File List": {
      drangular_clear_cache($form_state['values']['app_name'], 'scripts');
      break;
    }
    case "Rebuild Style File List": {
      drangular_clear_cache($form_state['values']['app_name'], 'styles');
      break;
    }
     case "Add Script": {
      drangular_add_to_cache($form_state['values']['app_name'], "scripts", $form_state['values']['add_script_fieldset']['script_file']);
      drupal_set_message(t("Script added to cache"));
      break;
    }
    case "Add Style": {
      drangular_add_to_cache($form_state['values']['app_name'], "styles", $form_state['values']['add_style_fieldset']['style_file']);
      drupal_set_message(t("Style added to cache"));
      break;
    }
  }
}
//
//function drangular_add_cache($app_name, $type, $value) {
//
//  //load the cache
//  $cache = db_select("drangular_apps")
//                    ->condition("app_name", $app_name)
//                    ->fields("drangular_apps", array("{$type}_cache"))
//                    ->execute()
//                    ->fetchField();
//
//  $scripts = unserialize($cache);
//
//  //add the value
//  $scripts[] = $value;
//
//  $cache = serialize($scripts);
//
//  //save the cache
//  db_update("drangular_apps")
//    ->condition("app_name", $app_name)
//    ->fields(array("{$type}_cache" => $cache))
//    ->execute();
//}