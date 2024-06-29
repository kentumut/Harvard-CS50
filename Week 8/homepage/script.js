$(document).ready(function() {
    $('.buttons').click(function() {
        var color = $(this).css('background-color')
        $(".navbar.bg-body-tertiary").css('background-color', color);
     } )})