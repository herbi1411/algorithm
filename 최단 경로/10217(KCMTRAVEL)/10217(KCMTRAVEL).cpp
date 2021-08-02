#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 0x7FFFFFFF
using namespace std;

int tcost[MAX];
int ttime[MAX];
bool visit[MAX];
vector<pair<int, pair<int,int>>> path[MAX]; //도착지,(시간,비용)
priority_queue<pair<int, pair<int,int>>> pq;  //시간, (위치,비용)
int minTime;
int T;
int N, M, K;

void bubble(int ccost, int ctime, const int cur) {

	if (cur == N)
		minTime = min(minTime, ctime);
	for (int i = 0; i < path[cur].size(); i++) {
		int nCur = path[cur][i].first;
		int ntime = path[cur][i].second.first + ctime;
		int ncost = path[cur][i].second.second + ccost;
		if (ncost <= M && visit[nCur] == false) {
			visit[nCur] = 1;
			bubble(ncost, ntime, nCur);
			visit[nCur] = 0;
		}
	}
}



int main(void) {
	int u, v, c, d;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int j = 0; j < N; j++) {
			tcost[j] = INF;
			ttime[j] = 0;
		}
		for (int j = 0; j < K; j++) {
			scanf("%d %d %d %d",&u,&v,&c,&d);
			path[u].push_back(make_pair(v, make_pair(d, c)));
		}
		minTime = INF;
		bubble(0, 0, 1);
		if (minTime == INF)
			printf("Poor KCM\n");
		else printf("%d\n",minTime);
		for (int j = 0; j < N; j++) {
			path[j].clear();
		}
		//tcost[1] = 0;
		//pq.push(make_pair(0, make_pair(1, 0)));
	}
}
