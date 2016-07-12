<?php
/**
 * @file
 * enterprise_data_brands.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enterprise_data_brands_taxonomy_default_vocabularies() {
  return array(
    'brand_customer_name' => array(
      'name' => 'Brand Customer Name',
      'machine_name' => 'brand_customer_name',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
