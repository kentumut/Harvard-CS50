#include <cs50.h>
#include <stdio.h>

typedef struct
{
    int name;
    int age;
}
alter;

int main(void)
{
    alter kent[2];
    kent[0].name = 32;
    kent[0].age = 69;

    printf("%i", kent[0].name);
}

