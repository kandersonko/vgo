package main

func f2(a int) (a int, b float32) { // ERROR "duplicate argument a|definition"
	return 8, 8.0
}

