package main

import "fmt"

func main() {
	var t int
	fmt.Scan(&t)

	for test_case := 0; test_case < t; test_case++ {
		var n, x, m int
		fmt.Scan(&n, &x, &m)

		tempL := x
		tempR := x

		for i:=0; i<m; i++ {
			var l, r int
			fmt.Scan(&l, &r)
			if (r>=tempL && tempR >= l) {
				if l < tempL {
					tempL = l
				}
				if r > tempR {
					tempR = r
				}
			}
		}
		fmt.Println(tempR-tempL+1)
	}

}