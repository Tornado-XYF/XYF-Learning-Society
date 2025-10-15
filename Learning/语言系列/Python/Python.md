# Life is short ，I choose Python

## 原始字符串

原始字符串只需要在字符串的第一个引号前加上一个字母 r（可以大小写），其作用是告诉解释器这是一个原始字符串，输出时其中的转义字符无效。

## 行连接符

Python 中可以使用反斜杠（\）来实现多行语句。
例如：

```python
total = item_one + \
        item_two + \
        item_three
```

输出：

```python
>>> print(total)
This is a long string that goes on

如果不使用反斜杠，也可以使用括号来实现多行语句。
例如：

```

total = ('item_one' +
        'item_two' +
        'item_three')

输出：

```python
>>> print(total)
This is a long string that goes on

```

## `"""`

`"""` 用于表示一个多行字符串。

例如：

```python
"""This is a long string that goes on
for many lines and some say
definitely more than four."""
```

输出：

```python
>>> print(total)
This is a long string that goes on
for many lines and some say
definitely more than four.
```

## 缩进

Python 中使用缩进来表示代码块，缩进的空格数可以是任意的，但是同一个代码块的缩进空格数必须相同。

## 数据类型-浮点数-精度

浮点数的精度是有限的，因此不能精确表示某些小数。

例如：

```python
>>> 0.1 + 0.2 == 0.3
False
```

要解决这个问题，可以使用 `decimal` 模块。

例如：

```python
>>> import decimal
>>> decimal.getcontext().prec = 2
>>> decimal.Decimal('0.1') + decimal.Decimal('0.2') == decimal.Decimal('0.3')
True
```

## 数字之间的运算

以下表格列出了 Python 中数字之间的运算：

| 运算符 | 描述 | 实例 |
| --- | --- | --- |
| + | 加 | 1 + 1 = 2 |
| - | 减 | 1 - 1 = 0 |
| * | 乘 | 1 * 1 = 1 |
| / | 除 | 1 / 1 = 1 |
| % | 取余 | 1 % 1 = 0 |
| ** | 幂 | 1 ** 1 = 1 |
| // | 取整 | 1 // 1 = 1 |
|abs|取绝对值|abs(-1) = 1|
|int|取整|int(1.1) = 1|
|float|取浮点数|float(1) = 1.0|
|complex|取复数|complex(1, 2) = 1 + 2j|
|divmod|取商和余数|divmod(1, 2) = (0, 1)|
|pow|取幂|pow(1, 2) = 1|
|x ** y|取幂|1 ** 2 = 1|

## 布尔类型

布尔类型只有两个值：`True` 和 `False`。

## 逻辑运算符

以下表格列出了 Python 中逻辑运算符：

| 运算符 | 描述 | 实例 |
| --- | --- | --- |
| and | 与 | True and False = False |
| or | 或 | True or False = True |
| not | 非 | not True = False |

## `is`运算

`is` 运算用于比较两个对象是否指向同一个内存地址。
例如：

```python
name1 = "张三"
name2 = "张三"
list1 = [1, 2, 3]
list2 = [1, 2, 3]
print(name1 is name2)
print(list1 is list2)
```

输出：

```python
True
False
```

解释：

由于列表中的元素是可变的，因此 `list1` 和 `list2` 指向不同的内存地址，方便进行增删改查。

### 短路运算

短路运算是指在逻辑运算中，如果第一个操作数已经可以确定整个表达式的值，那么就不会再计算第二个操作数。

### 运算符优先级

以下表格列出了 Python 中运算符的优先级：

| 运算符 | 描述 |
| --- | --- |
| ** | 幂 |
| * / % // | 乘、除、取余、取整 |
| + - | 加、减 |
| <= < > >= | 比较运算符 |
| == != | 等于、不等于 |
| = %= /= //= -= += *= **= | 赋值运算符 |
| not or and | 逻辑运算符 |

## 分支和循环

### 分支

分支是指根据条件的不同，执行不同的代码块。
有以下几种分支：

- if 分支
- 例如：

```python
if condition:
    # do something
```

- if-else 分支
- 例如：

```python
if condition:
    # do something
else:
    # do something else
```

- if-elif 分支
- 例如：

```python
if condition1:
    # do something
elif condition2:
    # do something else
```

- if-elif-else 分支

 例如：

```python
if condition1:
    # do something
elif condition2:
    # do something else
else:
    # do something else
```

### 条件表达式

条件表达式是指根据条件的不同，返回不同的值。

例如：

```python
x = 1 if condition else 0
```

解释：如果 condition 为真，那么 x 的值为 1，否则 x 的值为 0。

### 循环

循环是指根据条件的不同，重复执行一段代码块。

有以下几种循环：

- while 循环
- 例如：

```python
while condition:
    # do something
```

- for 循环
例如：

```python
for 变量 in 可迭代对象:
    # do something
```

例如：

```python
for i in range(10):
    print(i)
```

输出：

```python
0
1
2
3
4
5
6
7
8
9
```

#### `range()`

`range()` 函数用于生成一个整数序列，通常用于 for 循环中.

`range()` 函数有以下几种用法：

- `range(stop)`：生成一个从 0 到 stop-1 的整数序列。
- `range(start, stop)`：生成一个从 start 到 stop-1 的整数序列。
- `range(start, stop, step)`：生成一个从 start 到 stop-1 的整数序列，步长为 step。
- 例如：

```python
for i in range(10,5，-2):
    print(i)
```

输出：

```python
10
8
6
4
```

#### 可迭代对象

可迭代对象是指可以被遍历的对象。

## 列表

列表是一种有序的集合，可以包含任意类型的元素。
例如：

```python
my_list = [1, 2, 3, 4, 5]

```

列表的索引从 0 开始，例如：

```python
my_list[0] = 1
my_list[1] = 2
```

列表的特点：

- 有序
- 可以包含任意类型的元素
- 可以包含重复的元素
- 可以修改
- 可以嵌套

### 列表的常用方法

- `append()`：在列表的末尾添加一个元素。
- `extend()`：在列表的末尾添加另一个列表的元素。
- `insert()`：在列表的指定位置插入一个元素。
- `remove()`：删除列表中的第一个指定元素。
- `pop()`：删除列表中的指定位置的元素。
- `index()`：返回列表中指定元素的索引。
- `index(x, start, end)`: 返回列表中指定元素的索引，从 start 开始查找到 end。
- `count()`：返回列表中指定元素的出现次数。
- `sort()`：对列表进行排序。
- `reverse()`：反转列表。
- `copy()`：复制列表。
- `clear()`：清空列表。
- `len()`：返回列表的长度。
- `max()`：返回列表中的最大值。
- `min()`：返回列表中的最小值。
- `sum()`：返回列表中所有元素的和。
- `any()`：返回列表中是否有任意一个元素为真。
- `all()`：返回列表中是否所有元素为真。
- `enumerate()`：返回一个枚举对象，包含索引和值。
- `zip()`：zip() 函数是 Python 内置函数，它将可迭代对象作为参数，将对象中对应的元素打包成一个个元组，然后返回这些元组组成的迭代器。list() 函数可以将迭代器转换为列表。
- `map()`：返回一个 map 对象，包含对可迭代对象的每个元素应用函数后的结果。
- `filter()`：返回一个 filter 对象，包含对可迭代对象的每个元素应用函数后的结果，只包含满足条件的元素。
- `reduce()`：返回一个 reduce 对象，包含对可迭代对象的每个元素应用函数后的结果，只包含满足条件的元素。
- `list()`：将可迭代对象转换为列表。
- `tuple()`：将可迭代对象转换为元组。
- `set()`：将可迭代对象转换为集合。
- `dict()`：将可迭代对象转换为字典。
- `str()`：将可迭代对象转换为字符串。
- `reversed()`：返回一个反转的可迭代对象。
- `sorted()`：返回一个排序后的可迭代对象。

### 列表切片

列表切片是指获取列表中的一部分元素。
例如：

```python
my_list[0:3] = [1, 2, 3]
my_list[3:] = [4, 5]
my_list[:3] = [1, 2, 3]
my_list[::-1] = [5, 4, 3, 2, 1]
my_list[1:4:2] = [2, 4]
my_list[::2] = [1, 3, 5]
```

解释：

- `my_list[0:3]`：获取列表中从第一个元素开始到第三个元素结束的所有元素。
- `my_list[3:]`：获取列表中的从第四个元素开始的所有元素。
- `my_list[:3]`：获取列表中的前三个元素。
- `my_list[::2]`: 获取列表中的所有元素，步长为 2。
- `my_list[::-1]`：获取列表中的所有元素，步长为 -1，即反转列表。
- `my_list[1:4:2]`：获取列表中的从第二个元素开始到第四个元素结束的所有元素，步长为 2。

#### 利用切片增删改查

- 增：

```python
heros = ["蜘蛛侠","绿巨人",'"鹰眼"']
heros[0:0] = ["黑寡妇"]
print(heros)
```

输出：

```python
['黑寡妇', '蜘蛛侠', '绿巨人', '"鹰眼"']
```

- 删：

```python
heros = ["蜘蛛侠","绿巨人",'"鹰眼"']
heros[0:1] = []
print(heros)
```

输出：

```python
['绿巨人', '"鹰眼"']
```

- 改：

```python
heros = ["蜘蛛侠","绿巨人",'"鹰眼"']
heros[0:1] = ["黑寡妇"]
print(heros)
```

输出：

```python
['黑寡妇', '绿巨人', '"鹰眼"']
```

- 查：

```python
heros = ["蜘蛛侠","绿巨人",'"鹰眼"']
print(heros[0:2])
```

输出：

```python
['蜘蛛侠', '绿巨人']
```

### 列表运算

列表运算有以下几种：

- 加法：将两个列表拼接在一起。
- 例如：
- `my_list1 + my_list2`：将 `my_list1` 和 `my_list2` 拼接在一起。
- 乘法：将列表重复指定次数。
- 例如：
- `my_list * 3`：将 `my_list` 重复 3 次。
- 比较：比较两个列表的大小。
- 例如：
- `my_list1 > my_list2`：比较 `my_list1` 和 `my_list2` 的大小。
- 逻辑：判断列表是否为空。
- 例如：
  
  ```python
  my_list = []
  if my_list:
      print("列表不为空")
  else:
      print("列表为空")
  ```

- 成员：判断元素是否在列表中。
- 例如：

  ```python
  my_list = [1, 2, 3]
  if 2 in my_list:
      print("元素在列表中")
  else:
      print("元素不在列表中")
  ```

### 二维列表

二维列表是指列表中的元素也是列表。
例如：

```python
my_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
```

#### 二维列表的访问

二维列表的访问有以下几种方式：

- 访问元素：
  例如：

  ```python
  my_list[0][0] = 1
  my_list[1][1] = 5
  my_list[2][2] = 9
  ```

### 列表推导式

列表推导式是一种快速生成列表的方法。语法如下：

```python
[expression for item in iterable if condition]
```

解释：

- `expression`：表达式，用于生成列表中的元素。
- `item`：可迭代对象中的元素。
- `iterable`：可迭代对象。
- `condition`：条件，用于过滤元素。
内部实现：

- 列表推导式内部实现是通过 for 循环和 if 语句来实现的。
其内部实现类似于以下代码：

```python
result = []
for item in iterable:
    if condition:
        result.append(expression)
```

例如：

```python
my_list = [x for x in range(10)]
```

输出：

```python
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

解释：

- `[x for x in range(10)]`：生成一个包含 0 到 9 的列表。

## 浅拷贝

浅拷贝是指将一个对象的引用复制给另一个对象，两个对象指向同一个内存地址。
例如：

```python
import copy
my_list = [1, 2, 3]
my_list_copy1 = my_list.copy()
```

解释：

- `my_list.copy()`：将列表的引用复制给 `my_list_copy1`。

### 切片拷贝

切片拷贝是指将一个列表的一部分复制给另一个列表。
例如：

```python
my_list = [1, 2, 3]
my_list_copy2 = my_list[:]
```

## 深拷贝

深拷贝是指将一个对象的所有元素复制给另一个对象，两个对象指向不同的内存地址。
例如：

```python
import copy
my_list = [1, 2, 3]
my_list_copy3 = copy.deepcopy(my_list)
```

解释：

- `copy.deepcopy()`：将列表的所有元素复制给 `my_list_copy3`。

### 浅拷贝和深拷贝的区别

浅拷贝和深拷贝的区别在于：

- 浅拷贝：两个对象指向同一个内存地址。
- 深拷贝：两个对象指向不同的内存地址。

## 元组

元组是一种有序的集合，可以包含任意类型的元素。其运算与列表类似，但是元组是不可变的。
例如：

```python
my_tuple = (1, 2, 3, 4, 5,"上山打老虎")
```

元组的特点：

- 有序
- 可以包含任意类型的元素
- 可以包含重复的元素
- ==不可修改==
- ==可以嵌套==

### 元组的“查” `index()` 和 `count()`

  例如：

  ```python
  my_tuple = (1,2,3,4,5,3,2,3)
  nums.count(3)
  ```

  输出：

  ```python
  3
  ```

  解释：

  `nums.count(3)` 用于统计元组中元素 3 的个数。

  例（2）:
  
  ```python
  my_tuple = (1,2,3,4,5,3,2,3)
  nums.index(3)
  ```

 输出：

```python
  2
