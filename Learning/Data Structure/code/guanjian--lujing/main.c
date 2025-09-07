#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef int V;
typedef int E;
#define MAXSIZE 100

typedef struct {
    V vertex[MAXSIZE]; //点
    E arc[MAXSIZE][MAXSIZE]; //边
    int vertex_num; //
    int edge_num; //
}Mat_Graph; //定义邻接矩阵

typedef struct EdgeNode{
    int edge_vex; //顶点的下标
    int weight; //权重
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode {
    int in; //入度
    V data; //顶点的下标V1 V2...
    EdgeNode* head; //下一个结点地址
}VertexNode; //将每个顶点设置为结点

typedef VertexNode Adj_List[MAXSIZE];//adjacency毗邻 邻接  为每个顶点创建数组

typedef struct {
    Adj_List adj_list; //邻接表
    int vertex_num;
    int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

int top = -1;
int stack[MAXSIZE]; //并非标准的栈

void push(int e) {
    if (top > MAXSIZE) {
        printf("满了\n");
        return;
    }

    top++;
    stack[top] = e;
}

int pop() {
    if (top == -1) {
        printf("空\n");
        return 0;
    }

    int elem = stack[top];
    top--;
    return elem;
}

int is_empty() {
    if (top == -1) {
        return 0;
    }
    else {
        return 1;
    }
}

//绘制邻接矩阵
void create_graph(Mat_Graph* G) {
   //定义边和顶点的数量
    G->vertex_num = 10;
    G->edge_num = 13;

    for (int i = 0; i < G->vertex_num; i++) {
        G->vertex[i] = i; //给顶点下标赋值
    }
    //每个边初始化为0
    for (int i = 0; i < G->vertex_num;i++) {
        for (int j = 0; j < G->vertex_num; j++)
        {
            if (i == j) {
                G->arc[i][j] = 0 ; //邻接矩阵对角线为0
            }
            else
            G->arc[i][j] = MAXSIZE;
        }
    }
//给
    G->arc[0][1] = 3;
    G->arc[0][2] = 4;
    G->arc[1][3] = 5;
    G->arc[1][4] = 6;
    G->arc[2][3] = 8;
    G->arc[2][5] = 7;
    G->arc[3][4] = 3;
    G->arc[4][6] = 9;
    G->arc[4][7] = 4;
    G->arc[5][7] = 6;
    G->arc[6][9] = 2;
    G->arc[7][8] = 5;
    G->arc[8][9] = 3;


}

//将邻接矩阵转换为邻接表
void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG) {
    EdgeNode *e;

    *ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
    (*ALG)->vertex_num = G.vertex_num;
    (*ALG)->edge_num = G.edge_num;

    //初始化每个顶点
    for (int i = 0; i < G.vertex_num; i++) {
        (*ALG)->adj_list[i].in = 0;   //入度初始化为0
        (*ALG)->adj_list[i].data = G.vertex[i];//将每个结点的值对应顶点的下标
        (*ALG)->adj_list[i].head = NULL;
    }

    for (int i = 0; i<G.vertex_num; i++) {
        for (int j = 0; j < G.vertex_num; j++)
            {
            if (G.arc[i][j] != 0 && G.arc[i][j]<MAXSIZE) //当两个点之间有连接时
                {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->edge_vex = j;
                e->weight = G.arc[i][j];
                e->next = (*ALG)->adj_list[i].head;
                (*ALG)->adj_list[i].head = e;
                (*ALG)->adj_list[j].in++;
            }
        }
    }
}

//关键路径计算
void critical_path(Adj_List_Graph ALG) {
    EdgeNode *e;
    int top = -1;
    int top2 = -1;
    int stack[MAXSIZE];
    int stack2[MAXSIZE];
    int etv[MAXSIZE];
    int ltv[MAXSIZE];
    int curr;
    int k;
    for (int i = 0; i < ALG->vertex_num; i++) {
        if (ALG->adj_list[i].in == 0) {
            top++;
            stack[top] = i;
        }
    }

    for (int i = 0; i < ALG->vertex_num; i++ ) {
        etv[i] = 0;
    }

    while (top != -1) {
        curr = stack[top];
        top--;
        printf("V%d -> ",ALG->adj_list[curr].data);

        top2++;
        stack2[top2] = curr;

        e = ALG->adj_list[curr].head;

        while (e != NULL) {
            k = e->edge_vex;
            ALG->adj_list[k].in--;
            if (ALG->adj_list[k].in == 0) {
                top++;
                stack[top] = k;
            }

            if (etv[curr] + e->weight > etv[k]) {
                etv[k] = etv[curr] + e->weight;
            }

            e = e->next;
        }
    }
    printf("End\n");

    printf("etv: ");
    for (int i = 0; i < ALG->vertex_num;i++) {
        printf("%d -> ",etv[i]);

    }
    printf("End\n");

    for (int i = 0; i < ALG->vertex_num; i++) {
        ltv[i] = etv[ALG->vertex_num - 1];
    }
    while (top2 != -1) {
        curr = stack2[top2];
        top2--;

        e = ALG->adj_list[curr].head;
        while (e != NULL) {
          k = e->edge_vex;
            if (ltv[k] - e->weight < ltv[curr]) {
                ltv[curr] = ltv[k] - e->weight;
            }
            e = e->next;
        }
    }

    printf("ltv: ");
    for (int i = 0; i < ALG->vertex_num; i++) {
        printf("%d -> ",ltv[i]);
    }
    printf("End\n");
   for (int i = 0; i < ALG ->vertex_num; i++) {
       if (etv[i] == ltv[i] ) {
           printf("V%d -> ",i);
       }
   }
}



void topological_sort(Adj_List_Graph ALG) {
    EdgeNode* e;
    int curr;
    int k;

    for(int i = 0; i < ALG->vertex_num; i++) {
        if (ALG->adj_list[i].in == 0) { //入度为0则入栈
            push(i);
        }
    }
    while (is_empty() != 0) {
        curr = pop();
        printf("V%d -> ",ALG->adj_list[curr].data);
        e = ALG->adj_list[curr].head;

        while (e != NULL) {
            k = e->edge_vex;
            ALG->adj_list[k].in--;
            if (ALG->adj_list[k].in == 0) {
                push(k);
            }
            e = e->next;
        }
    }
}

int main(void) {
    Mat_Graph G;
    Adj_List_Graph ALG;
    create_graph(&G);
    create_adj_graph(G,&ALG);
    critical_path(ALG);
    return 0;
}