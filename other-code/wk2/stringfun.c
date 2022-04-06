#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Enter input: ");
    printf("Output: ");

    int enteredString = strlen(s);
    for (int i = 0; i < enteredString; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

}
