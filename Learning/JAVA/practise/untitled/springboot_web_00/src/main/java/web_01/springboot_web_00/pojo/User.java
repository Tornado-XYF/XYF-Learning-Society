package web_01.springboot_web_00.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * 封装用户信息
 */
@Data  //lombok，为下面封装的各个信息自动使用get方法
@NoArgsConstructor
@AllArgsConstructor
public class User {

    private Integer id; //要用包装类
    private String username;
    private String password;
    private String name;
    private Integer age;
    private LocalDateTime updateTime;
}
