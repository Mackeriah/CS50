#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("\n");


    ///////////////////////////////////////////////


    char *s2 = get_string("s2: ");

    // malloc assigns us memory for the length of t2 (+1 to include the nul character /0)
    char *t2 = malloc(strlen(s2)+1);
    // this is error handling to cater for the unlikely event that the comptuer could not allocate any memory
    // 1 in a million apparently but still best practice (but I bet people don't do it)
    if (t2 == NULL)
    {
        return 1;
    }

    // get string length on the fly here and note the comma it gets int datatype too
    // <= n so that we ensure the /0 is also copied
    // for (int i =0, n = strlen(s2); i <= n; i++)
    // {
    //     t2[i] = s2[i];
    // }

    strcpy(t2, s2);  // this is a function that does the same as the above for loop

    // this is some error handling in case the user doesn't enter anything
    if (strlen(t) > 0)
    {
        t2[0] = toupper(t2[0]);
    }

    printf("s2: %s\n", s2);
    printf("t2: %s\n", t2);

    // this is critical.  this is freeing up memory that you asked malloc to allocate for you
    free(t2);
}

