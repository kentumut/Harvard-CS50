#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask users for their name
    string name = get_string("What's your name?\n");
    // Greets the user with their name
    printf("hello, %s\n", name);
}