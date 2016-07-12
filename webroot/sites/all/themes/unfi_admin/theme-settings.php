<?php

/**
 * Implements THEME_form_system_theme_settings_alter().
 */
function unfi_admin_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['unfi_admin'] = array(
    '#type' => 'fieldset',
    '#title' => t('unfi_admin settings'),
    '#description' => t('Settings specific to unfi_admin theme.'),
  );
  $form['unfi_admin']['display_breadcrumbs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Toggle Breadcrumbs'),
    '#default_value' => theme_get_setting('display_breadcrumbs'),
    '#description' => t('If checked, breadcrumbs will not display'),
  );
  $form['unfi_admin']['unfi_admin_no_fadein_effect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Toggle fade-in effect'),
    '#default_value' => theme_get_setting('unfi_admin_no_fadein_effect'),
    '#description' => t('If checked, the fade-in effect will not occur.'),
  );
}
