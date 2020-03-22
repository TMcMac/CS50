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
        if(scanf("%d%c", &tmp, &term) != 2 || term != '\n')
        {
            printf("ERROR: you did not enter a number!\n");
            return (-1);
        }
    }

    space = count - 1;
    hash = 1;
    for (rows = 1; rows < count; rows++)
        {
            for (i = 0; i < space; i++)
            {
                putchar(' ');
            }
            for (i = 0; i < hash; i++)
            {
                putchar('#');
            }
            putchar(' ');
            for (i = 0; i < hash; i++)
            {
                putchar('#');
            }
            putchar('\n');
            space--;
            hash++;
        }

}
