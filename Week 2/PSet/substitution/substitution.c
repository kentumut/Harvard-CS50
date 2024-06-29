#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // The key should be 26 characters long and only one cla is accepted
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        // print out error message
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // length of the key
    int length = strlen(argv[1]);
    // creating new alphabet
    char newalpha[26];
    // looping through the key
    for (int i = 0; i < length; i++)
    {
        // making every character lowercase
        argv[1][i] = tolower(argv[1][i]);
        // assigning the new alphabet
        newalpha[i] = argv[1][i];
        // check if the charachters are alphabeticals
        if (isalpha(argv[1][i]) == 0)
        {
            printf("You can only use alphabetical characters!");
            return 1;
        }
        // checking if the characters are duplicate
        for (int d = 0; d < length; d++)
        {
            if (argv[1][i] == argv[1][d] && i != d)
            {
                printf("You can't use duplicate letters in your key!");
                return 1;
            }
        }
    }
    // asking for plaintext input
    string ptext = get_string("plaintext:  ");
    // allocating the memory
    string ctext = ptext;
    for (int i = 0; i < strlen(ptext); i++)
    {
        // changing the character if its alphabetical
        if (isalpha(ptext[i]))
        {
            // if its lowercase assigning the corresponding character to it
            if (islower(ptext[i]))
            {
                ctext[i] = newalpha[ptext[i] - 97];
            }
            // if its uppercase assigning the corresponding character to it
            else
            {
                ctext[i] = toupper(newalpha[ptext[i] - 65]);
            }
        }
        // if its character is not alphabetical don't change it
        else
        {
            ctext[i] = ptext[i];
        }
    }
    // print out the ciphertext
    printf("ciphertext: %s", ctext);
    printf("\n");
}