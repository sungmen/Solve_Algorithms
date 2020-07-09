package main

import "fmt"

func main() {
	n := 0
	fmt.Scan(&n)

	arr := make([]int, n+1)
	for i := 1; i <= n; i++ {
		arr[i] = i
		for j := 2; j*j <= i; j++ {
			if arr[i-(j*j)]+1 < arr[i] {
				arr[i] = arr[i-(j*j)] + 1
			}
		}
	}

	fmt.Println(arr[n])
}
