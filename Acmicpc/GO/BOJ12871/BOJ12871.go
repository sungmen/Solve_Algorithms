package main

import "fmt"

func GCD(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func LCM(a, b int, integers ...int) int {
	result := a * b / GCD(a, b)

	for i := 0; i < len(integers); i++ {
		result = LCM(result, integers[i])
	}

	return result
}

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	if len(t) == len(s) {
		if t == s {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	} else {
		lcm := LCM(len(s), len(t))
		res_s := s
		for i := 1; i < lcm/len(s); i++ {
			res_s += s
		}
		res_t := t
		for i := 1; i < lcm/len(t); i++ {
			res_t += t
		}

		if res_t == res_s {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}

}
