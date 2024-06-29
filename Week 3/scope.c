#include <stdio.h>

int change(zero)
    {
        for (int i = 0; i < 3; i++)
        {
            zero++;
        }
        return zero;
    }

int main(void)
{
    int zero = 0;
    change(zero);
    printf("%i", zero);
}