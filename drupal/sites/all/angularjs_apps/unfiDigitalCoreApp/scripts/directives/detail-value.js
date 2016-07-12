'use strict';

/*******************************************************************************************************
 * DETAIL value INPUT
 *******************************************************************************************************
 */
app.directive('detailvalue', function() {
    return {
        restrict: 'EA',
        scope: true,
        replace: true,
        templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail-value.html',
        controller: function($scope, $element, $attrs, $compile) {

            //todo move this over to use the service to pull the data instead of the local meta
            $scope.section_meta = $scope.meta[$scope.view].detail_pane[$attrs.section][$attrs.detailvalue];
        },
        link: function(scope, elm, attrs) {
            scope.initValidation();
        }
    }
})
