/***********************************************************************************************************************************************
 * FILTERS MODULE
 ***********************************************************************************************************************************************
 * @description On page-load/navigation:
 */
app.service('filters', ['module', '$q', 'model', function(module, $q, model) {

  function filters($scope) {
    var def = $q.defer();

    //
    // FILTERING
    //------------------------------------------------------------------------------------------//
    // @description

    $scope.filters = {
      products: $scope.getCategories
    };

    $scope.currentFilter = {};

    $scope.currentFilters = [];

    /**
     * FILTER PRODUCTS
     *
     * @description  calls the products API with a category filter
     * @param  {[type]} tid [description]
     * @return {[type]}     [description]
     */
    $scope.filterRecords = function(tid) {

      // Set filter param
      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].qualifier = 1;
      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].categories = [tid];

      $scope.currentFilter.tid = tid;

      $scope.query();
    };

    /**
     * FILTER COLLECTIONS
     *
     * @description  Filter elements down to those in the collection
     * @param  {[type]} tid [description]
     * @return {[type]}     [description]
     */
    $scope.filterCollection = function(nid) {
      // Set filter param
      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].collection].nid = nid;
      $scope.currentFilter.nid = nid;
      $scope.selectedCollection = nid;
      $scope.query();
    };

    /**
     * CLEAR FILTERS
     *
     * @description resets any filters on teh calls to the products api,
     * @return {[type]} [description]
     */
    $scope.clearFilters = function() {

      $scope.currentFilter = {};

      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].qualifier = null;
      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].categories = [];

      $scope.query();
    };

    $scope.clearCollectionFilter = function() {
      $scope.selectedCollection = null;

      $scope.search[$scope.view].collection.nid = null;

      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].qualifier = null;
      $scope.search[$scope.view][$scope.meta[$scope.view]["search"].category].categories = [];

      $scope.query();
    }

    /**
     * FILTER BRANDS
     *
     * @return {[type]} [description]
     */
    $scope.filterBrands = function() {
      $scope.search[$scope.view].brand.qualifier = 1;
      $scope.query();
    };

    def.resolve();
    return def.promise;
  }

  module.register({name: 'filters', fn: filters});
}])
