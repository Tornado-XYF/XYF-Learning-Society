# 爬虫

## 准备工作

以下是需要用到的包和大致思路

```py
from bs4 import BeautifulSoup  #网页解析 获取数据
import re   #正则表达式，进行文字匹配
import urllib.request,urllib.error #制定URL，获取网页数据
import xlwt   #进行excel操作
import sqlite3 #进行SQLite 数据库操作

def main():
    baseurl = "https://movie.douban.com/top250?start=" #要爬取的基础URL
    #1.爬取网页
    datalist = getdata(baseurl)

    #3.保存数据
    savepath = ".\\abababa.xls"
    savedata(savepath)

#爬取网页
def getdata(baseurl):
    datalist = []
    #2.逐一解析数据
    return datalist

#保存数据
def savedata(savepath):
    return 0

```

这些包的用处下面都会一一解释和列举

## 包urllib.request

用于获取指定URL的网页源代码

```py
import urllib.request

#获取一个get请求--即直接获取网站信息
response = urllib.request.urlopen("http://www.baidu.com") #打开指定网页，并获得响应数据然后保存到response变量中

print(response.read().decode('utf-8')) #这里可以获取到百度首页的源代码



#获取一个post请求--即网站服务器发送一个加密表单，从网站那里获得响应，更加安全

import urllib.parse #解析器，将指定内容按照指定格式进行解析

#post请求需要提交一个表单，这里对一个表单进行封装
data = bytes(urllib.parse.urlencode({"Hello":"world"}),encoding="utf-8")
#按照utf-8的方式将字典解析为二进制形式并存到bytes这个元组里面，然后再赋值给data

response = urllib.request.urlopen("http://httpbin.org/post",data = data) 
#这个网站是一个测试网站，用于测试post请求和get请求他会返回一个表单，表单中包含了我们提交的内容


print(response.read().decode("utf-8"))

```

post请求用来模拟网站用户登录的情况，因为登录时需要提交用户名和密码，而这些信息是不能直接暴露在URL中的，所以需要使用post请求来提交表单数据。

输出：

```py
{
  "args": {}, 
  "data": "", 
  "files": {}, 
  "form": {
    "Hello": "world"
  }, 
  "headers": {
    "Accept-Encoding": "identity", 
    "Content-Length": "11", 
    "Content-Type": "application/x-www-form-urlencoded", 
    "Host": "httpbin.org", 
    "User-Agent": "Python-urllib/3.13", 
    "X-Amzn-Trace-Id": "Root=1-689be088-36210fce5d36168900a11166"
  }, 
  "json": null, 
  "origin": "115.60.187.221", 
  "url": "http://httpbin.org/post"
}
```

### get

```py
import urllib.request

#-------get请求

response = urllib.request.urlopen("http://httpbin.org/get")
print(response.read().decode("utf-8"))

```

输出：

```py
{
  "args": {}, 
  "headers": {
    "Accept-Encoding": "identity", 
    "Host": "httpbin.org", 
    "User-Agent": "Python-urllib/3.13", #这个代码直接暴露了我们是python爬虫
    "X-Amzn-Trace-Id": "Root=1-689bdf6d-6d7ad20a5c58e5b66a334613"
  }, 
  "origin": "115.60.187.221", 
  "url": "http://httpbin.org/get"
}

```

### 时间控制

```py
response = urllib.request.urlopen("http://httpbin.org/get",timeout=0.1)

print(response.read().decode("utf-8"))

#如果网站响应时间超过了0.1秒，就会抛出一个异常
```

异常处理：

```py
try:
   response = urllib.request.urlopen("http://httpbin.org/get",timeout = 0.01)
   print(response.read().decode("utf-8"))
except urllib.error.URLError as e:
   print("timeout")
```

### 状态码，响应头

```py
response = urllib.request.urlopen("http://baidu.com/")

print(response.status) #获取状态码

print(response.getheaders()) #获取响应头信息

print(response.getheader("Server")) #获取响应头信息中的Server字段

```

### 伪装浏览器

```py
url = "http://httpbin.org/post" #要爬取的网站

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36 Edg/139.0.0.0"} #headers即响应头信息，对应上面测试网站返回的信息，User-Agent是最重要的，当然还可以增加其他的
data = bytes(urllib.parse.urlencode({"name":"xyf"}),encoding="utf-8")
req = urllib.request.Request(url = url,data = data,headers = headers,method = "POST")
#Request即向要访问的网站发出请求，请求内容可以自己设置

response = urllib.request.urlopen(req) #发出请求并获得响应

print(response.read().decode("utf-8"))
```

### 豆瓣测试-获取网站源代码

```py
url = "https://www.douban.com"
headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36 Edg/139.0.0.0"}
req = urllib.request.Request(url, headers=headers)
response = urllib.request.urlopen(req)
print(response.read().decode("utf-8"))
```

## 解析数据

利用BeautifulSoup解析数据

```py
from bs4 import BeautifulSoup

file = open("./baidu.html","rb") #将该文件读取到内存里
html = file.read() #将该文档作为html存起来
bs = BeautifulSoup(html,"html.parser") #创建BS对象，并说明要解析html文件并以html.parser解析器解析

print(bs.title)#获取title标签
print(bs.title.string)#仅仅获取title标签的字符串
print(bs.a)#获取第一个a标签
print(bs.a.attrs) #获取a标签的所有属性

print(bs) #打印文档里的所有内容
```

输出以实际html网页为准
这里面分以下几类：
1.Tag 标签及其内容: 如title，a，等bs会拿到它所找到的第一个标签内容
2.NavigableString(标签里定义的字符串)