package main

import (
	"bufio"
	"fmt"
	"math"
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

	max := math.Max(float64(first), float64(second))
	min := math.Min(float64(first), float64(second))

	fmt.Println(int(min), int(max))
}
