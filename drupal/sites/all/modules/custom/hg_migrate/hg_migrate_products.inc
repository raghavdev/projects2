<?php

/**
 * @file
 * A basic example of using the Migrate module to import taxonomy, users, nodes,
 * and comments.
 *
 * The basic idea is
 * - The users in the source application are listed in the
 *   migrate_example_beer_account table and are transformed into Drupal users.
 * - Drupal "beer" nodes describe beers; The information to create the nodes
 *   comes from the migrate_example_beer_node table.
 * - Taxonomy terms for the beer nodes (ale, pilsner) come from the
 *   migrate_example_beer_topic table and they are applied to nodes using the
 *   source information in the migrate_example_beer_topic_node table.
 * - Comments to be attached to the beer nodes are described in the source
 *   migrate_example_beer_comment table.
 *
 * We will use the Migrate API to import and transform this data and turn it into
 * a working Drupal system.
 */

/**
 * To define a migration process from a set of source data to a particular
 * kind of Drupal object (for example, a specific node type), you define
 * a class derived from Migration. You must define a constructor to initialize
 * your migration object. By default, your class name will be the "machine name"
 * of the migration, by which you refer to it. Note that the machine name is
 * case-sensitive.
 *
 * In any serious migration project, you will find there are some options
 * which are common to the individual migrations you're implementing. You can
 * define an abstract intermediate class derived from Migration, then derive your
 * individual migrations from that, to share settings, utility functions, etc.
 */
abstract class HGMigration extends DynamicMigration {
  public function __construct() {
    // Always call the parent constructor first for basic setup
    parent::__construct();

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    // $this->team = array(
    //   new MigrateTeamMember('Liz Taster', 'ltaster@example.com', t('Product Owner')),
    //   new MigrateTeamMember('Larry Brewer', 'lbrewer@example.com', t('Implementor')),
    // );

    // Individual mappings in a migration can be linked to a ticket or issue
    // in an external tracking system. Define the URL pattern here in the shared
    // class with ':id:' representing the position of the issue number, then add
    // ->issueNumber(1234) to a mapping.
    //$this->issuePattern = 'http://drupal.org/node/:id:';
  }

  public function preImport() {
    parent::preImport();
    //clear the staging tables
    //db_truncate("hg_products");

    //pull in the excel file feed into the staging tables
    //file must be default/files/hgproductfeed.xls
    $feed_filename = file_stream_wrapper_get_instance_by_uri(variable_get("digital_core_asset_protocol", "s3://"))->getDirectoryPath() . '/hgproductfeed.xls';

    $product_data = phpexcel_import($feed_filename);

    // Must return one of the MigrationBase RESULT constants
    return MigrationBase::RESULT_COMPLETED;
  }

  function hg_migrate_phpexcel_import($op, &$data, $phpexcel, $options, $column = NULL, $row = NULL) {

  }

  public function postImport() {
    parent::postImport();
  }

  public function preRollback() {
    parent::preRollback();
  }

  public function postRollback() {
    parent::postRollback();
  }
}
/**
 * There are four essential components to set up in your constructor:
 *  $this->source - An instance of a class derived from MigrateSource, this
 *    will feed data to the migration.
 *  $this->destination - An instance of a class derived from MigrateDestination,
 *    this will receive data that originated from the source and has been mapped
 *    by the Migration class, and create Drupal objects.
 *  $this->map - An instance of a class derived from MigrateMap, this will keep
 *    track of which source items have been imported and what destination objects
 *    they map to.
 *  Mappings - Use $this->addFieldMapping to tell the Migration class what source
 *    fields correspond to what destination fields, and additional information
 *    associated with the mappings.
 */
class HGProductsMigration extends HGMigration {
  public function __construct() {
    parent::__construct();

    // Human-friendly description of your migration process. Be as detailed as you
    // like.
    $this->description = t('');

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects. Usually, you'll use the MigrateSQLMap
    // class, which uses database tables for tracking. Pass the machine name
    // (BeerTerm) of this migration to use in generating map and message tables.
    // And, pass schema definitions for the primary keys of the source and
    // destination - we need to be explicit for our source, but the destination
    // class knows its schema already.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'upc' => array('type' => 'varchar',
                           'length' => 15,
                           'not null' => FALSE,
                           'description' => '',
                          ),
        ),
        MigrateDestinationTerm::getKeySchema()
      );

    // In this example, we're using tables that have been added to the existing
    // Drupal database but which are not Drupal tables. You can examine the
    // various tables (starting here with migrate_example_beer_topic) using a
    // database browser like phpMyAdmin.
    // First, we set up a query for this data. Note that by ordering on
    // style_parent, we guarantee root terms are migrated first, so the
    // parent_name mapping below will find that the parent exists.
    $query = db_select('hg_products', 'prod');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);

    // Set up our destination - terms in the migrate_example_beer_styles vocabulary
    $this->destination = new MigrateDestinationNode('product_details');

    // Assign mappings TO destination fields FROM source fields. To discover
    // the names used in these calls, use the drush commands
    // drush migrate-fields-destination BeerTerm
    // drush migrate-fields-source BeerTerm

    //TODO
    // $this->addFieldMapping('title', 'productName');
    // $this->addFieldMapping('field_case_upc', 'caseUPC');
    // $this->addFieldMapping('field_master_case_upc', 'masterCaseUPC');
    // $this->addFieldMapping('field_available_bp', 'availableBP');
    // $this->addFieldMapping('field_available_mpw', 'availableMPW');
    // $this->addFieldMapping('field_available_er', 'availableER');
    // $this->addFieldMapping('field_available_rbs', 'availableRBS');
    // $this->addFieldMapping('field_product_owner', 'productOwner');
    // $this->addFieldMapping('field_east_new_arrival_date', 'eastNewArrivalDate');
    // $this->addFieldMapping('field_west_new_arrival_date', 'westNewArrivalDate');
    // $this->addFieldMapping('field_eta_start_date', 'etaStartDate');
    // $this->addFieldMapping('field_eta_end_date', 'etaEndDate');

  }
}
