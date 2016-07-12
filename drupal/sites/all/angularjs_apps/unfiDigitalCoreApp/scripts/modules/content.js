/***********************************************************************************************************************************************
 * CONTENT MODULE
 ***********************************************************************************************************************************************
 * @description Builds content structure with meta data.
 */
app.service('content', ['module', '$q', '$http', function(module, $q, $http) {


  function content($scope) {
    var def = $q.defer();

    window.unfi = {};
    window.unfi.appended = [];

    //
    // META
    //------------------------------------------------------------------------------------------//
    // @description

    $scope.meta = {
      /**
       * PRODUCTS
       * @type {Object}
       */
      products: {
        list: {
          fields: [
            {name: 'product', predicate:'product_name', class:'product', record:'product_name'},
            {name: 'brand', predicate:'brand', class:'brand'},
            {name: 'Modified', predicate:'changed', class:'modified', record:'changed', formatting: 'time'},
            {name: 'SKU', predicate:'item_num', class:'upc'}
          ]
        },
        detail: {
          fields:[
            {title: 'Brand', type: ['product_details'], field: 'brand'},
            {title: 'SKU', type: ['product_details'], field: 'item_num'},
            {title: 'Last Updated', type: ['product_details'], field: 'changed', formatting: 'time'}
          ],
          header: {
            fields: [
              {name: 'SKU', record: 'item_num'},
              {name: 'File Title', record: 'product_name', formatting: 'capitalize'},
              {name: 'File Brand', record: 'brand'}
            ]
          },
          tabs: []
        },
        detail_pane: {
          product:
          {
            productname: {
              class: "detail-section",
              legend: "Extended Data",
              label: "Consumer Product Name",
              placeholder: "Four Fruits Preserve",
              record: "consumer_product_name",
              maxlength: "256"
            },
            coreproductdata: {
              class: "detail-section",
              legend: "Core Product Data",
              rows: [
                {label: 'SKU', record: 'item_num'},
                {label: 'Desc 1', record: 'title'},
                {label: 'Desc 2', record: 'desc_2'},
                {label: 'Consumer Name', record: 'consumer_name'}
              ]
            },
            gtin: {
              label: 'GTIN',
              record: 'gtin',
            },
            gtin_type: {
              label: "GTIN Type",
              record: 'gtin_type',
              options: [
                {name: 'UPC', value: 'upc'}
              ]
            },
            brand: {
              label: "Brand",
              record: 'brand'
            },
            activity_code: {
              label: "Activity Code",
              record: 'activity_code',
              options: [
                {name: 'Active', value: 'A'},
                {name: 'Forecasted', value: 'F'},
                {name: 'Obsolete', value: 'O'},
                {name: 'Planning', value: 'P'}
              ]
            },
            mtg_method: {
              label: "Mtg. Method",
              record: 'mtg_method',
              options: [
                {name: 'Order Entry', value: 'OE'},
                {name: 'PP', value: 'PP'}
              ]
            },
            active_date: {

            },
            item_category: {
              label: "Item Category",
              record: 'item_category',
              options: [
                {name: 'Purchased', value: 'P'},
                {name: 'Manufactured', value: 'M'},
              ]
            },
            material_cost_type: {
              label: "Matl Cost Type",
              record: "material_cost_type",
              options: [
                {name: 'Finished Goods', value: 'finished_goods'}
              ]
            },
            product_category: {
              label: "Product Category",
              record: 'product_category',
              options_key: 'categories'
            },
            macola: {
                label: 'Available in Macola',
                record: 'macola'
            },
            web_item: {
                label: 'Web Item',
                record: 'web_item'
            },
            report_sales: {
                label: 'Report Sales',
                record: 'report_sales'
            },
            print_flag: {
                label: 'Print Flag',
                record: 'print_flag'
            },
            is_discontinued: {
                label: 'Is Discontinued',
                record: 'is_discontinued'
            },
            unfi_east: {
              label: 'UNFI East',
              record: 'unfi_east'
            },
            unfi_west: {
              label: 'UNFI West',
              record: 'unfi_west'
            },
            target: {
              label: 'Target',
              record: 'target'
            }
          },
          dimensions: {
            //will probably need to repeat this for each field instance, but I really don't want to
            uom: {
              record: 'uom',
              options: [
                {name: 'CS', value: 'CS'},
                {name: 'LB', value: 'LB'},
                {name: 'EA', value: 'EA'},
                {name: 'CA', value: 'CA'},
                {name: 'FT', value: 'FT'}
              ]
            },
            selling_ratio: {
              record:'selling_ratio',
              label: 'Selling Ratio'
            },
            purchasing_ratio: {
              label: 'Purchasing Ratio',
              record: 'purchasing_ratio'
            },
            mfg_ratio: {
              label: 'Manufacturing Ratio',
              record: 'manufacturing_ratio'
            },
            case_width: {
              label: "Case Width",
              record: "case_width"
            },
            case_length: {
              label: "Case Length",
              record: "case_length"
            },
            case_height: {
              label: "Case Height",
              record: "case_height"
            },
            casetable: {
              rows: [
                {label:'Cube Feet', record: 'cube_feet'},
                {label: 'Qty/Cube', record: 'qty_cube'},
                {label: 'Case Qty', record: 'case_qty'},
                {label: 'Net Weight', record: 'net_weight'},
                {label: 'Gross Weight', record: 'gross_weight'}
              ]
            },
            item_width: {
              label: 'Item Width',
              record: 'item_width'
            },
            item_length: {
              label: 'Item Length',
              record: 'item_length'
            },
            item_height: {
              label: 'Item Height',
              record: 'item_height'
            },
            item_size: {
              label: 'Item Size',
              record: 'item_size'
            },
            item_weight: {
              label: 'Item Weight',
              record: 'item_weight'
            }
          },
          supply_chain: {
            location: {
              label: 'Primary Location',
              record: 'primary_location',
              options: [
                {name: 'HAL', value: 'HAL'}
              ]
            },
            grocery_type: {
              label: 'Grocery Type',
              record: 'grocery_type',
              options: [
                {name: 'Chilled', value: 'chilled'}
              ]
            },
            shelf_life: {
              label: 'Shelf Life Days',
              record: 'shelf_life_days'
            },
            warranty: {
              label: 'Warranty Days',
              record: 'warranty_days'
            },
            east_freight: {
              label: 'East Freight Rate',
              record: 'east_freight_rate'
            },
            west_freight: {
              label: 'West Freight Rate',
              record: 'west_freight_rate'
            },
            pallettable: {
              legend: 'Pallet',
              rows: [
                {label: 'Pallet Type', record: 'pallet_type'},
                {label: 'Tie', record: 'tie'},
                {label: 'High', record: 'high'},
                {label: 'Pallet Height', record: 'pallet_height'},
                {label: 'Pallet Weight', record: 'pallet_weight'},
                {label: 'Pallet Charges', record: 'pallet_charges'}
              ]
            }
          },
          attributes: {
            //Is there a better way than listing every attribute label + record?
          },
          marketing: {
            short_desc: {
              legend: 'Short Description'
            },
            long_desc: {
              legend: 'Long Description'
            }
          },
          nutritional: {
            ingredients: {
              class: "",
              legend: "Ingredients",
              record: "ingredients",
              max_chars: 512,
              modified: "ingredients_modified",
              modified_user: "ingredients_mod_user",
              validator: "modifiedDate"
            },
            allergens: {
              class: "",
              legend: "Allergens",
              record: "allergens",
              max_chars: 512,
              validator: "always"
            }
          },
          external: {
            externaltable: {
              legend: 'External System IDs',
              rows: [
                {label: 'UNFI East ID', record: 'unfi_east_id'},
                {label: 'UNFI West ID', record: 'unfi_west_id'},
                {label: 'HIC Item Num', record: 'hic_item_num'},
                {label: 'HPW Item Num', record: 'hpw_item_num'},
                {label: 'RBW Item Num', record: 'rbw_item_num'}
              ]
            }
          },
          certificates: {

          }
        },
        search: {
          category: 'category',
          collection: "collection"
        },
        display_image: 'thumb_url',
        identifier: 'nid'
      }
    };

    def.resolve();

    return def.promise;
  }

  module.register({name:'content', fn: content});

}]);