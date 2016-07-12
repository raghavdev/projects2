<?php

//resource functions
//////////////////////////////

//there may
function digital_core_services_assets_index ($perPage, $page, $parameters, $sort) {

  module_load_include('inc', 'digital_core_data', 'digital_core_data_assets');

  if(!isset($sort)) {
    $sort = "field_title";
  }

  $search = "";

  //since search is not a valid field, it will be filtered out below, so just set it here
  if(is_array($parameters) && array_key_exists("search", $parameters)) {
    $search = $parameters['search'];
  }

  //internal only is added to the ignore list so the boolean filter can be properly used,

  $parameters = tom_drupalize_fields("file", false, $parameters, array("internal_only",
                                                                                     "collection",
                                                                                     "sort_dir",
                                                                                     "sort",
                                                                                     "file_extension",
                                                                                     "asset_category"));

  //get the field name we are sorting by
  $sorting = tom_drupalize_fields("file", false, array($sort => ""));
  if(count($sorting) > 0) {
    $sort = array_keys($sorting);

    $sort = $sort[0];
  }

  $sort_dir = "ASC";
  if(array_key_exists("sort_dir", $parameters)) {
    $sort_dir = $parameters['sort_dir'];
  }

  $parameters = array_merge(array("perPage" => $perPage,
                                  "page" => $page,
                                  "sort_dir" => $sort_dir,
                                  "search" => $search,
                                  ),
                            $parameters);

  $parameters['sort'] = $sort;

  return digital_core_data_assets_read($parameters);
}

function digital_core_services_assets_retrieve($fid, $option = false) {
  digital_core_assets_download_asset($fid, $option);
}

function digital_core_services_assets_create($data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_assets');
  return digital_core_data_assets_create($data);
}

function digital_core_services_assets_update($id, $data) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_assets');
  return digital_core_data_assets_update($id, $data);
}

function digital_core_services_assets_delete($id) {
  module_load_include('inc', 'digital_core_data', 'digital_core_data_assets');
  return digital_core_assets_remove_image($id);
}