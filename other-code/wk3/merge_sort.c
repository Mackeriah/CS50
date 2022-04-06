// Merge sort alogorithm

// if array size is > 1
    // find halfway point in array
    // sort left half of array
    // sort right half of array
    // repeat until an array is of length 1
// merge the two halves together in order of lowest first

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int mergeArray[1] = {0};

//   merge(     array,       start_element,       middle_element,    middle_element + 1,  end_element);
void merge (int array[], int left_start, int left_end, int right_start, int right_end)
// void merge (int array[], int left_start, int left_end, int right_start, int right_end)
{
    // calculate length of sub-array DIRECTLY ABOVE us that we'll be merging back into
    int length = right_end - left_start + 1;

    // this index is used to keep track of the element in mergeArray so we can copy values there
    int index = left_start;

    // While there are UNMERGED elements in both subarrays
    while (left_start <= left_end && right_start <= right_end)
    {
        // Compare first element at the start of each sub array
        printf("Array left_start %i\n", array[left_start]);
        printf("Array right_start %i\n", array[right_start]);

        // if left array element less or equal to right array element
        // this is comparing the left start with right
        if (array[left_start] <= array[right_start])
        {
            // Add element from left array to new 'merged' array
            printf("Array left_start %i\n", array[left_start]);
            mergeArray[index] = array[left_start];
            printf("mergeArray Array %i\n", index);
            index++;
            left_start++;
        }
        // therefore left array element must be LESS than right array element
        else
        {
            // Add element from right array to new 'merged' array
            printf("Array right_start %i\n", array[right_start]);
            mergeArray[index] = array[right_start];
            printf("mergeArray index:%i value:%i\n", index, mergeArray[index]);
            index++;  // increment so next value added to mergeArray goes into next element
            right_start++;  // increment this so we can access next right array element IF one exists
        }
    }

    // the above while loop sends us here if one of the sub-arrays is fully merged
    // these 2 while loops are to determine which of the sub-arrays still has values that need to be merged

    // While elements remain in left array
    while (left_start <= left_end)
    {
        // Merge left element to merge array
        printf("I will be merging the value to mergeArray[%i]\n", index);
        mergeArray[index] = array[left_start];
        printf("mergeArray element %i now has value %i\n", index, mergeArray[index]);
        left_start++;  // increment this so we can access next left array element IF one exists
        index++;  // increment so next value added to mergeArray goes into next element
    }

    // While elements remain in right array
    while (right_start <= right_end)
    {
        // Append_element element to merged array
        mergeArray[index] = array[right_start];
        printf("mergeArray element %i now has value %i\n", index, mergeArray[index]);
        right_start++;
        index++;
    }

    // Copy newly sorted array over to original array
    for (int i = right_end, j = 0; j <= length; i--, j++)
    {
        array[i] = mergeArray[i];
        printf("Merged Array%i is %i\n", i, mergeArray[i]);
    }
}

void sort (int array[], int start_element, int end_element)
{
    // if there's more than 1 element do this (this isn't checking the value)
    // if not then there is only 1 element in either left or right sub-array
    if (end_element > start_element)
    {
        printf ("start_element:%i (value:%i)\n", start_element, array[start_element]);
        int middle_element = (start_element + end_element) / 2;
        printf ("middle_element:%i (value:%i)\n", middle_element, array[middle_element]);
        printf ("end_element:%i (value:%i)\n", end_element, array[end_element]);

        // if middle is element 0 then LEFT array is of size 1 so no need to sort
        if (middle_element == 0)
        {
            printf("left sub-array: %i\n", array[middle_element]);
        }

        else if (middle_element % 2 == 0)
        {
            for (int i = 0; i < middle_element+1; i++)
            {
                printf("array[%i]\n", array[i]);
            }
        }
        else
        {
            for (int i = 0; i < middle_element+1; i++)
            {
                printf("array[%i]\n", array[i]);
            }
        }
        // sort left half
        sort(array, start_element, middle_element);

        // sort right half
        printf("right sub-array: %i\n", array[middle_element+1]);
        sort(array, middle_element + 1, end_element);

        // merge the two halves
        merge(array, start_element, middle_element, middle_element + 1, end_element);
    }
}

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};

    int arrayLength = sizeof(numbers)/sizeof(numbers[0]);

    // print original array
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");

    sort(numbers, 0, arrayLength - 1);

    int arrayLength2 = sizeof(numbers)/sizeof(numbers[0]);
    // print final array
    for (int i = 0; i < arrayLength2; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

// my original attempt
// int numbers[] = {5, 2, 1, 3, 6, 4};
// int arrayLength;
// int leftSide();
// int middle;

// // int main(void)
// // {
// //     arrayLength = sizeof(numbers)/sizeof(numbers[0]);
// //     printf("Original array length: %i\n", arrayLength);
// //     leftSide(numbers);
// // }

// // int leftSide(array)
// // {

// //     for (int i = 0; i < arrayLength; i++)
// //     {
// //         int leftArray[]

// //         if (arrayLength == 1)  // base case
// //             return 0;

// //         else if (arrayLength > 1)
// //         {
// //             // calculate half point of array
// //             middle = (arrayLength / 2);
// //             printf("  middle point: %i\n", middle);

// //             // sort left half of array (assuming n > 1)
// //             int leftArray[middle];  // create new array
// //             for (int i = 0; i < middle; i++)
// //             {
// //                 leftArray[i] = numbers[i];
// //                 printf("  left: %i of leftarray[%i]\n", leftArray[i], middle);
// //             }

// //             arrayLength = sizeof(leftArray)/sizeof(leftArray[0]);
// //             printf("new array length: %i\n", arrayLength);
// //             leftSide(array);
// //         }
// //         return 0;


// //     }
// // }
