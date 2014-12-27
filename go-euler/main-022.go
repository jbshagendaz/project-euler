/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names, begin by sorting it into alphabetical order.
Then working out the alphabetical value for each name, multiply this value by its
alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func ExtendCapacity(slice []string) []string {
	newSlice := make([]string, len(slice), 2*cap(slice))
	copy(newSlice, slice)
	return newSlice
}

func ExtendLength(slice []string, element string) []string {
	n := len(slice)
	slice = slice[0 : n+1]
	slice[n] = element
	return slice
}

func main() {
	file, err := os.Open("../files/p022_names.txt")
	if err != nil {
		fmt.Println(err)
	}

	reader := bufio.NewReader(file)
	slice := make([]string, 1, 2)

	var letters = make(map[byte]int)
	letters[65] = 1  // 'A'
	letters[66] = 2  // 'B'
	letters[67] = 3  // 'C'
	letters[68] = 4  // 'D'
	letters[69] = 5  // 'E'
	letters[70] = 6  // 'F'
	letters[71] = 7  // 'G'
	letters[72] = 8  // 'H'
	letters[73] = 9  // 'I'
	letters[74] = 10 // 'J'
	letters[75] = 11 // 'K'
	letters[76] = 12 // 'L'
	letters[77] = 13 // 'M'
	letters[78] = 14 // 'N'
	letters[79] = 15 // 'O'
	letters[80] = 16 // 'P'
	letters[81] = 17 // 'Q'
	letters[82] = 18 // 'R'
	letters[83] = 19 // 'S'
	letters[84] = 20 // 'T'
	letters[85] = 21 // 'U'
	letters[86] = 22 // 'V'
	letters[87] = 23 // 'W'
	letters[88] = 24 // 'X'
	letters[89] = 25 // 'Y'
	letters[90] = 26 // 'Z'

	name, eof := reader.ReadString('\n')
	slice[0] = name

	for i := 1; eof == nil; i++ {
		if i == cap(slice) {
			slice = ExtendCapacity(slice)
		}

		name, eof = reader.ReadString('\n')
		slice = ExtendLength(slice, name)
	}

	sort.Strings(slice)

	var number int64
	for i := range slice {
		arr := []byte(slice[i])
		tmp := 0
		for j := range arr {
			if arr[j] != 10 {
				tmp += letters[arr[j]]
			}
		}
		fmt.Println(slice[i], " i:", i, " sum:", tmp)
		number += int64(tmp * (i + 1))
	}

	fmt.Println(number)
}
