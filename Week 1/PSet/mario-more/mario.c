#include <cs50.h>
#include <stdio.h>

// Dash Function Prototype
void dash(int height);

int main(void)
{
    // Ask for user input between 1 to 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Function begins
    dash(height);
}

void dash(int height)
{
    //Do this for every line
    for (int i = 1; i <= height; i++)
    {
        //Make space line - level times
        for (int f = 0; f < height - i; f++)
        {
            printf(" ");
        }
        // Print level times hashes
        for (int d = 0; d < i; d++)
        {
            printf("#");
        }
        // Make a space in the middle
        printf("  ");
        // Print the last hashes to right
        for (int d = 0; d < i; d++)
        {
            printf("#");
        }
        // Go to a new line
        printf("\n");
    }
}
