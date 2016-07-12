<?php

//get a list of image files that dont have a product association
//select distinct filename from file_managed
//left join field_data_field_primary_image p on p.field_primary_image_target_id = file_managed.fid
//where p.entity_id is null;

$q = db_select('file_managed')
          ->fields('file_managed', array("filename", 'fid'))
          ->isNull("p.entity_id");

$q->leftJoin("field_data_Field_primary_image", "p", "p.field_primary_image_target_id = file_managed.fid");
$files = $q->execute()->fetchAll();

print_r($files);

//loop each image find if there is a product that matches the pattern
foreach($files as $f) {

  //assign the image file
  if (preg_match(('/([0-9]*)mpw/'), $f->filename, $matches)) {
    // $matches[1] - the west id

    $query = db_select("digital_core_data_products")
              ->fields("p", array('entity_id'));
    $query->innerJoin("field_data_field_productsid", 'p', 'p.field_productsid_value = digital_core_data_products.productsid');
    $query->condition("digital_core_data_products.west_product_id", $matches[1]);
    $nid = $query->execute()->fetchField();

    if ($nid) {
      drush_print('Updating product ' . $nid . ' with file ' . $filePath);

      // direct update the product for speed
      digital_core_data_update_direct("node", "product_details", $nid, array("field_primary_image" => $f->fid), FALSE);
    }
  }
}


