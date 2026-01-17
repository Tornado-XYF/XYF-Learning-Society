# C++ Primer 丐版

## 使用new在堆上分配内存

```cpp
int * func()
{
    //在堆上创建整形数据
    //new返回的是一个指向该数据的指针
    int * p = new int(10);
    return p;
    //堆区数据由程序员管理，需要手动释放
    //delete p;释放p
}
```

## 引用

引用是变量的别名，通过引用可以直接访问到变量所存储的数据。

```cpp
int a = 10;
int & b = a; //b是a的引用
b = 20; //a的值也会变成20
//！！！！！！！！！！！！！！！！！！！！注意事项！！！！！！！！！！！！！！！！！！！！！！！！
//1.引用必须初始化，不能引用空指针 int & a; //错误
//2.引用一旦初始化，就不能改变引用的对象 int & c = b; c不允许再更改 纯爱战士这一块
```

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

## for高级循环法

用法:

```cpp
for(元素类型 临时变量名 : 数组变量)
{
    临时变量存储一个个元素
}
```

如:

```cpp
int arr[] = {1,2,3,4,5};
for(int i : arr)
{

    cout<<i<<endl;
}
```

## STL组件

STL六大组件有:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
STL是C++标准库的一部分，提供了通用的容器、算法、迭代器等组件，用于简化和加速C++程序的开发。

容器:各种数据结构用来存放数据，如vector、list、deque、set、map等。
算法:各种常用算法，如sort、find、copy等。
迭代器:算法与容器之间的桥梁，用于遍历容器中的元素。
仿函数:一种行为类似函数的对象，可以作为算法的某种策略
适配器:一种用来修饰容器或者仿函数或迭代器接口的东西
空间适配器:负责空间的分配和管理，如内存池、缓存等。

容器分为:
序列式容器:强调值的排序，容器中的每个元素有固定的位置
关联式容器:二叉树结构,各元素之间没有严格的物理上的顺序关系

算法分为:
质变算法:会改变容器中元素的算法，如sort、copy等。
非质变算法:不会改变容器中元素的算法，如find、count等。

迭代器:容器和算法的粘合剂

## vector 容器

vector可以理解为数组。

容器：vector
算法：for_each
迭代器：`vector<int>::iterator`

### vector 容器存放内置数据类型

```cpp
#include <vector>
#include <algorithm> //标准算法头文件
void test01()
{
    //创建vector容器
    vector<int> v;

    //向容器中插入数据
    v.push_back(10);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); //起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end(); //结束迭代器，指向容器中最后一个元素的下一个位置

    //第一种遍历方式
    while(itBegin != itEnd)
       {
        cout<<*itBegin<<endl;
        itBegin++; //迭代器++，指向下一个元素
       }

    //第二种遍历方式
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl;
    }

    //第三种遍历方式
    void myPrint(int val)
    {
        cout<<val<<endl;
    }
    for_each(v.begin(),v.end(),myPrint);
}
```

### vector存放自定义数据类型

```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    Person(string name , int age)
    {
        this -> name = name;
        this -> age = age;
    }
    string name;
    int age;
};
void test01()
{
    vector<Person> v;
    //创建自定义数据类型的对象
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);

    //将对象插入容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //遍历
    for(vector<Person>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<
        "姓名："<<
        it->name<<
        "年龄： "<<
        it -> age<<
        endl;

    }
}
```

### vector容器嵌套容器

```cpp
void test01(){
   vector < vector<int>>v;
   //创建小容器
   vector<int>v1;
   vector<int>v2;
   vector<int>v3;

  //为小容器创建数据
   for(int i = 0; i < 3; i++)
   {
      v1.push_back(i+1);
      v2.push_back(i+2);
      v3.push_back(i+3);
   }

   //将小容器插入到大容器中
   v.push_back(v1);
   v.push_back(v2);
   v.push_back(v3);

   //通过大容器，将所有数据遍历
   for(vector< vector<int>> :: iterator it = v.begin() ; it != v.end();it++)
   {  //(*it)指的是 vector<int>类型容器 
      for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end();vit++)
      {
         cout<<*vit<<" ";
      }
      cout << endl;
   }
}
```

### vector的构造

```cpp
printVector(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout << endl;
}
void test01(){
    vector<int>v1; //默认构造 无参构造
    for(int i = 0; i < 10; i++)
    {
        v1.push.back(i);
    }

    printVector(v1);

    vector<int>v2(v1.begin(),v1.end()); //区间构造
    printVector(v2);

    vector<int>v3(10,100); //n个elem方式构造，10个元素，每个元素值为100
    printVector(v3);

    vector<int>v4(v3); //拷贝构造
}
```

### vector赋值操作

