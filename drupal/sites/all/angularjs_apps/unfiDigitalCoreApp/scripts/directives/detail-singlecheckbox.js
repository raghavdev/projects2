'use strict';

/*******************************************************************************************************
 * DETAIL SINGLE CHECKBOX
 *******************************************************************************************************
 */
app.directive('detailsinglecheckbox', function() {
    return {
        restrict: 'EA',
        scope: true,
        replace: true,
        templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail-singlecheckbox.html',
        controller: function($scope, $element, $attrs, $compile) {

            if($attrs.resource) {
                $scope.resource = $attrs.resource;
            }

            //todo move this over to use the service to pull the data instead of the local meta
            $scope.section_meta = $scope.meta[$scope.view].detail_pane[$attrs.section][$attrs.detailsinglecheckbox];
        },
        link: function(scope, elm, attrs) {
            scope.initValidation();
        }
    }
})


