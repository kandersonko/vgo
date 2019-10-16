package main

import (
	"fmt"
	"math"
)

type pet struct {
	hunger int
	happy  int
	power  float64
	name   string
}

const x int = 2

var y float64 = math.Sin(30)

var z, t int

var logicalValue bool

func main() {
	// var year = math.Sin(20)
	print("hello, world\n")
	fmt.Println("stuff and things")
	var m string = "hello"
	const year int = 2019
	const data int = 1138159
	const age int = 17
}

func add(a int, b float64) string {
	var k string = "text"
	return a + b
}

func double(n int) float64 {
	var factor float64
	return n * factor
}
