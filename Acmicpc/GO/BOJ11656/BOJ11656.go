package main

import (
	"fmt"
	"sort"
)

func main() {

	var str string
	fmt.Scan(&str)
	length := len(str)
	slice := []string{}
	for i := 0; i < length; i++ {
		slicePiece := str[i:length]
		slice = append(slice, slicePiece)
	}
	sort.Strings(slice)
	for _, v := range slice {

		fmt.Println(v)
	}

}
