/**
 * Checklist-model
 * AngularJS directive for list of checkboxes
 *
 * Forked from http://vitalets.github.io/checklist-model/ in order to support md-checkboxes
 */

angular.module('checklist-model', [])
.directive('checklistModel', ['$parse', '$compile', function($parse, $compile) {
  // contains
  function contains(arr, item, comparator) {
    if (angular.isArray(arr)) {
      for (var i = arr.length; i--;) {
        if (comparator(arr[i], item)) {
          return true;
        }
      }
    }
    else if (angular.isObject(arr)) {
      if (angular.isObject(item)) {
        for (var i in item) {
          if (item.hasOwnProperty(i) && arr.hasOwnProperty(i) && comparator(arr[i], item[i])) {
            return true;
          }
        }
      }
      else {
        if (arr.hasOwnProperty(item.toString())) {
          return true;
        }
      }
    }
    return false;
  }

  // add
  function add(arr, item, comparator) {
    if(!contains(arr, item, comparator)) {
      if (angular.isArray(arr)) {
        arr.push(item);
      }
      else if (angular.isObject(arr)) {
        if (angular.isObject(item)) {
          for (var i in item) {
            if (item.hasOwnProperty(i)) {
              arr[i] = item[i];
            }
          }
        }
        else {
          arr[item.toString()] = item;
        }
      }
    }
    return arr;
  }  

  // remove
  function remove(arr, item, comparator) {
    if (angular.isArray(arr)) {
      for (var i = arr.length; i--;) {
        if (comparator(arr[i], item)) {
          arr.splice(i, 1);
          break;
        }
      }
    }
    else if (angular.isObject(arr)) {
      if (angular.isObject(item)) {
        for (var i in item) {
          if (item.hasOwnProperty(i)) {
            delete arr[i];
          }
        }
      }
      else {
        delete arr[item.toString()];
      }
    }
    return arr;
  }

  // http://stackoverflow.com/a/19228302/1458162
  function postLinkFn(scope, elem, attrs) {
    // compile with `ng-model` pointing to `checked`
    $compile(elem)(scope);

    // getter / setter for original model
    var getter = $parse(attrs.checklistModel);
    var setter = getter.assign;
    var checklistChange = $parse(attrs.checklistChange);

    // value added to list
    var value = $parse(attrs.checklistValue)(scope.$parent);


    var comparator = angular.equals;

    if (attrs.hasOwnProperty('checklistComparator')){
      comparator = $parse(attrs.checklistComparator)(scope.$parent);
    }

    // watch UI checked change
    scope.$watch('checked', function(newValue, oldValue) {
      if (newValue === oldValue) { 
        return;
      } 
      var current = getter(scope.$parent) || {};
      if (newValue === true) {
        setter(scope.$parent, add(current, value, comparator));
      } else {
        setter(scope.$parent, remove(current, value, comparator));
      }

      if (checklistChange) {
        checklistChange(scope);
      }
    });
    
    // declare one function to be used for both $watch functions
    function setChecked(newArr, oldArr) {
        scope.checked = contains(newArr, value, comparator);
    }

    // watch original model change
    // use the faster $watchCollection method if it's available
    if (angular.isFunction(scope.$parent.$watchCollection)) {
        scope.$parent.$watchCollection(attrs.checklistModel, setChecked);
    } else {
        scope.$parent.$watch(attrs.checklistModel, setChecked, true);
    }
  }

  return {
    restrict: 'A',
    priority: 1000,
    terminal: true,
    scope: true,
    compile: function(tElement, tAttrs) {
      if (!tAttrs.checklistValue) {
        throw 'You should provide `checklist-value`.';
      }

      // exclude recursion
      tElement.removeAttr('checklist-model');
      
      // local scope var storing individual checkbox model
      tElement.attr('ng-model', 'checked');

      return postLinkFn;
    }
  };
}]);
