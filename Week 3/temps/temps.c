// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10
// Defines the number of cities
typedef struct
{
    string city;
    int temp;
}
avg_temp;
// A neww data type is created
avg_temp temps[NUM_CITIES];
// The array of this data type is created
void sort_cities(void);
// Function prototype
int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;
    // Assinging values to the elements
    sort_cities();
    // The list ist sorted
    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
    // Print each city's name and temperature
}

void sort_cities(void)
{
    int count;
    avg_temp swap;
    // Counting and swapping variables are created
    for (int i = 0; i < 9; i++)
    {
        // The first loop begins (for sorting other elements)
        count = 0;
        // Counter is set to 0
        for (int h = 0; h < 9; h++)
        {
            // Loop to sort the smallest element to the end
            if (temps[h].temp < temps[h + 1].temp)
            {
                // If the temperature attribute of the current element is lower than the next elements begin
                swap = temps[h];
                // Copy the current element to a temporary variable
                temps[h] = temps[h + 1];
                // The next element is copied to the curent one
                temps[h + 1] = swap;
                // The current one is copied to the next one
                count++;
                // Swap successfull, counter is incremented
            }
        }
        if (count == 0)
        {
            return;
        }
        // If no swaps are done finish the sorting, The list is sorted
    }
}
