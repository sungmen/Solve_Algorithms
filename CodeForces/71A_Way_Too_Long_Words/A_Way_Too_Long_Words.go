package main

import "fmt"

func main() {
	var test_case int
	fmt.Scan(&test_case)

	for t := 0; t < test_case; t++ {
		var str string
		fmt.Scan(&str)

		if len(str) > 4 {
			fmt.Printf("%c%d%c\n", str[0], (len(str) - 2), str[len(str)-1])
		} else {
			fmt.Println(str)
		}
	}
}
