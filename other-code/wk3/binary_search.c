// Binary Search alogorithm

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int binarySearch();
int numbers[] = {6, 7, 8, 9, 10, 11, 14, 15, 17, 19, 22, 23, 25, 28, 30};
int userEnteredValue;

int main(void)
{
    userEnteredValue = get_int("Please enter a number to search for: ");
    binarySearch();
}

int binarySearch()
{

    int start = 0;
    int end = 14;
    int count = 0;
    int middle;

// Hang on is this not working because I'm using the values instead of the elements?
    for (int i = 0; i < 14; i++)
    {
        count += 1;
        printf("Count: %i \n", count);

        middle = (start + end) / 2;
        printf("middle = %i\n", numbers[middle]);

        if (numbers[middle] == userEnteredValue)
        {
            printf("That's numberwang!\n");
            return 0;
        }
        // above this line works AFAIK

        else if (userEnteredValue < numbers[middle])
        {
            end = middle -= 1;
        }
        else if (userEnteredValue > numbers[middle])
        {
            start = middle += 1;
        }

        if ((start > end) || (end < start))
        {
            printf("End of array reached!\n");
            return 1;
        }
    }
    return 0;
}