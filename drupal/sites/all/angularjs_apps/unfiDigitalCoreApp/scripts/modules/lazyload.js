/***********************************************************************************************************************************************
 * LAZY LOAD MODULE
 ***********************************************************************************************************************************************
 * @description Lazy Loading module.
 */
app.service('lazyload', ['module', '$q', 'model', function(module, $q, model) {
  function lazyload($scope) {
    var def = $q.defer();

    //
    // Lazy Loading
    //------------------------------------------------------------------------------------------//
    // @description

    // Increment
    $scope.stepBy = 1;

    // current step in the ggregration
    $scope.currentStep = $scope.stepBy;

    // Param name use in actual HTTP query
    $scope.queryParam = 'page';

    // Amount perPage
    $scope.perPage = 100;

    // lazy load param
    $scope.setParam($scope.queryParam, $scope.currentStep);

    // Max Steps - $scope needs to be replaced by the number of total products in a query / the perPage
    $scope.maxPage = 1000;

    // Keep track of loaded data so we don't have redundant requests.
    $scope.loadedSteps = [];

    // used by lazyLoading to reset 'lastScroll'
    $scope.resetLazyLoading = false;

    // The actual scope object of the lazy loading directive.
    $scope.LazyScope = null;

    /**
     * LAZY LOADER
     *
     * @description Provided as a callback to the lerzerlerd directive.
     * @return {[type]} [description]
     */
    $scope.lazyLoader = function(lazyScope) {
      var def = $q.defer();

      if(!$scope.lazyScope) $scope.lazyScope = lazyScope;
      
      if($scope.loadedSteps.indexOf($scope.currentStep) === -1 && $scope.currentStep <= $scope.maxPage) {

        // Track step
        $scope.loadedSteps.push($scope.currentStep);

        // REQUEST
        model.get($scope.resource, {by: $scope.getParams(), useRouteParams: false, forceFetch: true, ignoreConfigOpts: true, forceSerialize: true}).then(function(next) {

          $scope.appendNewData(next.results).then(function(data) {
           def.resolve();
          });

        });
      }

      return def.promise;
    };

    /**
     * APPEND NEW DATA
     *
     * @description Appends new cloud data to the products $scope object. There's nothing particularly async
     *              about what's going on here, so we could have just as easily used a callback.
     * @description  throws new data into DOM.
     * @param  {[type]} data [description]
     * @return {[type]}      [description]
     */
    $scope.appendNewData = function(data) {
      var def = $q.defer();
      
      // Add to lazy-loaded
      for(var i=0;i<data.length; i++) {
        $scope.records.push(data[i]);
      }
      
      // Incrememnt step
      $scope.setParam($scope.queryParam, $scope.currentStep+=parseInt($scope.stepBy));

      def.resolve();

      return def.promise;
    };

    /**
     * RESET
     *
     * @description Resets lazyLoader instance data. The lastScrolled and element.scrollTop
     *              manipulation was hard to justify putting here, It's just to make this thing
     *              triggerable upon search or something was very challenging.
     *              And this way it will work with multiple lazy loading directives on the page.
     * @param  {[type]} el [description]
     * @return {[type]}    [description]
     */
    $scope.lazyLoader.reset = function(el) {

      // Search has been conucted, reset lazyloading data
      $scope.setParam('page', 1);

      // Reset Current Step
      $scope.currentStep = $scope.stepBy;

      // Clear loaded steps
      $scope.loadedSteps = [];

      // Lazy load instance data.
      if($scope.lazyScope) {
        $scope.lazyScope.lastScrolled = 0;
        $scope.lazyScope.element.scrollTop = 0;
      }
    };

    /**
     * UPDATE TOTAL PAGES
     *
     * @description Updates the maxPage property used by lazyLoading to prevent superflous HTTP requests.
     *              Since this only runs when the reset function is also called they can probably be consolidated.
     * @param  {[type]} total [description]
     * @return {[type]}       [description]
     */
    $scope.updateTotalPages = function(total) {
      if(total) {
        $scope.maxPage = parseInt(total / $scope.perPage);
      }
    };

    def.resolve();

    return def.promise;
  };

  module.register({name:'lazyload', fn: lazyload});
}]);