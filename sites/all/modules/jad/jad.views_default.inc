<?php
/**
 * @file
 * jad.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jad_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'kml_download';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'KML Download';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = 'Location - lat';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'centroid',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location_1']['id'] = 'field_location_1';
  $handler->display->display_options['fields']['field_location_1']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location_1']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location_1']['label'] = 'Location - lon';
  $handler->display->display_options['fields']['field_location_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_location_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_location_1']['settings'] = array(
    'data' => 'centroid',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'kml_feed';
  $handler->display->display_options['style_options']['fields']['name'] = 'title';
  $handler->display->display_options['style_options']['fields']['description'] = 'title';
  $handler->display->display_options['style_options']['fields']['longitude'] = 'field_location_1';
  $handler->display->display_options['style_options']['fields']['latitude'] = 'field_location';
  $handler->display->display_options['style_options']['filename'] = 'jad_all_sites';
  $handler->display->display_options['path'] = 'jad_all_sites.kml';
  $export['kml_download'] = $view;

  return $export;
}
