<?php
/**
 * @file
 * jad.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jad_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jad_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jad_node_info() {
  $items = array(
    'site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A Just A Drop Site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
