#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
}Node;

//��ʼ��
Node *initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head -> data = 0;
    return head;
}

//ͷ�巨
void insertHead(Node *L,ElemType e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}


//��ȡβ�ڵ�
Node *get_tail(Node* L) {
    Node* p =L;
    while ( p->next != NULL ) {
        p = p->next;
    }
    return p;
}

//β�巨
Node *insertTail(Node *tail,ElemType e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail -> next = p;
    p->next = NULL;
    return p;
}


//����
void listNode(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

//�ͷ�
void freeList(Node *L) {
    if (L == NULL) {
        return;
    }
    Node *p = L->next;
    Node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

//ָ��λ�ò���
int insertNode(Node* L,int pos, ElemType e) {
    Node* p = L;
    Node* q = (Node*)malloc(sizeof(Node));
    int i = 0;
    while ( i < pos - 1) {
        p = p -> next;
        i++;
        if (p == NULL) {
            printf("����λ�ò��Ϸ�" );
            return 0 ;
        }
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//ָ��λ��ɾ��
int deleteNode(Node* L,int pos,ElemType *e) {
    Node* p = L;
    int i = 0;

    while (i < pos -1) {
        p = p->next;
        i++;
        if (p == NULL) {
            return 0;
        }
    }

    if (p -> next == NULL) {
        printf("ɾ��λ�ò��Ϸ�");
        return 0;
    }

    Node* q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

//���ҵ������е�����K��λ���ϵĽ��

int findNodeFS(Node *L,int k) {
    Node* fast = L->next;
    Node* slow = L->next;

    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    printf("������%d��λ���ϵĽ��Ϊ%d\n",k,slow->data);
    return 1;
}

//ɾ������ֵ��ͬ�Ľڵ�

void removeNode(Node *L,int n) { //n�����������ұ�����������<=n
    Node* p = L;
    int *q = (int*)malloc(sizeof(int)*(n - 1));
        for (int i = 0; i < n-1;i++) {
            *(q+i) = 0;
        }//�������飬����ʼ��Ϊ0
    int index;
    while (p -> next != NULL) {
        index = abs(p -> next -> data);
        if (*(q+index) == 0) {
            *(q+index) = 1; //��������е�Ԫ��Ϊ0��˵���þ���ֵû�г��ֹ�����ô�þ���ֵ��Ӧ���±��ֵ����Ϊ1
            p = p -> next;
        }
        else { //��������е�Ԫ�ز�Ϊ0��˵���þ���ֵ�Ѿ����ֹ�����ô����Ҫ��Ҫɾ���ڵ��ͷ��ڴ�
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

//��ת����

Node* reverseList(Node *head) {
    Node* first = NULL;
    Node* second = head->next;
    Node* third;

    while (second != NULL) {
        third = second -> next;
        second -> next = first;
        first = second;
        second = third;
    }

    Node *hd = initList();
    hd->next = first;

    return hd;
}

int main() {
    Node *list = initList();
    Node* tail = get_tail(list);
    tail = insertTail(tail,1);
    tail = insertTail(tail,20);
    freeList(list);

    free(list);
    free(tail);
    return 0;
}

// #define MAXSIZE 100
//
// typedef int ElemType;
//
// typedef struct
// {
//     ElemType data[MAXSIZE];
//     int length;
// }SeqList;
//
// void init(SeqList *L)
// {
//     L->length = 0;
// }
//
// //β�����
//
// int append(SeqList *L,ElemType e) {
//     //���ж�˳����Ƿ��Ѿ�����
//     if (L->length == MAXSIZE) {
//         printf("˳����Ѿ����ˡ��޷����");
//         return 0;
//     }
//     L->data[L->length] = e;
//     L->length++;
//     return 1;
// }
//
// //˳���ı���
// void listElem(SeqList *L) {
//     for (int i = 0; i < L->length;i++) {
//         printf("%d ",L->data[i]);
//     }
//     printf("\n");
// }
//
// //˳���Ĳ���
//
// int insert(SeqList *L,int pos,ElemType e) {
//     //������λ���Ƿ�Ϸ�
//     if (pos <= L->length && pos >= 0) {
//         for (int i = L->length-1;i >= pos - 1;i--) {
//             L->data[i+1] = L->data[i]; // ��pos-1λ���Լ��Ժ��Ԫ�ض������ƶ�һλ
//         }
//         L->data[pos - 1] = e;
//         L->length++;
//         return 1;
//     }
//     else {
//         printf("����λ�ò��Ϸ�");
//         return 0;
//     }
// }
//
// //˳����ɾ��
// int delete(SeqList *L,int pos,ElemType *e) {
//     *e = L->data[pos - 1];
//     if (pos < L->length && pos >= 0) {
//         for (int i = pos ;i < L->length -1 ; i++) {
//             L->data[i-1] = L->data[i];
//         }
//     }
//     L->length--;
//     return 1;
// }
//
// int main() {
//     SeqList List;
//     init(&List);
//     printf("��ʼ���ɹ�����ǰ˳�����Ϊ%d\n",List.length);
//     printf("Ŀǰռ���ڴ�Ϊ��%zu\n",sizeof(List.data));
//     return 0;
// }



