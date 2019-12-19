package main

func main() {
	var s string
	s = "hello" // should be on .string region

	var x int = 12 + 5
	var y float64 = 45 / 8
	var z int = x * y
	var w int = -x
	var test bool = true
	if x >= 2 {
		fmt.println("True")
	}
	// var u int = !w

	// var year int
	// year = x + y + 30
	// fmt.Println(x)
}
