package main

import "fmt"

func main () {
	var n int
	fmt.Scan(&n)
	var arr[200] int
	for i:=0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	var dp[200] int

	for i:=0; i < n; i++ {
		dp[i] = arr[i]
		for j:=0; j < i; j++ {
			if arr[j] < arr[i]{
				dp[i] = dp[j] + arr[i]
			}
		}
	}

	var maxL int
	maxL = dp[0]
	for i:=1; i < n; i++ {
		if maxL < dp[i] {
			maxL = dp[i]
		}
	}
	
	fmt.Println(maxL)
}