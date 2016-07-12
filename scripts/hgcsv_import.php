<?php

if (($handle = fopen("hgproductfeed.csv", "r")) !== FALSE) {
  while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
    db_update("digital_core_data_products")
      ->fields(array("organic" => ($data[32] != "" ? "Y" : "N"),
                     "gluten_free" => ($data[33] != "" ? "Y": "N"),
                     "dairy_free" => ($data[34] != "" ? "Y": "N"),
                     "yeast_free" => ($data[35] != "" ? "Y": "N"),
                     "wheat_free" => ($data[36] != "" ? "Y": "N"),
                     "vegan" => ($data[37] != "" ? "Y": "N"),
                     "kosher" => ($data[38] != "" ? "Y": "N"),
                     "fair_trade" => ($data[39] != "" ? "Y": "N"),
                     "pack" => $data[40],
                     "size" => $data[41]))
      ->condition("upc", "%" . db_like($data[22]), 'LIKE')
      ->execute();
  }
  fclose($handle);
}