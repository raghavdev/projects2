var default_image_path = '';

valence.model('products', {
	fields: _model,
	serializer: function(data, promise) {

		var serialized = [];

    var image_types = [
      "primary",
      "planogram_side",
      "planogram_top",
      "planogram_front",
      "nutritional_label",
      "print",
      "additional"
    ];

    var renditions = [
      "thumbnail",
      "medium",
      "large"
    ];

    default_image_path = Drupal.settings.unfiDigitalCoreApp.modulePath+ 'images/default_image.png';

    // pre-serialization, sigh
    if(data && !data.results) {
      if(data.constructor === Array && data.length) {
        var tmp = {};
        tmp.results = data;
        data = {};
        data = tmp;
      } else if(data.constructor === Object){
        var tmp = {};

        for(var prop in data) {
          tmp[prop] = data[prop];
        }

        data = {};
        data.results = tmp;
      }
    }
    if(data && data.results && data.results.length) {
      for(var i=0; i<data.results.length; i++) {

        if(data.results[i].brand && data.results[i].brand.constructor === Object) {
          data.results[i].brandtitle = data.results[i].brand.title;
        }

        if(data.results[i].keywords && data.results[i].keywords.constructor === Object) {
          var tmp = [];
          for(var keyword in data.results[i].keywords) {
            tmp.push(data.results[i].keywords[keyword]);
          }

          data.results[i].keywords = tmp.join(', ');
        }

        if(data.results[i].title && data.results[i].title.constructor === Array) {
          data.results[i].title = ((data.results[i].title.join(" ")).toUpperCase());
        }

        if(data.results[i].ein && data.results[i].ein.constructor === Array) {
          data.results[i].ein = data.results[i].ein[0];
        }

        if(data.results[i].upc && data.results[i].upc.constructor === Array) {
          data.results[i].upc = data.results[i].upc[0];
        }

        // Add default images if not present
        for(var j=0; j<image_types.length; j++) {
          if (data.results[i].image_urls
              && data.results[i].image_urls[image_types[j]]
              && data.results[i].image_urls[image_types[j]].constructor === Array) {
            if (!data.results[i].image_urls[image_types[j]].length) {
              // Create default data type
              data.results[i].image_urls[image_types[j]] = {};
              data.results[i].image_urls[image_types[j]].renditions = {};

              // Assign default path for each rendition
              for(var k=0; k<renditions.length; k++) {
                data.results[i].image_urls[image_types[j]].renditions[renditions[k]] =  default_image_path;
              }
            } else {
              // not sure what to do here yet
            }
          } else {
            if (data.results[i].image_urls
                && data.results[i].image_urls[image_types[j]]
                && data.results[i].image_urls[image_types[j]].renditions.thumbnail) {
              loadDefaultImage(data.results[i].image_urls[image_types[j]]);
            }
          }
        }

        //track a generic id
        data.results[i].id = data.results[i].nid;
      }
    }

    promise.resolve(data);

    return promise.promise;
  }
});

/**
 * LOAD DEFAULT IMAGE
 *
 * @param  {[type]} product [description]
 * @return {[type]}         [description]
 */
function loadDefaultImage(product_image) {
	image = new Image();
  // This is a shim that will still cause default_image to show if it can't find/errors on the image.
  image.onerror = function() {
    product_image.renditions.thumbnail =  default_image_path;
  }

  image.src = product_image.renditions.thumbnail;
}
