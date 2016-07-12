'use strict';

/*******************************************************************************************************
 * DETAIL TABLE
 *******************************************************************************************************
 */
app.directive('detailtextarea', function() {
  return {
    restrict: 'EA',
    scope: true,
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-textarea.html',
    controller: function($scope, $element, $attrs, $compile) {

      $scope.field_name = $attrs.detailtextarea;
      $scope.section_meta = $scope.meta.fields[$attrs.detailtextarea];

      if($scope.record[$scope.section_meta.record]) {
        $scope.characterCount = $scope.record[$scope.section_meta.record].length;
      }
      else {
        $scope.characterCount = 0;
      }

      $scope.updateCount = function() {
        if($scope.record[$scope.section_meta.record].length >= $scope.section_meta.max_chars) {
          //prevent breaking the max char list
          $scope.record[$scope.section_meta.record].length = $scope.record[$scope.section_meta.record].length.substring(0, $scope.section_meta.max_chars)
        }
        $scope.characterCount = $scope.record[$scope.section_meta.record].length;
      }
    },
    link: function(scope, elm, attrs) {
      scope.initValidation();
    }
  }
})
