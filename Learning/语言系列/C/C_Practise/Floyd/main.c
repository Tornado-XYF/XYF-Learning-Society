#include <stdio.h>

typedef int V;
typedef int E;

#define MAXSIZE 100
#define MAXEDGE 100
#define MAX 0x10000

typedef struct
{
    V vertex[MAXSIZE]; //定义点数
    E arc[MAXSIZE][MAXSIZE]; //定义邻接矩阵
    int vertex_num;
    int edge_num;
}Mat_Graph;

void createGraph(Mat_Graph* G)
{
    G->vertex_num = 9; //点的最大数
    G->edge_num = 16;  //边的最大数

    for (int i = 0;i < G->vertex_num; i++)
    {
        G->vertex[i] = "食堂"; //定义下角标
    }
    for(int i = 0;i < G->vertex_num; i++)
    {
        for(int j = 0; j < G->vertex_num; j++)
        {
            if(i == j)
            {
                G->arc[i][j] = 0;   //初始化二维矩阵
            }
            else
            {
                G->arc[i][j] = MAX;   //初始化邻接矩阵
            }
        }
    }
    G->arc[0][1] = 1;
    G->arc[0][2] = 5;

    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;

    G->arc[3][4] = 2;
    G->arc[3][6] = 3;

    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;

    G->arc[5][7] = 5;

    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4; //赋值

    for(int i = 0; i< G->vertex_num; i++)
    {
        for (int j = i; j< G->vertex_num;j++)
        {
            G->arc[j][i] = G->arc[i][j]; //使邻接矩阵对称
        }
    }
}

void floyd(Mat_Graph G)
{
    int path [MAXSIZE][MAXSIZE];
    int distance[MAXSIZE][MAXSIZE];

    for(int i = 0 ;i < G.vertex_num; i++)
    {
       for(int j = 0; j < G.vertex_num; j++)
       {
          distance[i][j] = G.arc[i][j];
           path[i][j] = j;
       }
    }

    for(int i = 0; i < G.vertex_num; i++)
    {
       for(int j = 0; j < G.vertex_num; j++)
       {
           for(int k = 0; k < G.vertex_num; k++)
           {
              if (distance[j][k] > distance[j][i] + distance[i][k])
              {
                  distance[j][k] = distance[j][i] + distance[i][k];
                  path[j][k] = path[j][i];
              }
           }
       }
    }

    int k;
    for(int i = 0; i < G.vertex_num; i++)
    {
       for(int j = i + 1; j < G.vertex_num; j++)
       {
          printf("V%d -> V%d 权重: %d",i,j,distance[i][j]);
           k = path[i][j];
           printf(" path:V%d",k);
           while(k != j)
           {
             printf("->V%d",k);
               k = path[k][j];
           }
           printf("->V%d\n",j);
       }
        printf("\n");
    }
}

int main(void) {
    Mat_Graph G;
    createGraph(&G);
    floyd(G);

    return 0;
}