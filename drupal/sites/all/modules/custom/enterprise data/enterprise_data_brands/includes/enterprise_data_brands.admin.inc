<?php
/**
 * @file
 *
 * Administration forms for creating, editing, and removing brands.
 */

/**
 *
 */
function enterprise_data_brands_admin_form($form, &$form_state) {

  // TODO: simply a form for Pending Approval

  // Horizontal tabs container
  $form['group_tabs'] = array(
    '#type'     => 'horizontal_tabs',
    '#attached' => array(
      'library' => array(
        array('field_group', 'horizontal-tabs'), // Converts fieldsets into tabs
      ),
    ),
  );

  //Enterprise Brands form
  //////////////////////////////////////////////////////////////////////////

  $form['enterprise'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Enterprise Brands'),
    '#group' => 'group_tabs',
  );

  //East Brands form
  //////////////////////////////////////////////////////////////////////////

  $form['east'] = array(
    '#type'  => 'fieldset',
    '#title' => t('East Brands'),
    '#group' => 'group_tabs',
  );

  //West Brands form
  //////////////////////////////////////////////////////////////////////////

  $form['west'] = array(
    '#type'  => 'fieldset',
    '#title' => t('West Brands'),
    '#group' => 'group_tabs',
  );

  //Items form
  //////////////////////////////////////////////////////////////////////////

  $form['items'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Items'),
    '#group' => 'group_tabs',
  );

  //Pending Approval form
  //////////////////////////////////////////////////////////////////////////

  $form['pending'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Pending Approval'),
    '#group' => 'group_tabs',
  );

  return $form;
}