```cpp
void printVector(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
     cout << endl;
}
void test01(){
   vector<int>v1;
   for(int i = 0; i<10;i++)
   {
    v1.push_back(i);
   }
   printVector(v1);

   //赋值
   vector<int>v2;
   v2 = v1;
   printVector(v2);

   //assign赋值
   vector<int>v3;
   v3.assign(v1.begin(),v1.end());
   printVector(v3);

   //n个elem方式赋值
   vector<int>v4(10,100);
   printVector(v4);
}
```

### vector容量和大小相关操作

```cpp
void printVector(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
     cout << endl;
}
void test01()
{
   vector<int>v1;
   for(int i = 0; i < 10; i++)
   {
    v1.push_back(i);
   }

   if(v1.empty()) // 判断容器是否为空
   {
    cout<<"v1容器为空"<<endl;
    cout<<"v1容器容量为："<<v1.capacity()<<endl;
    cout<<"v1容器大小为："<<v1.size()<<endl;   //容量永远大于等于容器的大小，容量根据容器的大小动态变化，且不同操作系统和编译器所扩展的容量可能不同
   }
   else
   {
    cout<<"v1容器不为空"<<endl;
   }

   v1.resize(15,100); //重新指定容器大小,且设置100为默认填充值
   printVector(v1); //如果指定的大小大于当前容器大小，则用默认值填充

   v1.resize(5); //重新指定容器大小为5，超出的元素会被删除
   printVector(v1);
}
```

### vector容器插入和删除

```cpp
void printVector(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
     cout << endl;
}
void test01(){
    vector<int>v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    //尾删
    v1.pop_back();
    printVector(v1);

    //插入
    v1.insert(v1.begin(),100); //第一个参数为迭代器，指向插入位置，第二个参数为插入元素
    printVector(v1);

    v1.insert(v1.begin(),2,1000); //在begin位置插入2个100
    printVector(v1);

    //删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    //清空
    v1.clear();
    v1.erase(v1.begin(),v1.end()); //删除所有元素
    printVector(v1);
}
```

### vectot数据存取

```cpp
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    //利用[]访问元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout << endl;

     //利用at访问元素
    for(int i = 0; i < v1.size(); i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout << endl;

    //获取第一个元素
     cout<<"v1的第一个元素为："<<v1.front()<<endl;
    //获取最后一个元素
     cout<<"v1的最后一个元素为："<<v1.back()<<endl;
}
```

### vector互换容器

```cpp
void printVector(vector<int>v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
     cout << endl;
}
void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    for(int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    //交换前
     cout<<"交换前"<<endl;
     printVector(v1);
     
     //交换后
     cout<<"交换后"<<endl;
     v1.swap(v2);
     printVector(v1);
     printVector(v2);

     
}
//实际用途
//巧用swap可以收缩内存空间
void test02(){
     vector<int>v1;
    for(int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
    }
    cout<<"v1容器的容量为："<<v1.capacity()<<endl;
    cout<<"v1容器的大小为："<<v1.size()<<endl;

    v1.resize(3);
    cout<<"v1容器的容量为："<<v1.capacity()<<endl;
    cout<<"v1容器的大小为："<<v1.size()<<endl;
}     
```

### vector预留空间

减少vector扩展次数，提高效率

```cpp
void test01(){
    vector<int>v1;

    //reserve预留空间
    v.reserve(100000);
    int num = 0 ; //统计开辟次数
    int *p = NULL;

for(int i = 0; i < 100000; i++)
    {
        v1.push_back(i);

        if(p != $v[0])
        {
            p = &v1[0]; //每次开辟内存其实就是换了一个更大的新容器，所以地址会改变，并不是在原先的地址上扩展
            num++;
        }

    }
}
```

## string容器

### string类的创建

```cpp
#include <string>

void test01()
{
   string s1;   //1.创建空字符串
   const char* str = "hello world";   //2.使用字符串str初始化
   
   string s2(str);
   string s3(s2);   //3.使用一个string对象初始化另一个string对象
   cout<< "s2 = " << s2 << endl;
   cout<< "s3 = " << s3 << endl;
   
   string s4(10 , 'a');  //4.使用n个字符a初始化
   cout << "s4 = "<< s4 << endl;
}
```

### 赋值操作

```cpp
void test01()
{
   string str1;
   str1 = "hello world"; //1.直接赋值char* 类型的字符串
   cout<<"str1 = "<<str1<<endl;

   string str2;
   str2 = str1; //2.同类型字符串传递赋值
   cout<<"str2 = "<<str3<<endl;
   
   string str3;
   str3 = 'a';   //3.单字符赋值
   cout<<"str3 = "<<str3<<endl;

   string str4;
   str4.assign("hello cpp");   //4.使用string类方法assign添加字符串
   cout<<"str4 = "<<str4<<endl;

   string str5;
   str5.assign("hello C++",5); //5.把字符串字符hello C++ 前5个字符赋值给当前字符串
   cout<<"str5 = "<<str5<<endl;

   string str6;
   str6.assigh(str5) //6.利用assign方法添加字符串
   cout<<"str6 = "<<str6<<endl;

   string str7;
   str7.assign(10,w) //7
   cout<<"str7 = "<<str7<<endl;


}
```

