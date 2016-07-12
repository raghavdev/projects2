'use strict';

// Hack
app.directive('mtdcChips', function() {
  return {
    restrict: 'E',
    require: 'ngModel',
    replace: true,
    template: '<div class="md-chips">' +
      '<div class="md-chip" ng-repeat="item in items">' +
        '<span><strong>{{item.label}}</strong></span>' +
        '<button class="md-chip-remove" ng-click="removeChip($index)">' +
          '<md-icon md-svg-src="{{ getCloseIcon() }}" alt="remove"></md-icon>' +
        '</button>' +
      '</div>' +
    '</div>',
    link: function($scope, $element, $attrs, $ngModel) {
      $ngModel.$render = function() {
        $scope.items = $ngModel.$modelValue;
      };
    },
    controller: function($scope, $element, $attrs, $compile) {
      $scope.removeChip = function(idx) {
        $scope.items.splice(idx, 1);
      };

      $scope.getCloseIcon = function() {
        return Drupal.settings.unfiDigitalCoreApp.modulePath + 'images/md-close.svg';
      };
    }
  };
});

app.directive('stringToNumber', function() {
  return {
    require: 'ngModel',
    link: function(scope, element, attrs, ngModel) {
      ngModel.$parsers.push(function(value) {
        return '' + value;
      });
      ngModel.$formatters.push(function(value) {
        if (isNaN(parseFloat(value, 10))) {
          return 0;
        }
        return parseFloat(value, 10);
      });
    }
  };
});

