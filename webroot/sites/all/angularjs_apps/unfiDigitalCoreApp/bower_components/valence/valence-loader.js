'use strict';

/*******************************************************************************************************
 * ANGULAR DATA - ANGULAR DATA MODULES - LOADER
 *******************************************************************************************************
 */
valenceApp.service('loader', ['valence', function(valence) {

  var Loader = function() {

    // Model queue used in determining when to shut down the loader
    this.queue = [];
    
    // Gernal flag to turn on/off the loader, enabled by default
    this.enabled = (valence.loader && valence.loader.enabled === false)? false : true;

    // Eventually holds reference to a time stamp.
    this.loaderStarted = null;

    // Classes for applying to the loader/content based on config or defaults.
    this.loaderClasses = {
      hide: (valence.loader.classes && valence.loader.classes.hide)? valence.loader.classes.hide : 'ngLoader-hidden',
      show: (valence.loader.classes && valence.loader.classes.show)? valence.loader.classes.show : 'ngLoader-visible'
    };

    // Holds references to DOM components that have loaders.
    this.loaderCollection = [];
    this.contentCollection = [];

    // Minimum time to display the loader
    this.minLoaderDisplayTime = valence.loader.minLoaderDisplayTime || 500;

    if(!this.enabled) {
      return this.prototype = {
        run: function(){},
        loaded:function(){},
        finish:function(){},
        wrapUp: function(){},
        halt:function(){}
      }
    }

    return this;
  };

  /**
   * RUN
   * @param  {Object} model When the loader is called with a model, that model gets added to a bank or queue.
   *                        The models get removed from the queue via the Model layer when loaded is called with the same model.
   * @return {[type]}       [description]
   */
  Loader.prototype.run = function(model, opts) {
    var content = valence.loader.content,
        loaderElem = valence.loader.loader;

    if(this.enabled) {
      if(model) {
        this.queue.push({name: model, opts:opts});
        if(model.loader) {
          if(opts.loader.content) {
            content = opts.loader.content;
          }
          if(opts.loader.loader) {
            loaderElem = opts.loader.loader;
          }
        }
      }

      if(!this.loaderStarted) {
        this.loaderStarted = new Date().getTime();
      }

      content = (document.querySelectorAll(content).length) ? document.querySelectorAll(content)
        : (function() {throw 'valence - ngLoader - It was requested that ['+content+'] be hidden when initiating the loader, however, no elements could be found in the DOM'})();

      loaderElem = (document.querySelectorAll(loaderElem).length) ? document.querySelectorAll(loaderElem)
        : (function() {throw 'valence - ngLoader - It was requested that ['+loaderElem+'] be hidden when initiating the loader, however, no elements could be found in the DOM'})();

      for(var i=0; i<content.length; i++) {
        content[i].classList.add(this.loaderClasses.hide);
        content[i].classList.remove(this.loaderClasses.show);
        this.contentCollection.push(content[i]);
      }

      for(var i=0; i<loaderElem.length; i++) {
        loaderElem[i].classList.add(this.loaderClasses.show);
        loaderElem[i].classList.remove(this.loaderClasses.hide);
        this.loaderCollection.push(loaderElem[i]);
      }
    }
  };

  /**
   * LOADED
   * @param  {Object} model Model passed in from the model layer. Gets compared with models in current queue
   * @return {[type]}       [description]
   */
  Loader.prototype.loaded = function(model) {
    var newQueue = [];
    // here we check the queue for a model match and if found we remove from the queue
    // and call finished
    if(model) {
      for(var i=0; i<this.queue.length; i++) {
        if(model !== this.queue[i].name) {
          newQueue.push(this.queue[i])
        }
      }

      // safe than splicing/deleting which can fuck up indexes in ie
      this.queue = newQueue;

      this.finish();
    } else {
      throw 'valence - ngLoader - Loader.loaded must be passed a model so it knows how "done" it is and when to stop the loader.'
    }
  };

  /**
   * FINISH
   * 
   * @description Analyzes the current queue, if empty, reverses loader className applications
   */
  Loader.prototype.finish = function() {
    var self = this,
        finishedTime;
    
    if(!this.queue.length) {
      finishedTime = new Date().getTime();
      if(finishedTime - this.loaderStarted >= this.minLoaderDisplayTime) {
        this.wrapUp();
      } else {
        setTimeout(function() {
          self.wrapUp();
        }, self.minLoaderDisplayTime - (finishedTime - self.loaderStarted));
      }

      this.loaderStarted = null;
    }
  };

  /**
   * WRAP UP
   * 
   * @description  Abstracted DOM manipulation to cater to a DRY'er use of .finish()
   */
  Loader.prototype.wrapUp = function() {
    if(!this.contentCollection.length) {
      // TODO: test this
      this.contentCollection = (document.querySelectorAll(valence.loader.content).length) ? document.querySelectorAll(valence.loader.content)
        : (function() {throw 'valence - ngLoader - It was requested that ['+valence.loader.content+'] be hidden when initiating the loader, however, no elements could be found in the DOM'})();
    }

    if(!this.loaderCollection.length) {
      this.loaderCollection = (document.querySelectorAll(valence.loader.loader).length) ? document.querySelectorAll(valence.loader.loader)
        : (function() {throw 'valence - ngLoader - It was requested that ['+valence.loader.loader+'] be hidden when initiating the loader, however, no elements could be found in the DOM'})(); 
    }

    for(var i=0; i<this.loaderCollection.length; i++) {
      this.loaderCollection[i].classList.remove(this.loaderClasses.show);
      this.loaderCollection[i].classList.add(this.loaderClasses.hide);
    }

    for(var i=0; i<this.contentCollection.length; i++) {
      this.contentCollection[i].classList.remove(this.loaderClasses.hide);
      this.contentCollection[i].classList.add(this.loaderClasses.show);
    }

    this.loaderCollection = [];
    this.contentCollection = [];
  };

  /**
   * HALT
   * @description Force stops the loader but manually emptying the queue and calling finish
   */
  Loader.prototype.halt = function() {
    // force empty the queue, and call finish
    this.queue = [];
    this.finish();
  };


  return new Loader();
}]);