### string字符串拼接

```c++
#include <string>
void test01(){
    string str1 = "我"；

    str1 += "爱玩游戏"; // 1.字符串拼接
    cout<<"str1 = "<<str1<<endl;

    str1 += ';'; //2.字符拼接

     cout<<"str1 = "<<str1<<endl;

    string str2 = "LOL CF";
     str1 += str2; //3.字符串拼接
     cout<<"str1 = "<<str1<<endl;

    string str3 = "I";
    str3.append("love"); //4.append方法拼接
     cout<<"str3 = "<<str3<<endl;

    str3.append("game abcde",4); //5.append方法，将字符串的前4个字符拼接到str3中
     cout<<"str3 = "<<str3<<endl;

    str3.append(str2,0,3); //6.append方法，拼接已经存在的字符串str2的第0个字符开始截取，截取3个字符
     cout<<"str3 = "<<str3<<endl;

}
```

### string查找和替换

```cpp
//查找
void test01()
{
    string str1 = "abcde";
    
    int pos = str1.find("de"); //查找子字符串"de"第一次出现的位置
    cout<<"pos = "<<pos<<endl; //检验pos的值，对应查找字符串的索引

    if(pos == -1)
    {
        cout<<"未找到该字符或者字符串"<<endl;
    }

    //rfind

    pos = str1.rfind("de"); //查找子字符串"de"最后一次出现的位置,即从后往前查找
    cout<<"pos = "<<pos<<endl; //检验pos的值，对应查找字符串的索引
}

//替换
void test02(){
    string str1 = "abcde";
    str1.replace(1,3,"1111"); //将str1从索引1开始的3个字符替换为"1111",这里四个1111都会替换进去
    cout<<"str1 = "<<str1<<endl;
}
```

### string字符串比较

==string的比较是按照字符的ASCII码值进行比较的==

```cpp
//字符串比较
void test01(){
    string str1 = "hello";
    string str2 = "hello";
    //可以通过修改这两个字符串的个别字符，来改变它们的ASCII码值，从而改变它们的比较结果
    if(str1.compare(str2) == 0)
    {
        cout<<"str1和str2相等"<<endl;
    }
    else if(str1.compare(str2) > 0)
    {
        cout<<"str1大于str2"<<endl;
    }
    else
    {
        cout<<"str1小于str2"<<endl;
    }
}
```

### string字符串存取

```cpp
void test01()
{
    string str1 = "hello"

    cout<<"str1 = "<<str1<<endl;

    //1.通过[]访问单个字符
    for(int i = 0; i < str1.size(); i++)
    {
        cout<<str1[i]<<" ";
    }
    cout<<endl;

    //2.通过at方式访问单个字符
    for(int i = 0; i < str1.size(); i++)
    {
        cout<<str.at(i)<<" ";
    }
    cout<<endl;

    //修改单个字符
    str1[0] = 'x'; //xello
    str1.at(1) = 'y'; //xyllo
}
```

### string字符串插入和删除

```cpp
//插入
void test01()
{
    string str1 = "hello";

    //插入
    str.insert(1,"111"); //h111ello
    cout<<"str1 = "<<str1<<endl;

    //删除
    str.erase(1,3); //删除第1个到第3个字符：hello
    cout<<"str1 = "<<str1<<endl;
}
```

### string截取子串

```cpp
void test01()
{
    string str1 = "abcdef";

    string subStr = str1.substr(1,3); //从索引1开始截取3个字符,重点是3个，是个数不是索引：bcd
    cout<<"subStr = "<<subStr<<endl;
}

//实用操作
void test02(){
    string email = "xyf23232@qq.con";

    //从邮件地址中获取用户名信息

    int pos = email.find("@"); //查找@符号的位置
    string userName = email.substr(0,pos)；
     cout<<"userName = "<<userName<<endl;
}
```

## deque容器

与vector容器不同，deque容器是双端队列，它的元素可以从两端进行插入和删除操作。
区别：

1. vector对于头部的插入删除效率低，数据量越大，效率越低
2. deque容器对于头部的插入删除操作效率高。
3. vector访问元素时的速度比deque快

### deque构造函数

```cpp
#include<iostream>
using namespace std;


//deque构造函数
void printDeque(deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
    //使用const_iterator遍历deque容器，避免修改容器元素
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    deque<int> d1; //默认构造函数
    for(int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
}
```

### deque赋值操作

由于与vector容器的赋值操作相似，所以这里不再提供案例。

赋值操作：

1. “=”赋值
2. assign()方法赋值

### deque大小操作

