/****************************************************
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *  1: 1
 *   3: 1,3
 *    6: 1,2,3,6
 *    10: 1,2,5,10
 *    15: 1,3,5,15
 *    21: 1,3,7,21
 *    28: 1,2,4,7,14,28
 *    We can see that 28 is the first triangle number to have over five divisors.
 *
 *    What is the value of the first triangle number to have over five hundred divisors?
 *    ***********************************************/

#include <stdio.h>
#include <time.h>

int factors(int num);

int main(){
	clock_t time;
	int factor;
	int number = 0;
	int counter = 1;
	
	time = clock();

	while(factor < 500){
		number += counter;
		counter += 1;
		
		factor = factors(number);
		printf("\nnumbers: %d\t factors: %d", number, factor);
//		printf("\nfactors: %d", factor);
	}

	time = clock() - time;

	printf("\nnumber: %d", number);
	printf("\nseconds: %f", ((float)time)/CLOCKS_PER_SEC);

	return 0;
}

int factors(int n) 
{
	int initial_n = n;
	int num_factors = 1;

	for (int i = 2; i * i <= initial_n; ++i) // for each number i up until the square root of the given number
	{	
	    int power = 0; 		// suppose the power i appears at is 0
		while (n % i == 0) 	// while we can divide n by i
		{
			n = n / i; 		// divide it, thus ensuring we'll only check prime factors
			++power; 		// increase the power i appears at
		}
		num_factors = num_factors * (power + 1);	 // apply the formula
	}

	if (n > 1) 										// will happen for example for 14 = 2 * 7
	{
	    num_factors = num_factors * 2;				// n is prime, and its power can only be 1, so multiply the number of factors by 2
	}

	return num_factors;
}
