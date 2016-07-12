'use strict';

/*******************************************************************************************************
 * DETAIL LIST
 *******************************************************************************************************
 */
app.directive('detaillist', function() {
  return {
    restrict: 'EA',
    scope: false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail-list.html',
    controller: function($scope, $element, $attrs, $compile) {

      //TODO this is a bit more complex than just looping the meta data
      $scope.section_meta = $scope.meta[$scope.view].detail_pane[$attrs.section][$attrs.detaillist];
    },
    link: function(scope, elm, attrs) {
      scope.initValidation();
    }
  }
})
