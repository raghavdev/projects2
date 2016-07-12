<?php //
/*
 * Map static table fields to place holder field groups
 */

//going to require some thought
//the static data has to map to field groups the same way as if it was data coming from drupal
//the data is agregated in the data feed, so it wont make a difference where it comes from


//place the fields into the list as children, with the name of the field as it will come out
//of the service there proper

function bluemarble_staging_field_group_mapping_form($form, $form_state, $module, $fromTable, $toContentType) {

  $toFields = array('None' => 'None');

  //get the list of field_group fields from the content type
  $toFieldsData = field_group_info_groups('node', $toContentType);

  if(!array_key_exists('form', $toFieldsData)) {
    return;
  }

  foreach($toFieldsData['form'] as $name => $data) {
    $toFields[$name] = $name;
  }

  //get list of fields from the static table
  $fields = bluemarble_staging_field_mapping_get_table_rows(array($module => $fromTable));

  $form = array();

  $form['mapping_table'] = array (
    '#type' => 'fieldset',
    '#theme' => 'bluemarble_staging_field_group_mapping_table',
    '#tree' => TRUE,
  );

  //while($record = $mapping->fetchAssoc()) {
  foreach ($fields as $field => $description) {

    if($field == 'None') {
      continue;
    }

    $form['mapping_table']['mapping_from'][$field] = array(
      '#description' => t(""),
      '#markup' => $description
    );

    //loop through and add the defined columns to the form
    $form['mapping_table']['mapping_to'][$field] = array(
      '#type' => 'select',
      '#description' => t(""),
      '#default_value' => bluemarble_staging_field_group_mapping_get_mapped_field_to($toContentType, $field),
      '#required' => TRUE,
      '#maxlength' => 500,
      '#size' => 1,
      '#options' => $toFields
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Mapping'),
  );
  return $form;
}

function bluemarble_staging_field_group_mapping_form_submit($form, $form_state) {

  $dataType = $form_state['build_info']['args'][2];

  //kill any records for this data type
  db_delete('bluemarble_field_group_mapping')
    ->condition('dataType', $dataType)
    ->execute();

  //save the mapping to the database
  foreach($form_state['values']['mapping_table']['mapping_to'] as $from => $to) {

    $fields = array('dataType' => $dataType,
                     'fromField' => $from,
                     'toField' => $to,
                    );

    //update the records
    db_insert('bluemarble_field_group_mapping')
      ->fields($fields)
      ->execute();
  }

  drupal_set_message(t("Mapping Updated."));
}

function theme_bluemarble_staging_field_group_mapping_table($variables) {

  $form = $variables['form'];

  $header = array(t('From Field'));

  $header[] = t('To Group');

  $rows = array();

  foreach (element_children($form['mapping_from']) as $key) {

    $record = array();
    $record[] = drupal_render($form['mapping_from'][$key]);
    $record[] = drupal_render($form['mapping_to'][$key]);

    $rows[] = $record;
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows
  ));

  return $output;
}

function bluemarble_staging_field_group_mapping_get_mapped_field_to($toContentType, $field) {

  return db_select('bluemarble_field_group_mapping', 'm')
          ->fields('m', array('toField'))
          ->condition('fromField', $field)
          ->condition('dataType', $toContentType)
          ->execute()
          ->fetchField();
}