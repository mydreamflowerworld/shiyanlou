package main

//import "bytes"
import "fmt"
import "regexp"

func main() {
	//判断一个字符串是否符合一个表达式
	match, _ := regexp.MatchString("p([a-z]+)ch", "peach")
	fmt.Println(match)

	r, _ := regexp.Compile("p([a-z])ch")
	fmt.Println(r.MatchString("peach"))

}
