jQuery(document).ready(function($) {
  /**
   * This function will allow the admin menu check to repeat until the menu is available.
   * @param callback
   * @param interval
   * @param repeat
   * @returns {*}
   */
  function repeat_function(callback, interval, repeat) {
    // Check for number of times to repeat, default to once.
    repeat = typeof repeat == 'undefined' ? 1 : repeat;
    // Check for time between checks, default to 1 second.
    interval = interval <= 0 ? 1000 : interval;
    var offset = 0;
    var id = null;
    // Repeat until finished.
    if (repeat > 0) {
      for (var i = 0; i < repeat; i++) {
        id = setTimeout(callback, interval * (i + offset));
      }
    }

    return id;
  }

  /**
   * Check if the admin menu is there and still needs to be initialized.
   */
  function init_admin_menu() {
    var admin_menu = $('#admin-menu');

    // If not there, or not ready, or already initialized, bail out.
    if (!admin_menu || (admin_menu.height() == null) || admin_menu.hasClass('initialized')) {
      return;
    }

    // Find the height, make it negative, and add a few pixels of overlap.
    var initial_height = (admin_menu.height() * -1 + 4);

    // Set the initial position of the admin menu.
    admin_menu.css('position', 'fixed');
    admin_menu.css('top', initial_height);
    admin_menu.addClass('initialized');

    // Set up the hover and blur listeners.
    var timeout = null;
    admin_menu.hover(
      function() {
        if (timeout) {
          clearTimeout(timeout);
          timeout = null;
        }
        $(this).animate({ top: 0 }, 'fast');
      },
      function() {
        var menuBar = $(this);
        timeout = setTimeout(function() {
          timeout = null;
          menuBar.animate({ top: initial_height }, 'slow');
        }, 1000);
      }
    );
  }

  // Repeat the init function until it runs.
  repeat_function(init_admin_menu, 100, 30);

});
