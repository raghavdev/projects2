@api
Feature: Basic account management
  As a user
  I want to be able to log in and edit my account settings
  So that I can

  Scenario: Item Manager User can Log In
    Given I am logged in as a user with the "Item Manager" role
    Then I should see the link "Profile"
    And I should see the link "Help"

  Scenario: Item Manager User can edit account
    Given I am logged in as a user with the "Item Manager" role
    When I click "Profile"
    Then I should see "E-mail address"
    And I should see the link "Request new password"
