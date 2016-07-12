<?php

//Update the feed, allowing addition or removal of items from the feed. The
//rest of the admin will be from drupal
function digital_core_services_feeds_update($id, $op, $nid, $data) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_feeds');

  //the id is the name of the user that owns the feed
  $owner = user_load_by_name($id);

  //ecom is a built in user so if it doesnt exist add it
  if($id == "ecom_feed" && !$owner) {

    $password = user_password(8);

    $fields = array(
      'name' => 'ecom_feed',
      'mail' => 'ecom_feed@unfi.com',
      'pass' => $password,
      'status' => 1,
      'init' => 'email address',
      'roles' => array(
        DRUPAL_AUTHENTICATED_RID => 'authenticated user',
      ),
    );

    $owner = user_save('', $fields);
  }

  if(!$owner) {
    services_error("Error updating feed, owner does not exist", 500);
  }

  //find the feed this owner is related to
  $feedID = db_select("field_data_field_feed_owner")
              ->fields("field_data_field_feed_owner", array("entity_id"))
              ->condition("field_feed_owner_uid", $owner->uid)
              ->execute()
              ->fetchField();

  //only the ecom feed is allowed to be jit created
  if(!$feedID && $id != "ecom_feed") {
    services_error("Error updating feed, Owner does not have a feed", 500);
  }
  else if(!$feedID && $id == "ecom_feed") {
    digital_core_data_feeds_create($feedID, $owner, $data);
  }
  else {
    //update the feed with the provided feed data
    digital_core_data_feeds_update($feedID, $op, $nid, $data);
  }

  return true;
}

function digital_core_services_feeds_retrieve($feedOwner, $perPage, $page, $sort) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_feeds');

  //the id is the name of the user that owns the feed
  $owner = user_load_by_name($feedOwner);

  if(!$owner) {
    services_error("Error retrieving feed, feed does not exist", 500);
  }

  return digital_core_data_feeds_read($feedOwner, array("page" => $page, "perPage" => $perPage, "sort" => $sort));
}