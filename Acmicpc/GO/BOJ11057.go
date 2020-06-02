package main

import "fmt"

func main() {
	var dp [1002][11]uint64
	for i := 0; i <= 10; i++ {
		dp[0][i] = 1
	}
	dp[1][1] = 1
	for i := 2; i <= 10; i++ {
		dp[1][i] = dp[1][i-1] + dp[0][i]
	}
	for i := 2; i < 1001; i++ {
		for j := 1; j <= 10; j++ {
			if j == 1 {
				dp[i][j] = 1
			} else {
				dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007
			}
		}
	}

	var num int
	fmt.Scan(&num)

	fmt.Print(dp[num][10])

}
