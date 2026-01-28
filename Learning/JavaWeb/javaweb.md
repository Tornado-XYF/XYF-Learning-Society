# JavaWeb

## SSM简述

## Spring MVC

基于MVC架构模式的Web应用框架，用于构建动态的、交互式的Web应用程序。
人话：接收用户请求，处理请求，返回响应。

```java
@SpringBootApplication
@RestController
@RequestMapping("/hello")
public class DemoApplication {
    public static void main(String[] args) {
        SpringApplication.run(VueQuickstartApplication.class, args);
    }

    // 处理GET请求，路径为/hello
    @GetMapping
    public String hello(@RequestParam String name,@RequestParam Long age){
        System.out.printf("name=%s,age=%d\n",name,age);//普通的参数获取方式
        return "hello "+name+",age is "+age;
    }
    @GetMapping("/{name}") //使用同类注解时，一定要设置不同的路径变量名
    public String hello(@PathVariable String name){
        System.out.println(name); //Restful风格的参数获取方式
        return "hello "+name;
    }

    // 处理POST请求，路径为/hello
    @PostMapping
    public String postHello(@RequestBody Map<String,String> name){
        System.out.println(map.toString());
        return "请求接收成功";
    }
    @PutMapping("/{name}")
    public String putHello(@PathVariable String name,@RequestBody Map<String,String> map){
        System.out.println(name);
        System.out.println(map.toString());
        return "请求接收成功";
    }
    @DeleteMapping("/{name}")
    public String deleteHello(@PathVariable String name){
        System.out.println(name);
        return "请求接收成功";
    }
}
```

## Vue快速入门

Vue的作用是构建用户界面的渐进式框架，人话就是将数据和DOM元素进行绑定，当数据发生变化时，DOM元素会自动更新。

```html
<div id = "app"> //挂载点这块儿div中，就可以使用Vue的指令和表达式来渲染数据
    <h1>{{message}}</h1>
</div>
<script type = "module"> // 模块化JS
    import {createApp} from "https://unpkg.com/vue@3/dist/vue.esm-browser.js";  //从官网导入Vue模块createApp
    //直接调用createApp方法创建Vue实例,这里createApp的参数是一个JS对象,对象中可以定义Vue实例的属性和方法
    createApp(
        {
            data(){
                return{
                    message:"hello vue"
                }
            }
        }
    ).mount("#app");  //将Vue实例挂载到id为app的元素上
```

## HTTP协议

http协议是超文本传输协议，是一种应用层协议，用于客户端和服务器之间的通信。
其特点是：

1. 基于请求响应模型：一次请求对应一次响应
2. 无状态: 每次请求都是独立的，服务器不会保留客户端的状态信息。
3. 无连接: 每次请求完成后，服务器会关闭与客户端的连接。
4. 基于TCP/IP协议

### HTTP请求数据格式

请求数据是客户端发送给服务器的信息，包括请求行、请求头、空行和请求体。
请求行：
请求行由请求方法、请求URL和HTTP版本组成，例如：
GET /index.html HTTP/1.1

请求头：
请求头包含了一些客户端的信息，例如：

| 请求头名称 | 简介 | 示例 |
| ---------- | ---- | ---- |
| Host | 主机名和端口号 | `Host: www.example.com:80` |
| User-Agent | 客户端浏览器信息 | User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36 |
| Accept | 客户端可以接受的响应类型 | Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9 |
| Accept-Encoding | 客户端可以接受的压缩编码 | Accept-Encoding: gzip, deflate, br |
| Accept-Language | 客户端可以接受的语言 | Accept-Language: en-US,en;q=0.9 |
| Content-Type | 请求体的媒体类型 | Content-Type: application/x-www-form-urlencoded |
| Content-Length | 请求体的长度 | Content-Length: 13 |

请求体：
请求体包含了客户端发送给服务器的具体数据，例如表单数据、JSON数据等。
请求体的格式取决于请求头中的Content-Type字段。

### SpringBoot 接收请求参数

示例：

```java
package demo.springbootquickstart;

import jakarta.servlet.http.HttpServletRequest;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class RequsetController {

    @RequestMapping("/request")
    public String request(HttpServletRequest request){
        //1.获取请求方式
        String method = request.getMethod();
        System.out.println("请求方式：" + method);
        //2.获取请求url地址
        String url = request.getRequestURL().toString();
        System.out.println("请求url：" + url);
        String uri = request.getRequestURI();
        System.out.println("请求uri：" + uri);
        //3.获取请求协议
        String protocol = request.getProtocol();
        System.out.println("请求协议：" + protocol);
        //4.获取请求参数 - name,age
        String name = request.getParameter("name");
        String age = request.getParameter("age");
        System.out.println("请求参数：name:" + name+" ,age:"+age);

        //5.获取请求头 - Accept
        String acceptHeader = request.getHeader("Accept");
        System.out.println("请求头：" + acceptHeader);
        return "OK";

    }
}
package demo.springbootquickstart;

import jakarta.servlet.http.HttpServletRequest;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class RequsetController {

    @RequestMapping("/request")
    public String request(HttpServletRequest request){
        //1.获取请求方式
        String method = request.getMethod();
        System.out.println("请求方式：" + method);
        //2.获取请求url地址
        String url = request.getRequestURL().toString();
        System.out.println("请求url：" + url);
        String uri = request.getRequestURI();
        System.out.println("请求uri：" + uri);
        //3.获取请求协议
        String protocol = request.getProtocol();
        System.out.println("请求协议：" + protocol);
        //4.获取请求参数 - name,age
        String name = request.getParameter("name");
        String age = request.getParameter("age");
        System.out.println("请求参数：name:" + name+" ,age:"+age);

        //5.获取请求头 - Accept
        String acceptHeader = request.getHeader("Accept");
        System.out.println("请求头：" + acceptHeader);
        return "OK";

    }
}

```

### HTTP响应数据格式

响应数据是服务器发送给客户端的信息，包括状态行、响应头、空行和响应体。
状态行：
状态行由HTTP版本、状态码和状态描述组成，例如：
HTTP/1.1 200 OK

响应头：
响应头包含了一些服务器的信息，例如：

| 响应头名称 | 简介 | 示例 |
| ---------- | ---- | ---- |
| Server | 服务器信息 | Server: Apache/2.4.41 (Ubuntu) |
| Date | 响应时间 | Date: Mon, 20 Dec 2021 12:00:00 GMT |
| Content-Type | 响应体的媒体类型 | Content-Type: text/html; charset=UTF-8 |
| Content-Length | 响应体的长度 | Content-Length: 1234 |

响应体：
响应体包含了服务器发送给客户端的具体数据，例如HTML页面、JSON数据等。
响应体的格式取决于响应头中的Content-Type字段。

### 示例：修改http响应数据

```java
package demo.springbootquickstart;

import jakarta.servlet.http.HttpServletResponse;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;

@RestController
public class ResponseController {

    @RequestMapping("/response")
    public void response(HttpServletResponse response) throws IOException {
        //1.设置响应状态码
        response.setStatus(401);

        //2.设置响应头
        response.setHeader("name", "wobuhao");

        //3.设置响应体
        response.getWriter().write("<h1>hello response</h1>");
    }
    @RequestMapping("/response2")
    //SpringBoot提供的ResponseEntity类可以方便地设置响应状态码、响应头和响应体。
    public ResponseEntity<String> response2() {
        return ResponseEntity
                .status(401)
                .header("name", "wobuhao")
                .body("<h1>hello response</h1>");
    }

}

```

## SpringBoot开发Web应用简单案例

### java反射

### IO流

### hutool工具类

### `lines.stream().map(line -> ...`方法
