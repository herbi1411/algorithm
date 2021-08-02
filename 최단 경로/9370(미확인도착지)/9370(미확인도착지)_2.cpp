#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2001
#define INF 0x7FFFFFFF
using namespace std;

int main(void) {
	int T;
	int n, m, t;
	int s, g, h;
	int a, b, d;

	int dist[3][MAX];
	int start[3];
	vector<pair<int, int>> path[MAX];
	priority_queue<pair<int, int>> pq;
	int* nom = NULL;
	int* rt = NULL;
	int rtindex = 0;

	scanf("%d",&T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		for (int i = 1; i <= n; i++)
			path[i].clear();

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			path[a].push_back(make_pair(b, d));
			path[b].push_back(make_pair(a, d));
		}

		nom = (int *)malloc(sizeof(int) * t);
		for (int i = 0; i < t; i++) {
			scanf("%d", &nom[i]);
		}

		start[0] = s;
		start[1] = g;
		start[2] = h;

		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = INF;
			}
			dist[i][start[i]] = 0;
			pq.push(make_pair(0, start[i]));
			while (!pq.empty()) {
				int cur = pq.top().second;
				int ccost = -pq.top().first;
				
				pq.pop();
				for (int j = 0; j < path[cur].size(); j++) {
					int nCur = path[cur][j].first;
					int nCost = path[cur][j].second + ccost;

					if (dist[i][nCur] > nCost) {
						dist[i][nCur] = nCost;
						pq.push(make_pair(-nCost, nCur));
					}
				}
			}
		}
		rtindex = 0;
		rt = (int*)malloc(sizeof(int) * t);
		for (int i = 0; i < t; i++) {
			int temp = INF;
			if (dist[0][g] != INF && dist[1][h] != INF && dist[2][nom[i]] != INF)
				temp = min(temp, dist[0][g] + dist[1][h] + dist[2][nom[i]]);
			if (dist[0][h] != INF && dist[2][g] != INF && dist[1][nom[i]] != INF)
				temp = min(temp, dist[0][h] + dist[2][g] + dist[1][nom[i]]);

			if (temp != INF && dist[0][nom[i]] == temp)
				rt[rtindex++] = nom[i];
		}

		sort(rt, rt + rtindex);
		for (int i = 0; i < rtindex; i++) {
			printf("%d ", rt[i]);
		}
		printf("\n");
		free(rt);
		free(nom);
	}
}