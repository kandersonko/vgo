package main

// A test of the for loop syntax

func random() int {
	return 1
}

func main() {

	var test1 int

	var test3 int
	var test4, test5 int
	var test6, test7, test8 int

	// All values filled
	for test1 = 0; test1 < 10; test1 += 1 {
	}

	// No first statement
	test3 = 0
	for ; test3 < 10; test3 += 1 {
	}

	// No second statement
	for test4 = 0; ; test4 += 1 {
		if test4 >= 10 {
			return
		}
	}

	// No final statement
	for test5 = 0; test5 < 10; {
		test5 += 1
	}

	// No first or second statement
	test6 = 0
	for ; ; test6 += 1 {
		if test6 >= 10 {
			return
		}
	}

	// No first or final statement, variable declared outside
	test7 = 0
	for test7 < 10 {
		test7 += 1
	}

	// No second or third statement
	for test8 = 0; ; {
		if test8 >= 10 {
			return
		}
		test8 += 1
	}

	// No statements, variable declared outside
	test9 = 0
	for {
		if test9 <= 10 {
			return
		}
		test9 += 1
	}

	// Only second statement, no variable (function call)
	for random() != 0 {
	}
}
