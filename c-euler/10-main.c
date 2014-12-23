/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <time.h>

int main(){
	long sum = 2;
	long primes;

	float min = 0;
	float sec = 0;

	clock_t time = clock();

	for(primes=3; primes < 2000000; primes+=2){
		for(int i=3; i<=primes; i+=2){
			if(i==primes){
				sum += primes;
			}

			if(primes%i == 0){
				i = primes + 1;
			}
		}
	}
   
	printf("\n%ld", sum);
	time = clock() - time;
	min = (float)(time / (CLOCKS_PER_SEC * 60));
	sec = (min - (int)min) * 60;

	printf("benchmark time: %fm %fs", min, sec);

	return 0;	
}
