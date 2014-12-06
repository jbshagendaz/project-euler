/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>
#include <stdint.h>
#include <time.h>

uint32_t collatz(uint32_t n);

int main(){
	clock_t time;
	uint32_t collatz_count;
	uint32_t collatz_max;
	uint32_t n_max;
	uint32_t n;
	uint32_t m;

	time = clock();

	for(n=999999; n > 0; n--){
		m = n;
		collatz_count = 1;

		while(m != 1){
			m = collatz(m);
			collatz_count++;
		
			if(collatz_count > collatz_max){
				collatz_max = collatz_count;
				n_max = n;
			}
		}
	}
	


	time = clock() - time;
	printf("\nseconds: %f", ((float)time)/CLOCKS_PER_SEC);
	printf("\nmax: %d", n_max);

	return 0;
}

uint32_t collatz(uint32_t n){
	if(n%2 == 0){
		return n/2;
	}

	else{
		return (3*n +1);
	}
}
