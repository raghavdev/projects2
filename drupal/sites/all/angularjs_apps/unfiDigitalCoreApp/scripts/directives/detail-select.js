'use strict';

/*******************************************************************************************************
 * DETAIL SELECT
 *******************************************************************************************************
 */
app.directive('detailselect', function() {
    return {
        restrict: 'EA',
        scope: true,
        replace: true,
        templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-select.html',
        controller: function($scope, $element, $attrs, $compile, $http, $rootScope) {
          $scope.field_name = $attrs.detailselect;
          $scope.section_meta = $scope.meta.fields[$attrs.detailselect];
        },
        link: function(scope, elm, attrs) {
            scope.initValidation();
        }
    };
});


