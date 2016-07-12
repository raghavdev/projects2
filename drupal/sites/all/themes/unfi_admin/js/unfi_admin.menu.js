(function ($) {

  Drupal.behaviors.unfiAdminMenu = {
    attach: function (context, settings) {
      $('#header', context).once('header', function() {
        var $self = $(this);

        $('button.menu', $self).on('click', function(e) {
          e.preventDefault();
          e.stopPropagation();

          $('#bmb-main-menu').toggleClass('open');
        });
      });
    }
  };

}(jQuery));
