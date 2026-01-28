# GoLang !!!/

## Print和Println

Println 会在输出的字符串末尾添加一个换行符,在输出多个字符串时,每个字符串之间会添加一个空格
Print 不会在输出的字符串末尾添加换行符，在输出多个字符串时,每个字符串之间不会添加空格
Printf 会根据格式化字符串输出对应的内容
如:

```go
package main

import (
    "fmt"
)

func main() {
    fmt.Printf("hello %s", "golang")
}   
```

### 使用Printf 打印变量类型

```go
package main

import (
    "fmt"
)

func main() {
    fmt.Printf("%T", 100)
}   
```

## 声明变量

1. var name 类型 = 值
2. var name 类型   name = 值
3. var name = 值

多次声明：
var(
    name0 类型
    name1 类型
    name2 类型
)
赋值时要和类型一致

短变量声明：
name := 值
==只适用于在函数内部声明局部变量，不能用于全局变量声明==

## 匿名变量（类似于Python的解包）

在接收函数返回值时,如果想要忽略某个值,可以使用匿名变量
如:

```go

func f() (int, string) {
    return 100, "hello"
}
var _, str = f()
fmt.Println(str)

```
