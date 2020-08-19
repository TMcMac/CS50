#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

/**
 * A simple program to calculate the the reading level required for a sample text.
 * This program will promt the user for a block of text and then calculate the
 * required reading level by avg letters in 100 word and avg sentances in 100 words
 * based on the Coleman-Liau index.
*/

int main(void)
{
    float letter_count = 0;
    int word_count = 1;
    float sentance_count = 0;
    int i;
    float grade;
    double l, s;

    string sometext = get_string("Text:");

    for (i = 0; sometext[i] != '\0'; i++)
    {
        if (toupper(sometext[i]) >= 65 && toupper(sometext[i]) <= 90)
        {
            letter_count++;
            // counts letters using toupper and ascii values
        }
        else if (sometext[i] == ' ')
        {
            word_count++;
            // counts words based on spaces
        }
        else if (sometext[i] == 33 || sometext[i] ==  46 || sometext[i] == 63)
        {
            sentance_count++;
            // counts punctuation for sentances (possible error on mr. mrs.)
        }
    }

    l = ((letter_count / word_count) * 100);
    s = ((sentance_count / word_count) * 100);
    grade = ((0.0588 * l) - (0.296 * s) - 15.8);
    // this is the calculation for Coleman-Liau index

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grade));
    }

    return 0;
}