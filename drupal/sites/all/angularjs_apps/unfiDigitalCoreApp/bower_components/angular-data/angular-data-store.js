'use strict';

/*******************************************************************************************************
 * ANGULAR DATA - ANGULAR DATA MODULES - STORE
 *******************************************************************************************************
 */
ngDataApp.service('store', ['$q', function($q) {

  var store = [];

  function getModel(model) {
    var def = $q.defer(),
        res = false;


    for(var i=0; i<store.length; i++) {
      if(store[i].name === model) {
        res = store[i];
      }
    }

    if(res) {
      def.resolve(res);
    } else {
      def.reject(res);
    }

    return def.promise;
  };

  function saveModel(model, data) {
    var hasModel = false;

    data = data.data; // this assumes a normalized format

    for(var i=0; i<store.length; i++) {
      if(store[i].name === model) {
        store[i].data = data;
        hasModel = true;    
      }
    }

    if(!hasModel) {
      store.push({name: model, data: data});
    }

    return getModel(model);
  };

  
  return {
    // hasModel: hasModel,
    getModel: getModel,
    saveModel: saveModel
  }
}]);