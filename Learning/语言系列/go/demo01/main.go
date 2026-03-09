package main

import "fmt"
// func sum(s []int, c chan int){
// 		sum := 0
// 		for i,v := range s{
// 			fmt.Println("下标是:",i)
// 			sum += v
// 		}
// 		c <- sum 
// 	}
func fibonacci(c, quit chan int) {
    x, y := 0, 1
    for {
        select {
        case c <- x:
            x, y = y, x+y
        case <-quit:
            fmt.Println("quit")
            return
        }
    }
}
func main() {
    c := make(chan int)
    quit := make(chan int)

    go func() {
        for i := 0; i < 10; i++ {
            fmt.Println(<-c)
        }
        quit <- 0
    }()
    fibonacci(c, quit)
}
	// s := []int{7,2,8,-9,4,0}gin

	// c := make(chan int)
	// go sum(s[:len(s)/2],c)
	// go sum(s[len(s)/2:],c)
	// x, y := <-c, <-c //从通道C中接受
	// fmt.Println("x=",x," y=",y," x+y=", x+y)
	// // start := time.Now().Unix()
	// for i := 0; i < 5; i++{
	// 	wg.Add(1)
	// 	go test01(i)
	// }
 	// fmt.Println("执行完毕")
	// wg.Wait()
	// end := time.Now().Unix()
	// fmt.Println("总耗时:", end-start) //多线程之前是1毫秒

// func test01(n int){

// 	for num := (n-1)*30000 + 1; num < n *30000; num++{
// 		var flag = true
// 		for i := 2; i< num; i++{
// 			if num%i == 0{
// 				flag = false
// 				break
// 			}
// 		}
// 		if flag{
// 			// fmt.Println(num)
// 		}
// 	}
// 	wg.Done()
	
// }

