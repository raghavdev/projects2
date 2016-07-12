app.directive('flexpane', function() {
  return {
    restrict: 'EA',
    scope:true,
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + '/scripts/directives/templates/flexpane/default.html',
    controller: function($scope, $element, $attrs, model, flex) {

      //
      // FLEX SCOPE GLOBALS
      //------------------------------------------------------------------------------------------//
      // @description First things first.

      $scope.direction = $attrs.flexpane;

      // First off, assign appropriate css class.
      $element[0].classList.add($scope.direction);

      // Min Width. Can add more as needed.
      $scope.leftMinWidth = $attrs.leftMinWidth || 300;

      //
      // DIMENSION MODELS
      //------------------------------------------------------------------------------------------//
      // @description This will eventuall be pulled from user prefs.

      $scope.flexpanes = {
        paneLeft: null,
        paneRight: null,
        paneTop: null,
        paneBottom: null
      };

      $scope.dimensions = {
        paneLeft: null,
        paneRight: null,
        paneTop: null,
        paneBottom: null
      };

      // Get elements:
      for(var pane in $scope.flexpanes) {
        if($attrs[pane]) {
          $scope.flexpanes[pane] = document.getElementById($attrs[pane]);
        }
      }

      // here would need to be a logic block that said if no user prefs were defined, simply get and store

      //
      // HANDLE, HANDLE STATES
      //------------------------------------------------------------------------------------------//
      // @description Keeps track of mouseenters/moves/downs

      // Grab the handle for the handle
      $scope.handle = $element[0].querySelectorAll('.handle')[0];

      // Hover State
      $scope.activateListener = function() {
        flex.bindMouseMove($scope);
      };

      //
      // FLEX CONTROL
      //------------------------------------------------------------------------------------------//
      // @description

      var wL, wR, hT, hB, windowHeight, windowWidth, panesWidth, panesHeight;

      flex.getFlexers().then(function(data) {
        
        for(var i=0; i<data.length; i++) {
          if(data[i].id === $scope.$id) {
            $scope.dimensions = data[i].dimensions;
          }
        }

        wL = ($scope.dimensions.paneLeft)? $scope.dimensions.paneLeft
          : ($scope.flexpanes.paneLeft)? $scope.flexpanes.paneLeft.offsetWidth +'px'
            : 0;
        wR = ($scope.dimensions.paneRight)? $scope.dimensions.paneRight
          : ($scope.flexpanes.paneRight)? $scope.flexpanes.paneRight.offsetWidth +'px'
            : 0;

        hT = ($scope.dimensions.paneTop)? $scope.dimensions.paneTop
          : ($scope.flexpanes.paneTop)? $scope.flexpanes.paneTop.offsetHeight +'px'
            : 0;
        hB = ($scope.dimensions.paneBottom)? $scope.dimensions.paneBottom
          : ($scope.flexpanes.paneTop)? $scope.flexpanes.paneBottom.offsetHeight +'px'
            : 0;

        var diffWidth, diffHeight;

        windowHeight = document.documentElement.clientHeight;
        windowWidth = document.documentElement.clientWidth;

        panesHeight = parseInt(hT) + parseInt(hB);
        panesWidth = parseInt(wL) + parseInt(wR);

        if(wL && parseInt(wL) < $scope.leftMinWidth) {
          wL = $scope.leftMinWidth;
          wR = windowWidth-$scope.leftMinWidth;
        }

        if(wL && wR && panesWidth !== windowWidth) {
          if(panesWidth < windowWidth) {
            // if less than, we need to calculate the difference and divide the remainder between the two
            // to keep the ratio intact
            diffWidth = windowWidth - panesWidth;
            wL = parseInt(wL) + (diffWidth/2) + 'px';
            wR = parseInt(wR) + (diffWidth/2) + 'px';
          } else {
            // if bigger, we need to subtract half of the difference from each pane
            diffWidth = panesWidth - windowWidth;
            wL = parseInt(wL) - (diffWidth/2) + 'px';
            wR = parseInt(wR) - (diffWidth/2) + 'px';
          }
        }

        // console.log(panesHeight, windowHeight, hT, hB);
        if(hT && hB && panesHeight !== windowHeight) {
          if(panesHeight < windowHeight) {
            // if less than, we need to calculate the difference and divide the remainder between the two
            // to keep the ration intact
            diffHeight = windowHeight - panesHeight;
            hT = parseInt(hT) + (diffHeight/2) + 'px';
            hB = parseInt(hB) + (diffHeight/2) + 'px';
          } else {
            // Because the difference in height can easily lead to negative values,
            // it's easier to basically perform a reset on this and divide by half.
            hT = windowHeight/2 + 'px';
            hB = windowHeight/2 + 'px';
          }
        }

        // This may seem redundant, but in the event that there server stored dimensions, we'll want to grab these:
        ($scope.flexpanes.paneLeft)? $scope.flexpanes.paneLeft.style.width = wL : '';
        ($scope.flexpanes.paneRight)? $scope.flexpanes.paneRight.style.width = wR : '';
        ($scope.flexpanes.paneTop)? $scope.flexpanes.paneTop.style.height = hT : '';
        ($scope.flexpanes.paneBottom)? $scope.flexpanes.paneBottom.style.height = hB : '';

        flex.addFlexer($scope);

        wL = parseInt(wL);
        wR = parseInt(wR);
        hT = parseInt(hT);
        hB = parseInt(hB);
      }, function(data) {
        // Register flexer
        flex.addFlexer($scope);
      });

      /**
       * FLEX
       *
       * @description main controller for the flex sliders, get's called on mouse move.
       * @param  {[type]} e [description]
       * @return {[type]}   [description]
       */
      $scope.flex = function(e) {
        var deltaX, deltaY, val;

        var x = Math.round(e.clientX);
        var y = Math.round(e.clientY)-29;

        // LEFT/RIGHT Panes
        if($scope.direction === 'vertical') {

          if(x>$element[0].offsetLeft) {

            deltaX = x-wL;

            $scope.flexpanes.paneLeft.style.width = $scope.dimensions.paneLeft = wL+deltaX +'px';
            $scope.flexpanes.paneRight.style.width = $scope.dimensions.paneRight = wR-deltaX +'px';

            wL = $scope.flexpanes.paneLeft.offsetWidth;
            wR = $scope.flexpanes.paneRight.offsetWidth;
          } else {
            deltaX = wL-x;
            // Prevent left side from going less than acceptance criteria
            lVal = (wL-deltaX <= $scope.leftMinWidth)? $scope.leftMinWidth : wL-deltaX;
            rVal = (wL-deltaX <= $scope.leftMinWidth)? windowWidth - $scope.leftMinWidth : wR+deltaX;

            $scope.flexpanes.paneLeft.style.width  = $scope.dimensions.paneLeft = Math.max(lVal, 0) +'px';
            $scope.flexpanes.paneRight.style.width = $scope.dimensions.paneRight = rVal +'px';

            wL = $scope.flexpanes.paneLeft.offsetWidth;
            wR = $scope.flexpanes.paneRight.offsetWidth;
          }
        }

        // UP/DOWN Panes.
        if($scope.direction === 'horizontal') {

          if(y<$element[0].offsetTop) {

            deltaY = hT-y;

            // increase pane left, decrease paneright by distance
            // Math.max(object.width - 16, 0)
            $scope.flexpanes.paneTop.style.height = $scope.dimensions.paneTop = Math.max(hT-deltaY, 0) +'px';

            // Decrease pane right
            $scope.flexpanes.paneBottom.style.height = $scope.dimensions.paneBottom = hB+deltaY +'px';

            hT = $scope.flexpanes.paneTop.offsetHeight;
            hB = $scope.flexpanes.paneBottom.offsetHeight;
          } else {
            deltaY = y-hT;
            // increase pane left, decrease paneright by distance
            $scope.flexpanes.paneTop.style.height = $scope.dimensions.paneTop = hT+deltaY +'px';

            // Decreate pane right
            $scope.flexpanes.paneBottom.style.height = $scope.dimensions.paneBottom = hB-deltaY +'px';

            hT = $scope.flexpanes.paneTop.offsetHeight;
            hB = $scope.flexpanes.paneBottom.offsetHeight;
          }
        }

        flex.updateFlexer($scope);
      };

      /**
       * RESIZE FLEX
       *
       * @description  Adjusts flexpanes on window resize
       * @param  {[type]} e [description]
       * @return {[type]}   [description]
       */
      $scope.resizeFlex = function(e) {
        var windowWidth, panesWidth, diffWidth;

        // Using this instead of innerWidth as IE doesn't have that.
        windowWidth = document.documentElement.clientWidth;
        // Combined real estate
        panesWidth = parseInt(wL) + parseInt(wR);

        // If we dont check for these then we might assign bogus values
        // to either element particularly causing IE8 to break.
        if(wL && wR) {
          if(panesWidth < windowWidth) {
            // if less than, we need to calculate the difference and divide the remainder between the two
            // to keep the ratio intact
            diffWidth = windowWidth - panesWidth;
            wL = parseInt(wL) + (diffWidth/2) + 'px';
            wR = parseInt(wR) + (diffWidth/2) + 'px';
          } else {
            // if bigger, we need to subtract half of the difference from each pane
            diffWidth = panesWidth - windowWidth;
            wL = parseInt(wL) - (diffWidth/2) + 'px';
            wR = parseInt(wR) - (diffWidth/2)  + 'px';
          }

          // Assign new values
          $scope.flexpanes.paneLeft.style.width = wL;
          $scope.flexpanes.paneRight.style.width = wR;
        }
      };
    }
  }
});
