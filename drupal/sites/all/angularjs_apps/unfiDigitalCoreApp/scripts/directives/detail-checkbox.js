'use strict';

/*******************************************************************************************************
 * DETAIL CHECKBOX
 *******************************************************************************************************
 */
app.directive('detailcheckbox', function() {
    return {
        restrict: 'EA',
        scope: true,
        replace: true,
        templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-boolean.html',
        controller: function($scope, $element, $attrs, $compile) {
          $scope.field_name = $attrs.detailcheckbox;
          $scope.section_meta = $scope.meta.fields[$attrs.detailcheckbox];
        },
        link: function(scope, elm, attrs) {
            scope.initValidation();
        }
    };
});

