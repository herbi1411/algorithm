#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 0x7FFFFFFF;
using namespace std;

int tcost[MAX];
int ttime[MAX];
vector<pair<int, pair<int, int>>> path[MAX];
priority_queue<pair<int, pair<int, int>>> pq;  //시간, (위치,비용)

int main(void) {
	int T;
	int N, M, K;
	int u, v, c, d;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int j = 0; j < N; j++) {
			tcost[j] = INF;
			ttime[j] = 0;
		}
		for (int j = 0; j < K; j++) {
			scanf("%d %d %d %d", u, v, c, d);
			path[u].push_back(make_pair(v, make_pair(c, d)));
		}

		tcost[1] = 0;
		pq.push(make_pair(0, make_pair(1, 0)));


	}
}
