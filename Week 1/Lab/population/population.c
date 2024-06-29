#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s_size;
    do
    {
        s_size = get_int("Start size: ");
    }
    while (s_size < 9);


    // TODO: Prompt for end size
    int e_size;
    do
    {
        e_size = get_int("End size: ");
    }
    while (e_size < s_size);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (s_size < e_size)
    {
        s_size = s_size + (s_size / 3) - (s_size / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i \n", years);
}
