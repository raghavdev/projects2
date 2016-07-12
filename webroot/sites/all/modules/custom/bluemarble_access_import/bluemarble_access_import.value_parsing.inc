<?php

/**
 * Map a default value provided from the mapping custom processing arguments.
 *
 * @param $value
 * @param $direction
 * @param $wrapper
 * @param array $context
 * @return null
 */
function bluemarble_access_import_map_default_value($value, $direction, $wrapper, $context = array()) {
  if (isset($context['mapping']->customProcessingArgs['default_value'])) {
    return $context['mapping']->customProcessingArgs['default_value'];
  }
  return NULL;
}

/**
 * Map boolean between Access database and Drupal.
 *
 * @param mixed $value
 * @param string $direction
 * @param EntityDrupalWrapper $wrapper
 * @param array $context
 * @return mixed entity_metadata_wrapper->{$field}->set() friendly data
 */
function bluemarble_access_import_map_boolean($value, $direction, $wrapper, $context = array()) {
  $value = trim(drupal_strtolower($value));
  if ((int) $value === -1 && (float) $value === -1.0) {
    return TRUE;
  }
  elseif (!empty($context['not_strict']) && !empty($value) && $value != 'null') {
    return TRUE;
  }
  return FALSE;
}

/**
 * Maps entity reference fields from CSV data.
 *
 * @see _bluemarble_access_import_map_entityreference_search
 * @see _bluemarble_access_import_map_entityreference_search_field_info
 *
 * @param mixed $value
 * @param string $direction
 * @param EntityDrupalWrapper $wrapper
 * @param array $context
 * @return mixed entity_metadata_wrapper->{$field}->set() friendly data
 */
function bluemarble_access_import_map_entityreference_field($value, $direction, $wrapper, $context = array()) {
  if (
    $direction != 'import'
    || empty($context['mapping'])
    || !is_object($context['mapping'])
    || empty($context['mapping']->toField)
    || !($field = field_info_field($context['mapping']->toField))
    || empty($field['settings']['target_type'])
    || empty($field['settings']['handler_settings']['target_bundles'])
    // Simple check to see if the bundle actually has the field. This should be
    // cached from the processing the wrapper.
    || !($instance = field_info_instance($wrapper->type(), $context['mapping']->toField, $wrapper->getBundle()))
  ) {
    return NULL;
  }

  $entity_type      = $field['settings']['target_type'];
  $context['field'] = $field;
  $mapping          = $context['mapping'];

  $search_field = _bluemarble_access_import_map_entityreference_search_field_info($mapping, $entity_type);
  if (!$search_field) {
    return NULL;
  }

  $context['entity_type'] = $entity_type;

  foreach ($field['settings']['handler_settings']['target_bundles'] as $bundle) {
    $entity = _bluemarble_access_import_map_entityreference_search($value, $search_field, $context);
    if ($entity) {
      return $entity;
    }
  }
  return NULL;
}

/**
 * Parse out a number.
 *
 * @param mixed $value
 * @param string $direction
 * @param EntityDrupalWrapper $wrapper
 * @param array $context
 * @return mixed entity_metadata_wrapper->{$field}->set() friendly data
 */
function bluemarble_access_import_map_regex_number($value, $direction, $wrapper, $context) {
  $args = $context['mapping']->customProcessingArgs;
  if (isset($args['typecast'])) {
    $typecast = $args['typecast'];
  }
  else {
    $typecast = '';
  }
  if (
    isset($args['preg_match_key'])
    && is_numeric($args['preg_match_key'])
  ) {
    $match_index = (int) $args['preg_match_key'];
  }
  else {
    $match_index = 0;
  }
  // @todo: more could be done as far as strictness of the preg_match
  $matches = NULL;
  if (preg_match_all('/(\d*\.?\d+)/', $value, $matches)) {
    $match = $matches[1];
    if (isset($match[$match_index])) {
      switch ($typecast) {
        default:
          return $match[$match_index];
        case 'int':
        case 'integer':
        case 'whole':
          return (int) $match[$match_index];
        case 'float':
        case 'decimal':
          return (float) $match[$match_index];
        case 'double':
          return (double) $match[$match_index];
        case 'string':
          return (string) $match[$match_index];
      }
    }
  }
  return NULL;
}

/**
 * Parse out a number with a (matching) unit of measure that follows.
 *
 * @param mixed $value
 * @param string $direction
 * @param EntityDrupalWrapper $wrapper
 * @param array $context
 * @return mixed entity_metadata_wrapper->{$field}->set() friendly data
 */
