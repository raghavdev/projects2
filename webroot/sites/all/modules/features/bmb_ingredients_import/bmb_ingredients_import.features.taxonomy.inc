<?php
/**
 * @file
 * bmb_ingredients_import.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bmb_ingredients_import_taxonomy_default_vocabularies() {
  return array(
    'ingredients' => array(
      'name' => 'Ingredients',
      'machine_name' => 'ingredients',
      'description' => 'Base Ingredient List',
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
