#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    int *y = 0;

    x = malloc(sizeof(int));

    *x = 42;
    printf("x = %i\n", *x);

    y = x;
    printf("y = %i\n", *y);
}



