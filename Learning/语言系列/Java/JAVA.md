
# JAVA初学问题答疑及知识汇总

## 1.如何理解`package`?

初学者记住就好，刚学不要在这里过度纠结，详情请看第21。

## 2.如何理解`public class`?

同上，详情请看第14和第20

## 3.如何理解`public static void main (String[] args)`

这段代码是程序的入口，程序从这里开始执行。初学不要过度深究

## 3.字面量

字面量是用来告诉程序员,数据在程序中的书写格式.有以下分类:
整数类型: 666,888...........小数类型:13.14,-5.21
字符串类型:"Helloworld".....字符类型:'A' '0'
布尔类型:只有两个`ture`和`false`
空类型:`null`

## 4.什么是`final`?

`final`修饰的变量,常量,方法,类不能被修改，不能被继承。

## 5.什么是`scanner`?

`scanner`是一个用来接受键盘录入的类(但是只允许接受整数),java程序里已将将这个类写好了,使用时只需要按照:导包-创建对象-接收数据,就可以使用这个类了.
例:

```  .
     package org.example;
    // 导包,让编译器找到Scanner类
    import java.util.Scanner;
    public class Keyboard_input {
    public static void main(String[] args){
        //创建对象,表示我现在要使用Scanner了
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入任意整数：");
        //接收数据
        int i = sc.nextInt();

        System.out.println(i);
            }
    }
```

## 6.`String`是用来干啥的？

## 7.隐式转换

数据类型的取值范围大小：
```byte<short<int<long<float<double```
提升规则：
1.取值范围小的，和取值范围大的进行计算，小的会先升为大的，再进行计算;
2.byte short char 三种类型的数据在计算的时候，都会直接升为`int`,再进行计算.
例(一):

``` .
    public class Text{
        public static void main(String []args){
            int a = 10;
            double b = 12.3;
            double c = a+b;
        }    
    }

```

例(二):

``` .
    public class Text{
        public static void main(String []args){
            byte a = 10;
            bute b = 10;
            int c = a+b;
        }    
    }

```

## 8.强制转换

把数据类型取值范围大的数强制赋值给取值范围小的变量.但是这个做法可能会导致精度丢失,造成数据错误.
格式:目标数据类型 变量名 = （目标数据类型）被强转的数据；
例:

```.
    double a = 12.3;
    int b = (int)a;
```

## 9. 字符相加有什么作用？

## 10.方法是什么？

方法是一个函数或一个过程，它对输入进行处理并给出输出结果。方法的类型就是输出结果值的类型。方法返回的数据类型可以是Java中的任何数据类型，当一个方法不想需要返回数据时，它的返回类型必须是void。

## 11.数组

数组是一种存储多个相同类型元素的集合。数组的声明格式为：数据类型[] 数组名 = new 数据类型[数组长度];
例如：

```.
    int[] arr = new int[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
```

1.数组的声明格式：数据类型[] 数组名 = new 数据类型[数组长度];
2.数组的索引从0开始，最大索引为数组长度-1。
3.数组的长度是固定的，一旦声明就不能改变。

### 二维数组

二维数组是指数组的数组，即数组中包含了数组。二维数组的声明格式为：
数据类型[][] 数组名 = new 数据类型 [行数] [列数];
例如：

```.
    int[][] arr = new int[3][4];
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[1][0] = 50;
    arr[1][1] = 60;
    arr[1][2] = 70;
    arr[1][3] = 80;
    arr[2][0] = 90;
    arr[2][1] = 100;
    arr[2][2] = 110;    
    arr[2][3] = 120;
```

或者

```.
    int[][] arr = {{10,20,30,40},{50,60,70,80},{90,100,110,120}}; 
```

### 对象数组

对象数组是对象数组是用来存储对象的数组。你可以创建一个对象数组来存储同一类的多个对象。
例如，如果你有一个 Person 类，你可以创建一个 Person 类型的数组来存储多个 Person 对象。
例如：

```.
   class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

public class Main {
    public static void main(String[] args) {
        Person[] people = new Person[3]; // 创建一个可以存储3个Person对象的数组

        // 初始化数组中的对象
        people[0] = new Person("Alice", 30);
        people[1] = new Person("Bob", 25);
        people[2] = new Person("Charlie", 35);

        // 输出数组中的每个对象的信息
        for (Person person : people) {
            System.out.println("Name: " + person.name + ", Age: " + person.age);
        }
    }
}

```

## 12.字符串变量

