package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("hello world!")
	for x, _ := range []string{"a", "b"} {
		fmt.Println(x)
	}
	os.Exit()
}
