
function toggleAllSwitch()
{
    $("input[type=checkbox]").click();
}

$(document).ready(function(){

    $(".switch").on("click", function(){
       var targetSourceType = event.target.type;
       if (targetSourceType != 'checkbox'){
        var item = $(this).find("input[type=checkbox]");
        item.prop("checked",!item.prop("checked"));
       }
       var control = $(this).find(".control-switch");
       control.toggleClass('on');
       
    });

});