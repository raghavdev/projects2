<?php
/**
 * @file
 * Contains the MacolaResultSet class.
 */

class MacolaResultSet implements Iterator, Countable {

  protected $total = 0;
  protected $page = 0;
  protected $per_page = 20;
  protected $count = 0;
  protected $results = array();
  protected $position = 0;

  public function __construct($data) {
    // Validate the response data
    if (isset($data->Total) && is_numeric($data->Total)) {
      $this->total = (int) $data->Total;
    }

    if (isset($data->Page) && is_numeric($data->Page)) {
      $this->page = (int) $data->Page;
    }

    if (isset($data->PerPage) && is_numeric($data->PerPage)) {
      $this->per_page = max((int) $data->PerPage, 1);
    }

    if (isset($data->Results) && is_array($data->Results)) {
      $this->results = $data->Results;
    }

    $this->count = count($this->results);
  }

  /**
   * {@inheritdoc}
   */
  public function current() {
    return $this->results[$this->position];
  }

  /**
   * {@inheritdoc}
   */
  public function next() {
    ++$this->position;
  }

  /**
   * {@inheritdoc}
   */
  public function key() {
    return $this->position;
  }

  /**
   * {@inheritdoc}
   */
  public function valid() {
    return isset($this->results[$this->position]);
  }

  /**
   * {@inheritdoc}
   */
  public function rewind() {
    $this->position = 0;
  }

  /**
   * {@inheritdoc}
   */
  public function count() {
    return $this->count;
  }

  /**
   * Get the total number of matches.
   *
   * @return int
   */
  public function getTotal() {
    return $this->total;
  }

  /**
   * Get the current page.
   *
   * @return int
   */
  public function getPage() {
    return $this->page;
  }

  /**
   * Returns the number of pages.
   *
   * @return int
   */
  public function getPageCount() {
    return max(ceil($this->total / $this->per_page), 1);
  }

}
