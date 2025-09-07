#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild; //指向前驱或左孩子
    struct ThreadNode *rchild; //指向后继或右孩子
    int ltag;  // 为0时指向左孩子，为1时指向前驱
    int rtag;  // 为0时指向右孩子，为1时指向后继
}ThreadNode;

typedef ThreadNode *ThreadTree; //这里修改的话下面的函数就不用加*了，但是这是老祖宗的做法了

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0; //下标

ThreadTree prev;

//创建树
void createTree(ThreadTree *T) { //c语言特性，这里只有加*，c语言才知道你传入的是个指针，否则他只会认为你穿进来的只是一个赋有地址的值
    ElemType ch;
    ch = str[idx++];
    if(ch == '#') {
        *T = NULL;
    }
    else {
        *T = (ThreadTree)malloc(sizeof(ThreadNode));
        (*T)->data = ch;

        createTree(&(*T)->lchild);
        if ((*T)->lchild != NULL) {
            (*T)->ltag = 0;
        }

        createTree(&(*T)->rchild);
        if ((*T)->rchild != NULL) {
            (*T)->rtag = 0;
        }
    }
}

//针对每一个节点加线索
void threading(ThreadTree T) {
    if (T != NULL) {
        threading(T->lchild);
        if (T->lchild == NULL) {
            T->ltag = 1 ;
            T->lchild = prev;
        }
        if (prev->rchild == NULL) {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        threading(T->rchild);
    }
}
//开始线索化
void inOrderThreading(ThreadTree *head, ThreadTree T) {
    //线索化需要创建一个头结点，类似于链表
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);

    if (T==NULL) {
        (*head)->lchild = *head;
    }
    else {
        (*head)->lchild = T;
        prev = (*head);

        threading(T);

        //最后一个结点线索化
        prev->rchild = *head;
        prev->rtag = 1;

        //头结点右孩子指向最后一个结点
        (*head)->rchild = prev;
    }
}

void  inOrder(ThreadTree T) {
    ThreadTree curr;
    curr = T->lchild;
    while (curr != T) {
        while (curr -> ltag == 0) {
            curr = curr->lchild;
        }
        printf("%c",curr->data);

        while (curr->rtag == 1 && curr->rchild != T) {
            curr = curr->rchild;
            printf("%c",curr->data);
        }
        curr = curr->rchild;
    }
    printf("\n");
}
int main() {
    ThreadTree head;
    ThreadTree T;
    createTree(&T);
    inOrderThreading(&head, T); //x线索化
    inOrder(head);
    return 0;
}


//-----------------------------------------------------------
// typedef char ElemType;
// typedef struct TreeNode {
//     ElemType data;
//     struct TreeNode *lchild;
//     struct TreeNode *rchild;
// }TreeNode;
//
// typedef TreeNode *BiTree;
//
// char str[] = "ABDH#K###E##CFI###G#J##";
// int idx = 0;
//
// void midOrder(BiTree T) {
//     if (T == NULL)
//         return;
//     midOrder(T->lchild);
//     printf("%c",T->data);
//     midOrder(T->rchild);
// }
//
// void createTree(BiTree *T) {
//     ElemType ch;
//     ch = str[idx++];
//     if (ch == '#') {
//         *T = NULL;
//     }
//     else {
//         *T = (BiTree)malloc(sizeof(TreeNode));
//         (*T)->data = ch;
//         createTree(&(*T)->lchild);
//         createTree(&(*T)->rchild);
//     }
// }
// int main(void) {
//     BiTree T;
//     createTree(&T);
//     midOrder(T);
//     return 0;
// }

















// -----------前序遍历--------------
// typedef char ElemType;
// typedef struct TreeNode {
//     ElemType data;
//     struct TreeNode *lchild;
//     struct TreeNode *rchild;
// }TreeNode;
//
// typedef TreeNode *BiTree;
//
// char str[] = "ABDH#K###E##CFI###G#J##";
// int idx = 0;
//
// void preOrder(BiTree T) {
//     if (T == NULL)
//         return;
//     printf("%c",T->data);
//     preOrder(T->lchild);
//     preOrder(T->rchild);
// }
//
// void createTree(BiTree *T) {
//     ElemType ch;
//     ch = str[idx++];
//     if (ch == '#') {
//         *T = NULL;
//     }
//     else {
//         *T = (BiTree)malloc(sizeof(TreeNode));
//         (*T)->data = ch;
//         createTree(&(*T)->lchild);
//         createTree(&(*T)->rchild);
//     }
// }
// int main(void) {
//     BiTree T;
//     createTree(&T);
//     preOrder(T);
//     return 0;
// }
//
//
