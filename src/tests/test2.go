// This tests a sample virtual pet type
package main

import "fmt"

type pet struct {
	hunger int
	happy  int
}

func play(p pet) {
	var choice int
	fmt.Println("What should we play?")
	fmt.Println("Fetch (1) \n Roll over (2)")
	// fmt.Scan(&choice);
	choice = 2
	if choice == 1 {
		fmt.Println("Fetch, eh")
		p.happy += 10
	} else if choice == 2 {
		fmt.Println("Roll over?  Really?")
		p.hunger += 1
	}
}

func main() {
	var myDog pet
	play(myDog)
}
