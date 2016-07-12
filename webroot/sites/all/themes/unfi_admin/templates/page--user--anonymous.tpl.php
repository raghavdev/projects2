<div id="header"><div class="section clearfix">
        <?php if ($logo): ?>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
        <?php endif; ?>

        <?php
        if ($logged_in) {
            $menu = menu_navigation_links('menu-digital-core-menu');
            print theme('links__menu-digital-core-menu', array(
                'links' => $menu,
                'attributes' => array(
                    'id' => 'bmb-main-menu',
                    'class' => array('links', 'clearfix'),
                )
            ));
        }
        ?>
    </div>
</div>

<div id="branding" class="clearfix">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h1 class="page-title">
            <?php print $title; ?>
        </h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
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
        <div class="row">
            <div class="eight columns"><?php print render($page['content']); ?></div>
            <div class="four columns"><img src="/<?php print $directory; ?>/images/bmb_welcome_image.png" /></div>
        </div>

    </div>

    <div id="footer">
        <?php print $feed_icons; ?>
    </div>

</div>
