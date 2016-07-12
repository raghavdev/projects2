/**
 * Products module.
 *
 * Handles creating new products.
 */
app.service('products', ['module', '$q', '$http', 'model', 'user', function(module, $q, $http, model, user) {
    function products($scope) {
        var prom = $q.defer();

        $scope.newProductDefaults = {};
        $scope.saving = false;

        $scope.openCreateProduct = function() {
            var myDate = new Date();
            var current_year = myDate.getFullYear();

            $scope.clearRecord();
            $scope.newProductDefaults = {
              is_new: true,
              type: 'product_details',
              language: 'und',
              contract_number: current_year
            };
            for (var field in $scope.meta.fields) {
              if ($scope.meta.fields.hasOwnProperty(field)) {
                if ($scope.meta.fields[field].default_value && $scope.meta.fields[field].default_value[0]) {
                  if ($scope.meta.fields[field].default_value[0].hasOwnProperty('value')) {
                    $scope.newProductDefaults[field] = $scope.meta.fields[field].default_value[0].value;
                  }
                  else if ($scope.meta.fields[field].default_value[0].hasOwnProperty('tid')) {
                    $scope.newProductDefaults[field] = $scope.meta.fields[field].default_value[0].tid;
                  }
                }
                else if ($scope.meta.fields[field].settings && $scope.meta.fields[field].settings.default_value_code) {
                  // Date field
                  $scope.newProductDefaults[field] = $scope.meta.fields[field].settings.default_value_code;
                }
                else if ($scope.meta.fields[field].widget && $scope.meta.fields[field].widget.type
                    && $scope.meta.fields[field].widget.type == 'workflow_default') {
                  var wid = $scope.meta.fields[field].config.settings.wid;
                  var current_state;
                  var min_weight = 999;
                  for (var sid in $scope.meta.workflows[wid].states) {
                    // Skip the creation state
                    if ($scope.meta.workflows[wid].states[sid].name == '(creation)') {
                      continue;
                    }
                    if (parseInt($scope.meta.workflows[wid].states[sid].weight) < min_weight) {
                      min_weight = parseInt($scope.meta.workflows[wid].states[sid].weight);
                      current_state = $scope.meta.workflows[wid].states[sid].sid;
                    }
                  }
                  $scope.newProductDefaults[field] = current_state;
                }
              }
            }
            $scope.loadRecord($scope.newProductDefaults);

            $scope.modal('new-product');
        };

        $scope.closeCreateProduct = function() {
            $scope.clearRecord();
            $scope.modalClose();
        };

        $scope.createProduct = function() {
          var def = $q.defer();

          var data = $scope.record;
          delete data.nid;
          data.uid = user.getCurrentUser().uid;

          if (!$scope.saving) {
            $scope.saving = true;
            $http.post('/service/digitalcore/products', data).then(function (response) {
              $scope.closeCreateProduct();
              $scope.loadingAppData = true;
              model.get($scope.resource, {
                by: {nid: response.data.nid},
                useRouteParams: false,
                ignoreConfigOpts: true,
                forceFetch: true,
                forceSerialize: true
              }).then(function (data) {
                if (data && data.results && data.results.length) {
                  $scope.record = data.results[0];
                  $scope.resultcount++;
                  $scope.records.splice(0, 0, $scope.record);
                }
              }).finally(function () {
                $scope.loadingAppData = false;
              });
              def.resolve(response.data);
            }, function (response) {
              def.reject(response.data);
            }).finally(function() {
              $scope.saving = false;
            });
          }

          return def.promise;
        };

        prom.resolve();

        return prom.promise;
    };

    module.register({name:'products', fn: products});
}]);
