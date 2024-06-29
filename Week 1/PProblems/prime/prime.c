#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    //Ask user for minimum input
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);
    //Ask user for maximum input
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);
    //Prints every number that is prime after it's checked by the function
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Prime number checker
    int factors = 0;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            factors++;
            break;
        }
    }
    // If it doesn't have a factor and the number is not 1 it's a prime number
    if (factors == 0 && number != 1)
    {
        return true;
    }
    return false;
}
