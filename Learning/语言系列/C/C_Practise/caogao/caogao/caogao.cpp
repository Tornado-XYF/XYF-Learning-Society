#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
ElemType *data[MAXSIZE];
int length;
}SeqList;

void init(SeqList *L)
{
L->length = 0;}























//----------------顺序表----------------------
//#define MAXSIZE 100
//typedef int ElemType;
//
//typedef struct
//{
//    ElemType* data;
//    int length;
//}SeqList;
//
//SeqList* initList()
//{
//    SeqList* L = (SeqList*)malloc(sizeof(SeqList));//申请内存空间，用来存储顺序表的地址
//    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);//申请内存空间，用来存储顺序表中的数组，sizeof(ElemType)只是单个ElemType的大小，乘以MAXSIZE才是整个数组的大小
//    L->length = 0; //初始化长度为0
//    return L;//返回的是L的地址
//}
//int append(SeqList* L, ElemType e)
//{
//    if (L->length == MAXSIZE) //判断顺序表是否已满
//    {
//        printf("顺序表已满，无法添加\n");
//        return 0;
//    }
//    L->data[L->length] = e;
//    L->length++; //长度加1
//    return 1;
//}
//
//void listElem(SeqList* L) //遍历
//{
//    for (int i = 0; i < L->length; i++)
//    {
//        printf("%d ", L->data[i]);
//    }
//    printf("\n");
//}
//
//
//int insert(SeqList* L, int pos, ElemType e) //pos是插入位置，所以pos-1就是插入位置的下标
//{
//    if (pos <= L->length - 1 && pos >= 1) //判断插入位置是否合法
//    {
//        for (int i = L->length - 1; i >= pos - 1; i--) //从后往前遍历，将pos-1位置后面的元素都往后移一位
//        {
//            L->data[i + 1] = L->data[i];
//        }
//        L->data[pos - 1] = e;
//        L->length++; //长度加1
//        return 1;
//    }
//}
//
//int main()
//{
//    SeqList *List = initList();
//    append(List, 1);
//    append(List, 2);
//    append(List, 3);
//    listElem(List);
//    insert(List, 2, 71);
//    listElem(List);
//    printf("初始化成功，目前长度为%d\n", List->length);
//    printf("目前占用内存为%zu\n", sizeof(List->data));
//    return 0;
//}