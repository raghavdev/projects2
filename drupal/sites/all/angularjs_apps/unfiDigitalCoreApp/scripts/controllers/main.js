'use strict';

app.controller('MainCtrl', function($scope, model, $location, utils, $injector, $q, $http, module, $parse, $rootScope) {
  // Hack to disable loading certain components until we have our meta data.
  $scope.isBootstrapped = false;
  $scope.productDetailsMetaFetch = function() {
    $http.get('/service/digitalcore/product_details').
      success(function (data, status, headers, config) {
        $scope.meta = data.content_types.product_details;
        if (data.workflows) {
          $scope.meta.workflows = data.workflows;
        }
        if (data.taxonomy) {
          $scope.meta.taxonomy = data.taxonomy;
        }
        if (data.field_collections) {
          $scope.meta.field_collections = data.field_collections;
        }
        $scope.isBootstrapped = true;
      }).
      error(function (data, status, headers, config) {
        // log error
      });
  };
  $scope.productDetailsMetaFetch();
  // Current View
  $scope.view = ($location.path().split('/')[1] === "")? 'products': $location.path().split('/')[1];

  //apply the active class to the view that is curently selected
  var links = angular.element(".links");
  for(var i in links[0].children) {

    var child = links[0].children[i];

    if(child.innerText && child.children[0]) {
      if(child.innerText.toLowerCase() == $scope.view) {
        //add the active class to the child which is the a link
        child.children[0].classList.add("active");
      }
      else {
        child.children[0].classList.remove("active");
      }
    }
  }

  //
  // MAIN CONTENT MODELS
  //------------------------------------------------------------------------------------------//
  // @description
  $scope.resource = $scope.view;

  $scope.records = [];

  $scope.record = null;

  $scope.selectedRecords = [];

  //
  // RECORDS
  //------------------------------------------------------------------------------------------//
  //

  /**
   * HAS RECORDS
   *
   * @description Used to hide/show empty data sets appropriately
   * @type {Boolean}
   */
  $scope.hasRecords = true;

  /**
   * NO PRODUCTS TEXT
   *
   * @description Used to display
   * @type {String}
   */
  $scope.noRecordsText = "No "+$scope.resource+" match those filters.";

  $scope.canCreateProduct = function() {
    var userService = $injector.get('user');
    return userService.hasPerm('create blue marble products');
  };

  /**
   * UPDATE RESOURCE
   *
   * @description Is called on a form field when validation passes.
   * @param  {[type]} el [description]
   * @return {[type]}    [description]
   */
  $scope.updateResource = function(el) {
    if(!$scope.record) return;
    if (!$scope.record[$scope.meta.identifier]) return;

    var field = null,
        value = $parse(el.getAttribute('ng-model'))($scope),
        body = {},
        resource = $scope.resource,
        identifier = $scope.record[$scope.meta.identifier];

    if(el.hasAttribute('ng-model')) {
      field = el.getAttribute('ng-model').split('record.')[1];
    }

    //allow for overriding the resource and the identifier
    if(el.hasAttribute('resource')) {
      resource = el.getAttribute('resource');
    }

    if(el.hasAttribute('identifier')) {
      identifier = el.getAttribute('identifier');
    }

    //there are 2 methods in play for how this works right now
    //will shift to the single if priorities and time allow
    if(!field) {
      //get the field name from the record attribute
      field = el.getAttribute('record');
      value = $scope.record[field];

      if(!value) {
        value = el.value;
      }
    }

    body[field] = value;

    return model.put(resource, {HTTP:{PUT:{url:resource+'/'+identifier}}, forceSerialize: true, useConfigOpts: false}, body).then(function(data) {
      return data;
    });
  };

  //similar to above but this update takes a record not an element
  $scope.updateResourceRecord = function() {
    var deferred = $q.defer();

    if( ! $scope.record || ! $scope.record[$scope.meta.identifier]) {
      // Quick hack to force this function to return a promise, resolving to false for empty records
      setTimeout(function() {
        deferred.resolve(false);
      }, 10);

      return deferred.promise;
    }

    return model.put($scope.resource, {HTTP:{PUT:{url:$scope.resource+'/'+$scope.record[$scope.meta.identifier]}}, forceSerialize: true, useConfigOpts: false}, $scope.record).then(function(data) {
      return data;
    });
  };
  //
  //
  // RECORD
  //------------------------------------------------------------------------------------------//
  // @description

  /**
   * RECORD
   *
   * @description Holds reference to the currently loaded product in the detail views.
   * @type {Object}
   */
  $scope.record = null;

  /**
   * LOAD THE APPROPRIATE PRODUCT
   *
   * @param  {[type]} ein [description]
   * @return {[type]}     [description]
   */
  $scope.loadRecord = function(record) {
    if ($scope.record == record) {
      $scope.record = null;
    }
    else {
      // Load record
      $scope.record = record

      // if mobile and filter open close filter
      if ($scope.isMobile && $scope.filtersOpen === true) {
        $scope.filtersOpen = false;
      }
    }
    ;
  };

  $scope.clearRecord = $rootScope.clearRecord = function() {
    $scope.new_asset = $scope.record = null;
  };

  $scope.clearNewAsset = $rootScope.clearNewAsset = function() {
    $scope.new_asset = null;
  };

  //delete the selected assets from the DAM
  $scope.removeSelected = $rootScope.removeSelected = function() {

    var def = $q.defer();

    var newRecords = [];
    var removeList = [];

    //push the selected items on to the collection
    for(var idx in $scope.records) {

      //if its checked we wont add it to the new running list
      if($scope.records[idx].actioncheckbox) {
        removeList.push($scope.records[idx]);
      }
      else {
        newRecords.push($scope.records[idx]);
      }
    }

    $scope.removeContent(removeList, def);

    //apply the edited list back
    $scope.records = newRecords;
    $scope.record = null;

    return def.promise;
  };

  //recurse till there are no more
  $scope.removeContent = function(list, def) {

    if(list.length > 0) {

      var obj = list[0];

      list.splice(0, 1);

      if($scope.view == "assets") {
        $http({method: 'DELETE', url: '/service/digitalcore/assets/'+obj.fid}).success(function() {
          $scope.removeContent(list, def);
        });
      }
      else {
        $http({method: 'DELETE', url: '/service/digitalcore/products/'+obj.nid}).success(function() {
          $scope.removeContent(list, def);
        });
      }
    }
    else {
      def.resolve();
    }
  };

  $scope.selectAll = function(masterselector) {

    masterselector = !masterselector;

    $scope.masterSelector = masterselector;

    for(var idx in $scope.records) {
      //if its checked we wont add it to the new running list
      if($scope.records[idx].actioncheckbox != masterselector) {
        $scope.records[idx].actioncheckbox = masterselector;
      }
    }
  };

  //set the defaults on the cmp range if selected
  $scope.cmpSet = function() {
    if($scope.record.cmp_include == 2) {
      var data = {};

      var currentTime = new Date();

      data['cmp_start_day'] = (!$scope.cmp_start_day ? currentTime.getDate() : $scope.cmp_start_day);
      data['cmp_start_year'] = (!$scope.cmp_start_year ? currentTime.getFullYear() : $scope.cmp_start_year);
      data['cmp_start_month'] = (!$scope.cmp_start_month ? currentTime.getMonth() : $scope.cmp_start_month);

      data['cmp_end_day'] = (!$scope.cmp_end_day ? currentTime.getDate() : $scope.cmp_end_day);
      data['cmp_end_year'] = (!$scope.cmp_end_year ? (currentTime.getFullYear() + 1) : $scope.cmp_end_year);
      data['cmp_end_month'] = (!$scope.cmp_end_month ? currentTime.getMonth() : $scope.cmp_end_month);

      return model.put('products', {HTTP:{PUT:{url:'products/'+$scope.record.nid}}, forceSerialize: true, useConfigOpts: false}, data).then(function(data) {
        return data;
      });
    }
  };

  //apply the cmp settings to the selected products
  $scope.cmpApply = function(cmpstatus) {

    var data = {};

    data['cmp_include'] = cmpstatus;

    if(cmpstatus == 2) {

      var currentTime = new Date();

      data['cmp_start_day'] = (!angular.element("#alt-start-day").val() ? currentTime.getDate() : angular.element("#alt-start-day").val());
      data['cmp_start_year'] = (!angular.element("#alt-start-year").val() ? currentTime.getFullYear() : angular.element("#alt-start-year").val());
      data['cmp_start_month'] = (!angular.element("#alt-start-month").val() ? currentTime.getMonth() : angular.element("#alt-start-month").val());

      data['cmp_end_day'] = (!angular.element("#alt-end-day").val() ? currentTime.getDate() : angular.element("#alt-end-day").val());
      data['cmp_end_year'] = (!angular.element("#alt-end-year").val() ? (currentTime.getFullYear() + 1) : angular.element("#alt-end-year").val());
      data['cmp_end_month'] = (!angular.element("#alt-end-month").val() ? currentTime.getMonth() : angular.element("#alt-end-month").val());

    }

    if($scope.masterSelector) {
      data['product_ids'] = "filter";

      data['filter_data'] = $scope.search;
    }
    else {
      var product_ids = "";

      for(var idx in $scope.records) {
        //if its checked we wont add it to the new running list
        if($scope.records[idx].actioncheckbox) {
          product_ids += $scope.records[idx].nid+",";
          $scope.records[idx].cmp_include = cmpstatus;
        }
      }

      data['product_ids'] = product_ids;
    }

    //open a spinner modal
    $scope.modal("addCMP");
    $scope.modalOpen = true;

    model.put('products', {HTTP:{PUT:{url:'products/-1'}}}, data).then(function(data) {
      //kill the spinner
      if($scope.modalOpen) {
        $scope.modalClose();
      }
    });
  };

  $scope.ecomApply = function(ecomStatus) {
    //open a spinner modal
    $scope.modal("addCMP");
    $scope.modalOpen = true;

    var product_ids = [];

    for(var idx in $scope.records) {
      //if its checked we wont add it to the new running list
      if($scope.records[idx].actioncheckbox) {
        //product_ids += $scope.records[idx].nid+",";
        product_ids.push($scope.records[idx].nid);
        $scope.records[idx].ecom_include = ecomStatus;
      }
    }

    var op = (ecomStatus ? "add" : "remove");

    model.put('products', {HTTP:{PUT:{url:'feeds/ecom_feed/'+op + '/-1'}}}, product_ids).then(function(data) {
      //kill the spinner
      if($scope.modalOpen) {
        $scope.modalClose();
      }
    });
  };

  //
  // GENERAL SCOPE PROPERTIES
  //------------------------------------------------------------------------------------------//
  // @description
  $scope.selected = 'selected';
  $scope.filtersOpen = true;

  //
  // HELPER FUNCTIONS
  //------------------------------------------------------------------------------------------//
  // @description Misc DOM helpers.

  /**
   * TOGGLE FILTERS DISPLAY
   *
   * @description  show/hide the filters panel
   */
  $scope.toggleFilters =  function() {
    if (!$scope.filtersOpen) {
      $scope.filtersOpen = true;

      // if mobile and record open close record
      if ($scope.isMobile && $scope.record != null) {
        $scope.record = null;
      }
    }
    else {
      $scope.filtersOpen = false;
    }
  }

  /**
   * DETECT MOBILE
   *
   * @description  detects mobile
   */
   $scope.detectMobile = function() {
      if( navigator.userAgent.match(/Android/i)
        || navigator.userAgent.match(/webOS/i)
        || navigator.userAgent.match(/iPhone/i)
        || navigator.userAgent.match(/iPad/i)
        || navigator.userAgent.match(/iPod/i)
        || navigator.userAgent.match(/BlackBerry/i)
        || navigator.userAgent.match(/Windows Phone/i)
      ){
        $scope.isMobile = true;
      }
      else {
        $scope.isMobile = false;
      }
   };
   $scope.detectMobile();

  /**
   * FORMATS DATE
   *
   * @description  formats into 1-1-1970
   * @param  {[type]} date [description]
   * @return {[type]}      [description]
   */
  $scope.formatDate =  function(date) {

    if(!date) return "";

    var formatted = '',
        D = new Date(parseInt(date)),

        year = D.getFullYear(),

        month = D.getMonth()+1,

        day = D.getDate();

    return formatted = month + '-' + day + '-' + year;
  };

  /**
   * IS ACTIVE
   * @param  {[type]}  link [description]
   * @return {Boolean}      [description]
   */
  $scope.isActive = function(link) {
    var isActive = '';

    if(link === $scope.view) {
      isActive = 'selected';
    }

    return isActive;
  };

  /**
   * TO UPPER
   *
   * @description
   * @param  {[type]} string [description]
   * @return {[type]}        [description]
   */
  $scope.toUpper = function(string) {
    return string.toUpperCase();
  };

  //allow for indexed object to ng-repeat without anoying sort
  $scope.notSorted = function(obj){
    if (!obj) {
        return [];
    }
    return Object.keys(obj);
  };

  //convert the string to time
  $scope.getTime = function(data) {
    if(jQuery.isNumeric(data)) {
      var myDate = new Date( data *1000);
      var minutes = myDate.getMinutes();

      data = myDate.toDateString() + " " + myDate.getHours() + ":" + (minutes < 10 ? '0' : '') + minutes;
    }

    return data;
  };

  //returns the name of the category of the active record
  $scope.getCategory = function() {
    if($scope.record && $scope.record.category) {
      for (var first in $scope.record.category) break;
      return $scope.record.category[first];
    }
    return "";
  };

  //
  // TIME MANAGEMENT
  //------------------------------------------------------------------------------------------//
  // @description

  /**
   * TIMER
   *
   * @description Object that stores all time related functionality
   * @type {Object}
   */

  var Timer = {};

  // Debounce Interval
  Timer.debounceInterval = 100;

  // Time value that gets manipulated
  Timer.currentTime;

  // Store the setInterval function
  Timer.interval;

  /**
   * RUN
   *
   * @description Runs the timer down.
   * @return {[type]} [description]
   */
  Timer.run = function(data) {
    var self = this;

    // Set/reset time.
    this.currentTime = this.debounceInterval;

    // Prevent the current interval from running;
    clearInterval(self.interval);

    // Create a new one.
    // We use setInterval here to get as close to a 1ms
    // representation as possible. Traditional forloop
    // runs way faster than 1ms/iteration. (if doing a simple -- operation like below, that is.)
    this.interval = setInterval(function() {
      // Decrement time
      self.currentTime--;

      // Check for timeout.
      if(self.currentTime === 0) {
        // Run the callback
        self.onTimeout(data);
        // If it timesout, clear the interval
        clearInterval(self.interval);
      }
    }, 1);
  };

  /**
   * ON TIMEOUT
   *
   * @description Function to run when a clock runs out successfully
   * @type {[type]}
   */
  Timer.onTimeout = $scope.updateResource;

  $scope.timer = Timer;
  $scope.timers = {};

    //
    // MODULE LOADING
    //------------------------------------------------------------------------------------------//
    // @description
    module.load([
      //'content',
      'collections',
      'categories',
      'brands',
      'products',
      'params',
      'lazyload',
      'image',
      'search',
      'filters'
    ], $scope).then(function (data) {
      module.load('sorting', $scope);
    });

    /**
     * TRACK BY
     *
     * @type {[type]}
     */
  //  $scope.trackBy = $scope.meta[$scope.view].trackBy;
});
