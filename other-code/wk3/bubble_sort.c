// Bubble sort alogorithm

#include <stdio.h>
#include <math.h>
//#include <cs50.h>
//#include <string.h>

int numbers[] = {500, 2, 10, 80, 2, 4, 99, 7, 50, 51, 52, 43, 44, 45};
int bubble_sort2();
void printArray();
int arrayLength;
int temp;

int main(void)
{
    arrayLength = sizeof(numbers)/sizeof(numbers[0]);

    // print original array
    printArray();

    //bubble_sort();
    bubble_sort2();

    // print sorted array
    printArray();
}

// the for loops run multiple times, each time two numbers are compared with one another and the highest is swapped to the right
int bubble_sort2()
{
    // why is this -1?
    // because the other for loop checks in the following element, so we do this to ensure we never check outside of our bounds
    for (int i = 0; i < arrayLength-1; i++)
    {
        // why is this -i and -1?
        //  it's minus 1 for the same reason as above, we don't want to look outside of our array's bounds
        //  but it's also minus i because each time through the 2nd for loop the largest
        //  number will be at the end, so we don't want to check it again
        for (int j = 0; j < arrayLength-i-1; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    return 0;
}

void printArray()
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}