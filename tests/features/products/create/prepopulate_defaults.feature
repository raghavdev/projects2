@api
Feature: Prepopulate Default Values
  As an Item Manager
  I want to be able to have product common default values pre-populated
  So that I can fill out the form as efficiently as possible

  @wip
  Scenario: Prepopulate Mfg Method and Activity Code
    Given I am logged in as a user with the "Item Manager" role
    When I press "Create New Product"
    Then "Manufacturing Method" should default to "Order Entry"
    And "Activity Code" should default to "Active"