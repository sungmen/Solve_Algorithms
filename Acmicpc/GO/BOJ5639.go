package main

import (
	"fmt"
)

type Tree struct {
	node *Node
}

type Node struct {
	value int
	left  *Node
	right *Node
}

func (t *Tree) insert(value int) *Tree {
	if t.node == nil {
		t.node = &Node{value: value}
	} else {
		t.node.insert(value)
	}
	return t
}

func postFix(n *Node) {
	if n == nil {
		return
	}
	postFix(n.left)
	postFix(n.right)
	fmt.Println(n.value)
}

func (n *Node) insert(value int) {
	if value <= n.value {
		if n.left == nil {
			n.left = &Node{value: value}
		} else {
			n.left.insert(value)
		}
	} else {
		if n.right == nil {
			n.right = &Node{value: value}
		} else {
			n.right.insert(value)
		}
	}
}

func main() {
	t := &Tree{}

	for i := 0; i < 10000; i++ {
		var n int
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		t.insert(n)
	}

	postFix(t.node)
}
