<?php
/**
 * @file
 * Field validation UPC Code - Macola validator.
 *
 * TODO: could be renamed and abstracted out with some settings added
 *
 */
$plugin = array(
  'label' => t('UPC Code - Macola'),
  'description' => t('Verifies that the selected UPC field has data.'),
  'handler' => array(
    'class' => 'bluemarble_upc_code_macola_validator',
  ),
);

class bluemarble_upc_code_macola_validator extends field_validation_validator {

  /**
   * Validate field.
   */
  public function validate() {
    if (!empty($this->value) && $this->value != 'field_case_upc') {
      $wrapper = entity_metadata_wrapper($this->entity_type, $this->entity);
      if (empty($wrapper->{$this->value})) {
        $this->set_error();
      }
      else {
        $other_value = $wrapper->{$this->value}->value();
        if (empty($other_value)) {
          $this->set_error();
        }
      }
    }
  }
}
