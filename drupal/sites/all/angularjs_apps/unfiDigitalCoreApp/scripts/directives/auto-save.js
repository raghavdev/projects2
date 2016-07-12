'use strict';

app.directive('autoSave', function() {
  return {
    restrict: 'A',
    require: 'ngModel',
    scope: true,
    controller: function($scope, $element, $attrs, $timeout) {
      $scope.saveMessage = '';
      $scope.saveState = 0; // None
      window.onbeforeunload = function(event) {
        if ($scope.saveState == $scope.UNSAVED) {
          return 'You currently have unsaved changes that will be lost.';
        }
      };

      $scope.SAVING = 1;
      $scope.SAVED = 2;
      $scope.SAVE_FAILED = 3;
      $scope.UNSAVED = 4;

      var timeout = null;
      var msgTimeout = null;
      var saveInProgress = false;
      var saveFinished = function() {
        saveInProgress = false;
      };

      var setState = function(state, message) {
        if (msgTimeout) {
          $timeout.cancel(msgTimeout);
        }
        $scope.saveState = state;
        $scope.saveMessage = message;
      };

      $scope.isSaving = function() {
        return $scope.saveState === $scope.SAVING;
      };

      var saveUpdates = function() {
        if ($scope.updateRecord.$valid) {
          if (!saveInProgress) {
            saveInProgress = true;
            setState($scope.SAVING, 'Saving...');
            $scope.updateResourceRecord().then(function() {
              if ($scope.saveState == $scope.SAVING) {
                if ($scope.updateRecord) {
                  $scope.updateRecord.$setPristine();

                  if($scope.updateRecord.recordForm) {
                    $scope.updateRecord.recordForm.$setPristine();
                  }
                }
              }
              setState($scope.SAVED, 'Updates saved.');
              if($scope.record) {
                $scope.record.changed = Math.floor(Date.now() / 1000);
              }

              msgTimeout = $timeout(function() {
                $scope.saveState = 0;
                $scope.saveMessage = '';
              }, 2000);
            }, function(response) {
              // @todo attempt to get error messages from response
              // fallback to a generic error message when necessary
              setState($scope.SAVE_FAILED, 'Save failed!');
            }).finally(saveFinished);
          }
          else {
            // Another save is in progress, wait until it finishes (whether it fails or not)
            timeout = $timeout(saveUpdates, 5000); // try again in 5 seconds
          }
        }
        else {
          // Examine: console.log($scope.updateRecord.$error);
          //  Can't trust: if ($scope.updateRecord.$dirty || ! $scope.updateRecord.$pristine) {...}
          setState($scope.SAVE_FAILED, 'Fix errors to save changes.');
        }
      };

      var debounceAutoSave = function(newVal, oldVal) {
        // When nothing was selected before, don't do anything.
        if (!oldVal || !newVal) {
          return;
        }
        if (newVal != oldVal) {
          // When switching objects, save right away.
          if (newVal.$$hashKey != oldVal.$$hashKey && $scope.saveState == $scope.UNSAVED) {
            saveInProgress = true;
            setState($scope.SAVING, 'Saving...');
            $scope.updateResourceRecord().then(function() {
              $scope.saveState = 0;
              $scope.saveMessage = '';
            }).finally(saveFinished);
          }
          else {
            // Ignore the changed property
            var newValCopy = angular.copy(newVal);
            var oldValCopy = angular.copy(oldVal);
            delete newValCopy.changed;
            delete oldValCopy.changed;
            // If the two objects are equal, then there are no changes to save. If we don't "trust" angular.equals()
            // consider additionally checking:
            //   (JSON.stringify(newValCopy) === JSON.stringify(oldValCopy))
            // bearing in mind that order of properties matter.
            // Additionally, check the .id properties, to prevent saveUpdates() from triggering if simply switching
            // between products.
            // TODO: figure out a way to account for switching between tabs while on one product,
            // which adds properties to the object, and thus triggering saveUpdates().
            if (angular.equals(newValCopy, oldValCopy) || (newValCopy.id !== oldValCopy.id)) {
              $scope.saveState = 0;
              $scope.saveMessage = '';
              return;
            }

            // Examine: console.log($scope.updateRecord.$error);
            if ($scope.updateRecord.$dirty || ! $scope.updateRecord.$pristine) {
              // Otherwise auto-save in a little bit.
              if (timeout) {
                $timeout.cancel(timeout)
              }

              setState($scope.UNSAVED, 'Unsaved changes...');
              timeout = $timeout(saveUpdates, 5000);
            }
            // [BMB-636] Because some of the fields of product records that were *imported* would not pass validation of
            // records in drupal, a change to the: Product Detail > Status [tab] > Activity Code [field] would prevent
            // any other field in the Product Details tabs from being auto-saved. Resetting the pristine *flags* in the
            // Angular form bypasses the $valid test in saveUpdates() without affecting any of the other tabs field
            // auto-saving behavior.
            $scope.updateRecord.$setPristine();
          }
        }
      };

      $scope.$watchCollection('record', debounceAutoSave);
    }
  }
});
