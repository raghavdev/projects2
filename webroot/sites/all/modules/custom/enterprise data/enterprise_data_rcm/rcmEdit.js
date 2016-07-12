(function ($) {
  Drupal.behaviors.rcmhierarchy = {
    attach: function(context, settings) {
      $("#dialog").dialog({ autoOpen: false,
                            modal: true} );

      $('.item-edit', context).on('click', function(e){

        var nid = e.srcElement.hash.substring(1, e.srcElement.hash.length);

        //do an ajax call to get the dialog contents
        var request = $.ajax({
          url: "/admin/enterprisedata/rcm/item/edit/" + nid,
          type: "GET",
          dataType: "html"
        });

        request.done(function(data) {

          //pull the drupal content out of the page to frame in the dialog
          var content = $(data).find(".content");

          $('#dialog-content').html(content);

          //re hook up the auto complete functions
          Drupal.behaviors.autocomplete.attach(document);

          $("#dialog").dialog("open");

          //attach some logic to the buttons
          $('#cancel-button', context).on('click', function(e) {
            e.preventDefault();
            $("#dialog").dialog("close");
          });

          $('#save-button', context).on('click', function(e) {
            e.preventDefault();
            //do an ajax call to drupal to save this data
            var request = $.ajax({
              url: "/admin/enterprisedata/rcm/item/edit/" + nid,
              type: "POST",
              dataType: "html",
              data: {
                "nid": nid,
                "flavor": $("#edit-flavor").val(),
                "product_type": $("#edit-product-type").val(),
                "form": $("#edit-form").val(),
                "ethnicity": $("#edit-ethnicity").val(),
                "rcm_hierarchy": $("#edit-rcm-hierarchy").val(),
                "op":"Save",
                "form_build_id":$("input[name='form_build_id']").val(),
                "form_token":$("input[name='form_token']").val(),
                "form_id":$("input[name='form_id']").val()
              }
            });

            $("#dialog").dialog("close");
          });
        });

        e.preventDefault()
      });
    }
  };
})(jQuery);