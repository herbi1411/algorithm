#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX 20001
using namespace std;
int V, E;
char matrix[MAX][MAX];
char link[MAX];
char target[MAX]; // 시작점에서의 최소거리
char visit[MAX]; //거리 계산할 때 방문? // 각 정점을 검사할 때마다 초기화해야함

void DFS(int s, int cost) { //현재위치 ,누적비용
	if (visit[s] == 1)
		return;
	visit[s] = 1;
	link[s] = 1;
	target[s] = (char) min((int)target[s], cost);
	for (int i = 1; i < V+1; i++) {
		if (matrix[s][i] != 0 && visit[s] == 0) {
			DFS(i, cost + matrix[s][i]);
			visit[i] = 0;
		}
	}
}

int main(void) {
	int S;
	int u, v, w;

	scanf("%d %d", &V, &E);
	scanf("%d", &S);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		matrix[u][v] = w;
	}
	memset(target, 0x7f, MAX);

	for (int i = 1; i < V+1; i++) {
		if (matrix[S][i] != 0) {
			memset(visit, 0, MAX);
			visit[S] = 1;
			DFS(i, matrix[S][i]);
		}
	}

	for (int i = 1; i < V + 1; i++)
	{
		if (link[i] == 0) {
			if (i == S)
			{
				printf("0\n");
			}
			else
				printf("INF\n");
		}
		else
			printf("%d\n", target[i]);
	}
}