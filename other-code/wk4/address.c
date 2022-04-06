#include <stdio.h>
#include <string.h>
//#include <cs50.h>

int main(void)
{
    int n = 50;
    // & gets the memory address for the variable n
    printf("%p\n", &n);

    // * goes to the memory address for n and & displays the value for n
    printf("%i\n", *&n);

    // this stores the memory address of variable n in the new variable n3 (which is of datatype int*)
    // the & is why the memory address is stored in n3
    // the * simply means you're declaring the variable as a pointer
    // the * is DIFFERENT from the other uses of * here (David mentions a few time this is confusing)
    int *n3 = &n;

    // so the below prints the memory address of n befcause n3 is pointing at that address
    printf("%p\n", n3);

    // adding * means GO TO the address that n3 is pointing at (n) and return the address contents
    printf("%i\n", *n3);

    printf("\n");

    char *s = "HI!";
    printf("%p = Pointer to first byte of memory address\n", s);
    printf("%p = First char: H\n", &s[0]);  // H
    printf("%p = Second char: I\n", &s[1]);  // I
    printf("%p = Third char: !\n", &s[2]);  // !
    printf("%p = Fourth char: /0\n", &s[3]);  // /0

    printf("\n");

    // alternatively we can use *s with pointer arithmetic
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));

}
