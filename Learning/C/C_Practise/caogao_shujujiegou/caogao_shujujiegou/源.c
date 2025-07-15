//˫ָ�������ҵ�����k�����//
#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node* next;
}Node;

Node* initList()//��ʼ������
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

Node* get_tail(Node* L)//���β�ڵ�
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}
Node* insertTail(Node* tail, ElemType e) //����
{
	Node* p = (Node*)malloc(sizeof(Node));
	p -> data = e;
	tail -> next = p;
	p -> next = NULL;
	return p;
}

Node* listNode(Node* L) //����
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






//---����---
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
//	struct node* next; //next�洢����һ��node���ݵĵ�ַ
//}Node;
//
//Node* initList()
//{
//	Node* head = (Node*)malloc(sizeof(Node)); //�����ڴ�ռ䣬�����洢˳���ĵ�ַ
//	head->next = NULL; //��ʼ��ͷ����ָ����Ϊnull
//	head->data = 0; //��ʼ��ͷ����������Ϊ0
//	return head;
//}
//
//int insertHead(Node* L, ElemType e) //L��ͷ��㣬e��Ҫ���������
//{
//	Node* p = (Node*)malloc(sizeof(Node)); //�����ڴ�ռ䣬���� �洢�½��
//	p->data = e; //���½���������ֵΪe
//	p->next = L->next; //���½���ָ����ֵΪͷ����ָ����Ҳ����ԭ���ĵ�һ�����
//	L->next = p; //��ͷ����ָ����ֵΪ�½��ĵ�ַ��Ҳ�����½���Ϊ�˵�һ�����
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
//Node* get_tail(Node* L) //��ȡβ���
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
//{  //��p�洢ͷ���ĵ�ַ
//	Node* p = L;
//	int i = 0;
//	//�ҵ�Ҫ����λ�õ�ǰһ�����
//	while (i < pos - 1)
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		{
//			return 0;
//		}
//	}
//	//��ʼ��Ҫ������½ڵ�
//	Node* q = (Node*)malloc(sizeof(Node));
//	q->data = e;
//	q->next = p->next; // ��ǰһ������ָ���� ��ֵ�� �½���ָ����
//	p->next = q; // �ٽ� �½��ĵ�ַ ��ֵ�� ǰһ������ָ����
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

















//----------------˳���----------------------
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
//    SeqList* L = (SeqList*)malloc(sizeof(SeqList));//�����ڴ�ռ䣬�����洢˳���ĵ�ַ
//    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);//�����ڴ�ռ䣬�����洢˳����е����飬sizeof(ElemType)ֻ�ǵ���ElemType�Ĵ�С������MAXSIZE������������Ĵ�С
//    L->length = 0; //��ʼ������Ϊ0
//    return L;//���ص���L�ĵ�ַ
//}
//int append(SeqList* L, ElemType e)
//{
//    if (L->length == MAXSIZE) //�ж�˳����Ƿ�����
//    {
//        printf("˳����������޷����\n");
//        return 0;
//    }
//    L->data[L->length] = e;
//    L->length++; //���ȼ�1
//    return 1;
//}
//
//void listElem(SeqList* L) //����
//{
//    for (int i = 0; i < L->length; i++)
//    {
//        printf("%d ", L->data[i]);
//    }
//    printf("\n");
//}
//
//
//int insert(SeqList* L, int pos, ElemType e) //pos�ǲ���λ�ã�����pos-1���ǲ���λ�õ��±�
//{
//    if (pos <= L->length - 1 && pos >= 1) //�жϲ���λ���Ƿ�Ϸ�
//    {
//        for (int i = L->length - 1; i >= pos - 1; i--) //�Ӻ���ǰ��������pos-1λ�ú����Ԫ�ض�������һλ
//        {
//            L->data[i + 1] = L->data[i];
//        }
//        L->data[pos - 1] = e;
//        L->length++; //���ȼ�1
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
//    printf("��ʼ���ɹ���Ŀǰ����Ϊ%d\n", List->length);
//    printf("Ŀǰռ���ڴ�Ϊ%zu\n", sizeof(List->data));
//    return 0;
//}