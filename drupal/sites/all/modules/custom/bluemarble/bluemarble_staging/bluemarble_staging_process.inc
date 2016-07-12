<?php

function bluemarble_staging_process_entity_records($data_type, $data, $primary_key_field) {

  module_load_include('inc', 'bluemarble_staging', 'bluemarble_staging_process');

  preg_match("/eiw_(.*)/", $data_type, $matches);

  if($matches) {
    $type = $matches[1];
  }

  if($type) {
    module_load_include('inc', 'bluemarble_data', "bluemarble_data_{$type}s");

    $pl = strtolower($primary_key_field);

    foreach($data as $record) {

      $cond = false;

      //the static record key is the primary field, but if its mapped to the drupal need to allow for that too
      if(!array_key_exists($primary_key_field, $record)) {
        $cond = $record["field_" . $pl];
      }
      else {
        $cond = $record[$primary_key_field];
      }

      $entity_id = false;

      if($cond) {
        //check if this entity exists or not already
        $entity_id = db_select("field_data_field_{$pl}")
                  ->fields("field_data_field_{$pl}", array("entity_id"))
                  ->condition("field_{$pl}_value", $cond)
                  ->execute()
                  ->fetchField();
      }

      $ind = $record['changeInd'];
      unset($record['changeInd']);

      switch($ind) {
        case "I": {
          //insert the new entity entity if it doesnt
          if(!$entity_id) {
            //create the new record
            $method = "bluemarble_data_{$type}s_create";
            $method($record);
          }

          break;
        }
        case "D": {
          //remove this entity from the system
          if($entity_id) {
            node_delete($entity_id);
          }
          break;
        }
        case "U": {
          if($entity_id) {
            //generate the update request for this entity
            $method = "bluemarble_data_{$type}s_update";
            $method($entity_id, $record);
          }
          else {
            //insert the record
            $method = "bluemarble_data_{$type}s_create";
            $method($record);
          }
          break;
        }
      }
    }
  }
}

function bluemarble_staging_process_static_records($data, $destination, $fields, $primary_key_field) {

  //process the delete
  $doDelete = false;
  $deleteQuery = db_delete($destination);
  foreach($data as $d) {
    if($d['changeInd'] == "D") {
      unset($d['changeInd']);
      $deleteQuery->condition($primary_key_field, $d[$primary_key_field]);
      $doDelete = true;
    }
  }

  if($doDelete) {
    $deleteQuery->execute();
  }

  //process inserts
  //sorry hate this but drupal doesnt support the mysql commands I want to use
  //they have duplicate records come thru on the same job sometimes, or its insert and it already exists
  $doInsert = false;
  $query = "REPLACE INTO {$destination} (";
  $query .= implode(",", $fields) . ") Values ";
  $v = array();

  foreach($data as $d) {
    if($d['changeInd'] == "I") {
      unset($d['changeInd']);

      foreach($d as $i => $vv) {
        //escapes any ' or "
        $d[$i] = addslashes($vv);

        if($vv == "") {
          $d[$i] = 'null';
        }
      }

      $dat = "('" . implode("','", $d) . "')";

      //nulls get quoted using that trick, undo this
      $dat = str_replace("'null'", "null", $dat);

      $v[] .=$dat;
    }
  }

  if(count($v) > 0) {
    $query .= implode(",", $v) . ";";
    $doInsert = true;
  }

  if($doInsert) {
    db_query($query);
  }

  //process updates
  //sadly has to be singluar due to paging its safer this way
  foreach($data as $d) {
    if($d['changeInd'] == "U") {
      unset($d['changeInd']);

      $updateQuery = db_update($destination);
      $updateQuery->fields($d);
      $updateQuery->condition($primary_key_field, $d[$primary_key_field])
      ->execute();
    }
  }
}