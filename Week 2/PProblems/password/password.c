// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    // Asks user for their password
    string password = get_string("Enter your password: ");
    // checks if the password is valid
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    // At start every variable is false
    bool upcase = false, lcase = false, num = false, sym = false;

    int i = 0;
    // till the string is over iterate through it
    while (password[i] != '\0')
    {
        // Check whether it has lowercase
        if (islower(password[i]))
        {
            lcase = true;
        }
        // Check whether it has uppercase
        else if (isupper(password[i]))
        {
            upcase = true;
        }
        // Check whether it has digits
        else if (isdigit(password[i]))
        {
            num = true;
        }
        // Check whether it has symbols
        else if (ispunct(password[i]))
        {
            sym = true;
        }
        i++;
    }

    if (lcase && upcase && num && sym == true)
    {
        return true;
    }
    return false;
}
