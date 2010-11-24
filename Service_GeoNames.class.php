<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of Service_GeoNames
 *
 * @author bgore
 */
class Service_GeoNames {
    const GEONAMES_URL = "http://ws.geonames.org/";
    protected $endpoints = array(
        'getCountriesData' => array(
            'xml' => 'countryInfo',
            'json' => 'countryInfoJSON',
        ),
        'getStatesProvinces' => array(
            'xml' => 'children?geonameId=',
            'json' => 'childrenJSON?geonameId=',

        )
    );

    public function __construct() {

    }

    public function getCountriesData($format='xml', $params=null) {
        if(!$this->endpoints['getCountriesData'][$format]){
            throw new Exception("Bad format requested.");
        }

        $url = self::GEONAMES_URL . $this->endpoints['getCountriesData'][$format] . "?";



        $curl = curl_init($url);

        curl_setopt($curl, CURLOPT_HEADER, FALSE);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);


        $raw_response = curl_exec($curl);

        $parsed_response = $this->parseResponse($raw_response, $format);

        return $parsed_response;


    }

    public function getStatesProvinces($geonameId, $format='xml', $params=null) {
        if($geonameId < 1){
            throw new Exception("Bad geonameId given.");
        }

        if(!$this->endpoints['getStatesProvinces'][$format]) {
            throw new Exception('Bad format requested.');
        }

        $url = self::GEONAMES_URL . $this->endpoints['getStatesProvinces'][$format] . $geonameId;

        $curl = curl_init($url);

        curl_setopt($curl, CURLOPT_HEADER, FALSE);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);

        $raw_response = curl_exec($curl);

        $parsed_response = $this->parseResponse($raw_response, $format);

        return $parsed_response;



    }

    protected function parseResponse($response, $format) {
        switch($format){
            case "xml":
                $parsed_response = new SimpleXMLElement($response);
                break;

            case "json":
                $parsed_response = json_decode($response);
                break;

            default:
                throw new Exception("Unsupported response format encountered.");
                break;
        }

        return $parsed_response;

    }

}

?>
