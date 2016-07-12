<?php

//get all cc and mpw images
//select fid, filename from file_managed where filename like "%cc.%" or filename like "%mpw%";
$or = db_or()->condition("filename", "%" . db_like("cc.") . "%", "LIKE")->condition("filename", "%" . db_like("mpw.") . "%", "LIKE");
$images = db_select("file_managed", "f")
            ->fields("f", array("fid", "filename"))
            ->condition($or)
            ->execute()
            ->fetchAll();


$records = array();

//figure out which product this image relates to then assign it
foreach($images as $img) {
  preg_match("/(.*)cc.*/", $img->filename, $cc);
  preg_match("/(.*)mpw.*/", $img->filename, $mpw);

  $data = array();

  $q = db_select("digital_core_data_products");
  $q->addJoin("inner", "field_data_field_productsid", "ps", "ps.field_productsid_value = digital_core_data_products.productsid");
  $d = $q->fields("ps", array("entity_id"))
          ->condition("digital_core_data_products.productsid", $cc[1]);
  $nid = $d->execute()->fetchField();
  $data['nid'] = $nid;
  $data['fid'] = $img->fid;

  if($data['nid'] != "" && $mpw) {
    $q = db_select("digital_core_data_products");
    $q->addJoin("inner", "field_data_field_productsid", "ps", "ps.field_productsid_value = digital_core_data_products.productsid");
    $nid = $d = $q->fields("ps", array("entity_id"))
            ->condition("digital_core_data_products.productsid", $mpw[1])
            ->execute()
            ->fetchField();
    $data['nid'] = $nid;
    $data['fid'] = $img->fid;
  }

  if($data['nid']) {

    db_delete("field_data_field_print_image")
      ->condition("entity_id", $data['nid'])
      ->execute();

    db_delete("field_revision_field_print_image")
      ->condition("entity_id", $data['nid'])
      ->execute();

    db_insert("field_data_field_print_image")
         ->fields(array("entity_type" => "node",
                        "bundle" => "product_details",
                        "deleted" => "0",
                        "entity_id" => $data['nid'],
                        "revision_id" => $data['nid'],
                        "language" => "und",
                        "delta" => "0",
                        "field_print_image_target_id" => $data['fid']))
         ->execute();

    db_insert("field_revision_field_print_image")
         ->fields(array("entity_type" => "node",
                        "bundle" => "product_details",
                        "deleted" => "0",
                        "entity_id" => $data['nid'],
                        "revision_id" => $data['nid'],
                        "language" => "und",
                        "delta" => "0",
                        "field_print_image_target_id" => $data['fid']))
         ->execute();
  }
}
