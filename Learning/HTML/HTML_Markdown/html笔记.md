# 关于HTML初学者可能有的一些偏门问题与答复

## HTML

### 1. 什么是根元素？

起始点，缺少会出现错误，会不符合xml语法规则，无法被解析器正常解析。

### 2. 可扩展标记语言 (Extensible Markup Language, XML)

标准通用标记语言的子集，可以用来标记数据、定义数据类型，是一种允许用户对自己的标记语言进行定义的源语言。 XML是标准通用标记语言可扩展性良好,内容与形式分离,遵循严格的语法要求,保值性良好等优点

人话：未知

### 3. 什么是标准通用标记语言？

标准通用标记语言（以下简称“通用标言”），是一种定义电子文档结构和描述其内容的国际标准语言；通用标言为语法置标提供了异常强大的工具，同时具有极好的扩展性，因此在

数据分类和索引中非常有用；是所有电子文档标记语言的起源，早在万维网发明之前“通用标言”就已存在。

人话：未知

### 4. 什么是标记标签？

HTML是一种标记语言，而这种语言使用类似于的标签来标记网页的，HTML标记标签通常成对出现，第一个是起始标签，第二个是结束标签。HTML标记标签包括文档标记，头部标记，标题标记和主题标记。

### 5. 什么是元数据（metadate）

元数据是用来描述数据属性的信息。可以抽象的理解为，一所饭店是由 厨师，服务员，菜单，煤气灶等等“数据”协调配合组成的，而厨师的生涯履历，身高体重，菜单的内容封面，煤气灶的品牌等等相当于这些数据的“元数据”

### 6. 什么是HTML元素？

例如
` <p>......</p> `
为一个HTML元素，`<p>`是该元素的起始标签（或开始标签），`<p>`是该元素的闭合标签（或结束标签），中间的`......`为元素的内容，也可以嵌套其他元素

### 7. 什么是HTML属性？

HTML元素可以设置属性，属性可以在元素中添加附加信息，一般描述于开始标签，属性总以名称或者值对的形式出现。如 `<a herf="https\://www.bilibili.com">B站<a/>`,的作用就是告诉解析器（或者后台，或者浏览器后台管它什么东西我也说不明白），“B站”这是一个网址链接（也就相当于给某个商品挂上“链接”标签，让顾客（就是上面说的解析器神马的）知道这个商品是链接），而herf为“B站”添加了信息，使“B站”有了`“https://www.bilibili.com”`的信息。于是当我们点击“B站”的时候就会跳转的对应网页。

### 8.为什么在VS CODE预览界面图片加载不出来，而点开网页可以

![alt text](image-1.png)
![alt text](image-2.png)
==存疑==</br>
但是有解决方法：将图片和自己做的html文件放在同一个目录里!!![alt text](image-3.png)
</br>接着直接复制图片的==名称+类型==就好了 !![alt text](image-4.png)

### 9.如何理解base标签

==存疑==

### 10.CSS中“text align：”和“float:”的区别是什么？

这两个在`<div>`或者`<tb>`排列布局中经常一块儿使用，`<text align>`是用来布局表格中或者版块儿中内容相对于这个版块儿的位置，而`<float>`是用来布局该小表格或版块儿相对于整个大板块或大表格的位置。建议多自己尝试，体会其中区别。
==实例：==

``` <!DOCTYPE html>
    <!DOCTYPE html>
    <html>
    <head>    
    <meta charset="utd-8">
    <style type="text/css">
    h1 {font-size:xx-large;text-align: center;}
    </style>
    </head>
    <div id="container" style="width:1860px;height:200px;"><h1><abbr title="哔哩哔哩-仿">BiliBli</abbr></h1>
        <div id="web and download" style="width:930px;height: 150px;float: left;text-align: right;">
        <a href="http://www.bilibili.com" target="_blank">
        <img src="https://activity.hdslb.com/zzjs/20160608appDownload/img/pc/tittle.png" style="width: 200px;background-color: pink;"  title=:"点此跳转至B站" alt="bilibili-logo"></a> 
        <br>
        <a href="https://dl.hdslb.com/mobile/fixed/bili_win/bili_win-install.exe?v=1.14.0" download style="font-size: xx-large;color:cornflowerblue;">下载bilibili</a>    
        </div>
    </div>
```

可以改动float：left和text align，还有各个块的尺寸大小，感受和把握这几者的关系。

### 11.如何理解id属性和class属性？

id 属性指定 HTML 元素的唯一 ID。 id 属性的值在 HTML 文档中必须是唯一的。

id 属性用于指向样式表中的特定样式声明。JavaScript 也可使用它来访问和操作拥有特定 ID 的元素。

id 的语法是：写一个井号 (#)，后跟一个 id 名称。然后，在花括号 {} 中定义 CSS 属性。
详情请跳转至<https://www.w3school.com.cn/html/html_id.asp> 该网页可以解释的更加清楚。

## CSS
