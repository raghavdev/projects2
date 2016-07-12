'use strict';

/*******************************************************************************************************
 * EDIT CATEGORIES DIRECTIVE
 *******************************************************************************************************
 */
app.directive('editcategories', function() {
  return {
    restrict: 'E',
    replace: true,
    scope: false,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/edit-categories.html',
    controller: function($scope, $element, $attrs, $http, $rootScope, $timeout) {

      $scope.lastNewCategoryTid = 0;

      //adds the ---- indentation based on the depth
      $scope.indentation = function(c) {
        var indent = '';

        for(var i = 0; i < c.depth; i++) {
          indent += "---";
        }

        return indent;
      }


      $scope.editCategoryDirty = function(category) {
        category.dirty = true;
      }

      $scope.editCategoryNewCategory = function() {
        $scope.newCategory = true;

        //if you just do this it doesnt give it a chance to add the field to the
        //dom right so focus does nothing, but a slight delay works
        $timeout(function() {
          angular.element("#newCategory").trigger('focus');
        },200);
      }

      $scope.editCategorySaveNewCategory = function(name) {

        if(name != '') {

          //create the div and the entry on the managedCategories list
          $scope.newCategory = false;

          //need to keep an id for the category that is unique
          $scope.lastNewCategoryTid--;

          var category = {
            'tid': $scope.lastNewCategoryTid,
            'name': name,
            'depth': 0,
            'parent': 0,
            'weight': 0,
            'dirty': true,
          }

          $scope.managedCategories.push(category);

          //clear the text box
          $scope.newcategoryname = '';
        }
      }

      $scope.toggle = function(c) {
        c.selected = !c.selected;
      }

      $scope.editCategorySelect = function(c) {
       if(!$rootScope.categoryDrag) {
          c.selected = true;
        }
      }

      $scope.editCategoryDeselect = function(c) {
        if(!$rootScope.categoryDrag) {
          c.selected = false;
        }
      }

      $scope.editCategoryMouseDown = function(c) {
        if(!$rootScope.categoryDrag) {
          $rootScope.categoryDrag = true;
          c.categoryDrag = true;
          $rootScope.dragging = c;
          //todo add a dragging class
          c.dirty = true;
        }
      }

      $scope.editCategoryMouseUp = function(c) {
        if($rootScope.categoryDrag) {
          $rootScope.categoryDrag = false;
          $rootScope.dragging = null;

          //remove the dragging class
          c.categoryDrag = false;
        }
      }

      function pauseEvent(e){
          if(e.stopPropagation) e.stopPropagation();
          if(e.preventDefault) e.preventDefault();
          e.cancelBubble=true;
          e.returnValue=false;
          return false;
      }

      $scope.editCategoryMouseMove = function($event) {

        if($rootScope.categoryDrag) {

          //stop the dragging on the
          pauseEvent($event);

          //little bit of tolerance so it doestn shift up when you just wanted to indent
          if($rootScope.previousY - $event.screenY !== 0) {
            //to slow it down need to add something like and mouse y is higher or lower than the current index of where it should be at
            if($rootScope.previousY && $rootScope.previousY + 1 < $event.screenY) {

              //cheap trick for now
              if($rootScope.delay > 15) {
                //going down
                var p = angular.element("#category-"+$rootScope.dragging.tid).next()
                angular.element("#category-"+$rootScope.dragging.tid).insertAfter("#" + p.attr("id"));

                $rootScope.delay = 0;
              }
            }

            if($rootScope.previousY && $rootScope.previousY + 1 > $event.screenY) {

              if($rootScope.delay > 15) {
                //going up
                var p = angular.element("#category-"+$rootScope.dragging.tid).prev()
                angular.element("#category-"+$rootScope.dragging.tid).insertBefore("#" + p.attr("id"));

                $rootScope.delay = 0;
              }
            }
          }

          if(!$rootScope.delay) {
            $rootScope.delay = 0;
          }

          $rootScope.delay++;
          $rootScope.dragging.depth += getDepthAdjustment($event.screenX);
        }

        $rootScope.previousX = $event.screenX;
        $rootScope.previousY = $event.screenY
      }

//      //the order in the array is dictative of the structure, so need to reshift the
//      //array when we move the categories around
//      //may want to rethink this approach
//      function moveCategoryDown(category) {
//        var newList = {};
//        var found = false;
//
//        for(var i in $scope.managedCategories) {
//
//          if(i != category.tid && !found) {
//            newList[i] = $scope.managedCategories[i];
//          }
//          else if(i == category.tid) {
//           found = true;
//          }
//          else if(found) {
//            newList[category.tid] = category;
//            newList[i] = $scope.managedCategories[i];
//            found = false;
//          }
//        }
//
//        return newList;
//      }
//
//      function moveCategoryUp(category) {
//
//        var newList = {};
//
//        var last = null;
//        for(var i in $scope.managedCategories) {
//
//          if(i != category.tid) {
//            newList[i] = $scope.managedCategories[i];
//          }
//          else {
//
//            if(last != null) {
//              delete newList[last];
//
//              newList[category.tid] = category;
//              newList[last] = $scope.managedCategories[last];
//            }
//          }
//
//          last = $scope.managedCategories[i];
//        }
//
//        return newList;
//      }

      function getDepthAdjustment(x) {

        var depthAdjustment = 0;

        //on the x axis need to test that the current item is not index 0 and its not a dept > the parent - 1
        if($rootScope.previousX && $rootScope.previousX + 2 < x) {

          //can not indent more than the one above + 1
          var p = angular.element("#category-"+$rootScope.dragging.tid).prev()

          var pc = $scope.getCategoryFromList($scope.managedCategories, p.attr("tid"));

          if($rootScope.dragging.depth - pc.depth < 1) {
            depthAdjustment++;
          }
        }
        //do the reverse to go the otherway
        else if($rootScope.previousX && $rootScope.previousX - 2 > x && $rootScope.dragging.depth > 0) {
          depthAdjustment--;
        }

        return depthAdjustment;
      }

      $scope.moveCategory = function(c) {

      }

      $scope.renameCategory = function(c, name) {
        if(name) {
          c.name = name;
        }
        c.rename = false;
        c.dirty = true;
      }

      $scope.addSubCategory = function(c) {

      }

      $scope.removeCategory = function(c) {
        //if there are children we need to recurse that and do the same
        for(var child in c.children) {
          $scope.removeCategory(c.children[child]);
        }

        angular.element("#category-"+c.tid).remove();

        $scope.removedCategories.push(c.tid);

        delete $scope.managedCategories[c.tid];

        c.deleted=true;

        c.dirty = true;

        //cant get it to work in the proper place....
        $http({method: 'DELETE', url: '/service/digitalcore/categories/'+c.tid}).success(function() {

        });
      }

      $scope.showRenameCategory = function(c) {
        c.rename = !c.rename;
      }
    }
  }
});


