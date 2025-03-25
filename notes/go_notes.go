package main

import "fmt"

func main() {
	fmt.Println("yo what up")
	var x int = 45
	y := 13
}

func add(a int, b int) int {
	return a + b
}
// ---------------------------------
// printing
var randomNum int = 10
fmt.Println(randomNum)
fmt.Printf("Random int: %s\n", randomNum)

// ---------------------------------
// loops
// for
for i:=0; i < 5; i++ {
	fmt.Println(i)
}
// while
for true {...}

slice1 := []int{1,2,3,4,5}
for index, value := range nums {
	fmt.Printf("Index: %d, Value; %d\n", index, value)
}

for i := 1; i < len(slice1); i++ {
	fmt.Printf("nums: %d\n", slice1[i])
}

// ---------------------------------
// conditionals
if x > 10 {
	fmt.Println("x is greater than 10")
} else {
	fmt.Println("x is 10 or less")
}
// init vars in if statement
if val, ok := s_map[key]; !ok || val != value {...}

// --------------------------------
// arrays and matrices
var arr [5]int
arr[0] = 10
fmt.Println(arr)

arr2 := [3]int{1,2,3}
fmt.Println(arr2)

// 2d array
var matrix [3][3]int
matrix[0][0] = 1

// 2d array
matrix := [2][2]int{
	{1,2},
	{3,4}
}
fmt.Println(matrix2)

str := "hello world"
// -------------------------------------------
// slices
/*slices are dynamically sized, flexible arrays*/
// array to slice
arr := [5]int{1,2,3,4,5} // writing [int] makes it array
slice:= arr[1:4]

// creating a slice directly
slice := []int{1,2,3,4,5}

// using make
slice := make([]int, 3) // slice of length 3 and capacity 3
slice := make([]int, 3, 5) // creates a slice with length 3 (init to zeros) and capcity 5
slice_len = len(slice)
slice_cap = cap(slice)

// appending to a slice
slice := []int{1,2,3}
slice = append(slice, 4,5) // append 4 and 5 to the slice

// copying a slice
src := []int{1,2,3}
dst := make([]int, len(src))
copy(dst, src)

// 2d slices
rows, cols := 3, 3
grid := make([][]int, rows) // create the outer slice
for i := range grid {
	grid[i] = make([]int, cols)
}

// empty slice of strings
var list []string

//-----------------------------------------
// structs
type Person struct {
	Name string
	Age int
}

p1 := Person("raquel", 21)
var p3 Person // fields will be set to their 0 values
P4 := new(Person)
p4.Name = "liam"
p4.Age = 35

// use pointer when you want to modify struct in function and 
// have those changs outside function too
type Person struct{
	name string
}
// allocates mem but does not initialize memory beyond setting it to zero value of type
p := new(Person)
p.name = "cucumber"
func change(p *Person) {
	p.name = "cynder" // go automatic derefencing
}
change(p)
fmt.Println(p.name)

// ---------------------------------------
// dictionaries
// make is used to init and alloc memory for clies, maps, and channel
// init beyond zeros means creating the structures and ret reference (pointers)
myMap := make(map[string]int)
myMap["apple"] = 10
// checking if key exists
if _, ok := myMap["banana"]; ok {...}\

// looping over dict
for key, val := range myMap {...}

// ---------------------------------------
// string editing
import (
	"fmt"
	"unicode"
	"strings"
)
var s string = "pancake"
// muttable string
// []byte for ASCII and UTF-8 text
mutabel_s := []bytes("walrus")
mutabel_s[4] = 'T'
mutabel_s = append(mutabel_s, '!', '!')

// []rune for unicode (> 1byte)
rune_s := []rune(s)
rune[0] = 't'
fmt.Println(len(s))

// checking if alphanumeric
unicode.IsLetter(s[left_p]) || unicode.IsDigit(s[left_p])

// upper, lower
strings.ToUpper(s)
strings.ToLower(s)

// concat ints and strings
num1 := 1
num2 := 2
result := strconv.Itoa(num1) + "->" + strconv.Itoa(num2)

// join and split
str1 := "helllo darkness my old friend"
split_str1 := strings.Split(str1, " ")
joined_str1 := strings.Join(split_str1, "")

// list(slice) of strings
var str_slice []string
str_slice = append(str_slice, "ballsack")