字符串变量是用来存储字符串的变量。字符串变量的声明格式为：数据类型 变量名 = "字符串内容";
例如：

```.
    String str = "Hello World";
```

### String和StringBuiler

String和StringBuiler都是用来存储字符串的类。

String:

```.
    String str = "Hello World";
```

1.String是不可变的,一旦创建就不能修改。
2.String是引用类型,可以作为方法的参数和返回值。


StringBuiler:

```.
    StringBuilder sb = new StringBuilder();
    sb.append("Hello");
    sb.append(" ");
    sb.append("World");
    String str = sb.toString();
```

1.StringBuilder是可变的，可以多次修改。


### new创建对象

例如：

```.
    String str = new String("Hello World");
```

### 字符串的操作

字符串的操作有很多，常用的有：
1.获取字符串长度：`str.length()`
例如：

```.
    String str = "Hello World";
    int len = str.length();
    System.out.println(len); //输出结果为11
```

2.获取字符串某个位置的字符：`str.charAt(index)`
例如：

```.
    String str = "Hello World";
    char c = str.charAt(0);
    System.out.println(c); //输出结果为H
```

3.字符串拼接：`str1 + str2`
例如：

```.
    String str1 = "Hello";
    String str2 = " World";
    String str3 = str1 + str2;
    System.out.println(str3); //输出结果为Hello World
```

4.字符串比较：`str1.equals(str2)`
例如：

```.
    String str1 = "Hello";
    String str2 = "Hello";
    boolean flag = str1.equals(str2);
    System.out.println(flag); //输出结果为true
```

5.字符串查找：`str.indexOf(str2)`
例如：

```.
    String str = "Hello World";
    int index = str.indexOf("l");
    System.out.println(index); //输出结果为2
```

6.字符串替换：`str.replace(str1,str2)`
例如：

```.
    String str = "Hello World";
    String str1 = "l";
    String str2 = "L";
    String str3 = str.replace(str1,str2);
    System.out.println(str3); //输出结果为HeLLo World
```

7.字符串分割：`str.split(str2)`
例如：

```.
    String str = "Hello,World";
    String[] arr = str.split(",");
    System.out.println(arr[0]); //输出结果为Hello
    System.out.println(arr[1]); //输出结果为World
```

8.字符串转换：`Integer.parseInt(str)`
例如：

```.
    String str = "123";
    int num = Integer.parseInt(str);
    System.out.println(num); //输出结果为123
```

9.字符串转换：`Double.parseDouble(str)`
例如：

```.
    String str = "12.3";
    double num = Double.parseDouble(str);
    System.out.println(num); //输出结果为12.3
```

10.得到子串：`str.substring(start,end)`
例如：

```.
    String str = "Hello World";
    String sub = str.substring(0,5);
    System.out.println(sub); //输出结果为Hello
```

## 13.函数

函数是用来完成特定功能的小段代码，它可以重复使用，提高代码的可读性和可维护性。函数的声明格式为：

```.
    数据类型 函数名(参数类型 参数名){
        //函数体
    }
```

### 调用函数

调用函数的格式为：`函数名(参数1,参数2,参数3)`
例如：

```.
    int add(int a,int b){
        return a+b;
    }
    int result = add(10,20);
    System.out.println(result); //输出结果为30
```

### 本地变量

函数内部定义的变量称为本地变量，它只能在函数内部使用，函数执行结束后，本地变量会被销毁。

## 14.面向对象

面向对象是一种编程思想，它将程序的功能和数据封装成一个个对象，每个对象都有自己的属性和方法。面向对象编程的特点是抽象、继承、多态。

### 类

类是面向对象编程的基本单元，它用来描述具有相同属性和方法的对象的集合。类声明格式为：

```.
    class 类名{
        //属性
        //方法
    }
```

1.属性：类中用于描述对象的特征和状态的变量。
2.方法：类中用于实现对象的功能的==函数。==

### 创建对象

创建对象就是实例化一个类，类的实例化格式为：`类名 对象名 = new 类名();`
例如：

```.
    class Person{
        String name;//成员变量
        int age;
        void sayHello(){//成员函数
            System.out.println("Hello,My name is "+name);
        }
    }
    Person p = new Person();
    p.name = "Tom";
    p.age = 20;
    p.sayHello(); //输出结果为Hello,My name is Tom
```

### 对象的初始化

对象初始化就是为对象设置初始值，对象的初始化格式为：`对象名.属性名 = 初始值;`如果没有设置初始值,则默认初始化为0、false、null等。

