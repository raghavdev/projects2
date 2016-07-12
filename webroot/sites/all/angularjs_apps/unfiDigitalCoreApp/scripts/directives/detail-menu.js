'use strict';

var app, Drupal;

/*******************************************************************************************************
 * SEARCH DIRECTIVE
 *******************************************************************************************************
 */
app.directive('detailmenu', function () {
  return {
    restrict: 'EA',
    scope: false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail-menu.html',
    controller: function ($scope, $element, $attrs, $compile, user) {

      $scope.menuMap = {assets: [], products: []};

      //convert to array for easier comparison
      var data = Object.keys(user.getUserPerms()).map(function (k) {
        return user.getUserPerms()[k];
      });

      //check the permissions and show the tabs that are allowed
      //setting all to product until we learn more

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Product Identifiers', view: 'identifiers'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Master Basics', view: 'item-master-basics'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Dimensions & Weights', view: 'dimensions-weights'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Shelf Life', view: 'shelf-life-info'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Loc. & Freight', view: 'location-freight'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Vendor Info', view: 'vendor-info'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'SP Select Fields', view: 'supplier-portal-select-fields'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Product Basics', view: 'product-basics'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Categories', view: 'categories'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Product Info & Attrib.', view: 'product-info-and-attrib'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Certifications', view: 'certification'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Nutrition Data', view: 'nutrition'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Exports', view: 'exports'});
      }

      if (data.indexOf("access blue marble product tab") !== -1) {
        $scope.menuMap['products'].push({text: 'Macola Only', view: 'macola-transmit'});
      }

      /**
       * LOAD DETAIL TEMPLATE AND SET SELECTED ITEM
       * @param  {[type]} name [description]
       * @return {[type]}      [description]
       */
      $scope.selectedItem = 'identifiers';
      $scope.loadDetailTemplate = function() {
        $scope.currentDetailTemplate[$scope.view] = $scope.selectedItem;
      };
    }
  };
});
