package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	line, _ := reader.ReadString('\n')
	lineSplit := strings.Split(strings.TrimSpace(line), " ")

	first, _ := strconv.Atoi(lineSplit[0])
	second, _ := strconv.Atoi(lineSplit[1])

	fmt.Println((float64(first) * float64(second)) / 2.0)
}
