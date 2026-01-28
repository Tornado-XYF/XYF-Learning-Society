# MySQL

## 创建数据库

CREATE DATABASE [IF NOT EXISTS] 数据库名;

## 删除数据库

DROP DATABASE [IF EXISTS] 数据库名;

## 选择数据库

USE 数据库名;

## 数据类型汇总

| 数据类型 | 描述 | 范围 |
| --- | --- | --- |
| INT | 整数 | -2147483648 ~ 2147483647 |
| FLOAT | 单精度浮点数 | -3.402823466E+38 ~ -1.175494351E-38, 0, 1.175494351E-38 ~ 3.402823466E+38 |
| DOUBLE | 双精度浮点数 | -1.7976931348623157E+308 ~ -2.2250738585072014E-308, 0, 2.2250738585072014E-308 ~ 1.7976931348623157E+308 |
| CHAR | 固定长度字符串 | 0 ~ 255 bytes |
| VARCHAR | 可变长度字符串 | 0 ~ 65535 bytes |
| TEXT | 长文本 | 0 ~ 65535 bytes |
| DATE | 日期 | 格式：YYYY-MM-DD |
| DATETIME | 日期和时间 | 格式：YYYY-MM-DD HH:MM:SS |
| TIMESTAMP | 时间戳 | 格式：YYYY-MM-DD HH:MM:SS |
| BOOLEAN | 布尔值 | TRUE, FALSE |

## 创建表

CREATE TABLE [IF NOT EXISTS] 表名 (
    列名1 数据类型1,
    列名2 数据类型2,
    ...
);
可以在创建表时指定主键、外键、索引，不为空等约束。
如：
CREATE TABLE [IF NOT EXISTS] 表名 (
    列名1 数据类型1 PRIMARY KEY,
    列名2 数据类型2 NOT NULL,
    ...
);

PRIMARY KEY 意思是主键，用于唯一标识每一行数据。
NOT NULL 意思是不为空，即该列不能存储 NULL 值。

## 删除表

DROP TABLE [IF EXISTS] 表名;
若只是删除表中数据而不删除表结构，可使用以下语句：
TRUNCATE TABLE 表名;

## 插入数据

INSERT INTO 表名 (列名1, 列名2, ...)
VALUES (值1, 值2, ...);

### NULL用于自增长列的占位符，表示系统将为id列生成唯一的自增数值
