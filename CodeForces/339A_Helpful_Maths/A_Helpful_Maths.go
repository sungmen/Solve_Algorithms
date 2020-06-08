package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	var str string

	fmt.Scan(&str)

	var num []int
	for i := 0; i < len(str); i += 2 {
		j, _ := strconv.Atoi(string(str[i]))
		num = append(num, j)
	}

	sort.Ints(num)

	for i := 0; i < len(str)/2; i++ {
		fmt.Printf("%d+", num[i])
	}
	fmt.Printf("%d\n", num[(len(str)/2)])

}
