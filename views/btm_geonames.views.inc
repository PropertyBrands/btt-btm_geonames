<?php

function btm_geonames_views_handlers() {
  return array(
    'info' => array(
      'path' => BTM_GEONAMES_PATH_TO_MODULE . '/views'
    ),
    'handlers' => array(
      'views_handler_field_province' => array(
        'parent' => 'views_handler_field'
      ),
      'views_handler_field_country' => array(
        'parent' => 'views_handler_field'
      ),
    )
  );

}

function btm_geonames_views_data() {
  $t = array();

  $t['btm_states_provinces']['table']['group'] = t('GeoNames States/Provinces');
  $t['btm_states_provinces']['table']['base'] = array(
    'field' => 'state_province_id',
    'title' => t('GeoNames States/Provinces'),
    'help' => t('help!'),
  );

  $t['btm_states_provinces']['state_province_name'] = array(
    'title' => t('State/province name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string'
    )
  );

  $t['btm_countries']['table']['group'] = t('GeoNames Countries');
  $t['btm_countries']['table']['base'] = array(
    'field' => 'geoname_id',
    'title' => t('GeoNames Countries'),
    'help' => t('Help!')
  );

  $t['btm_countries']['country_name'] = array(
    'title' => t('Country Name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string'
    )
  );

  $t['btm_countries']['country_code'] = array(
    'title' => t('Country Code'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click_sortable' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string'
    )
  );

  return $t;
}