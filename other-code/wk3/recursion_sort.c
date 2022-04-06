// Recursion sort alogorithm

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int collatz();
int fact();
int runAgain();


int main(void)
{
    int n = get_int("Enter an integer for n.\n");
    int steps = collatz(n);  // this will store the return value from the function
    collatz(n);
    printf("Steps: %i\n", steps);

    runAgain();
}

int collatz(int n)
{
    // printf("n: %i\n", n);
    if (n == 1)  // base case
        return 0;
    // steps += 1;
    if (n % 2 == 0) // if even
        return 1 + collatz(n / 2);  // recursive case
    else
        return 1 + collatz(3 * n + 1);  // recursive case if odd
}

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

int runAgain()
{
    char runFact = get_char("Run again? ");

    if (runFact == 'y' || runFact == 'Y')
    {
        main();
        return 0;
    }
    else
        return 1;
}
