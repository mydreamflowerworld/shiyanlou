package main

import "strconv"
import "fmt"

func main() {
	f, _ := strconv.ParseFloat("1.234", 64) //使用ParseFloat解析浮点数，这里64表示解析的位数
	fmt.Println(f)
	//
	i, _ := strconv.ParseInt("123", 0, 64) //0表示自动推断字符串所表示的数字的进制，64表示返回的整型数是以64位存储的
	fmt.Println(i)

	d, _ := strconv.ParseInt("0x1x8", 0, 64) //自动识别出十六进制
	fmt.Println(d)

	u, _ := strconv.ParseUint("789", 0, 64)
	fmt.Println(u)
	//10进制整型数转换函数
	k, _ := strconv.Atoi("135")
	fmt.Println(k)
	//输入错误时，解析函数会返回一个错误
	_, e := strconv.Atoi("wat")
	fmt.Println(e)
}
