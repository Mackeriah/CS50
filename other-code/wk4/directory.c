#include <stdio.h>
#include <dirent.h>
#include <string.h>

char *name = "copy.c";

int main(void)
{
    // Pointer for directory entry
    struct dirent *de;

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    // opendir returns NULL if couldn't open directory
    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 0;
    }

    // for readdir() refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);

        if (strcmp(de->d_name, name) == 0)
        {
            printf("hello\n");
        }
    }


    closedir(dr);
    return 0;
}