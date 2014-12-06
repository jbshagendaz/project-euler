/*******************************************
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * *****************************************/
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int number);
int answer = 0;

int main(void){
	int i = 999;
	int j = 999;
	int product =  0;
	int test = 0;	
	while(i>100){
		while(j>100){
			product = i*j;
			printf("\ni=%d\tj=%d\tproduct=%d", i, j, product);
			if(isPalindrome(product)){
				if(product > answer)
					answer = product;	
			}
			j--;
		}
		j=999;
		i--;
	}

	printf("\nproduct=%d", answer);
	return 0;
}

int isPalindrome(int number){
	int isPalindrome = 1;
	char* str = malloc(8); 
	int length = sprintf(str, "%d", number);
	

		if(length == 6){
			if((str[0] != str[5]) || (str[1] != str[4]) || (str[2] != str[3])){
				isPalindrome = 0;
			}
		}

		else if(length == 5){
			if(str[0] != str[4] || str[1] != str[3]){
				isPalindrome = 0;
			}
		}
	
	free(str);
	return isPalindrome;
}
