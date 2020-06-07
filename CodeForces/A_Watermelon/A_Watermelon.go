package main

import "fmt"

func main() {
	var num int
	fmt.Scan(&num)

	if num%2 == 0 && num > 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

}
