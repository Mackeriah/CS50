
// when the DOM is fully loaded (ready) the page will execut the first anonymous function (line 4)
// that function looks for something being of class jQButton (the . preceding means class)
// and when any of those buttons are clicked, it runs the second anonymous function
// this second function sets the background colour to the innerHTML text between the ><
// but first converts it to lowercase

$(document).ready(function() {
    $('.jQButton').click(function() {
        $('#colorDiv').css('background-color', this.innerHTML.toLowerCase());
    });
}); 