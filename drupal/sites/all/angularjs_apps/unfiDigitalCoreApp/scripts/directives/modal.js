/***********************************************************************************************************************************************
 * MODAL DIRECTIVE
 ***********************************************************************************************************************************************
 * @description
 */
app.directive('modal', function($parse) {
  return {
    restrict: 'EA',
    scope: true,
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath +'/views/modals/modal.html',
    controller: function($scope, $element, $attrs, $rootScope) {

      $element[0].style.display = 'none';

      $scope.template = '';

      $rootScope.modal = function(name, arg1, arg2) {
        $scope.arg1 = arg1;
        $scope.arg2 = arg2;
        $scope.template = Drupal.settings.unfiDigitalCoreApp.modulePath +'/views/modals/'+$scope.view+'/'+name+'.html';
          jQuery($element[0]).addClass(name);
          $scope.name = name;
      };

      $rootScope.modalClose = function() {
        $element[0].style.display = 'none';
        $scope.template = null;
          jQuery($element[0]).removeClass($scope.name);
      }

      $scope.open = function(fn, args) {
        $element[0].style.display = 'block';
        var $window = jQuery(window),
          $dialog = jQuery($element).find('.modal-wrapper'),
          offset = Math.floor(($window.height() - $window.scrollTop() - $dialog.height()) / 2);

        if (offset < 0) {
          offset = 0;
        }

        $dialog.css('margin-top', offset);

        fn = $parse(fn)($rootScope) || function() {};

        fn(args);

      };

      $scope.close = function(fn, args) {
        $element[0].style.display = 'none';
        $scope.template = null;
          jQuery($element[0]).removeClass($scope.name);
        fn = $parse(fn)($rootScope) || function() {};

        //if there isnt an argument there shift them
        //arg1 and 2 are pass thru variables from the opening of the dialog
        //arg is from the dialog itself
        if(!args) {
          args = $scope.arg1;
          $scope.arg1 = $scope.arg2;
          delete $scope.arg2;
        }

        fn(args, $scope.arg1, $scope.arg2);

      };
    }
  }
})
