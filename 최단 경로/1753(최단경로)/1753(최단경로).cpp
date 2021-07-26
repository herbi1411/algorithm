#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX 20001
using namespace std;
int V, E;
char matrix[MAX][MAX];
char link[MAX];
char target[MAX]; // ������������ �ּҰŸ�
char visit[MAX]; //�Ÿ� ����� �� �湮? // �� ������ �˻��� ������ �ʱ�ȭ�ؾ���

void DFS(int s, int cost) { //������ġ ,�������
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