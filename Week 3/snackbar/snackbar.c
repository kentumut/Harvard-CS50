// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 6

// Menu items have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");
    // Print the introduction
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");
    // Printing the price of menu items
    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }
        // Ask user for food items
        total += get_cost(item);
    }
    // Calculate the total of menu items

    printf("Your total cost is: $%.2f\n", total);
    // Print the total cost
}

// Add at least the first four items to the menu array
void add_items(void)
{
    menu[0].item = "Burger";
    menu[0].price = 9.5;
    menu[1].item = "Hot Dog";
    menu[1].price = 5;
    menu[2].item = "Cheese Dog";
    menu[2].price = 7;
    menu[3].item = "Cheese Fries";
    menu[3].price = 6;
    menu[4].item = "Water";
    menu[4].price = 2;
    menu[5].item = "Soda";
    menu[5].price = 2;
    return;
    // Adding 6 items to the menu
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcasecmp(item, menu[i].item) == 0)
        {
            // Search every element and compare the strings
            return menu[i].price;
            // If the strings are same return the price
        }

    }
    return 0.0;
    // Return case for user-mistakes
}