1. deque.empty() //判断deque容器是否为空
2. deque.size() //返回deque容器的元素个数，注意：deque容器没有容量概念，这也是与vector容器的主要区别
3. deque.resize(num) //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
4. deque.resize(num,elem) //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

### deque插入和删除操作

```cpp
void printDeque(deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
    //使用const_iterator遍历deque容器，避免修改容器元素
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    //两端操作
    deque<int>d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1); //200 100 10 20

    //尾删
    d1.pop_back();
    printDeque(d1); //200 100 10

    //头删
    d1.pop_front();
    printDeque(d1); //100 10
}

void test02(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1); //200 100 10 20

    //insert插入
    d1.insert(d1.begin(),1000);
    printDeque(d1); //1000 200 100 10 20

    d1.insert(d1.begin(),2,10000);
    printDeque(d1); //10000 10000 1000 200 100 10 20

    //按照区间进行插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end()); //在d1.begin()位置插入d2.begin()到d2.end()的所有元素
    printDeque(d1); //1 2 3 10000 10000 1000 200 100 10 20
}

void test03(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1); //200 100 10 20

    //erase删除
    deque<int>::iterator it = d1.begin();
    it++; //将迭代器往后偏移，指定删除位置
    d1.erase(it);
    printDeque(d1); //200 10 20

    //删除区间内的元素
    d1.erase(d1.begin(),d1.end());
    printDeque(d1); //空

    //清空
    d1.clear();
    printDeque(d1); //空
}
```

### deque数据存取

1.deque.at() //返回索引index所指的数据
2.deque.front() //返回容器第一个元素
3.deque.back() //返回容器最后一个元素
4.deque[ ] //返回索引index所指的数据

### deque排序操作

```cpp
#include<algorithm> //算法头文件
void printDeque(deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
    //使用const_iterator遍历deque容器，避免修改容器元素
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1); //300 200 100 10 20 30

    //排序
    //对于支持随机访问的迭代器的容器都支持dort算法排序
    sort(d1.begin,d1.end) //默认排序规则从小到大升序
    printDeque(d1); //10 20 30 100 200 300
}
```

## stack容器

栈是一种先进后出的数据结构，==不允许遍历==

### stack常用接口

```cpp
#include<stack>

void test01(){
    stack<int>s;

    //入栈
    s.push(10);

    while(!s.empty()) //当栈不是空时
    {
        cout<<s.top()<<endl;   //查看栈顶元素
        s.pop();   //出栈
    }

    cout<<"栈的大小为："<<s.size()<<endl; //s.size()返回栈的大小
}
```

## queue容器

队列容器，先进先出，只有队头和队尾可以进行操作，无法遍历

### queue常用接口

```cpp
#include<queue>
#include<string>
class Person{
public:
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

void test01(){
    //创建队列
    queue<Person>q;

    //准备数据
    Person p1("唐僧"，30)；
    Person p2("孙悟空"，1000);
    Person p3("猪八戒"，900);
    Person p4("沙僧"，800);

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout<<"队列的大小为："<<q.size()<<endl;
    //判断队列不为空
    while(!q.empty())
    {
        //查看队头元素
        cout<<"队头元素为："<<q.front().name<<" "<<q.front().age<<endl;
        //查看队尾元素
        cout<<"队尾元素为："<<q.back().name<<" "<<q.back().age<<endl;
        //出队
        q.pop();
    }
}
```

## list容器

list是一个链表容器

### list构造函数

```cpp
#include<list>
void printList(const list<int>&l)
{
    for(list<int>::const_iterator it = l.begin();it != l.end();it++)
    //使用const_iterator遍历list容器，避免修改容器元素
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    //创建list容器
    list<int>l1;

    //添加数据
    l1.push_back(10):
    l1.push_back(20)

    //区间方式构造
    list<int>l2(l1.begin(),l1.end());
    printList(l2); //10 20

    //拷贝构造
    list<int>l3(l2);
    printList(l3); //10 20

    //n个elem构造
    list<int>l4(4,100);
    printList(l4); //100 100 100 100
}
```

### list赋值和交换

与之前学习的vector容器赋值和交换操作类似，不给例子：

1. "="赋值操作
2. assign(beg,end) //将[beg,end]区间内的元素赋值给list容器
3. assign(n,elem) //将n个elem赋值给list容器

交换两个容器的数据
`list1.swap(list2);`

### list大小操作

1. list.empty() //判断list容器是否为空
2. list.size() //返回list容器的元素个数
3. list.resize(num) //重新指定list容器的元素个数为num,如果num大于当前容器元素个数,则用默认值填充
4. list.resize(num,elem) //重新指定list容器的元素个数为num,如果num大于当前容器元素个数,则用elem填充

### list插入和删除

