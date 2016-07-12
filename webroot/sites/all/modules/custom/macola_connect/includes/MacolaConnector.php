<?php
/**
 * @file
 * Contains the MacolaConnector class.
 */

class MacolaConnector {

  protected $url;

  /**
   * Constructor
   *
   * @param $url
   *    The Macola API base url.
   */
  public function __construct($url) {
    $this->url = $url;
  }

  /**
   * Send a request to the Macola API.
   *
   * @param $path
   *    The API endpoint to call.
   * @param string $method
   *    The HTTP Method in all caps. Defaults to GET.
   * @param array $data
   *    An array of parameters to pass. This is translated to url parameters
   *    for GET requests and a json encoded request body for all other requests.
   *
   * @return bool|mixed
   *    Returns a json decoded response or FALSE on failure.
   */
  public function sendRequest($path, $method = 'GET', $data = array()) {
    $full_url = rtrim($this->url, '/') . '/' . trim($path, '/');
    $options = array(
      'method' => $method,
    );
    if ($method == 'GET' && !empty($data)) {
      $full_url .= '?' . drupal_http_build_query($data);
    }
    elseif (!empty($data)) {
      $options['headers']['Content-Type'] = 'application/json';
      $options['data'] = json_encode($data);
    }
    $result = drupal_http_request($full_url, $options);

    if ($result->code == 200) {
      return json_decode($result->data);
    }

    watchdog('macola_connect', 'Request @path error: @error. Method: @method Full URL: @url. Data: @data Response: @response', array(
      '@path' => $path,
      '@error' => isset($result->error) ? $result->error : $result->code,
      '@method' => $method,
      '@url' => $full_url,
      '@data' => print_r($options, 1),
      '@response' => print_r($result, 1),
    ), WATCHDOG_ERROR);
    return FALSE;
  }

  /**
   * Get Product Categories from the Macola API.
   *
   * @return array
   *    List of Product Categories.
   */
  public function getCategories() {
    $result = $this->sendRequest('ProductCategories/ListAll');
    $categories = array();
    if ($result) {
      if (isset($result->Results) && is_array($result->Results)) {
        $categories = $result->Results;
      }
    }
    return $categories;
  }

  /**
   * Get Material Cost Types from the Macola API.
   *
   * @return array
   *    List of Material Cost Types.
   */
  public function getMaterialCostTypes() {
    $result = $this->sendRequest('MaterialCostTypes/ListAll');
    $material_cost_types = array();
    if ($result) {
      if (isset($result->Results) && is_array($result->Results)) {
        $material_cost_types = $result->Results;
      }
    }
    return $material_cost_types;
  }

  /**
   * Get Locations from the Macola API.
   *
   * @return array
   *    List of Locations.
   */
  public function getLocations() {
    $result = $this->sendRequest('Locations/ListAll');
    $locations = array();
    if ($result) {
      if (isset($result->Results) && is_array($result->Results)) {
        $locations = $result->Results;
      }
    }
    return $locations;
  }

  /**
   * Get Users from the Macola API.
   *
   * @return array
   *    List of Users.
   */
  public function getUsers() {
    $result = $this->sendRequest('Users/ListAll');
    $users = array();
    if ($result) {
      if (isset($result->Results) && is_array($result->Results)) {
        // Adjust the response to return data in the same format as we expect
        // from the other endpoints.
        foreach ($result->Results as $row) {
          $users[] = (object) array(
            'id' => $row->id,
            'name' => $row->number,
            'description' => $row->name,
          );
        }
      }
    }
    return $users;
  }

  /**
   * Search Products from the Macola API.
   *
   * @param int
   *   The page to request. Defaults to 1.
   * @param int
   *   The number of items requested. Defaults to 100.
   * @param string
   *   The field to sort on. Defaults to 'updated'.
   * @param string
   *   The direction to sort, either 'ASC' or 'DESC'. Defaults to 'DESC'.
   *
   * @return MacolaResultSet
   *    A MacolaResultSet object.
   */
  public function searchProducts($page = 1, $per_page = 100, $sort = 'updated', $sort_dir = 'DESC') {
    $data = array(
      'page' => $page,
      'perPage' => $per_page,
      // TODO: the sort params are not implemented in Macola's API,
      // so they don't work
      'sort' => $sort,
      'sort_dir' => (strtoupper($sort_dir) == 'DESC' ? 'DESC' : 'ASC'),
    );

    $result = $this->sendRequest('Products/List', 'GET', $data);

    return new MacolaResultSet($result);
  }

