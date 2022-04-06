#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float side1, float side2, float side3);

int main(void)
{
    float side1 = get_float("Please enter length of side 1: ");
    float side2 = get_float("Please enter length of side 2: ");
    float side3 = get_float("Please enter length of side 3: ");

    bool z = valid_triangle(side1, side2, side3);

    if (z == false)
    {
        printf("False \n");
    }
    else
    {
        printf("True \n");
    }
}


bool valid_triangle(float side1, float side2, float side3)
{
    if (side1 <= 0 || side2 <= 0 || side3 <= 0)
    {
        return false;
    }
    if (side2 + side3 <= side1 || side1 + side3 <= side2 || side1 + side2 <= side3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

