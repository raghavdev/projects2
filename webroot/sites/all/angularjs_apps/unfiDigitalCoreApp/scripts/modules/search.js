/***********************************************************************************************************************************************
 * SEARCH MODULE
 ***********************************************************************************************************************************************
 * @description Search operations
 */
app.service('search', ['module', '$q', 'model', function(module, $q, model) {

  function search($scope) {
    var def = $q.defer();

    //
    // SEARCH
    //------------------------------------------------------------------------------------------//
    // @description

    // Date obj used in providing a default end-date value
    var date = new Date();

    // Separator used in query string concatonation
    var separator = '|';
    var multi_separator = '+';

    /**
     * SEARCH DATA MODEL
     * @type {Object}
     */
    $scope.search = {};

    /**
     * PRODUCTS DATA MODEL\
     * @type {Object}
     */
    $scope.search.products = {
      search: null,
      category: {
        qualifier: 1,
        categories: []
      },
      brand: {
        qualifier: 1,
        brands: []
      },
      activity_state: {
        qualifier: 1,
        states:[]
      },
      product_name: {
        qualifier: 1,
        parameter: null,
        keywords: null
      },
      product_dates: {
        qualifier: 1,
        option: null,
        start: null,
        end: null
      },
      primary_image:{
        enabled:false,
        qualifier: 1
      },
      flyer_description: {
        enabled:false,
        qualifier: 1
      }
    };

    /**
     * QUERY
     *
     * @description Builds the query string to be sent to /products
     * @param  {[type]} e [description]
     * @return {[type]}   [description]
     */
    $scope.query = function(e) {
      $scope.record = null;

      if(e && e.srcElement.type != "checkbox") {
        e.preventDefault();
      }

      var searchModel = $scope.search[$scope.view],
          recordParams,
          params = {};

      for(var param in searchModel) {

        // Don't even continue if null
        if(searchModel[param] !== null) {

          // If a string value, just assign
          if(searchModel[param].constructor === String && searchModel[param]) {
            params[param] = searchModel[param];
          }
          else if(searchModel[param].constructor === Boolean) {

            if(searchModel[param]) {
              params[param] = searchModel[param];
            }
          }

          // If this conditional is entered only products that have ALL values will be preocessed
          if(searchModel[param].constructor === Object && validateObjectForQuery(searchModel[param])) {
            for(var prop in searchModel[param]) {
              if(prop !== 'enabled') {
                if(searchModel[param][prop].constructor === Object) {
                  for(var subprop in searchModel[param][prop]) {
                    params[param] += separator + searchModel[param][prop][subprop];
                  }
                } else if(searchModel[param][prop].constructor === Array) {
                  if(searchModel[param][prop].length > 1) {
                    params[param] += multi_separator + searchModel[param][prop].join('|');
                  }
                  else {
                    params[param] += separator + searchModel[param][prop].join('|');
                  }
                } else {
                  if(!params[param]) {
                    params[param] = searchModel[param][prop];
                  } else {
                    params[param] += separator + searchModel[param][prop];
                  }
                }
              }
            }
          }
        }
      }

      // Get all product params but 'page'
      recordParams = $scope.getParams({not: 'page'});

      // Params for search are a two part operation.
      // 1. Compare what exists in params, if it is:
      //  a. the prop exists in $scope.search.products
      //  b. does NOT exist in local params
      //  Then remove it.
      // 2. Add what does exist to local params to global params.
      for(var param in recordParams) {
        if($scope.search[$scope.view].hasOwnProperty(param) && !params[param]) {
          $scope.clearParams(param);
        }
      }

      // Two different for loops to make sure we catch all local params
      for(var param in params) {
        $scope.setParam(param, params[param]);
      }

      // Refresh params
      recordParams = $scope.getParams({not: 'page'});
      // HTTPIZZLE
      $scope.loadingAppData = true;
      model.get($scope.resource, {by: recordParams, useRouteParams: false, ignoreConfigOpts: true, forceFetch: true, forceSerialize: true}).then(function(data) {
        $scope.records = (data && data.results && data.results.length)? data.results : [];
        $scope.lazyLoader.reset();
        $scope.resultcount = data.total;

        //set the only record to be selected since thats it
        if(data.count == 1) {
          $scope.record = $scope.records[0];
        }

        $scope.updateTotalPages(data.total);
        $scope.loadingAppData = false;
      });
    };

    /**
     * VALIDATE OBJECT FOR QUERY
     *
     * @description Used in validating truthiness of all properties of an object. Based on the truthy values
     *              of our data model, i.e 0 === true.
     * @param  {[type]} obj [description]
     * @return {[type]}     [description]
     */
    function validateObjectForQuery(obj) {
      var isValid = true;

      for(var prop in obj) {
        // Seems a bit lengthy, but we can't simply do !obj[prop] because we have to allow zero.
        if(obj[prop] === false || obj[prop] === null || obj[prop] === undefined || obj[prop] === "" ||
            obj[prop].constructor === Array && !obj[prop].length || obj[prop].constructor === Object && !Object.keys(obj[prop]).length) {
          isValid = false;
          break;
        } else {
          // Recurse if needed
          if(obj[prop].constructor === Object && !validateObjectForQuery(obj[prop])) {
            isValid = false;
            break;
          }
        }
      }

      return isValid;
    };

    //
    // ASSET SEARCH DETAILS
    //------------------------------------------------------------------------------------------//
    // @description Used for tagimacator in assets search.

    $scope.supportedFileTypes = [
      {ext:'jpg'},
      {ext:'jpeg'},
      {ext:'png'},
      {ext:'bmp'},
      {ext:'txt'},
      {ext:'xls'},
      {ext:'csv'},
      {ext:'doc'},
      {ext:'docx'},
      {ext:'gif'},
      {ext:'tif'}
    ];

    def.resolve();

    return def.promise;
  }
  module.register({name:'search', fn: search});
}]);
