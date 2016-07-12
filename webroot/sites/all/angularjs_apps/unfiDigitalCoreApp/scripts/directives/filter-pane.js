'use strict';

/*******************************************************************************************************
 * FILTER PANE DIRECTIVE
 *******************************************************************************************************
 */
app.directive('filterpane', function() {
  return {
    restrict: 'EA',
    scope:false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/filter-pane.html',
    controller: function($scope, $element, $attrs, $http) {


      $scope.getFilterPaneTemplates = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/filters/'+$scope.view+'.html';
      };
    }
  };
});
