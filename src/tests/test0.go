package main

import (
	"fmt"
	"math"
)

var arr [128]string

type rect struct{ width, height int }

var mymap map[string]int
var map2 map[int]float64

type pet struct {
	hunger int
	happy  int
	power  float64
	name   string
}

// type pet struct {
// 	hunger int
// 	name   string
// }

const x int = 2

var y float64 = math.Sin(30)

var z, t int

var logicalValue bool

func main() {
	map2[3] = 9.6

	// var year = math.Sin(20)
	print("hello, world\n")
	fmt.Println("stuff and things")
	var m string = "hello"
	const year int = 2019
	const data int = 1138159
	const age int = 17
}

func add(a int, p bool, dog pet, m map[int]string, ar [5]string) string {
	a[4] = 100

	const x int = 4
}

func double(n int) float64 {
	return n * 0.2
}
