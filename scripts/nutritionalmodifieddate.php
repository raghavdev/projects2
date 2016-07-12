<?php

//get the nutritionupdated value from the table, convert it to a unix time stamp and push into the field on the product
$q = db_select("pws_productdetails");
$q->addJoin("inner", "digital_core_data_products", "dp", "dp.upc = pws_productdetails.upc");
$q->addJoin("inner", "field_data_field_productsid", "sid", "sid.field_productsid_value = dp.productsid");
$q->fields("pws_productdetails", array("ingredientsUpdated"))
  ->fields("sid", array("entity_id"));

$rows = $q->execute()->fetchAll();

$users = array();

foreach($rows as $row) {

  $time = strtotime($row->ingredientsUpdated);

  echo "\n entity:" . $row->entity_id . "  time:" . $time;

  ob_flush();

  $uid = 0;

  if($time) {
    try {

      db_insert("field_data_field_ingredients_modified")
        ->fields("field_data_field_ingredients_modified", array("entity_type" => "node",
          "bundle" => "product_details",
          "deleted" => 0,
          "entity_id" => $row->entity_id,
          "revision_id" => $row->entity_id,
          "language" => 'und',
          "delta" => 0,
          "field_ingredients_modified_value" => $time,
        ))
        ->execute();

      db_insert("field_revision_field_ingredients_modified")
        ->fields("field_revision_field_ingredients_modified", array("entity_type" => "node",
          "bundle" => "product_details",
          "deleted" => 0,
          "entity_id" => $row->entity_id,
          "revision_id" => $row->entity_id,
          "language" => 'und',
          "delta" => 0,
          "field_ingredients_modified_value" => $time,
        ))
        ->execute();

      db_insert("field_data_field_ingredients_mod_user")
        ->fields("field_data_field_ingredients_mod_user", array("entity_type" => "node",
          "bundle" => "product_details",
          "deleted" => 0,
          "entity_id" => $row->entity_id,
          "revision_id" => $row->entity_id,
          "language" => 'und',
          "delta" => 0,
          "field_ingredients_mod_user_value" => $time,
        ))
        ->execute();

      db_insert("field_revision_field_ingredients_mod_user")
        ->fields("field_revision_field_ingredients_mod_user", array("entity_type" => "node",
          "bundle" => "product_details",
          "deleted" => 0,
          "entity_id" => $row->entity_id,
          "revision_id" => $row->entity_id,
          "language" => 'und',
          "delta" => 0,
          "field_ingredients_mod_user_value" => $time,
        ))
        ->execute();
    }
    catch(Exception $ex) {

    }
  }
}