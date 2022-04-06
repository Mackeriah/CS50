// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables
const int HEADER_SIZE = 44; // Number of bytes in .wav header
FILE *input;  // create pointer of type FILE using the name 'input'
FILE *output;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not write output file.\n");
        return 1;
    }

    // convert string to float
    float factor = atof(argv[3]);

    // create uint8_t array to store 44 bytes from header of wav
    uint8_t header[HEADER_SIZE];

    // read size uint8_t, qty 44, from input file and store the 44 bytes in header (uint8_t = 1 byte)
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // create buffer variable for audio samples
    int16_t buffer;
    // read size int16_t, qty 1, from input file and store the 2 bytes in buffer (int16_t = 2 bytes)

    // read 2 byte sample from input file into buffer
    // fread returns how many bytes it read and thus when it reaches the end of the file it will
    // return 0 and the while loop will treat this as false and exit
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // So.  This is the correct way to check for end of file or error
        // Basically you have to check this AFTER you've read the data, not before
        if (!feof(input) || (!ferror(input)))
        {
            // scale sample
            buffer *= factor;

            // write the 2 byte sample from buffer inout output file
            fwrite(&buffer, sizeof(int16_t), 1, output);
        }

    }

    // Close files
    fclose(input);
    fclose(output);
}
