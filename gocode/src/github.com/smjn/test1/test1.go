package main

import (
	"fmt"
	"net/http"
	"os"
)

func main() {
	os.Exit(1)
	fmt.Println("hello world!")
	for x, _ := range []string{"a", "b"} {
		fmt.Println(x)
	}
	http.NewRequest()
}
