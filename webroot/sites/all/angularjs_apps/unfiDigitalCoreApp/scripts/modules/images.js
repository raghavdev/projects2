/***********************************************************************************************************************************************
 * IMAGE MODULE
 ***********************************************************************************************************************************************
 * @description Image processing module
 */
app.service('image', ['module', '$q', 'model', '$http', '$rootScope', 'user', function(module, $q, model, $http, $rootScope, user) {
  function image($scope) {

    var def = $q.defer();

    //
    // PRODUCT IMAGE PROCESSING
    //------------------------------------------------------------------------------------------//
    // @description
   // $scope.product_models = {};

    // Object to help with scaling for image templates
    // incase any other template types break away from the default
    var imageTypeTemplates = {
      additional: 'additional'
    };

    /**
     * LOAD IMAGE TYPE TEMPLATE
     *
     * @description Loads the correct view partial based on the image type.
     * @param  {[type]} type [description]
     * @return {[type]}      [description]
     */
    $scope.loadImageTypeTemplate = function(type) {
      return Drupal.settings.unfiDigitalCoreApp.modulePath + '/views/details/'+$scope.view+'/images/'+((imageTypeTemplates[type])? imageTypeTemplates[type] : 'default') +'.html';
    };

    /**
     * FORMAT IMAGE TITLE
     *
     * @description
     * @param  {[type]} title [description]
     * @return {[type]}       [description]
     */
    $scope.formatImageTitle = function(title) {

      if(title.match('_')) {
        title = title.split('_')
      } else {
        title = [title];
      }

      for(var i=0; i<title.length; i++) {
        title[i] = title[i].charAt(0).toUpperCase() + title[i].slice(1);
      }

      return title.join(' ');
    };

    /**
     * UPLOAD IMAGE
     *
     * @description  handles image uploads from UI
     * @param  {[type]} ein [description]
     * @return {[type]}     [description]
     */
    $scope.uploadAsset = function(args) {
      var def = $q.defer();

      if(args['use_modal']) {
        $scope.modal('processing');
        $scope.modalOpen = true;
      }

      $scope.errormessage = null;

      $rootScope.uploadStarted = true;

      //need to get the user first, so we know who uploaded
      //model.get('user', {localize:true}).then(function(user) {


        var body = {},
            action = 'post',
            reader = new FileReader(),
            fid = '';

        body.file_name = 'file.jpg';
        body.field_name = args.field_name;

        if(args.ident) {
          if($scope.meta.id === 'fid') {
            action = 'put'
            fid = '/'+args.ident;
          } else if($scope.meta.identifier === 'ein') {
            ein = args.ident;
            for(var i=0; i<$scope.records.length; i++) {
              if($scope.records[i].ein === args.ident) {

                //additional is always an upload
                if(args.type == "additional") {
                 action = 'post';
                }

                else if(!$scope.records[i][args.type] ) {
                  action = 'post';
                } else {
                  action = 'put';
                }
              }
            }
          }
        }

        // Using ng-model for file inputs has issues in IE8, the only real option here is to
        // manually query for the DOM element
        var element_id = args.element_id,
            assetElement = document.getElementById(element_id),
            assetData = assetElement.files[0];

        // short circuit if no files attached to assetElement
        if(!assetData)  {
          $rootScope.uploadStarted = false;
          $scope.errormessage = "Select and asset to upload";
          if($scope.modalOpen) {
            $scope.modalClose();
          }
          def.reject('No asset content found to upload');
        }

        // Callback for FileReader
        reader.onload = function(evt) {

          body.file_name = assetData.name;
          body.file_bytes = evt.target.result.split(',')[1];

          model[action]('assets', {HTTP: {PUT: {url: 'assets'+fid}}, POST: {url: 'assets'}, localize:false}, body).then(function(data) {

            $rootScope.uploadStarted = false;
            def.resolve(data);
          }, function(reason) {
            if(reason && reason.data[0]) {
              //set the error for display
              $scope.errormessage = reason.data[0];

              //kill the uploading flag
              $rootScope.uploadStarted = false;

              if($scope.modalOpen) {
                $scope.modalClose();
              }
            }

            def.reject(reason);
          }).finally(function() {
            // Clear values
            assetElement.value = '';
          });
        }

        reader.readAsDataURL(assetData);

      return def.promise;
      //});
    };

    //This method uses the service that was setup to fee up a file by its
    //fid and rendition, no fid gets the original file.
    //it is doing a cheap trick to make the browser click the link generated
    //seems kinda slow but it works
    $scope.downloadAssetFile = function(fid, rendition) {

      if(!fid) return;

      if(rendition) {
        rendition = '/'+rendition;
      }
      else {
        rendition = "";
      }

      var url = '/service/digitalcore/assets/'+fid+rendition;
      window.location = url;
    };

    /**
     * DOWNLOAD IMAGE
     *
     * @description  force downloads an image. in IE8 this opens in a new tab.
     * @param  {[type]} rendition [description]
     * @return {[type]}           [description]
     */
    $scope.downloadAsset = function(url) {

      if(!url) return;

      // Crea anchor tag
      var a = document.createElement('a');;
      a.setAttribute('href', url);
      a.setAttribute('download', '');
      a.setAttribute('style', 'display:none');

      // Append the anchor
      document.body.appendChild(a);

      // Click it
      a.click();

      // Remove it
      document.body.removeChild(a);

      // Reset model
      $scope.asset_models.rendition = "";
    };

    /**
     * REMOVE IMAGE
     *
     * @param  {[type]} ein [description]
     * @param  {[type]} fid [description]
     * @return {[type]}     [description]
     */
    $scope.removeImage = $rootScope.removeImage = function(nid, fid) {

      if(nid && fid) {
        $http({method: 'DELETE', url: '/service/digitalcore/assets/'+fid}).success(function(data) {
          model.get('products', {HTTP: {GET: {url:'products/'+nid}}, useRouteParams: false, localize: false, forceSerialize: true}).then(function(prod) {
            prod = prod.results[0];

            for(var i=0; i<$scope.records.length; i++) {
              if($scope.records[i].nid == prod.nid) {
                $scope.record = $scope.records[i] = prod;
              }
            }
          })
        });
      }
    };

    //Remove an asset specifically, its different than remove image wich is tied to a product
    $scope.removeAsset = $rootScope.removeAsset = function(asset) {
      var def = $q.defer();

      var removeList = [asset];
      var newRecords = [];

      //splice out the record that is being deleted
      for(var idx in $scope.records) {
        if($scope.records[idx].fid != asset.fid) {
          newRecords.push($scope.records[idx]);
        }
      }

      $scope.removeContent(removeList, def);

      $scope.clearRecord();

      //apply the edited list back
      $scope.records = newRecords;

      return def.promise;
    }

    def.resolve();

    return def.promise;
  }

  module.register({name:'image', fn: image});
}])
