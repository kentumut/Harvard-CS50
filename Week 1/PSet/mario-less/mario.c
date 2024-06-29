#include <cs50.h>
#include <stdio.h>

void dash(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    dash(height);
}

void dash(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int f = 0; f < height - i; f++)
        {
            printf(" ");
        }
        for (int d = 0; d < i; d++)
        {
            printf("#");
        }
        printf("\n");
    }
}
