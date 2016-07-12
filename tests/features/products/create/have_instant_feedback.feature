@api
Feature: Have Instant Feedback as I enter data
  As an Item Manager
  I want to be able to have instant feedback as I enter data
  So that I do not have to wait to submit the new product to see if the data I have provided is valid
  And I can correct my errors as I work instead of all at once.

  @wip
  Scenario: Invalid Item Number
    Given I am logged in as a user with the "Item Manager" role
    When I press "Create New Product"
    And I do not fill out "Item Number"
    Then I should see that the "Item Number" is invalid before I hit "Save"