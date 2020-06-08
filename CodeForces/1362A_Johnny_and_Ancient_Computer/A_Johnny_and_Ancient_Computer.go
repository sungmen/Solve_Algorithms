package main

import "fmt"

func main() {
	var test_case int
	fmt.Scan(&test_case)

	for t := 0; t < test_case; t++ {
		cnt := 0
		var n, m int64
		fmt.Scan(&n, &m)

		if n > m {
			for n > m {
				if n%8 == 0 && n/8 >= m {
					n /= 8
					cnt++
				} else if n%4 == 0 && n/4 >= m {
					n /= 4
					cnt++
				} else if n%2 == 0 && n/2 >= m {
					n /= 2
					cnt++
				} else {
					break
				}
			}
		} else {
			for n < m {
				if n*8 <= m {
					n *= 8
					cnt++
				} else if n*4 <= m {
					n *= 4
					cnt++
				} else if n*2 <= m {
					n *= 2
					cnt++
				} else {
					break
				}
			}
		}

		if n == m {
			fmt.Println(cnt)
		} else {
			fmt.Println("-1")
		}
	}
}
