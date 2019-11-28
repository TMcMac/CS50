#include <stdio.h>


int main() {
//Get the credit card number and store it is ccNum
	long ccNum = printf("Please enter your credit card number:\n");
    scanf("%ld", &ccNum);

//Validate that the number is between 13 and 16 digits
    int digits = 0;
    long validate = ccNum;

    while (validate > 0)
	    {
	        validate = validate / 10;
	        digits++;
	    };

	if (digits != 13 && digits != 15 && digits !=16) 
	{
		printf("INVALID\n");
	};

//Validate the credit card using Luhn’s Algorithm

	//this puts all the digits of ccNum in an array from the last digit to the first
	long checksum = ccNum;
	int count1 = digits;
	int luhn[count1];
		while (count1>0) {
			luhn[count1] = checksum % 10;
			checksum /= 10;
			count1--;
		};

	

	//This will preform the first check of Luhn's Algorithm (every other digit * 2 then add those digits together)

	int m = digits;
	int h = 1;
	int sumOdd = 0;

	while (h <= m) {
		int x = (luhn[h] * 2);

		if (x>=10) {
			int y = (x/10);
			int z = (x % 10);
			sumOdd+= (y+z);
		} else {
			sumOdd += x;
		};

		h += 2;
	};

	//This will add the even digits together for part two of Luhn's algorithm

	int n = digits;
	int i = 2;
	int sumEven = 0;
	

	while (i <= n) {
		sumEven += luhn[i];
		i += 2;
	};

	//Finally add our sumEven and sumOdd to do the final validation of Luhn's Algorithm
	
	int finalsum = ((sumOdd + sumEven) % 10);

	if (finalsum != 0) {
		printf("INVALID\n");
	};

//What type of card is it?
	long ident = ccNum;

	while (ident > 100) {
		ident = ident / 100;
	};

	if (ident >= 51 && ident <= 57) {
		printf("MASTERCARD\n");
	} else if (ident >= 40 && ident <= 49) {
		printf("VISA\n");
	} else if (ident == 34 || ident == 37) {
		printf("AMERICAN EXPRESS\n");
	} else {
		printf("INVALID\n");
	};
    
}