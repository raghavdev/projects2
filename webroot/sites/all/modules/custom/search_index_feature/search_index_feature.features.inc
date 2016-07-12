<?php
/**
 * @file
 * search_index_feature.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function search_index_feature_default_search_api_index() {
  $items = array();
  $items['asset_index'] = entity_import('search_api_index', '{
    "name" : "asset_index",
    "machine_name" : "asset_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "file",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "fid" : { "type" : "integer" },
        "field_alt" : { "type" : "string" },
        "field_aperture_f_number" : { "type" : "string" },
        "field_asset_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_byte_order_motorola" : { "type" : "string" },
        "field_cmp_updated" : { "type" : "string" },
        "field_color_mode" : { "type" : "string" },
        "field_copyright_notice" : { "type" : "string" },
        "field_creator" : { "type" : "string" },
        "field_date_time" : { "type" : "string" },
        "field_date_time_original" : { "type" : "string" },
        "field_description" : { "type" : "string" },
        "field_exposure_time" : { "type" : "string" },
        "field_f_number" : { "type" : "string" },
        "field_file_date_time" : { "type" : "string" },
        "field_file_extension" : { "type" : "string" },
        "field_file_size" : { "type" : "string" },
        "field_focal_length" : { "type" : "string" },
        "field_internal_only" : { "type" : "boolean" },
        "field_iso_speed_ratings" : { "type" : "string" },
        "field_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_make" : { "type" : "string" },
        "field_mime_type" : { "type" : "string" },
        "field_model" : { "type" : "string" },
        "field_publicly_available" : { "type" : "boolean" },
        "field_sections_found" : { "type" : "string" },
        "field_thumbnail_file_type" : { "type" : "string" },
        "field_thumbnail_interchange_len" : { "type" : "string" },
        "field_thumbnail_jpeg_interchange" : { "type" : "string" },
        "field_thumbnail_mime_type" : { "type" : "string" },
        "field_thumbnail_resolution_unit" : { "type" : "string" },
        "field_thumbnail_x_resolution" : { "type" : "string" },
        "field_thumbnail_y_resolution" : { "type" : "string" },
        "field_title" : { "type" : "text", "boost" : "5.0" },
        "field_uploaded_by" : { "type" : "string" },
        "mime" : { "type" : "string" },
        "name" : { "type" : "text" },
        "owner" : { "type" : "integer", "entity_type" : "user" },
        "search_api_language" : { "type" : "string" },
        "size" : { "type" : "integer" },
        "timestamp" : { "type" : "date" },
        "type" : { "type" : "string" },
        "url" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_brand_long_description" : true,
              "field_upc" : true,
              "field_master_case_upc" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_brand_long_description" : true,
              "field_upc" : true,
              "field_master_case_upc" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_brand_long_description" : true,
              "field_upc" : true,
              "field_master_case_upc" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_brand_long_description" : true,
              "field_upc" : true,
              "field_master_case_upc" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "base_wholesale" : { "type" : "string" },
        "body:value" : { "type" : "string" },
        "case_height" : { "type" : "string" },
        "case_length" : { "type" : "string" },
        "case_weight" : { "type" : "string" },
        "case_width" : { "type" : "string" },
        "category_profile" : { "type" : "string" },
        "changed" : { "type" : "date" },
        "country_of_origin" : { "type" : "string" },
        "created" : { "type" : "date" },
        "discontinued" : { "type" : "string" },
        "display" : { "type" : "string" },
        "east_product_id" : { "type" : "string" },
        "etailer_net_margin" : { "type" : "string" },
        "etailer_price_after_discount" : { "type" : "string" },
        "factno" : { "type" : "string" },
        "field_active" : { "type" : "boolean" },
        "field_additional_images" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_allergens" : { "type" : "string" },
        "field_amount" : { "type" : "decimal" },
        "field_asset_collection_data" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_brand" : { "type" : "integer", "entity_type" : "node" },
        "field_brand_description" : { "type" : "string" },
        "field_brand_long_description" : { "type" : "text" },
        "field_calories" : { "type" : "integer" },
        "field_calories_from_fat" : { "type" : "integer" },
        "field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_cholesterol" : { "type" : "decimal" },
        "field_cholesterol_pdv" : { "type" : "decimal" },
        "field_collection_data" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_color" : { "type" : "string" },
        "field_consumer_brand_name" : { "type" : "string" },
        "field_consumer_product_name" : { "type" : "text", "boost" : "5.0" },
        "field_description1" : { "type" : "string" },
        "field_description2" : { "type" : "string" },
        "field_description3" : { "type" : "string" },
        "field_description4" : { "type" : "string" },
        "field_dietary_fiber" : { "type" : "decimal" },
        "field_dietary_fiber_pdv" : { "type" : "decimal" },
        "field_display_panel" : { "type" : "boolean" },
        "field_ein" : { "type" : "string" },
        "field_facebook" : { "type" : "string" },
        "field_feature1" : { "type" : "string" },
        "field_feature2" : { "type" : "string" },
        "field_feature3" : { "type" : "string" },
        "field_feature4" : { "type" : "string" },
        "field_feature5" : { "type" : "string" },
        "field_hg_color" : { "type" : "string" },
        "field_hg_description" : { "type" : "string" },
        "field_hg_height" : { "type" : "string" },
        "field_hg_length" : { "type" : "string" },
        "field_hg_map_policy_price" : { "type" : "boolean" },
        "field_hg_open" : { "type" : "boolean" },
        "field_hg_product_features" : { "type" : "string" },
        "field_hg_promo_discount" : { "type" : "string" },
        "field_hg_promo_features" : { "type" : "string" },
        "field_hg_scent" : { "type" : "string" },
        "field_hg_status" : { "type" : "boolean" },
        "field_hg_weight" : { "type" : "string" },
        "field_hg_width" : { "type" : "string" },
        "field_ingredients" : { "type" : "string" },
        "field_iron" : { "type" : "decimal" },
        "field_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_label_order" : { "type" : "integer" },
        "field_manufacturer_info" : { "type" : "string" },
        "field_map_policy_price" : { "type" : "string" },
        "field_master_case_upc" : { "type" : "text" },
        "field_nutritional_label_image" : { "type" : "integer", "entity_type" : "file" },
        "field_nutritional_shown" : { "type" : "boolean" },
        "field_percent_dv" : { "type" : "decimal" },
        "field_planogram_front_image" : { "type" : "integer", "entity_type" : "file" },
        "field_planogram_side_image" : { "type" : "integer", "entity_type" : "file" },
        "field_planogram_top_image" : { "type" : "integer", "entity_type" : "file" },
        "field_primary_image" : { "type" : "integer", "entity_type" : "file" },
        "field_print_image" : { "type" : "integer", "entity_type" : "file" },
        "field_protein" : { "type" : "decimal" },
        "field_protein_pdv" : { "type" : "decimal" },
        "field_recipe_urls" : { "type" : "list\\u003Cstring\\u003E" },
        "field_saturated_fat" : { "type" : "decimal" },
        "field_saturated_fat_pdv" : { "type" : "decimal" },
        "field_scent" : { "type" : "string" },
        "field_serving_size" : { "type" : "string" },
        "field_servings_per_container" : { "type" : "string" },
        "field_sodium" : { "type" : "decimal" },
        "field_sodium_pdv" : { "type" : "decimal" },
        "field_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_sugars" : { "type" : "decimal" },
        "field_sugars_pdv" : { "type" : "decimal" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_total_carbs" : { "type" : "decimal" },
        "field_total_carbs_pdv" : { "type" : "decimal" },
        "field_total_fat" : { "type" : "decimal" },
        "field_total_fat_pdv" : { "type" : "decimal" },
        "field_trans_fat" : { "type" : "decimal" },
        "field_twitter" : { "type" : "string" },
        "field_unit_height" : { "type" : "string" },
        "field_unit_length" : { "type" : "string" },
        "field_unit_weight" : { "type" : "string" },
        "field_unit_width" : { "type" : "string" },
        "field_upc" : { "type" : "text" },
        "field_user_bin" : { "type" : "boolean" },
        "field_video_link" : { "type" : "list\\u003Cstring\\u003E" },
        "field_video_link_alt" : { "type" : "list\\u003Cstring\\u003E" },
        "field_vitamin_a" : { "type" : "decimal" },
        "field_vitamin_c" : { "type" : "decimal" },
        "field_website" : { "type" : "string" },
        "field_youtube" : { "type" : "string" },
        "gtin" : { "type" : "string" },
        "item_department" : { "type" : "string" },
        "item_size" : { "type" : "string" },
        "item_type" : { "type" : "string" },
        "min_order_qty" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "pack" : { "type" : "string" },
        "qty_oh" : { "type" : "string" },
        "rcm_category" : { "type" : "string" },
        "rcm_department" : { "type" : "string" },
        "rcm_segment" : { "type" : "string" },
        "rcm_sub_segment" : { "type" : "string" },
        "retailer_item_num" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "selling_unit" : { "type" : "string" },
        "shelf_life" : { "type" : "string" },
        "source_created" : { "type" : "string" },
        "source_modified" : { "type" : "string" },
        "srp" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "vendor" : { "type" : "string" },
        "west_product_id" : { "type" : "string" },
        "wholesale_after_discount" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
