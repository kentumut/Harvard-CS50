#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// checking if the cla is a digit
bool only_digits(string key);

int main(int argc, string argv[])
{
    // only one comand line argument is okay and it should be a digit
    if (argc != 2 || only_digits(argv[1]) == 0)
    {
        // print out the usage
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // the key can't be negative
    else if (atoi(argv[1]) < 0)
    {
        // print out the usage
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // gettig the plaintext
    string ptext = get_string("plaintext:  ");
    // finding the lenght
    int length = strlen(ptext);
    // allocating the same memory to ctext so that it doesn't give a segmentation fault
    string ctext = ptext;
    // convert the string to an int
    int key = atoi(argv[1]);
    // looping through letters
    for (int i = 0; i < length; i++)
    {
        // just convert alphabeticals
        if (isalpha(ptext[i]))
        {
            // conversion for lower cases
            if (islower(ptext[i]))
            {
                ctext[i] = (ptext[i] - 96 + key) % 26 + 96;
            }
            // conversion for upper cases
            else
            {
                ctext[i] = (ptext[i] - 64 + atoi(argv[1])) % 26 + 64;
            }

        }
        else
        {
            ctext[i] = ptext[i];
        }
    }
    // print out the result
    printf("ciphertext: %s", ctext);
    printf("\n");
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (47 > key[i] || key[i] > 58)
        {
            return false;
        }
    }
    return true;
}