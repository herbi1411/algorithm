#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 801
#define LOOPNUM 3
#define INF 0x7FFFFFFF
using namespace std;
vector<pair<int, int>>path[MAX];
int dist[LOOPNUM][MAX];
priority_queue<pair<int, int>>pq;

int main(void) {
	int N, E;
	int a, b, c;
	int v, w;
	int loopInit[LOOPNUM];
	int rt = INF;

	loopInit[0] = 1;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a].push_back(make_pair(b, c));
		path[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i < LOOPNUM; i++) {
		scanf("%d", &loopInit[i]);
	}
	for (int i = 0; i < LOOPNUM; i++){
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;
		dist[i][loopInit[i]] = 0;

		pq.push(make_pair(0,loopInit[i]));
		while (!pq.empty()) {
			int cur = pq.top().second;
			int ccost = -pq.top().first;
			
			pq.pop();
			for (int j = 0; j < path[cur].size(); j++) {
				int nCur = path[cur][j].first;
				int nCost = path[cur][j].second + ccost;

				if (dist[i][nCur] > nCost) {
					dist[i][nCur] = nCost;
					pq.push(make_pair(-nCost,nCur));
				}
			}
		}
	}
	//2°³
	v = loopInit[1];
	w = loopInit[2];

	if (dist[0][v] != INF && dist[1][w] != INF && dist[2][N] != INF)
		rt = min(rt, dist[0][v] + dist[1][w] + dist[2][N]);
	if (dist[0][w] != INF && dist[2][v] != INF && dist[1][N] != INF)
		rt = min(rt, dist[0][w] + dist[2][v] + dist[1][N]);
	
	if (rt == INF)
		printf("-1\n");
	else
		printf("%d\n", rt);
}