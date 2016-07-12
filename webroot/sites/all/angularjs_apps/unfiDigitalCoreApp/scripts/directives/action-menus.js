'use strict';

/*******************************************************************************************************
 * ACTION MENUS PANE DIRECTIVE
 *******************************************************************************************************
 */
app.directive('actionmenus', function() {
  return {
    restrict: 'EA',
    scope:false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/action-menus.html',
    controller: function($scope, $element, $attrs, $http) {

      $scope.getActionMenuTemplates = function() {
        if($scope.view) {
          return Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/action-menus/'+$scope.view+'.html';
        }
      };
    }
  };
});

