'use strict';

/*******************************************************************************************************
 * SEARCH DIRECTIVE
 *******************************************************************************************************
 */
app.directive('filter', function($parse) {
  return {
    restrict: 'EA',
    scope: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/filter.html',
    controller: function($scope, $element, $attrs, model, utils) {

      $scope.filter = [];

      $scope.filters[$scope.view]().then(function(data) {
        $scope.filter = data;
      });

      $scope.filterName = $attrs.filterName;
    },
    link: function(scope, elm, attr) {

      scope.$watch('categories', function(newValue, oldValue) {
        scope.filter = newValue;
      }, true);

    }
  }
})
