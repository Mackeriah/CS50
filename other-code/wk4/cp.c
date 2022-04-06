// Copies a file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// using typedef here simply means we can use BYTE as a reference to the datatype unit8_t
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: copy SOURCE DESTINATION\n");
        return 1;
    }

    // open input file
    FILE *source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
    }

    // open output file
    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL)
    {
        fclose(source);
        printf("Could not open %s.\n", argv[2]);
        return 1;
    }

    // Copy source to destination, one BYTE at a time
    // create a variable called buffer of BYTE datatype (really uint8_t)
    BYTE buffer;

    // read size byte, qty 1, from source file (and store in buffer of size 1 byte)
    while (fread(&buffer, sizeof(BYTE), 1, source))
    {
        fwrite(&buffer, sizeof(BYTE), 1, destination);
    }

    // Close files
    fclose(source);
    fclose(destination);
    return 0;

}