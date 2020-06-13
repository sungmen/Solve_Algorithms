package main

import "fmt"

var node[26][2] int
var N int

func main() {
	var N int
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		var val, idxl, idxr string
		fmt.Scan(&val, &idxl, &idxr)
		for _, num := range val {
			for _, la := range idxl {	
				if idxl != "." {
					node[int(num) - 65][0] = int(la) - 65
				} else {
					node[int(num) - 65][0] = -1
				}
			}

			for _, ra := range idxr {
				if idxr != "." {
					node[int(num) - 65][1] = int(ra) - 65
				} else {
					node[int(num) - 65][1] = -1
				}
			}
		}
	}
	preOrder(0)
	fmt.Println()
	inOrder(0)
	fmt.Println()
	postOrder(0)
}

func preOrder(n int) {
	if n == -1{
		return
	}
	fmt.Printf("%c", n +'A')
	preOrder(node[n][0])
	preOrder(node[n][1])
}

func inOrder(n int) {
	if n == -1{
		return
	}
	inOrder(node[n][0])
	fmt.Printf("%c", n +'A')
	inOrder(node[n][1])
}

func postOrder(n int) {
	if n == -1{
		return
	}
	postOrder(node[n][0])
	postOrder(node[n][1])
	fmt.Printf("%c", n +'A')
}