#include <cs50.h>
#include <stdio.h>

string replace(string argv);

int main(int argc, string argv[])
{
    // if no comand line argument has been typen print the usage
    if (argc == 1)
    {
        printf("Usage: ./no-vowels <word>\n");
        return 1;
    }
    // if it has, print the converted text
    printf("%s\n", replace(argv[1]));
    return 0;
}

string replace(string argv)
{
    int i = 0;
    // till the end of the string
    while (argv[i] != '\0')
    {
        // switch the characters with leet
        switch (argv[i])
        {
            case 97:
                argv[i] = '6';
                break;
            case 101:
                argv[i] = '3';
                break;
            case 105:
                argv[i] = '1';
                break;
            case 111:
                argv[i] = '0';
                break;
        }
        i++;
    }
    // return the leetspoken text
    return argv;
}