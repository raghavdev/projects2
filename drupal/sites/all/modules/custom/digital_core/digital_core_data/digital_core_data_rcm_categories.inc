<?php

function digital_core_data_rcm_categories_read() {
  //get the taxonomy vocab id
  $vid = taxonomy_vocabulary_machine_name_load("rcm_categories")->vid;

  return taxonomy_get_tree($vid);
}

//parse the data from staging and generate the category structure
function digital_core_data_rcm_categories_parse_staging() {
  $categoryTerms = array();

  // Massage the data to remove extra characters (i.e.: *)
  db_update('digital_core_data_rcm_categories')
    ->expression('department_name', 'REPLACE(department_name, \'*\', \'\')')
    ->expression('category_name', 'REPLACE(category_name, \'*\', \'\')')
    ->expression('segment_name', 'REPLACE(segment_name, \'*\', \'\')')
    ->expression('subsegment_name', 'REPLACE(subsegment_name, \'*\', \'\')')
    ->expression('profile_name', 'REPLACE(profile_name, \'*\', \'\')')
    ->execute();

  //get a list of the categories from the staging table
  $rcm_categories = db_select("digital_core_data_rcm_categories")
                      ->fields("digital_core_data_rcm_categories", array())
                      ->orderBy("RetailCatLinkSid", "ASC")
                      ->execute()
                      ->fetchAll();
  // +--------------------+--------------+------+-----+---------+-------+
  // | Field              | Type         | Null | Key | Default | Extra |
  // +--------------------+--------------+------+-----+---------+-------+
  // | RetailCatLinkSid   | int(11)      | YES  |     | NULL    |       |
  // | DataextrctSid      | int(11)      | YES  |     | NULL    |       |
  // | department_name       | varchar(100) | YES  |     | NULL    |       |
  // | category_name        | varchar(100) | YES  |     | NULL    |       |
  // | segment_name    | varchar(100) | YES  |     | NULL    |       |
  // | subsegment_name | varchar(100) | YES  |     | NULL    |       |
  // | profile_name       | varchar(100) | YES  |     | NULL    |       |
  // | ChangeInd          | char(1)      | YES  |     | NULL    |       |
  // | JobExecSid         | int(11)      | YES  |     | NULL    |       |
  // +--------------------+--------------+------+-----+---------+-------+


  $vocab = taxonomy_vocabulary_machine_name_load("rcm_categories");

  //convert them to their ids of the existing terms
  foreach($rcm_categories as $cat) {

    $department_sid = $cat->department_name;

    if(!array_key_exists($department_sid, $categoryTerms)) {
      $term_value = $cat->department_name;
      $vocab_id   = $vocab->vid;
      $sid        = $cat->RetailCatLinkSid;
      $parent     = NULL;
      $categoryTerms[$department_sid] = digital_core_data_rcm_categories_create($term_value, $vocab_id, $sid, $parent);
    }

    if($cat->category_name != "Not Applicable") {

      $category_sid = $department_sid . '|' . $cat->category_name;

      if(!array_key_exists($category_sid, $categoryTerms)) {
        $term_value = $cat->category_name;
        $vocab_id   = $vocab->vid;
        $sid        = $cat->RetailCatLinkSid;
        $parent     = $categoryTerms[$department_sid];
        $categoryTerms[$category_sid] = digital_core_data_rcm_categories_create($term_value, $vocab_id, $sid, $parent);
      }

      if($cat->segment_name != "Not Applicable") {

        $segment_sid = $category_sid . '|' . $cat->segment_name;

        if(!array_key_exists($segment_sid, $categoryTerms)) {
          $term_value = $cat->segment_name;
          $vocab_id   = $vocab->vid;
          $sid        = $cat->RetailCatLinkSid;
          $parent     = $categoryTerms[$category_sid];
          $categoryTerms[$segment_sid] = digital_core_data_rcm_categories_create($term_value, $vocab_id, $sid, $parent);
        }

        if($cat->subsegment_name != "Not Applicable") {

          $subsegment_sid = $segment_sid . '|' . $cat->subsegment_name;

          if(!array_key_exists($subsegment_sid, $categoryTerms)) {
            $term_value = $cat->subsegment_name;
            $vocab_id   = $vocab->vid;
            $sid        = $cat->RetailCatLinkSid;
            $parent     = $categoryTerms[$segment_sid];
            $categoryTerms[$subsegment_sid] = digital_core_data_rcm_categories_create($term_value, $vocab_id, $sid, $parent);
          }
        }
      }
    }
  }
}

