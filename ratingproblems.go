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

	line, _, _ := reader.ReadLine()
	lineSplit := strings.Split(strings.TrimSpace(string(line)), " ")

	first, _ := strconv.Atoi(lineSplit[0])
	second, _ := strconv.Atoi(lineSplit[1])

	nums := 0

	for i := 0; i < second; i++ {
		line, _, _ := reader.ReadLine()
		num, _ := strconv.Atoi(string(line))

		println(num)
		nums += num
	}

	lowest := float64(((first - second) * -3) + nums)
	highest := float64(((first - second) * 3) + nums)

	fmt.Println(lowest/float64(first), highest/float64(first))
}
