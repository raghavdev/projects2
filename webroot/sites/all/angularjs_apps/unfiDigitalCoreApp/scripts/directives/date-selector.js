'use strict';

/*******************************************************************************************************
 * DATE SELECTOR
 *******************************************************************************************************
 */
app.directive('dateselector', function() {
  return {
    restrict: 'EA',
    scope: true,
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/date-selector.html',
    controller: function($scope, $element, $attrs, $compile) {
      $scope.id = $attrs.selectorid;

      $scope.scope = $attrs.scope;

      $scope.selectormodel = $attrs.selectormodel;
      $scope.dayrecord = $attrs.selectormodel + "_day";
      $scope.monthrecord = $attrs.selectormodel + "_month";
      $scope.yearrecord = $attrs.selectormodel + "_year";

      $scope.days = new Array(31);
      $scope.years = new Array(150);

      $scope.months = [];
      $scope.months[1] = 'Jan';
      $scope.months[2] = 'Feb';
      $scope.months[3] = 'Mar';
      $scope.months[4] = 'Apr';
      $scope.months[5] = 'May';
      $scope.months[6] = 'Jun';
      $scope.months[7] = 'Jul';
      $scope.months[8] = 'Aug';
      $scope.months[9] = 'Sep';
      $scope.months[10] = 'Oct';
      $scope.months[11] = 'Nov';
      $scope.months[12] = 'Dec';

      var currentTime = new Date();

      if($attrs.defaultmonth) {
        if($attrs.defaultmonth == "next") {
          $scope.defaultmonth = currentTime.getMonth() + 2;
        }
        else if($attrs.defaultmonth == "previous") {
          $scope.defaultmonth = currentTime.getMonth() - 2;
        }
        else {
          $scope.defaultmonth = $attrs.defaultmonth;
        }
      }
      else {
        $scope.defaultmonth = currentTime.getMonth() + 1;
      }

      if($attrs.defaultday) {
        if($attrs.defaultday == "tomorrow") {
          $scope.defaultday = currentTime.getDate() + 1;
        }
        else {
          $scope.defaultday = $attrs.defaultday;
        }
      }
      else {
        $scope.defaultday = currentTime.getDate();
      }

      if($attrs.defaultyear) {
        if($attrs.defaultyear == "next") {
          $scope.defaultyear = currentTime.getFullYear() + 1;
        }
        else if($attrs.defaultyear == "previous") {
          $scope.defaultyear = currentTime.getFullYear() - 1;
        }
        else {
          $scope.defaultyear = $attrs.defaultyear;
        }
      }
      else {
        $scope.defaultyear = currentTime.getFullYear();
      }
    },
    link: function(scope, elm, attrs) {
      scope.initValidation();
    }
  }
})
