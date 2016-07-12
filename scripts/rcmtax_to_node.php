<?php

$nodes = array();
$termMapping = array();

//create all the terms first
$terms = taxonomy_get_tree(6);

foreach($terms as $term) {
  $node = new stdClass();
  $node->title = $term->name;
  $node->type = "rcm_hierarchy";
  node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
  $node->uid = 0;
  $node->status = 1; //(1 or 0): published or not
  $node->promote = 0; //(1 or 0): promoted to front page

  $node->field_active[$node->language][]['value'] = true;

  node_save($node);

  $node->tid = $term->tid;

  $nodes[] = $node;
  $termMapping[$term->tid] = $node->nid;
}

///after all terms created, go through and apply heirarchy
foreach($nodes as $node) {
  $parent = db_select("taxonomy_term_hierarchy")
              ->fields("taxonomy_term_hierarchy", array("parent"))
              ->condition("tid", $node->tid)
              ->execute()
              ->fetchField();

  if($parent) {
    db_insert("field_data_field_parent")
      ->fields(array(
            "field_parent_target_id" => $termMapping[$parent],
            "entity_type" => "node",
            "bundle" => "rcm_hierarchy",
            "deleted" => 0,
            "entity_id" => $node->nid,
            "revision_id" => $node->nid,
            "language" => "und",
            "delta" => 0,
          ))
      ->execute();

    db_insert("field_revision_field_parent")
       ->fields(array(
            "field_parent_target_id" => $termMapping[$parent],
            "entity_type" => "node",
            "bundle" => "rcm_hierarchy",
            "deleted" => 0,
            "entity_id" => $node->nid,
            "revision_id" => $node->nid,
            "language" => "und",
            "delta" => 0,
          ))
      ->execute();
  }
}