### 运算符`.`

`.`是用来访问类的属性和方法的符号。其含义为：从左边的对象中获取右边的属性或方法。

## 14.成员变量和成员函数

成员变量和成员函数是类的组成部分，它们共同组成了类的属性和方法。

### 成员变量

成员变量是类的属性，它是类的一个变量，用于描述类的状态。成员变量的声明格式为：

```.
    数据类型 变量名;
```

1.成员变量的作用域：在类中声明的变量，默认的作用域是类内部。
2.成员变量的可见性：成员变量的可见性决定了其他类是否可以访问它。

### 成员函数

成员函数是类的函数，它是类的一个功能，用于实现类的功能。成员函数的声明格式为：

```.
    返回值类型 函数名(参数类型 参数名){
        //函数体
    }
```

1.成员函数的作用域：在类中声明的函数，默认的作用域是类内部。
2.成员函数的可见性：成员函数的可见性决定了其他类是否可以调用它。
3.成员函数的返回值：成员函数可以返回一个值，也可以不返回值。
4.成员函数的重载：一个类可以有多个同名函数，只要它们的参数列表不同即可。

## 15.局部变量和局部函数

局部变量和局部函数是函数的组成部分，它们只能在函数内部使用。

### 局部变量

局部变量是函数的变量，它是函数的一个变量，用于临时存储数据。局部变量的声明格式为：

```.
    数据类型 变量名;
```

1.局部变量的作用域：局部变量的作用域只在函数内部，函数执行结束后，局部变量会被销毁。
2.局部变量的生命周期：局部变量的生命周期只在函数执行期间。

### 局部函数

局部函数是函数的函数，它是函数的一个功能，用于实现函数的功能。局部函数的声明格式为：
例如：

```.
    void sayHello(){
        void sayHi(){//局部函数
            System.out.println("Hi!");
        }
        sayHi();
    }
    sayHello();
```

1.局部函数的作用域：局部函数的作用域只在函数内部，函数执行结束后，局部函数会被销毁。
2.局部函数的可见性：局部函数的可见性只在函数内部可见。
3.局部函数的返回值：局部函数可以返回一个值，也可以不返回值。
4.局部函数的重载：一个函数可以有多个同名函数，只要它们的参数列表不同即可。

## 16.全局变量和全局函数

全局变量和全局函数是程序的组成部分，它们可以在整个程序中使用。

### 全局变量

全局变量是程序的变量，它是程序的一个变量，用于存储数据。

1.全局变量的作用域：全局变量的作用域是整个程序，它可以被所有函数访问。
2.全局变量的生命周期：全局变量的生命周期是整个程序的运行期间。

### 全局函数

全局函数是程序的函数，它是程序的一个功能，用于实现程序的功能。比如`main`函数就是一个全局函数

## 17.函数重载

函数重载是指一个类可以有多个同名函数，只要它们的参数列表不同即可。
例如：

```.
    class Person{
        void sayHello(){
            System.out.println("Hello!");
        }
        void sayHello(String name){
            System.out.println("Hello,My name is "+name);
        }
    }
```

在上面的代码中，`sayHello`函数有两个版本，一个无参数版本，一个有参数版本。这就是函数重载。这两个函数就构成了重载关系.
==创建对象时，调用函数时，编译器会根据调用函数的参数列表，选择最匹配的函数版本进行调用。==

## 18.构造函数

构造函数是类的特殊函数，它是类的一个特殊函数，用于在创建对象时进行初始化。构造函数的声明格式为：

```.
    class 类名{
        构造函数名(参数类型 参数名){
            //构造函数体
        }
    }
```

构造函数的作用：

1.构造函数的名称：构造函数的名称必须与类名相同。
2.构造函数的作用域：构造函数的作用域是类内部。
3.构造函数的可见性：构造函数的可见性决定了其他类是否可以调用它。
4.构造函数的重载：一个类可以有多个构造函数，只要它们的参数列表不同即可。

## 19.`this`关键字

`this`关键字是Java中一个特殊的关键字,它表示当前对象的引用。
例如：

```.
    class Person{
        String name;
        int age;
        void sayHello(){
            System.out.println("Hello,My name is "+this.name);
        }
    }
    Person p = new Person();
    p.name = "Tom";
    p.sayHello(); //输出结果为Hello,My name is Tom
```

例2:

