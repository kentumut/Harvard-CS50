#include <stdio.h>
#include <cs50.h>

string valid_triangle(int sides[]);

int main(void)
{

    int sides[3];
    for(int i = 0; i < 3; i++)
    {
        sides[i] = get_int("Give me the sides of the integer ");
    }

    printf("%s \n", valid_triangle(sides));
}

string valid_triangle(int sides[])
{
    if ((sides[0] || sides[1] || sides[2]) < 1 )
    {
        return "false";
    }

    else if( sides[0] + sides[1] < sides[2] || sides[0] + sides[2] < sides[1] || sides[1] + sides[2] < sides[0])
    {
        return "false";
    }
    return "true";
}