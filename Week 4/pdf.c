#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Unproper usage.\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(argv[1], "r");

    // Checks if file exists
    if (file == NULL)
    {
        printf("NO SUCH FILE FOUND.\n");
        return 1;
    }

    // Stores the first 4 bytes in buffer
    uint8_t buffer[4];
    fread(buffer, 1, 4, file);
    fclose(file);

    // Signatures for pdf and jpeg
    uint8_t pdf[] = {37, 80, 68, 70};
    uint8_t jpeg[] = {255, 216, 255, 224};

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != pdf[i])
        {
            printf("This is not a pdf.\n");
            break;
        }
        if (i == 3)
        {
            printf("This is a pdf.\n");
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != jpeg[i])
        {
            printf("This is not a jpeg.\n");
            break;
        }
        if (i == 3)
        {
            printf("This is a jpeg.\n");
        }
    }
}