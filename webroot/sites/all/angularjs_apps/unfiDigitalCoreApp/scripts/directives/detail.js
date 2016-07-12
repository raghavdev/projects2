'use strict';

/*******************************************************************************************************
 DETAIL
 *******************************************************************************************************
 */
app.directive('detail', function() {
  return {
    restrict: 'EA',
    scope: false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail.html',
    controller: function($scope, $element, $attrs, model, $http, $timeout, user) {

      // The pointer for the current view template.
      $scope.currentDetailTemplate = {
        products: 'identifiers',
        assets: 'asset'
      };

      /**
       * GET DETAIL TEMPLATE
       *
       * @return {[type]} [description]
       */
      $scope.getDetailTemplate = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + '/views/details/' + $scope.view + '/' + $scope.currentDetailTemplate[$scope.view] + '.html';
      };

      /**
       * ON DETAIL TEMPLATE LOAD
       *
       * @return {[type]} [description]
       */
      $scope.onDetailTemplateLoaded = function() {

        //convert to array for easier comparision
        var data = Object.keys(user.getUserPerms()).map(function (k) {
          return user.getUserPerms()[k]
        });

        if (data.indexOf("edit blue marble " + $scope.view + " " + $scope.currentDetailTemplate[$scope.view] + " tab") !== -1) {
          $scope.nopermission = false;
        }
        else {
          $scope.nopermission = true;
        }
      };
    },
  }
})
