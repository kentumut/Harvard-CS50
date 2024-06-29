#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int Coleman(string sen);

int main(void)
{
    // Get string input from user
    string sentence = get_string("Text: ");
    // Grade is the return of the function
    int grade = Coleman(sentence);
    // if its lower than 1 its before grade 1
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    // if its 16 or higer its Grade 16+
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    // else its that grade
    else
    {
        printf("Grade %i\n", grade);
    }
}

int Coleman(string sen)
{
    // initializing variables outside the loop
    int letter = 0;
    int word = 0;
    int sentence = 0;

    // iterating through the string
    for (int i = 0; i < strlen(sen); i++)
    {
        // if its a-z or A-Z increment letter
        if ((64 < sen[i] && sen[i] < 91) || (96 < sen[i] && sen[i] < 123))
        {
            letter++;
        }
        // if its . or ! or ? increment sentence
        else if (sen[i] == 46 || sen[i] == 33 || sen[i] == 63)
        {
            sentence++;
        }
        // if its space increment the word count
        else if (sen[i] == 32)
        {
            word++;
        }
    }
    // calculating the index
    word++;
    float L = letter / (float) word * 100;
    float S = sentence / (float) word * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return (int) round(index);
}