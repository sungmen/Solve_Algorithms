package main

import (
	"bytes"
	"fmt"
)

func main() {
	var reverse int
	fmt.Scan(&reverse)

	var str, str2 []byte
	fmt.Scan(&str, &str2)

	if reverse%2 == 0 {
		if bytes.Equal(str, str2) {
			fmt.Println("Deletion succeeded")
		} else {
			fmt.Println("Deletion failed")
		}
	} else {
		for i := 0; i < len(str); i++ {
			if str[i] == '0' {
				str[i] = '1'
			} else {
				str[i] = '0'
			}
		}
		if bytes.Equal(str, str2) {
			fmt.Println("Deletion succeeded")
		} else {
			fmt.Println("Deletion failed")
		}

	}

}
