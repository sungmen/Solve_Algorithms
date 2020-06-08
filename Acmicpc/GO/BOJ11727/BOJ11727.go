package main

import "fmt"

func main() {
	var n int
	var dp[1001] int

	dp[0] = 1
	dp[1] = 1

	fmt.Scan(&n)
	for i:=2; i <= n; i++ {
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007
	}

	fmt.Println(dp[n])
}