#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Asks the user for the week they have been taking CS50
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Getting the hours for each week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Asks user which output they want
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    int sum = 0;
    // Sums the hours
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }
    // If its the total it just prints
    if (output == 'T')
    {
        return sum;
    }
    // if its not then it's A so it return the average as float
    return (float) sum / weeks;
}