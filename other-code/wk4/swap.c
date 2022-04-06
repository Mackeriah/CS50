// by running this through debug50 you can actually see this working

#include <stdio.h>

void print_xy(int x, int y);
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    print_xy(x, y);

    // provide function arguments using memory address of x and y
    swap(&x, &y);

    print_xy(x, y);
}

// the function is declaring these as pointers using the *
void swap(int *a, int *b)
{
    // the * here is going to the memory address to get the actual value
    // if I instead used &a then it would store the memory address in tmp
    int tmp = *a;
    // now we go to a and assign the value from what is at b
    *a = *b;
    // now we go to b and assign the value from what is at tmp
    // we don't need any special operators for tmp as it's just storing the value from *a (which is 1)
    *b = tmp;
}

void print_xy(int x, int y)
{
    printf("x is %i, y is %i\n", x, y);
}

