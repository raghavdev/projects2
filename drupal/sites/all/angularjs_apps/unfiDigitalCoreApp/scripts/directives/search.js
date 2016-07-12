'use strict';

/*******************************************************************************************************
 * SEARCH DIRECTIVE
 *******************************************************************************************************
 */
app.directive('search', function() {
  return {
    restrict: 'EA',
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/search.html',
    controller: function($scope, $element, $attrs) {
      $scope.getSearchTemplate = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/search/'+$scope.view+'/search.html';
      };

      $scope.clearSelection = function() {
        $scope.search[$scope.view].search = null;
        $scope.query();
      };

      //clear out the search parameters that are applied
      $scope.clearSearch = function() {

        if($scope.view == "assets") {

          //kill the search parameters
          if($scope.search[$scope.view].asset_category) {
            $scope.search[$scope.view].asset_category.categories = [];
            $scope.search[$scope.view].asset_category.qualifier = 1;
          }

          if($scope.search[$scope.view].asset_dates) {
            $scope.search[$scope.view].asset_dates.end = null;
            $scope.search[$scope.view].asset_dates.option = null;
            $scope.search[$scope.view].asset_dates.qualifier = 1;
            $scope.search[$scope.view].asset_dates.start = null;
          }

          if($scope.search[$scope.view].asset_name) {
            $scope.search[$scope.view].asset_name.keywords = null;
            $scope.search[$scope.view].asset_name.parameter = null;
            $scope.search[$scope.view].asset_name.qualifier = 1;
          }

          if($scope.search[$scope.view].collection) {
            $scope.search[$scope.view].collection.nid = null;
          }

          if($scope.search[$scope.view].file_extension) {
            $scope.search[$scope.view].file_extension.qualifier = 1;
            $scope.search[$scope.view].file_extension.types = [];
          }

          if($scope.search[$scope.view].internal_only) {
            $scope.search[$scope.view].internal_only.enabled = false;
            $scope.search[$scope.view].internal_only.qualifier = 1;
          }
          $scope.search[$scope.view].search = '';

//          if(!$scope.search[$scope.view].sort) {
//            $scope.search[$scope.view].sort_dir = 'ASC';
//            $scope.search[$scope.view].sort = 'title';
//          }

          //call the query with no arguments
          $scope.query();
        }
        else if ($scope.view == "products") {
          if($scope.search[$scope.view].brand) {
            $scope.search[$scope.view].brands = [];
            $scope.search[$scope.view].qualifier = 1;
          }

          if($scope.search[$scope.view].category) {
            $scope.search[$scope.view].category.categories = [];
            $scope.search[$scope.view].category.qualifier = 1;
          }


          if($scope.search[$scope.view].description) {
            $scope.search[$scope.view].description.enabled = false;
            $scope.search[$scope.view].description.qualifier = 1;
          }

          if($scope.search[$scope.view].has_primary_image) {
            $scope.search[$scope.view].has_primary_image.enabled = false;
            $scope.search[$scope.view].has_primary_image.qualifier = 1;
          }

          if($scope.search[$scope.view].product_dates) {
            $scope.search[$scope.view].product_dates.qualifier = 1;
            $scope.search[$scope.view].product_dates.option = 1;
            $scope.search[$scope.view].product_dates.end = null;
            $scope.search[$scope.view].product_dates.start = null;
          }

          if($scope.search[$scope.view].title) {
            $scope.search[$scope.view].title.keywords = false;
            $scope.search[$scope.view].title.parameter = false;
            $scope.search[$scope.view].title.qualifier = 1;
          }

          if($scope.search[$scope.view].search) {
            $scope.search[$scope.view].search = null;
          }

          if(!$scope.search[$scope.view].sort) {
            $scope.search[$scope.view].sort_dir = 'ASC';
            $scope.search[$scope.view].sort = 'title';
          }

          //call the query with no arguments
          $scope.query();
        }
      };


      $scope.clearSearch();
    }
  };
});
