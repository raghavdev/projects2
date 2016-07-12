'use strict';

/*******************************************************************************************************
 * ACTION PANE DIRECTIVE
 *******************************************************************************************************
 */
app.directive('actionpane', function() {
  return {
    restrict: 'EA',
    scope:false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/action-pane.html',
    controller: function($scope, $element, $attrs, $http) {
      $scope.actionPaneMenu = [];
      $scope.actionPaneMenu.push({text: 'Filter', view: 'filterpane'});
      $scope.actionPaneMenu.push({text: 'Search', view: 'searchadvanced'});
      $scope.selectedTab = 'filterpane'; // Default tab

      $scope.getFilterPaneTemplates = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/filters/'+$scope.view+'.html';
      };

      $scope.visibleTabSelect = function(tabName, index) {
        $scope.selectedTab = tabName;
        $scope.filterSelectedIndex = index;
      };
    }
  };
});
