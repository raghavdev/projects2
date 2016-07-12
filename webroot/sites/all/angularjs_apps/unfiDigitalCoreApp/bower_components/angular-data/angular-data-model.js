'use strict';

/***********************************************************************************************************************************************
 * ANGULAR DATA - MODEL
 ***********************************************************************************************************************************************
 * @description On page-load/navigation:
 *
 * 1. analyze the current route, see if route has model property.
 * 2. 
 */
ngDataApp.service('model', ['ngData', 'cloud', 'store', 'loader', '$route', '$rootScope', '$location', '$rootElement', '$q', '$routeParams',
  function(ngData, cloud, store, loader, $route, $rootScope, $location, $rootElement, $q, $routeParams) {

  //
  // UTILITY FUNCTIONS
  //------------------------------------------------------------------------------------------//
  
  /**
   * SAFE APPLY
   * @param  {[type]}   scope [description]
   * @param  {Function} fn    [description]
   * @description queues up a $scope.apply
   */
  function safeApply(scope, fn) {
    var self = this;
    var applier = setInterval(function() {
      var phase = scope.$$phase;
      
      if(phase != '$apply' && phase != '$digest') {
        clearInterval(applier);
        scope.$apply(fn);
      }
      console.log('apply timer');
    }, 100);
  };

  /**
   * SPLIT AND STRIP
   * @param  {[type]} obj [description]
   * @return {[type]}     [description]
   */
  function splitAndStrip(obj) {
    var stripped = [];

    obj = obj.split('/');

    for(var i=0; i<obj.length; i++) {
      if(obj[i] !== "") {
        stripped.push(obj[i]);
      }
    }

    return stripped;
  };

  /**
   * GET ROUTE PARAMS
   * @return {[type]} [description]
   */
  function getRouteParams() {
    var def = $q.defer(),
        elapsed = 0;

    var paramChecker = setInterval(function() {
      if(Object.keys($routeParams).length) {
        clearInterval(paramChecker);
        def.resolve($routeParams);
      } else {
        elapsed += 300;
        if(elapsed >= 1000) {
          clearInterval(paramChecker)
          def.resolve(null)
        }
      }
    }, 300);

    return def.promise;
  };
  
  /*********************************************************************************************************************************************
   * MODEL CONSTRUCTOR
   *********************************************************************************************************************************************
   * @description Serves as the service entry point for working with models. At this point it
   *              does nothing more than give us a prototype chain and perform some basic,
   *              global-to-models error handling.
   */
  
  var Model = function() {
    // do stuff like check if ngModels has anything in it.
    if(!ngData.models.length) {
      throw 'ngData - no models in ngData.models were found. Add a model by using: ngData.model("myModelName", {})';
    }
  };

  //
  // MODEL PROTOTYPE
  //------------------------------------------------------------------------------------------//
  // @contains methods attached to the prototype chain of the Model class.
  Model.fn = Model.prototype = {
    /**
     * ----------
     * GET MODULE
     * ----------
     * @type {Object}
     */
    get: {
      /**
       * INIT
       * @param  {[type]} model [description]
       * @param  {[type]} opts  [description]
       * @return {[type]}       [description]
       */
      init: function(model, opts) {

        // This block is basically for convenience.
        // If a user passes in a a model without passing in its conifg,
        // we try and find it.
        model = model || (function() {throw 'ngData - you must pass in the name of a model to Model.get()'})();

        // Hook for calling this manually as in loadViewModel sends the config object with it.
        if(!opts) {
          // Load the model's config
          for(var i=0; i<ngData.models.length; i++) {
            if(ngData.models[i].name === model) {
              opts = ngData.models[i];
            }
          }

          if(!opts) {
            // We still couldn't find thin config, so basically the user is implementing this wrong.
            // No point in moving on.
            throw 'ngData - no model declaration found for ['+model+']. Please declare one via ngData.model('+model+', {})';
          }
        }

        // Add the model to the reuest queue
        if(ngData.appliedModels.indexOf(model) === -1) {
          ngData.retrievalQueue.push({name: model, opts: opts});
        }
        
        // Start processing the queue
        this.runner();

        // Return chainable object;
        return Model.fn;
      },
      /**
       * RUNNER
       * @return {[type]} [description]
       */
      runner: function() {
        var self = this;

        // Queue processing
        if(!ngData.retrievalProcessing && ngData.retrievalQueue.length > 0) {
          var mdl = ngData.retrievalQueue[0]; // Cache current queue object

          // Add model to loading queue
          loader.run(mdl);

          // Set flag to prevent next queue step form running before this one.
          ngData.retrievalProcessing = true;
          // Add current queue object to appiled stack
          ngData.appliedModels.push(mdl.name);

          // Check for blongsTo first
          if(mdl.opts.belongsTo && mdl.opts.belongsTo !== null && mdl.opts.belongsTo !== undefined) {
            this.belongsTo(mdl)    
          } else {
            // 1:1 fetch the model;
            fetcher(mdl.name).then(function(data) {
              // Apply the model dala
              apply(mdl, data);
              // Queue upkeep
              ngData.retrievalQueue.shift() // throw first index off the stack FIFO
              ngData.retrievalProcessing = false; // tell the queue we're done
              // Recurse, if there are no items left in the queue, it will be caught by the loader.
              self.runner();
            });
          }
        }
      },
      /**
       * BELONGS TO
       * @param  {[type]} mdl [description]
       * @return {[type]}     [description]
       */
      belongsTo: function(mdl) {
        var self = this;

        if(mdl.opts.hasOwnProperty('by') && mdl.opts.by !== null && mdl.opts.by !== undefined) {
          // We start out by calling the fetcher, wich is responsible for returning data from the appropriate source.
          fetcher(mdl.opts.belongsTo).then(function(data) {
            var record = [], // serializer cache
                recordMatch = 0, // matched records from query
                query = [], // data query
                result = {data:[]}; // query result

            // Serialize - this is going to be stupid error prone.
            // serialization will need its own user configurable layer.
            if(data.data.constructor !== Array) {
              record.push(data.data)
            } else {
              record = data.data;
            }

            // get the right data - only tests objects right now.
            if(mdl.opts.by.constructor === Object) {
              for(var key in mdl.opts.by) {
                if($routeParams.hasOwnProperty(key)) {
                  var obj = {}
                  obj[mdl.opts.by[key]] = $routeParams[key];
                  query.push(obj);
                }
              }
              
              // for all of the records returned, we find by query.
              for(var i=0; i<record.length; i++) {
                var queryMatch = 0;
                if(record[i].constructor === Object) {
                  for(var j=0; j<query.length; j++) {
                    for(var prop in query[j]) {
                      if(record[i].hasOwnProperty(prop) && record[i][prop] === query[j][prop]) {
                        queryMatch++;
                      }
                    }
                  }

                  // all queries queryMatch
                  if(queryMatch == query.length) {
                    if(mdl.opts.type === Object) {
                      if(record[i].constructor) {
                        result.data = record[i]
                      } else {
                        throw 'ngData - ['+mdl.name+'] was specified as type Object but the matched query returned a ['+record[i].constructor+']'
                      }
                    }
                    
                    // Array
                    if(mdl.opts.type === Collection) {
                      result.data.push(record[i]);
                    }

                    // Increment the closure's record match counter
                    // so we can throw an error if nothing matched
                    recordMatch++;
                  }
                }
              } 

              // No records were found to have the provided query
              if(!recordMatch) {
                // throw 'ngData - no records in: ['+mdl.opts.belongsTo+'] matched the query: ['+query+']';
              }

              // If we have a result set, send to the apply layer.
              if(result.data !== undefined || result.data.length > 0) {
                apply(mdl, result);
              } else {
                console.warn('ngData - no ['+ mdl.name+'] with ['+query+'] found in ['+mdl.belongsTo+']');
              }

              // Queue upkeep
              ngData.retrievalQueue.shift() // throw first index off the stack FIFO
              ngData.retrievalProcessing = false; // tell the queue we're done
              // Recurse, if there are no items left in the queue, it will be caught by the loader.
              self.runner();
            } else {
              throw 'ngData - ensure that the "by" property has a value that is an Object with the keys being the $routeParams and the values being the data keys, e.g: [by: {post_id : "id"}]';
            }
          });
        } else {
          throw 'ngData - "belongsTo" requires a "by" property to be present. This allows us to find the appropriate child model. Model: ['+mdl.name+']';
        }
      }
    },
    /**
     * ----------
     * SET MODULE
     * ----------
     * @type {Object}
     */
    set: {
      init: function(action, model, data) {
        var self = this;

        if(!model) {
          throw "ngData - A persistence method was called without a model name. Please provide one: model.set('myModelName', dataObject)";
        }

        if(!action) {
          throw "ngData - A persistence method was called without providing and HTTP action. Please use model.save or model.update which have these included."
        }

        if(!data) {
          console.warn("ngData - A persistence method was called without providing any data. We're letting this slide incase there is infact an endpoint for POST that you just need to hit.");
        };

        // Basic, method agnostic options
        var opts = {
          url: model,
          data: data,
          method: action
        };
        
        var config;

        // Get config. 
        for(var i=0; i<ngData.models.length; i++) {
          if(ngData.models[i].name === model) {
            config = ngData.models[i]
          }
        };

        if(!config) {
          throw "ngData - no model declaration found for ["+model+"] please dec one using ngData.model("+model+", {})";
        }

        if(config.endpoints && config.endpoints[action.toUpperCase()]) {
          opts.url = config.endpoints[action.toUpperCase()];
        }

        if(config.hasMany) {
          this.hasMany(config, opts);
        }

        // Add the model to the reuest queue
        ngData.persistenceQueue.push({name: model, action: action, opts: opts, config: config});

        this.runner();

        // Return chainable object.
        return Model.fn;
      },
      /**
       * RUNNER
       * @description This is what runs the queue down.
       */
      runner: function() {
        var self = this;

        if(!ngData.persistanceProcessing && ngData.persistenceQueue.length) {
          ngData.persistanceProcessing = true;

          var mdl = ngData.persistenceQueue[0];
          
          this.persist(mdl).then(function(data) {
            console.log(data);
            if(data.model.config.persistence && data.model.config.persistence.success) {
              data.model.config.persistence.success($location, data);
            }
          }, function(data) {
            if(data.model.config.persistence && data.model.config.persistence.fail) {
              data.model.config.persistence.fail($location, data);
            }
          })["finally"](function(data) {
            ngData.persistenceQueue.shift();
            ngData.persistanceProcessing = false;
            self.runner();
          });
        }
      },
      persist: function(model) {
        var self = this,
            def = $q.defer();

        cloud.saveModel(model.opts).then(function(data) {
          // so here it's either the server returns the whole model, and we just save it to the store
          // or we get returned the action item of the request and add it to the store record.
          self.updateStore(model.name).then(function(data) {
            data.model = model;
            def.resolve(data);
          }, function(data) {
            data.model = model;
            def.reject(data);
          });
        }, function(data) {
          data.model = model;
          def.reject(data);
        });
        
        return def.promise;
      },
      /**
       * UPDATE STORE
       * @param  {[type]} model [description]
       * @return {[type]}       [description]
       * @description Because we can't guarantee what kind of data set will be returned from the server
       *              We call get on the model we just saved to and re-save that to the store.
       *              
       */
      updateStore: function(model) {
        var def = $q.defer();

        // Call cloud
        cloud.fetchModel(model).then(function(data) {
          // Save to app store
          store.saveModel(model, data).then(function(data) {
            // Resolve
            def.resolve(data);
          }, function(data) {
            // Reject
            def.reject(data)
          })
        }, function(data) {
          // Reject
          def.reject(data);
        });

        // Return Promise object.
        return def.promise;
      },
      /**
       * HAS MANY
       * @param  {[type]}  config [description]
       * @param  {[type]}  opts   [description]
       * @return {Boolean}        [description]
       */
      hasMany: function(config, opts) {
        var childConfig;

        for(var i=0; i<ngData.models.length; i++) {
          if(config.hasMany === ngData.models[i].name) {
            childConfig = ngData.models[i];
          }
        }

        if(childConfig.by) {
          for(var prop in childConfig.by) {
            if($routeParams[prop]) {
              opts.data[childConfig.by[prop]] = $routeParams[prop];
            }
          }
        } else {
          throw "ngData - error saving data, it looks like you're trying to update a model wich belongs to a parent model.  \n The parent must have a 'hasMany' property and the child must have a 'belongsTo' and 'by' property so we know what criteria to send to your server."
        }
      }
    },
    remove: {
      init: function(model) {
        
      }
    }
  };

  //
  // MODEL API
  //------------------------------------------------------------------------------------------//

  Model.get = function(model, opts) {
    return Model.fn.get.init(model, opts);
  };

  Model.put = function(model, data) {
    return Model.fn.set.init('PUT', model, data)
  };

  Model.post = function(model, data) {
    return Model.fn.set.init('POST', model, data);
  };

  Model.remove = function(model, data) {
    return Model.fn.remove.init(model);
  };

  // Root Scope API access
  $rootScope.save = Model.post;
  $rootScope.update = Model.put;
  $rootScope.remove = Model.remove;
  
  //
  // CORE FUNCTIONS
  //------------------------------------------------------------------------------------------//
  //
  
  /**
   * FETCHER
   * 
   * @param  {String} model Model name
   * @return {Object} Promise object.
   * @description Contacts the store and Cloud layers and returns the appropriate data
   */
  function fetcher(model) {
    var def = $q.defer();

    // That means that at this point, we simple need to contact the store to see if the model exists.
    store.getModel(model).then(function(data) {
      def.resolve(data);
      // console.log(apply(model, data));
    }, function(data) {
      cloud.fetchModel(model).then(function(data) {
        // save to store
        store.saveModel(model, data).then(function(data) {
          def.resolve(data)
        });

      }, function(data, status, headers, config) {
        // error out, data cannot be retrieved
        throw 'ngData: Could not retrieve ['+ model + '] from ['+ ngData.api+'].';
        // perhaps code some retries in here.
      })
    });

    return def.promise;
  };


  /**
   * APPLY
   * @param  {[type]} model [description]
   * @param  {[type]} data  [description]
   * @description [description]
   */
  function apply(model, data) {
    var scopes = document.querySelectorAll('.ng-scope'),
        scope, // scope iteration reference
        thisModel, // context model
        hasAllProperties = false, // bool for scope detection
        matchCount, // how many to match,
        matchedCount; // mow many have matched

        // Normalize data
        data = data.data;

    // Loop through all the scopes on the DOM.
    for(var i=0; i<scopes.length; i++) {
      // Ignore scopes with ng-repeat attribute
      // this may prove problematic for certain use-cases, but as for now
      // it creates potention for HUGE amounts of wasted cycles.
      if(!scopes[i].hasAttribute('ng-repeat')) {
        scope = angular.element(scopes[i]).scope();
        // here we need to do all of the model analysis
        // determine relationships,
        // and assign scope properties.
        if(scope) {
          if(model.opts.fields) {
            matchCount = 0;
            matchedCount = 0;
            for(var field in model.opts.fields) {
              console.log(field);
              matchCount++;
              if(scope.hasOwnProperty(field)) {
                matchedCount++;
                if(model.opts.fields[field] === _model) {
                  // Just assign the entire model back to scope and let the dev decide how to use it.
                  scope[field] = data;
                } else {
                  if(data.constructor === Object) {
                    if(data.hasOwnProperty(field)) {
                      scope[field] = data[field];
                    } else {
                      console.warn('ngData - model property ['+ field +'] does not exist. Cannot assign to scope');
                    }
                  } else if(data.constructor === Array) {
                    // not sure what to do here
                  }
                }
              }
            }
            
            // All model fields matched to fields on the scope,
            // proceed with applying.
            if(matchedCount === matchCount) {
              safeApply(scope);
              scope.model = model;
              loader.loaded(model);
            } else {
              console.warn('ngData - a model $apply was attempted but none of the provided fields were found in scope [$id: '+scope.$id+'], meaning we do not really know what scope to apply the model to.');
            }
          } else {
            console.warn('ngData - Make sure your Model declaration has a [fields] property with the field names as keys for items in scope that are to receive model data.');
          }
        }
      }
    }
  };

  //
  // ROUTE HOOKS
  //------------------------------------------------------------------------------------------//

  function loadViewModel(scope) {
    var urlSegs = splitAndStrip($location.path()),
        routeMached = false,
        routeSegs;

    ngData.appliedModels = [];

    // Kick off the loader right away
    loader.run();

    getRouteParams().then(function(data) {
      for(var route in $route.routes) {
        var paramCounter = 0,
            paramMatchedCounter = 0,
            paramsPassed = false,
            uriCounter = 0,
            uriMatchedCounter = 0,
            urisPassed = false;

        // Param-less route.
        if(route === $location.path()) {
          if($route.routes[route].model) {
            for(var i=0; i<ngData.models.length; i++) {
              if(ngData.models[i].name === $route.routes[route].model) {
                Model.get(ngData.models[i].name, ngData.models[i]);
                return;
              }
            }
          } else {
            loader.finish();
            // route matches location but no model found.
            console.log('route matches location but no model found.', $route.routes[route]); 
            return;
          }
        }

        routeSegs = splitAndStrip(route);
        
        if(routeSegs.length === urlSegs.length) {
          if(data) {
            for(var i=0; i<routeSegs.length; i++) {
              if(routeSegs[i].match(':') !== null) {
                for(var param in data) {
                  paramCounter++;
                  if(routeSegs[i].match(param) !== null) {
                    paramMatchedCounter++;
                  }
                }
              } else {
                uriCounter++;
                if(routeSegs[i] === urlSegs[i]) {
                  uriMatchedCounter++;
                }
              }
            }

            if(paramCounter && paramMatchedCounter && paramCounter === paramMatchedCounter) {
              paramsPassed = true;
            }

            if(uriCounter && uriMatchedCounter && uriCounter === uriMatchedCounter) {
              urisPassed = true;
            }

            if(paramsPassed && urisPassed && !routeMached) {
              // Angular creates two routes for each app.js entry, one with a trailing /
              // this ensure it will only be run once.
              routeMached = true;
              if($route.routes[route].model) {
                for(var i=0; i<ngData.models.length; i++) {
                  if(ngData.models[i].name === $route.routes[route].model) {
                    Model.get(ngData.models[i].name, ngData.models[i]);
                  }
                }
              }
            }
          }
        }
      }

      loader.finish();
    });
  };

  //
  // INIT OPTS
  //------------------------------------------------------------------------------------------//

  $rootScope.$on('$locationChangeSuccess', function(data) {
    loadViewModel();
  });

  loadViewModel();

  return new Model();
}]);