```.
    class Person{
        String name;
        int age;
        Person(String name){
            this.name = name;
        }
    }
    Person p = new Person("Tom");
    System.out.println(p.name); //输出结果为Tom
```

这里的this关键字用于构造函数的调用,它可以把构造函数中的参数赋值给成员变量。

1.this关键字的作用:this关键字可以访问当前对象的成员变量和成员函数。
2.this关键字的位置:this关键字只能在成员函数中使用。
3.this关键字的返回值:this关键字不能作为函数的返回值。
4.this关键字的重载:一个类可以有多个同名函数，只要它们的参数列表不同即可。

## 20.访问属性

1.public:公共属性，可以在任何地方访问。
2.private:私有属性，只能在类内部访问。
3.protected:受保护属性，可以在同一个包内的子类中访问。
==如果没有指定访问权限，默认是public，但建议不要使用默认的public属性。==

## 21.包

包是Java的一种组织结构，它是Java的一种命名空间，用来解决类名冲突的问题。

### 包的声明

包的声明格式为：

```.
    package 包名;
```

### 包的导入

包的导入格式为：

```.
    import 包名.类名;
```

==通过这里就可以理解之前学习的```import java.util.*;```的意义了。其作用就是导入java自带的util包，可以直接使用其中的类。==

### 包的访问控制

Java中提供了四种访问权限：public、private、protected、default。

public:公共包，可以在任何地方访问。
private:私有包，只能在当前包内访问。
protected:受保护包，可以在同一个包内的子类中访问。
default:默认包，包名可以省略，在当前包内访问。

## 22.类变量和类函数（静态变量和静态函数）

类变量和类函数又叫静态变量和静态函数，它们是类的组成部分，它们共同组成了类的属性和方法。

### 类变量（静态变量）

类变量是类的属性，它是类的一个变量，用于描述类的状态。类变量的声明格式为：

```.
    static 数据类型 变量名;
```

1.类变量的作用域：类变量的作用域是整个类，它可以被所有函数访问。
2.类变量的生命周期：类变量的生命周期是整个程序的运行期间。
人话：类变量是全局变量，它可以在整个程序中使用，并且在程序运行期间一直存在。可以通过类名直接访问类变量。

### 类函数（静态函数）

类函数是类的函数，它是类的一个功能，用于实现类的功能。类函数的声明格式为：

```.
    static 返回值类型 函数名(参数类型 参数名){
        //函数体
    }
```

1.类函数的作用域：类函数的作用域是整个类，它可以被所有函数访问。
人话：类函数是全局函数，它可以在整个程序中使用，并且在程序运行期间一直存在。可以通过类名直接访问类函数。

## 23.`String`数组

`String`数组是Java中提供的一种数组，它可以存储多个字符串。

### 声明`String`数组

`String`数组的声明格式为：

```.
    String[] 数组名 = new String[数组长度];
```

但是这个数组比较特殊，它声明出来的数组元素默认值是null，所以如果需要用到字符串数组，必须先初始化。

## 24.泛型容器类

泛型容器类是Java中提供的一种容器类，它可以存储不同类型的数据。如：`ArrayList`、`LinkedList`、`HashMap`等。

### LinkedList

==整数类型不能用int，而是要用Integer。==

```.
    LinkedList<Integer> list = new LinkedList<>();
    list.add(10);
    list.add(20);
    list.add(30);
    System.out.println(list.get(0)); //输出结果为10
    System.out.println(list.get(1)); //输出结果为20
    System.out.println(list.get(2)); //输出结果为30
```

LinkedList是一种无序集合，它可以存储多个元素，并且可以按顺序访问。List的声明格式为：

```.
    LinkedList<数据类型> list = new LinkedList<>();
```

例：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.get(0)); //输出结果为Hello
    System.out.println(list.get(1)); //输出结果为World
```

LinkedList的特点：

1.LinkedList是泛型类，可以存储不同类型的数据。
2.LinkedList是无序集合，不允许按顺序访问元素。
3.LinkedList是线程不安全的，如果多个线程同时访问LinkedList，可能会导致数据不一致。

LinkedList的常用方法：

1.add(E e):向LinkedList中添加元素。
例如：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.get(0)); //输出结果为Hello
    System.out.println(list.get(1)); //输出结果为World
```

2.get(int index):获取LinkedList中指定位置的元素。
例：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.get(0)); //输出结果为Hello
    System.out.println(list.get(1)); //输出结果为World
