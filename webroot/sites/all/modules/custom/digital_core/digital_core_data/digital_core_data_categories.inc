<?php

function digital_core_data_categories_create($data) {

  $term = digital_core_services_categories_process_term_data($data);

  $result = taxonomy_term_save($term);

  $term = tom_dedrupalize_fields($term);

  return $term;
}

function digital_core_data_categories_read($tid = false) {

  if(!$tid) {
    //get the taxonomy vocab id
    $vid = taxonomy_vocabulary_machine_name_load("categories")->vid;

    $tree = taxonomy_get_tree($vid, 0, null, true);

    $clean = array();
    $i = 0;
    foreach($tree as $t) {
      $t->order = $i;

      $clean[] = tom_dedrupalize_fields($t);

      $i++;
    }

    return $clean;
  }

  $term = taxonomy_term_load($tid);

  return tom_dedrupalize_fields($term);
}

function digital_core_data_categories_update($tid, $data) {

  $data = tom_drupalize_fields('taxonomy_term', 'categories', $data);

  $data = digital_core_services_categories_process_term_data($data);
  $data->tid = $tid;

  $result = taxonomy_term_save($data);

  $data = tom_dedrupalize_fields($data);

  return $data;
}

function digital_core_data_categories_delete($tid) {
  return taxonomy_term_delete($tid);
}

function digital_core_services_categories_process_term_data($term) {
  //get the taxonomy vocab id
  $vid = taxonomy_vocabulary_machine_name_load("categories")->vid;

  $term = _services_arg_value($term, 'term');

  $term['field_internal_only'] = array("und" => array(array("value" => $term['field_internal_only'])));

  $term['vid'] = $vid;
  $term['vocabulary_machine_name'] = 'categories';
  $term = (object)$term;

  return $term;
}

function digital_core_data_categories_get_category_children_categories($category, &$children = array()) {
  //categories need to be able to search for all children also
  //so this must convert the category filter into a categories filter
  //where it includes its children
  $child_data = taxonomy_get_children($category);
  $child_data = array_keys($child_data);

  //get the children's children
  foreach($child_data as $child) {
    digital_core_data_categories_get_category_children_categories($child, $children);
    $children[] = $child;
  }

  //need that parent on the list too
  //$children[] = $category;

  return $children;
}

function digital_core_data_categories_parse_category_children($category_parameter) {
  $categories = false;

  //check for a many
  if(strpos($category_parameter, '+')) {
    //since this is a many query needs to be a categories query.
    //sadly cant really change the js to send categories instead, doesnt fit the model...

    //break up
    $parentCats = explode("+", $category_parameter);

    //take the parents
    $newCategories = $parentCats;

    //find the children
    foreach($categories as $c) {
      $newCategories = array_merge($newCategories, digital_core_data_categories_get_category_children_categories($c));
    }

    //change the query to be the categories query
    $categories = $data[0]."+".implode("|", $newCategories);
  }
  else {
    //get the children of the category
    $data = explode("|", $category_parameter);

    $child_data = digital_core_data_categories_get_category_children_categories($data[1]);
    $child_data[] = $data[1]; //make sure the parent is in there

    //only bother if there are children
    if(count($child_data) > 0) {
      $categories = $data[0]."+".implode("|", $child_data);
    }
  }

  return $categories;
}