package main

import (
	"fmt"
	"math"
)

func main() {
	var num int
	var arr[9] int
	
	fmt.Scan(&num)

	var temp int
	
	for num != 0 {
		temp = num % 10
		if(temp == 9) {
			arr[6]++
		} else {
			arr[temp]++
		}
		num /= 10
	} 
	d := float64(arr[6]) / 2.0
	arr[6] = int(math.Ceil(d))
	var max int
	max = 1
	for j:=0;j < 9; j++ {
		if max < arr[j] {
			max = arr[j]
		}
	}

	fmt.Println(max)

}