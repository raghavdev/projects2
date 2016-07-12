/***********************************************************************************************************************************************
 * VALIDATION
 ***********************************************************************************************************************************************
 * @description Contains,
 */
app.service('validation', ['module', '$q', 'ngValidation', 'model', '$rootScope', "$http", function(module, $q, ngValidation, model, $rootScope, $http) {

  function validation($scope) {
    var def = $q.defer();

    //
    // RECORD
    //------------------------------------------------------------------------------------------//
    // @description
    ngValidation.add_rule('record', {
      async: true,
      ele_success: function(data) {

        var id = false;

        //get a unique key for the timer
        if(data.attributes.hasOwnProperty("ng-model")) {
          id = data.attributes.getNamedItem("ng-model").value;
        }
        else if(data.attributes.hasOwnProperty("record")) {
          id = data.attributes.getNamedItem("record").value;
        }

        //start the timer
        if(id) {
          if(!$scope.timers.hasOwnProperty(id)) {
            //add the timer to the list
            var newTimer = jQuery.extend(true, {}, $scope.timer);
            $scope.timers[id] = newTimer;
          }

          //a timer per field, so that nothing gets lost
          $scope.timers[id].run(data);
        }
      },
      events: {
        keydown: ['text', 'password', 'email', 'textarea', 'tel'],
        keyup: ['text', 'password', 'email', 'textarea', 'tel'],
        click: ['submit', 'checkbox', 'radio'],
        change: ['checkbox', 'radio', 'select', 'select-one'],
        paste: ['text', 'password', 'email', 'textarea', 'tel'],
        blur: ['password', 'email', 'textarea'],
      },
      validators: {
        url: function(data) {
          var str = data.value;
          var pattern = new RegExp('^(https?:\\/\\/)?'+ // protocol
                '((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.)+[a-z]{2,}|'+ // domain name
                '((\\d{1,3}\\.){3}\\d{1,3}))'+ // OR ip (v4) address
                '(\\:\\d+)?(\\/[-a-z\\d%_.~+]*)*'+ // port and path
                '(\\?[;&a-z\\d%_.~+=-]*)?'+ // query string
                '(\\#[-a-z\\d_]*)?$','i'); // fragment locator
          if(!pattern.test(str)) {
            return false;
          }

          return true;
        },
        always: function() {
          //nothing to validate
          return true;
        },
        numeric: function(data, args, ignored, additional) {

          if(!ignored) {
            ignored = "";
          }

          // store current positions in variables
          var start = data.selectionStart,
              end = data.selectionEnd;

           //strip any character that isnt numeric
          var re = new RegExp("[^0-9"+ignored+"]+");

          data.value = data.value.replace(re,'');

          if(additional) {
            additional.call(this, data);
          }

          // restore from variables...
          data.setSelectionRange(start, end);

          return true;
        },
        decimal: function(data, args) {

          var dec = function(data) {

            var decimalPlaces = 2;

            if(data.hasAttribute("decimal-places")) {
              decimalPlaces = data.getAttribute("decimal-places");
            }

            //check the decimal places
            if(data.value.toString().indexOf(".") !== -1 && data.value.toString().split(".")[1].length > decimalPlaces) {
              data.value = +(Math.round(data.value + "e+"+decimalPlaces)  + "e-" + decimalPlaces);
            }
          };

          if(this.opts) {
            return this.opts.validators.numeric(data, args, '\\.', dec);
          }
          else if(this.numeric) {
            return this.numeric(data, args, '\\.', dec);
          }

          return true;
        },
        validatepdv: function(data) {

          //validate decimal
          this.opts.validators.decimal(data);

          var pdv = 1;
          var parentValue = 0;

          if(data.hasAttribute("pdv")) {
            pdv = data.getAttribute("pdv");
          }

          if(data.hasAttribute("parent-pv")) {
            var p = data.getAttribute("parent-pv");
            parentValue = $scope.record[p];
          }

          var calcValue = parseFloat(parentValue/pdv);
          calcValue = Math.round(100 * calcValue);

          if(data.value != "" && data.value != calcValue) {
            //set the warning message

            //set a class that that the field is not validated
            angular.element('#'+data.id).addClass('validate-warning');
          }
          else {
            angular.element('#'+data.id).removeClass('validate-warning');
          }

          return true;
        },
        modifiedDate: function(data) {
          //this one is a little more custom,

          //do an update to the modified date
          $scope.record.ingredients_modified = Math.floor(Date.now() / 1000);

          //nothing to validate
          return true;
        },
        dependent: function(data) {
          if(data.hasAttribute("dependant") && data.hasAttribute("dependant").value != "" && data.value != "") {
            angular.element("#"+data.attributes.dependant.value).prop( "disabled", false );
            $rootScope.ecomparentid = data.value;
          }
          return true;
        }
      }
    });

    $rootScope.loadValidation = function(args) {
      ngValidation.init(args.rule);
    };

    def.resolve();
    return def.promise;
  };

  $rootScope.initValidation = function() {
    ngValidation.init();
  };

  module.register({name:'validation', fn: validation})
}])
