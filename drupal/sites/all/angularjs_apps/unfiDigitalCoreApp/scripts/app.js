 'use strict';

var app = angular.module('unfiDigitalCoreApp', [
  'ngCookies',
  'ngResource',
  'ngSanitize',
  'ngRoute',
  'ui.date',
  'ngMessages',
  'valence',
  'ngMaterial',
  'checklist-model',
  'treeControl'
]);

app.config(function ($routeProvider, valenceProvider, valenceAuthProvider, $rootScopeProvider, $compileProvider) {
  // NG DATA CONFIG

  valenceProvider.api = '/service/digitalcore';

  valenceProvider.storageEngine = {primary: 'memory', fetchOnReload: true};

  valenceProvider.loader.enabled = false;
  valenceAuthProvider.enabled = false;

  $routeProvider
    .when('/', {
      templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath + 'views/main.html',
      controller: 'MainCtrl',
      resolve: { //resolves the current user data before bootstrap
        'user':function(user) {
          return user.promise;
        }
      }
    })
    .when('/products', {
      templateUrl: Drupal.settings.unfiDigitalCoreApp.modulePath +'views/main.html',
      controller: 'MainCtrl',
      resolve: { //resolves the current user data before bootstrap
        'user':function(user) {
          return user.promise;
        }
      }
    })
    .otherwise({
      redirectTo: '/'
    }
  );

  // Disable debug info per http://blog.thoughtram.io/angularjs/2014/12/22/exploring-angular-1.3-disabling-debug-info.html
  // To enable for local dev just comment this line out
  $compileProvider.debugInfoEnabled(false);
});

app.run(function(
  module,
  content,
  collections,
  categories,
  brands,
  products,
  params,
  search,
  sorting,
  lazyload,
  filters,
  image
) {
});
