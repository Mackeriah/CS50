#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Please enter a number: ");

    if (n % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
}



