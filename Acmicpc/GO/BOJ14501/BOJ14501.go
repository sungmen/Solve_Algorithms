package main

import (
	"fmt"
)

var n int64;
var arr[16] int64;
var profit[16] int64;
var max_v int64;

func Max(x, y int64) int64 {
	if x < y {
		return y;
	}
	return x;
}

func fnd(day int64, sum int64, num int64) {
	if day == n + 1 {
		max_v = Max(max_v, sum);
		return;
	} else if day > n + 1 {
		max_v = Max(max_v, sum - num);
		return;
	}

	var t_case int64;

	for t_case = day + arr[day]; t_case <= n + arr[day]; t_case++ {
		fnd(t_case, sum + profit[day], profit[day]);
	}
}

func main() {
	fmt.Scan(&n);
	var t_case int64;

	for t_case = 1; t_case <= n; t_case++ {
		fmt.Scan(&arr[t_case], &profit[t_case]);
	}
	for t_case = 1; t_case <= n; t_case++ {
		fnd(t_case, 0, 0);
	}
	fmt.Printf("%d", max_v);
}