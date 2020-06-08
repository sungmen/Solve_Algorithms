package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scan(&str)

	res := strings.ToLower(str)
	for i := 0; i < len(str); i++ {
		if res[i] != 'a' && res[i] != 'i' && res[i] != 'e' && res[i] != 'o' && res[i] != 'y' && res[i] != 'u' {
			fmt.Printf(".%c", res[i])
		}
	}
}
