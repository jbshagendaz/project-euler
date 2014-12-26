package main

import (
	"fmt"
)

func main() {
	var year int
	var month int
	var day int
	var today_int int = 2
	var count int = 0

	var days = make(map[int]int)
	days[0] = 31  //Jan
	days[1] = 28  //Feb
	days[2] = 31  //Mar
	days[3] = 30  //Apr
	days[4] = 31  //May
	days[5] = 30  //Jun
	days[6] = 31  //Jul
	days[7] = 31  //Aug
	days[8] = 30  //Sep
	days[9] = 31  //Oct
	days[10] = 30 //Nov
	days[11] = 31 //Dec

	var today = make(map[int]string)
	today[0] = "Sunday"
	today[1] = "Monday"
	today[2] = "Tuesday"
	today[3] = "Wednesday"
	today[4] = "Thursday"
	today[5] = "Friday"
	today[6] = "Saturday"

	for year = 1901; year < 2001; year++ {
		if (year%4 == 0 && year%100 != 0) || (year%400 == 0) {
			days[1] = 29
		} else {
			days[1] = 28
		}

		for month = 0; month < 12; month++ {
			for day = 0; day < days[month]; day++ {
				if day == 0 && today_int == 0 {
					count++
				}

				if today_int < 6 {
					today_int++
				} else {
					today_int = 0
				}
			}
		}
	}

	fmt.Println(count)
}