```

解释：

`nums.index(3)` 用于查找元组中元素 3 的第一次出现索引。

### 单元素元组

单元素元组是指只有一个元素的元组。
例如：

```python
my_tuple = (1,)
```

解释：

由于元组是不可变的，因此单元素元组必须在元素后面加上逗号，否则会被解释为其他类型。

比如：

```python
my_tuple = (1)
print(type(my_tuple))  # type()函数用于获取变量的类型
```

输出：

```python
<class 'int'>
```

### 打包和解包

打包和解包是指将多个元素打包成一个元组，或者将一个元组解包成多个元素。
例如：

```python
my_tuple = (1, "XYF", 3.14) #打包
a, b, c = my_tuple #解包
```

输出：

```.
a = 1
b = "XYF"
c = 3.14
```

解包不止是元组可以解包，其他可迭代对象也可以解包。
例如：

```python
my_list = "GENJI"
a, b, c,d,e = my_list
```

输出：

```python
a = "G"
b = "E"
c = "N"
d = "J"
e = "I"
```

== 可迭代对象解包时，变量个数必须与元素个数相同。==

### 元组的"改"

元组是不可变的，因此不能修改元组中的元素。但是当元素是可变对象时，可以修改可变对象中的元素。
例如：

```python
my_tuple = (1, [2, 3], 4)
my_tuple[1][0] = 5
print(my_tuple)
```

输出：

```python
(1, [5, 3], 4)
```

## 字符串

### 大小写转换

#### `captialize()`

`capitalize()` 方法用于将字符串的第一个字符转换为大写。
例如：

```python
my_string = "hello world"
print(my_string.capitalize())
```

输出：

```python
Hello world
```

#### `casefold()`

`casefold()` 方法用于将字符串转换为小写。
例如：

```python
my_string = "Hello World"
print(my_string.casefold())
```

输出：

```python
hello world
```

#### `title()`

`title()` 方法用于将字符串的每个单词的第一个字符转换为大写。
例如：

```python
my_string = "hello world"
print(my_string.title())
```

输出：

```python
Hello World
```

#### `upper()`

`upper()` 方法用于将字符串转换为大写。
例如：

```python
my_string = "hello world"
print(my_string.upper())
```

输出：

```python
HELLO WORLD
```

#### `swapcase()`

`swapcase()` 方法用于将字符串中的大写字母转换为小写字母，小写字母转换为大写字母。
例如：

```python
my_string = "Hello World"
print(my_string.swapcase())
```

输出：

```python
hELLO wORLD
```

#### `lower()`

`lower()` 方法用于将字符串转换为小写。
例如：

```python
my_string = "Hello World"
print(my_string.lower())
```

输出：

```python
hello world
```

### 左中右对齐

#### `center()`

`center()` 方法用于将字符串居中对齐，第一个参数为宽度，第二个参数为填充字符。
例如：

```python
my_string = "hello world"
print(my_string.center(20, "*"))
```

输出：

```python
****hello world****
```

#### `ljust()`

`ljust()` 方法用于将字符串左对齐，第一个参数为宽度，第二个参数为填充字符。
例如：

```python
my_string = "hello world"
print(my_string.ljust(20, "*"))
```

输出：

```python
hello world********
```

#### `rjust()`

`rjust()` 方法用于将字符串右对齐，第一个参数为宽度，第二个参数为填充字符。
例如：

```python
my_string = "hello world"
print(my_string.rjust(20, "*"))
```

输出：

```python
********hello world
```

### 字符串的“查”

#### 查找`find()`

`find()` 方法用于查找字符串中第一次出现的子字符串的索引。如果没有找到，则返回 -1。
例如：

```python
my_string = "hello world"
print(my_string.find("world"))
```

输出：

```python
6
```

#### 查找索引`index()`

`index()` 方法用于查找字符串中第一次出现的子字符串的索引。如果没有找到，则抛出异常。
例如：

```python
my_string = "hello world"
print(my_string.index("world"))
```

输出：

```python
6
```

异常：

```python
my_string = "hello world"
print(my_string.index("xyf"))
```

输出：

```python
ValueError: substring not found
```

#### 统计`count()`

`count(x, start, end)` 方法用于统计字符串中某个子字符串出现的次数.
参数：

- `x`：要统计的子字符串。
- `start`：可选参数，指定开始统计的位置。
- `end`：可选参数，指定结束统计的位置。
返回值：

- 子字符串出现的次数。
- 如果没有找到，则返回 0。
- 如果 `start` 或 `end` 参数超出了字符串的范围，则抛出异常。

例如：

```python
my_string = "hello world"
print(my_string.count("o"))
```

输出：

```python
2
```

### 字符串的“改”

#### 制表替换空格`expandtabs()`

`expandtabs()` 方法用于将字符串中的制表符替换为空格。
例如：

```python
my_string = "hello\tworld"
print(my_string.expandtabs(4)) #制表符改为4个空格
```

输出：

```python
hello   world
```

#### 字符替换`replace()`

`replace(old, new, count)` 方法用于将字符串中的某个子字符串替换为另一个子字符串。
参数：

- `old`：要替换的子字符串。
- `new`：替换后的子字符串。
- `count`：可选参数，指定替换的次数。
- 返回值：
  - 替换后的字符串。
  - 如果 `count` 参数指定了替换的次数，则最多替换 `count` 次。
  - 如果 `count` 参数没有指定，则替换所有出现的子字符串。

例如：

```python
my_string = "hello world"
print(my_string.replace("world", "xyf"))
```

输出：

```python
hello xyf
```

#### `translate(table)`

`translate(table)` 方法用于将字符串中的字符替换为另一个字符。
参数：

- `table`：一个映射表，用于指定字符的替换规则。
- 返回值：
  - 替换后的字符串。
  - 如果 `table` 参数没有指定，则使用默认的替换规则。
  - 如果 `table` 参数指定了替换规则，则使用指定的替换规则。

例如：

```python
my_string = "hello world"
print(my_string.translate(str.maketrans("o", "x")))
```

输出：

```python
hellx wxrld
```

### 字符串的判断和检测

#### `startswith()`

`startswith(prefix, start, end)` 方法用于检查字符串是否以指定的前缀开头。
参数：

- `prefix`：要检查的前缀。
- `start`：可选参数，指定开始检查的位置。
- `end`：可选参数，指定结束检查的位置。
- 返回值：
  - 如果字符串以指定的前缀开头，则返回 `True`。
  - 如果字符串不以指定的前缀开头，则返回 `False`。
  - 如果 `start` 或 `end` 参数超出了字符串的范围，则抛出异常。

例如：

```python
my_string = "hello world"
print(my_string.startswith("hello"))
```

输出：

```python
True
```

#### `endswith()`

`endswith(suffix, start, end)` 方法用于检查字符串是否以指定的后缀结尾。
参数：

- `suffix`：要检查的后缀。
- `start`：可选参数，指定开始检查的位置。
- `end`：可选参数，指定结束检查的位置。
- 返回值：
  - 如果字符串以指定的后缀结尾，则返回 `True`。
  - 如果字符串不以指定的后缀结尾，则返回 `False`。
  - 如果 `start` 或 `end` 参数超出了字符串的范围，则抛出异常。

例如：

```python
my_string = "hello world"
print(my_string.endswith("world"))
```

输出：

```python
True
```

== `startswith()` 和 `endswith()` 方法的参数`suffix`允许指定为元组，这样可以检查字符串是否以元组中的任意一个后缀结尾。==

例如：

```python
my_string = "hello world"
print(my_string.endswith(("world", "xyf")))
```

输出：

```python
True
```

#### 大写判断`istitle()`

`istitle()` 方法用于检查字符串的所有单词是否都是首字母大写的。
例如：

```python
my_string = "Hello World"
print(my_string.istitle())
```

输出：

```python
True
```

#### 检测是否只有字母`isalpha()`

`isalpha()` 方法用于检查字符串是否只包含字母。
例如：

```python
my_string = "hello world"
print(my_string.isalpha())
```

输出：

```python
False
```

#### 检测是否只有空白字符`isspace()`

`isspace()` 方法用于检查字符串是否只包含空白字符。
例如：

```python
my_string = "   "
print(my_string.isspace())
```

输出：

```python
True
```

#### 检测是否全为可打印字符`isprintable()`

`isprintable()` 方法用于检查字符串是否只包含可打印字符。
例如：

```python
my_string = "hello world\n"
print(my_string.isprintable())
```

输出：

```python
False
```

#### 检测是否没有符合python标识符规则的字符`isidentifier()`

`isidentifier()` 方法用于检查字符串是否符合 Python 标识符的规则。
例如：

```python
my_string = "hello world" #空格不符合标识符规则
print(my_string.isidentifier()) 
```

输出：

```python
False 
```

#### 判断是否为python的保留标识符`iskeyword()`

`iskeyword()` 方法用于检查字符串是否是 Python 的保留关键字。
例如：

```python
import keyword #导入关键字模块
my_string = "if"
print(keyword.iskeyword(my_string))
```

输出：

```python
True
```

### 字符串截取

#### 不留空白字符`strip()`

`strip()` 方法用于去除字符串的左右空白字符。
例如：

```python
my_string = " hello world "
print(my_string.strip())
```

输出：

```python
hello world
```

#### 不留空白字符`lstrip()`

`lstrip()` 方法用于去除字符串的左空白字符。
例如：

```python
my_string = " hello world "
print(my_string.lstrip())
```

输出：

```python
hello world
```

#### 不留空白字符`rstrip()`

`rstrip()` 方法用于去除字符串的右空白字符。
例如：

```python
my_string = " hello world "
print(my_string.rstrip())
```

输出：

```python
 hello world
```

==`strip()`, `lstrip()`, `rstrip()` 方法的参数`chars`允许指定要去除的字符。==

例如`strip()`：

```python
my_string = " hello world "
print(my_string.strip(" h"))
```

输出：

```python
ello world
```

`lstrip()`：

```python
my_string = " hello world "
print(my_string.lstrip(" h"))
```

输出：

```python
ello world
```

`rstrip()`：

```python
my_string = " hello world "
print(my_string.rstrip(" h"))
```

输出：

```python
 hello world
```

#### `removeprefix()`

`removeprefix(prefix)` 方法用于去除字符串的前缀。
参数：

- `prefix`：要去除的前缀。
- 返回值：
  - 如果字符串以指定的前缀开头，则返回去除前缀后的字符串。
  - 如果字符串不以指定的前缀开头，则返回原字符串。
  - 如果 `prefix` 参数超出了字符串的范围，则抛出异常。
  - 前缀范围：从字符串的开头到第一个不匹配的字符。
  
例如：

```python
my_string = "hello world"
print(my_string.removeprefix("hello"))
```

输出：

```python
 world