app.directive('formfield', function(user, $q, $http, $timeout, $parse) {
  // Maps Drupal widgets to Angular templates.
  var widget_type_map = {
    'number': 'number',
    'options_onoff': 'boolean',
    'options_select': 'select',
    'options_buttons': 'checkboxes',
    'taxonomy_autocomplete': 'autocomplete', // Product Category
    'node_reference_autocomplete': 'autocomplete', // Brand
    'entityreference_autocomplete': 'autocomplete',
    'text_textarea': 'textarea',
    'text_textfield': 'textinput',
    'workflow_default': 'workflow',
    'file_generic': 'file',
    'image_image': 'image',
    'date_text': 'date', // Active Date
    'field_collection_embed': 'field-collection'
  };
  return {
    restrict: 'A',
    scope: true,
    replace: true,
    template: '<div ng-include="getWidgetUrl()"></div>',
    link: function($scope, $element, $attrs) {
      $scope.getWidgetUrl = function() {
        if ($scope.widget_type) {
          var type = $scope.widget_type;
          return Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-' + type + '.html';
        }
      };
    },
    controller: function($scope, $element, $attrs, $compile, $mdDialog) {
      $scope.isObject = angular.isObject;
      $scope.isString = angular.isString;

      // @todo make this not hard coded
      $scope.entity_type = 'node';
      $scope.bundle = 'product_details';

      $scope.field_name = $scope.$eval($attrs.formfield) || $attrs.formfield;
      // Make sure that field exists before
      if ($scope.meta && $scope.meta.fields && $scope.meta.fields[$scope.field_name]) {
        $scope.section_meta = $scope.meta.fields[$scope.field_name];

        // Marketing Icons list
        $scope.section_meta.marketing_icons = ($scope.meta.fields[$scope.field_name].display) ? $scope.meta.fields[$scope.field_name].display.default.settings.field_formatter_class.split(' ') : '';
        // Special case for node title, since it doesn't allow class assignment in drupal UI via field_formatter_class
        if ($scope.field_name == 'title') {
           $scope.section_meta.marketing_icons = ["cloud-web-required"];
        }

        var widget_type = ($scope.section_meta.widget && $scope.section_meta.widget.type) ? $scope.section_meta.widget.type : 'text_textfield';
        $scope.drupal_widget_type = widget_type;
        $scope.widget_type = widget_type_map[widget_type] || 'textinput';

        // Handle cardinality
        $scope.multivalued = false;
        if ($scope.section_meta.config && $scope.section_meta.config.cardinality != 1) {
          $scope.multivalued = true;
          // For unlimited values, always have one more then the current number of values
          if ($scope.section_meta.config.cardinality == -1) {
            $scope.field_count = 1;
            if ($scope.record[$scope.field_name]) {
              $scope.field_count = $scope.record[$scope.field_name].length + 1;
            }
          }
          else {
            $scope.field_count = $scope.section_meta.config.cardinality;
          }
        }

        // Handle "computed" fields
        $scope.computed = false;
        if ($scope.section_meta.hasOwnProperty('widget') && $scope.section_meta.widget.hasOwnProperty('computation_callbacks')) {
          $scope.computed = true;
          $scope.isComputing = false;

          $scope.$watchCollection('recordForm', function(newVal, oldVal) {
            // Avoid sending multiple requests
            if ($scope.isComputing) {
              return;
            }

            // If the form is dirty, recalculate the value of this field
            if ($scope.recordForm && $scope.record) {
              $scope.isComputing = true;

              var data = $scope.record;
              for (var prop in $scope.recordForm) {
                if ($scope.recordForm.hasOwnProperty(prop) && $scope.recordForm[prop] && $scope.recordForm[prop].hasOwnProperty('$viewValue')) {
                  data[prop] = $scope.recordForm[prop].$viewValue;
                }
              }

              // Send ajax request to recalculate
              $http.post('/service/digitalcore/compute', {record:data, field:$scope.field_name, entity_type:$scope.entity_type, bundle:$scope.bundle, formFields:[]}).success(function(data) {
                if (data.hasOwnProperty('value')) {
                  $scope.record[$scope.field_name] = data.value;
                }
              }).finally(function() {
                $scope.isComputing = false;
              });
            }
          });
        }

        // Field collection handler
        if ($scope.widget_type == 'field-collection' && $scope.meta.field_collections) {
          // Watch for changes in selected record
          $scope.$watch('record.nid', function(newVal, oldVal) {
            if (newVal != oldVal) {
              if (!$scope.record[$scope.field_name]) {
                $scope.record[$scope.field_name] = [{"field_name":$scope.meta.fields[$scope.field_name].field_name}];
              }
            }
          });

          // Pass in fields and widget types
          $scope.collection_fields = $scope.meta.field_collections[$scope.field_name].fields;
          $scope.widget_type_map = widget_type_map;

          // Handle changes coming up-scope from field collection scope
          $scope.$on('collection_update', function(e){
            $scope.record[$scope.field_name][e.targetScope.collection_index] = e.targetScope.collection_update;
            $scope.record.needs_update = new Date();
          });

          // 'add' functionality
          $scope.addItem = function(item) {
            item = {"field_name":$scope.meta.fields[$scope.field_name].field_name};
            if (!$scope.record[$scope.field_name]) {
              $scope.record[$scope.field_name] = [];
            }
            $scope.record[$scope.field_name].push(item);
          };

          // BLOCKED: API doesn't allow delete functionality. If/When that happens this is a stub of the
          // expected functionality. Directive is also in template.
          //
          // $scope.removeItem = function($event, collection_delta) {
          //   $scope.record[$scope.field_name].splice(collection_delta, 1);
          //   // Force a save
          //   $scope.record.needs_update = new Date();
          // };
        }



        // Date fields have different input types depending on the granularity
        if ($scope.widget_type == 'date') {

          // We need to convert our model value to a Date object and back again.
          $scope.date_object = {
            value: null,
          };

          // If field has saved value, set date object value
          if ($scope.record[$scope.field_name]) {
            $scope.date_object.value = new Date($scope.record[$scope.field_name]);
          } else {
            $scope.date_object.value = '';
          }

          // pass jQueryUI DatePicker options through
          $scope.dateOptions = {
            changeYear: true,
            changeMonth: true,
            dateFormat: 'mm/dd/yy',
          };

          // Determine the input type by the cardinality.
          if ($scope.section_meta.config.settings.granularity.day) {
            // Has a date, check if it has a time
            if ($scope.section_meta.config.settings.granularity.hour) {
              $scope.widget_type = 'datetime-local';
            }
          }
          else if ($scope.section_meta.config.settings.granularity.month) {
            $scope.widget_type = 'month';

            $scope.dateOptions = {
              changeYear: true,
              changeMonth: true,
              dateFormat: 'MM yy',
              showButtonPanel: true,
              defaultDate: $scope.date_object.value,
              beforeShow: function(input, inst) {
                // Always set to 1st of the month
                inst.currentDay = 1;
                inst.selectedDay = 1;
                var widget = jQuery( ".form-field-month input" ).datepicker( "widget" );
                widget[0].classList.add('month-picker');
              },
              onChangeMonthYear: function(year, month, inst) {
                var widget = jQuery( ".form-field-month input" ).datepicker( "widget" );
                widget[0].classList.add('month-picker');
              },
              onClose: function(dateText, inst) {
                inst.currentDay = 1;
                inst.selectedDay = 1;
                $scope.date_object.value = new Date(inst.selectedMonth + 1 + '-' + inst.selectedDay + '-' + inst.selectedYear);
                var widget = jQuery( ".form-field-month input" ).datepicker( "widget" );
                widget[0].classList.remove('month-picker');
                $scope.$digest();
              }
            };
          }
          else if ($scope.section_meta.config.settings.granularity.hour) {
            $scope.widget_type = 'time';
          }

          // Watch for switching selected record
          $scope.$watch('record.nid', function(newVal, oldVal) {
            if (newVal == oldVal) {
              return;
            }
            if ($scope.record[$scope.field_name]) {
              $scope.date_object.value = new Date($scope.record[$scope.field_name]);
            }
            else {
              $scope.date_object.value = null;
            }
          });

          // Watch for changing date value
          $scope.$watch('date_object.value', function(newVal, oldVal) {
            if (newVal == oldVal) {
              return;
            }
            if (newVal) {
              $scope.record[$scope.field_name] = newVal.toISOString();
            }
            else {
              $scope.record[$scope.field_name] = null;
            }
          });
        }

        // Autocomplete field
        if ($scope.section_meta.widget && $scope.widget_type == 'autocomplete') {
          $scope.getMatches = function(text) {
            var def = $q.defer();
            var url = '/bluemarble/autocomplete';
            if ($scope.section_meta.config.cardinality == 1) {
              url += '/single';
            }
            else {
              url += '/tags';
            }
            // @todo figure out how to get the actual Drupal field name without assuming all fields start with field_
            // An example of a field that does not follow this pattern is the og_group_ref entityreference field.
            // For now we do not have any of those fields though.
            url += '/field_' + $scope.field_name;
            url += '/' + $scope.entity_type + '/' + $scope.bundle + '/';
            if ($scope.record && $scope.record.hasOwnProperty('nid') && $scope.record.nid) {
              url += $scope.record.nid;
            }
            else {
              url += 'NULL';
            }
            // Add the text typed so far
            url += '/' + text;
            $http.get(url).success(function(data) {
              var items = [];
              for (var key in data) {
                if (data.hasOwnProperty(key)) {
                  items.push({value: key, label: data[key]});
                }
              }
              def.resolve(items);
            }).error(function(data) {
              def.reject(data);
            });

            return def.promise;
          };

          $scope.addItem = function(item) {
            if (item) {
              $scope.selectedItems.push(item);
              var max = parseInt($scope.section_meta.config.cardinality);
              if (max >= 1) {
                if ($scope.selectedItems.length > max) {
                  $scope.selectedItems = $scope.selectedItems.slice(-max);
                }
              }

              if (this.$$childHead.$mdAutocompleteCtrl) {
                var autocompleteCtrl = this.$$childHead.$mdAutocompleteCtrl;
                autocompleteCtrl.clear();
                // This is a hack to hide the progress bar afterwards.
                // For some reason loading is true at some point after this method finishes and never resolves because
                // our searchText is empty.
                $timeout(function () {
                  autocompleteCtrl.loading = false;
                }, 10);
              }
            }
          };

          // Initialize
          $scope.selectedItems = [];
          for (var key in $scope.record[$scope.field_name]) {
            if ($scope.record[$scope.field_name].hasOwnProperty(key)) {
              var item = {};
              item.value = key;
              item.label = $scope.record[$scope.field_name][key];
              $scope.selectedItems.push(item);
            }
          }

          // Watch for changes from input element
          $scope.$watchCollection('selectedItems', function(newValue, oldValue) {
            if (newValue == oldValue) {
              return;
            }

            $scope.record[$scope.field_name] = {};

            for (var key in newValue) {
              // If the key does not exist in the record, add it.
              if (!$scope.record[$scope.field_name].hasOwnProperty(newValue[key].value)) {
                $scope.record[$scope.field_name][newValue[key].value] = newValue[key].label;
              }
            }
          });

          // Watch for changes in selected record
          $scope.$watch('record', function(newValue, oldValue) {
            if (newValue == oldValue) {
              return;
            }

            $scope.selectedItems = [];
            for (var key in $scope.record[$scope.field_name]) {
              if ($scope.record[$scope.field_name].hasOwnProperty(key)) {
                var item = {};
                item.value = key;
                item.label = $scope.record[$scope.field_name][key];
                $scope.selectedItems.push(item);
              }
            }
          });
        }

        // File and image upload field
        if ($scope.section_meta.widget && ($scope.widget_type == 'file' || $scope.widget_type == 'image')) {
          $scope.buttonText = 'Upload';
          $scope.uploadFile = function() {
            $scope.buttonText = 'Uploading';
            $scope.uploadAsset({field_name: $scope.field_name, element_id: $scope.field_name + '-file'}).then(function(file) {
              // success
              if ($scope.multivalued) {
                var current_length = 0;
                if ($scope.record[$scope.field_name]) {
                  current_length = $scope.record[$scope.field_name].length;
                }
                else {
                  $scope.record[$scope.field_name] = [];
                }
                var delta = Math.min(current_length, $scope.field_count - 1);
                $scope.record[$scope.field_name][delta] = file;
                if ($scope.section_meta.config.cardinality == -1) {
                  $scope.field_count++;
                }
              }
              else {
                $scope.record[$scope.field_name] = file;
              }
              // Hack! @todo really after an update the server should return the saved object which should contain this
              // change.
              if ($scope.field_name == 'primary_image') {
                $scope.record.thumb_url = file.renditions.thumbnail;
              }
            }, function() {
              // failure
              $element.error();
            }).finally(function() {
              $scope.buttonText = 'Upload';
              $scope.record.needs_update = new Date();
            });
          };

          $scope.removeFile = function(ev, delta) {
            if ($scope.record.nid) {
              if ($scope.multivalued) {
                if ($scope.record[$scope.field_name][delta].fid) {
                  // Appending dialog to document.body to cover sidenav in docs app
                  var confirm = $mdDialog.confirm()
                    .title('Are you sure you want to delete this file?')
                    .content('The file ' + $scope.record[$scope.field_name][delta].filename + ' will be permanently deleted.')
                    .ok('Yes')
                    .cancel('No')
                    .targetEvent(ev);
                  $mdDialog.show(confirm).then(function () {
                    $scope.removeImage($scope.record.nid, $scope.record[$scope.field_name][delta].fid);
                  }, function () {
                    // do nothing
                  });
                }
                else {
                  $scope.record[$scope.field_name].splice(delta, 1);
                }
              }
              else {
                if ($scope.record[$scope.field_name].fid) {
                  // Appending dialog to document.body to cover sidenav in docs app
                  var confirm = $mdDialog.confirm()
                    .title('Are you sure you want to delete this file?')
                    .content('The file ' + $scope.record[$scope.field_name].filename + ' will be permanently deleted.')
                    .ok('Yes')
                    .cancel('No')
                    .targetEvent(ev);
                  $mdDialog.show(confirm).then(function () {
                    $scope.removeImage($scope.record.nid, $scope.record[$scope.field_name].fid);
                  }, function () {
                    // do nothing
                  });
                }
                else {
                  $scope.record[$scope.field_name] = null;
                }
              }
            }
            // Hack! @todo really after an update the server should return the saved object which should contain this
            // change.
            if ($scope.field_name == 'primary_image') {
              $scope.record.thumb_url = null;
            }
          };
        }

        // Workflow field
        if ($scope.section_meta.widget && $scope.widget_type == 'workflow') {
          var wid = $scope.section_meta.config.settings.wid;
          var workflow = $scope.meta.workflows[wid];

          // Initialize
          $scope.state = {
            current: $scope.record[$scope.field_name],
            selected: $scope.record[$scope.field_name]
          };
          $scope.getAllowedStates = function() {
            var current_user = user.getCurrentUser();
            var hasAnyOfRole = function(roles) {
              for (var rid in roles) {
                if (roles.hasOwnProperty(rid)) {
                  if (current_user.roles.hasOwnProperty(rid)) {
                    return true;
                  }
                }
              }
              return false;
            };
            // Fallback to the first state
            if (!$scope.state.current) {
              var min_weight = 999;
              for (var sid in workflow.states) {
                if (parseInt(workflow.states[sid].weight) < min_weight) {
                  $scope.state.current = workflow.states[sid].sid;
                  min_weight = workflow.states[sid].weight;
                }
              }
            }
            var all_states = workflow.states;
            var all_transitions = workflow.transitions;
            var allowed_states = {};
            // Allow to keep the current state
            allowed_states[$scope.state.current] = all_states[$scope.state.current].state;
            // When creating we only allow the first state.
            if ($scope.record && $scope.record.hasOwnProperty('nid') && $scope.record.nid) {
              for (var tid in all_transitions) {
                if (all_transitions[tid].sid == $scope.state.current || all_transitions[tid].sid == $scope.state.selected) {
                  // Check roles allowed to perform transition
                  if (hasAnyOfRole(all_transitions[tid].roles)) {
                    var new_tid = all_transitions[tid].target_sid;
                    allowed_states[new_tid] = all_states[new_tid].state;
                  }
                }
              }
            }
            return allowed_states;
          };

          // Watch for changes in selected state
          $scope.$watch('state.selected', function(newValue, oldValue) {
            var el = $scope.recordForm[$scope.field_name];
            if (!el) {
              return;
            }
            // If validation is pending, do not do anything
            if (el.$pending) {
              return;
            }

            // Check if the selected value is valid
            if (el.$valid) {
              $scope.state.current = newValue;
              $scope.record[$scope.field_name] = newValue;
            }
            else if (!el.$valid) {
              $scope.state.selected = $scope.state.current;
              $scope.record[$scope.field_name] = $scope.state.current;
            }
          });

          // Watch for changes in selected record
          $scope.$watch('record', function(newValue, oldValue) {
            if (newValue == oldValue) {
              return;
            }

            $scope.state.current = $scope.record[$scope.field_name];
            $scope.state.selected = $scope.record[$scope.field_name];
          });
        }

        // Select and checkboxes widgets have a list of options
        if ($scope.widget_type == 'select' || $scope.widget_type == 'checkboxes') {
          var options = [];

          // Default isSelected method
          $scope.isSelected = function (val, selected) {
            var isEqual = angular.equals(val, selected);
            if (isEqual && val.hasOwnProperty('$$mdSelectId')) {
              // Hack for some f-ed up bug with md-selects
              // @todo find a better way/update to a version of Angular material that doesn't have this bug
              if (val.$$mdSelectId != selected.$$mdSelectId) {
                this.record[this.field_name].$$mdSelectId = val.$$mdSelectId;
              }
            }
            return isEqual;
          };

          $scope.onChange = function () {
            // Since a watchCollection will not catch changes, we need to set a flag to let our watchCollection know.
            $scope.record.needs_update = new Date();
          };

          // Available options depends on the field type.
          if ($scope.section_meta.config.settings.hasOwnProperty('allowed_values')) {
            var allowed_values = $scope.section_meta.config.settings.allowed_values;
            // Term reference fields
            if (allowed_values.hasOwnProperty(0) && allowed_values[0].hasOwnProperty('vocabulary')) {
              var vocab = $scope.section_meta.config.settings.allowed_values[0].vocabulary;
              var terms = $scope.meta.taxonomy[vocab];
              for (var i in terms) {
                var key = terms[i].tid;
                var name = terms[i].name;
                var option = {
                  'value': {},
                  'label': name
                };
                option.value[key] = name;
                options.push(option);
              }
            }
            // Default
            else {
              var vals = $scope.section_meta.config.settings.allowed_values;
              for (var key in vals) {

                // Developer's Note: This is probably not the best place for this logic.
                // But I chose to do this here because other approaches would make the code base that much more WET.
                if ($scope.field_name == 'upc_code_macola') {
                  var record         = $scope.$parent.$parent.$parent.$parent.record,
                      shortened_name = key.replace('field_', ''),
                      hasEmptyUPC    = typeof record[shortened_name] == 'undefined';
                  hasEmptyUPC = hasEmptyUPC || record[shortened_name] == '';
                  // Only allow UPC field option if that field has data, but Master Case UPC (case_upc) is the default,
                  // so allow that always so that it can still be synced
                  if (shortened_name != 'case_upc' && hasEmptyUPC) {
                    continue;
                  }
                }

                var name = vals[key];
                var option = {
                  'value': key,
                  'label': name
                };
                options.push(option);
              }
            }
          }
          else if (
            $scope.section_meta.config.settings.hasOwnProperty('target_type')
            && $scope.section_meta.config.settings.hasOwnProperty('handler_settings')
          ) {
            if (
              $scope.section_meta.config.settings.target_type == 'taxonomy_term'
              && $scope.section_meta.config.settings.handler_settings.hasOwnProperty('target_bundles')
            ) {
              for (var ix in $scope.section_meta.config.settings.handler_settings.target_bundles) {
                var vocab = $scope.section_meta.config.settings.handler_settings.target_bundles[ix];
                var terms = $scope.meta.taxonomy[vocab];
                for (var i in terms) {
                  var key = terms[i].tid;
                  var name = terms[i].name;
                  if (typeof $scope.section_meta.widget.label_field != 'undefined') {
                    var label_field = $scope.section_meta.widget.label_field;
                    if (typeof terms[i][label_field].und[0].safe_value != 'undefined') {
                      name = terms[i][label_field].und[0].safe_value;
                    }
                  }
                  var option = {
                    'value': {},
                    'label': name
                  };
                  option.value[key] = name;
                  options.push(option);
                }
              }
            }
          }
          // Entityreference fields
          if ($scope.section_meta.config.settings.hasOwnProperty('referenceable_types')) {
            // We should really just use autocomplete for entityreference fields.
            console.warn($scope.field_name, 'entityreference fields should probably be autocomplete');
          }

          $scope.getOptions = function () {
            return options;
          };
        }
      }
    }
  };
});
