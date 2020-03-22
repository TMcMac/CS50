#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char term;
    int count = 0;
    int i, space, hash, rows, tmp;

    while (count < 1 || count > 8)
    {
        printf("Please enter a number between 1 and 8 (inclusive): \n");
        tmp = scanf("%d%c", &count, &term);
        if (tmp != 2 || term != '\n')
        {
            printf("ERROR: you did not enter a number!\n");
            return (-1);
        }
    }

    space = count - 1;
    hash = 1;
    i = 0;
    for (rows = 0; rows < count; rows++)//iterate till we hit the right number of rows
    {
        for (i = 0; i < space; i++)//leading spaces left side of pyramid
        {
            putchar(' ');
        }
        for (i = 0; i < hash; i++)//left hashes
        {
            putchar('#');
        }
        putchar(' '); //gap between sides
        putchar(' '); //gap between sides
        for (i = 0; i < hash; i++)//right side of pyramid
        {
            putchar('#');
        }
        putchar('\n');
        space--;
        hash++;
    }
}