1. push_back(elem); //在容器尾部加入一个元素
2. pop_back; //删除容器最后一个元素
3. push_front(elem); //在容器头部加入一个元素
4. pop_front(); //删除容器第一个元素
5. insert(pos,elem) //在pos位置插入elem元素的拷贝，返回新数据的位置
6. insert(pos,n,elem) //在pos位置插入n个elem元素的拷贝，无返回值
7. insert(pos,beg,end); //在pos位置插入[beg,end]区间内的元素的拷贝，无返回值
8. clear() ; //清空
9. erase(beg,end); //删除[beg,end]区间内的元素，返回下一个元素的位置
10. erase(pos); //删除pos位置的元素，返回下一个元素的位置
11. remove(elem); //删除容器中所有与elem值匹配的元素

### list数据存取

list是链表结构，不能用`list[0]`和`list.at()`访问元素，迭代器也不支持随机访问,只能`+1`或者`-1`操作迭代

存取方式：

1. list.front() //返回第一个元素
2. list.back() //返回最后一个元素

### list反转和排序

```cpp
#include<list>
#include<algorithm>
void printList(const list<int>&l)
{
    for(list<int>::const_iterator it = l.begin();it != l.end();it++)
    //使用const_iterator遍历list容器，避免修改容器元素
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    //反转
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    
    L1.reverse(); //反转操作
    printList(L1); //30 20 10
}

void test02(){
    //排序
    list<int>L2;
    L2.push_back(10);
    L2.push_back(20);
    L2.push_back(30);
    L2.push_back(40);

    //所有不支持随机访问迭代器的容器，不可以用标准算法，但是其内部会有对应算法
    L2.sort(); //默认排序规则，从小到大
    printList(L2); //10 20 30 40

    //降序实现
    //首先设置一个bool函数
    bool myCompare(int v1,int v2)
    {
        return v1 > v2;
    }
    L2.sort(myCompare); //降序排序
    printList(L2); //40 30 20 10
}
```

### list排序案例

```cpp
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

class Person
{
public:
Person(string name,int age,int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string name;
    int age;
    int height;
};

bool comparePerson(Person &p1,Person &p2) //指定排序规则
{
    //按照年龄升序排列
    if(p1.age == p2.age)
    {
        return p1.height > p2.height; 
        //年龄相同,按身高降序排列
    }
    return p1.age < p2.age;
} //根据年龄排序,升序

void test01()
{
    list<Person>L1;

    //准备数据
    Person p1("刘备",35,175);
    Person p2("关羽",34,178);
    Person p3("张飞",33,172);
    Person p4("赵云",32,170);

    //插入数据
    L1.push_back(p1);
    L1.push_back(p2);
    L1.push_back(p3);
    L1.push_back(p4);

    for(list<Person>::iterator it = L1.begin();it != L1.end();it++)
    {
        cout<<"姓名："<<it->name<<" 年龄："<<it->age<<" 身高："<<it->height<<endl;
    }

    //排序-----------------
    cout<<"-----------------"<<endl;

    //自定义类型要指定排序规则

    
    L1.sort(comparePerson);
}
```

## set和multiset容器以及区别

set和multiset属于关联式容器，底层结构为二叉树
区别为：
set容器不允许容器中有重复的元素
set插入数据的同时会返回插入结果，表示插入是否成功
multiset容器允许容器中有重复的元素

```cpp
void test01()
{
    set<int>s;

    pair<set<int>::iterator,bool>ret = s.insert(10); //set插入会返回一个pair类型的对象，
    //first成员是一个迭代器，指向插入的元素
    //second成员是一个bool值，表示插入是否成功
    if(ret.second)
    {
        cout<<"插入成功"<<endl;
    }
    else
    {
        cout<<"插入失败"<<endl;
    }

    ret = s.insert(10); //set容器不允许插入重复元素
    if(ret.second)
    {
        cout<<"插入成功"<<endl;
    }
    else
    {
        cout<<"插入失败"<<endl;
    }
}
```

### set容器构造和赋值

```cpp
#include<set>

void printSet(set<int>&s)
{
    for(set<int>::iterator it = s.begin();it != s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    set<int>s1;

    //插入数据只有insert()方法
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30); //set容器不允许插入重复元素

    //容器特点：
    //所有元素都会在插入时自动被排序
    //set容器不允许有重复的元素
    //multiset容器允许有重复的元素
    printSet(s1); //10 20 30 40

    //拷贝构造
    set<int>s2(s1);
    printSet(s2); //10 20 30 40
}
```

### set容器大小和交换

1. set.empty() //判断容器是否为空
2. set.size() //返回容器中元素的个数
3. set.swap(s2) //交换s1和s2容器的元素

### set容器的插入和删除

1. set.insert(elem) //在容器中插入元素
2. set.clear() //清空容器所有元素
3. set.erase(s1.begin()); //删除pos迭代器所指的元素，返回下一个元素的迭代器
4. set.erase(beg,end); //删除[beg,end]区间内的元素，返回下一个元素的位置
5. set.erase(elem); //删除容器中所有与elem值匹配的元素

