package main

import "fmt"

func main() {
	var test_case int
	fmt.Scan(&test_case)

	for i := 1; i <= test_case; i++ {
		var str string
		fmt.Scan(&str)

		fmt.Printf("String #%d\n", i)
		for j := 0; j < len(str) ; j++ {
			if (str[j] == 'Z') {
				fmt.Printf("A")
			} else {
				fmt.Printf("%c", str[j]+1)
			}
		}
		fmt.Printf("\n\n")

	}
	
}