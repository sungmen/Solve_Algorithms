package main

import "fmt"

func main() {
	var dp [100001]int
	var input int
	fmt.Scan(&input)
	dp[0] = 3
	dp[1] = 7
	dp[2] = 17
	dp[3] = 41

	for i := 4; i < 100001; i++ {
		dp[i] = (dp[i-1]*2 + dp[i-2]) % 9901
	}

	fmt.Println(dp[input-1])
}
