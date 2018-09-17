//SHA散列
package main

import "crypto/sha1"
import "fmt"

func main() {
	s := "sha1 this string"
	//产生散列值的方式
	h := sha1.New()
	//写入要处理的字节
	h.Write([]byte(s))
	//得到最终散列值的字符切片
	bs := h.Sum(nil)

	fmt.Println(s)
	fmt.Printf("%x\n", bs) //%x是将散列结果格式化为16进制字符串
}
