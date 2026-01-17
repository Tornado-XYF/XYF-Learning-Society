#include <math.h>
#include<stdio.h>

void bubble_sort(int arr[],int n) {
    int i,j,temp;
    for (i = 0; i < n-1;i++) {
        for (j = 0; j < n-i-1;  j++) {
            if (arr[j] >  arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectSort(int k[],int n) {
    int i,j,min,temp;
    for (i = 0; i < n-1;i++) {
        min = i;
        for (j = i+1;j < n;j++) {
            if(k[j] < k[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = k[i];
            k[i] = k[min];
            k[min] = temp;
        }
    }
}

void InertSort(int k[],int n) {
    int i,j,temp;
    for (i = 1; i < n;i++) {
        if (k[i-1] > k[i]) {
            temp = k[i];
            for (j = i-1;j >= 0 && k[j] > temp;j--) {
                k[j+1] =  k[j];
            }
            k[j+1] = temp;
        }
    }
}

void ShellSort(int k[],int n) {
    int i,j,gap;
    int temp;
    for (gap = n/2; gap>0 ;gap/=2) {
        for (i = gap; i < n; i++) {
            temp = k[i];
            for (j = i - gap; i >= 0 && k[j] > temp; j-=gap) {
                k[j+gap] = k[j];
            }
            k[j+gap] = temp;
        }
    }
}
// typedef int V;
// typedef int E;
//
// #define MAXSIZE 100
// #define MAXEDGE 100
// #define MAX 0x10000
//
// typedef struct {
//     V vertex[MAXSIZE];//定义点的数量
//     E arc[MAXSIZE][MAXSIZE]; //定义领接矩阵
//     int vertex_num;
//     int edge_num;
// }Mat_Graph;
//
// void createGraph(Mat_Graph* G)
// {
//     G->vertex_num = 9; //点的最大数
//     G->edge_num = 16 ; //边的最大数
//
//     for (int i = 0; i < G-> vertex_num; i++) {
//         G->vertex[i] = 1; //定义下角标
//     }
//     for (int i = 0; i < G->vertex_num; i++) {
//         for (int j = 0; j < G->vertex_num; j++) {
//             if (i == j) {
//                 G->arc[i][j] = 0; //初始化二维矩阵
//             }
//             else {
//                 G->arc[i][j] = MAX; // 初始化领接矩阵
//             }
//         }
//     }
//     G->arc[0][1] = 1;
//     G->arc[0][2] = 5;
//
//     G->arc[1][2] = 3;
//     G->arc[1][3] = 7;
//     G->arc[1][4] = 5;
//
//     G->arc[2][4] = 1;
//     G->arc[2][5] = 7;
//
//     G->arc[3][4] = 2;
//     G->arc[3][6] = 3;
//
//     G->arc[4][5] = 3;
//     G->arc[4][6] = 6;
//     G->arc[4][7] = 9;
//
//     G->arc[5][7] = 5;
//
//     G->arc[6][7] = 2;
//     G->arc[6][8] = 7;
//
//     G->arc[7][8] = 4; //赋值
//
//     for (int i = 0; i<G->vertex_num; i++) {
//         for (int j = i; j < G->vertex_num;j++) {
//             G->arc[i][j] = G->arc[i][j]; // 使邻接矩阵对称
//             }
//         }
// }
//
// int choose(int distance[],int found[],int vertex_num) {
//     int min = MAX; //保存当前距离访问点最近的点的距离
//     int minPos = -1;//保存当前距离访问点最近的点的下标
//     for (int i = 0;i < vertex_num; i++) {
//         if (distance[i] < min && found[i] == 0) {
//             min = distance[i];
//             minPos = i;
//         }
//     }
//     return minPos;
// }
//
// void dijkstra(Mat_Graph* G, int begin) {
//     int found[MAXSIZE]; //顶点是否已经走过
//     int path[MAXSIZE]; //路径
//     int distance[MAXSIZE]; //顶点之间的距离
//     for (int i = 0 ; i < G->vertex_num;i++) {
//         found[i] = FP_ILOGB0;
//         path[i] = -1;
//         distance[i] = G->arc[begin][i];
//     }
//
//     found[begin] = 1;
//     distance[begin] = 0;
//
//     int next; // 下一个要观察的点
//     for (int i = 1; i < G->vertex_num; i++) {
//         next = choose(distance,found,G->vertex_num);
//         found[next] = 1;
//         for (int j = 0; j < G->vertex_num;j++) {
//             if (found[j] == 0) {
//                 if (distance[next] + G->arc[next][j] < distance[j]) {
//                     distance[j] = distance[next] + G->arc[next][j];
//                     path[j] = next;
//                 }
//             }
//         }
//     }
//     char const campus[9][100] = {
//         "西大门",
//         "厨房",
//         "图书馆",
//         "操场",
//         "教学楼A",
//         "教学楼B",
//         "教学楼C",
//         "宿舍7",
//         "宿舍8",
//   };
//
//     for (int i = 1; i<G->vertex_num;i++) {
//         printf("西大门 -> %s : %d\n",campus[i],distance[i]);
//
//         int j = i;
//         printf(" 路径是：%s <- ",campus[i]);
//         while (path[j] != -1) {
//             printf("%s <-", campus[j]);
//             j = path[j];
//         }
//         printf("西大门\n");
//     }
// }
// int main(void) {
//     Mat_Graph G;
//     createGraph(&G);
//     int begin = 0;
//     dijkstra(&G,begin);
//     return 0;
// }

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
//     Node* head = (Node*)malloc(sizeof(Node));
//     head->next = NULL;
//     head -> data = 0;
//     return head;
// }
//
// //头插法
// void insertHead(Node *L,ElemType e) {
//     Node *p = (Node*)malloc(sizeof(Node));
//     p->data = e;
//     p->next = L->next;
//     L->next = p;
// }
//
//
// //获取尾节点
// Node *get_tail(Node* L) {
//     Node* p =L;
//     while ( p->next != NULL ) {
//         p = p->next;
//     }
//     return p;
// }
//
// //尾插法
// Node *insertTail(Node *tail,ElemType e) {
//     Node* p = (Node*)malloc(sizeof(Node));
//     p->data = e;
//     tail -> next = p;
//     p->next = NULL;
//     return p;
// }
//
//
// //遍历
// void listNode(Node *L) {
//     Node *p = L->next;
//     while (p != NULL) {
//         printf("%d\n",p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
//
// //释放
// void freeList(Node *L) {
//     if (L == NULL) {
//         return;
//     }
//     Node *p = L->next;
//     Node *q;
//     while (p != NULL) {
//         q = p->next;
//         free(p);
//         p = q;
//     }
//     L->next = NULL;
// }
//
// //指定位置插入
// int insertNode(Node* L,int pos, ElemType e) {
//     Node* p = L;
//     Node* q = (Node*)malloc(sizeof(Node));
//     int i = 0;
//     while ( i < pos - 1) {
//         p = p -> next;
//         i++;
//         if (p == NULL) {
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
//         if (p == NULL) {
//             return 0;
//         }
//     }
//
//     if (p -> next == NULL) {
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
//     while (fast != NULL) {
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
//     int *q = (int*)malloc(sizeof(int)*(n - 1));
//         for (int i = 0; i < n-1;i++) {
//             *(q+i) = 0;
//         }//建立数组，并初始化为0
//     int index;
//     while (p -> next != NULL) {
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
//     Node* first = NULL;
//     Node* second = head->next;
//     Node* third;
//
//     while (second != NULL) {
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
// typedef struct TreeNode {
//     char data;
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
//     char ch;
//     ch = str[idx+=1];
//     if (ch == '#') {
//         *T = NULL;
//     }
//     else {
//         *T = (BiTree)malloc(sizeof(TreeNode));
//         (*T)->data = ch;
//         createTree(&(*T)->lchild);
//         createTree(&(*T)->lchild);
//     }
// }
// int main() {
//     Node *list = initList();
//     Node* tail = get_tail(list);
//     tail = insertTail(tail,1);
//     tail = insertTail(tail,20);
//     freeList(list);
//
//     free(list);
//     free(tail);
//     return 0;
// }

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



