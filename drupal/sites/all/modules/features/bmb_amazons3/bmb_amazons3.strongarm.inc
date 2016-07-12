<?php
/**
 * @file
 * bmb_amazons3.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bmb_amazons3_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amazons3_presigned_urls';
  $strongarm->value = '300000000|watermarked/*
1209600|*';
  $export['amazons3_presigned_urls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'amazons3_useprivate';
  $strongarm->value = 1;
  $export['amazons3_useprivate'] = $strongarm;

  return $export;
}
