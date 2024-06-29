#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
// Function prototype

int main(void)
{
    string input = get_string("Enter a positive integer: ");
    // Gets string input from the user

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    // Checks whether the input a number

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case
    if (strlen(input) == 1)
    {
        return input[0] - 48;
    }
    int digit = input[strlen(input) - 1] - 48;
    // String is converted to a digit
    input[strlen(input) - 1] = input[strlen(input)];
    // Last digit is erased
    return 10 * convert(input) + digit;
    // Where the fun happens
}