#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 501
using namespace std;

int N, M;
vector<pair<int, pair<int,int>>> path;
long long dist[MAX];

int main(void) {
	int a, b, c;
	bool flag = false;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 0; i <= N; i++)
		dist[i] = 0x7FFFFFFF;

	dist[1] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < path.size(); j++) {
			int cur = path[j].second.first;
			int next = path[j].second.second;
			int cost = path[j].first;

			if (dist[cur] != 0x7FFFFFFF) {
				if (dist[next] > dist[cur] + cost) {
					if (i == N - 1)
						flag = true;
					else
						dist[next] = dist[cur] + cost;
				}
			}
		}
	}

	if (flag)
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == 0x7FFFFFFF)
				printf("-1\n");
			else
				printf("%lld\n", dist[i]);
		}
	}
}