# Spider 网络爬虫

## 基本步骤

使用urllib获取网页源码

1.定义一个url，即要访问的网站

`url = 'http://www.baidu.com'`

2.模拟浏览器向服务器发送请求

`response = urllib.request.urlopen(url)`

3.获取响应中的页面中的源码

read()方法用于读取响应中的所有内容，返回字节形式的二进制数据。

decode()即以括号中的方式，解码

`content = response.read().decode("utf-8")`

4.打印内容

`print(content)`

## urllib的1个类型和6个方法

```python
import urllib.request

#一个类型和六个方法

url = "http://www.baidu.com"

response = urllib.request.urlopen(url)

#response是HTTPResponse的类型
print(type(response))

#read()方法按照一个字节一个字节去读，括号里是要读的字节数
content = response.read(5)
print(content)

#readline()只能读取一行，括号里也是要读的字节数
content1 = response.readline()
print(content1)

#readlines()一行一行的读
content2 = response.readlines()
print(content2)


#getcode()返回状态码
print(response.getcode())

#geturl()返回状态码
print(response.geturl())

#getheaders()返回头文件
print(response.getheaders())
```

## 下载网页图片视频

```python
#下载网页
url_page = 'http://www.baidu.com'
#urllib.request.urlretrieve(url=下载路径,filename=文件名称)
urllib.request.urlretrieve(url_page,'my.html')

#下载图片
url_img = '某图片网上链接'
urllib.request.urlretrieve(url_img,'picture.jpg')

#下载视频
url_video = '某视频网上链接'
urllib.request.urlretrieve(url_video,'video.mp4')

```

## url组成

http/https   `www.baidu.com`    80/443...
1.协议           2.主机         3.端口号     4.路径      5.参数     6.锚点

## headers提取UA和定制请求信息

```py
url = 'https://www.baidu.com/'

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win32; x32) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36 Edg/139.0.0.0"}

request = urllib.request.Request(url = url,headers = headers)

response = urllib.request.urlopen(request)
```

## get请求quote方法将中文转为unicode编码

```py
import urllib.request
import urllib.parse

name = urllib.parse.quote('杨戬')
print(name)
```

## get请求urlencode方法将多参数转换为url编码

```py
import urllib.request
import urllib.parse

base_url = 'https://www.baidu.com/s?'


data = {
    'wd':'周杰伦',
    'sex':'男',
    'location':'中国台湾省'
}

new_data = urllib.parse.urlencode(data)

print(new_data)

url = base_url + new_data
```

## post请求百度翻译

```py
import urllib.request
import urllib.parse

#这里最麻烦，要找到post请求的接口
url = 'https://fanyi.baidu.com/sug'

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36 Edg/139.0.0.0"}

data = {
    'kw':'spider'
}

#post请求的参数必须要进行编码而且要再使用encode方法

data = urllib.parse.urlencode(data).encode('utf-8')

#post请求的参数是不会拼接在url后面的，而是要放在请求对象定制的参数中
request = urllib.request.Request(url = url,data = data,headers = headers)

#print(request)

response = urllib.request.urlopen(request)

content = response.read().decode('utf-8')


#post请求的响应是json格式的，所以要使用json模块来解析
import json

obj = json.loads(content)
print(obj)

```

## ajax的get请求豆瓣第一页数据

```py
import urllib.request
import urllib.parse
import json

url = 'https://movie.douban.com/j/chart/top_list?type=5&interval_id=100%3A90&action=&start=0&limit=20'

headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36 Edg/139.0.0.0'
}
req = urllib.request.Request(url = url, headers = headers)

response = urllib.request.urlopen(req)
content = response.read().decode('utf-8')
print(content)

# 数据下载到本地
#open方法默认是gbk编码，想要保存汉字需要指定编码格式为utf-8
fp = open('douban.jason','w',encoding='utf-8')
fp.write(content)
```
