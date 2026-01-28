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
