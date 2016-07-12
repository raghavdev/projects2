<?php

// Print out exported items.
foreach ($themed_rows as $count => $item_row):
  if($item_row["field_shipper"] == 'N') { $item_row['field_shipper_components'] = array(); }
  print implode($separator, $item_row) . "\r\n";
endforeach;