/****
 * Smallest multiple
 * Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 * ***/

#include <stdio.h>


int main(void){
	int is_done = 0;
	int number = 5;

	while(!is_done){
		if(number%20 == 0 && number%19 == 0 && number%18 == 0 && number%17 == 0 && number%16 == 0 && 
		   number%15 == 0 && number%14 == 0 && number%13 == 0 && number%12 == 0 && number%11 == 0){
		   is_done = 1;
		}
		else
			number++;	
	}

	printf("number = %d", number);

	return 0;
}
