







#include <stdio.h>
#include<stdlib.h>

typedef int E;

typedef struct node
{
	E date;
	struct node* next;
} Node;

Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->date = 0;
	return head;
}
int insertHead(Node* L, E x)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->date = x;

	p->next = L->next;
	L->next = p;
   
	

	return 1;
}

int deletNode(Node* L, int y) 
{
	Node* p = L;
	int i = 0;
	while (i < y - 1) 
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}

	if (p->next == NULL)
	{
		printf("删除位置错误\n");
		return 0;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

void listNode(Node* L)
{
	Node* p = L;
	while (p != NULL)
	{
		printf("%d \n", p->date);
		p = p->next;
	}

	printf("\n");

}
int main()
{
	Node* list = initList();
	insertHead(list, 1);
	insertHead(list, 2);
	insertHead(list, 3);
	listNode(list);

	return 0;
}


























//
//typedef int ElemType;
//
//typedef struct node {
//	ElemType data;
//	struct node* next;
//}Node;
//
//Node* initList()//初始化链表
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->data = 0;
//	head->next = NULL;
//	return head;
//}
//
//Node* get_tail(Node* L)//获得尾节点
//{
//	Node* p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	return p;
//}
//Node* insertHead(Node* tail, ElemType e) //插入
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	tail->next = p;
//	p->next = NULL;
//	return p;
//}
//
//Node* listNode(Node* L) //遍历
//{
//	Node* p = L->next;
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//void freeList(Node* L)
//{
//	Node* p = L->next;
//	Node* q;
//	while (p != NULL)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	L->next = NULL;
//}
//
////查找倒数第K个结点
//int findNodeFS(Node* L, int k) 
//{
//	Node* fast = L->next;
//	Node* slow = L->next;
//
//	for (int i = 0; i < k; i++)
//	{
//		fast = fast->next;
//	}
//	while (fast != NULL)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//
//	printf("倒数第%d个节点值为：%d \n", k, slow->data);
//	return 1;
//}
//int main()
//{
//	Node* list = initList();
//	Node* tail = get_tail(list);
//	tail = insertHead(tail, 21);
//	tail = insertHead(tail, -15);
//	tail = insertHead(tail, -15);
//	tail = insertHead(tail, -15);
//	tail = insertHead(tail, -15);
//
//	listNode(list);
//	findNodeFS(list, 2);
//	freeList(list);
//	return 0;
//}
