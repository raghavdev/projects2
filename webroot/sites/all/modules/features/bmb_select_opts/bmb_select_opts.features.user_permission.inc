<?php
/**
 * @file
 * bmb_select_opts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bmb_select_opts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in agency_gluten_free'.
  $permissions['add terms in agency_gluten_free'] = array(
    'name' => 'add terms in agency_gluten_free',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in agency_organic'.
  $permissions['add terms in agency_organic'] = array(
    'name' => 'add terms in agency_organic',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in container_type'.
  $permissions['add terms in container_type'] = array(
    'name' => 'add terms in container_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in dietary_preference'.
  $permissions['add terms in dietary_preference'] = array(
    'name' => 'add terms in dietary_preference',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in ethnicity'.
  $permissions['add terms in ethnicity'] = array(
    'name' => 'add terms in ethnicity',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in free_of'.
  $permissions['add terms in free_of'] = array(
    'name' => 'add terms in free_of',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in freight_protection_from'.
  $permissions['add terms in freight_protection_from'] = array(
    'name' => 'add terms in freight_protection_from',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in freight_protection_level'.
  $permissions['add terms in freight_protection_level'] = array(
    'name' => 'add terms in freight_protection_level',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in gluten_content'.
  $permissions['add terms in gluten_content'] = array(
    'name' => 'add terms in gluten_content',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in gtin_type'.
  $permissions['add terms in gtin_type'] = array(
    'name' => 'add terms in gtin_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in life_dating_open'.
  $permissions['add terms in life_dating_open'] = array(
    'name' => 'add terms in life_dating_open',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in life_dating_type'.
  $permissions['add terms in life_dating_type'] = array(
    'name' => 'add terms in life_dating_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in major_allergen'.
  $permissions['add terms in major_allergen'] = array(
    'name' => 'add terms in major_allergen',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in manufacturing_method'.
  $permissions['add terms in manufacturing_method'] = array(
    'name' => 'add terms in manufacturing_method',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in non_gmo'.
  $permissions['add terms in non_gmo'] = array(
    'name' => 'add terms in non_gmo',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in organic_content'.
  $permissions['add terms in organic_content'] = array(
    'name' => 'add terms in organic_content',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in origin_country'.
  $permissions['add terms in origin_country'] = array(
    'name' => 'add terms in origin_country',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in origin_other'.
  $permissions['add terms in origin_other'] = array(
    'name' => 'add terms in origin_other',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in origin_state'.
  $permissions['add terms in origin_state'] = array(
    'name' => 'add terms in origin_state',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in payment_terms'.
  $permissions['add terms in payment_terms'] = array(
    'name' => 'add terms in payment_terms',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in processing_allergen'.
  $permissions['add terms in processing_allergen'] = array(
    'name' => 'add terms in processing_allergen',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in salt_content'.
  $permissions['add terms in salt_content'] = array(
    'name' => 'add terms in salt_content',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in secondary_allergen'.
  $permissions['add terms in secondary_allergen'] = array(
    'name' => 'add terms in secondary_allergen',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in sweetener'.
  $permissions['add terms in sweetener'] = array(
    'name' => 'add terms in sweetener',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in veg_type'.
  $permissions['add terms in veg_type'] = array(
    'name' => 'add terms in veg_type',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in whole_grain_stamp'.
  $permissions['add terms in whole_grain_stamp'] = array(
    'name' => 'add terms in whole_grain_stamp',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in agency_gluten_free'.
  $permissions['delete terms in agency_gluten_free'] = array(
    'name' => 'delete terms in agency_gluten_free',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in agency_organic'.
  $permissions['delete terms in agency_organic'] = array(
    'name' => 'delete terms in agency_organic',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in container_type'.
  $permissions['delete terms in container_type'] = array(
    'name' => 'delete terms in container_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in dietary_preference'.
  $permissions['delete terms in dietary_preference'] = array(
    'name' => 'delete terms in dietary_preference',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in ethnicity'.
  $permissions['delete terms in ethnicity'] = array(
    'name' => 'delete terms in ethnicity',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in free_of'.
  $permissions['delete terms in free_of'] = array(
    'name' => 'delete terms in free_of',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in freight_protection_from'.
  $permissions['delete terms in freight_protection_from'] = array(
    'name' => 'delete terms in freight_protection_from',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in freight_protection_level'.
  $permissions['delete terms in freight_protection_level'] = array(
    'name' => 'delete terms in freight_protection_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in gluten_content'.
  $permissions['delete terms in gluten_content'] = array(
    'name' => 'delete terms in gluten_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in gtin_type'.
  $permissions['delete terms in gtin_type'] = array(
    'name' => 'delete terms in gtin_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in life_dating_open'.
  $permissions['delete terms in life_dating_open'] = array(
    'name' => 'delete terms in life_dating_open',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in life_dating_type'.
  $permissions['delete terms in life_dating_type'] = array(
    'name' => 'delete terms in life_dating_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in major_allergen'.
  $permissions['delete terms in major_allergen'] = array(
    'name' => 'delete terms in major_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in manufacturing_method'.
  $permissions['delete terms in manufacturing_method'] = array(
    'name' => 'delete terms in manufacturing_method',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in non_gmo'.
  $permissions['delete terms in non_gmo'] = array(
    'name' => 'delete terms in non_gmo',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in organic_content'.
  $permissions['delete terms in organic_content'] = array(
    'name' => 'delete terms in organic_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in origin_country'.
  $permissions['delete terms in origin_country'] = array(
    'name' => 'delete terms in origin_country',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in origin_other'.
  $permissions['delete terms in origin_other'] = array(
    'name' => 'delete terms in origin_other',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in origin_state'.
  $permissions['delete terms in origin_state'] = array(
    'name' => 'delete terms in origin_state',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in payment_terms'.
  $permissions['delete terms in payment_terms'] = array(
    'name' => 'delete terms in payment_terms',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in processing_allergen'.
  $permissions['delete terms in processing_allergen'] = array(
    'name' => 'delete terms in processing_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salt_content'.
  $permissions['delete terms in salt_content'] = array(
    'name' => 'delete terms in salt_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in secondary_allergen'.
  $permissions['delete terms in secondary_allergen'] = array(
    'name' => 'delete terms in secondary_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in sweetener'.
  $permissions['delete terms in sweetener'] = array(
    'name' => 'delete terms in sweetener',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in veg_type'.
  $permissions['delete terms in veg_type'] = array(
    'name' => 'delete terms in veg_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in whole_grain_stamp'.
  $permissions['delete terms in whole_grain_stamp'] = array(
    'name' => 'delete terms in whole_grain_stamp',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in agency_gluten_free'.
  $permissions['edit terms in agency_gluten_free'] = array(
    'name' => 'edit terms in agency_gluten_free',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in agency_organic'.
  $permissions['edit terms in agency_organic'] = array(
    'name' => 'edit terms in agency_organic',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in container_type'.
  $permissions['edit terms in container_type'] = array(
    'name' => 'edit terms in container_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in dietary_preference'.
  $permissions['edit terms in dietary_preference'] = array(
    'name' => 'edit terms in dietary_preference',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in ethnicity'.
  $permissions['edit terms in ethnicity'] = array(
    'name' => 'edit terms in ethnicity',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in free_of'.
  $permissions['edit terms in free_of'] = array(
    'name' => 'edit terms in free_of',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in freight_protection_from'.
  $permissions['edit terms in freight_protection_from'] = array(
    'name' => 'edit terms in freight_protection_from',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in freight_protection_level'.
  $permissions['edit terms in freight_protection_level'] = array(
    'name' => 'edit terms in freight_protection_level',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in gluten_content'.
  $permissions['edit terms in gluten_content'] = array(
    'name' => 'edit terms in gluten_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in gtin_type'.
  $permissions['edit terms in gtin_type'] = array(
    'name' => 'edit terms in gtin_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in life_dating_open'.
  $permissions['edit terms in life_dating_open'] = array(
    'name' => 'edit terms in life_dating_open',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in life_dating_type'.
  $permissions['edit terms in life_dating_type'] = array(
    'name' => 'edit terms in life_dating_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in major_allergen'.
  $permissions['edit terms in major_allergen'] = array(
    'name' => 'edit terms in major_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in manufacturing_method'.
  $permissions['edit terms in manufacturing_method'] = array(
    'name' => 'edit terms in manufacturing_method',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in non_gmo'.
  $permissions['edit terms in non_gmo'] = array(
    'name' => 'edit terms in non_gmo',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in organic_content'.
  $permissions['edit terms in organic_content'] = array(
    'name' => 'edit terms in organic_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in origin_country'.
  $permissions['edit terms in origin_country'] = array(
    'name' => 'edit terms in origin_country',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in origin_other'.
  $permissions['edit terms in origin_other'] = array(
    'name' => 'edit terms in origin_other',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in origin_state'.
  $permissions['edit terms in origin_state'] = array(
    'name' => 'edit terms in origin_state',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in payment_terms'.
  $permissions['edit terms in payment_terms'] = array(
    'name' => 'edit terms in payment_terms',
    'roles' => array(
      'Manager' => 'Manager',
      'Supply Chain' => 'Supply Chain',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in processing_allergen'.
  $permissions['edit terms in processing_allergen'] = array(
    'name' => 'edit terms in processing_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salt_content'.
  $permissions['edit terms in salt_content'] = array(
    'name' => 'edit terms in salt_content',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in secondary_allergen'.
  $permissions['edit terms in secondary_allergen'] = array(
    'name' => 'edit terms in secondary_allergen',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in sweetener'.
  $permissions['edit terms in sweetener'] = array(
    'name' => 'edit terms in sweetener',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in veg_type'.
  $permissions['edit terms in veg_type'] = array(
    'name' => 'edit terms in veg_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in whole_grain_stamp'.
  $permissions['edit terms in whole_grain_stamp'] = array(
    'name' => 'edit terms in whole_grain_stamp',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
