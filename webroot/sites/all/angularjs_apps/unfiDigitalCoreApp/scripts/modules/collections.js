/***********************************************************************************************************************************************
 * COLLECTIONS MODULE
 ***********************************************************************************************************************************************
 * @description manages all things collections.
 */
app.service('collections', ['module', '$q', 'model', '$rootScope', '$http', 'user', function(module, $q, model, $rootScope, $http, user) {
  function collections($scope) {
    var prom = $q.defer();

    $scope.selectedCollection = '';

    //
    // COLLECTIONS
    //------------------------------------------------------------------------------------------//
    // @description

    $scope.getCollections = function() {
      if(!$scope.collections) {

        if (!$scope.collectionspromise) {

          $scope.collectionspromise = $q.defer();

          var type = $scope.view == "products" ? "collection" : "asset_collection";

          if (user.getCurrentUser()) {
            model.get('collections', {
              HTTP: {GET: {url: 'collections/' + user.getCurrentUser().uid + '?type=' + type}},
              localize: false
            }).then(function (data) {
              $scope.collections = data;
              $scope.collectionspromise.resolve(data);
            });
          }
        }
      }
      else {
        $scope.collectionspromise = $q.defer();
        $scope.collectionspromise.resolve($scope.collections);
      }

      return $scope.collectionspromise.promise;
    };

    $scope.downloadCollection = function() {
      $http({method: 'GET', url: '/service/digitalcore/collection/download/'+$scope.collectionSelected});
    }

    //create a new collection with the name specified
    $scope.createCollection = $rootScope.createCollection = function(data) {
      var collection = {};

      if($scope.view == "products") {
        collection.type = 'collection';
      }
      else if($scope.view == "assets") {
        collection.type = 'asset_collection';
      }

      collection.title = data;

      if(user.getCurrentUser()) {
        collection.uid = user.getCurrentUser().uid;

        $scope.postCollection(collection).then(function() {
          $scope.collections = null;
          $scope.getCollections();
          $scope.updateActionMenus();
        });
      }
    }

    //call the convert bin to collection function
    $scope.convertBin = $rootScope.convertBin = function(title) {

      var collection = {};

      if($scope.view == "products") {
        collection.type = 'collection';
      }
      else if($scope.view == "assets") {
        collection.type = 'asset_collection';
      }

      collection.title = title;
      collection.nid = $scope.binId;
      collection.user_bin = 0;

      $scope.setCollection(collection).then(function() {
        $scope.getCollections();
        $scope.updateActionMenus();
        $scope.bin = null;
        $scope.getBin();
      });
    }

    $scope.setCollection = function(collection) {
      var def = $q.defer();

      model.put('collections', {HTTP: {PUT: {url: 'collections/'+collection.nid}}, localize:false}, collection).then(function(data) {
        def.resolve(data);
      });

      return def.promise;
    }

    $scope.getBin = function() {

      if(!$scope.bin) {

        if(!$scope.binpromise) {

          $scope.binpromise = $q.defer();

          var type = $scope.view == "products" ? "collection" : "asset_collection";

          if (user.getCurrentUser()) {
            model.get('bin', {
              HTTP: {GET: {url: 'collections/' + user.getCurrentUser().uid + '?bin&type=' + type}},
              localize: false
            }).then(function (data) {

              for (first in data) break;

              $scope.bin = data[first];
              $scope.binId = first;

              $scope.binpromise.resolve(data);
            });
          }
        }
      }
      else {
        $scope.binpromise = $q.defer();
        $scope.binpromise.resolve($scope.bin);
      }

      return $scope.binpromise.promise;
    }

    //adds items that have been checked to the specified collection id
    $scope.addSelectedToCollection = function(collectionId) {

      var def = $q.defer();

      //update the collection object
      var collection = {};

      var collection_field = "collection_data";

      if($scope.view == "assets") {
       collection_field = "asset_collection_data";
      }

      if($scope.binId == collectionId) {
        collection = $scope.bin;
      }
      else {
        collection = $scope.collections[collectionId];
      }

      //push the selected items on to the collection
      for(var idx in $scope.records) {
        var idType = 'nid';

        if($scope.view == "assets") {
          idType = 'fid';
        }

        if($scope.records[idx].actioncheckbox) {

          if(!jQuery.isArray(collection[collection_field])) {
            collection[collection_field] = [];
          }

          collection[collection_field].push($scope.records[idx][idType]);
        }
      }

      //posts the collection back to the service
      $scope.setCollection(collection).then(function() {
        $scope.modal('collectionConfirmation');
        $scope.selectAll(true);
        def.resolve();
      });

      return def.promise;
    }

    $scope.removeSelectedFromCollection = function(collectionId) {

      var def = $q.defer();

       //update the collection object
      var collection = {};

      var collection_field = "collection_data";

      if($scope.view == "assets") {
       collection_field = "asset_collection_data";
      }

      if($scope.binId == collectionId) {
        collection = $scope.bin;
      }
      else {
        collection = $scope.collections[collectionId];
      }

      //push the selected items on to the collection
      for(var idx in $scope.records) {

        if($scope.records[idx].actioncheckbox) {

          var index = -1;
          var idType = 'nid';

          if($scope.view == "assets") {
            idType = 'fid';
          }

          index = collection[collection_field].indexOf($scope.records[idx][idType].toString());

          if (index > -1) {
            collection[collection_field].splice(index, 1);
          }
          else {

            //seems it gets added mixed, int or string check for the int version
            index = collection[collection_field].indexOf(parseInt($scope.records[idx][idType].toString()));

            if (index > -1) {
              collection[collection_field].splice(index, 1);
            }
          }

        }
      }

      //posts the collection back to the service
      $scope.setCollection(collection).then(function() {
        def.resolve();
      });

      return def.promise;
    }

    $scope.postCollection = function(collection, promise) {
      var def = $q.defer();

      model.post('collections', {HTTP: {POST: {url: 'collections'}}, localize:false}, collection).then(function(data) {
        def.resolve();
      });

      return def.promise;
    }

    $scope.removeSelectedCollection = $rootScope.removeSelectedCollection = function() {
      var def = $q.defer();

      if($rootScope.collectionSelected) {
        $http({method: 'DELETE', url: '/service/digitalcore/collections/'+$rootScope.collectionSelected}).success(function() {
          delete $scope.collections[$rootScope.collectionSelected];

          $scope.clearCollectionFilter();
          $rootScope.collectionSelected = false;

          def.resolve();
        });
      }

      return def.promise;
    }

    $scope.renameCollection = $rootScope.renameCollection = function(newName) {
      var def = $q.defer();

      $scope.collections[$rootScope.collectionSelected].title = newName;

      var updateData = $scope.collections[$rootScope.collectionSelected];

      //kill the collection data from the update request
      delete updateData['collection_data'];

      model.put('collections', {HTTP: {PUT: {url: 'collections/'+$rootScope.collectionSelected}}, localize:false}, updateData).then(function(data) {
        if(promise)
          promise.resolve(data);
      });

      return def.promise;
    }

    prom.resolve();

    return prom.promise;
  };

  module.register({name:'collections', fn: collections});
}]);
