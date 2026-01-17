#define MAXSIZE 100
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top; //栈顶下标
}Stack;

void initStack(Stack *s) {
    s->top = -1; //当top为-1时，说明栈空
}



int main() {
    return 0;
}

//----------------------------------------以下是链表-------------------------------------



// #include <istream>
// #include <malloc.h>
// #include <cmath>
//
//
// typedef int ElemType;
//
// typedef struct node {
//     ElemType data;
//     struct node *next;
// }Node;
//
// //初始化
// Node *initList() {
//     Node *head = static_cast<Node*>(malloc(sizeof(Node)));
//     head->next = nullptr;
//     head -> data = 0;
//     return head;
// }
//
// //头插法
// void insertHead(Node *L,ElemType e) {
//     Node *p = static_cast<Node*>(malloc(sizeof(Node)));
//     p->data = e;
//     p->next = L->next;
//     L->next = p;
// }
//
//
// //获取尾节点
// Node *get_tail(Node* L) {
//     Node* p =L;
//     while ( p->next != nullptr ) {
//         p = p->next;
//     }
//     return p;
// }
//
// //尾插法
// Node *insertTail(Node *tail,ElemType e) {
//     Node *p = static_cast<Node*>(malloc(sizeof(Node)));
//     p->data = e;
//     tail -> next = p;
//     p->next = nullptr;
//     return p;
// }
//
//
// //遍历
// void listNode(Node *L) {
//     Node *p = L->next;
//     while (p != nullptr) {
//         printf("%d\n",p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
//
// //释放
// void freeList(Node *L) {
//     if (L == nullptr) {
//         return;
//     }
//     Node *p = L->next;
//     Node *q = nullptr;
//     while (p != nullptr) {
//         q = p->next;
//         free(p);
//         p = q;
//     }
//     L->next = nullptr;
// }
//
// //指定位置插入
// int insertNode(Node* L,int pos, ElemType e) {
//     Node* p = L;
//     Node *q = static_cast<Node*>(malloc(sizeof(Node)));
//     int i = 0;
//     while ( i < pos - 1) {
//         p = p -> next;
//         i++;
//         if (p == nullptr) {
//             printf("插入位置不合法" );
//             return 0 ;
//         }
//     }
//     q->data = e;
//     q->next = p->next;
//     p->next = q;
//     return 1;
// }
//
// //指定位置删除
// int deleteNode(Node* L,int pos,ElemType *e) {
//     Node* p = L;
//     int i = 0;
//
//     while (i < pos -1) {
//         p = p->next;
//         i++;
//         if (p == nullptr) {
//             return 0;
//         }
//     }
//
//     if (p -> next == nullptr) {
//         printf("删除位置不合法");
//         return 0;
//     }
//
//     Node* q = p->next;
//     p->next = q->next;
//     free(q);
//     return 1;
// }
//
// //查找到链表中倒数第K个位置上的结点
//
// int findNodeFS(Node *L,int k) {
//     Node* fast = L->next;
//     Node* slow = L->next;
//
//     for (int i = 0; i < k; i++) {
//         fast = fast->next;
//     }
//     while (fast != nullptr) {
//         fast = fast->next;
//         slow = slow->next;
//     }
//     printf("倒数第%d个位置上的结点为%d\n",k,slow->data);
//     return 1;
// }
//
// //删除绝对值相同的节点
//
// void removeNode(Node *L,int n) { //n是链表结点数且保存的最大整数<=n
//     Node* p = L;
//     int *q = static_cast<int*>(malloc(sizeof(int)*(n - 1)));
//         for (int i = 0; i < n-1;i++) {
//             *(q+i) = 0;
//         }//建立数组，并初始化为0
//     int index = 0;
//     while (p -> next != nullptr) {
//         index = abs(p -> next -> data);
//         if (*(q+index) == 0) {
//             *(q+index) = 1; //如果数组中的元素为0，说明该绝对值没有出现过，那么该绝对值对应的下标的值就设为1
//             p = p -> next;
//         }
//         else { //如果数组中的元素不为0，说明该绝对值已经出现过，那么按照要求要删掉节点释放内存
//             Node *temp = p->next;
//             p->next = temp->next;
//             free(temp);
//         }
//     }
//     free(q);
// }
//
// //反转链表
//
// Node* reverseList(Node *head) {
//     Node* first = nullptr;
//     Node* second = head->next;
//     Node* third = nullptr;
//
//     while (second != nullptr) {
//         third = second -> next;
//         second -> next = first;
//         first = second;
//         second = third;
//     }
//
//     Node *hd = initList();
//     hd->next = first;
//
//     return hd;
// }
//
// //删除链表中间节点
// int delMidNode(Node *head) {
//     if (head == nullptr || head -> next == nullptr)
//         return 0;
//     Node *fast = head -> next;
//     Node *slow = head;
//
//     while (fast != nullptr && fast -> next != nullptr) {
//         fast = fast -> next -> next;
//         slow = slow -> next;
//     }
//     Node *q = slow -> next;
//     slow -> next = q -> next;
//     free(q);
//     return 1;
// }
//
// //反转交叉链表
// void reOrederList(Node *head) {
//     if (head == nullptr || head -> next == nullptr)
//         return;
//     Node *fast = head -> next;
//     Node *slow = head;
//
//     while (fast != nullptr && fast -> next != nullptr) {
//         fast = fast -> next -> next;
//         slow = slow -> next;
//     }
//     Node *first = nullptr;
//     Node *second = slow -> next;
//     slow -> next = nullptr;
//     Node *third = nullptr;
//
//     while (second != nullptr) {
//         third = second -> next;
//         second -> next = first;
//         first = second;
//         second = third;
//     }
//
//     Node *p1 = head->next;
//     Node *q1 = first;
//     Node *p2 = nullptr,*q2 = nullptr;
//
//     while (p1 != nullptr && q1 != nullptr) {
//         p2 = p1 ->next;
//         q2 = q1 -> next;
//
//         p1 -> next = q1;
//         q1 -> next = p2;
//
//         p1 = p2;
//         q1 = q2;
//     }
//
// }
//
// //判断是否为单向循环链表
// int isCycle(Node *head) {
//     Node *fast = head;
//     Node *slow = head;
//
//     while (fast != nullptr &&  fast -> next != nullptr) {
//         fast = fast -> next -> next;
//         slow = slow -> next;
//         if (fast == slow)
//         {return 1;}
//     }
//     return 0;
// }
//
// //找单向循环链表的入口
// Node* findBegin(Node *head) {
//     Node* fast = head;
//     Node* slow = head;
//
//     while (fast != nullptr && fast -> next != nullptr) {
//         fast = fast -> next -> next;
//         slow = slow -> next;
//         if (fast == slow) {
//             Node *p = fast;
//             int count = 1;
//             while (p->next != slow) {
//                 count++;
//                 p = p->next;
//             }
//             fast = head;
//             slow = head;
//             for (int i = 0; i < count; i++) {
//                 fast = fast->next;
//             }
//             while (fast != slow) {
//                 fast = fast->next;
//                 slow = slow->next;
//             }
//             return slow;
//         }
//     }
//     return nullptr;
// }
//
// //双向链表初始化
// typedef struct both_node {
//     ElemType data;
//     struct both_node *next;//后继
//     struct both_node *pre;//前驱
// }BothNode;
//
// //双向链表头插法
//
// int BothInsertHead(BothNode *L,ElemType e) {
//     BothNode *p = new  BothNode;
//     p->data = e;
//     p->next = L->next;
//     p->pre = L;
//     if (L->next != nullptr) {
//         L->next->pre = p;
//     }
//     L->next = p;
//     return 1;
// }


