<?php

function enterprise_data_rcm_hierarchy_page_form($form, &$form_state) {

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'enterprise_data_rcm') . '/rcmHierarchy.js'
  );

  $form['add_dept'] = array(
    '#type' => 'button',
    '#value' => 'Add Department',
  );

  $form['show_disabled']['submit'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show Disabled',
    '#attributes' => array("id" => 'show_disabled')
  );

  $form['add-dialog'] = array(
      "#markup" => '<div id="add-dialog" title="Create a New Department"><div id="add-dialog-content"></div></div>'
  );

  $form['edit-dialog'] = array(
      "#markup" => '<div id="edit-dialog" title="Edit"><div id="edit-dialog-content"></div></div>'
  );

  //generate the base category department data
  $form['base'] = enterprise_data_rcm_hierarchy_generate_level(false, 0, false);

  return $form;
}

function enterprise_data_rcm_hierarchy_add($data) {

}

function enterprise_data_rcm_hierarchy_generate_level($parentid, $level, $render = true) {

  //get the base heirarchy data top level stuff
  $data = enterprise_data_rcm_hierarchy_get_data($parentid);

  if(count($data) == 0) {
    return;
  }

  $levelType = "Departments";
  switch($level) {
    case 1: {
      $levelType = 'Categories';
      break;
    }
    case 2: {
      $levelType = "Segments";
      break;
    }
    case 3: {
      $levelType = "Subsegments";
      break;
    }
  }

  $levelClass = strtolower($levelType);

  $form_data = array(
    '#type'  => 'fieldset',
    '#title' => t($levelType),
    '#attributes' => array("class" => array('rcm-hierarchy-nodes'))
  );

  $form_data['data'] = array();

  $level++;

  foreach($data as $id => $record) {

    $element = array(
        '#type' => 'link',
        '#href' => 'admin/enterprisedata/rcm/hierarchy/data/' . $id . '/' . $level,
        '#title' => $record->title,
        '#ajax' => array(
          'callback' => 'enterprise_data_rcm_hierarchy_generate_level',
          'wrapper' => 'hierarchy-container-' . $id,
          'method' => 'replace',
          'effect' => 'fade',
        ),
        '#attributes' => array("id" => 'hierarchy-link-' . $id, "class" => 'rcm-hierarchy-node collapsed ' . $levelClass . ' ' . ($record->field_active_value == 0 ? "disabled-node hidden" : "")),
        '#suffix' => "<a class='edit' href='/admin/enterprisedata/rcm/hierarchy/edit/{$id}'>Edit</a><div id='hierarchy_container_{$id}'></div></li>",
        '#prefix' => "<li class='$levelClass collapsed'>"
      );
    $form_data['data'][] = $element;
  }

  if(!$render) {
    return $form_data;
  }

  $html = drupal_render($form_data);

  $commands[] = ajax_command_append("#hierarchy_container_{$parentid}", $html);

  print ajax_render($commands);
  drupal_exit();
}

function enterprise_data_rcm_hierarchy_get_data($parent) {

  $q = db_select("node");
  $q->fields("node", array("title", "nid"));
  $q->condition("node.type", "rcm_hierarchy");
  $q->distinct();
  if(!$parent) {
    $q->addJoin("left", "field_data_field_parent", "p", "p.entity_id = node.nid");
    $q->isNull("p.field_parent_target_id");
    $q->fields("p", array("field_parent_target_id"));
  }
  else {
    $q->addJoin("inner", "field_data_field_parent", "p", "p.entity_id = node.nid");
    $q->condition("p.field_parent_target_id", $parent);
  }

  $q->addJoin("left", "field_data_field_active", "a", "a.entity_id = node.nid");
  $q->fields('a', array('field_active_value'));
  $q->orderBy("title");

  $data = $q->execute()->fetchAllAssoc('nid');

  return $data;
}

