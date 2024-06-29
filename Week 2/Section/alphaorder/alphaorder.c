#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string checking = get_string("What's the string? ");

    for(int i = 1; i < strlen(checking); i++)
    {
        if (checking[i] < checking[i-1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}