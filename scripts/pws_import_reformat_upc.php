<?php

$upcs2 = db_select("digital_core_data_products")
        ->fields("digital_core_data_products", array("upc"))
        ->condition("upc", "", "<>")
        ->execute()
        ->fetchAll();

foreach($upcs2 as $upc2) {
  $upc = substr($upc2->upc, 2, strlen($upc2->upc) - 2);

//      db_update("pws_products")
//        ->fields(array("upc" => $upc2->upc))
//        ->condition("upc", $upc)
//        ->execute();

//      db_update("pws_productnutrition")
//        ->fields(array("upc" => $upc2->upc))
//        ->condition("upc", $upc)
//        ->execute();

    db_update("pws_cmp")
    ->fields(array("upcnumber" => $upc2->upc))
    ->condition("upcnumber", $upc)
    ->execute();
}

