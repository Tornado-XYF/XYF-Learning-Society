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
    public ResponseEntity<String> response2() {
        return ResponseEntity
                .status(401)
                .header("name", "wobuhao")
                .body("<h1>hello response</h1>");
    }

}
