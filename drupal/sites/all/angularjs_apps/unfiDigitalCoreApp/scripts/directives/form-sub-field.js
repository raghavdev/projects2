'use strict';

app.directive('formsubfield', function(user, $q, $http, $timeout, $parse) {
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
    link: function($scope, $element, $attrs, $ngModel) {
      $scope.getWidgetUrl = function() {
        if ($scope.widget_type) {
          var type = $scope.widget_type;
          return Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/form-field-' + type + '.html';
        }
      };
    },
    controller: function($scope, $element, $attrs, $compile, $mdDialog) {
      var getIdentifierField = function(entity_type) {
        var identifier = false;
        // @todo don't rely on $scope.meta, maybe we need a service for this?
        if (entity_type == 'node') {
          identifier = 'nid';
        }
        else if ($scope.meta && $scope.meta[entity_type] && $scope.meta[entity_type].identifier) {
          identifier = $scope.meta[entity_type].identifier;
        }
        else if (entity_type == 'taxonomy_term') {
          identifier = 'tid';
        }

        return identifier;
      };

      $scope.field = {
        value: null,
        name: $scope.$eval($attrs.formsubfield) || $attrs.formfield,
        config: $scope.$parent.collection_field || {
          widget: {
            type: 'text_textfield'
          }
        }
      };

      $scope.field.config.disabled = $scope.nopermission || false;

      // Make sure that field exists before continuing
      if ($scope.field && $scope.field.name && $scope.field.config) {
        //console.log($scope.field.config);
        /**
         * @defgroup formsubfield_template_variables formsubfield scope variables used in templates.
         * @{
         * These variables are required by the current form-field-*.html templates.
         *
         * These are the glue that allow this directive use the same templates as the formfield directive.
         * @}
         */

        /**
         * $scope.field_name is used in the templates to add css classes and determine the property to update
         * on the model.
         *
         * @ingroup formsubfield_template_variables
         */
        $scope.field_name = $scope.field.name;

        /**
         * $scope.section_meta is the Drupal field configuration, which is used in the templates to determine
         * the field labels, required state and descriptions, etc.
         *
         * @ingroup formsubfield_template_variables
         */
        $scope.section_meta = $scope.field.config;

        /**
         * $scope.widget_type is used to determine the type of input to display.
         *
         * @ingroup formsubfield_template_variables
         */
        var widget_type =  $scope.field.config.widget.type;
        $scope.drupal_widget_type = widget_type;
        $scope.widget_type = widget_type_map[widget_type] || 'textinput';

        /**
         * $scope.record is used as the model for the field, here it's keyed by the current field collection iterator
         *
         * @ingroup formsubfield_template_variables
         */
        // Create new scope-specific sub-record
        $scope.record = $scope.$parent.record[$scope.$parent.field_name][$scope.$parent.$parent.collection_delta];
        // Index in multi-valued collections
        $scope.collection_index = $scope.$parent.$parent.collection_delta;

        /**
         * $scope.field.value is used as the model for the field (FUTURE IMPLEMENTATION)
         * Currently used by Autocomplete function below
         *
         * @ingroup formsubfield_template_variables
         */
        $scope.field.value = $scope.record[$scope.field.name];

        // Since this directive is only used in field collections currently, the entity type and bundle are known
        // to come from the parent field.
        /**
         * $scope.entity_type is used in the drupal-validate directive to set the Drupal entity type being validated.
         *
         * @ingroup formsubfield_template_variables
         */
        $scope.entity_type = $scope.field.config.entity_type;

        /**
         * $scope.bundle is used in the drupal-validate directive to set the Drupal entity bundle being validated.
         *
         * @ingroup formsubfield_template_variables
         */
        $scope.bundle = $scope.field.config.bundle;

        // Watch for changing selection of the parent record
        $scope.$parent.$watch('record.nid', function(newVal, oldVal) {
          if (newVal != oldVal) {
            $scope.record = $scope.$parent.record[$scope.$parent.field_name][$scope.$parent.$parent.collection_delta];
            // Index in multi-valued collections
            $scope.collection_index = $scope.$parent.$parent.collection_delta;
            $scope.field.value = $scope.record[$scope.field.name];
          }
        });

        // Send updates to collection's record up in scope to the main "record" scope
        $scope.$watchCollection('record', function(newCollection, oldCollection) {
          if (newCollection === oldCollection) {
            return;
          }
          $scope.collection_update = $scope.record;
          $scope.$emit('collection_update', {data: '$scope.emit'});
        });

        /**
         * Widget Types
         */

        /**
         * Date fields have different input types depending on the granularity
         */
        if ($scope.widget_type == 'date') {
          // Determine the input type by the cardinality.
          if ($scope.section_meta.config.settings.granularity.day) {
            // Has a date, check if it has a time
            if ($scope.section_meta.config.settings.granularity.hour) {
              $scope.widget_type = 'datetime-local';
            }
          }
          else if ($scope.section_meta.config.settings.granularity.month) {
            $scope.widget_type = 'month';
          }
          else if ($scope.section_meta.config.settings.granularity.hour) {
            $scope.widget_type = 'time';
          }

          // We need to convert our model value to a Date object and back again.
          $scope.date_object = {
            value: null,
          };
          $scope.$watch('date_object.value', function (newVal, oldVal) {
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

        /**
         * Autocomplete field
         */
        if ($scope.field.config.widget.type && $scope.field.config.widget.type == 'entityreference_autocomplete') {
          $scope.getMatches = function(text) {
            var def = $q.defer();
            var url = '/bluemarble/autocomplete';
            if ($scope.section_meta.config.cardinality == 1) {
              url += '/single';
            }
            else {
              url += '/tags';
            }

            url += '/' + $scope.field.config.field_name;
            url += '/' + $scope.entity_type + '/' + $scope.bundle + '/';
            var identifier = getIdentifierField($scope.entity_type);
            if ($scope.record && identifier && $scope.record.hasOwnProperty(identifier) && $scope.record[identifier]) {
              url += $scope.record[identifier];
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
          for (var key in $scope.field.value) {
            if ($scope.field.value.hasOwnProperty(key)) {
              //console.log($scope.field.value);
              var item = {};
              item.value = key;
              item.label = $scope.field.value[key];
              $scope.selectedItems.push(item);
            }
          }

          // Watch for changes from input element
          $scope.$watchCollection('selectedItems', function(newValue, oldValue) {
            if (newValue == oldValue) {
              return;
            }

            $scope.record[$scope.field.name] = {};
            for (var key in newValue) {
              // If the key does not exist in the record, add it.
              if (!$scope.record[$scope.field.name].hasOwnProperty(newValue[key].value)) {
                $scope.record[$scope.field.name][newValue[key].value] = newValue[key].label;
              }
            }
          });

          // Watch for changes in selected record
          $scope.$parent.$watch('record.nid', function(newValue, oldValue) {
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

        /**
         * File and image upload field
         */
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
            if ($scope.entity_type == 'node' && $scope.record.nid) {
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
            else {
              // @todo make the api for removing files from entities not only work for product nodes.
              console.warning('Removing files from other entities besides nodes is not implemented in the API.');
            }
            // Hack! @todo really after an update the server should return the saved object which should contain this
            // change.
            if ($scope.field_name == 'primary_image') {
              $scope.record.thumb_url = null;
            }
          };
        }

        /**
         * Workflow field
         */
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
            var identifier = getIdentifierField($scope.entity_type);
            if ($scope.record && $scope.record.hasOwnProperty(identifier) && $scope.record[identifier]) {
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

        /**
         * Select and checkboxes widgets have a list of options
         */
        if ($scope.widget_type == 'select' || $scope.widget_type == 'checkboxes') {
          var options = [];

          // Default isSelected method
          $scope.isSelected = function (val, selected) {
            var isEqual = angular.equals(val, selected);

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

          //$scope.options = options;
          var currentRow = $scope.collection_delta;

          $scope.getOptions = function () {
            return options;
          };
        }
      }
    }
  };
});
