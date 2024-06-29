$(document).ready(function() {
    $('.answer').click(function() {
        if (this.innerHTML == "Python")
        {
            $(this).css('background-color', '#00FF00');
            $('#q1')[0].innerHTML = "Correct!";
        }
        else
        {
            $(this).css('background-color', '#FF0000');
            $('#q1')[0].innerHTML = "Incorrect";
        }
    })
    $('#free-response').click(function() {
        if ($('#submitted').val() == "Kent")
        {
            $('#submitted').css('background-color', '#00FF00');
            $('#q2')[0].innerHTML = "Correct!";
        }
        else
        {
            $('#submitted').css('background-color', '#FF0000');
            $('#q2')[0].innerHTML = "Incorrect";
        }
    })
})