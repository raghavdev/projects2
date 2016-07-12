(function ($) {
  Drupal.behaviors.bulkDownloadWizard = {
    attach: function (context, settings) {
       $('.idt_radio').change(function() {
         if($(this).val()) {
           $('input[name=identity_column]').val($(this).val());
          //$('[name="submitted[identity_column]"]').val($(this).val());

         }
       });
    }
  };
})(jQuery);