<?php

/**
 * Implementation of hook_drush_command().
 */
function asset_migrate_drush_command() {
  $items = array();

  $items['asset_migrate'] = array(
    'description' => 'Migrates images from a source into Drupal.',
    'aliases' => array(
      'am',
    ),
    'options' => array(
      'nostage'   => 'Only processes the existing staging table.',
      'nosave'    => 'When processing the staging table do not actually save new file data.',
      'onlystage' => 'Only build the staging table.',
    ),
    'arguments' => array(
      'source' => 'Parent directory of the images library.',
    ),
    'examples' => array(
      'drush asset_migrate' => 'Blame Marcus for not righting this.',
    ),
    'drupal dependencies' => array(
    ),
    'core' => array('7'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function asset_migrate_drush_help($section) {
  switch ($section) {
    case 'drush:asset_migrate':
      return dt('Blame Marcus for not righting this.');
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate().
 */
function drush_asset_migrate_validate() {
  // Because of a bug in the way that Drush 4 computes the name of functions to
  // call from a Drush command, we may end up getting called twice, so we just
  // don't do anything on subsequent invocations.
  static $already_run = FALSE;
  if ($already_run) {
    return;
  }
  $already_run = TRUE;
}

/**
 * Drush command callback to export a views data to a file.
 *
 * @see drush_asset_migrate_validate().
 */
function drush_asset_migrate($source = 's3://IMAGES') {
  // Because of a bug in the way that Drush 4 computes the name of functions to
  // call from a Drush command, we may end up getting called twice, so we just
  // don't do anything on subsequent invocations.
  static $already_run = FALSE;
  if ($already_run) {
    return;
  }
  $already_run = TRUE;

  drush_print('Source: ' . $source);

  $onlystage = drush_get_option('onlystage');
  $nostage = drush_get_option('nostage');
  $nosave = drush_get_option('nosave');
  $save = empty($nosave);

  if ($onlystage && $nostage) {
    drush_print('Doing nothing.');
    return;
  }

  $batch = array(
    'operations'       => array(),
    'finished'         => 'asset_migrate_batch_finished',
    'title'            => t('Processing Example Batch'),
  );

  if (!$nostage) {
    $batch['operations'][] = array('asset_migrate_batch_stage_file_list', array($source));
  }

  if (!$onlystage) {
    $batch['operations'][] = array('asset_migrate_batch_manage_files', array($save));
    $batch['operations'][] = array('asset_migrate_batch_link_files', array());
  }

  batch_set($batch);
  $batch                =& batch_get();
  $batch['progressive'] = FALSE;

  // Process the batch.
  drush_backend_batch_process();
}
