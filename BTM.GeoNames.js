var BTM = BTM || {}

BTM.GeoNames = {
  get_provinces_path: 'btm_geonames/get_states_provinces',
  showProvincesSelect: function(selector, context, states_provinces){
    var select = $(selector, context);
    var options = select.attr('options');

    $('option', select).remove();

    $.each(states_provinces, function(val, text) {
      options[options.length] = new Option(text, val);
    });
  },

  bindCountryProvinceSelectSet: function(context, country_select, province_select) {
   //console.log(country_select, context);
   if(!country_select) {
      country_select = '#edit-country';
    }

    if(!province_select) {
      province_select = '#edit-state_province';
    }

    $(country_select, context).change(
      function(){
        var country_id = $(this).val();

        var url = Drupal.settings.basePath + BTM.GeoNames.get_provinces_path + '/' + country_id;
        $.ajax({
          'url': url,
          'dataType': 'json',
          'type':'GET',
          'success': function(response){
            BTM.GeoNames.showProvincesSelect(province_select, context, response.states_provinces);
          },
          'error': function(response){

          }
        });
      });
  }
  
}


