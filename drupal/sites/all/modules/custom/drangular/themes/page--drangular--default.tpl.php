<?php
// todo: Temporary, need to make sure we're actually using the browse.tpl and take this back out.
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
<div id="angular-view-wrapper" ng-view=""></div>