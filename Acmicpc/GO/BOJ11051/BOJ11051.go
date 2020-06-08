package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var dp [1001][1001]int

	for row := 1; row <= n; row++ {
		for col := 0; col <= n; col++ {
			if row == col || col == 0 {
				dp[row][col] = 1
				continue
			}
			dp[row][col] = (dp[row-1][col] + dp[row-1][col-1]) % 10007
		}
	}
	fmt.Printf("%d", dp[n][k])
}
