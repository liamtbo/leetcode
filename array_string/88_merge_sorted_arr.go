package main

import "fmt"

func merge(num1 []int, m int, num2 []int, n int) {
	slice := make([]int, 0, m+n) // slice with len 0 and capacity m+n
	num1_p := 0
	num2_p := 0
	for i := 0; i < (m + n); i++ {

		if num2_p >= len(num2) {
			slice = append(slice, num1[num1_p])
			num1_p++
		} else if num1_p >= len(num1) {
			slice = append(slice, num2[num2_p])
			num2_p++
		} else if num1[num1_p] > num2[num2_p] {
			slice = append(slice, num2[num2_p])
			num2_p++
		} else {
			slice = append(slice, num1[num1_p])
			num1_p++
		}
	}
	num1 = slice
	fmt.Println(num1)
}