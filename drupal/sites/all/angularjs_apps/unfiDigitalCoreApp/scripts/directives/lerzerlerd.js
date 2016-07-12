/***********************************************************************************************************************************************
 * LERZERLERD - An Ermagherd Lazy Loading Directive
 ***********************************************************************************************************************************************
 * @description On page-load/navigation: 
 */
app.directive('lerzerlerd', function($parse, $http, $rootScope, $q) {
  return {
    restrict: 'A',
    scope: true,
    template: '',
    replace:false,
    controller: function($scope, $element, $attrs, utils) {

      //
      // SCOPE DATA
      //------------------------------------------------------------------------------------------//
      // @description
      
      //Throw $elemnt on scope for external access
      $scope.element = $element[0];

      // Stores the last scrollTop position so that when a new lazyloading trigger occurs, a scroll up won't meet
      // the criteria for the below conditional in $scope.scroller.
      $scope.lastScrolled = 0;

      //
      // SCROLLING/LAZY LOAD CONTROLS
      //------------------------------------------------------------------------------------------//
      // @description
      
      /**
       * SCROLLER
       * 
       * @param  {[type]} e [description]
       * @return {[type]}   [description]
       */
      $scope.scroller = function(e) {
        
        if(e.target.scrollTop >= $scope.lastScrolled && e.target.scrollHeight - (e.target.scrollTop + e.target.clientHeight) <= $scope.threshold) {       
          // Set new baseline - prevents triggering lazyloader when scrollig up from the very bottom
          $scope.lastScrolled = e.target.scrollTop;
          // Run user-provided loader
          $scope.lazyload();
        }
      };

      /**
       * LAZY LOAD
       * 
       * @return {[type]} [description]
       */
      $scope.lazyload = function() {
        // Execute user code.
        $scope.runner($scope).then(function() {});
      };
    },
    link: function($scope, $element, $attrs) {

      //
      // ATTRIBUTE PARSING TIME CONFIG
      //------------------------------------------------------------------------------------------//
      // @description
      var waitLimit = 3000;

      var waited = 0;

      var interval = 500;

      //
      // LERZERLERD MODELS
      //------------------------------------------------------------------------------------------//
      // @description

      /**
       * RUNNER
       *
       * @description This is the closure that gets executed every time lazyloading scroll criteria is met.
       * @type {[type]}
       */
      $scope.runner = $parse($attrs.lerzerlerd)($scope) || null;

      /**
       * THRESHOLD
       *
       * @description Value in pixel from bottom of lazy load element to trigger the runner.
       * @type {[type]}
       */
      $scope.threshold = $attrs.lerzerlerdPerxerlThersherld || 100;

      //
      // LERZERLERD ERRORS
      //------------------------------------------------------------------------------------------//
      // @description Interval $parser because this controller will most likely be executed 
      //              before the entity service $scope properties have been injected into the 
      //              lazy-load scope.
      
      if(!$scope.runner) {

        var checkLoader = setInterval(function() {
          if(waited >= waitLimit) {
            clearInterval(checkLoader);
            throw 'Lerzerlerd - please provide a function to call on lazy-load. On: '+$element[0].outerHTML;
          } else {

            $scope.runner = $parse($attrs.lerzerlerd)($scope) || null;

            if($scope.runner) {
              clearInterval(checkLoader);
            }
          }

          waited += interval;
        }, interval);
      }

      //
      // SCROLLING
      //------------------------------------------------------------------------------------------//
      // @description This assignment is in Link because $attrs are typically parsed by this point.

      $element[0].onscroll = $scope.scroller;
    }
  }
});

