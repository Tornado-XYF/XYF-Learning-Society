
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char TreeType;
typedef struct TreeNode {
    TreeType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

//构成链表
typedef struct QueueNode {
    TreeType data;
    struct QueueNode *next;
}QueueNode;

typedef TreeNode *ElemType;//构成队列

typedef struct //动态内存分配初始化
{
    ElemType *data;
    int front;
    int rear;
}Queue;

typedef TreeNode *BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

int equeue(Queue *Q,ElemType e) {
    if (Q == NULL)
        return 2;
    //对应上面的修改此处应该是
    //Q->rear = (Q->rear + 1) % MAXSIZE;那么下面的相同的语句就要删掉了
    if ((Q->rear + 1)%MAXSIZE == Q->front) {
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //这里没有直接+1，是因为下标是数组，直接+1最后会出现下标为8的情况，但实际上是0
    return 1;
}

int dequeue(Queue *Q,ElemType *e) {
    if (Q == NULL)
        return 2;
    if (Q->front == Q->rear) {
        printf("空了\n");
        return 1;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % MAXSIZE;
    return 0;
}

int isEmpty(Queue *Q)
{   if (Q == NULL)
       return 2;
    if(Q->front == Q->rear)
    {
        // printf("空的\n");
        return 1;
    }
    else
        return 0;

}

void createTree(BiTree *T) {
    TreeType ch;
    ch = str[idx++];
    if (ch == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}

int queueSize(Queue *Q) {
    if (Q == NULL)
        return 2;

    if (!isEmpty(Q)) {
        return Q->rear - Q -> front;
    }
    else
        return 0;
}

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int depth = 0;
    Queue *q = initQueue();
    equeue(q,root);

    while (!isEmpty(q)) {
        int count = queueSize(q); //判断队列当中有多少元素
        while (count > 0) {
            TreeNode *curr;
            dequeue(q,&curr);
            if (curr->lchild != NULL) {
                equeue(q,curr->lchild);
            }
            if (curr->rchild != NULL) {
                equeue(q,curr->rchild);
            }
            count--;
        }
        depth++;
    }
return depth;
}
int main(void) {
    BiTree T;
    createTree(&T);
    printf("%d\n",maxDepth(T));
    return 0;
}