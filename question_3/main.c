/*************************************************
 * Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600,851,475,143?
 * **********************************************/

#include <stdio.h>
int isPrime(long number_to_test);

int main(void){
	long number = 600851475143;
	long largest_prime = 2;

	for(long j=2; j<number; j++){
		if(number%j == 0 && isPrime(j)){
			number = number / j;
			
			printf("\n j=%ld \t number=%ld",j, number);
			if(j > largest_prime){
				largest_prime = j;
				
				if(isPrime(number) && number > largest_prime){
					largest_prime = number;
					number = 1; 
				}
			}

			j=2;
		}
	}	

	printf("\n\n\nlargest prime = %ld", largest_prime);

	return 0;
}

int isPrime(long number_to_test){
	for(int i=2; i<number_to_test; i++){
		if(number_to_test%i == 0) 
			return 0;
	}
	
	return 1;
}
