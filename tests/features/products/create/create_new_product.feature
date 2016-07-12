@api
Feature: Create a New Product
  As an Item Manager
  I want to be able to create a new product
  So that I can edit and create products in the same interface.

  @wip
  Scenario: Save Product as Item Manager
    Given I am logged in as a user with the "Item Manager" role
    When I press "Create New Product"
    And fill out the New Product form
    And I press "Save"
    Then the product should show up in the product list