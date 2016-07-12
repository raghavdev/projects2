<?php

$type = "product_details";
$limit = 10;

// keep this alive
set_time_limit(600);

do {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('n.type', $type);
  $query->orderBy('n.nid');
  $result = $query->range(0, $limit)->execute();

  $node_ids = $result->fetchCol();

  node_delete_multiple($node_ids);

} while ((int) $query->countQuery()->execute()->fetchField() > 0);
