//双指针解决查找倒数第k个结点//
#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node* next;
}Node;

Node* initList()//初始化链表
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

Node* get_tail(Node* L)//获得尾节点
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}
Node* insertTail(Node* tail, ElemType e) //插入
{
	Node* p = (Node*)malloc(sizeof(Node));
	p -> data = e;
	tail -> next = p;
	p -> next = NULL;
	return p;
}

Node* listNode(Node* L) //遍历
{
	Node* p = L->next;
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Node* list = initList();
	Node* tail = get_tail(list);
	tail = insertHead(tail, 10);
	tail = insertHead(tail, 20);
	tail = insertHead(tail, 30);
	listNode(list);
	return 0;
}






//---链表---
// 
// 
// 
// 
// 
//#include <stdio.h>
//#include <malloc.h>
//
//typedef int ElemType;
//
//typedef struct node
//{
//	ElemType data;
//	struct node* next; //next存储了下一个node数据的地址
//}Node;
//
//Node* initList()
//{
//	Node* head = (Node*)malloc(sizeof(Node)); //申请内存空间，用来存储顺序表的地址
//	head->next = NULL; //初始化头结点的指针域为null
//	head->data = 0; //初始化头结点的数据域为0
//	return head;
//}
//
//int insertHead(Node* L, ElemType e) //L是头结点，e是要插入的数据
//{
//	Node* p = (Node*)malloc(sizeof(Node)); //申请内存空间，用来 存储新结点
//	p->data = e; //将新结点的数据域赋值为e
//	p->next = L->next; //将新结点的指针域赋值为头结点的指针域，也就是原来的第一个结点
//	L->next = p; //将头结点的指针域赋值为新结点的地址，也就是新结点成为了第一个结点
//	return 0;
//}

//void listNode(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//Node* get_tail(Node* L) //获取尾结点
//{
//	Node* p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	return p;
//}
//
//Node* insertTail(Node* tail, ElemType e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	tail->next = p;
//	p->next = NULL;
//	return p;
//}
//
//int insertNode(Node* L, int pos, ElemType e)
//{  //用p存储头结点的地址
//	Node* p = L;
//	int i = 0;
//	//找到要插入位置的前一个结点
//	while (i < pos - 1)
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		{
//			return 0;
//		}
//	}
//	//初始化要插入的新节点
//	Node* q = (Node*)malloc(sizeof(Node));
//	q->data = e;
//	q->next = p->next; // 将前一个结点的指针域 赋值给 新结点的指针域
//	p->next = q; // 再将 新结点的地址 赋值给 前一个结点的指针域
//	return 1;
//}
//
//int main()
//{
//	Node* list = initList();
//	Node* tail = get_tail(list);
//	tail = insertTail(tail, 10);
//	tail = insertTail(tail, 20);
//	tail = insertTail(tail, 30);
//	listNode(list);
//	insertNode(list, 2, 15);
//	listNode(list);
//	return 0;
//}
//
//
//
//
//
//
//

















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