```

3.remove(int index):从LinkedList中删除指定位置的元素。
例如：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    list.remove(0);
    System.out.println(list.get(0)); //输出结果为World
4.size():获取LinkedList中元素的个数。
例如：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.size()); //输出结果为2
5.isEmpty():判断LinkedList是否为空。
例如：
```.
    LinkedList<String> list = new LinkedList<>();
    System.out.println(list.isEmpty()); //输出结果为true
```

4.clear():清空LinkedList。
例如：

```.
    LinkedList<String> list = new LinkedList<>();
    list.add("Hello");
    list.add("World");
    list.clear();
    System.out.println(list.isEmpty()); //输出结果为true
```

### ArrayList

ArrayList是一种有序集合，它可以存储多个元素，并且可以按顺序访问。List的声明格式为：

```.
    ArrayList<数据类型> list = new ArrayList<>();
```

例：

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.get(0)); //输出结果为Hello
    System.out.println(list.get(1)); //输出结果为World
```

ArrayList的特点：

1.ArrayList是泛型类，可以存储不同类型的数据。
2.ArrayList是有序集合，可以按顺序访问元素。
3.ArrayList是线程不安全的，如果多个线程同时访问ArrayList，可能会导致数据不一致。

ArrayList的常用方法：

1.add(E e):向ArrayList中添加元素。
2.get(int index):获取ArrayList中指定位置的元素。
3.set(int index, E e):修改ArrayList中指定位置的元素。
例：

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    list.set(0,"Hi");
    System.out.println(list.get(0)); //输出结果为Hi
```

4.contains(Object o):判断ArrayList中是否包含指定元素。

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.contains("Hello")); //输出结果为true
```

5.remove(int index):从ArrayList中删除指定位置的元素。

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    list.remove(0);
    System.out.println(list.get(0)); //输出结果为World
```

6.size():获取ArrayList中元素的个数。

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    System.out.println(list.size()); //输出结果为2
```

7.isEmpty():判断ArrayList是否为空。

```.
    ArrayList<String> list = new ArrayList<>();
    System.out.println(list.isEmpty()); //输出结果为true
```

8.clear():清空ArrayList。

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    list.clear();
    System.out.println(list.isEmpty()); //输出结果为true
```

## 24. for-each循环

for-each循环是Java中提供的一种循环语句，它可以遍历集合中的元素。

### 遍历ArrayList

```.
    ArrayList<String> list = new ArrayList<>();
    list.add("Hello");
    list.add("World");
    for(String str : list){
        System.out.println(str);
    }
```

1.for-each循环的语法格式为：

```.
    for(数据类型 变量名 : 集合名){
        //循环体
    }
```

2.for-each循环的特点：

1.for-each循环可以遍历集合中的元素。
2.for-each循环可以自动识别集合中的元素类型。
3.for-each循环可以简化代码。

## 25.集合容器

### ArrayList:ArrayList是一种有序集合,它可以存储多个元素.并且可以按顺序访问

nihao

### LinkedList:LinkedList是一种无序集合,它可以存储多个元素，并且可以按顺序访问

### HashSet

HashSet:HashSet是一种无序集合,它可以存储多个元素,并且不允许重复。HashSet的声明格式为:

```.
    HashSet<数据类型> set = new HashSet<>();
```

HashSet的操作方法:

1.add(E e):向HashSet中添加元素。
2.contains(Object o):判断HashSet中是否包含指定元素。
3.remove(Object o):从HashSet中删除指定元素。
4.size():获取HashSet中元素的个数。
5.isEmpty():判断HashSet是否为空。
6.clear():清空HashSet。

### HashMap

HashMap:HashMap是一种键值对集合，它可以存储多个键值对，并且可以根据键值对的键来获取值。HashMap的声明格式为：

```.
    HashMap<数据类型,数据类型> map = new HashMap<>();
```

HashMap的操作方法：

1.put(K key, V value):向HashMap中添加键值对。
2.get(Object key):获取HashMap中指定键对应的值。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    map.put("Tom",18);
    map.put("Jerry",20);
    System.out.println(map.get("Tom")); //输出结果为18
```

3.containsKey(Object key):判断HashMap中是否包含指定键。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    map.put("Tom",18);
    map.put("Jerry",20);
    System.out.println(map.containsKey("Tom")); //输出结果为true
```

4.remove(Object key):从HashMap中删除指定键。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    map.put("Tom",18);
    map.put("Jerry",20);
    map.remove("Tom");
    System.out.println(map.containsKey("Tom")); //输出结果为false
```

