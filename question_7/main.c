/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 *
 */

#include <stdio.h>

int main(){
	int prime_counter = 1;
	long counter = 1;

	while(prime_counter < 10001){
		if(counter % 2 != 0) {
			for(int i=3; i<=counter; i++){	
				if(i==counter){
					prime_counter++;
					printf("\n%ld\t\t%d", counter, prime_counter);
				}

				if(counter%i == 0){
					i = counter + 1;
				}

			}
		}

		counter++;
	}

}