function bluemarble_access_import_map_regex_number_with_uom($value, $direction, $wrapper, $context = array()) {
  if (isset($context['mapping']->customProcessingArgs['uom_field_name'])) {
    $uom_field_name = $context['mapping']->customProcessingArgs['uom_field_name'];
  }
  elseif (strpos($context['mapping']->toField, '_value') !== FALSE) {
    $uom_field_name = str_replace('_value', '', $context['mapping']->toField) . '_uom';
  }
  elseif (strpos($context['mapping']->toField, '_uom') !== FALSE) {
    $uom_field_name = $context['mapping']->toField;
  }
  else {
    return NULL;
  }

  $field_info = field_info_field($uom_field_name);
  if (empty($field_info['settings']['allowed_values'])) {
    // @todo: watchdog warning?
    return NULL;
  }

  if (empty($context['mapping']->customProcessingArgs['preg_match_key'])) {
    $context['mapping']->customProcessingArgs['preg_match_key'] = strpos($context['mapping']->toField, '_uom') === FALSE ? 1 : 2;
  }

  $uom_regex = '(' . implode('|', $field_info['settings']['allowed_values']) . ')';
  $matches   = NULL;
  if (preg_match('/(\d*\.?\d+)[ ]*' . $uom_regex . '/', $value, $matches)) {
    return $matches[$context['mapping']->customProcessingArgs['preg_match_key']];
  }
  return NULL;
}

/*
 * ==== Specific parsing functions ==== ---- ---- ---- ---- ---- ---- ---- ----
 */

/**
 * Map uom between Access database and Drupal.
 */
function bluemarble_access_import_map_item_size_uom($value, $direction, $wrapper, $context = array()) {
  // Array mapping access values => drupal values
  $map = array(
    '#' => 'count',
    '1.1 oz (32' => 'oz',
    'bars' => 'bars',
    'bx' => 'box',
    'case' => 'case',
    'cases' => 'case',
    'cs' => 'case',
    'ct' => 'count',
    'cu in' => 'cubic inches',
    'dz' => 'dozen',
    'ea' => 'each',
    'each' => 'each',
    'fl oz' => 'fl oz',
    'gal' => 'gal',
    'kg' => 'kg',
    'l' => 'liter',
    'lb' => 'lb',
    'litre' => 'liter',
    'lt' => 'liter',
    'ml' => 'ml',
    'null' => NULL,
    'oz' => 'oz',
    'pack' => 'pack',
    'pc' => 'piece',
    'pck' => 'pack',
    'pcs' => 'piece',
    'pk' => 'pack',
    'roll' => 'roll',
    'sleeve' => 'sleeve',
    'tins/bx' => 'box',
    'units' => 'count',
  );

  $field = field_info_field('field_item_size_uom');
  $allowed_values = array();
  if (!empty($field['settings']['allowed_values'])) {
    $allowed_values = $field['settings']['allowed_values'];
  }

  $ret = NULL;
  $value = strtolower(trim($value));
  if (isset($map[$value])) {
    $find = strtolower($map[$value]);
    if (empty($allowed_values) || isset($allowed_values[$find])) {
      $ret = $find;
    }
    else {
      watchdog('bluemarble_access_import', 'Access import of Item Size UOM ($value = @v) does not match any actual allowed value.', array('@v' => $find), WATCHDOG_WARNING);
    }
  }

  return $ret;
}

/**
 * Map "X Free" fields between Access database and Drupal taxonomy terms.
 */
function bluemarble_access_import_map_free_of_attribute($value, $direction, $wrapper, $context = array()) {
  $value = bluemarble_access_import_map_boolean($value, $wrapper, $context);
  $matches = NULL;
  if ($value && preg_match('/Is([A-Z]+[a-z]+)+Free', $context['fromField'], $matches)) {
    array_shift($matches);
    $value = implode(' ', $matches);
    return bluemarble_access_import_map_entityreference_field($value, $direction, $wrapper, $context);
  }
  return NULL;
}

/**
 * Map product intro date between Access database and Drupal.
 */
