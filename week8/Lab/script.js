// when the whole DOM is loaded (so everything on the page) then and only then, run the above listen function
document.addEventListener('DOMContentLoaded', function() {

    // when correct answer is clicked, change colour to green and display correct
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function() {
        correct.style.backgroundColor = 'green';
        document.querySelector('#feedback1').innerHTML = 'Correct!';
    });

    // when any incorrect answer is clicked, change colour to red and display incorrect
    let incorrects = document.querySelectorAll('.incorrect');
    // this loop ensures that any number of 'incorrect' buttons are monitored
    for (let i = 0; i < incorrects.length; i++) {
        incorrects[i].addEventListener('click', function() {
            incorrects[i].style.backgroundColor = 'red';
            document.querySelector('#feedback1').innerHTML = 'Incorrect';
        });
    }

     // Check free response submission
     document.querySelector('#check').addEventListener('click', function() {
        let input = document.querySelector('input');   
        let input2 = input.value;
        let input3 = input2.toLowerCase();
        // console.log(input.value);
        // console.log(input2);
        // console.log(input3);
        if (input3 === 'blue') {
            input.style.backgroundColor = 'green';
            document.querySelector('#feedback2').innerHTML = 'Correct!';
        } else {
            input.style.backgroundColor = 'red';
            document.querySelector('#feedback2').innerHTML = 'Incorrect';
        }
    });

});