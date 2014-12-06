/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *
 * a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>
#include <math.h>

int main(){
 	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int c = 2;

	char done = 0;

	for(a=1; a<1000 && !done; a++){
		for(b=2; b<1000 && !done; b++){
			for(c=3; c<1000 && !done; c++){
				if((pow(a,2) + pow(b,2)) == pow(c,2)){
					if((a+b+c) == 1000){
						done = 1;
						printf("a = %d\n", a);
						printf("b = %d\n", b);
						printf("c = %d\n", c);
					}
				}
			}
		}
		
		printf("%d\n", a);
	}


	return 0;
}
