// #include <math.h>
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
    G->vertex_num = 14;
    G->edge_num = 20;

    for (int i = 0; i < G->vertex_num; i++) {
        G->vertex[i] = i; //给顶点下标赋值
    }
    //每个边初始化为0
    for (int i = 0; i < G->vertex_num;i++) {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[i][j] = 0;
        }
    }
//给
    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][2] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;

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
            if (G.arc[i][j] == 1) //当两个点之间有连接时
                {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->edge_vex = j;
                e->next = (*ALG)->adj_list[i].head;
                (*ALG)->adj_list[i].head = e;
                (*ALG)->adj_list[j].in++;
            }
        }
    }
}

//拓扑排序
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
    topological_sort(ALG);
    return 0;
}