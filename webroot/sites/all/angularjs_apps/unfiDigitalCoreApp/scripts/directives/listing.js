'use strict';

/*******************************************************************************************************
 * SEARCH DIRECTIVE
 *******************************************************************************************************
 */
app.directive('listing', function() {
  return {
    restrict: 'EA',
    scope: false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/listing.html',
    controller: function($scope, $element, $attrs, utils) {

      $scope.listingSelected = function(r) {

        if($scope.record) {
          if(r.id == $scope.record.id) {
            //checkbox is checked when record is selected
            //r.actioncheckbox = true;
            //alas, there is no way to uncheck a box with this method. Disabling for now, but I want to revist
            return "selected";
          }
        }

        return "";
      }
    }
  }
})
