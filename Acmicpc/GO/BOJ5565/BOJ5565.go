package main

import "fmt"

func main() {
	var sum int
	fmt.Scan(&sum)
	for i := 0; i < 9; i++ {
		var input int
		fmt.Scan(&input)
		sum -= input
	}
	fmt.Println(sum)
}