// Selection sort alogorithm

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int numbers[] = {1, 2, 4, 18, 2, 6, 10, 3};
int selection_sort();
int arrayLength;

int main(void)
{
    arrayLength = sizeof(numbers)/sizeof(numbers[0]);

    // print the original array
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    selection_sort();
}

int selection_sort()
{
    // this is where I'll store the array index of the smallest value
    int arrayIndices = 0;

    for (int i = 0; i < (arrayLength - 1); i++)
    {
        int smallestValue = numbers[i];  // may as well start somewhere!
        arrayIndices = i; // store the current array index

        for (int j = i; j < (arrayLength - 1); j++)
        {
            // check if current smallest value is actually larger
            if (smallestValue > numbers[j+1])
            {
                // in which case make that the new smallest value and store it's array index
                smallestValue = numbers[j+1];
                arrayIndices = j+1;
            }
        }
        // number swapping code
        int temp = numbers[i];
        numbers[i] = numbers[arrayIndices];
        numbers[arrayIndices] = temp;
    }
    // print the sorted array
    for (int k = 0; k < arrayLength; k++)
    {
        printf("%i ", numbers[k]);
    }
    printf("\n");

    return 0;
}