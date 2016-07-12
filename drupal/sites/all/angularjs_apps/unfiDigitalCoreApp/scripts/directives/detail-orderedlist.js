'use strict';

/*******************************************************************************************************
 * DETAIL ORDERED LIST
 *******************************************************************************************************
 */
app.directive('detailorderedlist', function() {
  return {
    restrict: 'EA',
    scope: true,
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/detail-orderedlist.html',
    controller: function($scope, $element, $attrs, $compile, $timeout) {

      $scope.newRecord = {};

      $scope.section_meta = $scope.meta[$scope.view].detail_pane[$attrs.section][$attrs.detailorderedlist];

      $scope.addrow = function() {
        for(var s in $scope.section_meta.sections) {
          if(!$scope.record[$scope.section_meta.sections[s].record]) {
            $scope.record[$scope.section_meta.sections[s].record] = [];
          }

          $scope.record[$scope.section_meta.sections[s].record].push("");
        }
      }

      //mark this field dirty for update
      $scope.invalidate = function(id, record) {

        //start the timer
        if(id) {
          if(!$scope.timers.hasOwnProperty(id)) {
            //add the timer to the list
            var newTimer = jQuery.extend(true, {}, $scope.timer);
            $scope.timers[id] = newTimer;
          }

          //kinda strange but this is what the method is expecting
          var el = document.createElement("input");
          el.setAttribute("record", record);

          //a timer per field, so that nothing gets lost
          $scope.timers[id].run(el);
        }
      }
    },
    link: function(scope, elm, attrs) {
      scope.initValidation();
    }
  }
})
