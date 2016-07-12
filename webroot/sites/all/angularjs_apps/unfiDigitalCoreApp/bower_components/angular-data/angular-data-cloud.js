'use strict';

/*******************************************************************************************************
 * ANGULAR DATA - ANGULAR DATA MODULES - CLOUD
 *******************************************************************************************************
 */
ngDataApp.service('cloud', ['ngData', '$http', function(ngData, $http) {
  
  var url = ngData.api + '/';

  function fetchModel(model) {
    console.log('Fetching:', model +';'+' from: ' +ngData.api);
    return $http({method: 'GET', url: url+model}).success(function(data) {
      // console.log(data);
    }).error(function(data) {
      console.log('Error fetching: ' +model+ 'from cloud.', data);
    });
  };

  function saveModel(opts) {

    opts.url = url+opts.url;

    return $http(opts).success(function(data) {
      console.log(data);
    }).error(function(data) {
      console.log(data);
    });
  };

  return {
    fetchModel: fetchModel,
    saveModel: saveModel
  };
}]);
