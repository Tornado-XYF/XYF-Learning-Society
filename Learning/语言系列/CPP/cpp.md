# C++ Primer 丐版

## 输出`std::count`

写法一：

```cpp
#include <iostream>

int main()
{
    std::cout<<"姓名：\n年龄：\n性别：\n体重：";
}
```

写法二：

```cpp
#include <iostream>

int main()
{
    std::cout<<"姓名："
             <<"年龄："
             <<"性别："
             <<"体重：";
}//缩进不影响
```

写法三：

```cpp
#include <iostream>

int main()
{
    
    std::cout<<"姓名："
             <<std::endl //换行
             <<"年龄："
             <<"性别："
             <<"体重："; 
}
```

写法四

```cpp
#include <iostream>
using namespace std; //使用std命名空间，即可以省略std::
int main()
{
    cout<<"姓名："
        <<endl //换行
        <<"年龄："
        <<"性别："
}
```

C++给变量赋值后，可以用变量名直接代替值输出

```c++
#include <iostream>
using namespace std; //使用std命名空间，即可以省略std::
int main()
{
    string name = "张三";
    int age = 20;
    char sex = 'X';
    double weight = 70.5;
    cout<<"姓名： "
        <<name
        <<"\n年龄： "
        <<age
        <<"\n性别： "
        <<sex
        <<"\n体重： "
        <<weight; 
}
```

## STL组件

STL组件有:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器