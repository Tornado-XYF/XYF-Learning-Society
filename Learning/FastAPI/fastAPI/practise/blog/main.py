from fastapi import FastAPI,HTTPException,Depends
from typing import List
import sqlite3
import hashlib
from models import *

app = FastAPI(title = "我的博客API",description="个人博客后端接口")

#数据库连接

def get_db():
    conn = sqlite3.connect('blog.db') #创建数据库‘blog.db'，并建立连接
    try:
        yield conn #返回数据库连接
    finally:
        conn.close() #关闭数据库连接

@app.post("/users/",response_model=UserOut)  #调用
async def create_user(user:UserCreate,db = Depends(get_db)):

