<?php

/**
 * Override or insert variables into the maintenance page template.
 */
function unfi_admin_preprocess_maintenance_page(&$vars) {
  // While markup for normal pages is split into page.tpl.php and html.tpl.php,
  // the markup for the maintenance page is all in the single
  // maintenance-page.tpl.php template. So, to have what's done in
  // unfi_admin_preprocess_html() also happen on the maintenance page, it has to be
  // called here.
  unfi_admin_preprocess_html($vars);
}
/**
 * Implements hook_html_head_alter().
 */
function unfi_admin_html_head_alter(&$head_elements) {
  $head_elements['viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width,initial-scale=1,maximum-scale=1,user-scalable=0'),
  );
}

/**
 * Override or insert variables into the html template.
 */
function unfi_admin_preprocess_html(&$vars) {
  // Add conditional CSS for IE8 and below.
  drupal_add_css(path_to_theme() . '/styles/ie/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
  // Add conditional CSS for IE7 and below.
  drupal_add_css(path_to_theme() . '/styles/ie/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
  // Add conditional CSS for IE6.
  drupal_add_css(path_to_theme() . '/styles/ie/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 6', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
}

/**
 * Override or insert variables into the page template.
 */
function unfi_admin_process_page(&$vars) {
  if (theme_get_setting('display_breadcrumbs') == 1) {
    unset($vars['breadcrumb']);
  }
}

/**
 * Display the list of available node types for node creation.
 */
function unfi_admin_node_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="clearfix">';
      $output .= '<span class="label">' . l($item['title'], $item['href'], $item['localized_options']) . '</span>';
      $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  else {
    $output = '<p>' . t('You have not created any content types yet. Go to the <a href="@create-content">content type creation page</a> to add a new content type.', array('@create-content' => url('admin/structure/types/add'))) . '</p>';
  }
  return $output;
}

/**
 * Overrides theme_admin_block_content().
 *
 * Use unordered list markup in both compact and extended mode.
 */
function unfi_admin_admin_block_content($variables) {
  $content = $variables['content'];
  $output = '';
  if (!empty($content)) {
    $output = system_admin_compact_mode() ? '<ul class="admin-list compact">' : '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li class="leaf">';
      $output .= l($item['title'], $item['href'], $item['localized_options']);
      if (isset($item['description']) && !system_admin_compact_mode()) {
        $output .= '<div class="description">' . filter_xss_admin($item['description']) . '</div>';
      }
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 * Override of theme_tablesort_indicator().
 *
 * Use our own image versions, so they show up as black and not gray on gray.
 */
function unfi_admin_tablesort_indicator($variables) {
  $style = $variables['style'];
  $theme_path = drupal_get_path('theme', 'unfi_admin');
  if ($style == 'asc') {
    return theme('image', array('path' => $theme_path . '/images/arrow-asc.png', 'alt' => t('sort ascending'), 'width' => 13, 'height' => 13, 'title' => t('sort ascending')));
  }
  else {
    return theme('image', array('path' => $theme_path . '/images/arrow-desc.png', 'alt' => t('sort descending'), 'width' => 13, 'height' => 13, 'title' => t('sort descending')));
  }
}

/**
 * Implements hook_css_alter().
 */
function unfi_admin_css_alter(&$css) {
  // Use unfi_admin's vertical tabs style instead of the default one.
  if (isset($css['misc/vertical-tabs.css'])) {
    $css['misc/vertical-tabs.css']['data'] = drupal_get_path('theme', 'unfi_admin') . '/styles/vertical-tabs.css';
  }
  if (isset($css['misc/vertical-tabs-rtl.css'])) {
    $css['misc/vertical-tabs-rtl.css']['data'] = drupal_get_path('theme', 'unfi_admin') . '/styles/vertical-tabs-rtl.css';
  }
  // Use unfi_admin's jQuery UI theme style instead of the default one.
  if (isset($css['misc/ui/jquery.ui.theme.css'])) {
    $css['misc/ui/jquery.ui.theme.css']['data'] = drupal_get_path('theme', 'unfi_admin') . '/styles/jquery.ui.theme.css';
  }
}

/**
 * Implements hook_preprocess_page().
 */
function unfi_admin_preprocess_page(&$variables) {
  if (user_is_anonymous() && arg(0) == 'user') {
    $variables['theme_hook_suggestions'][] = 'page__user__anonymous';
  }
}
