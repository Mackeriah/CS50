#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // this is essentially using malloc to create an array
    int *list = malloc(3 * (sizeof(int)));
    if (list == NULL)
    {
        return 1;
    }

    // as malloc returns a CONTIGUOUS (in a sequence) block of memory you can access it using []
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;


    // now for whatever reason we want to change the size of our list 'array' to 4
    // perhaps we now need to store another piece of user information
    // so we create a new temp int array of size 4
    int *tmp  = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        // return the memory before the program quits
        free(list);
        return 1;
    }

    // we now use a for loop to copy the existing (3) data from list into the tmp array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] =  list[i];
    }

    // assign the new value to the new array
    tmp[3] = 4;

    /*  at this point we have both the original list array and the new tmp array
        the list array contains 1,2,3
        the tmp array contains 1,2,3,4
    */

    // return the memory from the original array
    free(list);

    // this repoints (my term) the pointer to the new memory address (which is used by the tmp array)
    // so now both tmp and list are poiting at the same address
    list = tmp;


    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // as always if we use malloc, we have to return the memory
    // we don't need to free tmp also, because list and tmp are pointing at the same address, so free using either list or tmp returns the memory
    free(list);


}