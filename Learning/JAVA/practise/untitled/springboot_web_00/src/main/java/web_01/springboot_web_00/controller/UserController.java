package web_01.springboot_web_00.controller;

import cn.hutool.core.io.IoUtil;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import web_01.springboot_web_00.pojo.User;

import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;


@RestController
public class UserController {

    @RequestMapping("/list")
    public List<User> list() throws Exception{
        //1.加载并读取user.txt
//        不建议写：InputStream in = new FileInputStream("D:\Learning\Learning\JAVA\practise\\untitled\springboot_web_00\src\main\resources\\user.txt");
//        因为绝对路径会把user.txt位置写死
        InputStream in = this.getClass().getClassLoader().getResourceAsStream("user.txt");
        ArrayList<String> lines = IoUtil.readLines(in, StandardCharsets.UTF_8,new ArrayList<>());
        //解析用户信息，封装为User对象->list集合
        List<User> userList = lines.stream().map(line -> {
            String[] parts = line.split(","); //将下面的数据按照，切割，并将其放入一个数组中
            Integer id = Integer.parseInt(parts[0]);
            String username = parts[1];
            String password = parts[2];
            String name = parts[3];
            Integer age = Integer.parseInt(parts[4]);
            LocalDateTime updateTime = LocalDateTime.parse(parts[5], DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));

            return new User(id,username,password,name,age,updateTime);
        }).toList();
        return userList;
    }

}
