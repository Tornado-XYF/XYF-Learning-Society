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
   char const *campus[] = {
         "西大门",
         "厨房",
         "图书馆",
         "操场",
         "教学楼A",
         "教学楼B",
         "教学楼C",
         "宿舍7",
         "宿舍8",
   };


   for(int i = 1; i < G.vertex_num; i++)
   {
      printf("西大门 -> %s : %d\n",campus[i],distance[i]);

      int j = i;
      printf(" 路径是：西大门 ->");
      int total = sizeof(campus) / sizeof(campus[0]);  // 计算数组长度
      const char *temp;  // 临时指针

      // 倒序交换指针
      for (int x = 0; x < total / 2; x++) {
         temp = campus[x];
         campus[x] = campus[total - 1 - x];
         campus[total - 1 - x] = temp;
      }

      while (path[j] != -1) {
         printf("%s ->", campus[j]);
         j = path[j];
      }
      for (int x = 0; x < total / 2; x++) {
         temp = campus[x];
         campus[x] = campus[total - 1 - x];
         campus[total - 1 - x] = temp;
      }
      printf("%s\n",campus[i]);
   }
}

int main(void) {
   Mat_Graph G;
   createGraph(&G);
   int begin = 0;
   dijkstra(G,begin);
   return 0;
}