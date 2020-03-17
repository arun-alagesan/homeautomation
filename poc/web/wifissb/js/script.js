


$(document).ready(function(){

    $(".switch").on("click", function(){
        var item = $(this).find("input[type=checkbox]");
       item.prop("checked",!item.prop("checked"));
    });

});