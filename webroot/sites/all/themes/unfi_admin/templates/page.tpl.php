<div id="header">
  <div class="section clearfix">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    <?php endif; ?>

    <?php if ($logged_in): ?>
      <md-button class="md-icon-button md-primary" aria-label="Settings">
              <md-icon md-svg-icon="img/icons/menu.svg"></md-icon>
      </md-button>
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

<div id="branding" class="clearfix">
  <?php if (!empty($breadcrumb)): ?>
    <?php print $breadcrumb; ?>
  <?php endif; ?>

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h1 class="page-title">
      <?php print $title; ?>
      </h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
     <div id="tab-bar" class="clearfix">
    <?php print render($tabs); ?>
    </div>
  </div>

  <div id="page"<?php echo theme_get_setting('unfi_admin_no_fadein_effect') ? '' : ' class="fade-in"'?>>

  <?php if ($page['help']): ?>
    <?php print render($page['help']); ?>
  <?php endif; ?>

  <?php if ($messages): ?>
    <div id="console" class="clearfix">
      <?php print $messages; ?>
    </div>
  <?php endif; ?>

  <div id="content" class="clearfix">
    <div class="element-invisible">
      <a id="main-content"></a>
    </div>
    <div class="actions">
    <?php if ($action_links): ?>
        <ul class="action-links">
        <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>
    </div>
    <?php print render($page['content']); ?>
  </div>

  <div id="footer">
    <?php print $feed_icons; ?>
  </div>

</div>
