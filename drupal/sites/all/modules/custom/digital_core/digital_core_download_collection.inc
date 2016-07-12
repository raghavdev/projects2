<?php

function digital_core_download_collection($collection_id) {

  if(!$collection_id) {
    return;
  }

  $collection = node_load($collection_id);

  $file_info = false;
  if($collection->type == "collection") {
    $file_info = digital_core_download_collection_product($collection);
  }
  else {
    $file_info = digital_core_download_collection_asset($collection);
  }

  //initiate the download
  if($file_info) {
     // Most of this is only necessary because of IE
    header("Cache-Control: public");
    header("Content-Type: application/octet-stream");
    header("Cache-Control: no-store, no-cache, must-revalidate");
    header("Cache-Control: post-check=0, pre-check=0");
    header("Content-Disposition: attachment; filename=\"{$file_info['filename']}\";" );
    header("Content-Transfer-Encoding: binary");

    $fp = fopen($file_info['full_path'], 'rb');
    fpassthru($fp);
    exit();
  }

  return false;
}

function digital_core_download_collection_product($collection) {

  $file_info = array("full_path" => "temporary://{$collection->title}.csv", "filename" => $collection->title . ".csv");

  module_load_include('inc', 'digital_core_data', 'digital_core_data_products');

  $job_id = false;

  //generate the rows and header
  //write the header
  $header = array("East Product Number","Product Name","Brand","UPC","Last Updated");

  $image_types = digital_core_download_collections_get_image_type_list();

  foreach($image_types as $image_name) {
    $header[] = $image_name . " last updated";
  }

  $rows = array();

  if(array_key_exists("und", $collection->field_collection_data)) {
    //loop the assets referenced and get their files

    $product_data = digital_core_data_products_read(array("collection" => $collection->nid));

    foreach($product_data['results'] as $product) {
      $row = array();
      $row[] = $product['east_product_id'];
      $row[] = $product['title'];
      if(array_key_exists("brand", $product)) {
        $row[] = $product["brand"]['title'];
      }
      else {
        $row[] = "";
      }
      $row[] = $product['upc'];
      $row[] = $product['changed'];

      foreach($image_types as $image_name) {

        $img_key = strtolower($image_name);

        //remove the trailing image part
        $img_key = str_replace(" image", "", $img_key);

        if(array_key_exists($img_key, $product['image_urls']) &&
                array_key_exists("uploaded_timestamp", $product['image_urls'][$img_key])) {
          $row[] = $product['image_urls'][$img_key]['uploaded_timestamp'];
        }
      }

      $rows[] = $row;
    }
  }

  $fp = fopen($file_info['full_path'], 'w');

  fputcsv($fp, $header);

  foreach($rows as $r) {
    fputcsv($fp, $r);
  }

  fclose($fp);

  return $file_info;
}

function digital_core_download_collection_asset($collection) {

  $file_info = array("full_path" => "temporary://{$collection->title}.zip", "filename" => $collection->title . ".zip");

  if(!$file_info) {
    return false;
  }

  $zip = new ZipArchive();

  if ($zip->open(drupal_realpath($file_info['full_path']), ZipArchive::OVERWRITE) === TRUE) {

    if(array_key_exists("und", $collection->field_asset_collection_data)) {
      //loop the assets referenced and get their files
      foreach($collection->field_asset_collection_data['und'] as $asset) {

        $file = file_load($asset['target_id']);

        //pull the file local so it can be zipped
        $tmpFile = file_copy($file, "temporary://{$file->filename}");

        $readable = is_readable($tmpFile->uri);
        $exists = file_exists($tmpFile->uri);

        if($readable && $exists) {

          //add to the zip
          $zip->addFile(drupal_realpath($tmpFile->uri), basename($tmpFile->uri));

          //delete the temp file
          file_delete($tmpFile);
        }
        else {
          drupal_set_message(t("Error adding image file to the archive, it does not exist. File: @file", array('@file' => $file['file_name'])));
        }
      }
      //close the zip
      $result = $zip->close();
    }
  }

  return $file_info;
}

function digital_core_download_collections_get_image_type_list() {

  $image_types = array();

  //pull up all of the image references on a product record
  $query = db_select("field_config_instance");
  $query->fields("field_config_instance", array("field_name", "data"));
  $query->join("field_config", "field_config", "field_id = field_config.id");
  $query->condition("bundle", "product_details");
  $query->condition("field_config.type", "entityreference");
  $asset_data = $query->execute()
              ->fetchAll();

  foreach($asset_data as $data) {
    $field_data = unserialize($data->data);

    $image_types[] = $field_data['label'];
  }

  return $image_types;
}