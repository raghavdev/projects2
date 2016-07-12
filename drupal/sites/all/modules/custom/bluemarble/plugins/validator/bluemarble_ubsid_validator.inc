<?php
/**
 * @file
 * Field validation UBS ID validator.
 *
 */
$plugin = array(
  'label' => t('UBS ID'),
  'description' => t('Verifies that user-entered values are valid UBS IDs.'),
  'handler' => array(
    'class' => 'bluemarble_ubsid_validator',
  ),
);

class bluemarble_ubsid_validator extends field_validation_validator {

  /**
   * Validate field.
   */
  public function validate() {
    $settings = $this->rule->settings;
    if ($this->value !== '' && !is_null($this->value)) {
      // Remove formatting characters
      $val = preg_replace('/[\s\-]/', '', $this->value);
      // Any character left that is not a number is an error.
      if (preg_match('/[^0-9]/', $val)) {
        $this->set_error();
      }
      else if (drupal_strlen($val) != 7) {
        $this->set_error();
      }
      else {
        $checkdigit = $this->calculate_checksum($val);
        if ($checkdigit != $val[6]) {
          $this->set_error();
        }
      }
    }
  }

  /**
   * UPC validate helper function.
   */
  function calculate_checksum($digits) {
    $even = 0;
    // Multiple the second, fourth and sixth digit by 2.
    foreach (array(1,3,5) as $i) {
      $b = $digits[$i] * 2;
      // If the result is more then 9, we need to subtract 10 and add 1
      // aka: add the digits of the two digit number together.
      if ($b > 9) {
        $b = $b - 9; // = b - 10 + 1
      }
      // Add the second, fourth and sixth digits together
      $even += $b;
    }
    $odd = $digits[0] + $digits[2] + $digits[4];
    $total = $even + $odd;

    $checksum = $total % 10;
    if ($checksum != 0) {
      $checksum = 10 - $checksum;
    }
    return $checksum;
  }

}