//----------------------------------------以下是顺序表-------------------------------------




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
// //尾部添加
//
// int append(SeqList *L,ElemType e) {
//     //先判断顺序表是否已经满了
//     if (L->length == MAXSIZE) {
//         printf("顺序表已经满了。无法添加");
//         return 0;
//     }
//     L->data[L->length] = e;
//     L->length++;
//     return 1;
// }
//
// //顺序表的遍历
// void listElem(SeqList *L) {
//     for (int i = 0; i < L->length;i++) {
//         printf("%d ",L->data[i]);
//     }
//     printf("\n");
// }
//
// //顺序表的插入
//
// int insert(SeqList *L,int pos,ElemType e) {
//     //检查插入位置是否合法
//     if (pos <= L->length && pos >= 0) {
//         for (int i = L->length-1;i >= pos - 1;i--) {
//             L->data[i+1] = L->data[i]; // 将pos-1位置以及以后的元素都往后移动一位
//         }
//         L->data[pos - 1] = e;
//         L->length++;
//         return 1;
//     }
//     else {
//         printf("插入位置不合法");
//         return 0;
//     }
// }
//
// //顺序表的删除
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
//     printf("初始化成功，当前顺序表长度为%d\n",List.length);
//     printf("目前占据内存为：%zu\n",sizeof(List.data));
//     return 0;
// }


