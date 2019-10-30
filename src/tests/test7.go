package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	var v Vertex
	v.X = 4
	fmt.Println(v.X)
	// fmt.Println(Vertex{1, 2})
}
