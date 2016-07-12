'use strict';

app.directive('drupalValidate', function($q, $http) {
  return {
    restrict: 'A',
    scope: true,
    require: 'ngModel',
    link: function($scope, $element, $attrs, $ctrl) {
      $ctrl.$asyncValidators.drupal = function(modelValue, viewValue) {
        // Don't validate empty values, those should be handled by required.
        if ($ctrl.$isEmpty(modelValue)) {
          return $q.when();
        }

        // Don't validate unchanged values
        if (!$ctrl.$dirty) {
          return $q.when();
        }

        // Don't validate when we have a pending validation
        if ($ctrl.$pending && $ctrl.$pending.drupal) {
          return $q.when();
        }

        var def = $q.defer();

        var data = $scope.record;
        data[$scope.field_name] = modelValue;

        $http.post('/service/digitalcore/validate', {record:data, field:$scope.field_name, entity_type:$scope.entity_type, bundle:$scope.bundle}).success(function(data, status) {
          try {
            if (data.valid) {
              def.resolve();
            }
            else {
              $scope.$parent.$parent.drupal_messages = data.errors.join("\n ");
              // An additional "$parent" needed to use "ng-bind-html" for example in the form-field-*.html directive templates.
              // Conservatively keeping both for now...
              $scope.$parent.$parent.$parent.drupal_messages = data.errors.join("\n ");
              def.reject();
            }
          }
          catch(e) {
            $scope.$parent.$parent.drupal_messages = 'An unknown error occurred.';
            def.reject();
          }
        }).error(function(data, status) {
          if (status == 403) {
            def.reject();
            // reload the current page
            window.location = '/user/login';
          }
          $scope.$parent.$parent.drupal_messages = 'An unknown error occurred.';
          def.reject();
        });

        return def.promise;
      };
    }
  };
});
