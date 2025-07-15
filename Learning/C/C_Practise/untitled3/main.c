#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node* next; //next存储了下一个node数据的地址
}Node;

Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node)); //申请内存空间，用来存储顺序表的地址
	head->next = NULL; //初始化头结点的指针域为null
	head->data = 0; //初始化头结点的数据域为0
	return head;
}

int insertHead(Node* L, ElemType e) //L是头结点，e是要插入的数据
{
	Node* p = (Node*)malloc(sizeof(Node)); //申请内存空间，用来 存储新结点
	p->data = e; //将新结点的数据域赋值为e
	p->next = L->next; //将新结点的指针域赋值为头结点的指针域，也就是原来的第一个结点
	L->next = p; //将头结点的指针域赋值为新结点的地址，也就是新结点成为了第一个结点
	return 0;
}

void listNode(Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
Node* get_tail(Node* L) //获取尾结点
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}
int main()
{
	Node* list = initList();
	Node* tail = get_tail(list);
	tail = insertTail(tail, 10);
	tail = insertTail(tail, 20);
	tail = insertTail(tail, 30);
	listNode(list);
	return 0;
}






















