#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

// it's important to note here that arrayLength and array are just the names of the inputs, so we can call them anything
// so the below code isn't doing anything until it's called, at which point we PROVIDE the two ints the function will use
// e.g. average(TOTAL, scores)

float average();

int main(void)
{
    //int total = get_int("Enter total number of scores: ");
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Enter score %i: ", i + 1);
    }

    printf("Average: %f\n", average(TOTAL, scores));

}

float average(int arrayLength, int array[])
{
    int sum = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        sum += array[i];
    }
    return sum / (float) arrayLength;  // this is casting the result to a float datatype
}
