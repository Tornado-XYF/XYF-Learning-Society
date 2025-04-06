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

total = ('item_one + '
        'item_two + '
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
