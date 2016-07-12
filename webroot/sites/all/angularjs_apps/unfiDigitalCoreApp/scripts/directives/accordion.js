app.directive('accordion', function($parse, $sce, $rootScope) {
  return {
    scope: true,
    restrict: 'EA',
    replace: true,
    templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/accordion.html',
    controller: function($scope, $element, $attrs, $compile) {

      // This prevents the child elements from being compiled
      // every time a toggle is clicked.
      var isCompiled;

      // Get context for recursive $parsing
      var context = $parse($attrs.accordionModelContext)($scope) || $scope;
      var content;

      // Set state
      $scope.state = $attrs.accordionState || 'closed';

      // Set model
      if($attrs.accordionModel) {

        $scope.acc_model = $parse($attrs.accordionModel)(context);

        if($scope.acc_model && $scope.acc_model.constructor === Function) {
          $scope.acc_model().then(function(data) {
            $scope.acc_model = data;
          });
        }
      }

      // Set Direction
      $scope.reversed = false;

      if($attrs.hasOwnProperty('accordionReversed')) {
        $scope.reversed = true;
      }

      $scope.setSelected = function(){
        var tid = parseInt($scope.acc_model.tid);

        if($scope.record) {
          if($scope.record.asset_category.indexOf(tid) !== -1) {
            return 'selected';
          }
        }
        return '';
      }

      /**
       * GET HEADER TEMPLATE
       *
       * @description Resolves template header file path.
       * @return {[type]} [description]
       */
      $scope.getHeaderTemplate = function() {
        var path;

        path = ($attrs.accordionHeaderTemplate)? Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/accordion/'
          + $attrs.accordionHeaderTemplate : Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/accordion/default-header.html';

        return path;
      };

      /**
       * GET CONTENT TEMPLATE
       *
       * @description Resolves content template
       * @return {[type]} [description]
       */
      $scope.getContentTemplate = function() {
        var path;

        path = ($attrs.accordionContentTemplate)? Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/accordion/'
          + $attrs.accordionContentTemplate : Drupal.settings.unfiDigitalCoreApp.modulePath + 'scripts/directives/templates/accordion/default-content.html';

        return path;
      };

      /**
       * TOGGLE STATE
       *
       * @description Opens/shuts an accordion.
       * @return {[type]} [description]
       */
      $scope.toggleState = function() {
        var acc = $element[0].querySelectorAll('.accordion')[0];

        if(acc.classList.contains('closed')) {
          acc.classList.remove('closed');
          acc.classList.add('open');
          if(!isCompiled) {
            $compile(content)($scope);
            isCompiled = true;
          }
        } else if(acc.classList.contains('open')) {
          acc.classList.remove('open');
          acc.classList.add('closed');
        }
      };

      /**
       * LOAD CHILDREN
       *
       * @description Acts as a lazy-loader to child accordions so that they all don't have to be loaded at once.
       *              The biggest drawback to this is that obviously the HTML (and the existence of a children property)inside this function is unique to filter accordions.
       *              The solution would be to include a "lazy" attribute and GET the HTML fragment.
       * @return {[type]} [description]
       */
      $scope.loadChildren = function() {
        var html = '';

        if($scope.acc_model  && $scope.acc_model.children && $scope.acc_model.children.length) {
          html = '<div ng-repeat="child in acc_model.children | orderBy:\'order\'">' +
                    '<div accordion accordion-state="closed" accordion-model="child" accordion-header-template="'+$attrs.accordionHeaderTemplate+'" accordion-content-template="'+$attrs.accordionContentTemplate+'" on-accordion-item-click="'+$attrs.onAccordionItemClick+'"></div>' +
                  '</div>'

          content = $element[0].querySelector('.accordion-content');
          // Notice how we don't $compile here, only append.
          // Compilation occurrs during the opening so as
          angular.element(content).html(html);
          $scope.nochildren = "";
        }
        else {
          $scope.nochildren = "invisible";
        }

        return;
      };
    },
    link: function($scope, $elem, $attrs) {
      $scope.onAccordionItemClick = $parse($attrs.onAccordionItemClick)($scope);
    }
  }
})
