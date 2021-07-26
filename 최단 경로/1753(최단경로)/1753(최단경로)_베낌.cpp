///∫£≥¶
//√‚√≥: https://yabmoons.tistory.com/376
#include <cstdio>
#include <queue>
#include <climits>
#define MAX 20010
using namespace std;

int V, E, S;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

int main(void) {
	int u, v, w;
	priority_queue<pair<int, int>> PQ;
	scanf("%d %d %d", &V, &E, &S);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		Vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++)Dist[i] = INT_MAX;

	PQ.push(make_pair(0, S));
	Dist[S] = 0;

	while (PQ.empty() == 0) {
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Vertex[cur].size(); i++) {
			int next = Vertex[cur][i].first;
			int nCost = Vertex[cur][i].second;

			if (Dist[next] > cost + nCost) {
				Dist[next] = cost + nCost;
				PQ.push(make_pair(-Dist[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (Dist[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", Dist[i]);
	}
}

