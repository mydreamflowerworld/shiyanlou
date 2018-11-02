package main

import "fmt"
import "time"

func main() {
	p := fmt.Println  //p是别名
	now := time.Now() //得到当前时间
	p(now)

	then := time.Date(
		2018, 9, 16, 19, 48, 58, 651387237, time.UTC)
	p(then)
	//提取时间的各个组成部分
	p(then.Year())
	p(then.Month())
	p(then.Day())
	p(then.Hour())
	p(then.Minute())
	p(then.Second())
	p(then.Nanosecond())
	p(then.Location())

	p(then.Weekday())
	//输出星期
	p(then.Before(now))
	p(then.After(now))
	p(then.Equal(now))
	//方法Sub返回一个`Duration`来表示两个时间点的时间间隔
	diff := now.Sub(then)
	p(diff)
	//计算不同单位下的时间长度值
	p(diff.Hours())
	p(diff.Minutes())
	p(diff.Seconds())
	p(diff.Nanoseconds())
	//使用Add将时间后移一个时间间隔或者使用-来将时间前移一个时间间隔
	p(then.Add(diff))
	p(then.Add(-diff))
}
