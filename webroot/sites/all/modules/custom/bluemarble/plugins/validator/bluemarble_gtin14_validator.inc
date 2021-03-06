<?php
/**
 * @file
 * Field validation GTIN-14 validator.
 *
 */
$plugin = array(
  'label' => t('GTIN-14'),
  'description' => t('Verifies that user-entered values are valid GTIN-14 number.'),
  'handler' => array(
    'class' => 'bluemarble_gtin14_validator',
  ),
);

class bluemarble_gtin14_validator extends field_validation_validator {

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
      else if (drupal_strlen($val) > 14) {
        $this->set_error();
      }
      else {
        if (drupal_strlen($val) < 14) {
          $val = str_repeat('0', 14 - drupal_strlen($val)) . $val;
        }
        $checkdigit = $this->calculate_checksum($val);
        if ($checkdigit != $val[13]) {
          $this->set_error();
        }
      }
    }
  }

  /**
   * UPC validate helper function.
   */
  function calculate_checksum($digits) {
    $even = $digits[1] + $digits[3] + $digits[5] + $digits[7] + $digits[9] + $digits[11];
    $odd = $digits[0] + $digits[2] + $digits[4] + $digits[6] + $digits[8] + $digits[10] + $digits[12];
    $odd = $odd * 3;
    $total = $even + $odd;
    $checksum = $total % 10;
    if ($checksum != 0) {
      $checksum = 10 - $checksum;
    }
    return $checksum;
  }

}
