# 功能基础数据模型

from pydantic import BaseModel ##数据验证包
from typing import List,Optional ##类型标注
from datetime import datetime ##时间日期

class UserBase(BaseModel):
    username: str
    email:str

class UserCreate(UserBase):
    password: str

class UserOut(UserBase):
    id:int
    created_at:datetime

    class Config:
        from_attributes = True;

class ArticleBase(BaseModel):
    title: str
    content : str
    published : bool = True

class ArticleCreate(ArticleBase):
    pass

class ArticleOut(ArticleBase):
    id : int
    author_id : int
    created_at : datetime
    updated_at : datetime

    class Config:
        from_attributes = True;