function digital_core_data_rcm_categories_create($term_value, $vocab_id, $sid, $parent = null) {
  if($term_value == "") {
    return "";
  }

  $term = taxonomy_get_term_by_name($term_value, "rcm_categories");

  //make sure the term we pulled up was the same heirachically
  if($parent) {
    if(is_array($term)) {
      $f = false;
      foreach($term as $t) {
        foreach(taxonomy_get_parents($t->tid) as $p) {
          if ($p->tid == $parent) {
            $f = TRUE;
            $term = $t;
            break 2;
          }
        }
      }

      if(!$f) {
        $term = false;
      }
    }
    else {
      $f = FALSE;
      foreach(taxonomy_get_parents($term->tid) as $p) {
        if ($p->tid == $parent) {
          $f = TRUE;
          break;
        }
      }
      if (!$f) {
        $term = FALSE;
      }
    }
  }

  if(!$term) {
    $term = new stdClass();
    $term->name = $term_value;
    $term->vid = $vocab_id;
    $term->field_retailcatlinksid['und'][0]['value'] = $sid;

    if($parent != null) {
      $term->parent = $parent;
    }

    //create the term
    taxonomy_term_save($term);
  }

  if(is_object($term)) {
    return $term->tid;
  }
  else if(is_array($term)) {
    $term = array_shift($term);
    return $term->tid;
  }

  return "";
}

//handle the relation of categories to products
function digitial_core_data_rcm_categories_relate_products($products) {
  foreach($products as $product) {

    //cast to array to ensure its proper type
    $product = (array)$product;

    $tid = (string) db_select("field_data_field_retailcatlinksid")
              ->fields("field_data_field_retailcatlinksid", array("entity_id"))
              ->condition("field_retailcatlinksid_value", $product['RetailCatLinkSid'])
              ->execute()
              ->fetchField();

    //convert the sid into a nid so we can update the product
    $nid = (string) db_select("field_data_field_productsid")
              ->fields("field_data_field_productsid", array("entity_id"))
              ->condition("field_productsid_value", $product['ProductSid'])
              ->execute()
              ->fetchField();

    if($tid && $nid) {
      //sadly VERY SLOW
      //digital_core_data_products_update($nid, array("category" => $tid));

      try {
        //MUCH faster
        db_merge("field_data_field_category")
          ->key(array("entity_type" => "node",
                      "bundle" => "product_details",
                      "entity_id" => $nid,
                      "field_category_tid" => $tid))
          ->fields(array("entity_type" => 'node',
                         "bundle" => 'product_details',
                         "deleted" => 0,
                         "entity_id" => $nid,
                         "revision_id" => $nid,
                         "language" => "und",
                         "delta" => 0,
                         "field_category_tid" => $tid))
          ->execute();

        db_merge("field_revision_field_category")
          ->key(array("entity_type" => "node",
                      "bundle" => "product_details",
                      "entity_id" => $nid,
                      "field_category_tid" => $tid))
          ->fields(array("entity_type" => 'node',
                         "bundle" => 'product_details',
                         "deleted" => 0,
                         "entity_id" => $nid,
                         "revision_id" => $nid,
                         "language" => "und",
                         "delta" => 0,
                         "field_category_tid" => $tid))
          ->execute();
      }
      catch(Exception $ex) {

      }
    }
  }
}