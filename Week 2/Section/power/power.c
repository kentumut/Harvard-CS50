#include <stdio.h>
#include <cs50.h>

void power(int arraysize);

int main(void)
{
    int arraysize;
    do
    {
        arraysize = get_int("The Array Size: ");
    }
    while (arraysize < 1);

    power(arraysize);
}

void power(int arraysize)
{
    int power[arraysize];
    int powers = 1;
    for (int i = 0; i < arraysize; i++)
    {
        power[i] = powers;
        powers *= 2;
        printf("%i\n", power[i]);
    }
}