#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// Defining BYTE and blocksize
typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // The CLAs must be 2
    if (argc != 2)
    {
        printf("Incorrect usage!\n");
        return 1;
    }
    // If file cannot be opened exit
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("The file cannot be opened!\n");
        return 1;
    }
    // Defining variables for the program
    int fnum = 0;
    BYTE *buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    char filename[8];
    FILE *outptr = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // If it's a new image open a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] < 0xf0 && buffer[3] > 0xdf)
        {
            if (fnum != 0)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03i.jpg", fnum);
            outptr = fopen(filename, "w");
            fnum++;
        }
        // If a file is opened, write
        if (fnum > 0)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
    // Close to get memories back
    fclose(outptr);
    free(buffer);
    fclose(file);
}