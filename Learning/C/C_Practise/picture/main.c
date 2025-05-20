#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct
{
   VertexType vertex[MAXSIZE];
   EdgeType arc[MAXSIZE][MAXSIZE];
   int vertex_num;
   int edge_num;
}Mat_Grph;

