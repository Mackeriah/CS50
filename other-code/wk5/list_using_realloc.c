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

    // in this version we use realloc instead, which takes the address of already allocated memory and the new memory size you want
    int *tmp  = realloc(list, 4 * sizeof(int));

    if (tmp == NULL)
    {
        // return the memory before the program quits
        free(list);
        return 1;
    }

    // we no longer need this bit as realloc copies the old memory into the new memory
    /*
    for (int i = 0; i < 3; i++)
    {
        tmp[i] =  list[i];
    }
    */

    // assign the new value to the new array
    tmp[3] = 4;

    // David never said to remove this but it didn't work correctly with it, so I commented it out
    // free(list);


    // this repoints (my term) the pointer to the new memory address (which is used by the tmp array)
    // so now both tmp and list are poiting at the same address
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // we don't need to free tmp also, because list and tmp are pointing at the same address, so free using either list or tmp returns the memory
    free(list);

}