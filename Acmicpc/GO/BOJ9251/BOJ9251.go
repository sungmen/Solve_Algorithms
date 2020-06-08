package main

import "fmt"

func LCS(str1, str2 string) int {
	var res [1001][1001]int

	for i := 1; i <= len(str1); i++ {
		for j := 1; j <= len(str2); j++ {
			if str1[i-1] == str2[j-1] {
				res[i][j] = res[i-1][j-1] + 1
			} else {
				if res[i-1][j] > res[i][j-1] {
					res[i][j] = res[i-1][j]
				} else {
					res[i][j] = res[i][j-1]
				}
			}
		}
	}

	return res[len(str1)][len(str2)]
}

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	fmt.Println(LCS(str1, str2))
}
