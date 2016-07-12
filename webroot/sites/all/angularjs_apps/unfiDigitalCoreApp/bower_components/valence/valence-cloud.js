'use strict';

/*******************************************************************************************************
 * ANGULAR DATA - ANGULAR DATA MODULES - CLOUD
 *******************************************************************************************************
 */
valenceApp.service('cloud', ['valence', 'auth', '$http', '$q', '$rootScope', function(valence, auth, $http, $q, $rootScope) {

  var baseEarl = valence.api + '/';
  var staggerInt = 250;
  var staggerCiel = 2500;
  var lastStagger;

  function fetchModel(model, opts, query) {
    var def = $q.defer(),
        token,
        predicates,
        httpOpts = {};

    // Defaults
    httpOpts.method = 'GET';
    httpOpts.url = baseEarl+model;
    httpOpts.params = null;
    $rootScope.progressactive = true;

    // Build url
    if(opts.HTTP && opts.HTTP.GET && opts.HTTP.GET.url) {
      httpOpts.url = baseEarl+opts.HTTP.GET.url;
    }

    // Build Params
    if(query) {
      httpOpts.params = {};
      predicates = Object.keys(query);
      for(var i=0; i<predicates.length; i++) {
        for(var param in query[predicates[i]]) {
          httpOpts.params[param] = query[predicates[i]][param];
        }
      }
    }

    // Get auth token if necessary
    if(opts && opts.retrieval && opts.retrieval.auth) {
      token = Auth.getAuthParams().token;
      if(token) {
        httpOpts.params.token = token;
      }
    }

    // Make request - I know $http returns a promise
    // I prefer keeping things consistent
    $http(httpOpts).success(function(data) {
      def.resolve(data)
      $rootScope.progressactive = false;
    }).error(function(data, status, headers, config) {
      $rootScope.progressactive = false;
      def.reject({data: data, status: status, headers: headers, config: config});
    });

    return def.promise;
  };

  /**
   * [saveModel description]
   * @param  {[type]} model  [description]
   * @param  {[type]} action [description]
   * @param  {[type]} opts   [description]
   * @param  {[type]} query  [description]
   * @param  {[type]} data   [description]
   * @return {[type]}        [description]
   */
  function saveModel(model, action, opts, query, data) {
    var def = $q.defer(),
        token,
        httpOpts = {};

    action = action.toUpperCase();

    httpOpts.method = action;
    httpOpts.url = baseEarl+model;
    httpOpts.params = null;

    if(opts.HTTP && opts.HTTP[action] && opts.HTTP[action].url) {
      httpOpts.url = baseEarl+opts.HTTP[action].url;
    }

    // Build Params
    if(query && query.params) { httpOpts.params = query.params};

    // Message body
    httpOpts.data = data;

    // Add any config declared data
    if(query && query.data) {
      for(var key in query.data) {
        httpOpts.data[key] = query.data[key];
      }
    }

    // Get auth token if necessary
    if(opts && opts.persistence && opts.persistence.auth) {
      token = auth.getAuthParams().token;
      if(token) {
        if(!httpOpts.params) httpOpts.params = {};
        httpOpts.params.token = token;
      }
    }

    if(opts.stagger) {
      if(!lastStagger) {
        lastStagger = new Date().getTime();
      } else {
        if((new Date().getTime() - lastStagger) <= staggerInt) {
          return def.promise;
        }
      }
    }

    // Send request
    $http(httpOpts).success(function(data) {

      if(lastStagger) { lastStagger = null }

      def.resolve(data);
    }).error(function(data, status, headers, config) {
      def.reject({data: data, status: status, headers: headers, config: config});
    });

    return def.promise;
  };

  return {
    fetchModel: fetchModel,
    saveModel: saveModel
  };
}]);
