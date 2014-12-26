/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	hundreds := make(map[int]string)
	hundreds[0] = ""
	hundreds[1] = "one"
	hundreds[2] = "two"
	hundreds[3] = "three"
	hundreds[4] = "four"
	hundreds[5] = "five"
	hundreds[6] = "six"
	hundreds[7] = "seven"
	hundreds[8] = "eight"
	hundreds[9] = "nine"

	tens := make(map[int]string)
	tens[0] = ""
	tens[1] = ""
	tens[2] = "twenty"
	tens[3] = "thirty"
	tens[4] = "forty"
	tens[5] = "fifty"
	tens[6] = "sixty"
	tens[7] = "seventy"
	tens[8] = "eighty"
	tens[9] = "ninety"
	tens[10] = "ten"
	tens[11] = "eleven"
	tens[12] = "twelve"
	tens[13] = "thirteen"
	tens[14] = "fourteen"
	tens[15] = "fifteen"
	tens[16] = "sixteen"
	tens[17] = "seventeen"
	tens[18] = "eighteen"
	tens[19] = "nineteen"

	ones := make(map[int]string)
	ones[0] = ""
	ones[1] = "one"
	ones[2] = "two"
	ones[3] = "three"
	ones[4] = "four"
	ones[5] = "five"
	ones[6] = "six"
	ones[7] = "seven"
	ones[8] = "eight"
	ones[9] = "nine"

	var buffer bytes.Buffer

	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {

				if i > 0 {
					buffer.WriteString(hundreds[i])
					buffer.WriteString("hundred")

					if j != 0 || k != 0 {
						buffer.WriteString("and")
					}
				}

				if j == 1 {
					buffer.WriteString(tens[(j*10)+k])
				} else {
					buffer.WriteString(tens[j])
					// buffer.WriteString(" ")
					buffer.WriteString(ones[k])
				}

				// fmt.Println(buffer.String())
				// buffer.Reset()
			}
		}
	}

	buffer.WriteString("onethousand")

	fmt.Println(buffer.String())
	fmt.Println(len(buffer.String()))

}
