'use strict';

/*******************************************************************************************************
 * SEARCH DIRECTIVE
 *******************************************************************************************************
 */
app.directive('listingmenu', function() {
  return {
    restrict: 'EA',
    scope:false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/listing-menu.html',
    controller: function($scope, $element, $attrs, user) {

      $scope.viewMode = 'list';

      var validViewMode = function(mode) {
        var valid = ['list', 'thumb']; // @todo don't hard code this?
        if (valid.indexOf(mode) !== -1) {
          return true;
        }
        return false;
      };

      $scope.loadViewMode = function(mode) {
        if (!validViewMode(mode)) {
          mode = 'list';
        }
        $scope.viewMode = mode;
        user.savePref('viewMode', mode);
      };

      user.getPref('viewMode').then(function(data) {
        if (!validViewMode(data)) {
          data = 'list';
        }
        $scope.viewMode = data;
      });

      $scope.loadViewModeTemplate = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/view-modes/'+$scope.viewMode+'.html';
      };
    }
  }
})
