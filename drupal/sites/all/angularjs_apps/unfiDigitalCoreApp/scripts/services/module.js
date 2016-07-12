/***********************************************************************************************************************************************
 * MODULE SERVICE
 ***********************************************************************************************************************************************
 * @description Module Loader
 */
app.service('module', ['$q', function($q) {

  var modules = [];

  //
  // MODULE CLASS
  //------------------------------------------------------------------------------------------//
  // @description
  
  var Module = {};

  Module.load = function(mods, scope) {
    var def = $q.defer(),
        resolved = 0;

    if(mods.constructor !== Array) {
      mods = [mods];
    }

    modules.forEach(function(itm ,idx) {
      if(mods.indexOf(itm.name) !== -1) {
        itm.fn(scope).then(function(data) {
          resolved++;
          if(resolved === mods.length) {
            def.resolve();
          }
        });
      }
    });

    return def.promise;
  };

  Module.register = function(mod) {
    if(modules.indexOf(mod) === -1) {
      modules.push(mod);
    }
  };

  return Module;
}]);