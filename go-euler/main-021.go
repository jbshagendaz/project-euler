/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide
evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a
and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

package main

import (
	"fmt"
)

func sum_divisors(num int64) int64 {
	var sum int64 = 0
	var i int64

	for i = 1; i < num; i++ {
		if num%i == 0 {
			sum += i
		}
	}

	return sum
}

func main() {
	var i int64 = 0
	var sum int64 = 0
	var tmp1 int64 = 0
	var tmp2 int64 = 0
	for i = 1; i < 10000; i++ {
		tmp1 = sum_divisors(i)
		tmp2 = sum_divisors(tmp1)

		if (i == tmp2) && (i != tmp1) {
			sum += i
			fmt.Printf("tmp1: %d\ttmp2: %d\ti: %d\n", tmp1, tmp2, i)
		}
	}

	fmt.Println(sum)
}
