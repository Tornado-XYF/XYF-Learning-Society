#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define INF INT_MAX

void floyd(vector<vector<int>>& graph)
{
	int V = graph.size();
	vector<vector<int>> dist(V, vector<int>(V));

	for (int i = 0; i < V; i++) {
		for (int j = 0;j < V;j++) {
		dist[i][j] = graph[i][j];
		}
	}//将输入的邻接矩阵复制到dist矩阵中
	//初始时，dist[i][j]直接存储顶点i到j的直接距离（如果没有直接边则为INF）

	for (int k = 0; k < V; k++){					//k外层循环k：考虑将顶点k作为中间节点
		for (int i = 0; i < V; i++) {				//中间循环i：源顶点
			for (int j = 0; j < V; j++) {			//内层循环j：目标顶点
													//外层必须是k，内层先循环i还是j都行

				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {				//条件判断：
					dist[i][j] = dist[i][k] + dist[k][j];															//首先检查i->k和k->j的路径是否存在（不为INF）
																													//然后比较i->j的直接距离和通过k的间接距离i->k->j
				}																									//如果间接距离更短，则更新dist[i][j]
																													//防止整数溢出：在相加前检查是否为INF，避免整数溢出
			}
		}
	}

	//打印最终的最短距离矩阵
	cout << "所有顶点对之间的最短距离矩阵:"<<endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF) {
				cout << "INF\t";
			}
			else {
				cout << dist[i][j] << "\t";        // \t保证对齐
			}
		}
		cout << endl;
	}


}


int main(){
	int V = 31;//一共有多少个点就填几
	//在下面填上初始矩阵
	vector<vector<int>> graph = {

		{ 0, 48, 114, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ 48, 0, 71, 71, 202, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ 114, 71, 0, INF, INF, INF, INF, INF, 150, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, 71, INF, 0, 141, INF, INF, 89, 8, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, 202, INF, 141, 0, 182, 70, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, 182, 0, 177, INF, INF, 60, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, 70, 127, 0, 136, INF, 184, 87, INF, 67, 82, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, 89, INF, INF, 136, 0, 78, INF, INF, INF, INF, 123, 142, 43, 98, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, 150, 8, INF, INF, INF, 78, 0, INF, INF, INF, INF, INF, INF, INF, 130, 78, INF, 153, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, 60, 184, INF, INF, 0, 170, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 248, INF, INF, INF, INF, INF, INF, INF, INF, 75 },
	{ INF, INF, INF, INF, INF, INF, 87, INF, INF, 170, 0, 83, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 83, 0, 47, INF, INF, INF, INF, INF, INF, INF, INF, 194, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, 67, INF, INF, INF, INF, 47, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, 214, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, 82, 123, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, 179, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, 142, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, 138, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, 43, INF, INF, INF, INF, INF, INF, INF, 0, 53, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, 98, 130, INF, INF, INF, INF, INF, INF, 53, 0, INF, INF, INF, INF, INF, INF, INF, 75, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, 150, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 136, 54, INF, INF, INF, INF, 50, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 56, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, 153, INF, INF, INF, INF, INF, INF, INF, INF, 136, 56, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 54, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, 248, INF, 194, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 74, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 214, 179, 138, INF, INF, INF, INF, INF, INF, 74, 0, 147, 181, INF, 183, INF, 198, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 147, 0, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 75, INF, INF, INF, INF, INF, 181, INF, 0, INF, 89, INF, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 50, INF, INF, INF, INF, INF, INF, INF, 0, 7, 90, INF, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 183, INF, 89, 7, 0, 76, 119, INF, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 90, 76, 0, INF, 105, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 198, INF, INF, INF, 119, INF, 0, 90, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 105, 90, 0, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, 75, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0 }

	};

	floyd(graph);

	return 0;
}
