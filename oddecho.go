package main

import "fmt"

func main() {
	var numberOfWords int

	_, _ = fmt.Scanln(&numberOfWords)

	for i := 1; i < numberOfWords+1; i++ {
		var input string
		_, _ = fmt.Scanln(&input)

		if i%2 != 0 {
			fmt.Println(input)
		}
	}

}
