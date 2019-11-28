#include <stdio.h>

int main(void)
{
    int height; 
    do {
    printf("Please enter a number between 1 and 8.\n");
    scanf("%d", &height);
    } while ( height < 1 || height > 8);
    
    for (int r = 0 ; r<=height; r++)
        {
            for (int u = 8; u > r; u--)
            {
            	printf(" ");
            }

            for (int s = 0; s < r; s++)
            {
                printf("#");
                
            }
            
            printf(" ");

            for (int t = 0; t < r; t++)
            {
            	printf("#");
            }


        printf("\n");
        }

}
