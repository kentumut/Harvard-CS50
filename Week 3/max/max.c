// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);
// Prototype for the function
int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);
    // Gets a positive integer for the number of elements
    int arr[n];
    // Creates the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }
    // Asks user for the elements
    printf("The max value is %i.\n", max(arr, n));
    // Prints the max value
}

int max(int array[], int n)
{
    int current_max = array[0];
    // Sets the current max to the first element
    for (int i = 1; i < n; i++)
        // Begings to iterate through every element
    {
        if (current_max < array[i])
        {
            current_max = array[i];
        }
        // If the current max is lower than the current value make they max the current value
    }
    return current_max;
}
