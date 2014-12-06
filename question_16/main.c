/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/

#include <stdio.h>
#include <gmp.h>

int main(){
    mpz_t x;
    mpz_t y;
    mpz_t ans;

    mpz_inits(x, y, ans);

    mpz_set_ui(ans, 0);
    mpz_set_ui(x, 2);
    mpz_set_ui(y, 15);

    mpz_pow_ui(ans, x, 1000);

    mpz_out_str(stdout, 10, ans);
    //mpz_clears(ans, y, x);

  return 0;
}