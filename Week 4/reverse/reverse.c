#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Inproper usage!\n");
        return 1;
    }
    // Can the input file can be opened
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Input file cannot be opened!\n");
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, 44, 1, inptr);

    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf("Invalid WAV format!\n");
        return 1;
    }

    // Open output file for writing
    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        printf("Output file cannot be opened!\n");
        return 1;
    }

    // Write header to file
    fwrite(&header, 44, 1, outptr);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    BYTE buffer[block_size];
    fseek(inptr, 0, SEEK_END);
    long audio_size = ftell(inptr) - sizeof(WAVHEADER);
    int blocks = audio_size / block_size;
    fseek(inptr, block_size, SEEK_END);
    for (int i = 0; i < blocks ; i++)
    {
        fseek(inptr,  -2 * block_size, SEEK_CUR);
        fread(buffer, block_size, 1, inptr);
        fwrite(buffer, block_size, 1, outptr);
    }
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int size = (header.bitsPerSample / 8) * header.numChannels;
    return size;
}