### set查找和统计

```cpp
void printSet(set<int>&s)
{
    for(set<int>::iterator it = s.begin();it != s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    printSet(s1); //10 20 30 40

    //查找find(key),返回值是一个迭代器，指向key值的元素，如果未找到，返回end()迭代器
    set<int>::iterator it = s1.find(30);
    if(it != s1.end())
    {
        cout<<"找到元素："<<*it<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }

    //统计count(key)
    int num = s1.count(30);
    cout<<"30的个数为："<<num<<endl;
}
```

### pair对组创建和使用

```cpp
#include<iostream>
#include<string>
using namespace std;
void test01()
{
    //第一种方式
    pair<string,int>p1("张三",18);
    cout<<"姓名："<<p1.first<<" 年龄："<<p1.second<<endl;

    //第二种方式
    pair<string,int>p2 = make_pair("李四",20);
    cout<<"姓名："<<p2.first<<" 年龄："<<p2.second<<endl;
}
```

### set容器的排序

利用仿函数改变排序规则

```cpp
//存放已有数据类型

class MyCompare //仿函数
{
public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2;
    }
}
void printSet(set<int>&s)
{
    for(set<int>::iterator it = s.begin();it != s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int>s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    printSet(s1); //10 20 30 40
    
    //指定排序规则从大到小

    set<int,MyCompare>s2; 
    //数据插入以后就已经确定顺序了
    //利用仿函数指定排序规则为从大到小
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);

    for(set<int,MyCompare>::iterator it = s2.begin();it != s2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//存放自定义数据类型
class Person
{
public:
    Person(string name,int age,int height)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
}

class comparePerson
{
public:
    bool operator()(const Person&p1,const Person&p2)
    {   //按照年龄降序
        return p1.age > p2.age;
    }
}
void test02()
{
    set<Person,comparePerson>s3;
    Person p1("张三",18);
    Person p2("李四",20);
    Person p3("王五",22);

    //自定义数据类型都会指定排序规则
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);

    for(set<Person,comparePerson>::iterator it = s3.begin();it != s3.end();it++)
    {
        cout<<"姓名："<<it->name<<" 年龄："<<it->age<<endl;
    }
}
```001232223456

## map容器

map中的所有元素都为`pair`,`pair`中第一个元素为键值，第二个元素为值

==所有元素都会根据元素的键值自动排序==

map/multimap属于关联式容器，底层结构是用二叉树实现

与multimap的区别:

map不允许有重复的key值
multimap允许有重复的key值

### map的构造和赋值

```cpp
#include<iostream>
#include<map>
using namespace std;

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        cout<<"key: "<<it->first<<"value: "<<it->second<<endl;
    }
}
void test01()
{
    //默认构造
    map<int,int>m;

    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));

    printMap(m);

    //拷贝构造
    map<int,int>m2(m);
    printMap(m2);

    //赋值
    map<int,int>m3;
    m3 = m2;
    printMap(m3);
}
```

### map的大小和交换

1. map.size(); //返回容器中元素数目
2. map.empty(); //判断容器是否为空
3. map.swap(m2); //交换m和m2的元素

### map的插入和删除

```cpp
void test01()
{
    //插入
    map<int,int>m;

    //第一种方式
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));

    //第二种方式
    m.insert(make_pair(4,40));

    //第三种方式
    m.insert(map<int,int>::value_type(5,50));

    //第四种
    m[6] = 40; //不建议，因为如果key不存在，会插入一个新的元素，值为0

    //删除
    m.erase(3); //删除key为3的元素

    m.erase(m.begin()); //按照迭代器删除,并返回下一个元素的迭代器
    m.erase(m.begin(),m.end()); //按照区间删除
    m.clear(); //清空
}
```

### map的查找和统计

1. map.find(key); //查找key是否存在，若存在，返回该键的迭代器；若不存在，返回map.end()
2. map.count(key); //统计key的元素个数，map为0或1，multimap为0或大于1

```cpp
map<int,int>::iterator it = m.find(1); //用一个迭代器接收find的返回值
if(it != m.end())
{
    cout<<"找到元素key："<<it->first<<"value: "<<it->second<<endl;
}
else
{
    cout<<"未找到元素"<<endl;
}
```

### map排序

利用仿函数改变排序规则

```cpp
#include<iostream>
#include<map>
using namespace std;

class MyCompare //构造仿函数
{
public:
    bool operator()(int m1,int m2)
    {
        return m1 > m2;
    }
}
void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        cout<<"key: "<<it->first<<"value: "<<it->second<<endl;
    }
}
void test01()
{
    map<int,int>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(make_pair(5,50));

    printMap(m);//默认排序规则为key值从小到大

    //指定排序规则从大到小
    map<int,int,MyCompare>m2(m);
    for(map<int,int,MyCompare>::iterator it = m2.begin();it != m2.end();it++)
    {
        cout<<"key: "<<it->first<<"value: "<<it->second<<endl;
    }
}
```

