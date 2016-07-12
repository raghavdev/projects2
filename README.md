# Contents of this File

* [Purpose](#purpose)
* [Overview of Directory Structure](#overview-of-directory-structure)
* [Local Project Setup](#local-project-setup)

# Purpose

Blue Marble Brands Digital Manager is an internal tool for Blue Marble Brands
staff to manage product information.

# Overview of Directory Structure

* db
  This directory is not stored in version control, but it is created when you do
  a cap db:pull. It stores database backups. Feel free to use this to store your
  own local db backups here.
* docs
  This directory is for patches. Whenever you need to patch core or a contrib
  module, you should save the patch file to this directory. Please be sure the
  patch is [named properly](http://drupal.org/patch/submit#patch_naming), and
  prefixed with the module name.

  Whenever doing core or module updates, you must check this directory to see if
  there are any patches that will need to be re-applied. If you see a patch that
  might need to be re-applied, when it is named properly you can take the issue
  number and go to drupal.org/node/[issue-number] to see the status, perhaps the
  patch has already been committed and won't need to be re-applied. Just check
  that the release/update includes that commit, and if so that patch can be
  removed from the repo. If it is unresolved and there are new patches, those
  will need to be tested.
* drupal
  This is where drupal's files go.
* scripts
  This directory contains php scripts, many of which are called using drush:
  `drush php-script`.
* tests
  This is where behat tests for the project are written.

# Local Project Setup

After you clone the repo, you created your database, added your database
configuration to drupal/sites/default/local_settings.php, and pulled the
database, there are a few other things you should do when working on this
project in particular.

* Ensure you have [https setup on your local environment](https://wiki.metaltoad.com/index.php/Metaltoad:Developer_Handbook#Virtual_host_setup)
* Setup [Solr 4 using the instructions for Search API Solr](https://www.drupal.org/node/1999310#installing-solr)
* Add the following to your local_settings.php file:

  ```
  $conf['solr_search_api_path'] = '\\/solr'; // Update to point to your solr instance.

  $conf['cdn_status'] = 0;
  $conf['preprocess_css'] = 0;
  $conf['preprocess_js'] = 0;
  $conf['cache_default_class'] = 'DrupalDatabaseCache';
  $conf['file_temporary_path'] = '/tmp';
  $conf['file_private_path'] = 'sites/default/private_files';
  ```
* This project uses [SASS and Compass](https://wiki.metaltoad.com/index.php/Metaltoad:Developer_Handbook#Install_Additional_Software)
  You will find the SCSS files in drupal/sites/all/themes/unfi_admin/sass/
* Local only (optional): Enable Macola Connect Mock Server `drush en macola_connect_mock -y`
* Local only (optional): Set macola_connect_mock_enabled to true: `drush vset macola_connect_mock_enabled 1`
  Alternatively set `macola_connect_api_url` to 'http://yourdomain.dev/macola'
  in your local_settings. This will make it so you can run imports from drush as well.

# Key Features

* TOM: The Object Manager (tom)
  This module is hosted on ToadHub (toadhub.metaltoad.com). Changes to that module
  should be done in that repo and released as a new version. To download the latest
  version:
  
  `drush dl tom --source="https://toadhub.metaltoad.com/project-updates" --destination="sites/all/modules/shared"`
* Macola Connect (macola_connect)
  Two-way integration with the Macola ERP system via an API. The API is currently
  documented http://docs.testapi1092.apiary.io/.

  The API is only accessible when connected to the UNFI VPN. Currently there is
  only a dev instance of the API at http://10.1.124.96/bmbmacola/api

  Set `macola_connect_api_url` to the correct URL per environment.

  Macola Connect settings can be configured from: /admin/config/bluemarble/macola
* Access Import (bluemarble_access_import)
  Imports CSV data from exports of their Access database.

  CSV Files can be imported from: /admin/config/bluemarble/access_import
