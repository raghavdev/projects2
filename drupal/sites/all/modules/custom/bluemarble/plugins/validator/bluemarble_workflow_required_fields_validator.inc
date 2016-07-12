<?php
/**
 * @file
 * Field validation Workflow required fields validator.
 *
 */
$plugin = array(
  'label' => t('Required fields for Workflow state'),
  'description' => t('Verifies that required fields are not empty for given workflow state(s).'),
  'handler' => array(
    'class' => 'bluemarble_workflow_required_fields_validator',
  ),
);

class bluemarble_workflow_required_fields_validator extends field_validation_validator {

  /**
   * Flag to avoid infinite recursion since we call field_attach_validate()
   * which triggers field_validation classes.
   */
  static $call_count = 0;

  public function bypass_validation() {
    $bypass = parent::bypass_validation();
    // Bypass validation whenever the parent implementation does or if we are
    // being called recursively.
    if ($bypass || self::$call_count > 0) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Validate field.
   */
  public function validate() {
    self::$call_count++;

    $settings = $this->rule->settings;
    if ($this->value !== '' && !is_null($this->value)) {
      if (in_array($this->value, $settings['states'])) {
        $error_fields = array();
        foreach ($settings['fields'] as $field_name) {
          // Ignore fields that were not selected
          if (!$field_name) {
            continue;
          }
          // Fail safe to avoid an infinite loop.
          if ($this->rule->field_name == $field_name) {
            continue;
          }

          try {
            // The field is required, first check that
            if ($this->field_is_empty($field_name)) {
              throw new Exception('Required field is empty');
            }
            field_attach_validate($this->entity_type, $this->entity, array('field_name' => $field_name));
          }
          catch (FieldValidationException $e) {
            if (isset($e->errors[$field_name])) {
              throw $e;
            }
          }
          catch (Exception $e) {
            $info = field_info_instance($this->entity_type, $field_name, $this->rule->bundle);
            $error_fields[] = $info['label'];
          }
        }

        if (!empty($error_fields)) {
          $this->set_error(array('[fields]' => implode(', ', $error_fields)));
        }
      }
    }
  }

  /**
   * Check if a field is empty.
   */
  function field_is_empty($field_name) {
    $wrapper = entity_metadata_wrapper($this->entity_type, $this->entity);
    $val = $wrapper->$field_name->value();
    return empty($val);
  }

  /**
   * Provide settings option
   */
  function settings_form(&$form, &$form_state) {
    parent::settings_form($form, $form_state);

    $default_settings = $this->get_default_settings($form, $form_state);

    $states_options = $this->get_workflow_state_options($form, $form_state);
    $form['settings']['states'] = array(
      '#title' => t('States'),
      '#description' => t('Only the checked states will trigger this validation rule.'),
      '#type' => 'checkboxes',
      '#options' => $states_options,
      '#default_value' => isset($default_settings['states']) ? $default_settings['states'] : array(),
    );

    $field_options = $this->get_field_options($form, $form_state);
    $form['settings']['fields'] = array(
      '#title' => t('Required fields'),
      '#description' => t('These fields will be required and must pass all validation.'),
      '#type' => 'checkboxes',
      '#options' => $field_options,
      '#default_value' => isset($default_settings['fields']) ? $default_settings['fields'] : array(),
    );
  }

  /**
   * Get list of workflow states suitable for form #options.
   */
  function get_workflow_state_options($form, $form_state) {
    $rule = isset($form_state['item']) ? $form_state['item'] : new stdClass();
    $field_name = isset($rule->field_name) ? $rule->field_name : $form['field_name']['#value'];

    $info = field_info_field($field_name);
    $workflow = workflow_load($info['settings']['wid']);
    $states = $workflow->getStates();

    $options = array();
    foreach ($states as $state) {
      $options[$state->sid] = $state->state;
    }

    return $options;
  }

  /**
   * Get list of field names suitable for form #options.
   */
  function get_field_options($form, $form_state) {
    $rule = isset($form_state['item']) ? $form_state['item'] : new stdClass();
    $field_name = isset($rule->field_name) ? $rule->field_name : $form['field_name']['#value'];
    $entity_type = isset($rule->entity_type) ? $rule->entity_type : $form['entity_type']['#value'];
    $bundle = isset($rule->bundle) ? $rule->bundle : $form['bundle']['#value'];

    $fields = field_info_instances($entity_type, $bundle);

    $options = array();
    foreach ($fields as $field_info) {
      $options[$field_info['field_name']] = $field_info['label'];
    }
    // Do not include this field.
    unset($options[$field_name]);

    return $options;
  }

}
