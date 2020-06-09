// https://www.acmicpc.net/problem/18301
package main

import (
	"fmt"
	"math"
)

func main() {
	var n1, n2, n12, N float64
	fmt.Scan(&n1, &n2, &n12)
	N = math.Floor((n1+1)*(n2+1)/(n12+1) - 1)
	fmt.Println(N)
}
