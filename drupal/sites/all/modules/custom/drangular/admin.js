(function ($) {
  removeRow = function(type, rowID) {

    var weight = $("#edit-" + type + "-table-rows-" + rowID + "-weight");
    var row = $("#" + type + "_table_row_" + rowID);

    weight.val('-1');
    row.hide();

    return (false);
  }
})(jQuery);

