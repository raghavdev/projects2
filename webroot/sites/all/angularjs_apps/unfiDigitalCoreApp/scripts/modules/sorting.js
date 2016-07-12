/***********************************************************************************************************************************************
 * SORTING MODULE
 ***********************************************************************************************************************************************
 * @description Controls list-view sorting.
 */
app.service('sorting', ['module', '$q', 'user', '$rootScope', function(module, $q, user, $rootScope) {

  function sorting($scope) {
    var def = $q.defer();
    //
    // SORTING
    //------------------------------------------------------------------------------------------//
    // @description section that contains anything related to sorting.

    // Sorting predicate
    $scope.predicate = null;

    // List of elements
    $scope.sortables = null;

    $scope.dir = 'ascending';

    /**
     * LOAD SORTING PREFS
     *
     * @return {[type]} [description]
     */
    $scope.loadSortingPrefs = function() {
      if($scope.viewMode === 'list') {
        if(!$scope.search[$scope.view].sort) {
          if($scope.view == "products") {
            $scope.search[$scope.view].sort = "product_name";
            getSortables("product_name");
          }
          else {
            $scope.search[$scope.view].sort = "title";
            getSortables("title");
          }
        }
        else {
          // Load the saved predicate then apply the correct calsses.
//          user_prefs.get('predicate').then(function(data) {
//            $scope.dir = (data.charAt(0) === '-')? 'descending' : 'ascending';
//
//            // Assign the saved predicate
//            $scope.predicate = data;
//
//            // Strip the data down non-directional for matching purposes.
//            data = (data.match('-'))? data.split('-')[1] : data;
//
//            getSortables(data);
//          }, function() {
//            if($scope.view == "products") {
//              getSortables('product_name');
//            }
//            else {
//              getSortables('asset_name');
//            }
//          });

          getSortables($scope.search[$scope.view].sort);
        }
      }


    };

    function getSortables(data) {
      var el;
      // Toggle classes on page load
      // wrapped in a setTimeout for the classList API
      // el isn't undefined but classList.add doesn't do anything
      var getSortables = setTimeout(function() {

        // Grab sortable element list
        $scope.sortables = document.querySelectorAll('.sortable');

        // Determine the right element.
        for(var i=0; i<$scope.sortables.length; i++) {
          if($scope.sortables[i].getAttribute('data-predicate').match(data)) {
            el = $scope.sortables[i];
            break;
          }
        }

        // Toggle classes
        toggleSortClasses(el, $scope.dir);
      }, 350);
    }

    $scope.sort = function(e, pred) {
       var key = '',
          dir,
          keydir = "ascending";

      //(!$scope.predicate)? $scope.predicate = pred : '';

//      if($scope.predicate.charAt(0) !== '-') {
//        //$scope.predicate = '-'+pred;
//        //$scope.dir = 'descending';
//        dir = "DESC";
//      } else {
//        //$scope.predicate = $scope.predicate.split('-')[1];
//        //$scope.dir = 'ascending';
//        dir = "ASC";
//      }

      if(!$scope.sortDir || $scope.sortDir == "ASC") {
        dir = "DESC";
        keydir = "descending";
      }
      else {
        dir = "ASC";
        keydir = "ascending"
      }

      toggleSortClasses(e.target, keydir);

      // Save once a new predicate has been assigned
      user.savePref('predicate', pred);

      //if its a special path based value, break it down and take the first value
      if(pred.match('.') !== null) {
          levels = pred.split('.');

          pred = levels[0];
      }

      $scope.sortDir = dir;
      $scope.search[$scope.view].sort_dir = dir;
      $scope.search[$scope.view].sort = pred;
      $scope.query();

    }

    /**
     * SORT
     *
     * @description  changes the sorting predicate on the data set. without an element to update
     * @param  {[type]} pred [description]
     * @return {[type]}      [description]
     */
    $scope.simpleSort = function(pred) {
      var key = '',
          dir;

      //(!$scope.predicate)? $scope.predicate = pred : '';

//      if($scope.predicate.charAt(0) !== '-') {
//        //$scope.predicate = '-'+pred;
//        //$scope.dir = 'descending';
//        dir = "DESC";
//      } else {
//        //$scope.predicate = $scope.predicate.split('-')[1];
//        //$scope.dir = 'ascending';
//        dir = "ASC";
//      }

      if(!$scope.sortDir || $scope.sortDir == "ASC") {
        dir = "DESC";
      }
      else {
        dir = "ASC";
      }

      // Save once a new predicate has been assigned
      user.savePref('predicate', pred);

      //if its a special path based value, break it down and take the first value
      if(pred.match('.') !== null) {
          levels = pred.split('.');

          pred = levels[0];
      }

      $scope.sortDir = dir;
      $scope.search[$scope.view].sort_dir = dir;
      $scope.search[$scope.view].sort = pred;
      $scope.query();
    }


    /**
     * TOGGLE SORT CLASSES
     *
     * @description  Removes sort classes from everything then applies the
     *               correct directional to the correct element.
     * @param  {[type]} el  [description]
     * @param  {[type]} dir [description]
     * @return {[type]}     [description]
     */
    function toggleSortClasses(el, dir) {
      if(!el) {
        $scope.loadSortingPrefs();
        return;
      }

      for(var i=0; i<$scope.sortables.length; i++) {
        $scope.sortables[i].classList.remove('ascending');
        $scope.sortables[i].classList.remove('descending');
      }

      el.classList.add(dir);
    };

    $scope.loadSortingPrefs();

    def.resolve();

    return def.promise;
  }

  module.register({name:'sorting', fn: sorting});
}]);
