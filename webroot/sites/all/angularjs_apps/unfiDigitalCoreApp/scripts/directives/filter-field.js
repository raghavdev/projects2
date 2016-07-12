app.directive('filterField', function($q, $http, $parse) {
  // Maps Drupal widgets to Angular templates.
  var widget_type_map = {
    'number': 'numberrange',
    'options_onoff': 'boolean',
    'options_select': 'multiselect',
    'options_buttons': 'multiselect',
    'taxonomy_autocomplete': 'autocomplete', // Product Category
    'node_reference_autocomplete': 'autocomplete', // Brand
    'entityreference_autocomplete': 'multiselect',
    'text_textarea': 'keyword',
    'text_textfield': 'keyword',
    'workflow_default': 'multiselect',
    'file_generic': 'hasfile',
    'image_image': 'hasfile',
    'date_text': 'daterange' // Active Date
  };

  return {
    restrict: 'A',
    scope: true,
    replace: true,
    template: '<div ng-include="getWidgetUrl()"></div>',
    link: function ($scope, $element, $attrs) {
      $scope.getWidgetUrl = function () {
        if ($scope.widget_type) {
          var type = $scope.widget_type;
          return Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/filter-field-' + type + '.html';
        }
      };
    },
    controller: function ($scope, $element, $attrs, $compile) {
      $scope.filterField = $attrs.filterField; // The Drupal field name
      $scope.filterName = $attrs.filterName; // The name of the parameter when performing the search
      $scope.filterLabel = $attrs.filterLabel; // The label to display

      // Transforms taxonomy terms to an object suitable for our multiselect template.
      function transformTerms(vocab) {
        var options = [];
        var terms = $scope.meta.taxonomy[vocab];
        for (var i in terms) {
          var key = terms[i].tid;
          var name = terms[i].name;
          var option = {
            'value': key,
            'label': name
          };
          options.push(option);
        }

        return options;
      }

      // Sets the value for the current filter and triggers a search.
      function applyFilter(value) {
        var getter = $parse($scope.filterName);
        var setter = getter.assign;
        var context = $scope.search[$scope.view];
        setter(context, value);
        // Trigger a search query
        $scope.query();
      }

      // Make sure that field exists before
      if ($scope.meta && $scope.meta.fields && $scope.meta.fields[$scope.filterField]) {
        $scope.section_meta = $scope.meta.fields[$scope.filterField];

        var widget_type = ($scope.section_meta.widget && $scope.section_meta.widget.type) ? $scope.section_meta.widget.type : 'text_textfield';
        $scope.drupal_widget_type = widget_type;
        $scope.widget_type = widget_type_map[widget_type] || 'keyword';

        // Multiselect filters
        if ($scope.widget_type == 'multiselect') {
          $scope.clearSelection = function() {
            $scope.selectedNodes = [];
            applyFilter([]);
          };

          var options = [];

          // Workflow fields
          if ($scope.drupal_widget_type == 'workflow_default') {
            var wid = $scope.section_meta.config.settings.wid;
            var workflow = $scope.meta.workflows[wid];
            var all_states = workflow.states;
            for (var key in all_states) {
              if (all_states[key].name != '(creation)') {
                option = {
                  'value': all_states[key].sid,
                  'label': all_states[key].state
                };
                options.push(option);
              }
            }
          }

          // Available options depends on the field type.
          if ($scope.section_meta.config.settings.hasOwnProperty('allowed_values')) {
            var allowed_values = $scope.section_meta.config.settings.allowed_values;
            // Term reference fields
            if (allowed_values.hasOwnProperty(0) && allowed_values[0].hasOwnProperty('vocabulary')) {
              var vocab = $scope.section_meta.config.settings.allowed_values[0].vocabulary;
              options = transformTerms(vocab);
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
          // Entityreference fields
          if ($scope.section_meta.config.settings.hasOwnProperty('target_type')) {
            var target_type = $scope.section_meta.config.settings.target_type;
            if (target_type == 'taxonomy_term') {
              for (var vocab in $scope.section_meta.config.settings.handler_settings.target_bundles) {
                if ($scope.section_meta.config.settings.handler_settings.target_bundles.hasOwnProperty(vocab)) {
                  options = options.concat(transformTerms(vocab));
                }
              }
            }
            else {
              // @todo make this support other node types
              // Hack. We support a special node type, brands
              if (target_type == 'node' && $scope.section_meta.config.settings.handler_settings.target_bundles.hasOwnProperty('brand')) {
                // We have a service to get brands
                $scope.getBrands().then(function (data) {
                  var options = [];
                  for (var i in data) {
                    var key = data[i].nid;
                    var label = data[i].title;
                    var option = {
                      'value': key,
                      'label': label
                    };
                    options.push(option);
                  }
                  $scope.treeData = options;
                });
              }
              else {
                // We should really just use autocomplete for entityreference fields.
                console.warn($scope.filterField, 'entityreference fields should probably be autocomplete');
              }
            }
          }

          $scope.treeData = options;

          $scope.selectedNodes = [];

          $scope.treeConfig = {
            nodeChildren: "children",
            dirSelectable: true,
            multiSelection: true
          };

          $scope.showSelected = function(node, selected) {
            var values = [];
            for (var i in $scope.selectedNodes) {
              values.push($scope.selectedNodes[i].value);
            }
            applyFilter(values);
          }
        }
      }
      else {
        // Attempt to use a keyword field
        $scope.widget_type = 'keyword';
      }

      // Keyword filters -- not all of these are real Drupal fields
      if ($scope.widget_type == 'keyword') {
        $scope.input = {
          keyphrase: ''
        };
        $scope.clearSelection = function() {
          $scope.input.keyphrase = '';
          applyFilter('');
        };

        $scope.findMatches = function() {
          applyFilter($scope.input.keyphrase);
        };
      }
    }
  };
});
