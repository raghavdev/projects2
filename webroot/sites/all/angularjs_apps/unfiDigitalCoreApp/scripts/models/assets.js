valence.model('assets', {
  field: _model,
  serializer: function(data, promise) {
    var obj = {};
    obj.results = null;

    if(!data.results) {
      obj.results = data;
    } else {
      obj = data;
    }

    for(var i=0; i<obj.results.length; i++) {
      if(obj.results[i].keywords && obj.results[i].keywords.constructor === Object) {
        var tmp = [];
        for(var keyword in obj.results[i].keywords) {
          tmp.push(obj.results[i].keywords[keyword]);
        }

        obj.results[i].keywords = tmp.join(', ');
      }

      //lets product and asset both track a generic drupal id
      obj.results[i].id = obj.results[i].fid;
    }
    promise.resolve(obj);

    return promise.promise;
  }
})
