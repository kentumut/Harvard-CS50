#include <cs50.h>
#include <stdio.h>

int collatz (int input);

int main (void)
{
    int number;
    do
    {
        number = get_int("Please type a positive integer that you want to enter into collatz conjecture\n");
    }
    while (number < 0);

    printf("Your result is %i\n", collatz(number));
}

int collatz (int input)
{
    if (input == 1)
    {
        return 0;
    }
    else if ((input % 2) == 0)
    {
        return 1 + collatz(input / 2);
    }
    else
    {
        return 1 + collatz(input * 3 + 1);
    }
}