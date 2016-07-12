<?php

//Field mapping form page
/*
 * hook_form
 *
 * @param $module - the module that is calling this form, used to pull up the table schema
 * @param $dataType - the data type that will be marked in the staging table for this data when saved and loaded
 * @param $table - the staging table used to be mapping to and from
 * @param $toContentTypes - array of contentype the to fields will come from
 * @param $toTables - array of tables the to fields all also come from, key - module defining the table, value - table name
 *
 */

//Mapping UI
//////////////////

function digital_core_staging_field_mapping_form($form, $form_state, $module, $table, $toContentTypes, $toTables, $source, $options) {

  $stagingData = array('None' => 'None');
  $toFields = array('None' => 'None');

  $toContentFields = digital_core_staging_field_mapping_get_content_type_fields($toContentTypes);
  $stagingData = array_merge($stagingData, digital_core_staging_field_mapping_get_table_rows(array($module => $table)));
  $toTablesFields = digital_core_staging_field_mapping_get_table_rows($toTables, " (STATIC)");

  $moreToFields = array_merge($toContentFields, $toTablesFields);
  $toFields = array_merge($toFields, $moreToFields);

//  //attach the filed data to the form_state, need it in the submit
//  $form_state['build_info']['args']['toContentFields'] = $toContentFields;
//  $form_state['build_info']['args']['toTablesFields'] = $toTablesFields;

  $form = array();

  $form['mapping_table'] = array (
    '#type' => 'fieldset',
    '#theme' => 'digital_core_staging_field_mapping_table',
    '#tree' => TRUE,
  );

  //while($record = $mapping->fetchAssoc()) {
  foreach ($stagingData as $field => $description) {

    if($field == 'None') {
      continue;
    }

    $form['mapping_table']['mapping_from'][$field] = array(
      '#description' => t(""),
      '#markup' => $description
    );

    if($options['alt']) {
      $form['mapping_table']['mapping_to_alt'][$field] = array(
        '#type' => 'select',
        '#options' => $stagingData,
        '#description' => t(""),
        '#default_value' => digital_core_staging_field_mapping_get_mapped_field_from_alt($source, $table, $field),
        '#required' => TRUE,
        '#maxlength' => 500,
        '#size' => 1,
        '#multiple' => false,
      );
    }

    if($options['toType'] == 'select') {
      //loop through and add the defined columns to the form
      $form['mapping_table']['mapping_to'][$field] = array(
        '#type' => 'select',
        '#description' => t(""),
        '#default_value' => digital_core_staging_field_mapping_get_mapped_field_to($source, $table, $field),
        '#required' => TRUE,
        '#maxlength' => 500,
        '#size' => 1,
        '#options' => $toFields
      );
    }
    else {

      $form['mapping_table']['mapping_to'][$field] = array(
        '#type' => 'textfield',
        '#description' => t(""),
        '#default_value' => digital_core_staging_field_mapping_get_mapped_field_to($source, $table, $field),
        '#required' => FALSE,
        '#maxlength' => 5,
        '#size' => 5,
      );
    }

    if($options['primary_key']) {
      $form['mapping_table']['primary_key'][$field] = array(
        '#type' => 'checkbox',
        '#default_value' => digital_core_staging_field_mapping_field_primary_key($source, $table, $field),
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Mapping'),
  );
  return $form;
}

function digital_core_staging_field_mapping_form_submit($form, $form_state) {

  $dataType = $form_state['build_info']['args'][1];
  $source = $form_state['build_info']['args'][4];
  $options = $form_state['build_info']['args'][5];
  $toContentTypes = digital_core_staging_field_mapping_get_content_type_fields($form_state['build_info']['args'][2], true);
  $toTables = digital_core_staging_field_mapping_get_table_rows($form_state['build_info']['args'][3], true);

  //get any custom processing that was entered
  $customProcessing = db_select("digital_core_mapping")
                        ->fields("digital_core_mapping", array("customProcessing", "fromField", "toField"))
                        ->condition('dataType', $dataType)
                        ->condition('source', $source)
                        ->execute()->fetchAll();

  //kill any records for this data type
  db_delete('digital_core_mapping')
    ->condition('dataType', $dataType)
    ->condition('source', $source)
    ->execute();

  //save the mapping to the database
  foreach($form_state['values']['mapping_table']['mapping_to'] as $from => $to) {
    $destination = '';

    foreach($toContentTypes as $content_type => $fields) {
      if(array_key_exists($to, $fields)) {
        $destination = $content_type;
      }
    }

    foreach($toTables as $table => $fields) {
      if(array_key_exists($to, $fields)) {
        $destination = $table;
      }
    }

    $fields = array('source' => $source,
                     'dataType' => $dataType,
                     'fromField' => $from,
                     'toField' => $to,
                     'destination' => $destination);

    if($options['primary_key']) {
      $fields['primary_key'] = $form_state['values']['mapping_table']['primary_key'][$from];
    }

    if($options['alt']) {
      $fields['fromAlt'] = $form_state['values']['mapping_table']['mapping_to_alt'][$from];
    }

    //update the records
    db_insert('digital_core_mapping')
      ->fields($fields)
      ->execute();
  }

  //TODO expose this in the UI then this isnt needed and its easier to edit
  //put the procesisng commands back
  foreach($customProcessing as $cp) {
    if(isset($cp->customProcessing)) {
      db_update("digital_core_mapping")
        ->fields(array("customProcessing" => $cp->customProcessing))
        ->condition("fromField", $cp->fromField)
        ->condition("toField", $cp->toField)
        ->condition('dataType', $dataType)
        ->condition('source', $source)
        ->execute();
    }
  }

  drupal_set_message(t("Mapping Updated."));
}

function theme_digital_core_staging_field_mapping_table($variables) {

  $form = $variables['form'];

  $header = array(t('From Field'));

  if(isset($form['mapping_to_alt'])) {
    $header[] = t('Alt From Field');
  }

  $header[] = t('To Field');

  if(isset($form['primary_key'])) {
    $header[] = t('Primary Key');
  }

  $rows = array();

  foreach (element_children($form['mapping_from']) as $key) {

    $record = array();
    $record[] = drupal_render($form['mapping_from'][$key]);

    if(isset($form['mapping_to_alt'])) {
      $record[] = drupal_render($form['mapping_to_alt'][$key]);
    }

    $record[] = drupal_render($form['mapping_to'][$key]);

    if(isset($form['primary_key'])) {
      $record[] = drupal_render($form['primary_key'][$key]);
    }

    $rows[] = $record;
  }

  $output = theme('table', array(
      'header' => $header,
      'rows' => $rows
  ));

  return $output;
}

function digital_core_staging_field_mapping_get_table_rows($tables, $categorized = false, $subfix = false){
  $fields = array();

  foreach($tables as $module => $table) {
    $fieldData = array();

    //pull up the eiw staging table schema and use these fields as the definition for the list
    $schema = drupal_get_schema_unprocessed($module, $table);

    if(!empty($schema) && isset($schema['fields'])) {
      foreach($schema['fields'] as $field => $data) {
        if(array_key_exists("description", $data)) {
          $fieldData[$field] = $data['description'];

          if($subfix) {
            $fieldData[$field] . $subfix;
          }
        }
        else {
          $er = "hmmm";
        }
      }
    }

    //put the fields into arrays keyed by the table they come out of
    if($categorized) {
      $fields[$table] = $fieldData;
    }
    else {
      $fields = array_merge($fieldData, $fields);
    }
  }

  return $fields;
}

function digital_core_staging_field_mapping_get_content_type_fields($contentTypes, $categorized = false){
  $definedFields = array();

  foreach($contentTypes as $contentType) {
    $fieldData = array();

    $fields = field_info_instances("node", $contentType);

    if (empty($fields)) {
        return;
    }

    foreach ( $fields as $fieldName => $data ) {
      $fieldData[$fieldName] = $data['label'];
    }

    $fieldData["title"] = "Title";

     //put the fields into arrays keyed by the table they come out of
    if($categorized) {
      $definedFields[$contentType] = $fieldData;
    }
    else {
      $definedFields = array_merge($definedFields, $fieldData);
    }
  }

  return $definedFields;
}


/////////////////////////////


//Mapping functions
////////////////
function digital_core_staging_field_mapping_get_mapped_field_to($source, $dataType, $field) {
   return db_select('digital_core_mapping', 'm')
          ->fields('m', array('toField'))
          ->condition('fromField', $field)
          ->condition('dataType', $dataType)
          ->condition('source', $source)
          ->execute()
          ->fetchField();
}

function digital_core_staging_field_mapping_get_mapped_field_from($source, $dataType, $toField) {
   return db_select('digital_core_mapping', 'm')
          ->fields('m', array('fromField'))
          ->condition('toField', $toField)
          ->condition('dataType', $dataType)
          ->condition('source', $source)
          ->execute()
          ->fetchField();
}

function digital_core_staging_field_mapping_get_mapped_field_from_alt($source, $dataType, $field) {
   $value = db_select('digital_core_mapping', 'm')
          ->fields('m', array('fromAlt'))
          ->condition('fromField', $field)
          ->condition('dataType', $dataType)
          ->condition('source', $source)
          ->execute()
          ->fetchField();

   if(!$value || empty($value)) {
     return 'None';
   }

   return $value;
}

function digital_core_staging_field_mapping_field_primary_key($source, $dataType, $field) {
   $value = db_select('digital_core_mapping', 'm')
          ->fields('m', array('primary_key'))
          ->condition('fromField', $field)
          ->condition('dataType', $dataType)
          ->condition('source', $source)
          ->execute()
          ->fetchField();

   if(!$value || empty($value)) {
     return 'false';
   }

   return $value;
}

///////////////////