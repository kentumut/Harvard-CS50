#include <cs50.h>
#include <stdio.h>
#include <string.h>


void print_bulb(int bit);

int main(void)
{
    // Gets user input
    string message = get_string("Message: ");
    // Magic Number length
    int length = strlen(message);
    // Creating the bin array and digitvalue
    char bin[length][8];
    int digitvalue;
    // Iterating through the string
    for (int i = 0; i < length; i++)
    {
        digitvalue = 0;
        // Converting to decimal
        while (message[i] > 1)
        {
            if (message[i] % 2 != 0)
            {
                bin[i][digitvalue] = '1';
            }
            else
            {
                bin[i][digitvalue] = '0';
            }
            message[i] /= 2;
            digitvalue++;
        }
        if (message[i] == 1)
        {
            bin[i][digitvalue] = '1';
            digitvalue++;
        }
        // Filling the rest of the bits
        for (int b = 0; b <= 8 - digitvalue; b++)
        {
            bin[i][digitvalue] = '0';
            digitvalue++;
        }
    }
    // Printing the bulbs from left to right
    for (int s = 0; s < length; s++)
    {
        for (int d = 7; d >= 0; d--)
        {
            print_bulb(bin[s][d]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == '0')
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == '1')
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}