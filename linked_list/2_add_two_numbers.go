package main

import (
	"fmt"
	"strconv"
)

type ListNode struct {
	val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	curr_1 := l1
	curr_2 := l2

	var slice_rune_1 []rune
	var slice_rune_2 []rune

	for i := 0; i < 3; i++ {
		slice_rune_1 = append(strconv.Itoa(curr_1.val), slice_rune_1)

		curr_1 = curr_1.Next
		curr_2 = curr_2.Next
	}
}

func main() {
	l1_0 := new(ListNode)
	l1_0.val = 2
	l1_1 := new(ListNode)
	l1_1.val = 4
	l1_2 := new(ListNode)
	l1_2.val = 3
	l1_0.Next = l1_1
	l1_1.Next = l1_2
	l1_2.Next = nil

	l2_0 := new(ListNode)
	l2_0.val = 5
	l2_1 := new(ListNode)
	l2_1.val = 6
	l2_2 := new(ListNode)
	l2_2.val = 4
	l2_0.Next = l2_1
	l2_1.Next = l2_2
	l2_2.Next = nil

	l3 := addTwoNumbers(l1_0, l2_0)
	fmt.Println(l3.val)

}
