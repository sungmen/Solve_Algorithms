package main

import "fmt"

var dp[1001] int
var p[1001] int

func main() {
	var n int
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		fmt.Scan(&p[i])
	}

	for i:= 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			if dp[i] > p[j] + dp[i-j] {
				dp[i] = dp[i]
			} else {
				dp[i] = p[j] + dp[i-j]
			}
		}
	}

	fmt.Println(dp[n])
}