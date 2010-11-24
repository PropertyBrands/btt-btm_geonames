<?php
/**
 * Description of views_handler_field_country
 *
 * @author btm
 */
class views_handler_field_country extends views_handler_field{
    public function render($values){
      //You need to change this to reflect your country id field
      $output = btm_geonames_get_country($values->country);

      return $output;
    }
}