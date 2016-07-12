<?php

//relink the image files to the products


//pull up the list of managed files
$files = db_select("file_managed")
            ->fields("file_managed", array("fid", "filename"))
            ->execute()
            ->fetchAllKeyed();

print_r($files);

//read the file name if it is ^([0-9]+)cc then its primary image for that east id, ccw is print image for that id
foreach($files as $fid => $file) {

  echo $file;

  $image_type = 0;
  if(preg_match("/^([0-9]+)ccw/", $file, $match)) {
    //primary image
    $image_type = 2;
  }
  else if(preg_match("/^([0-9]+)cc/", $file, $match)) {
    //print image
    $image_type = 1;
  }

  if($image_type != 0) {
    //find the nid of the product that matches this east id
    $q = db_select("field_data_field_productsid")
            ->fields("field_data_field_productsid", array("entity_id"));

    $q->addJoin("inner", "digital_core_data_products", "d", "d.ProductSid = field_data_field_productsid.field_productsid_value");
    $nid = $q->condition("d.east_product_id", $match[1])
              ->execute()
              ->fetchField();

    if($nid) {

      if($image_type == 1) {
        db_merge("field_data_field_primary_image")
            ->key(array("entity_id" => $nid))
            ->fields(array(
                "entity_type" => "node",
                "bundle" => "product_details",
                "deleted" => "0",
                "entity_id" => $nid,
                "revision_id" => $nid,
                "language" => "und",
                "delta" => "0",
                "field_primary_image_target_id" => $fid
            ))
            ->execute();

        db_merge("field_revision_field_primary_image")
            ->key(array("entity_id" => $nid))
            ->fields(array(
                "entity_type" => "node",
                "bundle" => "product_details",
                "deleted" => "0",
                "entity_id" => $nid,
                "revision_id" => $nid,
                "language" => "und",
                "delta" => "0",
                "field_primary_image_target_id" => $fid
            ))
            ->execute();
      }
      else {
        db_merge("field_data_field_print_image")
            ->key(array("entity_id" => $nid))
            ->fields(array(
                "entity_type" => "node",
                "bundle" => "product_details",
                "deleted" => "0",
                "entity_id" => $nid,
                "revision_id" => $nid,
                "language" => "und",
                "delta" => "0",
                "field_print_image_target_id" => $fid
            ))
            ->execute();

        db_merge("field_revision_field_print_image")
            ->key(array("entity_id" => $nid))
            ->fields(array(
                "entity_type" => "node",
                "bundle" => "product_details",
                "deleted" => "0",
                "entity_id" => $nid,
                "revision_id" => $nid,
                "language" => "und",
                "delta" => "0",
                "field_print_image_target_id" => $fid
            ))
            ->execute();
      }
    }
  }
}
