<?php
/**
 * @file
 * Field validation Current Year validator.
 *
 */
$plugin = array(
  'label' => t('Current year'),
  'description' => t('Verifies that user-entered value is the current year.'),
  'handler' => array(
    'class' => 'bluemarble_current_year_validator',
  ),
);

class bluemarble_current_year_validator extends field_validation_validator {

  /**
   * Validate field.
   */
  public function validate() {
    $settings = $this->rule->settings;
    if ($this->value !== '' && !is_null($this->value)) {
      if ($this->value != date('Y')) {
        $this->set_error();
      }
    }
  }

}