function enterprise_data_rcm_hierarchy_edit_page_form($form, &$form_state) {

  $form = array();
  $form['#attributes']['class'][] = 'rcm-edit-form';

  //get the node we are editing
  $node = node_load($form_state['build_info']['args'][0]);

  //breadcrumb?

  //revisions button
  $form['revisions'] = array(
    '#type' => 'button',
    '#value' => 'Revisions',
  );

  //Name
  $form['title'] = array(
   '#type' => 'textfield',
   '#title' => 'Name',
   '#size' => 54,
   '#default_value' => $node->title,
  );

  $parents = array("" => "None");

  $parents = array_replace($parents, db_select("node")
              ->fields("node", array("nid", "title"))
              ->condition("type", "rcm_hierarchy")
              ->execute()
              ->fetchAllKeyed());

  //Parent
  $form['parent'] = array(
   '#type' => 'select',
   '#title' => 'Parent',
   '#options' => $parents,
   '#default_value' => (array_key_exists("und", $node->field_parent) ? $node->field_parent['und'][0]['target_id'] : "")
  );

  //Profile
  $form['profile'] = array(
   '#type' => 'select',
   '#title' => 'Profile',
   '#options' => array(),
   //'#default_value' => $node->title,
  );

  //subsegments

  //add new subsegment??? what are these???
  $form['add_subsection'] = array(
    '#type' => 'button',
    '#value' => 'Add New Subsection',
  );

  $form['activebtn'] = array(
    '#type' => 'button',
    '#value' => (array_key_exists("und", $node->field_active) ? ($node->field_active['und'][0]['value'] == 1 ? "Disable" : "Enable") : "Enable"),
  );

  //add the disable dialog only if its disabled
  if($node->field_active['und'][0]['value'] == 1) {
    $form['deactivate_dialog'] = array(
      "#prefix" => '<div id="deactivation-dialog" title="Confirm Disable"><p>All items must be removed from a category before it can be disabled.</p>',
      "#suffix" => "</div>",
      "#type" => "fieldset"
    );

    //get a department list

    $depts = db_select("node")
                ->fields("node", array("nid", "title"))
                ->condition("type", "rcm_hierarchy")
                ->condition("nid", $node->nid, "!=")
                ->execute()
                ->fetchAllKeyed();

    $form['deactivate_dialog']['move'] = array(
      "#type" => "select",
      '#options' => $depts,
      "#title" => "Move all items to:",
    );

    $form['deactivate_dialog']['disable_category'] = array(
      "#type" => "button",
      "#value" => "Disable Category",
      "#attributes" => array("id" => "dialog-disable")
    );

    $form['deactivate_dialog']['cancel'] = array(
      "#type" => "button",
      "#value" => "Cancel",
      "#attributes" => array("id" => "dialog-cancel")
    );
  }

  //save
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  $form['assigned_items'] = array(
    "#type" => "fieldset",
    "#title" => "Assigned Items",
    "#attributes" => array(
       "class" => array('assigned'),
    )
  );

  $form['assigned_items']['move_selected'] = array(
    '#type' => 'button',
    '#value' => 'Move Selected',
  );

  $form['assigned_items']['add_item'] = array(
    '#type' => 'textfield',
    '#title' => 'Add Item',
    '#size' => 30,
    '#autocomplete_path' => 'admin/enterprisedata/rcm/hierarchy/item/autocomplete'
  );

  $form['assigned_items']['add_item_btn'] = array(
    '#type' => 'submit',
    '#value' => 'Add Item',
  );

  $form['assigned_items']['item-nid'] = array(
    '#type' => 'hidden',
    '#attributes' => array("id" => 'item-nid')
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'enterprise_data_rcm') . '/rcmHierarchyEdit.js'
  );

  $form['hierarchy-nid'] = array(
    '#type' => 'hidden',
    '#value' => $form_state['build_info']['args'][0],
    '#attributes' => array("id" => 'hierarchy-nid')
  );

  //stick the view and its exposed filter into the form
  $view = views_get_view("rcm_item_assignment");
  $view->set_display("RCM Items Assignment");
  $view->pre_execute();

  //is there a better way to do this??
  //set the exposed filter values
  if(array_key_exists('field_enterprise_brand_target_id', $_POST)) {
    $view->filter['field_enterprise_brand_target_id']->value = $_POST['field_enterprise_brand_target_id'];
  }

  if(array_key_exists('combine', $_POST)) {
    $view->filter['combine']->value = $_POST['combine'];
  }

  $view->execute();

  $form['assigned_items']['data']['#markup'] = $view->render();

  return $form;
}

function enterprise_data_rcm_hierarchy_edit_page_form_submit($form, $form_state) {
  switch($form_state['values']['op']) {
    case "Add Item": {
      //add the item to the hierarchy
      if($form_state['values']['item-nid']) {
        $node = node_load($form_state['values']['item-nid']);
        $node->field_rcm_hierarchy['und'][] = array("target_id" => $form_state['values']['hierarchy-nid']);
        node_save($node);

        drupal_set_message("Item added to Hierarchy");
      }
      break;
    }

    case "Save": {
      $node = node_load($form_state['values']['hierarchy-nid']);

      if($node) {
        $node->title = $form_state['values']['title'];

        if($form_state['values']['parent'] != "") {
          $node->field_parent['und'][0] = array('target_id' => $form_state['values']['parent']);
        }

        //TODO Profile??
        //TODO subsegments??

        $node->field_active['und'][0] = array('value' => (array_key_exists("active", $form_state['values']) ? $form_state['values']['active'] : $_POST['active']));

        node_save($node);

        drupal_set_message("Hierarchy Saved");
      }
      break;
    }
  }
}