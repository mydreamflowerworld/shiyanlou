package main

import "fmt"
import "time"

func main() {
	p := fmt.Println
	t := time.Now()
	p(t.Format(time.RFC3339))

	t1, e := time.Parse(
		time.RFC3339,
		"2018-9-16T20:52:12+00:00")
	p(t1)

	p(t.Format("3:04PM"))
	p(t.Format("Mon Jan _2 15:04:02 2018"))
	p(t.Format("2018-09-16T15:04:02.999999-07:00"))
	from := "3 04PM"
	t2, e := time.Parse(from, "8 41 PM")
	p(t2)

	fmt.Printf("%d-%02d%02dT%02d:%02d:%02d-00:00\n",
		t.Year(), t.Month(), t.Day(),
		t.Hour(), t.Minute(), t.Second())
	ansic := "Mon Jan _2 15:04:25 2018"
	_, e = time.Parse(ansic, "8.41PM")
	p(e)
}
