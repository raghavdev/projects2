'use strict';

/*******************************************************************************************************
 * ACTION MENU PANE DIRECTIVE
 *******************************************************************************************************
 */
app.directive('actionmenu', function() {
  return {
    restrict: 'EA',
    scope:true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/action-menu.html',
    controller: function($scope, $element, $attrs, $http, $rootScope) {

      $scope.selectedItem = "";

      $scope.menuItemVisible = function() {

        if($scope.actionMenuViewCallback) {
          return $scope.actionMenuViewCallback();
        }

        return true;
      };

      $scope.updateActionMenus = $rootScope.updateActionMenus = function() {

        //get a list of the collections and the bin
        //need the ids
        $scope.getBin().then(function() {
          $scope.getCollections().then( function() {
            var col = [];
            col[0] = { "id": $scope.binId, "name": "Your Bin"};

            var c = 1;
            for(var idx in $scope.collections) {
              col[c] = {"id": idx, "name": $scope.collections[idx].title};
              c++;
            }

            $scope.actionMenuActionType = $attrs.actionmenu;
            switch($attrs.actionmenu) {
              case "add-to": {
                  $scope.actionMenuViewCallback = function() {
                    if($scope.selectedCollection) {
                      return false;
                    }
                    return true;
                  };
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "select";
                  $scope.actionMenuPlaceholder = "Add selected to:";
                  $scope.actionMenuItems = col;
                  $scope.actionMenuAction = function(selected) {

                    $scope.addSelectedToCollection(selected).then(function() {

                      //doesnt work gets reset soon as the function completes
                      //angular.element("." + $attrs.actionmenu).val("");
                      //angular.element("." + $attrs.actionmenu).val("");
                    });
                  };
                  break;
              }
              case "move-to": {
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "select";
                  $scope.actionMenuPlaceholder = "Move selected to:";
                  $scope.actionMenuItems = col;
                  $scope.actionMenuAction = function(selected) {
                    //selected will be the nid of the collection the checked items will be added to
                  };
                  break;
              }
              case "delete-selected": {
                  //called on the ng-show, put custom logic in here
                  $scope.actionMenuViewCallback = function() {
                    if($scope.selectedCollection) {
                      return false;
                    }
                    return true;
                  };
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "href";
                  $scope.actionMenuLabel = "Delete selected " + $scope.view;
                  $scope.actionMenuAction = function() {

                    $scope.modal('delete-'+$scope.view+'-confirm');
                  };
                  break;
              }
              case "remove-selected": {
                  //called on the ng-show, put custom logic in here
                  $scope.actionMenuViewCallback = function() {
                    if($scope.selectedCollection) {
                      return true;
                    }
                    return false;
                  };
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "href";
                  $scope.actionMenuLabel = "Remove selected " + $scope.view;
                  $scope.actionMenuAction = function() {
                    //call the removal function
                    $scope.removeSelectedFromCollection($scope.selectedCollection).then(function() {
                      //refresh the collections list
                      $scope.filterCollection($scope.selectedCollection);
                    });
                  };
                  break;
              }
              case "sort-by": {

                  var fields = [];
                  for(var idx in $scope.meta[$scope.view].list.fields) {
                    fields[idx] = {};
                    fields[idx]['id'] = $scope.meta[$scope.view].list.fields[idx]['class'];
                    fields[idx]['name'] = $scope.meta[$scope.view].list.fields[idx]['name'];
                  }
                  $scope.actionMenuViewMode = ["thumb", "list"];
                  //$scope.actionMenuLabel = "Sort By:";
                  $scope.actionMenuPlaceholder = "Sort By:"; // puts label inside select box
                  $scope.actionMenuType = "select";
                  $scope.actionMenuItems = fields;
                  $scope.actionMenuAction = function(selected) {
                    //$scope.actionMenuPlaceholder = false;
                    var pred = false;
                    //find the predicate for the selected
                    for(var idx in $scope.meta[$scope.view].list.fields) {
                       if($scope.meta[$scope.view].list.fields[idx].class === selected) {
                        pred = $scope.meta[$scope.view].list.fields[idx].predicate;
                      }
                    }

                    if(pred) {

                      if($scope.viewMode == "list") {
                        var el = {};
                        el.target= angular.element("." + selected + ".sortable")[0];

                        $scope.sort(el, pred);
                      }
                      else {
                        $scope.simpleSort(pred);
                      }
                    }
                  };

                  break;
              }
              case "cmp-include": {
                  //called on the ng-show, put custom logic in here
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "cmp";
                  $scope.actionMenuLabel = "CMP Status";
                  $scope.actionMenuAction = function(action, cmpstatus) {
                    if(action == "show") {
                        if($scope.popout_open) {
                          $scope.popout_open = false;
                        }
                        else {
                          $scope.popout_open = true;
                        }
                      }
                      else if(action == "apply") {
                        $scope.popout_open = false;
                        $scope.cmpApply(cmpstatus);
                      }
                    };
                    break;
              }
              case "ecom-include": {
                  //called on the ng-show, put custom logic in here
                  $scope.actionMenuViewMode = ["thumb", "detail", "list"];
                  $scope.actionMenuType = "ecommerceFeed";
                  $scope.actionMenuLabel = "eComm Status";
                  $scope.actionMenuAction = function(action, ecomstatus) {
                    if(action == "show") {
                        if($scope.popout_open) {
                          $scope.popout_open = false;
                        }
                        else {
                          $scope.popout_open = true;
                        }
                      }
                      else if(action == "apply") {
                        $scope.popout_open = false;
                        $scope.ecomApply(ecomstatus);
                      }
                    };
                    break;
              }
            }
          });
        });
      };

      $scope.viewModeVisible = function() {
        if($scope.actionMenuViewMode.indexOf($scope.viewMode) != -1) {
          return true;
        }
        return false;
      };

      $scope.getMenuItemTemplate = function() {
        if($scope.actionMenuType) {
          return Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/action-menu-items/'+$scope.actionMenuType+'.html';
        }
      };

      $scope.updateActionMenus();
    }
  };
});
