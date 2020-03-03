var wifisurl = 'http://192.168.0.188/';

$(document).ready(function(){
    $('input[type=checkbox]').click(function () {

        var action = wifisurl + $(this).attr('dev') ;
        if ($(this).prop('checked')) {
           // do what you need here
           action += 'on';     
           
           console.debug('Checked :' + action );
        }
        else {
           // do what you need here
           action += 'off';         
           console.debug('Unchecked :' + action );
        }
        $.get( action, function( data ) {
            $("#response").html( data );
          });
      });
});