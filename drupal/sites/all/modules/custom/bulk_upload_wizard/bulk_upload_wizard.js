(function ($) {
  Drupal.behaviors.bulkUploadWizard = {

    attach: function (context, settings) {

      $('#edit-asset').val("");

      $('#edit-asset').change(function() {
        if(Drupal.settings.bulk_upload_wizard.asset_info[$('#edit-asset').val()].uploader == "file") {
          $('#edit-file-upload-fieldset').show();
          $('#edit-upload-fieldset').hide();
        }
        else {
          $('#edit-file-upload-fieldset').hide();
          $('#edit-upload-fieldset').show();
        }

        $(".asset-options").hide();
        $("#" + $('#edit-asset').val() + "-options").show();
        $('#uploader_type').val(Drupal.settings.bulk_upload_wizard.asset_info[$('#edit-asset').val()].uploader);
      });
    }
  };
})(jQuery);

function filesAddedCallback() {

}

function uploadCompleteCallback() {
  jQuery('#edit-submit').show();
}