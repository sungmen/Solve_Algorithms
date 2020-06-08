package main

import "fmt"

func main() {
	var c [101]int
	var dp [10001]int

	var n, k int
	fmt.Scan(&n, &k)

	for i := 1; i <= n; i++ {
		fmt.Scan(&c[i])
	}

	dp[0] = 1

	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			if j >= c[i] {
				dp[j] += dp[j-c[i]]
			}
		}
	}

	fmt.Print(dp[k])
}
