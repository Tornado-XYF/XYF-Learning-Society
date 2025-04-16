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
- `zip()`：返回一个 zip 对象，包含多个可迭代对象的元素。
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
len(d)
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
