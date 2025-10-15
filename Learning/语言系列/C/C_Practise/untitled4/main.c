#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char no[20];   								//书号
	char name[100]; 							//书名
	float price;   								//价格
}Book;

typedef struct{
	Book *elem; 								//指向数组的指针
	int length; 								//数组的长度
}SqList;

void InitList(SqList &L){
//使用动态内存分配new进行初始化
*L->elem = (Book *)malloc(sizeof(Book));
}

void FreeList(SqList &L){
//释放内存
free();
}

void ReadFile(SqList &L, char filepath){
//从文件中读取图书信息，将其按顺序存入L.elem指向的数组中

}

int main()
{
	char filename;
    filename = getchar();
	SqList L;
	InitList(L);
	ReadFile(L, filename);
}