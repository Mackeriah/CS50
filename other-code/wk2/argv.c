#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// take integer as one input and an array of strings as another input
//argc = argument count: count how many strings entered
//argv = argument vector (a list) which will store in an array all the strings a user enters after the prompt
// you can of course name these arguments what you like but this is the convention
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int n = strlen(argv[1]);
        for (int i = 0; i < n; i++)
        {
            printf("%c\n", argv[1][i]);
        }
    }

}
