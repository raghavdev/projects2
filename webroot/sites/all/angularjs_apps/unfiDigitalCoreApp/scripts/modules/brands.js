/***********************************************************************************************************************************************
 * BRANDS MODULE
 ***********************************************************************************************************************************************
 * @description manages all things brands.
 */
app.service('brands', ['module', '$q', 'model', function(module, $q, model) {
  function brands($scope) {
    var prom = $q.defer();

    //
    // BRANDS
    //------------------------------------------------------------------------------------------//
    // @description
    $scope.brands = [];

    $scope.getBrands = function() {
      if(!$scope.brands || $scope.brands.length == 0) {
        if (!$scope.brandPromise) {

          $scope.brandPromise = $q.defer();

          model.get('brands', {HTTP: {GET: {url: 'brands?perPage=0'}}, useRouteParams: false}).then(function (data) {
            data.results.forEach(function(brand) {
              // The 'brand' content type has many "empty" Titles, in drupal
              if(brand.product_name && brand.title) {
                $scope.brands.push(brand);
              }
            });
            $scope.brandPromise.resolve($scope.brands);
          });
        }
      }
      else {
        $scope.brandPromise = $q.defer();
        $scope.brandPromise.resolve($scope.brands);
      }

      return $scope.brandPromise.promise;
    };

    prom.resolve();

    return prom.promise;
  };

  module.register({name:'brands', fn: brands});
}]);