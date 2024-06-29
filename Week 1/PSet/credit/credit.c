#include <cs50.h>
#include <stdio.h>
// Function checking the credit card with the checksum
bool validator(long ccnumber);
// Function saying the name of the provider
string company(long ccnumber);
int main(void)
{
    // Asking user the Credit Card Number
    long ccnumber = get_long("Number: ");
    // If checksum validates print which company's card it is else print invalid
    if (validator(ccnumber))
    {
        printf("%s", company(ccnumber));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool validator(long ccnumber)
{
    // Assign ccnumber to a different variable in order to keep the ccnumber value after the operations
    long creditcard = ccnumber;
    // Geting every other digit starting with the last
    int sum1 = 0;
    while (creditcard > 0)
    {
        int last_digit = creditcard % 10;
        sum1 = sum1 + last_digit;
        creditcard = creditcard / 100;
    }
    // Getting every other digit starting with the second last
    int sum2 = 0;
    creditcard = ccnumber / 10;
    while (creditcard > 0)
    {
        int last_digit = creditcard % 10;
        sum2 = sum2 + (2 * last_digit % 10) + ((2 * last_digit) / 10);
        creditcard = creditcard / 100;
    }
    // If the total of the sums modulo 10 is congruent to 0 the cards are valid
    int fsum = sum1 + sum2;
    if (fsum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string company(long ccnumber)
{
    // Trying to find the credit card length
    int length = 0;
    while (ccnumber > 100)
    {
        ccnumber = ccnumber / 10;
        length++;
    }
    // Keeps first two digits of the creditcardnumber
    length = length + 2;
    // If the creditcard number starts with 4 and its length is 13 or 16 it's VISA
    if (ccnumber / 10 == 4 && (length == 13 || length == 16))
    {
        return "VISA\n";
    }
    // If the creditcard number starts with 34 or 37 and its length is 16 it's American Express
    else if ((ccnumber == 34 || ccnumber == 37) && length == 15)
    {
        return "AMEX\n";
    }
    // If the creditcard number starts with 51 or 52 or 53 or 54 and its length is 16 it's Mastercard
    else if ((ccnumber == 51 || ccnumber == 52 || ccnumber == 53 || ccnumber == 54 || ccnumber == 55) && length == 16)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}