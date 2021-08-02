#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define GCOST 10001
#define INF 0x7FFFFFFF
using namespace std;

int dp[MAX][GCOST];
vector<pair<int, pair<int, int>>> path[MAX]; //위치, (시간,비용);
priority_queue<pair<pair<int, int>,int>> pq;  //(시간,비용),위치

void dijkstra(int s) {

}

int main(void) {
	int T;
	int N, M, K;
	int u, v, c, d;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < GCOST; k++)
				dp[j][k] = INF;
			path[j].clear();
		}
		for (int j = 0; j < K; j++) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			path[u].push_back(make_pair(v, make_pair(d, c)));
		}
		dp[1][0] = 0;
		dijkstra(1);
		pq.push(make_pair(make_pair(0, 0), 1));
		while (!pq.empty()) {
			int cur = pq.top().second;
			int ctime = -pq.top().first.first;
			int ccost = pq.top().first.second;
			pq.pop();

			for (int j = 0; j < path[cur].size(); j++) {
				int nCur = path[cur][j].first;
				int nTime = path[cur][j].second.first + ctime;
				int nCost = path[cur][j].second.second + ccost;
				if (nCost <= M && dp[nCur][nCost] > nTime) {
					dp[nCur][nCost] = nTime;
					pq.push(make_pair(make_pair(-nTime, nCost), nCur));
					for (int k = nCost; k <= M; k++) {
						if (dp[nCur][k] < dp[nCur][nCost])
							break;
						else
							dp[nCur][k] = nTime;
					}
				}
			}
		}

		if (dp[N][M] == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", dp[N][M]);
	}
}
