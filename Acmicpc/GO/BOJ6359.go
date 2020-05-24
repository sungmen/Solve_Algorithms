package main

import "fmt"

func main() {
	var dp [101]int
	dp[5] = 2

	for i := 6; i <= 100; i++ {
		if factorization(i) == 1 {
			dp[i] = dp[i-1] + 1
		} else {
			dp[i] = dp[i-1]
		}

	}

	var test_case int
	fmt.Scan(&test_case)

	for i := 1; i <= test_case; i++ {
		var t int
		fmt.Scan(&t)
		fmt.Println(dp[t])
	}
}

func factorization(num int) int {
	cnt := 0
	for i := 1; i <= num; i++ {
		if (num % i) == 0 {
			cnt++
		}
	}

	return cnt % 2
}
