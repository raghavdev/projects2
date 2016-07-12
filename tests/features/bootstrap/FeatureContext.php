<?php

use Drupal\DrupalExtension\Context\DrupalContext;

use Behat\Behat\Context\Step\Given,
    Behat\Behat\Context\Step\When,
    Behat\Behat\Context\Step\Then,
    Behat\Behat\Exception\PendingException;

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {

  /* ! User Handling methods */

  /**
   * Creates and authenticates a user with the given role via Drush.
   */
  public function assertAuthenticatedByRole($role) {
    $this->iAmLoggedInAsAUserWithTheRole('default', $role);
  }

  /**
   * @Given /^I am logged in as a "([^"]*)" user with the "([^"]*)" role$/
   *
   * "who" can be anything - it's a way to generate additional accounts, and refer back to them later.
   */
  public function iAmLoggedInAsAUserWithTheRole($who, $role) {
    // If a role is called for more than once, retrieve the previous account and re-use that one.
    if (isset($this->stashedUsers[$who][$role])) {
      // Only login again if we aren't already logged in as this user
      if ($this->stashedUsers[$who][$role]->name != $this->user->name) {
        $this->user = $this->stashedUsers[$who][$role];
        $this->login();
      }
    }
    else {
      parent::assertAuthenticatedByRole($role);
      $this->stashedUsers[$who][$role] = $this->user;
    }
  }

  /**
   * @Given /^userPop$/
   *
   * Internal - don't use this step in Feature files.
   */
  public function userPop() {
    $this->user = array_pop($this->userStack);
    $this->login();
  }

  /**
   * @Given /^userPush$/
   *
   * Internal - don't use this step in Feature files.
   */
  public function userPush() {
    array_push($this->userStack, $this->user);
  }

  /**
   * @Then /^I should see "([^"]*)" within "([^"]*)" seconds?$/
   */
  public function iShouldSeeWithinSeconds($text, $time) {
    $this->getSession()->wait($time * 1000,
      "jQuery(':contains(" . $text . ")').length > 0");
    $this->assertSession()->pageTextContains($text);
  }

  /* ! New Product methods */

  /**
   * @When /^(|I )fill out the New Product form$/
   *
   * Fills out required fields in the new product form.
   */
  public function fillOutNewProductForm() {
    return array(
      new Given('I enter "0123456" for "Item Number"'),
      new Given('I enter "BEHAT TEST PRODUCT" for "Item Description"'),
    );
  }

  /**
   * @Then /^the product should show up in the product list$/
   *
   * Checks for "BEHAT TEST PRODUCT"
   * @todo Make this work for other product titles and/or make a method
   *       to store the previously created product title.
   */
  public function productAppearsInList($title = "BEHAT TEST PRODUCT") {
    $this->iWaitForAjaxToFinish();
    return array(
      new Then('I should see "' . $title . '" in the "listing" region'),
    );
  }


  /* ! Helper methods */

  /**
   * @Given /^I do not fill out "([^"]*)"$/
   */
  public function iDoNotFillOut($field) {
    return array(
      new When('I fill in "" for "' . $field .'"'),
      new When('I wait for AJAX to finish'),
    );
  }

  /**
   * @Then /^I should see that (?:|the )"([^"]*)" is invalid.*$/
   */
  public function invalidInput($field) {
    $this->iWaitForAjaxToFinish();
    $element = $this->getSession()->getPage()->findField($field);
    if (!$element) {
      throw new Exception("Field '$field' not found");
    }

    if (!$element->hasClass('ng-invalid')) {
      throw new Exception("Field '$field' should be invalid");
    }
  }

  /**
   * Overrides DrupalContext::pressButton()
   */
  public function pressButton($button) {
    $this->iWaitForAjaxToFinish();
    parent::pressButton($button);
    $this->iWaitForAjaxToFinish();
  }

  /**
   * Overrides DrupalContext::assertRegionText()
   */
  public function assertRegionText($text, $region) {
    $this->iWaitForAjaxToFinish();
    parent::assertRegionText($text, $region);
  }

  /**
   * Overrides DrupalContext::iWaitForAjaxToFinish()
   */
  public function iWaitForAjaxToFinish() {
    $this->getSession()->evaluateScript('window.behatAjaxing=window.behatAjaxing||0;app.provider().factory("behatHttpInterceptor", ["$q", function($q) {
      return {
        "request": function(config){
          window.behatAjaxing++;
          return config;
        },
        "response":function(response){
          window.behatAjaxing--;
          return response;
        }
      };
    }]);');
    $this->getSession()->wait(5000, 'window.behatAjaxing<=0');
    parent::iWaitForAjaxToFinish();
  }
}
