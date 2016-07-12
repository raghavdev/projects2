/***********************************************************************************************************************************************
 * FLEX SERVICE
 ***********************************************************************************************************************************************
 * @description Handles propogation of mousemove subscriptions
 */
app.service('flex', ['$rootElement', 'model', '$q', 'user', function($rootElement, model, $q, user) {
  var self = this;

  //
  // FLEXER REGISTRATION, METHODS
  //------------------------------------------------------------------------------------------//
  // @description
  
  var flexers = false;

  var throttle = null;

  var isFlexing = false;

  //
  // FLEXER API
  //------------------------------------------------------------------------------------------//
  // @description
  
  /**
   * ADD FLEXER
   * @param {[type]} scope [description]
   */
  this.addFlexer = function(scope) {
    var scopeObj = {}

    if(!flexers) {flexers = []}

    // This prevents stringification and only keeps the data we need;
    scopeObj["id"] = scope.$id;
    scopeObj["dimensions"] = scope.dimensions;
    scopeObj["flex"] = scope.flex;
    scopeObj["resizeFlex"] = scope.resizeFlex;

    flexers.push(scopeObj);
  };

  /**
   * GET FLEXERS
   * @return {[type]} [description]
   */
  this.getFlexers = function() {
    var def = $q.defer();

    user.getPref('flexers').then(function(data) {
      def.resolve(data);
    }, function() {
      // resolve anyways
      def.resolve([]);
    });
    
    return def.promise;
  };

  this.updateFlexer = function(scope) {
    for(var i=0; i<flexers.length; i++) {
      if(flexers[i].id === scope.$id) {
        flexers[i].dimensions = scope.dimensions;
      }
    }
    return;
  }
  
  //
    // FLEXER MOUSEMOVE
  //------------------------------------------------------------------------------------------//
  // @description

  /**
   * UNBIND MOUSE MOVE
   * 
   * @param  {[type]} scope [description]
   * @return {[type]}       [description]
   */
  this.bindMouseMove = function(scope) {
    $rootElement[0].onmousemove = function(e) {
      var evt = e || event;
      isFlexing = true;

      for(var i=0; i<flexers.length; i++) {
        if(flexers[i].id === scope.$id) {
          scope.flex(evt);
        }
      }
    };

    $rootElement[0].classList.add('no-select');
  };

  /**
   * UNBIND MOUSE MOVE
   * 
   * @return {[type]} [description]
   */
  this.unbindMouseMove = function() {

    if(isFlexing) {
      // $rootElement[0].removeEventListener('mousemove', function(e) {
      //   console.log('remove listener cb');
      // }, true);
      $rootElement[0].classList.remove('no-select');
      $rootElement[0].onmousemove = null;

      user.savePref('flexers', flexers).then(function(data) {
        
      });
      
      isFlexing = false;
    }
  };

  // FLEXER MOUSE UP
  //------------------------------------------------------------------------------------------//
  // @description
  try {
    $rootElement[0].addEventListener('mouseup', function(e) {
      self.unbindMouseMove();
    }, false);
  } catch (e) {
    $rootElement[0].attachEvent('onmouseup', function(e) {
      self.unbindMouseMove();
    }, false);
  }
  
  //
  // FLEXER RESIZE
  //------------------------------------------------------------------------------------------//
  // @description handles dimensions when window is resized
  try {
    window.addEventListener('resize', function(evt) {
      for(var i=0; i<flexers.length; i++) {
        flexers[i].resizeFlex(evt);
      }
    }, false);
  } catch (err) {
    window.attachEvent('onresize', function(e) {
      for(var i=0; i<flexers.length; i++) {
        flexers[i].resizeFlex(evt);
      }
    }, false);
  }

  return this;
}]);
