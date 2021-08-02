#include <cstdio>
#include <algorithm>
#define MAX 401
#define INF 1e9
using namespace std;

int main(void) {
	int dist[MAX][MAX];
	int V, E;
	int a, b, c;
	int rt = INF;
	scanf("%d %d", &V, &E);
	for(int i=1; i<=V; i++)
		for (int j = 1; j <= V; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			if (i == k)
				continue;
			for (int j = 1; j <= V; j++) {
				if (i == j || j == k)
					continue;
				else
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	for (int i = 1; i < V; i++) {
		for (int j = i+1; j <= V; j++) {
			rt = min(rt, dist[i][j] + dist[j][i]);
		}
	}

	if (rt == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", rt);
	}
}

