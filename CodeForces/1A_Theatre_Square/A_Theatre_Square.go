package main

import "fmt"

func main() {
	var n, m, a, x, y int64
	fmt.Scan(&n, &m, &a)

	if n%a == 0 {
		x = n / a
	} else {
		x = (n / a) + 1
	}

	if m%a == 0 {
		y = m / a
	} else {
		y = (m / a) + 1
	}

	fmt.Println(x * y)

}
