#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int fact(int n)
{
    if (n == 1)
    {
        printf ("n: %i\n", n);
        return 1;
    }
    else
    {
        printf ("n: %i\n", n);
        return n * fact(n-1);
    }
}

int main(void)
{
    int n = get_int("Enter an integer for n.\n");
    fact(n);
}