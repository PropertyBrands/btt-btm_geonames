<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of views_handler_field_province
 *
 * @author btm
 */
class views_handler_field_province extends views_handler_field {
  public function render($values){

    //You need to change this to reflect your actual field name
    $output = btm_geonames_get_province($values->state_province);


    return $output;
  }

}


