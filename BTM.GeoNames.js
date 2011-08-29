Drupal.behaviors.bindCountryProvinceSelect = function(context) {
  if($("#edit-country-province-wrapper", context).length) {
    BTM.GeoNames.bindCountryProvinceSelectSet(context);
  }
}

var BTM = BTM || {}

BTM.GeoNames = {
  get_provinces_path: 'btm_geonames/get_states_provinces',
  showProvincesSelect: function(selector, context, states_provinces, default_selected){
    var default_selected = default_selected || '';
    var select = $(selector, context);
    var options = select.attr('options');

    $('option', select).remove();


//    var names = new Array();
//
//    $.each(states_provinces, function(val, text) {
//      names.push(text);
//    });
//
//    names.sort();
//
//    PRC.console.log(names);

    $.each(states_provinces, function(val, text) {
      options[options.length] = new Option(val, text);
    });

    $(select).val(default_selected);
  },

  bindCountryProvinceSelectSet: function(context, country_select, province_select, default_province) {
   //console.log(country_select, context);
   if(!country_select) {
      country_select = '#edit-country-province-country';
    }

    if(!province_select) {
      province_select = '#edit-country-province-state-province';
    }

  $(country_select, context).change(
      function(){
        var country_id = $(this).val();

        var url = Drupal.settings.basePath + BTM.GeoNames.get_provinces_path + '/' + country_id + '/0/TRUE';
        $.ajax({
          'url': url,
          'dataType': 'json',
          'type':'GET',
          'success': function(response){
            BTM.GeoNames.showProvincesSelect(province_select, context, response.states_provinces, default_province);
          },
          'error': function(response){

          }
        });
      });
  }
  
}


