<?php
/**
 * @file
 * digital_core.features.exif_custom.inc
 */

/**
 * Implements hook_exif_custom_export_maps().
 */
function digital_core_exif_custom_export_maps() {
  $items = array(
    'product image' => array(
      'name' => 'product image',
      'fields' => array(
        0 => array(
          'exif_field' => 'EXIF:FILE:FileName',
          'exif_example' => '46437cc.jpg',
          'img_field' => 'filename',
        ),
        1 => array(
          'exif_field' => 'EXIF:FILE:FileDateTime',
          'exif_example' => 1393449613,
          'img_field' => 'field_file_date_time',
        ),
        2 => array(
          'exif_field' => 'EXIF:FILE:FileSize',
          'exif_example' => 530353,
          'img_field' => 'field_file_size',
        ),
        3 => array(
          'exif_field' => 'EXIF:FILE:FileType',
          'exif_example' => 2,
          'img_field' => 'none',
        ),
        4 => array(
          'exif_field' => 'EXIF:FILE:MimeType',
          'exif_example' => 'image/jpeg',
          'img_field' => 'field_mime_type',
        ),
        5 => array(
          'exif_field' => 'EXIF:FILE:SectionsFound',
          'exif_example' => 'ANY_TAG, IFD0, THUMBNAIL, EXIF',
          'img_field' => 'field_sections_found',
        ),
        6 => array(
          'exif_field' => 'EXIF:COMPUTED:html',
          'exif_example' => 'width="1600" height="1600"',
          'img_field' => 'none',
        ),
        7 => array(
          'exif_field' => 'EXIF:COMPUTED:Height',
          'exif_example' => 1600,
          'img_field' => 'none',
        ),
        8 => array(
          'exif_field' => 'EXIF:COMPUTED:Width',
          'exif_example' => 1600,
          'img_field' => 'none',
        ),
        9 => array(
          'exif_field' => 'EXIF:COMPUTED:IsColor',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        10 => array(
          'exif_field' => 'EXIF:COMPUTED:ByteOrderMotorola',
          'exif_example' => 1,
          'img_field' => 'field_byte_order_motorola',
        ),
        11 => array(
          'exif_field' => 'EXIF:COMPUTED:ApertureFNumber',
          'exif_example' => 'f/20.0',
          'img_field' => 'field_aperture_f_number',
        ),
        12 => array(
          'exif_field' => 'EXIF:COMPUTED:UserComment',
          'exif_example' => '',
          'img_field' => 'none',
        ),
        13 => array(
          'exif_field' => 'EXIF:COMPUTED:UserCommentEncoding',
          'exif_example' => 'UNDEFINED',
          'img_field' => 'none',
        ),
        14 => array(
          'exif_field' => 'EXIF:COMPUTED:Thumbnail.FileType',
          'exif_example' => 2,
          'img_field' => 'none',
        ),
        15 => array(
          'exif_field' => 'EXIF:COMPUTED:Thumbnail.MimeType',
          'exif_example' => 'image/jpeg',
          'img_field' => 'none',
        ),
        16 => array(
          'exif_field' => 'EXIF:IFD0:ImageWidth',
          'exif_example' => 3000,
          'img_field' => 'field_image_width',
        ),
        17 => array(
          'exif_field' => 'EXIF:IFD0:ImageLength',
          'exif_example' => 3000,
          'img_field' => 'field_image_length',
        ),
        18 => array(
          'exif_field' => 'EXIF:IFD0:BitsPerSample',
          'exif_example' => '8, 8, 8, 8',
          'img_field' => 'none',
        ),
        19 => array(
          'exif_field' => 'EXIF:IFD0:Compression',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        20 => array(
          'exif_field' => 'EXIF:IFD0:PhotometricInterpretation',
          'exif_example' => 5,
          'img_field' => 'none',
        ),
        21 => array(
          'exif_field' => 'EXIF:IFD0:ImageDescription',
          'exif_example' => 'SONY DSC',
          'img_field' => 'none',
        ),
        22 => array(
          'exif_field' => 'EXIF:IFD0:Make',
          'exif_example' => 'SONY ',
          'img_field' => 'field_make',
        ),
        23 => array(
          'exif_field' => 'EXIF:IFD0:Model',
          'exif_example' => 'DSLR-A900',
          'img_field' => 'field_model',
        ),
        24 => array(
          'exif_field' => 'EXIF:IFD0:Orientation',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        25 => array(
          'exif_field' => 'EXIF:IFD0:SamplesPerPixel',
          'exif_example' => 4,
          'img_field' => 'none',
        ),
        26 => array(
          'exif_field' => 'EXIF:IFD0:XResolution',
          'exif_example' => '3000000/10000',
          'img_field' => 'none',
        ),
        27 => array(
          'exif_field' => 'EXIF:IFD0:YResolution',
          'exif_example' => '3000000/10000',
          'img_field' => 'none',
        ),
        28 => array(
          'exif_field' => 'EXIF:IFD0:PlanarConfiguration',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        29 => array(
          'exif_field' => 'EXIF:IFD0:ResolutionUnit',
          'exif_example' => 2,
          'img_field' => 'none',
        ),
        30 => array(
          'exif_field' => 'EXIF:IFD0:Software',
          'exif_example' => 'Adobe Photoshop CS6 (Macintosh)',
          'img_field' => 'none',
        ),
        31 => array(
          'exif_field' => 'EXIF:IFD0:DateTime',
          'exif_example' => '2013:07:18 09:30:35',
          'img_field' => 'field_date_time',
        ),
        32 => array(
          'exif_field' => 'EXIF:IFD0:Exif_IFD_Pointer',
          'exif_example' => 320,
          'img_field' => 'none',
        ),
        33 => array(
          'exif_field' => 'EXIF:THUMBNAIL:Compression',
          'exif_example' => 6,
          'img_field' => 'none',
        ),
        34 => array(
          'exif_field' => 'EXIF:THUMBNAIL:XResolution',
          'exif_example' => '72/1',
          'img_field' => 'field_thumbnail_x_resolution',
        ),
        35 => array(
          'exif_field' => 'EXIF:THUMBNAIL:YResolution',
          'exif_example' => '72/1',
          'img_field' => 'field_thumbnail_y_resolution',
        ),
        36 => array(
          'exif_field' => 'EXIF:THUMBNAIL:ResolutionUnit',
          'exif_example' => 2,
          'img_field' => 'field_thumbnail_resolution_unit',
        ),
        37 => array(
          'exif_field' => 'EXIF:THUMBNAIL:JPEGInterchangeFormat',
          'exif_example' => 994,
          'img_field' => 'field_thumbnail_jpeg_interchange',
        ),
        38 => array(
          'exif_field' => 'EXIF:THUMBNAIL:JPEGInterchangeFormatLength',
          'exif_example' => 3120,
          'img_field' => 'field_thumbnail_interchange_len',
        ),
        39 => array(
          'exif_field' => 'EXIF:EXIF:ExposureTime',
          'exif_example' => '1/125',
          'img_field' => 'field_exposure_time',
        ),
        40 => array(
          'exif_field' => 'EXIF:EXIF:FNumber',
          'exif_example' => '200/10',
          'img_field' => 'field_f_number',
        ),
        41 => array(
          'exif_field' => 'EXIF:EXIF:ExposureProgram',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        42 => array(
          'exif_field' => 'EXIF:EXIF:ISOSpeedRatings',
          'exif_example' => 100,
          'img_field' => 'none',
        ),
        43 => array(
          'exif_field' => 'EXIF:EXIF:ExifVersion',
          'exif_example' => '0221',
          'img_field' => 'none',
        ),
        44 => array(
          'exif_field' => 'EXIF:EXIF:DateTimeOriginal',
          'exif_example' => '2013:06:13 05:32:56',
          'img_field' => 'field_date_time_original',
        ),
        45 => array(
          'exif_field' => 'EXIF:EXIF:DateTimeDigitized',
          'exif_example' => '2013:06:13 05:32:56',
          'img_field' => 'none',
        ),
        46 => array(
          'exif_field' => 'EXIF:EXIF:ComponentsConfiguration',
          'exif_example' => '' . "\0" . '',
          'img_field' => 'none',
        ),
        47 => array(
          'exif_field' => 'EXIF:EXIF:CompressedBitsPerPixel',
          'exif_example' => '8/1',
          'img_field' => 'none',
        ),
        48 => array(
          'exif_field' => 'EXIF:EXIF:ShutterSpeedValue',
          'exif_example' => '6965784/1000000',
          'img_field' => 'none',
        ),
        49 => array(
          'exif_field' => 'EXIF:EXIF:ApertureValue',
          'exif_example' => '8643856/1000000',
          'img_field' => 'none',
        ),
        50 => array(
          'exif_field' => 'EXIF:EXIF:BrightnessValue',
          'exif_example' => '400/100',
          'img_field' => 'none',
        ),
        51 => array(
          'exif_field' => 'EXIF:EXIF:ExposureBiasValue',
          'exif_example' => '0/10',
          'img_field' => 'none',
        ),
        52 => array(
          'exif_field' => 'EXIF:EXIF:MaxApertureValue',
          'exif_example' => '400/100',
          'img_field' => 'none',
        ),
        53 => array(
          'exif_field' => 'EXIF:EXIF:MeteringMode',
          'exif_example' => 5,
          'img_field' => 'none',
        ),
        54 => array(
          'exif_field' => 'EXIF:EXIF:LightSource',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        55 => array(
          'exif_field' => 'EXIF:EXIF:Flash',
          'exif_example' => 16,
          'img_field' => 'none',
        ),
        56 => array(
          'exif_field' => 'EXIF:EXIF:FocalLength',
          'exif_example' => '450/10',
          'img_field' => 'field_focal_length',
        ),
        57 => array(
          'exif_field' => 'EXIF:EXIF:UserComment',
          'exif_example' => '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '' . "\0" . '',
          'img_field' => 'none',
        ),
        58 => array(
          'exif_field' => 'EXIF:EXIF:FlashPixVersion',
          'exif_example' => '0100',
          'img_field' => 'none',
        ),
        59 => array(
          'exif_field' => 'EXIF:EXIF:ColorSpace',
          'exif_example' => 65535,
          'img_field' => 'none',
        ),
        60 => array(
          'exif_field' => 'EXIF:EXIF:ExifImageWidth',
          'exif_example' => 1600,
          'img_field' => 'none',
        ),
        61 => array(
          'exif_field' => 'EXIF:EXIF:ExifImageLength',
          'exif_example' => 1600,
          'img_field' => 'none',
        ),
        62 => array(
          'exif_field' => 'EXIF:EXIF:FileSource',
          'exif_example' => '',
          'img_field' => 'none',
        ),
        63 => array(
          'exif_field' => 'EXIF:EXIF:SceneType',
          'exif_example' => '',
          'img_field' => 'none',
        ),
        64 => array(
          'exif_field' => 'EXIF:EXIF:CustomRendered',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        65 => array(
          'exif_field' => 'EXIF:EXIF:ExposureMode',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        66 => array(
          'exif_field' => 'EXIF:EXIF:WhiteBalance',
          'exif_example' => 1,
          'img_field' => 'none',
        ),
        67 => array(
          'exif_field' => 'EXIF:EXIF:FocalLengthIn35mmFilm',
          'exif_example' => 45,
          'img_field' => 'none',
        ),
        68 => array(
          'exif_field' => 'EXIF:EXIF:SceneCaptureType',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        69 => array(
          'exif_field' => 'EXIF:EXIF:Contrast',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        70 => array(
          'exif_field' => 'EXIF:EXIF:Saturation',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        71 => array(
          'exif_field' => 'EXIF:EXIF:Sharpness',
          'exif_example' => 0,
          'img_field' => 'none',
        ),
        72 => array(
          'exif_field' => 'XMP:xmpmeta:rdf:description:description:alt:li',
          'exif_example' => 'SONY DSC',
          'img_field' => 'none',
        ),
        73 => array(
          'exif_field' => 'IPTC:1#090',
          'exif_example' => '%G, %G, %G, %G',
          'img_field' => 'none',
        ),
        74 => array(
          'exif_field' => 'IPTC:2#000',
          'exif_example' => '' . "\0" . '',
          'img_field' => 'none',
        ),
        75 => array(
          'exif_field' => 'IPTC:2#120',
          'exif_example' => 'SONY DSC',
          'img_field' => 'none',
        ),
        76 => array(
          'exif_field' => 'IPTC:2#055',
          'exif_example' => 20130613,
          'img_field' => 'none',
        ),
        77 => array(
          'exif_field' => 'IPTC:2#060',
          'exif_example' => '000000+0000',
          'img_field' => 'none',
        ),
      ),
    ),
  );
  return $items;
}
