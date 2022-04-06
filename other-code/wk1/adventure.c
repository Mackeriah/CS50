

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system ("clear");

    int level = get_int("Level 1 or level 2? \n");

    if (level == 1)
    {
        printf("Level %i ", level);
        printf("chosen huh, you want it easy then do you? \n \n");
        string playerName = get_string("Now, tell me your name adventurer? \n");
        printf("Greetings, %s \n \n", playerName);
    }
    else if (level == 2)
    {
        printf("Aha!  You must be a bold adventurer to choose level %i \n \n", level);
        string playerName = get_string("Now, tell me your name brave adventurer? \n");
        printf("Greetings, %s \n \n", playerName);

    }
    else
    {
        system ("clear");

        for (int i = 0; i < 50; i++)
        {
            printf("Hello! \n");
        }

    }

}