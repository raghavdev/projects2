/***********************************************************************************************************************************************
 * CATEGORIES MODULE
 ***********************************************************************************************************************************************
 * @description manages all things categories.
 */
app.service('categories', ['module', '$q', 'model', '$rootScope', function(module, $q, model, $rootScope, $http) {
  function categories($scope) {
    var prom = $q.defer();


    $scope.selectedCategories = [];
    $scope.removedCategories = [];

    //
    // CATEGORIES
    //------------------------------------------------------------------------------------------//
    // @description

    // hack until i get more time to figure out why categories keeps
    // being overriden with rcm_categories
    $scope.getRCMCategories = function() {
      if(!$scope.rcm_categories || $scope.rcm_categories.length == 0) {
        if (!$scope.rcm_categoriesPromise) {

          $scope.rcm_categoriesPromise = $q.defer();

          model.get('rcm_categories', {'forceFetch': true, localize: false}).then(function (rcm_categories) {
            $scope.rcm_categoriesPromise.resolve(rcm_categories);
            $scope.rcm_categories = rcm_categories;
          });
        }
      }
      else {
        $scope.rcm_categoriesPromise = $q.defer();
        $scope.rcm_categoriesPromise.resolve($scope.rcm_categories);
      }

      return $scope.rcm_categoriesPromise.promise;
    };

    $scope.getCategories = function(force) {

      if(!$scope.categories || $scope.categories.length == 0) {
        if (!$scope.categoriesPromise) {

          $scope.categoriesPromise = $q.defer();

          if (!force) {
            force = false;
          }

          model.get('categories', {'forceFetch': force, localize: false}).then(function (categories) {
            $scope.categoriesPromise.resolve($scope.categories);
            $scope.categories = categories;
          });
        }
      }
      else {
        $scope.categoriesPromise = $q.defer();
        $scope.categoriesPromise.resolve($scope.categories);
      }

      return $scope.categoriesPromise.promise;
    };

    $scope.assignCategory = $rootScope.assignCategory = function(tid) {

      //turn the tid into an int
      var tid = parseInt(tid);
      if($scope.record.asset_category.indexOf(tid) !== -1) {
        $scope.record.asset_category.splice($scope.record.asset_category.indexOf(tid), 1);
      } else {
        $scope.record.asset_category.push(tid);
      }

      $scope.updateResourceRecord();
    };

    $scope.openCategoryManageModal = function() {

      //convert the category list into somehting more flat so its easier to manage
      var list = [];
      $scope.managedCategories = flattenCategory(list, $scope.categories);

      $scope.modal('edit-categories');
    }

    //called when the manager dialog is closed, update the categories from this data
    $scope.handleCategoryManageModalClose = $rootScope.handleCategoryManageModalClose = function(data) {
      $scope.updateCategories($scope.managedCategories).then(function() {
        $scope.getCategories(true);
      })
    }

    $scope.deleteCategories = function(categories) {
      var def = $q.defer();

      $scope.deleteCategory(categories, def);

      return def.promise;
    }

    $scope.deleteCategory = function(category, promise) {

      var k = Object.keys(category)[0];

      var tid = category[k];

//      $http({method: 'DELETE', url: '/service/digitalcore/categories/'+tid}).success(function() {
//         if(Object.keys(category).length > 0) {
//           $scope.deleteCategory(category, promise);
//         }
//         else {
//            //finally we resolve the promise after the list is done
//            promise.resolve();
//         }
//      });
    }

    $scope.updateCategories = function(categories) {

      var def = $q.defer();

      var weight = 0;
      var lastCategory = null;

      //ordering is dictated in the dom, so are the parents
      //correct depth is in the model
      var cats = angular.element('.managed-category');

      var weight = 0;
      var topWeight = 0;

      for(var i in cats) {

        if(!isNaN(i)) {
          var category = null;

          //find the category from the array
          category = $scope.getCategoryFromList(categories, cats[i].attributes["tid"].value);

          if(category !== null) {
            if(category.depth == 0) {
              category.parent = 0;
              weight = topWeight;
              topWeight++;
            }
            else if(lastCategory.depth < category.depth) {

              if(category.parent != lastCategory.tid) {
                category.dirty = true;
              }

              category.parent = lastCategory.tid;
            }
            else if(lastCategory != null && lastCategory.depth == category.depth) {

              if(category.parent != lastCategory.parent) {
                category.dirty = true;
              }

              category.parent = lastCategory.parent;
            }

            if(lastCategory != null && category.parent != 0) {
              if(lastCategory.parent != category.parent) {
                if(category.weight != 0) {
                  category.dirty = true;
                }
                weight = 0;
              }
              else {
                weight = lastCategory.weight + 1;
              }
            }

            if(category.weight != weight) {
              category.dirty = true;
            }

            category.weight = weight;

            lastCategory = category;
          }
        }
      }

      updateCategories(categories, def);

      return def.promise;
    }

    $scope.getCategoryFromList = function(categories, tid) {
      var category = null;

      for(var c in categories) {
        if(categories[c].tid === tid) {
          category = categories[c];
          break;
        }
      }

      return category;
    }

    function updateCategories(categories, promise) {
      for(var idx in categories) {

        var category = categories[idx];

        if(category.dirty) {

          //remove the flag
          delete category['dirty'];

          if(category['internal_only']) {
            category['internal_only'] = 1;
          }
          else {
            category['internal_only'] = 0;
          }

          if(category.tid > 0) {
            $scope.putCategory(category, promise);
          }
          else {
            delete category['tid'];

            $scope.postCategory(category, promise);
          }
        }
      }
    }

    function flattenCategory(flatList, categories) {
      for(idx in categories) {
        var c = categories[idx];
        if(c.tid) {
          flatList.push({'tid': c.tid, 'name': c.name, 'depth': c.depth, 'parent': c.parents[0], 'weight': c.weight, 'vid': c.vid, 'order': c.order, 'internal_only': c.internal_only});
          if(categories[idx].children && categories[idx].children.length > 0) {
            //for(idc in categories[idx].children) {
              flatList = flattenCategory(flatList, categories[idx].children);
            //}
          }
        }
      }

      return flatList;
    }

    //create new category
    $scope.postCategory = function(category, promise) {
      model.post('categories', {HTTP: {POST: {url: 'categories'}}, localize:false}, category).then(function(data) {
        promise.resolve(data);
      });
    }

    //update category
    $scope.putCategory = function(category, promise) {
      model.put('categories', {HTTP: {PUT: {url: 'categories/'+category.tid}}, localize:false}, category).then(function(data) {
        if(promise)
          promise.resolve(data);
      });
    }

    prom.resolve();

    return prom.promise;
  };



  module.register({name:'categories', fn: categories});
}]);
