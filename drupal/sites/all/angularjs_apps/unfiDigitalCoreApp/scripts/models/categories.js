valence.model('categories', {
	fields: _model,
  serializer: function(data, promise) {
    var serialized = [],
        tmp = {};


    // Taking a farily procedural approach to this in teh interest of time.

    // Convert everything to object, don't let Peter see this.
    for(var i=0; i<data.length; i++) {
      if(data[i].internal_only == 1) {
        data[i].internal_only = true;
      }
      else {
        data[i].internal_only = false;
      }
      tmp[data[i].tid] = data[i];
    }

    // Now perform basic sorting
    for(var tid in tmp) {
      if(tmp[tid].parents) {
        for(var i=0; i<tmp[tid].parents.length; i++) {
          if(tmp[tid].parents[i] !== "0" && tmp.hasOwnProperty(tmp[tid].parents[i])) {
            if(!tmp[tmp[tid].parents[i]].children) {
              tmp[tmp[tid].parents[i]].children = [];
            }

            tmp[tmp[tid].parents[i]].children.push(tmp[tid]);
          }
        }
      }
    }

    // Now push all TLO's to the serialized return value
    for(var tid in tmp) {
      if(tmp[tid].parents) {
        parentLoop:
        for(var i=0; i<tmp[tid].parents.length; i++) {
          if(tmp[tid].parents[i] === "0") {
            serialized.push(tmp[tid]);
            break parentLoop;
          }
        }
      }
    }

    tmp = null;

    promise.resolve(serialized);

    return promise.promise;
  }
});