(function ($) {

  Drupal.behaviors.rcmhierarchyEdit = {
    attach: function(context, settings) {

      $("#item-select-all").change(function(e) {
        $(".item-selectcheck").prop("checked", $("#item-select-all").prop("checked"));
      });

      $("#deactivation-dialog").dialog({autoOpen: false, modal: true});

      $('#edit-activebtn', context).on('click', function(e){
        e.preventDefault();
        if($('#edit-activebtn').val() == "Disable") {

          $("#deactivation-dialog").dialog("open");

          $('#dialog-disable', context).on('click', function(e){

            var request = $.ajax({
                url: "/admin/enterprisedata/rcm/hierarchy/item/move",
                type: "POST",
                dataType: "html",
                data : {
                  "items" : "all",
                  "from" : $("#hierarchy-nid").val(),
                  "to" : $("#edit-move").val()
                }
              });

            request.done(function(data) {
              //remove the items from the list
              $(".view-rcm-item-assignment tbody").remove();

              //change the disable to enable button
              $("#edit-activebtn").val("Enable");

              //send the request to deactivate the category
              var request = $.ajax({
                url: "/admin/enterprisedata/rcm/hierarchy/edit/"+$("#hierarchy-nid").val(),
                type: "POST",
                dataType: "html",
                data : {
                  "active" : 0,
                  "op":"Save",
                  "form_build_id":$("input[name='form_build_id']").val(),
                  "form_token":$("input[name='form_token']").val(),
                  "form_id":$("input[name='form_id']").val()
                }
              });
            });

            e.preventDefault();
            $("#deactivation-dialog").dialog("close");
          });

          $('#dialog-cancel', context).on('click', function(e){
            e.preventDefault();
            $("#deactivation-dialog").dialog("close");
          });
        }
        else {
          //send a request to activate this category
          //send the request to deactivate the category
          var request = $.ajax({
            url: "/admin/enterprisedata/rcm/hierarchy/edit/"+$("#hierarchy-nid").val(),
            type: "POST",
            dataType: "html",
            data : {
              "active" : 1,
              "op":"Save",
              "form_build_id":$("input[name='form_build_id']").val(),
              "form_token":$("input[name='form_token']").val(),
              "form_id":$("input[name='form_id']").val()
            }
          });

          request.done(function() {
            //change the disable to disable button
            $("#edit-activebtn").val("Disable");
          })
        }
      });
    }
  }
 /**
 * Puts the currently highlighted suggestion into the autocomplete field.
 * Overridden from misc/autocomplete.js to add an event trigger on autocomplete
 */
if (Drupal.jsAC) {
  Drupal.jsAC.prototype.select = function (node) {
    //this.input.value = $(node).data('autocompleteValue');
    this.input.value = node.innerText;

    //set the hidden value to the nid
    $("#item-nid").val($(node).data('autocompleteValue'));
  };

  //this is the core function with a custom trigger added
  Drupal.jsAC.prototype.hidePopup = function (keycode) {
    // Select item if the right key or mousebutton was pressed.
    if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
      //this.input.value = $(this.selected).data('autocompleteValue');
      this.input.value = this.selected.innerText;

      //set the hidden value to the nid
      $("#item-nid").val($(this.selected).data('autocompleteValue'));
    }
    // Hide popup.
    var popup = this.popup;
    if (popup) {
      this.popup = null;
      $(popup).fadeOut('fast', function () { $(popup).remove(); });
    }
    this.selected = false;
    $(this.ariaLive).empty();
  };
}
})(jQuery);
