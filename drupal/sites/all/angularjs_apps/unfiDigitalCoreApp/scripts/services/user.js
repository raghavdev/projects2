/***********************************************************************************************************************************************
 * USER SERVICE
 ***********************************************************************************************************************************************
 * @description processes data behind shallow API.
 */
app.service('user', ['model', '$q', '$http', function(model, $q, $http) {

    var userId = null;
    var prefs = {};
    var current_user = {};
    var user_permissions = {};

    var p = $q.defer();
    var self = this;

    // Get CSRF TOKEN
    $http({method: 'GET', url: '/services/session/token'}).success(function(data) {
        $http.defaults.headers.put["X-CSRF-Token"] = data;
        $http.defaults.headers.post["X-CSRF-Token"] = data;
        $http.defaults.headers.delete = {"X-CSRF-Token": data};
        $http.defaults.headers.get = {"X-CSRF-Token": data};
        //self = this;

        $http({method: 'GET', url: "/service/digitalcore/user"}).success(function (user) {
            if (user && user.current_user && user.current_user.uid) {
                current_user = user.current_user;
                prefs = user.current_user.data.digital_core_user_prefs;
                userId = user.current_user.uid;
                user_permissions = user.current_user_permissions;
            }

            p.resolve();
        });
    });

    return {
        promise: p.promise,
        getCurrentUser: function() {
            return current_user;
        },
        getPrefs: function() {
            return prefs;
        },
        getUserPerms: function() {
            return user_permissions;
        },
        hasPerm: function(perm) {
            var data = Object.keys(user_permissions).map(function(k) { return user_permissions[k] });
            return (data.indexOf(perm) !== -1);
        },
        getPref: function(key) {
            var def = $q.defer();
            if(!prefs) {
                //defaults
                prefs = {
                    flexers: [
                        {
                            dimensions: {
                                paneBottom: "815px",
                                paneLeft: null,
                                paneRight: null,
                                paneTop: "516px"
                            },
                            id: "005"
                        },
                        {
                            dimensions: {
                                paneBottom: null,
                                paneLeft: "300px",
                                paneRight: "980px",
                                paneTop: null
                            },
                            id: "004"
                        },
                    ],
                    viewMode: "thumb",
                    predicate: "product_name"
                }
            }

            if (key) {
                if(prefs[key]) {
                    def.resolve(prefs[key]);
                } else {
                    def.reject();
                }
            } else {
                def.resolve(prefs);
            }

            return def.promise;
        },
        savePref: function(key, data) {
            var def = $q.defer(),
                self = this;

            if(key && data) {
                prefs[key] = data;
            }

            model.put('user_prefs', {HTTP: {PUT: {url: 'user_prefs/'+userId}}, localize:true}, prefs).then(function(data) {
                def.resolve(data);
            });

            return def.promise;
        }
    };
}]);