5.size():获取HashMap中键值对的个数。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    map.put("Tom",18);
    map.put("Jerry",20);
    System.out.println(map.size()); //输出结果为2
```

6.isEmpty():判断HashMap是否为空。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    System.out.println(map.isEmpty()); //输出结果为true
```

7.clear():清空HashMap。
例如：

```.
    HashMap<String,Integer> map = new HashMap<>();
    map.put("Tom",18);
    map.put("Jerry",20);
    map.clear();
    System.out.println(map.isEmpty()); //输出结果为true
```

### 集合之间的操作

集合之间的操作：
1.交集：取两个集合的交集。
2.并集：取两个集合的并集。
3.差集：取两个集合的差集。
4.对称差集：取两个集合的对称差集。

```.
    HashSet<String> set1 = new HashSet<>();
    set1.add("Tom");
    set1.add("Jerry");
    set1.add("Mary");
    HashSet<String> set2 = new HashSet<>();
    set2.add("Tom");
    set2.add("Jerry");
    set2.add("Lily");
    //交集
    HashSet<String> intersection = new HashSet<>(set1);
    intersection.retainAll(set2);
    System.out.println(intersection); //输出结果为[Tom, Jerry]
    //并集
    HashSet<String> union = new HashSet<>(set1);
    union.addAll(set2);
    System.out.println(union); //输出结果为[Tom, Jerry, Mary, Lily]
    //差集
    HashSet<String> difference = new HashSet<>(set1);
    difference.removeAll(set2);
    System.out.println(difference); //输出结果为[Mary]
    //对称差集
    HashSet<String> symmetricDifference = new HashSet<>(set1);
    symmetricDifference.addAll(set2);
    symmetricDifference.removeAll(intersection);
    System.out.println(symmetricDifference); //输出结果为[Mary, Lily]
```

## 26.继承

继承是面向对象编程的重要概念，它是指一个类可以从另一个类继承其属性和方法。

### 继承的语法格式

继承的语法格式为：

```.
    class 子类 extends 父类{
        //子类属性和方法
    }
```

继承的作用：

1.子类可以继承父类的属性和方法。
2.子类可以重写父类的方法。
3.子类可以添加新的属性和方法。

例如：

```.
    class Animal{
        void eat(){
            System.out.println("动物吃东西");
        }
    }
    class Dog extends Animal{
        void bark(){
            System.out.println("狗叫");
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为动物吃东西
    dog.bark(); //输出结果为狗叫    
```

在 Java 中，当创建子类的对象时，子类的构造函数==会默认先调用父类的构造函数==（如果没有显式调用，编译器会自动插入对父类无参构造函数的调用），
这是因为子类对象的构建过程需要先初始化从父类继承来的成员变量等。然后再执行子类自己的构造函数中的代码。

```.
    class Animal{
        Animal(){
            System.out.println("动物构造函数");
        }
    }
    class Dog extends Animal{
        Dog(){
            super();
            System.out.println("狗构造函数");
        }
    }
    Dog dog = new Dog(); //输出结果为动物构造函数 狗构造函数
```

### super关键字

super关键字是Java中用于调用父类的方法和属性的关键字。

super关键字的用法：

```.
    class Animal{
        void eat(){
            System.out.println("动物吃东西");
        }
    }
    class Dog extends Animal{
        void bark(){
            System.out.println("狗叫");
        }
        void eat(){
            System.out.println("狗吃骨头");
            super.eat(); //调用父类的eat方法
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为狗吃骨头 动物吃东西
```

## 27.Math类

### 常用方法

 ```.
    Math.abs(double a):求绝对值。
    Math.ceil(double a):向上取整。
    Math.floor(double a):向下取整。
    Math.max(double a,double b):求最大值。
    Math.min(double a,double b):求最小值。
    Math.pow(double a,double b):求a的b次方。
    Math.random():生成一个随机数。
    Math.round(double a):四舍五入。
    Math.sqrt(double a):求平方根。
 ```

## 28.接口

接口（Interface）是Java提供的一种抽象机制，它是一种特殊的类，它不能实例化，只能作为其他类的父类。接口中可以定义抽象方法，抽象方法是不包含方法体的接口方法。

### 接口的语法格式

接口的语法格式为：

```.
    interface 接口名{
        //接口方法
    }
```

1.接口不能实例化，只能作为其他类的父类。
2.接口中可以定义抽象方法，抽象方法是不包含方法体的接口方法。
3.接口中的方法默认是public的。

