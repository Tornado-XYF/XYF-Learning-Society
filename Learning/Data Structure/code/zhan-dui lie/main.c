#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 8

typedef int ElemType;

//构成链表
typedef struct QueueNode {
    ElemType data;
    struct QueueNode *next;
}QueueNode;

//构成队列
typedef struct //动态内存分配初始化
{

    QueueNode * front;
    QueueNode * rear;
}Queue;

Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));//创立头结点
    node->data = 0;
    node->next = NULL;
    q->front = node; //node 就是头结点
    q->rear = node;
    return q;
}

//进队
void equeue(Queue *q,ElemType e) {
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue *q,ElemType *e) {
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node) {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//判断队列是否为空
int isEmpty(Queue *Q) {
    if (Q == NULL)
        return 2;
    if (Q->front == Q->rear) {
        return 1;
    }
    return 0;
}

//获取队头元素
ElemType getFront(Queue *q) {
    if (isEmpty(q)) {
        printf("空了\n");
        return 0;
    }
    return q->front->next->data;
}

int main() {
    Queue *Q = initQueue();
    equeue(Q,10);
    equeue(Q,20);
    equeue(Q,30);
    equeue(Q,40);
    ElemType e;
    dequeue(Q,&e);
    printf("%d\n",e);
    dequeue(Q,&e);
    printf("%d\n",e);
    printf("%d\n",getFront(Q));

    return 0;
}













//-----------以下是循环队列------------
// typedef int ElemType;
//
// typedef struct //动态内存分配初始化
// {
//     ElemType *data;
//     int front;
//     int rear;
// }Queue;
//
// Queue *initQueue()
// {
//     Queue *q = (Queue*)malloc(sizeof(Queue));
//     q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//     q->front = 0;
//     q->rear = 0;
//     return q;
// }
//
// //循环队列入队
//
// int equeue(Queue *Q,ElemType e) {
//     if (Q == NULL)
//         return 2;
//     if ((Q->rear + 1)%MAXSIZE == Q->front) {
//         printf("满了\n");
//         return 1;
//     }
//     Q->data[Q->rear] = e;
//     Q->rear = (Q->rear + 1) % MAXSIZE; //这里没有直接+1，是因为下标是数组，直接+1最后会出现下标为8的情况，但实际上是0
//     return 0;
// }
//
// //循环队列出队
//
// ElemType dequeue(Queue *Q,ElemType *e) {
//     if (Q == NULL)
//         return 2;
//    if (Q->front == Q->rear) {
//        printf("空了\n");
//        return 1;
//    }
//     *e = Q->data[Q->front];
//     Q->front = (Q->front+1) % MAXSIZE;
//     return 0;
// }
//
// int getHead(Queue *Q,ElemType *e) {
//     if (Q == NULL)
//         return 2;
//     if (Q->front == Q->rear) {
//         printf("空了\n");
//         return 1;
//     }
//     *e = Q->data[Q->front];
//     return 0;
// }
//
// int isEmpty(Queue *Q) {
//     if (Q == NULL)
//         return 2;
//     if (Q->front == Q->rear) {
//         printf("空了\n");
//         return 1;
//     }
//     return 0;
// }
// int main() {
//     Queue *Q = initQueue();
//     isEmpty(Q);
//     equeue(Q,10);
//     equeue(Q,20);
//     equeue(Q,30);
//     equeue(Q,40);
//     ElemType e;
//     dequeue(Q,&e);
//     printf("%d\n",e);
//     dequeue(Q,&e);
//     printf("%d\n",e);
//     getHead(Q,&e);
//     printf("%d\n",e);
//     free(Q->data);
//     free(Q);
//     return 0;
// }

















// -------------以下是栈-------------------
// typedef int ElemType;
//
// typedef struct {
//     ElemType *data;
//     int top;
// }Stack;
//
// Stack* initStack() { //初始化
//    Stack *s = (Stack*)malloc(sizeof(Stack));
//     s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//     s->top = -1;
//     return s;
// }
//
// int isEmpty(Stack *s) { //判断是否为空
//     if (s->top == -1) {
//       printf("空的\n");
//         return 1;
//     }
//     else {
//         return  0;
//     }
// }
//
// int push(Stack *s, ElemType e) {//进栈
//     if (s->top >= MAXSIZE -1) {
//         printf("栈满\n");
//         return 0;
//     }
//     else {
//         s->top++;
//         s->data[s->top] = e;
//         return 1;
//     }
// }
//
// int pop(Stack *s, ElemType *e) //出栈
// {
//     if (s->top == -1) {
//         printf("栈空\n");
//         return 0;
//     }
//     else {
//         *e = s->data[s->top]; //把要删除的数据传出去
//         s->top--;
//         return 1;
//     }
// }
//
// int getTop(Stack *s, ElemType *e) {
//         if (s->top == -1) {
//             printf("栈空\n");
//             return 0;
//         }
//         else {
//             *e = s->data[s->top];
//             return 1;
//         }
// }
//
// //动态内存分配
//
// int main() {
//     Stack *s = initStack();
//     push(s, 1);
//     push(s, 2);
//     push(s, 3);
//     push(s, 4);
//     ElemType e;
//     pop(s,&e);
//     printf("%d\n",e);
//     getTop(s,&e);
//     printf("%d\n",e);
//
//     free(s->data);
//     free(s);
//     return 0;
// }