package main

import "fmt"

func main() {
	var test_case int
	fmt.Scan(&test_case)

	cnt := 0

	for t := 0; t < test_case; t++ {
		var str string
		fmt.Scan(&str)

		if str[0] == '+' || str[2] == '+' {
			cnt++
		} else if str[0] == '-' || str[2] == '-' {
			cnt--
		}
	}

	fmt.Println(cnt)
}