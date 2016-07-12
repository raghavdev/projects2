<?php
if ($logged_in) {
  $menu = menu_navigation_links('menu-digital-core-menu');
  print theme('links__menu-digital-core-menu', array(
    'links' => $menu,
    'attributes' => array(
      'id' => 'digital-core-menu',
      'class' => array('links', 'clearfix'),
    )
  ));
}
?>

<!--[if lte IE 8]>
  <script>
    document.createElement('ng-include');
    document.createElement('ng-pluralize');
    document.createElement('ng-view');
    document.createElement('ng-class');

    // Optionally these for CSS
    document.createElement('ng:include');
    document.createElement('ng:pluralize');
    document.createElement('ng:view');
    document.createElement('ng:class');
  </script>
<![endif]-->
<script type="text/javascript">
  window.hasOwnProperty = window.hasOwnProperty || function (key) { return Object.prototype.hasOwnProperty.call(window, key);};
</script>
<div id="angular-view-wrapper" ng-view=""></div>