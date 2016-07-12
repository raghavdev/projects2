<?php
/**
 * @file
 * A drush script for migrating images.
 */

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

  $fid = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('f.uri', 's3://' . $file_info['file_name'])
    ->execute()
    ->fetchField();

  if (!$fid) {
    drush_print('Could not load file for ' . $filePath);
    continue;
  }

  // relate the product to the image
  // the eastid is the name of the file, drop off the ccw.jpg or the cc
  // mpw = west print image
  // mpww = west web image
  if (preg_match(('/([0-9]*)mpw/'), $file_info['file_name'], $matches)) {
    // $matches[1] - the west id

    $query = db_select("digital_core_data_products")
              ->fields("p", array('entity_id'));
    $query->innerJoin("field_data_field_productsid", 'p', 'p.field_productsid_value = digital_core_data_products.productsid');
    $query->condition("digital_core_data_products.west_product_id", $matches[1]);
    $nid = $query->execute()->fetchField();

    if ($nid) {
      drush_print('Updating product ' . $nid . ' with file ' . $filePath);

      // direct update the product for speed
      digital_core_data_update_direct("node", "product_details", $nid, array("field_primary_image" => $fid), FALSE);
    }
  }
}
