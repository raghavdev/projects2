<?php

//Upload form
///////////////////////

function bluemarble_staging_csv_upload_form($form, $form_state, $dataType) {

  //Define the page for uploading the csv file
  $form = array();
  $form['csv_file'] = array(
    '#type' => 'file',
    '#title' => t('Delimited Data file'),
    '#description' => t("Delimited data file for upload"),
  );
  $form['delimiter'] = array(
    '#type' => 'select',
    '#title' => t('Delimiter'),
    '#options' => array(
      "," => "comma",
      "\t" => "tab",
      "|" => "|",
    ),
    '#description' => t("Delimiter of the data file."),
    '#default_value' => ',',
    '#required' => false,
  );

  $form['contains_header'] = array(
    '#type' => 'checkbox',
    '#title' => t('File contains a header'),
    '#description' => t("Skip the first line because it is a header."),
    '#default_value' => TRUE,
  );

  $form['#attributes']['enctype'] = "multipart/form-data";

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Upload Data'),
  );
  return $form;
}

function bluemarble_staging_csv_upload_form_validate($form, &$form_state) {

  $file = file_save_upload('csv_file', array(
      'file_validate_extensions' => array('csv txt'),
  ));
  if ($file) {
    $dir = 'public://bluemarble_staging_csv_uploads/';
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    if ($file = file_move($file, $dir . $file->filename)) {
      $form_state['values']['csv_file'] = $file;
    }
    else {
      form_set_error('csv_file', t('Failed to write the uploaded file the site\'s tmp folder.'));
    }
  }
  else {
    form_set_error('csv_file', t('No file was uploaded.'));
  }
}

function bluemarble_staging_csv_upload_form_submit($form, &$form_state) {

  $dataType = $form_state['build_info']['args'][0];

  $file = $form_state['values']['csv_file'];

  if(!empty($file->uri)) {
    if(file_exists($file->uri)) {
      bluemarble_staging_csv_process_file($dataType, $form_state['values']['contains_header'],
              $form_state['values']['delimiter'], $file->uri);
    }
  }
}

//read the csv file into the database
function bluemarble_staging_csv_process_file($dataType, $useHeader, $delimiter, $filePath) {

  module_load_include('inc', 'bluemarble_staging', 'bluemarble_staging_field_mapping');

  //read records from the csv file
  $handle = fopen($filePath, "r");

  // start count of imports for this upload
  $send_counter = 0;

  $rowIdx = 0;

  bluemarble_staging_prep_table($dataType);

  $header = array();
  while (($data = fgetcsv($handle, 0, $delimiter, '"')) !== FALSE) {

    //skip the header line
    if($useHeader && $rowIdx == 0) {
      $rowIdx++;
      $header = $data;
      continue;
    }

    $record = array();

    //map the fields from the csv column to field
    foreach($data as $column => $value) {
      if (isset($header[$column])) {
        // Escape the field to remove special characters. The CSV also may have
        // percent characters for percentage fields, and we need to distinguish
        // them from other fields, so need to name them _percent in our staging
        // table.
        $col_name = db_escape_field(str_replace('%', '_percent', $header[$column]));
        // If the CSV contains a column name that does not exist we do not want
        // to insert a value
        if (db_field_exists($dataType, $col_name)) {
          $record[$col_name] = utf8_encode($value);
        }
      }
    }

    bluemarble_staging_write_record($dataType, $record);

    $rowIdx++;
  }

  drupal_set_message(t("CSV Uploaded"));
}