## 函数对象

本质上是一个类，行为类似函数调用，也可以称为仿函数

### 函数对象的使用

可以像普通函数那样去调用，有参数和返回值
可以作为参数传递

```cpp
#include<iostream>
#include<string>
using namespace std;

class MyAdd
{
public:
 int operator()(int v1,int v2)
 {
    return v1+v2;
 }
};

//1.像普通函数一样调用
void test01()
{
    MyAdd myAdd:
    cout << myAdd(10,10)<< endl;
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
   MyPrint()
   {
    this->count = 0;
   }
   void operator()(string test)
   {
    cout<<test<<endl
    this->count++;
   }

   int count; //内部自己的状态
};

void test02()
{
    MyPrint myPrint;
    myPrint("hello world");

    cout<<"调用次数："<<myPrint.count<<endl;
}

//3.函数对象可以作为参数传递
void doPrint(MyPrint& mp, string)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint,"hello c++");
}

int main()
{
    test01();

    system("pause");
    return 0;
}
```

## 谓词

返回bool类型的仿函数称为谓词
如果operator()接受一个参数，那么叫做一元谓词
如果operator()接受两个参数，那么叫做二元谓词

```cpp
#include<iostream>
#include<string>
using namespace std;

//一元谓词

class GreaterFive
{
public:
    bool operator()(int val)
    {

    }
}
void test01(){
    vector<int>v1;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i);
    }

    //查找容器中有没有大于5的数字
    vector<int>::iterator it = find.if(v.begin(),v.end(),GreaterFive()); //find方法的返回值要用迭代器接收
    if(if == v.end)
    {
        cout<<"未找到大于5的数字"<<endl;
    }
    else
    {
        cout<<"找到大于5的数字："<<*it<<endl;
    }
}

//二元谓词

class MyCompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2; // 大于为true，小于为false
    }
};
void test02()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    sort(v.begin(),v.end()); //默认排序规则为从小到大

    sort(v.begin(),v.end(),MyCompare()); //指定排序规则为从大到小
}
```

## 内建函数对象

### 算术仿函数

实现四则运算
negate是一元运算，其他为二元运算

```cpp
template<class T> T plus<T>   //加法仿函数
template<class T> T minus<T>   //减法仿函数
template<class T> T multiplies<T>   //乘法仿函数
template<class T> T divides<T>   //除法仿函数
template<class T> T modulus<T>   //取模仿函数
template<class T> T negate<T>   //取反仿函数
```

```cpp
#include<iostream>
#include<functional>
using namespace std;

//negate 一元仿函数 取反仿函数
void test01()
{
    negate<int>n;

    cout<<n(50)<<endl;
}

//plus 二元仿函数 加法仿函数
void test02()
{
    plus<int>p;
    cout<<p(10,20)<<endl;
} 
```

### 关系仿函数

```cpp
template<class T> bool greater<T>   //大于仿函数
template<class T> bool greater_equal<T>   //大于等于仿函数
template<class T> bool less<T>   //小于仿函数
template<class T> bool less_equal<T>   //小于等于仿函数
template<class T> bool equal_to<T>   //等于仿函数
template<class T> bool not_equal_to<T>   //不等于仿函数
```

```cpp
class MyCompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2; // 大于为true，小于为false
    }
};
void test01()
{   
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    //sort(v.begin(),v.end(),MyCompare()); //指定排序规则为从大到小
    sort(v.begin(),v.end(),greater<int>()); //默认排序规则为从大到小,greater<int>()为内建函数对象
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl ;
    }
    cout<<endl;
}
```

### 逻辑仿函数

```cpp
template<class T> bool logical_and<T>   //逻辑与仿函数
template<class T> bool logical_or<T>   //逻辑或仿函数
template<class T> bool logical_not<T>   //逻辑非仿函数
```

```cpp
void test01()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for(vector<bool>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl ;
    }
    cout<<endl;

    //利用逻辑非 将容器v搬运到容器v2中，并取反
    vector<bool>v2;
    v2.resize(v.size()); //先给v2分配空间

    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>()); //搬运区间实施取反操作
    for(vector<bool>::iterator it = v2.begin();it != v2.end();it++)
    {
        cout<<*it<<endl ;
    }
    cout<<endl; 
}
```

## 常用算法及函数

主要由头文件`<algorithm>，<numeric>，<functional>`等组成

### max求最大值

max(10,20); //返回20

### for_each

```cpp
#include <algorithm>
void print01(int val)
{
    cout<<val<<endl;
}

//仿函数
class MyPrint
{
public:
    void operator()(int val)
    {
        cout<<val<<endl;
    }
};
int main(){
    vector<int>v;
    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);

    for_each(v.begin(),v.end(),MyPrint());
}
```

### transform搬运

