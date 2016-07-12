<?php
/**
 * @file
 * bmb_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function bmb_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: watermarked.
  $styles['watermarked'] = array(
    'label' => 'watermarked',
    'effects' => array(
      4 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => '00',
          'alpha' => 100,
          'path' => 'module://bmb_image_styles/watermark.png',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: web_thumbnail.
  $styles['web_thumbnail'] = array(
    'label' => 'Web Thumbnail (216x216)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 216,
          'height' => 216,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
