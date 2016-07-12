<?php
/**
 * @file
 * A drush script for migrating images.
 */

/*
 * Deprecated for drush commands in asset_migrate.drush.inc.
 *
$directories = asset_migrate_crawl_directory("/Users/jonathan/Sites/unfi-dc/migrate_images", "*.*");

$start_record = (int) drush_get_option('start');
$max_record = count($directories);

drush_print('Starting from file index: ' . $start_record . ' of ' . $max_record);

$i = $start_record;
while ($i < $max_record) {
  $filePath = $directories[$i];
  $i++;

  $ignore_files = array('Thumbs.db', '.DS_Store');
  if (in_array(basename($filePath), $ignore_files)) {
    drush_print('Skipping ' . $filePath);
    continue;
  }

  drush_print('Migrating file at index ' . ($i-1) . ': ' . $filePath);

  $file_info['file_path'] = $filePath;
  $file_info['file_name'] = basename($filePath);

  $file = digital_core_assets_create_asset($file_info);
  if (!$file) {
    drush_print('Could not create file for ' . $filePath);
    continue;
  }

  $pathdata = explode('/', $file_info['file_path']);

  $pathdata = array_splice($pathdata, 13, count($pathdata) - 13);

  if (count($pathdata) > 1) {
    // remove the file from the list
    unset($pathdata[count($pathdata) - 1]);

    // check if the path exists
    $tid = asset_migrate_get_term_id($pathdata, 0);

    if ($tid) {
      drush_print('Setting category for ' . $filePath . ' to ' . $tid);

      // assign the asset to the category
      $file->field_asset_category['und'][0]['tid'] = $tid;
      file_save($file);
    }
  }

  // relate the product to the image
  // the eastid is the name of the file, drop off the ccw.jpg or the cc
  // ccw = original
  // cc = print
  if (preg_match(('/([0-9]*)cc/'), $file_info['file_name'], $matches)) {
    // $matches[1] - the east id

    $query = db_select("digital_core_data_products")
              ->fields("p", array('entity_id'));
    $query->innerJoin("field_data_field_productsid", 'p', 'p.field_productsid_value = digital_core_data_products.productsid');
    $query->condition("digital_core_data_products.east_product_id", $matches[1]);
    $nid = $query->execute()->fetchField();

    if ($nid) {
      drush_print('Updating product ' . $nid . ' with file ' . $filePath);

      // direct update the product for speed
      digital_core_data_update_direct("node", "product_details", $nid, array("field_primary_image" => $file->fid), FALSE);
    }
  }
}
 */
