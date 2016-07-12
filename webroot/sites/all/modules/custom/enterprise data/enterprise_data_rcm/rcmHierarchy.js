(function ($) {
  Drupal.behaviors.rcmhierarchy = {
    attach: function(context, settings) {
      $("#add-dialog").dialog({ autoOpen: false,
                            modal: true} );

      $("#edit-dialog").dialog({ autoOpen: false,
       modal: true} );

      $('#edit-add-dept', context).on('click', function(e){

        e.preventDefault();

        //do an ajax call to get the dialog contents
        var request = $.ajax({
          url: "/node/add/rcm-hierarchy",
          type: "GET",
          dataType: "html"
        });

        request.done(function(data) {

          //pull the drupal content out of the page to frame in the dialog
          var content = $(data).find(".content");

          var token = $(content).find("input[name='form_token']");
          var buildid = $(content).find("input[name='form_build_id']");
          var formid = $(content).find("input[name='form_id']");

          $('#add-dialog-content').html(content);

          //massage the ui a little
          //no need for the body
          $('.form-item-body-und-0-value').hide();
          $('#body-add-more-wrapper').hide();

          //no need for the vertical tabs
          $('.vertical-tabs-panes').hide();

          //kill the preview
          $('#edit-preview').hide();

          //hide the level selection, need to do that dynamically
          $('.field-name-field-level').hide();

          //show the dialog
          $("#add-dialog").dialog("open");

          $('#edit-submit', context).on('click', function(e) {
            e.preventDefault();
            $("#add-dialog").dialog("close");

            //save the data
            //do an ajax call to drupal to save this data
            var request = $.ajax({
              url: "/node/add/rcm-hierarchy",
              type: "POST",
              dataType: "html",
              data: {
                "title": $("#edit-title").val(),
                "body[und][0][summary]":"",
                "body[und][0][value]":"",
                "body[und][0][format]":"filtered_html",
                "field_profile[und][0][value]":$("#edit-field-profile-und-0-value").val(),
                "field_active[und]":$("#edit-field-active-und").val(),
                "field_level[und][0][value]":$("#edit-field-level-und-0-value").val(),
                "field_parent[und]":$("#edit-field-parent-und").val(),
                "revision_operation":1,
                "comment":2,
                "log": "",
                "changed": "",
                "status":1,
                "promote":1,
                "name": $("#edit-name").val(),
                "unique_field_override": 0,
                "publication_date": "",
                "menu[link_title]": "",
                "menu[description]": "",
                "menu[weight]": 0,
                "path[alias]": "",
                "additional_settings__active_tab": "edit-revision-information",
                "menu[parent]": "main-menu:0",
                "form_build_id":buildid.val(),
                "form_token":token.val(),
                "form_id":formid.val(),
                "op":"Save",
              }
            });

            //need to show the department that was just added.... ugh.....
            request.done(function(data) {

              //get the nid and level from the response
              var nid = $(data).find(".node").attr("id").replace("node-", "");

              var level = $(data).find(".field-name-field-level .field-item").text();

              //can get if the parent is shown by looking for hierarchy-link-PARENT

              var levelClass = "departments";
              switch(level) {
                case 2: {
                    levelClass = "categories";
                    break;
                }
                case 3: {
                    levelClass = "segments";
                    break;
                }
                case 4: {
                    levelClass = "subsegments";
                    break;
                }
              }

              //setup the element to add
              var newItem = '<li class="'+levelClass+' collapsed">\n\
                              <a href="/admin/enterprisedata/rcm/hierarchy/data/'+nid+'/'+level+'" id="hierarchy-link-'+nid+
                              '" class="rcm-hierarchy-node '+levelClass+' collapsed ajax-processed">'+$("#edit-title").val()+'</a>\n\
                              <div id="hierarchy_container_'+nid+'"></div>\n\
                            </li>';

              if($("#edit-field-parent-und").val() != "_none") {
                //var parent = $('#hierarchy-link-'+$("#field_parent[und]").val());
                var parentContainer = $('#hierarchy_container_'+$("#edit-field-parent-und").val());

                //if this has children, then we must add this new one to the list
                if(parentContainer[0].children.length > 0) {
                  //.append();
                  var container = $('#hierarchy_container_'+$("#edit-field-parent-und").val() + ".fieldset-wrapper");
                  container.append(newItem);
                }
              }
              else {
                //this is base level add it there
                //get the base container
                $('#edit-base .fieldset-wrapper').append(newItem);
              }

              //attach the javascript to this new item for the on click
              //since there arnt any children just disable the on click for it for now
              //TODO come back to this possibly and make it really work if more items are added under it
              $('#hierarchy-link-'+nid, context).on('click', function(e) {
                e.preventDefault();
              });
            });
          });
        });
      });

      //add on click handler to collapse an open branch
      $('.rcm-hierarchy-node', context).on('click', function(){
        //toggle the collapsed flag
        $(this).parent().toggleClass("collapsed");
      });

      //toggle disabled nodes
      $('#show_disabled', context).on('click', function(e){
        if($(this).is(':checked')) {
          $(".disabled-node").removeClass("hidden");
        }
        else {
          $(".disabled-node").addClass("hidden");
        }
      });
    }
  };
})(jQuery);