例如：

```.
    interface Animal{
        void eat();
    }
    class Dog implements Animal{
        public void eat(){
            System.out.println("狗吃东西");
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为狗吃东西
```

1.Dog类实现了Animal接口，Dog类可以调用Animal接口中的eat()方法。

接口的作用：

1.接口可以定义一个标准，使得不同的类遵循这个标准，从而实现代码的重用。
2.接口可以隐藏类的内部细节，使得类只需要关注接口的功能，而不需要关注实现的细节。
3.接口可以多继承。

## 29.多态

多态是面向对象编程的重要概念，它是指一个对象可以赋予多个形态。java中多态方法的体现有两种：

1.方法重写：子类可以重新定义父类的方法，使得子类对象调用的方法与父类的方法具有相同的功能。
2.方法重载：同一个类中可以有多个同名的方法，但是这些方法的参数列表必须不同。

### 方法重写

方法重写是指子类可以重新定义父类的方法，使得子类对象调用的方法与父类的方法具有相同的功能。

例如：

```.
    class Animal{
        void eat(){
            System.out.println("动物吃东西");
        }
    }
    class Dog extends Animal{
        void eat(){
            System.out.println("狗吃骨头");
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为狗吃骨头
```

在上面的代码中，Dog类重写了Animal类的eat()方法，使得Dog对象调用的eat()方法具有了不同的功能。

#### 向上转型

向上造型是将子类对象赋值给父类类型的变量，是一种多态的机制，是重写的一种特殊情况。由于子类是对父类的扩展和具体化，这种赋值在逻辑上是合理的，就好像把一个更“具体”的对象当作一个更“抽象”的对象来使用。

例如：

```.
    class Animal {
    public void makeSound() {
        System.out.println("动物发出声音");
    }
}
class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("汪汪汪");
    }
}
Dog myDog = new Dog();
Animal myAnimal = myDog; 
myAnimal.makeSound();
```

在这个例子中，`myDog`是`Dog`类的对象，通过`Animal myAnimal = myDog;`这一语句实现了向上造型，将`Dog`对象赋值给`Animal`类型的变量`myAnimal`。
当调用`makeSound`方法时，会根据对象的实际类型（`Dog`）来执行`Dog`类中重写后的`makeSound`方法。

### 方法重载

例如：
在一个类中，可以定义多个方法名相同，但参数列表（参数的个数、类型、顺序）不同的方法。当调用这个方法时，编译器会根据传递的实际参数来决定调用哪个具体的方法。

例如：

```.
public class OverloadingExample {
    public int add(int a, int b) {
        return a + b;
    }
    public double add(double a, double b) {
        return a + b;
    }
    public int add(int a, int b, int c) {
        return a + b + c;
    }
}
```

## 30.覆写

Override是Java中的一个关键字，它用来表示子类覆盖了父类的方法。

例如：

```.
    class Animal{
        void eat(){
            System.out.println("动物吃东西");
        }
    }
    class Dog extends Animal{
        @Override
        void eat(){
            System.out.println("狗吃骨头");
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为狗吃骨头
```

1.Dog类覆盖了Animal类的eat()方法。
2.Dog类的eat()方法使用了@Override注解，表示它覆盖了父类的方法。

### 覆写的限制

1.子类方法的访问权限必须大于等于父类方法的访问权限。
2.子类方法的返回类型必须与父类方法的返回类型相同或相兼容。
3.子类方法的参数列表必须与父类方法的参数列表相同或相兼容。
4.子类方法的异常类型必须与父类方法的异常类型相同或相兼容。

## 31.函数绑定

函数绑定（Method Binding）是指将一个方法调用和它对应的方法主体连接起来的过程。Java 中有两种主要的绑定方式：静态绑定（也叫早期绑定）和动态绑定（也叫晚期绑定）。

### 静态函数绑定

静态绑定是指在编译时期就能够确定调用哪个方法的绑定方式。它主要应用于私有方法、静态方法和final方法。
例如：

```.
    class Animal{
        void eat(){
            System.out.println("动物吃东西");
        }
    }
    class Dog extends Animal{
        void eat(){
            System.out.println("狗吃骨头");
        }
    }
    Dog dog = new Dog();
    Animal animal = new Animal();
    dog.eat(); //输出结果为狗吃骨头
    animal.eat(); //输出结果为动物吃东西
```

