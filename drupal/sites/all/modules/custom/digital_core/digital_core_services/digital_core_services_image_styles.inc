<?php

//Return a list of the image styles that are defined
function digital_core_services_image_styles_index() {
  return image_styles();
}

//return an array of the image files defined for the styles of the specified image file
function digital_core_services_image_styles_retrieve($image_file) {
  return digital_core_assets_get_file_rendition_urls($image_file);
}