package main

import s "strings"
import "fmt"

var p = fmt.Println

func main() {
	p("Contains: ", s.Contains("test", "es")) //strings包里的函数
	p("Len:", len("hello"))
	p("Char:", "hello"[1]) //取字符的长度，101二进制，十进制为5
}
