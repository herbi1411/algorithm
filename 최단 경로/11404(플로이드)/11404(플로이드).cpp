#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 101
#define INF 100000000 //1¾ï
using namespace std;

int dist[MAX][MAX];
int N, M;

int main(void) {
	int a, b, c;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (k == i)
				continue;
			else
				for (int j = 1; j <= N; j++) {
					if (i == j || k == j)
						continue;
					else
					{
						dist[i][j] = min(dist[i][j],  dist[i][k] + dist[k][j]);
					}
				}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}