// CS50 Recover 2021 Owen FitzGerald

// Add header files
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// create BYTE filetype
typedef uint8_t BYTE;

// declare global variables
FILE *input;  // create pointer of type FILE using the name 'input'
FILE *output;
BYTE blockSize[512];
char filename[99];
bool openFileFLAG = false;
int counter = -1;

// declare prototypes
void findJPEG();


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover <file>.raw\n");
        return 1;
    }

    // Open input file in read mode
    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file '%s'.\n", argv[1]);
        return 1;
    }

    findJPEG();
}


void findJPEG()
{
    // read 512 blocks from input file until end of file
    while (fread(&blockSize, sizeof(BYTE), 512, input))
    {
        // check whether this fread was beyond end of file or an error was returned
        if (!feof(input) || (!ferror(input)))
        {
            // do first 4 bytes of 512 block indicate a JPEG?
            if ((blockSize[0] == 0xff) && (blockSize[1] == 0xd8) && (blockSize[2] == 0xff) && ((blockSize[3] >= 0xe0) && (blockSize[3] <= 0xef)))
            {
                // this is only set true after we find the first JPEG
                if (openFileFLAG == true)
                {
                    // close currently open file
                    fclose(output);
                }

                // set to true when we find the FIRST JPEG
                if (openFileFLAG == false)
                {
                    openFileFLAG = true;
                }

                counter += 1;  // used to increment filename
                sprintf(filename, "%03i.jpg", counter);  // generate new filename
                output = fopen(filename, "w");  // create/overwrite file

                // quit if file is null
                if (output == NULL)
                {
                    exit(0);
                }

                // write 512 bytes to the current output file
                fwrite(&blockSize, sizeof(BYTE), 512, output);
            }
            // if current 512 block didn't contain a JPEG 'header', we must still be inside a JPEG so just write the block to the open file
            else
            {
                // this is to ensure we only do this IF we have a file open
                // it also means that we don't write any BEFORE we find the very first JPEG (which there is)
                if (openFileFLAG == true)
                {
                    // write 4 bytes to the output file
                    fwrite(&blockSize, sizeof(BYTE), 512, output);
                }
            }
        }
    }

    // close files when end of input file reached
    fclose(input);
    fclose(output);
}