<?php

function digital_core_staging_process_data($data_type) {
  $handle = background_process_start('digital_core_staging_process_data_records', $data_type);
}

//standard tables
function digital_core_staging_process_data_records_callback($data_type) {

  $page_size = variable_get("digital_core_staging_page_size", 1000);

  $primary_key_field = db_select("digital_core_mapping", 'm')
                              ->fields('m', array("fromField"))
                              ->condition("dataType", $data_type)
                              ->condition("source", "staging")
                              ->condition('primary_key', 1)
                              ->execute()->fetchField();

  //get the jobs in order they had been ran to keep history of changes right
  //get the jobs we need to run
  $job = db_select("eiw_jobs")
            ->fields("eiw_jobs", array("JobExecSid",  "total_pages", "attempts", "processed_last_page", "processed"))
            ->condition("processed", 0)
            ->condition("data_type", $data_type)
            ->orderBy("JobExecSid", "ASC")
            ->execute()
            ->fetchObject();

  if(!$job) {
    return;
  }

  $page = 0;
  if($job->processed_last_page != null) {
    $page = $job->processed_last_page;
  }

  if($job->total_pages == 0 || is_null($job->total_pages)) {
    //get a record count for this job and figure out how many pages it has
    $r = db_select($data_type)
          ->fields($data_type)
          ->execute();
    $count = $r->rowCount();
    unset($r);

    $total_pages = floor($count / $page_size) + 1;

    $job->total_pages = $total_pages;

    //set the page count on the job record
    db_update("eiw_jobs")
      ->fields(array("total_pages" => $total_pages))
      ->condition("JobExecSid", $job->JobExecSid)
      ->condition("data_type", $data_type)
      ->execute();
  }

  if(is_null($job->attempts)) {
    $job->attempts = 0;
    $job->processed = 0;
  }

  $job->attempts++;

  //update the job table with this new info
  db_update("eiw_jobs")
    ->fields(array("processed_last_page" => $page, "processed" => $job->processed, "processedTime" => time(), "attempts" => $job->attempts))
    ->condition("JobExecSid", $job->JobExecSid)
    ->condition("data_type", $data_type)
    ->execute();

  //get a list of destinations for this data type
  $dd = db_select("digital_core_mapping", 'm')
                    ->fields('m', array("destination"))
                    ->condition("dataType", $data_type)
                    ->condition("destination", 'NULL', '!=')
                    ->condition("destination", '', '!=')
                    ->distinct()
                    ->execute()
                    ->fetchAll();

  $content_types = node_type_get_types();

  //flatten the data. damn it drupal
  $destinations = array();
  foreach($dd as $d) {
    //force the content type to be processed first
    if(array_key_exists($d->destination, $content_types)) {
      $destinations[0] = $d->destination;
    }
    else {
      $destinations[1] = $d->destination;
    }
  }

  ksort($destinations);

  foreach($destinations as $destination) {

    $primary_key_field = db_select("digital_core_mapping", 'm')
                              ->fields('m', array("fromField"))
                              ->condition("dataType", $data_type)
                              ->condition("source", "staging")
                              ->condition('primary_key', 1)
                              ->execute()->fetchField();

    //get the mapping
    $or = db_or();
    $or->condition("destination", $destination);
    $or->condition("primary_key", 1);

    $fieldMappings = db_select("digital_core_mapping", 'm')
                        ->fields('m', array("fromField", "toField", "fromAlt", "customProcessing", "destination"))
                        ->condition("dataType", $data_type)
                        ->condition("source", "staging")
                        ->condition($or)
                        ->execute()
                        ->fetchAllAssoc('fromField');

    //get the products for this page of data
    $query = db_select($data_type);

    $fields = array();
    foreach($fieldMappings as $field) {
      $fields[] = $field->toField;

//      if($field->fromAlt) {
//        $query->addField($data_type, $field->fromAlt, "alt-" . $field->toField);
//      }

      $query->addField($data_type, $field->fromField, $field->toField);
    }

    //TEMPORARY till better solution is made
    if($destination == "digital_core_data_products") {
      $fields[] = "product_name";
      $query->addField('eiw_product', 'EastProductDesc', 'product_name');
    }

    $query->addField($data_type, "changeInd");
    $query->range($page * $page_size, $page_size);
    $query->condition("JobexecSID", $job->JobExecSid);
    $data = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    //invoke hook for pre processing
    module_invoke_all('digital_core_staging_process_pre', $destination,  $data, $data_type);

    //drupal data will be procedural
    if(array_key_exists($destination, $content_types)) {
      digital_core_staging_process_entity_records($data_type, $data, $primary_key_field);
    }
    else {
      //static data can be processed through straight queries, its faster and more effcient
      digital_core_staging_process_static_records($data, $destination, $fields, $primary_key_field);
    }

    //invoke hook for post processing
    module_invoke_all('digital_core_staging_process_post', $destination, $data, $data_type);
  }

  $page = $job->processed_last_page + 1;

  $processed = 0;

  //check if we have exceeded the pages for this job, mark it processed if we have
  //this job will keep being ran till it has had all pages finished
  if($job->total_pages == $page) {
    $processed=1;
  }

  //dont let it get stuck on a job if it has processed it a few times and isnt making it thru
  if($job->attempts > (2 * $job->total_pages)) {
    $processed=1;
  }

  db_update("eiw_jobs")
    ->fields(array("processed_last_page" => $page, "processed" => $processed))
    ->condition("JobExecSid", $job->JobExecSid)
    ->condition("data_type", $data_type)
    ->execute();

  if($processed == 1) {
    //delete the staging records for this job
    db_delete($data_type)
      ->condition("JobExecSid", $job->JobExecSid)
      ->execute();

    //finished copying over the category data, to the holding table, we then need to update drupal,
    //categories are special that they dont fit the model used here for mapping and handling of the data, too specific
    if($data_type == "eiw_rcm_category") {
      module_load_include('inc', 'digital_core_data', 'digital_core_data_rcm_categories');
      digital_core_data_rcm_categories_parse_staging();
    }
  }

  //hate adding this here as its tied directly to a type
  if($destination == "digital_core_data_products") {
    //if any products were created here i this run, it will be missing its check digit
    //this will add it in post process
    digital_core_data_add_missing_checkdigits();
  }

  //call the job processor to start next batch
  digital_core_staging_process_data_records($data_type);
}

function digital_core_staging_process_entity_records($data_type, $data, $primary_key_field) {

  module_load_include('inc', 'digital_core_staging', 'digital_core_staging_process');

  preg_match("/eiw_(.*)/", $data_type, $matches);

  if($matches) {
    $type = $matches[1];
  }

  if($type) {
    module_load_include('inc', 'digital_core_data', "digital_core_data_{$type}s");

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
            $method = "digital_core_data_{$type}s_create";
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
            $method = "digital_core_data_{$type}s_update";
            $method($entity_id, $record);
          }
          else {
            //insert the record
            $method = "digital_core_data_{$type}s_create";
            $method($record);
          }
          break;
        }
      }
    }
  }
}

function digital_core_staging_process_static_records($data, $destination, $fields, $primary_key_field) {

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