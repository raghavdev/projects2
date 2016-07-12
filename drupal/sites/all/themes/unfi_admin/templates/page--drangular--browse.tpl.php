<div id="header"><div class="section clearfix">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    <?php endif; ?>

    <?php if ($logged_in): ?>
      <button class="menu menu-icon" aria-label="Menu"></button>
    <?php
      $menu = menu_navigation_links('menu-digital-core-menu');
      print theme('links__menu-digital-core-menu', array(
        'links' => $menu,
        'attributes' => array(
          'id' => 'bmb-main-menu',
          'class' => array('links', 'clearfix'),
        )
      ));
    ?>
    <?php endif; ?>
  </div>
</div>

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
