package main

import "fmt"

func main() {
	var n, k int

	fmt.Scan(&n, &k)

	var a int
	for i := 0; i < k; i++ {
		fmt.Scan(&a)
		if a == 0 {
			fmt.Println(i)
			return
		}
	}

	for i := k; i < n; i++ {
		var a2 int
		fmt.Scan(&a2)

		if a2 != a {
			fmt.Println(i)
			return
		}
	}

	fmt.Println(n)
}
