from fastapi import FastAPI, HTTPException, status, Depends, Body, Query, Path
from fastapi.security import HTTPBasic, HTTPBasicCredentials
from pydantic import BaseModel, EmailStr, constr, Field
from typing import List, Optional
import secrets
from datetime import datetime

app = FastAPI(title = "个人博客API（无数据库版本)",
              description = "适合我这种笨蛋学习的",
              version = "1.0")

security = HTTPBasic() #存疑？？？？？？？？？？？？？？？？？？？？？

#存储结构模拟数据库
users_db = []
posts_db = []
comments_db = []
next_user_id = 1
next_post_id = 1
next_comment_id = 1

#Pydantic数据模型

class UserBase(BaseModel):
    username: constr(min_length=3, max_length=20) = Field(...,example = "john_doe")
    email: EmailStr = Field(...,example = "john@example.com")

class UserCreate(UserBase):
    password: constr(min_length = 6) = Field(...,example = "securepassword")

class UserResponse(UserBase):
    id:int
    is_active: bool
    created_at: datetime

class PostBase(BaseModel):
    title: constr(min_length = 1, max_length = 200) = Field(...,example = "我的第一篇博客")
    content: constr(min_length = 1) = Field(...,example = "这是我的博客内容")
    is_published: bool = Field(True , example = True)

class PostCreate(PostBase):
    pass


#？？？？？？？？？？？这里的Optionnal是什么？？？？？？？？？？？？？？？？
class PostUpdate(BaseModel):
    title: Optional[constr(min_length = 1,max_length = 200)] = Field(None,example = "更新后的标题")
    content: Optional[constr(min_length=1)] = Field(None , example = "更新后的内容...")
    is_published: Optional[bool] = Field(None,examples=False)

class PostResponse(PostBase):
    id:int
    author_id : int
    create_at : datetime
    updated_at: Optional[datetime] = None

class CommentBase(BaseModel):
    content: constr(min_length = 1,max_length = 1000) = Field(...,example = "很好的文章")
    author_name: constr(min_length = 1,max_length = 50) = Field(...,example = "读者A")
    author_email:Optional[EmailStr] = Field(None, example = "reader@example.com")

class CommentCreate(CommentBase):
    post_id : int = Field(...,example = 1)

class CommentResponse(CommentCreate):
    id: int
    post_id: int
    is_approved: bool
    created_at: datetime

class LoginRequest(BaseModel):
    username: str = Field(...,examples = "john_doe")
    password: str = Field(...,examples = "securepassword")

class Token(BaseModel):
    access_token: str
    token_type: str


def init_database():
    conn = sqlite3.connect('blog.db')
    cursor = conn.cursor()

   # 创建用户表
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    ''')

    # 创建文章表
    cursor.execute(''' CREATE TABLE IF NOT EXISTS articles (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            content TEXT NOT NULL,
            published BOOLEAN DEFAULT TRUE,
            author_id INTEGER,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (author_id) REFERENCES users (id)
        )
    ''')

    conn.commit()
    conn.close()


app = FastAPI(title = "我的博客API",description="个人博客后端接口")

#数据库连接

def get_db():
    conn = sqlite3.connect('blog.db') #创建数据库‘blog.db'，并建立连接
    try:
        yield conn #返回数据库连接
    finally:
        conn.close() #关闭数据库连接

@app.post("/users/",response_model=UserOut)  #调用 这里其实用了装饰器
async def create_user(user:UserCreate,db = Depends(get_db)): #接收参数:user
    #密码加密
    hashed_password = hashlib.sha256(user.password.encode()).hexdigest()

    cursor = db.cuosor() #创建数据库游标，即来执行SQL命令和管理结果

    #利用游标执行SQL命令
    #
    cursor.execute("INSERT INTO users(username,email,[password) VALUES (?, ? , ?)",
    (user.username,user.email,hashed_password)# 这里是要填写的具体信息
    )
    db.commit() #提交信息至数据库

    return {**user.dict(),"id":cursor.lastrowid,"created_at":"2025"}

@app.get("/articles/",response_model = List[ArticleOut])
async def get_articles(db = Depends(get_db)):
    cursor = db.cursor()
    cursor.execute("SELECT * FROM articles")
    articles = cursor.fetchall()
    return articles

@app.post("/articles/",response_model = ArticleOut)
async def create_article(article:ArticleCreate,db = Depends(get_db)):
    cursor = db.cursor()
    cursor.execute(
        "INSERT INTO articles(title,content,published,author_id) VALUES (?,?,?,?)",
        (article.title,article.content,article.published,1)
    )
    db.commit()

    return {**article.dict(),"id":cursor.lastrowid,"author_id":1}


if __name__ == '__main__':
    init_database()
    print("数据库初始化完成")

