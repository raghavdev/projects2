<?php

// Print out exported items.
foreach ($themed_rows as $count => $item_row):
  //if($item_row["field_shipper"] == 'No') { $item_row['field_shipper_components'] = array(); }
  $item_row["field_shipper"] =  "Testing";
  print implode($separator, $item_row) . "\r\n";
endforeach;