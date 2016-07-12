<?php

function bluemarble_data_brands_create($data) {
  $data = tom_drupalize_fields("node", "brand", $data);

  return tom_create_drupal_entity("node", "brand", $data);
}

function bluemarble_data_brands_read($parameters) {

  $parameters["type"] = "brand";

  $brand_data = simple_solr_search(array(
    'index_name'       => variable_get('bluemarble_data_index_name', 'default_node_index'),
    'query_parameters' => $parameters,
  ));

  //clean up the field names
  foreach($brand_data['results'] as $idx => $record) {
    $brand_data['results'][$idx] = tom_dedrupalize_fields($record);
  }

  return $brand_data;
}

function bluemarble_data_brands_update($id, $data) {
  $data = tom_drupalize_fields('node', 'brand', $data);

  $return_value = tom_update_drupal_entity($id, "node", $data);

  $return = tom_dedrupalize_fields($return_value);

  if(sizeof($return) == 0) {
    services_error("Error updating brand", 500);
    return false;
  }
  else {
    return $return;
  }
}

function bluemarble_data_brands_delete() {

}

function digitial_core_data_brand_relate_products($products) {
  foreach($products as $product) {

    $brandnid = (string) db_select("field_data_field_brandsid")
              ->fields("field_data_field_brandsid", array("entity_id"))
              ->condition("field_brandsid_value", $product['BrandSid'])
              ->execute()
              ->fetchField();

    //convert the sid into a nid so we can update the product
    $nid = (string) db_select("field_data_field_productsid")
              ->fields("field_data_field_productsid", array("entity_id"))
              ->condition("field_productsid_value", $product['ProductSid'])
              ->execute()
              ->fetchField();

    if($brandnid && $nid) {

      //Far tooo slow
      //bluemarble_data_products_update($nid, array("brand" => $brandnid));

       //MUCH faster
      db_merge("field_data_field_brand")
        ->key(array("entity_type" => "node",
                    "bundle" => "product_details",
                    "entity_id" => $nid,
                    "field_brand_nid" => $brandnid))
        ->fields(array("entity_type" => 'node',
                       "bundle" => 'product_details',
                       "deleted" => 0,
                       "entity_id" => $nid,
                       "revision_id" => $nid,
                       "language" => "und",
                       "delta" => 0,
                       "field_brand_nid" => $brandnid))
        ->execute();

      db_merge("field_revision_field_brand")
        ->key(array("entity_type" => "node",
                    "bundle" => "product_details",
                    "entity_id" => $nid,
                    "field_brand_nid" => $brandnid))
        ->fields(array("entity_type" => 'node',
                       "bundle" => 'product_details',
                       "deleted" => 0,
                       "entity_id" => $nid,
                       "revision_id" => $nid,
                       "language" => "und",
                       "delta" => 0,
                       "field_brand_nid" => $brandnid))
        ->execute();
    }
  }
}