```cpp
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
    vector<int>v1;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i);
    }
    vector<int>v2;
    
    v2.resize(v1.size());//一定记得先要给v2分配空间！！！！！！！！！！！！！！！！！

    transform(v1.begin(),v1.end(),v2.begin(),negate<int>());//搬运区间实施取反操作
    for(vector<int>::iterator it = v2.begin();it != v2.end();it++)
    {
        cout<<*it<<endl ;
    }
    cout<<endl; 
}
```

### 查找算法find

```cpp
#include <algorithm>
#include <vector>
using namespace std;
#include <string>
void test01()
{
    vector<int>v;
    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find(v.begin(),v.end(),5); //查找5
    if(it == v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到："<<*it<<endl;
    }
}

//查找自定义数据类型
class Person{
public:
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person& p)
    {
        if(this->name == p.name && this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string name;
    int age;
};
void test02()
{
    vector<Person>v;
    Person p1("张三",18);
    Person p2("李四",20);
    Person p3("王五",22);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //vector<Person>::iterator it = find(v.begin(),v.end(),p3);这样写会报错，因为find函数无法直接比较自定义数据类型
    //需要自己定义一个仿函数，或者重载运算符==
    vector<Person>::iterator it = find(v.begin(),v.end(),p3);
    if(it == v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到："<<it->name<<endl;
    }
}

```

### find_if

按条件查找

```cpp
#include <algorithm>
#include <vector>
using namespace std;
#include <string>
class MyCompare
{
public:
    bool operator()(int v1)
    {
        return v1 > 5; // 大于为true，小于为false
    }
};
void test01()
{
    vector<int>v;
    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),MyCompare()); //查找大于5的第一个元素
    if(it == v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到："<<*it<<endl;
    }
}
```

### 查找相邻重复元素adjacent_find

```cpp
#include <algorithm>
#include <vector>
using namespace std;
#include <string>
void test01()
{
    vector<int>v;
    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }
    v.push_back(5);
    v.push_back(5);
    
    vector<int>::iterator pos = adjacent_find(v.begin(),v.end()); //会返回相邻两个重复元素前一个元素的迭代器
    if(pos == v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到："<<*pos<<endl;
    }
}
```

### 查找是否存在元素binary_search

==无序容器不支持binary_search==

原型:

```cpp
bool binary_search(iterator first,iterator last,const T& value); //返回一个bool值
```

### count统计元素个数

原型:

```cpp
int count(iterator first,iterator last,const T& value); //返回一个int值
```

### count_if统计符合条件的元素个数

原型:

```cpp
int count_if(iterator first,iterator last,条件); //返回一个int值
```

### 排序算法

```cpp
//sort
sort(v.begin(),v.end()); //默认排序规则为升序,参数为迭代器

sort(v.begin(),v.end(),greater<int>()); //降序排序,也可以自定义排序规则，如自定义一个仿函数
```

### 洗牌算法random_shuffle

```cpp
srand((unsigned int)time(NULL)); //随机数种子,需要包含头文件<ctime>,否则每次运行结果都一样
random_shuffle(v.begin(),v.end()); //随机打乱容器中的元素
```

### 合并算法merge

==两个容器必须都是有序的==

```cpp
vector<int>v3;

v3.resize(v1.size() + v2.size()); //合并后的容器大小为两个容器大小之和
// ！！！！！！！！！！！！！！！！一定要提前分配好v3的空间！！！！！！！！！！！！！！！！！！！！


merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); //合并两个有序容器v1和v2,并将结果存储在v3中
```

### 反转算法reverse

```cpp
reverse(v.begin(),v.end()); //反转容器中的元素
```

### 拷贝和替换算法copy和replace

```cpp
vector<int>v2(v1.size()); //提前分配好v2的空间

copy(v1.begin(),v1.end(),v2.begin()); //将容器v1中的元素拷贝到容器v2中

replace(v.begin(),v.end(),5,100); //将容器v中的所有5替换为100
```

### 条件替换算法replace_if

```cpp
replace_if(v.begin(),v.end(),MyCompare(),100); //将容器v中所有大于5的元素替换为100,MyCompare()为一个仿函数,用于判断是否大于5
```

### 算术生成算法accumulate

```cpp
#include <numeric>
using namespace std;
//accumulate
int sum = accumulate(v.begin(),v.end(),0); //将容器v中的元素累加起来,初始值为0
```

### 填充算法fill

```cpp
fill(v.begin(),v.end(),100); //将容器v中的所有元素填充为100
```

### 集合算法

```cpp
set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); //求两个容器的并集,并将结果存储在v3中
set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); //求两个容器的交集,并将结果存储在v3中
set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); //求两个容器的差集,并将结果存储在v3中，若没有差集元素，则返回v3.end()

//！！！！！！！！！！！！！！！依然要记得提前分配好v3的空间！！！！！！！！！！！！！！！！！！！！
```
