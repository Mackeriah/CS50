#include <cs50.h>
#include <stdio.h>
#include <string.h>

int searchForNumber();
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int userEnteredValue;

int main(void)
{
    userEnteredValue = get_int("Please enter a number from 1 to 20: ");

    searchForNumber();
}

int searchForNumber()
{
    int count = 0;
    for (int i = 0; i < 20; i++ )
    {
        if (numbers[i] == userEnteredValue)
        {
            count += 1;
            printf("It took me %i steps to find your number.\n", count);
            return 0;
        }
        else
        {
            count += 1;
        }
    }
    printf("Seriously? %i isn't a number from 1 to 20 you idiot!\n", userEnteredValue);
    return 1;
}