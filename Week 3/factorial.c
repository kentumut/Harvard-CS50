#include <cs50.h>
#include <stdio.h>

int factorial(int input);

int main(void)
{
    int input = get_int("Please enter a number that you convert to a factorial\n");
    printf("The result is: %i\n", factorial(input));
}

int factorial(int input)
{
    if (input == 0)
    {
        return 1;
    }
    return input * factorial(input - 1);
}