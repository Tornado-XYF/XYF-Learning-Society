#include <stdio.h>

typedef int V;
typedef int E;

#define MAXSIZE 100
#define MAXEDGE 100
#define MAX 500

typedef struct
{
   V vertex[MAXSIZE]; //定义点数
   E arc[MAXSIZE][MAXSIZE]; //定义邻接矩阵
   int vertex_num;
   int edge_num;
}Mat_Graph;

char const *campus[] = {
   "宿舍7,8",
   "国旗台",
   "花园",
   "教学楼A",
   "教学楼B",
   "教学楼C",
   "校史草地",
   "操场",
   "试验田",
   "食堂",
   "快递站",
   "宿舍1，2",
   "宿舍3，4",
   "宿舍7，8",
   "西大门",

};


void createGraph(Mat_Graph* G)
{
   G->vertex_num = 15; //点的最大数
   G->edge_num = 24;  //边的最大数

    for (int i = 0;i < G->vertex_num; i++)
   {
     G->vertex[i] = i; //定义下角标
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
   G->arc[13][1] = 100;
   G->arc[13][7] = 70;
   G->arc[13][9] = 100;


   G->arc[1][2] = 50;
   G->arc[1][3] = 50;
   G->arc[1][7] = 60;
   G->arc[1][9] = 40;

   G->arc[2][3] = 70;
   G->arc[2][9] = 10;

   G->arc[3][7] = 90;
   G->arc[3][4] = 45;

   G->arc[4][5] = 45;

   G->arc[5][7] = 30;
   G->arc[5][6] = 20;
   G->arc[5][8] = 50;

   G->arc[7][8] = 30; //赋值

   G->arc[9][10] = 50;

   G->arc[10][11] = 80;
   G->arc[10][12] = 80;
   G->arc[10][0] = 100;
   G->arc[10][14] = 100;

   G->arc[11][14] = 80;

   G->arc[12][0] = 80;

   G->arc[0][14] = 100;

   for(int i = 0; i< G->vertex_num; i++)
   {
      for (int j = i; j< G->vertex_num;j++)
      {
         G->arc[j][i] = G->arc[i][j]; //使邻接矩阵对称
      }
   }
}

int choose(int distance[],int found[], int vertex_num)
{
   int min = MAX;
   int minPos = -1;
   for(int i = 0; i < vertex_num; i++)
   {
      if(distance[i] < min && found[i] == 0)  //distance
      {
         min = distance[i];
         minPos = i;
      }
   }
   return minPos;
}


void printPath(int path[], int destination) {
   if (path[destination] == -1) {
      printf("%s", campus[destination]);
      return;
   }
   printPath(path, path[destination]);
   printf(" -> %s", campus[destination]);
}

void dijkstra(Mat_Graph G, int begin) // Dijkstra算法
{
   int found[MAXSIZE]; //顶点是否已走过
   int path[MAXSIZE]; //路径
   int distance[MAXSIZE]; // 顶点之间的距离
   for (int i = 0;i < G.vertex_num; i++)
   {
      found[i] = 0;
      path[i] = -1;
      distance[i] = G.arc[begin][i];
   }

   found[begin] = 1;
   distance[begin] = 0;

   int next; //下一个要观察的点
   for(int i = 1; i < G.vertex_num; i++)
   {
      next = choose(distance, found, G.vertex_num);

      found[next] = 1;
      for(int j = 0; j < G.vertex_num; j++)
      {
         if(found[j] == 0) //若改顶点没有访问过
         {
            if(distance[next] + G.arc[next][j] < distance[j])
            {
                  distance[j] = distance[next] + G.arc[next][j];
               path[j] = next;
            }
         }
      }
   }
   printf("从 %s 出发到各地点最短路径:\n", campus[begin]);
   for(int i = 1; i < G.vertex_num; i++) {
      // printf("%s ",campus[i]);
      printf("%s -> %s: ", campus[begin], campus[i]);

         printf("距离: %d\n", distance[i]);
         printf("  路径: 宿舍7,8 -> ");
         printPath(path, i);
      printf("  \n");
   }
}

int main(void) {
   Mat_Graph G;
   createGraph(&G);
   int begin = 0;
   dijkstra(G,begin);
   return 0;
}