  /**
   * Get a single product from the Macola API.
   *
   * @param string
   *   The Item Number for the product.
   *
   * @return object
   *   A product object or FALSE on failure.
   */
  public function getProduct($item_no) {
    $data['itemNumber'] = $item_no;
    $result = $this->sendRequest('Products/Load', 'GET', $data);
    if ($result && $result->item_no == $item_no) {
      return $result;
    }
    return FALSE;
  }

  /**
   * Create Product.
   *
   * @param object
   *   A product object. Once created the product object will have an id.
   *
   * @return boolean
   *   True if the product was created successfully. False otherwise.
   */
  public function createProduct($product) {
    // Product already exists if it has an id.
    if (isset($product->id)) {
      return TRUE;
    }
    $result = $this->sendRequest('Products/Create', 'POST', $product);
    if ($result && isset($result->id)) {
      $product->id = $result->id;
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Update Product.
   *
   * @param object
   *  A product object. Include only the parameters that should be updated.
   *
   * @return boolean
   *   True if the product was updated successfully. False otherwise.
   */
  public function updateProduct($product) {
    // Product does not have an id, we cannot update it.
    if (!isset($product->item_no)) {
      watchdog('macola_connect', 'Item number missing when updating product. @product', array(
        '@product' => print_r($product, 1),
      ));
      return FALSE;
    }
    $result = $this->sendRequest('Products/Update', 'POST', $product);
    if ($result) {
      return TRUE;
    }
    return FALSE;
  }


  /**
   * Get Product Vendor Prices for a product.
   *
   * @param string
   *   The Item Number for the product.
   *
   * @return MacolaResultSet
   *    A MacolaResultSet object.
   */
  public function getProductVendorPrices($item_no) {
    if (!empty($item_no)) {
      $data['itemNumber'] = $item_no;
      $result = $this->sendRequest('ProductVendorPrices/List', 'GET', $data);
    }
    else {
      watchdog('macola_connect', 'Missing or empty item number (@type) @value', array(
        '@type' => gettype($item_no),
        '@value' => print_r($item_no, 1),
      ));
      $result = (object) array();
    }

    return new MacolaResultSet($result);
  }

  /**
   * Get a Product Vendor Price.
   *
   * @param string
   *   The Item Number for the product.
   * @param string
   *   The Vendor Number for the vendor.
   */
  public function getProductVendorPrice($item_no, $vendor_no) {
    $data['itemNumber'] = $item_no;
    $data['vendorNumber'] = $vendor_no;
    $result = $this->sendRequest('ProductVendorPrices/Load', 'GET', $data);
    if ($result && $result->item_no == $item_no && $result->vend_no == $vendor_no) {
      return $result;
    }
    return FALSE;
  }

  /**
   * Create Product Vendor Price for a product.
   *
   * @param object
   *   A product vendor price object. Once created the product vendor price will
   *   have an id.
   *
   * @return boolean
   *   True if the product vendor price was create created successfully. False
   *   otherwise.
   */
  public function createProductVendorPrice($product_vendor_price) {
    // Product Vendor Price already exists if it has an id.
    if (isset($product_vendor_price->id)) {
      return TRUE;
    }
    $result = $this->sendRequest('ProductVendorPrices/Create', 'POST', $product_vendor_price);
    if ($result && isset($result->id)) {
      $product_vendor_price->id = $result->id;
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Update Product.
   *
   * @param object
   *  A product vendor price object. Include only the parameters that should be updated.
   *
   * @return boolean
   *   True if the product vendor price was updated successfully. False otherwise.
   */
  public function updateProductVendorPrice($product_vendor_price) {
    // Product Vendor Price does not have an id, we cannot update it.
    if (!isset($product_vendor_price->id)) {
      watchdog('macola_connect', 'Id missing when updating product vendor price. @product_vendor_price', array(
        '@product_vendor_price' => print_r($product_vendor_price, 1),
      ));
      return FALSE;
    }
    $result = $this->sendRequest('ProductVendorPrices/Update', 'POST', $product_vendor_price);
    if ($result) {
      return TRUE;
    }
    return FALSE;
  }

}
