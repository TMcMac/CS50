#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long CCnum, temp;
    int breakup[16];
    int firsttwo, i, count = 0, sum1 = 0, sum2 = 0;

    CCnum = get_long("Please enter your credit card number: "); //get the crdtcrd num and validate is long

    temp = CCnum; //I want to perserve CCnum in case I need it

    while (temp >= 1)
    {
        temp /= 10;
	count++; // This counts the number of digits
    }
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n"); // if it does have these digit counts it isnt valid
        return (0);
    }
    temp = CCnum;
    for (i = 0; i < count; i++)
    {
        if (temp >= 10)
        {
            breakup[i] = (temp % 10); //putting the ccnum in an array back to front
            temp /= 10;
        }
        else
        {
            breakup[i] = temp; 
            // last (first) digit of ccnum
        }
    }
    
    //Starting Luhn's algo
    for (i = 0; i < count; i++)
    {
        if (i == 0 || i % 2 == 0)
        {
            sum1 += breakup[i]; //my array has ccnum backwards of array[0] is last digit
        }
        else
        {
            sum2 += (((breakup[i] * 2) / 10) + ((breakup[i] * 2) % 10));
            // any odd position in the array this way needs to be doubled 
            //and then its digits summed together
        }
    }
    if ((sum1 + sum2) % 10 != 0)
      
    {
        printf("INVALID\n"); // if our sum does not end in 0 it is invalid
        return (0);
    }
    else
    {
        firsttwo = ((breakup[count - 1] * 10) + (breakup[count - 2]));
        if (count == 15 && (firsttwo == 34 || firsttwo == 37))
        {
            printf("AMEX\n"); // AMEX is 15 digits and starts with 34 or 37
        }
        else if ((count == 13 || count == 16) && (firsttwo / 10 == 4))
        {
            printf("VISA\n"); // VISA is 13 or 16 digits and starts with 4
        }
        else if (count == 16 && (firsttwo > 50 && firsttwo < 56))
        {
            printf("MASTERCARD\n"); // MC is 16 digits and starts with 51 to 55
        }
        else
        {
            printf("INVALID\n");
        }
    }
    return (0);
}
