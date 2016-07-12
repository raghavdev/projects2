valence.model('bin', {
	fields: _model,
  serializer: function(data, promise) {
    var serialized = [],
        tmp = {};

    for(var i=0; i<data.results.length; i++) {
      tmp[data.results[i].nid] = data.results[i];
    }

    promise.resolve(tmp);

    return promise.promise;
  }
});