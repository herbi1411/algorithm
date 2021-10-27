#include <cstdio>
#include <vector>
//#include <cstring>
#include <queue>

#define CMAX 1001
#define INF 0x7FFFFFFF
using namespace std;

vector<pair<int, int>> path[CMAX]; //destination,cost
int dp[CMAX];
int parent[CMAX] = { 0 };


int main(void) {
	int N, m;
	int a, b, c;
	int st, ed;
	int temp;
	priority_queue<pair<int,int>> q;
	vector<int> route;
	scanf("%d", &N);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &st, &ed);
	q.push(make_pair(0, st));

	//memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++)dp[i] = INF;
	dp[st] = 0;

	while (!q.empty()) {
		int cur = q.top().second;
		int curCost = -q.top().first;
		q.pop();

		if (curCost > dp[cur]) continue;

		for (int i = 0; i < path[cur].size(); i++) {
			int next = path[cur][i].first;
			int nCost = path[cur][i].second + curCost;

			if (dp[next] > nCost) {
				q.push(make_pair(-nCost, next));
				dp[next] = nCost;
				parent[next] = cur;
			}
		}
	}

	printf("%d\n", dp[ed]);

	temp = ed;
	while (temp > 0) {
		route.push_back(temp);
		temp = parent[temp];
	}

	printf("%d\n", route.size());
	for (int i = route.size() - 1; i >= 0; i--) printf("%d ", route[i]);
	printf("\n");
}