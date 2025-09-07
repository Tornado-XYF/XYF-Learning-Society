#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
    struct node *prev; //前驱
}Node;

Node* initList() {
    Node *head =  (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;
    head->data = 0;
    return head;
}
int insertHead(Node* L,ElemType e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if (L->next != NULL) {
        L->next->prev = p;
    }
    L->next = p;
return 1;
}
void listNode(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

Node *getTail(Node *L) {
    Node *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    return p ;
}
Node * insertTail(Node *tail,ElemType e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}
void freeList(Node* L) {
    Node *p = L;
    Node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}
int insertNode(Node* L, int pos, ElemType e)
{  //用p存储头结点的地址
    Node* p = L;
    int i = 0;
    //找到要插入位置的前一个结点
    while(i < pos-1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }

    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    if(p->next != NULL)
        p->next->prev = q;
    p->next = q;
    return 1;
}
int insertDele(Node* L, int pos)
{  //用p存储头结点的地址
    Node* p = L;
    int i = 0;
    //找到要插入位置的前一个结点
    while(i < pos-1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }

    if(p->next == NULL)
        return 0;

    Node *q = p->next;
    p->next = q->next;
    q->next->prev = q->prev;
    free(q);
    return 1;
}
int main() {
    Node* list = initList();
    Node *tail = getTail(list);
    tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    insertNode(list,3,15);
    listNode(list);
    insertDele(list,2);
    listNode(list);
    freeList(list);
    return 0;
}
