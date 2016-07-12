/***********************************************************************************************************************************************
 * PARAMS MODULE
 ***********************************************************************************************************************************************
 * @description Maintains param tracking.
 */
app.service('params', ['module', '$q', function(module, $q) {

  function params($scope) {
    var def = $q.defer();
    //
    // PARAM CENTRAL
    //------------------------------------------------------------------------------------------//
    // @description Helper functions around dealing with filter params
    
    /**
     * PARAMS
     *
     * @description serves as the SSOT for the query params that get sent to /products
     * @type {Object}
     */
    $scope.params = {};

    /**
     * CEALR PARAMS
     *
     * @description Deletes a specific param if provided to simply resets all params.
     * @param  {[type]} param [description]
     * @return {[type]}       [description]
     */
    $scope.clearParams = function(param) {
      if(!param) {
        $scope.params = {};
      } else {
        delete $scope.params[param];
      }
    };

    /**
     * SET PARAM
     *
     * @description Adds a param to the params object.
     * @param {[type]} param [description]
     * @param {[type]} val   [description]
     */
    $scope.setParam = function(param, val) {
      return $scope.params[param] = val;
    };

    /**
     * GET PARAMS
     *
     * @description This function will return params based on the argument passed.
     *                Empty = all params
     *                String = specific param
     *                Object.not = All but value of Object.not
     *              This will probably recive further support for more queries.
     * @param  {[type]} opts [description]
     * @return {[type]}      [description]
     */
    $scope.getParams = function(opts) {
      var tmp = {};

      if(!opts) {
        tmp = $scope.params;
      } else {
        if(opts.constructor === Object && opts.not) {
          for(var prop in $scope.params) {
            if(prop !== opts.not) {
              tmp[prop] = $scope.params[prop];
            }
          }
        } else {
          if(opts.constructor === String && $scope.params[opts]) {
            tmp[opts] = $scope.params[opts];
          }
        }
      }

      return tmp;
    };

    def.resolve();

    return def.promise;
  };

  module.register({name:'params', fn:params});
}]);