function bluemarble_access_import_map_product_intro_date($value) {
  if (strpos($value, '/')) {
    $date_arr = explode('/', $value);
    $month = $date_arr[0];
    if (count($date_arr)) {
      $year = $date_arr[2];
    }
    else {
      $year = $date_arr[1];
    }
    $year = (int) $year;
    if ($year < 16) {
      $year = "20" . str_pad($year, 2, "0", STR_PAD_LEFT);
    }
    elseif ($year < 1900) {
      $year = "19" . $year;
    }
    $month = str_pad($month, 2, "0", STR_PAD_LEFT);
    return "$year-$month-01";
  }
  return NULL;
}

/**
 * Map product category between Access database and Drupal.
 *
 * Use this with entityreference mapping, but...
 * @see _bluemarble_access_import_map_entityreference_search_field_info
 */
function _bluemarble_access_import_map_product_category_preprocess(&$value, $direction, $wrapper, $context) {
  // Map of Access values to Macola values
  $map  = array(
    'bbq sauce'          => 'BBQ',
    'beverage, misc mix' => 'BM',
  );
  $temp = strtolower($value);
  if (isset($map[$temp])) {
    $value = $map[$temp];
  }
}

/**
 * Map bottle bill states between Access database and Drupal.
 *
 * Use this with entityreference mapping, but...
 * @see _bluemarble_access_import_map_entityreference_search_field_info
 */
function bluemarble_access_import_map_bottle_bill_states(&$value, $direction, $wrapper, $context) {
  $map = array(
    'CA' => 'California',
    'CT' => 'Connecticut',
    'DE' => 'Delaware',
    'HI' => 'Hawaii',
    'IA' => 'Iowa',
    'ME' => 'Maine',
    'MA' => 'Massachusetts',
    'MI' => 'Michigan',
    'NV' => 'Nevada',
    'NY' => 'New York',
    'OR' => 'Oregon',
    'VT' => 'Vermont',
  );
  $temp = trim(drupal_strtoupper($value));
  if (isset($map[$temp])) {
    $value = $map[$temp];
  }
  $ret = NULL;
  if (!empty($value)) {
    $ret = array();
    $states = preg_split('/[\s,]+/', $value);
    foreach ($states as $state) {
      $state = trim($state);
      if (!empty($state)) {
        if (isset($map[$state])) {
          $ret[] = $map[$state];
        }
        else {
          watchdog('bluemarble_access_import', 'Missing state @state for bottle bill states.', array('@state' => $state));
        }
      }
    }
  }
  return $ret;
}

/*
 * ==== Support functions ==== ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
 */

function _bluemarble_access_import_map_entityreference_search($needle, $search_field_info, $context) {
  if (!empty($search_field_info['preprocess']) && function_exists($search_field_info['preprocess'])) {
    $search_field_info['preprocess']($needle, $search_field_info, $context);
  }

  $entity_type = $context['field']['settings']['target_type'];

  $query = db_select($search_field_info['table'], 'tbl');
  $query->fields('tbl', array($search_field_info['id']));
  $query->condition('tbl.' . $search_field_info['name'], $needle);

  if (!empty($search_field_info['query_alter']) && function_exists($search_field_info['query_alter'])) {
    $search_field_info['query_alter']($query, $needle, $search_field_info, $context);
  }

  $results = $query->execute();

  $entity = NULL;
  if (($id = $results->fetchField())) {
    $entity = entity_load_single($entity_type, $id);
  }

  if (!empty($search_field_info['postprocess']) && function_exists($search_field_info['postprocess'])) {
    $search_field_info['postprocess']($entity, $needle, $search_field_info, $context);
  }

  if (empty($entity) && !is_null($entity)) {
    $entity = NULL;
  }

  return $entity;
}

function _bluemarble_access_import_map_entityreference_search_field_info($mapping, $entity_type) {
  if (
    !empty($mapping->customProcessingArgs['search_field']['name'])
    && !empty($mapping->customProcessingArgs['search_field']['table'])
    && !empty($mapping->customProcessingArgs['search_field']['id'])
  ) {
    $search_field = $mapping->customProcessingArgs['search_field'];
  }
  else {
    switch ($entity_type) {
      case 'node':
        $search_field = array(
          'name'  => 'title',
          'table' => 'node',
          'id'    => 'nid',
        );
        break;
      case 'taxonomy_term':
        $search_field = array(
          'name'  => 'name',
          'table' => 'taxonomy_term_data',
          'id'    => 'tid',
        );
        break;
      default:
        return FALSE;
    }
  }
  return $search_field + array(
    'preprocess'  => NULL,
    'query_alter' => NULL,
    'postprocess' => NULL,
  );
}
