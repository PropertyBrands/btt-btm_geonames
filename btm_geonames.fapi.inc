<?php

/**
 * Tell the FAPI about our elements
 *
 * @return array
 */
function btm_geonames_elements(){
  return array(

    'country_province_select' => array(
        '#input' => TRUE,
        '#process' => array('btm_geonames_fapi_country_province_select_expand'),
        '#element_validate' => array('btm_geonames_fapi_country_province_select_validate'),
    )

  );

}

/**
 * Tell FAPI what our element is made of, ie build the individual elements
 *
 * @param array $element
 * @return array
 */
function btm_geonames_fapi_country_province_select_expand($element){
  if(empty($element['#value'])){
    $element['#value'] = array('country' => '0', 'state_province' => '0');
  }

  if($element['#value']['country'] > 0){
    $provinces = btm_geonames_get_states_provinces($element['#value']['country']);
  }else{
    $provinces = $provinces = array('0' => 'Select a country');
  }

  $element['#tree'] = TRUE;
//  $pre = $element['#id_prefix'];

 $parents = $element['#parents'];

  $parents[] = 'country';
  $element['country'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#options' => btm_geonames_get_countries(),
    '#value' => $element['#value'],
    '#required' => $element['#required'],
  );

  $parents = $element['#parents'];
  $parents[] = 'state_province';

  $element['state_province'] = array(
    '#type' => 'select',
    '#title' => t('State/Province'),
    '#options' => $provinces,
    '#value' => $element['#value'],
    '#required' => $element['#required'],
  );

  return $element;
}

/**
 * This would be used to enforce the 'required' value
 *
 * @param array $element
 */
function btm_geonames_fapi_country_province_select_validate($element){

}

/**
 * This is verbatim from theme_password_confirm. Draw the element. Default is stacked
 * select boxes
 *
 * @param array $element
 * @return string
 */
function theme_country_province_select($element){
  return theme('form_element', $element, $element['#children']);
}