```

#### `removesuffix()`

`removesuffix(suffix)` 方法用于去除字符串的后缀。
参数：

- `suffix`：要去除的后缀。
- 返回值：
  - 如果字符串以指定的后缀结尾，则返回去除后缀后的字符串。
  - 如果字符串不以指定的后缀结尾，则返回原字符串。
  - 如果 `suffix` 参数超出了字符串的范围，则抛出异常。
  - 后缀范围：从字符串的结尾到第一个不匹配的字符。

例如：

```python
my_string = "hello world"
print(my_string.removesuffix("world"))
```

输出：

```python
hello
```

### 字符串的拆分和合并

#### 三元素拆分`partition()`

`partition(sep)` 方法用于将字符串拆分为三个部分。方向为从左到右。
参数：

- `sep`：分隔符。
- 返回值：
  - 如果字符串中包含分隔符，则返回一个包含三个元素的元组，分别是分隔符左边的部分、分隔符本身和分隔符右边的部分。

例如：

```python
my_string = "www.ilovefishc.com.cn"
print(my_string.partition("."))
```

输出：

```python
('www', '.', 'ilovefishc.com.cn')
```

#### 三元素拆分`rpartition()`

`rpartition(sep)` 方法用于将字符串拆分为三个部分。方向为从右到左。
参数：

- `sep`：分隔符。
- 返回值：
  - 如果字符串中包含分隔符，则返回一个包含三个元素的元组，分别是分隔符左边的部分、分隔符本身和分隔符右边的部分。

例如：

```python
my_string = "www.ilovefishc.com.cn"
print(my_string.rpartition("."))
```

输出：

```python
('www.ilovefishc.com', '.', 'cn')
```

#### 分割`split()`

`split(sep, maxsplit)` 方法用于将字符串拆分为多个子字符串。
参数：

- `sep`：分隔符。
- `maxsplit`：可选参数，指定最大分割次数。
- 返回值：
  - 如果字符串中包含分隔符，则返回一个包含多个子字符串的列表。
  - 如果字符串中不包含分隔符，则返回一个包含一个元素的列表，该元素是原字符串。
  - 如果 `maxsplit` 参数指定了分割次数，则最多分割 `maxsplit` 次。
  - 如果 `maxsplit` 参数没有指定，那么默认是-1，则分割所有出现的分隔符。
  - 如果 `maxsplit` 参数指定为 0，则返回一个包含一个元素的列表，该元素是原字符串。

例如：

```python
my_string = "www.ilovefishc.com.cn"
print(my_string.split('.',1))
```

输出：

```python
['www', 'ilovefishc.com.cn']
```

#### 分割`rsplit()`

`rsplit(sep, maxsplit)` 方法用于将字符串拆分为多个子字符串。方向为从右到左。

例如：

```python
my_string = "www.ilovefishc.com.cn"
print(my_string.rsplit('.',1))
```

输出：

```python
['www.ilovefishc.com', 'cn']
```

#### 按行分割`splitlines()`

`splitlines(keepends)` 方法用于将字符串拆分为多个子字符串。
参数：

- `keepends`：可选参数，指定是否保留换行符。
- 返回值：
  - 如果字符串中包含换行符，则返回一个包含多个子字符串的列表。
  - 如果字符串中不包含换行符，则返回一个包含一个元素的列表，该元素是原字符串。
  - 如果 `keepends` 参数指定了true，则保留换行符。
  - 如果 `keepends` 参数没有指定，那么默认是 `False`，则不保留换行符。

例如：

```python
my_string = "www.ilovefishc.com.cn\nwww.fishc.com.cn"
print(my_string.splitlines())
```

输出：

```python
['www.ilovefishc.com.cn', 'www.fishc.com.cn']
```

#### 合并`x.join()`

`x.join(iterable)` 方法用于将多个子字符串合并为一个字符串。
参数：

- `x`：分隔符。
- `iterable`：可迭代对象，包含多个子字符串。

例如：

```python
my_string = "www.ilovefishc.com.cn"
print(".".join(my_string))
```

输出：

```python
w.w.w.i.l.o.v.e.f.i.s.h.c.c.o.m.c.n
```

### 字符串的格式化

#### 格式化字符串`format()`

`format()` 方法用于格式化字符串。
参数：

- `format`：格式化字符串。
- 返回值：
  - 如果格式化字符串中包含占位符，则返回一个格式化后的字符串。
  - 如果格式化字符串中不包含占位符，则返回原字符串。
  
例如：

```python
year = 2010
"鱼c工作室成立于{}年".format(year)
```

输出：

```python
'鱼c工作室成立于2010年'
```

例二：

```python
"1+2={},2的平方是{}".format(1+2,2*2)
```

输出：

```python
'1+2=3,2的平方是4'
```

位置索引例三：

```python
"1+2={1},2的平方是{1}".format(1+2,2*2)
```

输出：

```python
'1+2=4,2的平方是4'
```

关键字索引例四：

```python
"1+2={a},2的平方是{b}".format(a=1+2,b=2*2)
```

输出：

```python
'1+2=4,2的平方是4'
```

#### `[align]`对齐方式

`[align]` 用于指定对齐方式。

- `[align]` 可以是 `<`（左对齐）、`>`（右对齐）、`^`（居中对齐）、`=`（填充字符）。
- `[align]` 可以跟一个数字，表示对齐的宽度。
- `[align]` 可以跟一个字符，表示对齐的字符。

例如：

```python
"1+2={:<10},2的平方是{:>10}".format(1+2,2*2)
```

输出：

```python
'1+2=3       ,2的平方是      4'
```

例二：

```python
"{1:>10}{0:<10}".format(520,250)
```

输出：

```python
'      250520      '
```

解释：

`{1:>10}`中，`1`表示位置索引，`>`表示对齐方向，`10`表示对齐的宽度。

指定填充字符例三：

```python
"{1:=>10}{0:=<10}".format(520,250)
```

输出：

```python
'======250520======'
```

#### 符号选项

`[sign]` 用于指定符号选项。

- `[sign]` 可以是 `+`（显示正号）、`-`（显示负号，且负号是默认的）、`( )`（显示空格）、`0`（显示0）。
- `[sign]` 可以跟一个数字，表示对齐的宽度。
- `[sign]` 可以跟一个字符，表示对齐的字符。

例如：

```python
"{:+}{:-}".format(520,-250)
```

输出：

```python
+520-250
```

#### 切分选项

`[split]` 用于指定切分选项。

- `[split]` 可以是 `,`（千分位分隔符）、`_`（下划线分隔符）。
- `[split]` 可以跟一个数字，表示对齐的宽度。
- `[split]` 可以跟一个字符，表示对齐的字符。

例如：

```python
"{:,}".format(1000000000)
```

输出：

```python
'1,000,000,000'
```

#### 精度选项

`[precision]` 用于指定精度选项。

- `[type]` 可以是 `f`（浮点数）、`e`（科学计数法）、`g`（自动选择）、`%`（百分比）。
- 对于`[type]`设置为`f`或`F`的浮点数来说，表示小数点后的位数。
- 对于`[type]`设置为`g`或`G`的浮点数来说，表示有效数字的位数。
- 对于非数字类型来说，表示输出的最大长度。
- 对于整数类型来说，不允许设置精度选项`[precision]`

例如：

```python
"{:.2f}".format(3.1415926)
```

输出：

```python
'3.14'
```

例二：

```python
"{:.2g}".format(3.1415926)
```

输出：

```python
'3.1'
```

例三：

```python
"{:.6}".format("I love Fishc")
```

输出：

```python
'I love '
```

#### 类型选项

`[type]` 用于指定类型选项。

以下是各种类型选项的表格：

| 类型选项 | 描述 | 示例 |
| --- | --- | --- |
| `s` | 字符串 | `"{:s}".format("Fishc")` |
| `d` | 十进制整数 | `"{:d}".format(10)` |
| `b` | 二进制整数 | `"{:b}".format(10)` |
| `o` | 八进制整数 | `"{:o}".format(10)` |
| `x` | 十六进制整数（小写） | `"{:x}".format(10)` |
| `X` | 十六进制整数（大写） | `"{:X}".format(10)` |
| `e` | 科学计数法（小写） | `"{:e}".format(10)` |
| `E` | 科学计数法（大写） | `"{:E}".format(10)` |
| `f` | 浮点数（默认保留6位小数） | `"{:f}".format(10)` |
| `F` | 浮点数（默认保留6位小数） | `"{:F}".format(10)` |
| `g` | 自动选择（根据值的大小选择科学计数法或浮点数） | `"{:g}".format(10)` |
| `G` | 自动选择（根据值的大小选择科学计数法或浮点数） | `"{:G}".format(10)` |
| `%` | 百分比 | `"{:%}".format(0.1)` |

### f-string

f-string 是 Python 3.6 引入的一种字符串格式化方式。

f-string 的语法是在字符串的开头加上 `f` 或 `F`，然后在字符串中使用 `{}` 来表示要插入的值。

例如：

```python
name = "Fishc"
age = 18
print(f"我的名字是{name}，我今年{age}岁")
```

输出：

```python
我的名字是Fishc，我今年18岁
```

例二：

```python
fill = '+'
align = '^'
width = 10
prec = 3
ty = 'g'
f"{3.1415:{fill}{align}{width}.{prec}{ty}}"
```

输出：

```python
'+++3.14+++'
```

## `id`

`id()` 函数用于获取对象的内存地址。
参数：

- `object`：对象。
- 返回值：
  - 返回对象的内存地址。
  - 如果对象不存在，则返回 `None`。

## 序列

序列是 Python 中最基本的数据结构。

序列中的每个元素都分配一个数字 - 它的位置，或索引，第一个索引是 0，第二个索引是 1，依此类推。

可变序列：

- 列表（list）
- 字典（dict）
- 集合（set）

不可变序列：

- 字符串（str）
- 元组（tuple）

### 序列运算符

Python 中的序列支持以下运算符：

- `+`：连接
- `*`：重复

### 判断元素是否在序列中`in` 和 `not in`

`in` 和 `not in` 用于判断元素是否在序列中。

- `in`：如果在指定的序列中找到值返回 `True`，否则返回 `False`。
- `not in`：如果在指定的序列中没有找到值返回 `True`，否则返回 `False`。
- `in` 和 `not in` 都可以用于字符串、列表、元组、字典等序列类型。

例如：

```python
my_list = [1, 2, 3, 4, 5]
print(3 in my_list)
print(6 in my_list)
print(3 not in my_list)
print(6 not in my_list)
```

输出：

```python
True
False
False
True
```

### 删除一个或多个指定的对象`del`

`del` 语句用于删除一个或多个指定的对象。

- `del` 语句可以删除单个对象，也可以删除多个对象。
- `del` 语句可以删除列表、元组、字典、集合等序列类型。
- `del` 语句可以删除变量，也可以删除对象的属性。

例如(运用切片):

```python
my_list = [1, 2, 3, 4, 5]
del my_list[1:3]
print(my_list)
```

输出：

```python
[1, 4, 5]
```

### 跟序列相关的函数

#### 序列之间的转换

`list(seq)`：将序列转换为列表。
`tuple(seq)`：将序列转换为元组。
`str(seq)`：将序列转换为字符串。

例如：

```python
list("Fishc")
tuple("Fishc")
str([1,2,3,4,5])
```

输出：

```python
['F', 'i', 's', 'h', 'c']
('F', 'i', 's', 'h', 'c')
'[1,2,3,4,5]'
```

#### `min`和`max`

一、
`min(seq,default="")`：返回序列中的最小值。`default`参数用于指定默认值。
`max(seq,default="")`：返回序列中的最大值。

例如：

```python
min([1,2,3,4,5])
max([],default="什么也没有")
```

输出：

```python
1
'什么也没有'
```

二、
直接传入参数：

```python
min(1,2,3,4,5)
max(1,2,3,4,5)
```

输出：

```python
1
5
```

#### 计算长度`len()`和求和`sum()`

`len(seq)`：返回序列的长度。
`sum(seq)`：返回序列中所有元素的和。
`sum(seq,start)`：返回序列中所有元素的和加上`start`的值。
例如：

```python
len([1,2,3,4,5])
sum([1,2,3,4,5])
sum([1,2,3,4,5],10)
```

输出：

```python
5
15
25
```

#### 重新排序`sorted()`

`sorted(seq)`：返回一个新的已排序列表。
`sorted(seq,key=func)`：返回一个新的已排序列表，`key`参数用于指定排序规则。
`sorted(seq,reverse=True)`：返回一个新的已排序列表，降序排列。
== 注意：==
`sorted()` 函数不会改变原序列，而是返回一个新的已排序列表。
如果需要对原序列进行排序，可以使用 `sort()` 方法。但是 `sort()` 方法只能用于列表,而`sorted()`函数可以用于任何可迭代对象。
例如：

```python
s=[2,1,3,4,5]
sorted(s)
s
sorted(s,reverse=True)
s.sort()
s
```

输出：

```python
[1,2,3,4,5] #全新列表
[2,1,3,4,5] #s未被改变
[5,4,3,2,1] #全新列表
[5,4,3,2,1] #s被改变
```

例二：

```python
s=["apple","pear","banana","orange"]
sorted(s,key=len) #按照长度排序
s.sort(key=len) #按照长度排序
s
```

输出：

```python
['pear','apple','banana','orange']
['pear','apple','banana','orange']
```

#### `reversed()`

`reversed(seq)`：返回一个反转的迭代器。
`list(reversed(seq))`：返回一个反转的列表。
`tuple(reversed(seq))`：返回一个反转的元组。
例如：

```python
s=[1,2,5,8,0]
reversed(s)
list(reversed(s))
tuple(reversed(s))
```

输出：

```python
<list_reverseiterator object at 0x000001E680748E80> #迭代器
[0,8,5,2,1] #列表
(0,8,5,2,1) #元组
```

#### 判断元素值是否为真`any()`和`all()`

`any(seq)`：如果序列中的任何一个元素为真，则返回 `True`，否则返回 `False`。
`all(seq)`：如果序列中的所有元素都为真，则返回 `True`，否则返回 `False`。
例如：

```python
any([0,0,0,2])
all([0,0,0,2])
```

输出：

```python
True
False
```

#### 枚举`enumerate()`

`enumerate(seq,x)`：返回一个枚举对象。`x`参数用于指定起始索引。
`list(enumerate(seq))`：返回一个枚举对象的列表。
`tuple(enumerate(seq))`：返回一个枚举对象的元组。
例如：

```python
seasons = ["Spring", "Summer", "Fall", "Winter"]
enumerate(seasons)
list(enumerate(seasons))
list(enumerate(seasons,start=10))
tuple(enumerate(seasons))
```

输出：

```python
<enumerate object at 0x000001E680748E80> #迭代器
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')] #列表
[(10, 'Spring'), (11, 'Summer'), (12, 'Fall'), (13, 'Winter')] #列表
((0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')) #元组
```

#### 创建一个聚合多个可迭代对象的迭代器`zip()`

`zip(seq1,seq2)`：返回一个元组列表，其中每个元组包含来自每个序列的一个元素。
`list(zip(seq1,seq2))`：返回一个元组列表。
`tuple(zip(seq1,seq2))`：返回一个元组列表。

例如：

```python
s1=[1,2,3,4,5]
s2=["a","b","c","d","e"]
zip(s1,s2)
list(zip(s1,s2))
tuple(zip(s1,s2))
```

输出：

```python
<zip object at 0x000001E680748E80> #迭代器
[(1, 'a'), (2, 'b'), (3, 'c'), (4, 'd'), (5, 'e')] #列表
((1, 'a'), (2, 'b'), (3, 'c'), (4, 'd'), (5, 'e')) #元组
```

例二：

```python
s1=[1,2,3]
s2=["a","b","c","d","e"]
zip(s1,s2)
list(zip(s1,s2))
tuple(zip(s1,s2))
```

输出：

```python
<zip object at 0x000001E680748E80> #迭代器
[(1, 'a'), (2, 'b'), (3, 'c')] #列表
((1, 'a'), (2, 'b'), (3, 'c')) #元组
```

##### `itertools`解决`zip()`函数丢掉元素问题

`itertools.zip_longest(seq1,seq2)`：返回一个元组列表，其中每个元组包含来自每个序列的一个元素。如果序列长度不同，则使用 `None` 填充缺失的值。

例如：

```python
import itertools
s1=[1,2,3]
s2=["a","b","c","d","e"]
itertools.zip_longest(s1,s2)
list(itertools.zip_longest(s1,s2))
tuple(itertools.zip_longest(s1,s2))
```

输出：

```python
<zip_longest object at 0x000001E680748E80> #迭代器
[(1, 'a'), (2, 'b'), (3, 'c'), (None, 'd'), (None, 'e')] #列表
((1, 'a'), (2, 'b'), (3, 'c'), (None, 'd'), (None, 'e')) #元组
```

#### 对指定的可迭代对象的元素计算`map()`

`map(func,seq)`：返回一个迭代器，其中每个元素都是 `func` 函数对 `seq` 序列中对应元素的应用。
`list(map(func,seq))`：返回一个列表。
`tuple(map(func,seq))`：返回一个元组。
例如：

```python
mapped = map(ord, "Fishc") #ord()函数返回一个字符的ASCII值
list(mapped)
mapped = map(pow, [1, 2, 3], [2, 3, 4]) #pow()函数返回x的y次幂
list(mapped)
[pow(1,2),pow(2,3),pow(3,4)] #pow正常用法
list(map(max,[1,2,3],[4,5,6],[7,8,9,10])) #max()函数返回给定参数的最大值
```

输出：

```python
[70, 83, 104, 99] #列表
[1, 8, 81] #列表
[1，8, 81]
[7, 8, 9] #列表,10被舍弃
```

#### 对指定的可迭代对象的元素进行过滤`filter()`

`filter(func,seq)`：返回一个迭代器，`seq` 序列中每个元素都应用 `func` 函数进行判断，返回 `True` 的元素会被保留。
`list(filter(func,seq))`：返回一个列表。
`tuple(filter(func,seq))`：返回一个元组。
例如：

```python
list(filter(str.islower, "FishC")) #islower()方法检测字符串是否由小写字母组成
```

输出：

```python
['i', 's', 'h'] #列表
```

### 迭代器和可迭代对象

二者关系：
迭代器是可迭代对象，可迭代对象不一定是迭代器。

可迭代对象是可以反复使用，而迭代器是一次性的。

例如：

```python
mappped = map(ord, "Fishc") #ord()函数返回一个字符的ASCII值
for each in mappped: #mappped是一个迭代器，只能使用一次
    print(each)
list(mappped) #mappped已经被使用过了，所以返回一个空列表
```

输出：

```python
70
83
104
99
[] #空列表，说明mappped已经被使用过了
```

#### `iter()`和`next()`

`iter(seq)`：返回一个迭代器对象。
`next(iter)`：返回迭代器的下一个元素。
例如：

```python
x = [1,2,3,4,5]
y = iter(x) #iter()函数返回一个迭代器对象
next(y) #next()函数返回迭代器的下一个元素
next(y)
next(y)
next(y)
next(y) #迭代器已经没有元素了，会报错
z = iter(x) #iter()函数返回一个迭代器对象
next(z,"没有了") #next()函数返回迭代器的下一个元素，如果没有元素了，会返回"没有了"
next(z,"没有了")
next(z,"没有了")
next(z,"没有了") 
next(z,"没有了")
next(z,"没有了") #迭代器已经没有元素了，会返回"没有了"
```

输出：

```python
1
2
3
4
5
#这里会报错
1
2
3
4
5
'没有了' #说明迭代器已经没有元素了，会返回"没有了"
```

## 字典

字典是一种可变容器模型，且可存储任意类型对象。

字典的每个键值(key=>value)对用冒号(:)分割，每个对之间用逗号(,)分割，整个字典包括在花括号({} )中。

### 创建字典

创建字典的方法有以下几种：

- 使用花括号 `{}` 创建字典。

  ```python
  a = {"吕布"："貂蝉"，"曹操"："刘备"，"孙权"："周瑜"}
  ```

- 使用 `dict()` 函数创建字典。

  ```python
  b = dict(name="xyf", age=18, sex="男")
  ```

- 使用`dict()`与列表的组合创建字典。

  ```python
  c = dict([("吕布"，"貂蝉")，("曹操"，"刘备")，("孙权"，"周瑜")])
  ```

- 将第一种方法作为参数传入`dict()`函数创建字典。

  ```python
  d = dict({"吕布"："貂蝉"，"曹操"："刘备"，"孙权"："周瑜"})
  ```

- 混合法
  
  ```python
  e = dict([("吕布"，"貂蝉")，("曹操"，"刘备")，("孙权"，"周瑜")]，name="xyf"，age=18，sex="男")
  ```

- 利用`zip()`函数创建字典。

  ```python
  f = dict(zip(["吕布","曹操","孙权"],["貂蝉","刘备","周瑜"]))
  ```

  ### 字典方法

  #### 增`fromkeys(iterable,value)`

  `fromkeys(iterable,value)`：创建一个新字典，其中包含来自 `iterable` 的键，每个键的值都设置为 `value`。

  例如：

  ```python
  d = dict.fromkeys("FishC",520)
  d
  ```

  输出：

  ```python
  {'F': 520, 'i': 520, 's': 520, 'h': 520, 'C': 520}
  ```

  如果需要修改某个键的值，可以直接赋值。

  例如：

  ```python
  d['F'] = 666
  d
  ```

  输出：

  ```python
  {'F': 666, 'i': 520,'s': 520, 'h': 520, 'C': 520}
  ```

  如果在修改时，找不到键，就会在字典中添加这个键。

  例如：

  ```python
  d['xyf'] = 666
  d
  ```

  输出：

  ```python
  {'F': 666, 'i': 520,'s': 520, 'h': 520, 'C': 520,'xyf': 666}
  ```

  #### 删`pop(key,default)`

  `pop(key)`：删除字典中指定键 `key` 的键值对，并返回该键对应的值，如果键不存在，则会抛出 `KeyError` 异常,可以使用 `pop()` 方法的第二个参数指定默认值，在键不存在时返回默认值。

  例如：

  ```python
  d.pop("F")
  d.pop("dog","None")
  ```

  输出：

  ```python
  666 #返回值
  'None' #返回值
  ```

##### `popitem()`

`popitem()`：删除字典中最后一个键值对，并返回该键值对的元组。

例如：

```python
d.popitem()
```

输出：

```python
('xyf', 666) #返回值
```

##### `del`

`del`：删除字典中指定键 `key` 的键值对，如果键不存在，则会抛出 `KeyError` 异常。

例如：

```python
del d["i"]
del d
```

输出：

```python
666 #返回值
NameError: name 'd' is not defined #报错
```

##### `clear()`

`clear()`：删除字典中所有的键值对。

例如：

```python
d.clear()
```

输出：

```python
{} #返回值 空字典
```

#### 改

##### `update()`

`update()`：更新字典中的键值对，如果键不存在，则会添加该键值对。

例如：

```python

d = dict.fromkeys("FishC")
d
d.update({"F":520,"i":666})
d
```

输出：

```python
{'F': None, 'i': None,'s': None, 'h': None, 'C': None} #返回值
{'F': 520, 'i': 666,'s': None, 'h': None, 'C': None} #返回值
```

#### 查

##### `get(key,default)`

`get(key,default)`：返回字典中指定键 `key` 的对应值，如果键不存在，则返回 `default` 的值，如果 `default` 未指定，则会报错。

例如：

```python
d.get("F")
d.get("dog","None")
```

输出：

```python
520 #返回值
None #返回值
```

##### `setdefault(key,default)`

`setdefault(key,default)`：返回字典中指定键 `key` 的对应值，如果键不存在，则会添加该键值对，并将值设置为 `default` 的值，如果 `default` 未指定，则会报错。

例如：

```python
d.setdefault("dog","None")
d
```

输出：

```python
None #返回值
{'F': 520, 'i': 666,'s': None, 'h': None, 'C': None,'dog':'None'} #返回值
```

#### 获取视图对象

视图对象是字典的视图，它是一个动态的视图，当字典发生变化时，视图也会相应地发生变化。

##### `keys()`  `values()` 和 `items()`

`keys()`：返回字典中所有的键。
`values()`：返回字典中所有的值。
`items()`：返回字典中所有的键值对。

例如：

```python
keys = d.keys()
values = d.values()
items = d.items()
keys
values
items
d.pop("F") #删除键值对
keys
values
items #视图对象相应地发生变化
```

输出：

```python
dict_keys(['F', 'i', 's', 'h', 'C']) #返回值
dict_values([520, 666, None, None, None]) #返回值
dict_items([('F', 520), ('i', 666), ('s', None), ('h', None), ('C', None)]) #返回值

dict_keys(['i','s', 'h', 'C']) #返回值
dict_values([666, None, None, None]) #返回值
dict_items([('i', 666), ('s', None), ('h', None), ('C', None)]) #返回值
```

#### 浅拷贝`copy()`

例如：

```python
e = d.copy()
e
```

输出：

```python
{'i': 666, 's': None, 'h': None, 'C': None} #返回值
```

#### 获取键值对数量`len()`

例如：

```python
len(d) #获取字典键值对数量
```

输出：

```python
4 #返回值
```

#### 判断键是否存在`in`和`not in`

例如：

```python
"F" in d #判断键是否存在
"F" not in d #判断键是否不存在
```

输出：

```python
True #返回值
False #返回值
```

#### 字典转列表`list()`

例如：

```python
list(d) #将字典键转换为列表
list(d.values()) #将字典值转换为列表
```

输出：

```python
['i', 's', 'h', 'C'] #返回值
[666, None, None, None] #返回值
```

#### 把字典的键构成迭代器`iter()` `next()`

例如：

```python
e = iter(d) #将字典键转换为迭代器
next(e) #返回迭代器的下一个元素
next(e) 
next(e) 
next(e)
next(e) #迭代器已经没有元素了，会报错
```

输出：

```python
'i' #返回值
's' #返回值
'h' #返回值
'C' #返回值
#这里会报错
```

#### 逆序`reversed()`

例如：

```python
reversed(d) #将字典键逆序
list(reversed(d)) #将字典键逆序转换为列表
```

输出：

```python
reversed(d) #返回值
['C', 'h', 's', 'i'] #返回值
```

### 嵌套

例如：

```python
d = {"吕布":{"语文":20,"数学":30},"关羽":{"语文":100,"数学":70}}
d["吕布"]["语文"] #获取吕布的语文成绩
d["关羽"]["语文"] #获取关羽的语文成绩
```

输出：

```python
20 #返回值
100 #返回值
```

### 与列表嵌套

例如：

```python
d = {"吕布"：[60,70,20],"关羽"：[100,70,30]}
d["吕布"][2] 
```

输出：

```python
20 #返回值
```

### 字典推导式

字典推导式是一种快速创建字典的方法，它可以从一个可迭代对象中创建字典。
语法为：

```python
{key_expression: value_expression for expression in iterable}
```

解释为：

- `key_expression`：用于生成字典的键。
- `value_expression`：用于生成字典的值。
- `expression`：用于遍历可迭代对象中的每个元素。
- `iterable`：可迭代对象。

例如：

```python
d = {'F':70,'i':105,'s':115,'h':104,'C':67}
d = {v:k for k,v in d.items() if v > 100} #创建一个新字典，其中包含键值对的值大于100的键值对,并将键和值交换
d
```

输出：

```python
{105: 'i', 115: 's',104:'h'} #返回值
```

例二：

```python
d = {'F':70,'i':105,'s':115,'h':104,'C':67}
d = {x:ord(x) for x in d} #创建一个新字典，其中包含键值对的键和值的ASCII值
d
```

输出：

```python
{'F': 70, 'i': 105, 's': 115, 'h': 104, 'C': 67} #返回值
```

思考一下：

```python
d = {x:y for x in [1,3,5] for y in [2,4,6]}
d
```

输出：

```python
{1:6,3:6,5:6} #返回值
```

## 集合

集合是一种无序、不重复的数据结构，它的元素可以是任意类型的对象。

### 创建可变（不可变）集合

集合分为可变和不可变集合。
创建可变集合的方法有以下几种：

- 使用花括号 `{}` 创建集合。

  ```python
  a = {1,2,3,4,5}
  ```

- 集合推导式

  ```python
  b = {x for x in "FishC"}
  ```

  输出：

  ```python
  {'F', 'i', 's', 'h', 'C'} #返回值
  ```

- 使用 `set()` 函数创建集合。

  ```python
  d = set("FishC")
  ```

  输出：

  ```python
  {'F', 'i','s', 'h', 'C'} #返回值
  ```

而不可变几何则是使用 `frozenset()` 函数创建集合。

例如：

```python
a = frozenset("FishC")
a
```

输出：

```python
frozenset({'F', 'i','s', 'h', 'C'}) #返回值
```

### 访问集合

由于集合是无序的，所以不能通过索引访问集合中的元素。

例如：

```python
a = {1,2,3,4,5}
a[0] #报错
```

输出：

```python
#这里会报错
```

运用循环遍历集合中的元素。

例如：

```python
for x in a:
    print(x)
```

输出：

```python
1 #返回值
2 #返回值
3 #返回值
4 #返回值
5 #返回值
```

### 利用集合唯一性去重

例如：

```python
a = {1,2,3,4,5,1,2,3,4,5} #集合中的元素是唯一的
set(a)
```

输出：

```python
{1,2,3,4,5} #返回值
```

### （可变）集合方法

#### 检测集合之间毫不相干`isdisjoint()`

例如：

```python
a = set("Python")
b = set("FishC")
a.isdisjoint(set(b)) #检测集合之间是否毫不相干
```

输出：

```python
False #返回值
```

#### 检测集合是否是另一个集合的子集`issubset()`

例如：

```python
a = set("Fish")
b = set("FishC.py")
a.issubset(b) #检测集合a是否是集合b的子集
```

输出：

```python
True #返回值
```

#### 检测集合是否是另一个集合的超集`issuperset()`

例如：

```python
a = set("Fish")
b = set("FishC.py")
a.issuperset(b) #检测集合a是否是集合b的超集
```

输出：

```python
False #返回值
```

#### 集合的并集`union()`

例如：

```python
a = set("apple")
b = set("FishC.py")
a.union(b) #集合的并集
```

输出：

```python
{'a', 'e', 'i', 'l', 'p', 's', 'h', 'F', 'C', 'y', '.'} #返回值
```

#### 集合的交集`intersection()`

例如：

```python
a = set("apple")
b = set("FishC.py")
a.intersection(b) #集合的交集
```

输出：

```python
{'p'} #返回值
```

#### 集合的差集`difference()`

例如：

```python
a = set("Fishs")
b = set("FishC.py")
a.difference(b) #集合的差集
```

输出：

```python
{'s'} #返回值
```

#### 集合的对称差集`symmetric_difference()`

例如：

```python
a = set("Fishs")
b = set("FishC.py")
a.symmetric_difference(b) #集合的对称差集
```

输出：

```python
{'s', 'C', 'y', '.','p'} #返回值
```

#### 集合检测运算

检测符号：

- `>`：检测是否是真超集。
- `<`：检测是否是真子集。
- `>=`：检测是否是超集。
- `<=`：检测是否是子集。
- `==`：检测是否相等。
- `!=`：检测是否不相等。

例如：

```python
a = set("Fishs")
b = set("FishC.py")
a > b #检测集合a是否是集合b的真超集
a < b #检测集合a是否是集合b的真子集
a >= b #检测集合a是否是集合b的超集
a <= b #检测集合a是否是集合b的子集
a == b #检测集合a是否等于集合b
a != b #检测集合a是否不等于集合b
```

输出：

```python
False #返回值
False #返回值
False #返回值
False #返回值
True #返回值
False #返回值
```

运算符号：

- `&`：交集。
- `|`：并集。
- `-`：差集。
- `^`：对称差集。

例如：

```python
a = set("Fishs")
b = set("FishC.py")
a & b #集合的交集
a | b #集合的并集
a - b #集合的差集
a ^ b #集合的对称差集
```

输出：

```python
{'p'} #返回值
{'a', 'e', 'i', 'l', 'p','s', 'h', 'F', 'C', 'y', '.'} #返回值
{'s'} #返回值
{'s', 'C', 'y', '.'} #返回值
```

#### 添加元素`update()`

`update()` 方法用于将一个集合中的元素添加到另一个集合中。

例如：

```python
a = set("Fishs")
a.update([1,1],"23") #将列表[1,1]和字符串"23"中的添加到集合a中
a
```

输出：

```python
{'s', 'F', 'i', 'h', '1', '3'，'2'} #返回值,体现了集合的唯一性和无序性
```

##### `intersection_update()`

例如：

```python
a = set("FishC")
b = set("Fishes")
a.intersection_update(b) #集合的交集
a
```

输出：

```python
{'i', 's', 'h', 'F'} #返回值
```

##### `difference_update()`

例如：

```python
a = set("FishC")
b = set("Fishes")
a.difference_update(b) #集合的差集
a
```

输出：

```python
{'C'} #返回值
```

##### `symmetric_difference_update()`

例如：

```python
a = set("FishC")
b = set("Fishes")
a.symmetric_difference_update(b) #集合的对称差集
a
```

输出：

```python
{'e','c'}
```

#### 添加元素`add()`

`add()` 方法用于将一个元素添加到集合中。和 `update()` 方法不同的是，`add()` 方法只能添加一个元素。而且在传入字符串时，会将整个字符串作为一个元素添加到集合中。

例如：

```python
a = set("FishC")
a.add("Fish") #将字符串"Fish"添加到集合a中
a
a.update("Fish") #将字符串"Fish"中的每个字符添加到集合a中
a
```

输出：

```python
{'C', 'F', 'i', 'h', 'Fish'} #返回值
{'C', 'F', 'i', 'h', 'F', 'i', 's', 'h'} #返回值
```

#### 删除元素`remove()`和`discard()`

`remove()` 方法用于删除集合中的指定元素。如果指定的元素不存在，则会抛出 `KeyError` 异常。而 `discard()` 方法用于删除集合中的指定元素。如果指定的元素不存在，则不会抛出异常。

例如：

```python
a = set("FishC")
a.remove("x") #删除集合a中的元素"F"
a
a.discard("x") #删除集合a中的元素"F"
a
```

#### 随机删除元素`pop()`

`pop()` 方法用于随机删除集合中的一个元素，并返回该元素。

例如：

```python
例如：
a = set("FishC")
a.pop() #随机删除集合a中的一个元素
a
```

## 哈希`hash(x)`

创建字典和集合都有一个硬性要求，就是字典的键和集合的元素必须可哈希，利用`hash(x)`可以求出x的哈希值
一般来说，不可变的对象都有哈希值，而可变对象没有哈希值。

## 函数

例如：

```.
  def myfunc():
      pass
```

解释：
  `def` 用来定义函数，`myfunc`是定义的函数名，冒号`:`之后就是函数体,`pass`经常用来当占位符，没什么实际用处，理解为，做个记号，后期替换pass处，补充功能。括号`()`里面，可以需要传入的参数

例如：

```.
def myfunc(name,times):
  for i in range(3):
            print("I love python")
myfunc("python",5)
```

### 返回值

```.
def div(x,y):
      if y == 0:
         return"除数不能为0！"
      return x/y
div(3,2)
```

### 位置参数

```.python
def myfunc(s,vt,o):
      return"".join((o,vt,s))
myfunc("Fish","C","Py")
```

解释：
`join()`方法用于将序列中的元素以指定的字符连接生成一个新的字符串。

输出

```.
PyCFish
```

### 关键字参数

```.
def myfunc(s,vt,o):
      return"".join((o,vt,s))
myfunc(o="Fish",vt="C",s="Py")
```

输出

```.
FishCpy
```

==位置参数一定要在关键字参数之前==

### 默认参数

```.
def myfunc(s,vt,o="Fish"):
      return"".join((o,vt,s))
myfunc("Py","C")
```

这里的o是默认参数，在调用函数时，如果没有传入o的值，则会使用默认值。

==默认参数一定要在位置参数之后==

输出：

```.
FishCPy
```

### `/`和`*`

`/`和`*`是Python 3.8中新增的语法，用于指定函数的参数类型。

`/`表示位置参数，`*`表示关键字参数。

例如：

```.
def myfunc(a,/,b,c):
      print(a,b,c)
abc(a=1,2,3)
```

输出：

```.
TypeError: myfunc() got some positional-only arguments passed as keyword arguments: 'a'
```

解释：
`/`限制了其左边不能使用关键字参数。但是任意位置可以使用位置参数。

例二：

```.
def myfunc(a,*b,,c):
      print(a,b,c)
abc(1,2,c=3)
```

输出：

```.
TypeError: myfunc() got some positional-only arguments passed as keyword arguments: 'a'
```

解释：
`*`限制了其右边不能使用位置参数。但是任意位置可以使用关键字参数。

### 收集参数

收集参数是指在函数定义时，使用`*`或`**`来表示收集参数。收集参数的过程是将传入的参数收集到一个元组或字典中。

例如：

```.
def myfunc(*args):
      print("有{}个参数".format(len(args)))
      print(args)
myfunc(1,2,3,4,5)
```

输出：

```.
有5个参数
(1,2,3,4,5)
```

### 关键字收集参数

例如：

```.
def myfunc(*args,a,b): #这里的a，b必须用关键字参数传入
      print(args,a,b)
myfunc(1,2,3,4,5,a=6,b=7)
```

输出：

```.
(1,2,3,4,5) 6 7
```

### 字典收集参数

例如：

```.
def myfunc(**kwargs):
      print(kwargs)
myfunc(a=1,b=2,c=3)
```

输出：

```.
{'a':1,'b':2,'c':3}
```

### 收集参数的混合使用

例如：

```.py
def myfunc(a,*args,**kwargs):
      print(a,args,kwargs)
myfunc(1,2,3,4,5,a=6,b=7)
```

输出：

```.
1 (2,3,4,5) {'a':6,'b':7}
```

### 收集参数的解包

例如：

```.
args = (1,2,3,4) #元组
def myfunc(a,b,c,d):
      print(a,b,c,d)
myfunc(*args) #将元组解包，然后把解出来的四个值分别传入到函数中
```

输出：

```.
1 2 3 4
```

例如：

```.
kwargs = {'a':1,'b':2,'c':3,'d':4} #字典
def myfunc(a,b,c,d):
      print(a,b,c,d)
myfunc(**kwargs) #将字典解包，然后把解出来的四个值分别传入到函数中
```

输出：

```.
1 2 3 4
```

### 作用域

作用域是指变量的作用范围。

### `global`

`global` 关键字用于在函数内部声明一个全局变量,并且可以改变函数外部的全局变量的值。

### 嵌套函数

函数里面用函数。

### `nonlocal`

`nonlocal` 关键字用于在函数内部声明一个非局部变量,并且可以改变函数外部的非局部变量的值。

### LEGB

LEGB 是 Python 中用于查找变量的规则。

- L（Local）：局部作用域，函数内部的作用域。
- E（Enclosing）：闭包函数外的函数中。
- G（Global）：全局作用域，模块级别的作用域。
- B（Built-in）：内置作用域，Python 内置的作用域。

### 闭包

闭包是指一个函数内部定义的函数，这个内部函数可以访问外部函数的变量。

例如：

```.
def outer():
      x = 10 #外部函数的变量
      def inner():
            print(x) #内部函数可以访问外部函数的变量
      return inner
f = outer() #调用外部函数，返回内部函数，此时`f`就相当于是`inner`
f() #调用内部函数
```

输出：

```.
10
```

==利用内部函数可以访问外部函数的变量，实现函数的记忆功能==

例如：

```.
def outer():
      x = 0 #外部函数的变量
      def inner(x1):
            nonlocal x #声明非局部变量，可以改变函数外部的非局部变量的值
            x += 1 #内部函数可以访问外部函数的变量
            print(x) #内部函数可以访问外部函数的变量
      return inner
f = outer() #调用外部函数，返回内部函数,c此时`f`就相当于是`inner`
f(2) #调用内部函数
```

输出：

```.
1
```

紧接着：

```.
f(3) #调用内部函数，此时外部函数的x已经改变了
```

输出：

```.
2
```

### 装饰器

装饰器是一种特殊的函数，它可以用来修改其他函数的行为。其优势在于可以在不修改原函数的情况下，增加新的功能。

例如：

```.
def outer(func): #装饰器
      def inner(): #内部函数
            print("装饰器") #装饰器的功能
            func() #调用被装饰的函数
      return inner #返回内部函数
@outer #装饰器，相当于myfunc = outer(myfunc)
def myfunc(): #被装饰的函数
      print("函数") #被装饰的函数的功能
myfunc() #调用被装饰的函数
```

输出：

```.
装饰器
函数
```

#### 多个装饰器的使用

例如：

```.
def add(func):
      der inner():
            x = func() #调用被装饰的函数
            return x + 1 #返回被装饰的函数的返回值
      return inner #返回内部函数
def cube(func):
      def inner():
            x = func() #调用被装饰的函数
            return x*x*x #返回被装饰的函数的返回值
      return inner #返回内部函数
def square(func):
      def inner():
            x = func() #调用被装饰的函数
            return x*x #返回被装饰的函数的返回值
      return inner #返回内部函数
@add #装饰器，相当于myfunc = add(myfunc)
@cube #装饰器，相当于myfunc = cube(myfunc)
@square #装饰器，相当于myfunc = square(myfunc)
def myfunc(): #被装饰的函数
      return 2 #被装饰的函数的功能
myfunc() #调用被装饰的函数
print(myfunc()) #调用被装饰的函数
```

输出：

```.
65
```

解释：`@square`装饰器先装饰`myfunc`，然后`@cube`装饰器再装饰`myfunc`，最后`@add`装饰器再装饰`myfunc`。

#### 给装饰器传入参数

例如：

```.py
import time
def logger(msg):
   def time_master(func):
      def call_func():
         start = time.time()
         func()
         stop = time.time()
         print(f"[{msg}]一共消费了{(stop-start):.2f}")
      return call_func
   return time_master
@logger(msg="A") #装饰器，相当于funA = logger(msg="A")(funA)
def funA():
   time.sleep(1)
   print("正在调用funA...")
@logger(msg="B") #装饰器，相当于funB = logger(msg="B")(funB)
def funB():
   time.sleep(2)
   print("正在调用funB...")
funA() #调用被装饰的函数
funB() #调用被装饰的函数
```

输出：

```.
正在调用funA...
[A]一共消费了1.00
正在调用funB...
[B]一共消费了2.00
```

解释：`@logger(msg="A")`装饰器先装饰`funA`，然后`@logger(msg="B")`装饰器再装饰`funB`。

### lambda表达式

lambda表达式是一种匿名函数，它可以用来创建一个函数对象。
语法：

```.
lambda 参数列表: 表达式
```

例如：

```.
def squareX(x):
   return x*x
```

可以写成：

```.
squareX = lambda x: x*x
```

放到列表里面：

```.
y = [lambda x: x*x,2,3]
y[0](3) #调用列表中的第一个元素，即函数对象，然后传入参数3
y[0](2) #调用列表中的第二个元素，即2
```

输出：

```.
9
4
```

==lambda是一个表达式，可以实现一些简单的功能，但是不能实现复杂的功能，所以可以放到函数里面做参数，可以放在列表里面做元素等等等==

### 生成器

我们可以通过闭包，来实现函数的记忆功能，但是这样的话，过多的全局变量，会导致代码的可读性很差，所以我们可以使用生成器来实现函数的记忆功能。

生成器是一种特殊的迭代器，特点是可以在迭代的过程中不断的==产生==值。（即每次调用时只会提供一个数据，并且可以记住当时的状态）

==生成器支持迭代器协议，即实现了`__iter__`和`__next__`方法==

例如：

```.
def counter():
   i = 0
   while i<=5 :
      yield i #yield是一个关键字，用来产生一个值，并且可以记住当时的状态
      i += 1
for i in counter(): #for循环会自动调用next方法，直到抛出StopIteration异常
   print(i) #打印每次产生的值
```

输出：

```.
0
1
2
3
4
5
```

解释：`yield`是一个关键字，用来产生一个值，并且可以记住当时的状态。

==生成器中，使用下角标来访问生成器中的值是会报错的，这也说明，生成器是产生值，而不是保存值==
例如：

```.
def counter():
   i = 0
   while i<=5 :
      yield i #yield是一个关键字，用来产生一个值，并且可以记住当时的状态
      i += 1
c = counter() #创建一个生成器对象
c[0] #访问生成器中的第一个值，会报错
next(c) #访问生成器中的第一个值
```

输出：

```.
TypeError: 'generator' object is not subscriptable
0
```

==生成器可以使用`next`方法来访问生成器中的值==

### 生成器表达式

生成器表达式是一种特殊的生成器，它可以用来创建一个生成器对象。

例如：

```.
g = (i for i in range(10)) #创建一个生成器对象，生成器表达式
for i in g: #for循环会自动调用next方法，直到抛出StopIteration异常
   print(i) #打印每次产生的值
```

输出：

```.
0
1
2
3
4
5
6
7
8
9
```

解释：`(i for i in range(10))`是一个生成器表达式，它会创建一个生成器对象，生成器表达式可以用来创建一个生成器对象。
==每次只会生成一个值，并且可以记住当时的状态，不像列表推导式（一次生成所有值并保存到一个列表当中）==

### 递归

递归是一种函数调用自身的方式。但是递归算法的效率比较低，因为递归算法会不断的调用自身，直到达到终止条件。
==要让递归停止，必须要有一个终止条件==
例如：

```.
def factorial(n): #求阶乘
   if n == 1: #终止条件
      return 1 #返回1
   else: #递归条件
      return n * factorial(n-1) #返回n乘以n-1的阶乘
```

#### 汉诺塔

```.
def hanoi(n,a,b,c): #n表示盘子的数量，a,b,c表示三个柱子
   if n == 1: #终止条件
      print(a,"-->",c) #将盘子从a柱子移动到c柱子
   else: #递归条件
      hanoi(n-1,a,c,b) #将n-1个盘子从a柱子移动到b柱子
      print(a,"-->",c) #将盘子从a柱子移动到c柱子
      hanoi(n-1,b,a,c) #将n-1个盘子从b柱子移动到c柱子
hanoi(3,"A","B","C") #将3个盘子从A柱子移动到C柱子
```

### 类型注解

类型注解是一种语法，用来指定函数的参数和返回值的类型。
注解语法：

```.
def 函数名(参数:类型,参数:类型) -> 返回值类型:
   函数体
```

例如：

```.
def add(x:int,y:int) -> int: #指定函数的参数和返回值的类型
   return x + y #返回x和y的和
add(1,2) #调用函数，传入参数1和2
```

==这个只是方便阅读，不会影响程序的运行==

### 内省

内省是一种机制，用来获取对象的信息。
例如：

```.
def add(x:int,y:int) -> int: #指定函数的参数和返回值的类型
   return x + y #返回x和y的和
add(1,2) #调用函数，传入参数1和2
add.__annotations__ #获取函数的参数和返回值的类型
add.__name__ #获取函数的名称
add.__doc__ #获取函数的文档
```

输出：

```.
{'x': <class 'int'>, 'y': <class 'int'>, 'return': <class 'int'>}
'add'
None
```

### 高阶函数

高阶函数是指函数可以作为参数传递给其他函数，或者函数的返回值是一个函数。

#### `functools`函数

`functools`是一个内置模块，它提供了一些高阶函数。

例如：

```.
import functools #导入functools模块
def add(x,y): #定义一个函数，用来相加
   return x + y #返回x和y的和
functools.reduce(add,[1,2,3,4,5]) #使用reduce函数，将列表中的元素相加
```

输出：

```.
15
```

解释：`functools.reduce`函数的作用是将第二个参数中的元素依次传入到第一个参数中，然后返回一个值。

### 偏函数

偏函数是指对一个函数进行部分参数的固定，返回一个新的函数。
例如：

```.
import functools #导入functools模块
square = functools.partial(pow,exp=2) #对pow函数进行部分参数的固定，返回一个新的函数
square(3) #调用新的函数，传入参数3
```

输出：

```.
9
```

解释：`pow`函数的作用是计算一个数的幂次方。

### '@wraps'装饰器

`@wraps`装饰器是一个内置装饰器，它可以用来保留被装饰函数的元信息。
例如：

```.
import functools #导入functools模块
def my_decorator(func): #定义一个装饰器
   @functools.wraps(func) #保留被装饰函数的元信息
   def wrapper(*args, **kwargs): #定义一个包装器
      print("装饰器") #装饰器的功能
      return func(*args, **kwargs) #调用被装饰的函数
   return wrapper #返回包装器
@my_decorator #装饰器，相当于funA = my_decorator(funA)
def funA(): #被装饰的函数
   print("函数") #被装饰的函数的功能
funA() #调用被装饰的函数
funA.__name__ #获取被装饰函数的名称
funA.__doc__ #获取被装饰函数的文档
```

输出：

```.
装饰器
函数
'funA'
None
```

小声bb：感觉没什么用

## 永久存储

### 创建文件和修改文件

```.
f = open("test.txt","w") #创建一个文件，文件名是test.txt，模式是w，w表示写入模式，如果文件不存在，会创建一个新的文件，如果文件存在，会覆盖原有的文件
f.write("hello world") #写入文件
f.writelines(["hello world","hello world","hello world"]) #写入文件
f.close() #关闭文件
```

解释：`open`函数的第一个参数是文件名，第二个参数是模式，模式有以下几种：

- r：读取模式，默认模式
- w：写入模式，如果文件不存在，会创建一个新的文件，如果文件存在，会覆盖原有的文件
- a：追加模式，如果文件不存在，会创建一个新的文件，如果文件存在，会在文件的末尾添加内容

`write`函数的作用是写入文件，`writelines`函数的作用是写入文件，但是`writelines`函数会将列表中的元素依次写入文件。

`close`函数的作用是关闭文件,如果没有关闭文件，那么文件的内容不会被保存。

### 文件对象操作

以下表格是对文件对象操作的常用方法：

| 方法 | 描述 |
| --- | --- |
| `read()` | 读取整个文件 |
| `readline()` | 读取文件的一行 |
| `readlines()` | 读取文件的所有行 |
| `write()` | 写入文件 |
| `writelines()` | 写入文件 |
| `seek()` | 设置文件指针的位置 |
| `tell()` | 返回文件指针的位置 |
| `close()` | 关闭文件 |
| `flush()` | 刷新文件缓冲区 |
| `truncate()` | 截断文件 |
| `fileno()` | 返回文件描述符 |
| `isatty()` | 判断文件是否是终端设备 |
| `readable()` | 判断文件是否可读 |
| `writable()` | 判断文件是否可写 |
| `seekable()` | 判断文件是否可定位 |
| `closed()` | 判断文件是否关闭 |

#### `truncate()`

`truncate`函数的作用是截断文件，`truncate`函数的参数是文件的大小。
例如：

```.
f = open("test.txt","w") #创建一个文件，文件名是test.txt，模式是w，w表示写入模式，如果文件不存在，会创建一个新的文件，如果文件存在，会覆盖原有的文件，==即原有文件的内容会被清空==
f.write("hello world") #写入文件
f.truncate(5) #截断文件，文件的大小是5
f.close() #关闭文件
```

输出：

```.
hello
```

### 路径处理

`pathlib`是一个内置模块，它提供了一些路径处理的函数。
例如：

```.
from pathlib import Path #导入Path类
p = Path("test.txt") #创建一个Path对象，文件名是test.txt
p.exists() #判断文件是否存在
p.is_file() #判断是否是文件
p.is_dir() #判断是否是目录
p.name #获取文件名
Patn.cwd() #获取当前工作目录
'''还有很多操作，这里就不一一列举了，有兴趣的可以自己去看官方文档'''
```

### 上下文管理器

上下文管理器是一种特殊的对象，它可以用来管理资源的获取和释放。
例如：

```.
with open("test.txt","r") as f: #使用with语句打开文件，with语句会自动关闭文件
   f.write("hello world") #写入文件
   f.read() #读取文件
```

解释：`with`语句的作用是打开文件，`with`语句会自动关闭文件。

例二：

```.
with open("xyf.txt","w") as f: #使用with语句打开文件，with语句会自动关闭文件
   f.write("hello world") #写入文件
   1/0;
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 3, in <module>
    1/0;
ZeroDivisionError: division by zero
```

解释：这里虽然会报错，但是文件的内容还是会被写入到文件当中，因为`with`语句会自动关闭文件。

### `pickle`模块--允许将Python对象保存到文件中

`pickle`模块是一个内置模块，它提供了一些函数，用来将Python对象保存到文件中。
`dump`函数的作用是将Python对象保存到文件中。
`load`函数的作用是从文件中加载Python对象。
例如：

```.
"""写入"""
import pickle #导入pickle模块
x,y,z=1,2,3
s="xyf"
l=["xyf",1,2]
d={"xyf":1,"xyf2":2}

with open("test.pkl","wb") as f: #使用with语句打开文件，with语句会自动关闭文件
   pickle.dump(x,f) #将x保存到文件中
   pickle.dump(y,f) #将y保存到文件中
   pickle.dump(z,f) #将z保存到文件中
   pickle.dump(s,f) #将s保存到文件中
   pickle.dump(l,f) #将l保存到文件中
   pickle.dump(d,f) #将d保存到文件中
   '''或者用元组的形式保存：
   pickle.dump((x,y,z,s,l,d),f) '''
   
```

解释：`dump`函数的第一个参数是要保存的对象，第二个参数是文件对象。

```.
"""读取"""
import pickle #导入pickle模块
with open("test.pkl","rb") as f: #使用with语句打开文件，with语句会自动关闭文件
   x=pickle.load(f) #从文件中加载x
   y=pickle.load(f) #从文件中加载y
   z=pickle.load(f) #从文件中加载z
   s=pickle.load(f) #从文件中加载s
   l=pickle.load(f) #从文件中加载l
   d=pickle.load(f) #从文件中加载d
   print(x,y,z,s,l,d,sep="\n") #打印x,y,z,s,l,d,`sep="\n"`表示每个元素之间换行
```

输出：

```.
1
2
3
xyf
['xyf', 1, 2]
{'xyf': 1, 'xyf2': 2}
```

解释：`load`函数的作用是从文件中加载Python对象。

## 处理异常

==异常可以嵌套==
`try`语句的作用是尝试执行一段代码，如果出现异常，就会跳转到`except`语句中执行。
`except`语句的作用是捕获异常，`except`语句的参数是异常的类型。
例如：

```py
try: #尝试执行这段代码
   1/0 #这里会抛出一个异常，因为0不能作为除数
except ZeroDivisionError: #捕获异常，ZeroDivisionError是异常的类型
   print("除数不能为0") #打印异常信息
```

输出：

```.
除数不能为0
```

如果异常类型出错，那么仍然会报错。
例如：

```.
try: #尝试执行这段代码
   520+“xyf” #这里会抛出一个异常
except ZeroDivisionError: #捕获异常，但是这里的异常类型是TypeError，所以不会捕获到异常
   print("出错了") #打印异常信息
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 3, in <module>
    520+“xyf” #这里会抛出一个异常
TypeError: unsupported operand type(s) for +: 'int' and 'str'
```

### 使用`as`可以将异常信息赋值给一个变量

例如：

```.
try: #尝试执行这段代码
   1/0 #这里会抛出一个异常，因为0不能作为除数
except ZeroDivisionError as e: #捕获异常，ZeroDivisionError是异常的类型，as e是将异常信息赋值给变量e
   print(e) #打印异常信息
```

输出：

```.
division by zero
```

### 如果不确定异常类型，可以用元组的形式来捕获异常

例如：

```.
try: #尝试执行这段代码
   1/0 #这里会抛出一个异常，因为0不能作为除数
   520+“xyf” #这里会抛出一个异常
except (ZeroDivisionError,TypeError): #捕获异常，
   pass #检测到其中一个任何一个异常就会跳过
```

### 可以对不同的异常类型使用不同的处理方式

例如：

```.
try: #尝试执行这段代码
   1/0 #这里会抛出一个异常，因为0不能作为除数
   520+“xyf” #这里会抛出一个异常
except ZeroDivisionError: #捕获异常，ZeroDivisionError是异常的类型
   print("除数不能为0") #打印异常信息
except TypeError: #捕获异常，TypeError是异常的类型
   print("类型错误") #打印异常信息
```

输出：

```.
除数不能为0
```

解释：当检查到其中一个异常时，就会跳过后面的异常处理。

### `try-except-else`和`finally`语句

`try-except-else`语句的作用是在没有异常的情况下执行一段代码。
`finally`语句的作用是无论是否有异常，都会执行一段代码。

例如：

```.
try: #尝试执行这段代码
   1/1 #这里不会抛出异常
except ZeroDivisionError: #捕获异常，ZeroDivisionError是异常的类型
   print("除数不能为0") #打印异常信息
else: #没有异常的情况下执行这段代码
   print("没有异常") #打印信息
```

输出：

```.
没有异常
```

例如：

```.
try: #尝试执行这段代码
   1/0 #这里会抛出一个异常，因为0不能作为除数
except ZeroDivisionError: #捕获异常，ZeroDivisionError是异常的类型
   print("除数不能为0") #打印异常信息
else: #没有异常的情况下执行这段代码
   print("没有异常") #打印信息
finally: #无论是否有异常，都会执行这段代码
   print("无论是否有异常，都会执行这段代码") #打印信息
```

输出：

```.
除数不能为0
无论是否有异常，都会执行这段代码
```

### `raise`语句,抛出异常

`raise`语句的作用是抛出一个异常。
例如：

```.
raise ZeroDivisionError("除数不能为0") #抛出一个异常，ZeroDivisionError是异常的类型，"除数不能为0"是异常的信息
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 3, in <module>
    raise ZeroDivisionError("除数不能为0") #抛出一个异常，ZeroDivisionError是异常的类型，"除数不能为0"是异常的信息
ZeroDivisionError: 除数不能为0
```

解释：`raise`语句的作用是抛出一个异常，`raise`语句的参数是异常的类型和异常的信息。

### 异常链

异常链是一种机制，用来将一个异常传递给另一个异常。
例如：

```.
raise ZeroDivisionError("除数不能为0") from ValueError #抛出一个异常，ZeroDivisionError是异常的类型，"除数不能为0"是异常的信息，from None表示没有异常
```

### `assert`语句

`assert`语句的作用是断言，`assert`语句的参数是一个表达式，如果表达式为真，就会继续执行，如果表达式为假，就会抛出一个异常,且该异常只能是`AssertionError`类型。
例如：

```.
assert 1==1 #断言，1==1为真，不会抛出异常
assert 1==2 #断言，1==2为假，会抛出异常
```

### 利用异常实现跳转

```.
try：
   while true：
      while true：
            for i in range(10)：
               if i>3：
                     raise
                print(i)
            print("被跳过")
      print("被跳过")
    print("被跳过")
except：
    print("跳到这里了")
```

输出：

```.
0
1
2
3
跳到这里了
```

## 模块

模块是一个包含了Python代码的文件，模块可以被其他模块导入，也可以被其他模块导入。
模块的作用是将代码组织起来，方便管理和重用。

### 模块的导入

模块的导入有两种方式：

- 导入整个模块
- 导入模块中的特定函数
- 导入模块中的所有函数

#### 导入整个模块

```.
import 模块名 #导入整个模块
模块名.函数名() #调用模块中的函数
```

#### 导入模块中的特定函数

```.
from 模块名 import 函数名 #导入模块中的特定函数
函数名() #调用函数
```

#### 导入模块中的所有函数

```.
from 模块名 import * #导入模块中的所有函数
函数名() #调用函数
```

### 给模块起别名

```.
import 模块名 as 别名 #导入整个模块，给模块起别名
别名.函数名() #调用函数
```

## `if __name__ == '__main__'`

模块导入时，会执行模块中的所有代码，但是有些代码我们不想让它执行，此时就可以使用`if __name__ == '__main__'`来判断是否是直接执行模块。当一个模块被直接执行时，他的`__name__`属性的值是`__main__`，当一个模块被导入时，他的`__name__`属性的值是模块的名称。
`if __name__ == '__main__'`是一个条件语句，它的作用是判断当前模块是否被直接执行，如果是，就执行下面的代码，如果不是，就不执行下面的代码。

## 包

包是一个包含了多个模块的文件夹，包的作用是将代码组织起来，方便管理和重用。
包的导入有两种方式：

- 导入整个包
- 导入包中的特定模块
- 导入包中的所有模块

### 导入整个包

```.
import 包名 #导入整个包
包名.模块名.函数名() #调用模块中的函数
```

### 导入包中的特定模块

```.
from 包名 import 模块名 #导入包中的特定模块
模块名.函数名() #调用函数
```

### 导入包中的所有模块

```.
from 包名 import * #导入包中的所有模块
模块名.函数名() #调用函数
```

### 通过`__init__.py`文件来控制包的导入

`__init__.py`文件是一个特殊的文件，它的作用是用来控制包的导入。
`__init__.py`文件可以为空，也可以包含一些初始化代码。

#### `__init__.py`定义属于包的全局变量

例如：

```.
"""__init__.py"""
x=1 #定义一个全局变量
y=2 #定义一个全局变量
z=3 #定义一个全局变量
```

此时在其他模块中导入包时，就可以使用包中的全局变量。
例如：

```.
import 包名 #导入整个包
print(包名.x) #打印包中的全局变量x
print(包名.y) #打印包中的全局变量y
print(包名.z) #打印包中的全局变量z
```

#### `__aLL__`遏制`import *`的副作用，防止导入包中的所有模块

例如：

```.
"""__init__.py"""
__all__=["x","y","z"] #定义一个列表，列表中的元素是包中的模块的名称
```

此时在其他模块中导入包时，就只能导入包中的指定模块。

 对于模块来说，如果没有使用`__all__`来定义模块的导出列表，那么`import *`语句会导入模块中的所有变量和函数。
 对于包来说，如果没有使用`__init__.py`来定义包的导出列表，那么`import *`的语句==不会导入包里面的任何模块==。

## 类和对象

类是一种用户定义的数据类型，它包含了数据成员和成员函数。
对象是类的实例，它包含了类的数据成员和成员函数。
类和对象的关系是：类是对象的模板，对象是类的实例。

### 实例化对象

```.
class 类名: #定义一个类，类名是类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
```

解释：`class`关键字用来定义一个类，类名是类的名称。

```.
obj=类名() #实例化一个对象，obj是对象的名称，类名是类的名称
obj.方法名() #调用对象的方法，方法名是方法的名称
```

### 为对象添加属性

```.
class 类名: 
   def 方法名(self): 
      print(self) 
obj=类名() #实例化一个对象，obj是对象的名称，类名是类的名称
obj.属性名=值 #为对象添加属性，属性名是属性的名称，值是属性的值
```

同类的对象之间的属性是相互独立的，所以属性名字可以相同不会冲突。

### `self`究竟是什么

`self`是一个特殊的参数，它的作用是指向当前对象。
当实例化一个对象时，引用类里面的方法，会将对象自己作为第一个参数传递给方法，此时就需要`self`来充当这个参数。
例如：

```.
class 类名: #定义一个类，类名是类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
```

### 继承

继承是一种机制，用来表示一个类是另一个类的子类。
==所有类没有规定继承自哪个类，所以所有类都是object类的子类。==
子类继承父类的属性和方法，子类可以重写父类的方法，子类可以添加新的属性和方法，也可以覆盖。
例如：

```.
class A #定义一个父类，父类是类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
```

```.
class B(A) #定义一个子类，子类是类的名称，A是父类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
```

### 判断一个对象是否是一个类的实例

isinstance(对象,类) #判断一个对象是否是一个类的实例，对象是对象的名称，类是类的名称，返回值是布尔值。

### 多重继承

多重继承是一种机制，用来表示一个类可以继承多个父类。
例如：

```.
class A: #定义一个父类，父类是类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
class B: #定义一个父类，父类是类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
class C(A,B): #定义一个子类，子类是类的名称，A是父类的名称，B是父类的名称
   def 方法名(self): #定义一个方法，方法名是方法的名称，self是一个特殊的参数，它的作用是指向当前对象
      print(self) #打印self
```

C的对象会按照先A后B的顺序来查找方法，当A没有需要的方法时，才回去B中寻找。

### 组合

组合是一种机制，用来表示一个类可以包含多个其他类的对象。
例如：

```.
class A:
   def 方法名(self):、
      print(self) #打印self
class B:
   def 方法名(self):、
      print(self) #打印self
class C: 
   def 方法名(self):
      print(self) #打印self
class D:
   a = A() #创建一个A的对象，a是对象的名称，A是类的名称
   b = B() 
   c = C() 
   def 方法名(self):
      self.a.方法名()
      self.b.方法名() 
      self.c.方法名()
```

### 构造函数

构造函数是一种特殊的方法，用来初始化对象的属性。
构造函数的名称是`__init__`，它的作用是用来初始化对象的属性。
例如：

```.
class C：
   def __init__(self,x,y):
     self.x = x
     self.y = y
   def add(self):
     return self.x + self.y 
   def mul(self):
     return self.x * self.y
```

### 动态添加属性和方法

动态添加属性和方法是一种机制，用来在运行时添加属性和方法。

```.
class C：
   def __init__(self,x,y):
     self.x = x
     self.y = y
   def add(self):
     return self.x + self.y
   def mul(self):
     return self.x * self.y
p = C(1,2)
p.z = 3 #动态添加属性
p.add = lambda self: self.x + self.y #动态添加方法
p.__dict__ #查看对象的属性和方法
```

输出：

```.
{'x': 1, 'y': 2, 'z': 3, 'add': <function C.<lambda> at 0x0000022C444780D0>}
```

### 重写

重写是一种机制，用来表示一个类可以重写父类的方法。
例如：

```.
class C：
   def __init__(self,x,y):
     self.x = x
     self.y = y
   def add(self):
     return self.x + self.y 
   def mul(self):
     return self.x * self.y
class D(C):
   def__init__(self,x,y,z):
     C.__init__(self,x,y)
     self.z = z
   def add(self):
     return C.add(self) + self.z
   def mul(self):
     return C.mul(self) * self.z
```

### 严重问题——钻石继承

钻石继承是一种机制，用来表示一个类可以继承多个父类。
例如：

```.
class A:
   def __init__(self):
     print("A")
class B1(A):
   def __init__(self):
     A.__init__(self)
     print("B1")
class B2(A):
   def __init__(self):
     A.__init__(self)
     print("B2")
class C(B1,B2):
   def __init__(self):
     B1.__init__(self)
     B2.__init__(self)
     print("C")
```

这样写会导致A被初始化两次，所以会出现问题。

输出：

```.
A
B1
A
B2
C
```

### `super`

`super`是一个特殊的函数，用来调用父类的方法。
例如：

```.
class A:
   def __init__(self):
     print("A")
class B1(A):
     super().__init__()
     print("B1")
class B2(A):
     super().__init__()
     print("B2")
class C(B1,B2):
   def __init__(self):
     super().__init__()
     print("C")
```

输出：

```.
A
B1
B2
C
```

解释：用`super`查找父类方法，就会自动地按照MRO的顺序查找（MRO是方法解析顺序，即按照继承关系来查找方法的顺序，可以通过类名的`__mro__`属性来查看）。如果之前的方法已经被调用过了，就不会再调用了。

==`super`的性能很优秀，但是有不少小坑，使用之前可以查看一下==

### mixin

mixin是一种机制，用来表示一个类可以包含多个其他类的方法。写游戏外挂基本上用的都是mixin。
例如：

```.
class A:
   def __init__(self,name,age):
     self.name = name
     self.age = age
   def say(self):
     print(f"my name is{self.name}and my age is{self.age}")
class B:
   def fly(self):
     print("I can fly")
class C(A,B):
   def swim(self):
     print("I can swim")
p = C("xyf",20)
p.say()
p.fly()
p.swim()
```

输出：

```.
my name is xyf and my age is 20
I can fly
I can swim
```

### 多态

多态体现在子类在继承父类之后，可以对父类的方法进行重写，从而实现不同的功能。

### 多态接口

多态接口是一种机制，一个函数可以接受多种类型的对象作为参数，从而实现不同的功能。

### 鸭子类型

鸭子类型是一种机制，当对象作为参数传递给函数时，函数会检查对象是否有特定的方法，如果有，就会调用该方法，否则就会抛出异常，并不会检查对象的类型。

### python版"私有变量"，"私有方法"--名字改编术

python没有真正的私有变量和私有方法，但是可以通过名字改编术来实现私有变量和私有方法。

名字改编术是一种机制，用来将一个变量或方法的名称改编成一个新的名称，从而实现类似的私有变量和私有方法。

```.

class C:
   def __init__(self,x):
     self.__x = x """这里面把x变成了“私有变量”."""
   def set_x(self,x):
     self.__x = x 
   def get_x(self):
     print(self.__x)
c = C(250)
c.__x
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 10, in <module>
    c.__x
AttributeError: 'C' object has no attribute '__x'
```

解释：`__x`是一个"私有变量"，只能通过类里面的方法访问，外部不能访问。

```.
c.get_x()
c.__dict__ """查看对象的属性"""
c._C__x 
```

输出：

```.
250
{'_C__x': 250} """发现只是把x改了名字，但是还是可以访问"""
250
```

==但是动态添加属性是无法规定私有变量的，只能在类里面规定私有变量==

==所以当看到单个或两个下划线开头的变量时，不要去管他，他可能是内部变量，不要随意改动==

### `__slots__`限制动态添加属性

`__slots__`是一个特殊的属性，用来限制动态添加属性。
例如：

```.
class C:
   __slots__ = ("x","y")
   def __init__(self,x,y):
     self.x = x
c = C(250)
c.y = 250
c.x
c.y
c.z = 250
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 11, in <module>
    c.z = 250
AttributeError: 'C' object has no attribute 'z'
```

解释：`__slots__`限制了动态添加属性，只能添加`x`和`y`，其他属性都不能添加。

甚至在构造函数中也不能添加属性

```.
class C:
   __slots__ = ("x","y")
   def __init__(self,x,y):
     self.x = x
     self.y = y
     self.z = Z
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 11, in <module>
    self.z = Z
AttributeError: 'C' object has no attribute 'z'
```

==`__slots__`只能限制动态添加属性，不能限制继承的属性,在子类中是不生效的==

### 魔法方法`__new__`

`__new__`是一个特殊的方法，用来创建对象。
`__new__`的作用是在对象创建之前调用，它的返回值是一个对象。
例如：

```.
class CapStr(str): #继承自str类
   def __new__(cls,string):
     string = string.upper()
     return super().__new__(cls,string)
s = CapStr("hello")
s
```

输出：

```.
HELLO
```

### 魔法方法`__del__`

`__del__`是一个特殊的方法，用来销毁对象。
`__del__`的作用是在对象销毁之前调用，它的返回值是None。
例如：

```.
class C:
   def __init__(self,):
     print("我来了")
   def __del__(self):
     print("我走了)
c = C()
del c
```

输出：

```.
我来了
我走了
```

python具有垃圾回收机制，即当一个对象没有被引用时，就会被销毁。所以在使用`__del__`之前，如果把对象赋值给其他变量，此时对象就会被引用，就不会被销毁，此时只有销毁对象赋予的变量时，对象才会被销毁。

```.
class C:
   def __init__(self,):
     print("我来了")
   def __del__(self):
     print("我走了)
c = C()
d = c
del c
del d
```

输出：

```.
我来了
我走了 """其实是走到del d的时候，对象才会被销毁，才会出现这个输出结果"""
```

### 闭包实现"复活"被销毁的对象

```.
class E:
   def __init__(self,name,func):
     self.name = name
     self.func = func
   def __del__(self):
     self.func(self)
def outter():
   x=0
   def inner(y = None):
     nonlocal x """nonlocal关键字用来声明一个变量是外层函数的变量"""
     if y :"""如果y不为None，就把y赋值给x"""
       x = y
     else:
       return x
   return inner
f = outter()
e = E("xyf",f)
del e
e
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 26, in <module>
    e
NameError: name 'e' is not defined
```

说明：`e`对象被销毁了

```.
g = f() """此时f()就相当于是inner()，因为f()的返回值是inner函数,g就是被保存的e对象"""
g.name
```

输出：

```.
xyf
```

说明：`e`对象被复活了

### 魔法方法`__call__`

### 类方法和静态方法

类方法作用是用来操作类的属性，类方法的第一个参数是类本身，通常用`cls`来表示。

```.
class C:
   count = 0
   def __init__(self):
     C.count += 1
   @classmethod
   def get_count(cls):
     print(f"该类实例化了{cls.count}个对象") """cls是类本身"""
c1 = C()
c2 = C()
c3 = C()
c3.get_count()
```

输出：

```.
该类实例化了3个对象
```

解释：`c3.get_count()`相当于`C.get_count(c3)`，`c3`是对象本身，`C`是类本身，`cls`是类本身。

当我们需要创立一个不需要参数的方法可以使用静态方法，静态方法可以创立一个不需要参数绑定的方法。
静态方法的第一个参数是类本身，通常用`cls`来表示。

```.
class C:
   count = 0
   def __init__(self):
     C.count += 1
   @staticmethod
   def get_count():
     print(f"该类实例化了{C.count}个对象")
c1 = C()
c2 = C()
c3 = C()
c3.get_count()
```

输出：

```.
该类实例化了3个对象
```

不过类似于统计有多少个实例化的对象，更加建议使用类方法，因为当涉及到继承时，类方法会更加方便。

```python
class C:
   count = 0
   @classmethod
   def add(cls):
     cls.count += 1 """实现自动统计实例化的对象"""
   def __init__(self):
     self.add()
   def get_count(self):
     print(f"该类实例化了{cls.count}个对象")
class D(C):
   count = 0
class E(C):
   count = 0
c1 = C()
d1,d2 = D(),D()
e1,e2,e3 = E(),E(),E()
c1.get_count()
d1.get_count()
e1.get_count()
```

输出：

```.
该类实例化了3个对象
该类实例化了2个对象
该类实例化了3个对象
```

### `type`函数

`type`函数的作用是传入一个对象，返回一个对象的类型。

例如：

```.
type(1)("520")
```

输出：

```.
520
```

解释：`type(1)`返回的是`int`类型，`type(1)("520")`相当于`int("520")`，返回的是`520`。

第二种用法：根据传入的三个参数，创建一个新的type类型的对象。
用法为：`type(类名,父类,属性)`，第一个参数是一个字符串，用来表示类名，第二个参数是一个元组，用来表示继承的父类，第三个参数是一个字典，用来表示类的属性。

```python
class C:
   pass
D = type("D",(C,),{"x":1,"y":2}) """创建一个名为D的类，继承自C，属性为x和y"""
D.x
D.y
D.__bases__
```

输出：

```.
1
2
(<class '__main__.C'>,) """说明D继承自C"""
```

属性里面还可以添加方法，例如：

```python
def func(self,name="xyf"):
   print(f"hello {name}")
F = type("F",(),dict(say_hi=func))
f = F() """实例化一个F类的对象"""
f.say_hi()
```

输出：

```.
hello xyf
```

### `__init_subclass__`加强父类对子类的控制

`__init_subclass__`是一个特殊的方法，用来加强父类对子类的控制。
例如：

```python
class C:
   def__init_subclass__(cls):
      print("""我是父类，我被继承了""")
      cls.x = 520
class D(C):
   x=250
D.x
```

输出：

```.
我是父类，我被继承了 """子类D生成以后，会直接触发父类的__init_subclass__方法，所以会输出这个结果"""
520 """说明父类的__init_subclass__方法可以对子类进行控制"""
```

还可以用`__init_subclass__`方法来通过父类向子类传递参数。

```python
class C:
   def__init_subclass__(cls,value):
      print("""我是父类，我被继承了""")
      cls.x = value
class D(C,value=250): """第一次遇到这种传参形式"""
   x = 520
D.x
```

输出：

```.
我是父类，我被继承了
250
```

用`type`试一试：

```python
class C:
   def__init_subclass__(cls,value1,value2):
      print("""我是父类，我被继承了""")
      cls.x = value1
      cls.y = value2
D = type("D",(C,),dict(x = 250),value1 = 520,value2 = 666)
D.x
D.y
```

输出：

```.
我是父类，我被继承了
520
666
```

### 元类

元类是用来创建类的类，元类的作用是用来创建类。
创建一个元类需要继承自`type`类：

```python
class MyMeta(type):
   pass
class C(metaclass=MyMeta):
   pass
c = C()
type(c)
type(C)
type(MyMeta)
```

输出：

```.
<class '__main__.C'>
<class '__main__.MyMeta'>
<class 'type'>
```

解释：`type(c)`返回的是`C`类的类型，`type(C)`返回的是`MyMeta`类的类型，`type(MyMeta)`返回的是`type`类的类型。

```python
class MetaC(type):
   def __new__(mcls,name,bases,attrs): """mcls是元类本身，name是类名，bases是父类，attrs是属性"""
      print("__new__() in MetaC")
      return type.__new__(mcls,name,bases,attrs)
class C(metaclass=MetaC): """依照元类`MetaC`创建一个类C"""
   def __new__(cls):
      print("__new__() in C")
      return super().__new__(cls) """元类创建的类，不会影响该类的继承体系，所以这里默认继承自object"""
   def __init__(self):
      print("__init__() in C")
      super().__init__()
```

输出：

```.
__new__() in MetaC
__init__() in MetaC
```

解释：这里并没有输出`__new__() in C`，说明元类的`__new__`方法在创建类时就已经执行了，而不是在实例化对象时执行。

### 抽象基类

抽象基类其实很像Java中的接口，抽象基类的作用是用来规定子类必须实现的方法。实现抽象基类必须使用`abc`模块。

```python
from abc import ABCMeta,abstractmethod
class Fruit(metaclass=ABCMeta):
   def __init__(self,name):
      self.name = name
   @abstractmethod
   def good_for_health(self):
      pass
fruit = Fruit("apple")
```

输出：

```.
Traceback (most recent call last):
  File "D:\Python\Python.md\test.py", line 10, in <module>
    fruit = Fruit("apple")
TypeError: Can't instantiate abstract class Fruit with abstract methods good_for_health
```

解释：`Fruit`类是一个抽象基类，它规定了子类必须实现`good_for_health`方法，否则就会报错。

```python
class Apple(Fruit):
   def good_for_health(self):
      print("apple is good for health")
apple = Apple("apple")
apple.good_for_health()
```

输出：

```.
apple is good for health
```
