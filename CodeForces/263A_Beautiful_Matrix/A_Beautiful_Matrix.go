package main

import "fmt"

func main () {
	var num int

	cnt := 0

	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			fmt.Scan(&num)
			if num == 1 {
				i = 2 - i
				j = 2 - j
				if i < 0 {
					cnt -= i
				} else {
					cnt += i
				}
				if j < 0 {
					cnt -= j
				} else {
					cnt += j
				}

				fmt.Println(cnt)
				return
			}
		}
	}
}