// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    typedef uint8_t BYTE;
    BYTE buffer[HEADER_SIZE];
    fread(buffer, sizeof(BYTE), 44, input);
    fwrite(buffer, sizeof(BYTE), 44, output);

    // TODO: Read samples from input file and write updated data to output file

    typedef int16_t byte;
    byte sample;
    while (fread(&sample, sizeof(byte), 1, input))
    {
        sample = sample * factor;
        fwrite(&sample, sizeof(byte), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