1.dog.eat()调用的是Dog类中的eat()方法，因为dog对象是Dog类的实例，所以编译器可以确定调用哪个方法。
2.animal.eat()调用的是Animal类中的eat()方法，因为animal对象是Animal类的实例，所以编译器可以确定调用哪个方法。

### 动态函数绑定

动态绑定是指在运行时期才能够确定调用哪个方法的绑定方式。它主要应用于非私有方法、非静态方法和非final方法。

例如：

```.
   class Animal {
       public void makeSound() {
           System.out.println("Animal makes a sound.");
       }
   }
   class Dog extends Animal {
       @Override
       public void makeSound() {
           System.out.println("Dog barks.");
       }
   }
   class DynamicBindingExample {
       public static void main(String[] args) {
           Animal animal1 = new Animal();
           Animal animal2 = new Dog();
           animal1.makeSound();
           animal2.makeSound();
       }
   }
```

在这个例子中，Animal类有一个makeSound方法，Dog类继承了Animal类并覆盖了makeSound方法。在main方法中，animal1是Animal类型的对象，它调用makeSound方法时会输出Animal makes a sound.。而animal2虽然是Animal类型的引用，但它实际指向的是Dog类型的对象。当animal2调用makeSound方法时，由于动态绑定，在运行时会根据对象的实际类型（Dog）来调用Dog类中覆盖后的makeSound方法，输出Dog barks.。

## 32.Object类

Object类是所有类的父类，它提供了一些通用的方法，如equals()、hashCode()、toString()等。

### equals()方法

equals()方法是用来判断两个对象是否相等的。

```.
    public boolean equals(Object obj) {
        return (this == obj);
    }
```

默认情况下，equals()方法比较两个对象的内存地址是否相同，如果相同，则认为它们相等。

### hashCode()方法

hashCode()方法是用来获取对象的哈希码的。

```.
    public int hashCode() {
        return super.hashCode();
    }
```

默认情况下，hashCode()方法返回对象的内存地址的整数值。

### toString()方法

toString()方法是用来获取对象的字符串表示的。

如：

```.
    public String toString() {
        return getClass().getName() + "@" + Integer.toHexString(hashCode());
    }
```

默认情况下，toString()方法返回类的全名以及对象的内存地址的十六进制表示。

## 33.抽象类

抽象类（Abstract Class）是Java提供的一种抽象机制，它是一种特殊的类，它不能实例化，只能作为其他类的父类。抽象类中可以定义抽象方法，抽象方法是不包含方法体的接口方法。

通俗一点来讲，抽象类的作用就是用来定义一个类，它必须有子类可以继承这个类，抽象类来指明方向，子类来实现具体的功能。

抽象类可以有抽象方法和非抽象方法，抽象方法是不包含方法体的接口方法，子类必须实现这些抽象方法，而非抽象方法可以有方法体。

例如：

```.
    abstract class Animal{
        void eat(){//非抽象方法
            System.out.println("动物吃东西");
        }
        abstract void makeSound();//抽象方法
    }
    class Dog extends Animal{
        @Override
        void makeSound(){//实现抽象方法
            System.out.println("狗叫");
        }
    }
    Dog dog = new Dog();
    dog.eat(); //输出结果为动物吃东西
    dog.makeSound(); //输出结果为狗叫
```

### 抽象类和接口的区别

抽象类可以有部分实现（非抽象方法），而接口在 Java 8 之前几乎是完全抽象的（只有方法签名和常量）。从抽象程度来说，接口比抽象类更抽象。例如，接口就像一个纯粹的规范，规定了一系列的行为但没有提供任何实现；而抽象类除了规定行为（抽象方法）外，还可以提供一些通用的实现（非抽象方法）。

一个类只能继承一个抽象类，但可以实现多个接口。这是因为 Java 不支持多重继承（继承多个类），但支持一个类实现多个接口来获取多种行为规范。例如，一个类可以继承一个抽象类来获取其模板和部分实现，同时可以实现多个接口来满足多种功能需求。

## 34.异常

在Java中,异常是一种在程序运行过程中出现的意外情况，它会打断程序的正常执行。
Java提供了强大的异常处理机制来处理这些异常,确保程序能够优雅地应对错误情况。

### 捕捉异常

捕捉异常是指在代码中使用try-catch语句来捕捉并处理异常。

```.
    try{
        //可能产生异常的代码
    }catch(异常类型 变量名){
        //异常发生时执行的代码
    }
```

### 异常捕捉机制

![alt text](QQ_1734401054551.png)
