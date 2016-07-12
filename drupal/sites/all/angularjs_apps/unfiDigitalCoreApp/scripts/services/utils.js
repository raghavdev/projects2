/***********************************************************************************************************************************************
 * UTILS
 ***********************************************************************************************************************************************
 * @description Angular convenience functions.
 */
app.service('utils', [function() {

  /**
   * APPLY
   * @param  {[type]} scope [description]
   * @return {[type]}       [description]
   */
  this.apply = function(scope, fn) {
    var applier = setInterval(function() {
      var phase = scope.$$phase;

      if(phase != '$apply' && phase != '$digest') {
        clearInterval(applier);
        scope.$apply(fn);
      }

    }, 100);
  };

  /**
   * RESOLVE OBJECT PATH
   *
   * @description Takes a root object and a string and resolves it;
   * @param  {[type]} obj  [description]
   * @param  {[type]} path [description]
   * @return {Mixed} Value of the resolved property, null if unresolvable.
   */
  this.resolveObjectPath = function(obj, path) {
    var resVal = null,
        currPath = obj,
        matched = 0,
        props = (path.match('.'))? path.split('.') : [path];

    for(var i=0; i<props.length; i++) {
      if(currPath[props[i]]) {
        currPath = currPath[props[i]];
        matched++;
      } else {
        break;
      }
    }

    if(matched === props.length) {
      resVal = currPath;
    }

    return resVal;
  };


  this.isSelected = function(expr) {
    var isSelected = '';

    if(expr) {
      isSelected = 'selected';
    }

    return isSelected;
  };

  return this;
}]);