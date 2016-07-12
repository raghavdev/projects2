<?php

$products = db_select("digital_core_data_products")
              ->fields("digital_core_data_products", array("ProductSid", "east_product_id"))
              ->condition("east_product_id", "", "!=")
              ->isNull("east_product_id_full")
              ->execute()
              ->fetchAll();

foreach($products as $product) {
  $checkDigit = digital_core_data_calulate_check_digit($product->east_product_id);

  if($product->east_product_id != "") {
    echo $product->east_product_id . "-" . $checkDigit . "\n";
    db_update("digital_core_data_products")
      ->fields(array("east_product_id_full" => $product->east_product_id ."-". $checkDigit))
      ->condition("east_product_id", $product->east_product_id)
      ->execute();
  }
}