#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    // get length of string
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        // convert to uppercase
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}



