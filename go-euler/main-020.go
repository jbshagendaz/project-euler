package main

import (
	"fmt"
)

func factorial(in int64) int64 {
	var out int64 = 1

	for i := in; i > 0; i-- {
		out *= i
	}

	return out
}
func main() {
	fmt.Println(factorial(10))
}
