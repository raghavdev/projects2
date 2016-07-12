var hasAppended;

app.filter('records', function($compile) {
  return function(record, path, opts, scope, elem, elemIndex) {

    var levels = null,
        obj = record,
        isCompound = false,
        html,
        data = [];

    /**
     * PARSE
     *
     * @param  {[type]} obj  [description]
     * @param  {[type]} path [description]
     * @return {[type]}      [description]
     */
    (function parse(obj, path){
      if(path) {
        // Multiple values passed, recurse.
        if(path.match(',')) {
          isCompound = true;
          path = path.split(',');
          for(var i=0; i<path.length; i++) {
            parse(obj, path[i]);
          }
          return;
        }

        // Single value, divide and conquer
        if(path.match('.') !== null) {
          levels = path.split('.');
        } else {
          levels = [path];
        }

        // Begin 'evaling' object path
        for(var i=0; i<levels.length; i++) {
          if(obj[levels[i]]) {
            obj = obj[levels[i]]
          } else {
            obj = '';
            break;
          }
        }
      } else {
        obj = '';
      }

      // If multiple, just keep pushing value into
      // our scope store
      if(isCompound) {
        data.push(obj);
      } else {
        data = obj;
      }

    })(obj, path);

    //
    // COMPOUND PARSING
    //------------------------------------------------------------------------------------------//
    // @description
    if(isCompound) {
      // if a concat is passed,
      // join compound values with concat.
      if(opts && opts.concat) {
        data = data.join(opts.concat)
      }
    }

    //
    // FORMATTING
    //------------------------------------------------------------------------------------------//
    //
    if(opts && opts.formatting) {
      switch(opts.formatting) {
        case "time": {
          if(jQuery.isNumeric(data)) {
            var myDate = new Date( data *1000);
            data = (myDate.getMonth() + 1) + "/" + myDate.getDate() + "/" + myDate.getFullYear();
          }
         break;
        }
      }
    }


    //
    // HTML PARSING
    //------------------------------------------------------------------------------------------//
    // @description
    if(opts && opts.html) {
      if(!scope) {
        throw 'Records Filter - When "html" is used we need to be able to compile the inject markup, please provide the scope (by passing "this" as an argument in the DOM)';
      }

      if(!elem) {
        throw 'Records Filter - When "html" is used we need to be able to compile the inject markup, please provide a string wehreby we can query for an element';
      }

      elem = document.querySelectorAll(elem);

      if(elemIndex > -1) {
        elem = elem[elemIndex];
      } else {
        elem = elem[0];
      }

      // Normalize to always be array
      if(opts.html.constructor === Object) {
        opts.html = [opts.html];
      }

      // Loop through element structures
      for(var i=0; i<opts.html.length; i++) {
        html = document.createElement(opts.html[i].tag);

        // Add attributes
        for(var attr in opts.html[i].attrs) {
          html.setAttribute(attr, opts.html[i].attrs[attr]);
        }

        // Add properties
        for(var prop in opts.html[i].properties) {
          html[prop] = opts.html[i].properties[prop];
        }

        // Only append if valid
        if(elem.children.length < opts.html.length) {
          elem.appendChild(html);
        }

        // Compile on a timeout to prevent
        setTimeout(function() {
          $compile(angular.element(elem).contents())(scope);
        },0);
      }

      return;
    }

    return data;
  }
});

