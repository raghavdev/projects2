'use strict';

/*******************************************************************************************************
 * DETAIL TEXT INPUT
 *******************************************************************************************************
 */
app.directive('detailtextinput', function() {
    return {
        restrict: 'EA',
        scope: true,
        replace: true,
        templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-textinput.html',
        controller: function($scope, $element, $attrs, $compile) {
          $scope.field_name = $attrs.detailtextinput;
          $scope.section_meta = $scope.meta.fields[$attrs.detailtextinput];
        },
        link: function(scope, elm, attrs) {
            scope.initValidation();
        }
    };
});
