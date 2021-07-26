#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 501
using namespace std;

int N, M;
vector<pair<int, int>> path[MAX];
int dist[MAX];
priority_queue<pair<int, int>> pq;

int main(void) {
	int a, b, c;
	bool flag = false;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i <= N; i++)
		dist[i] = 0x7FFFFFFF;

	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int pathCost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < path[cur].size(); i++) {
			int nCur = path[cur][i].first;
			int nCost = path[cur][i].second + pathCost;
			if (nCost < dist[nCur]) {
				if(dist[nCur] < 0)
				pq.push(make_pair(-nCost,nCur));
				dist[nCur] = nCost;
			}
		}
	}



}