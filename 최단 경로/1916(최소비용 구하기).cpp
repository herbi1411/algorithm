#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <tuple>
#define MAXN 1001
#define endl '\n'
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int S, E;
	int ans;
	bool visited[MAXN] = { 0 };
	vector<pair<int, int>> v[MAXN];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int s, e, c;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> s >> e >> c;
		v[s].push_back(make_pair(e, c));
	}


	cin >> S >> E;
	pq.push(make_pair(0, S));

	while (!pq.empty()) {
		int cost, cur;

		tie(cost, cur) = pq.top();
		pq.pop();
		if (cur == E) {
			ans = cost;
			break;
		}
		if (visited[cur])
			continue;
		visited[cur] = true;

		for (int i = 0; i < v[cur].size(); i++) {
			int ncost, next;
			tie(next, ncost) = v[cur][i];
			ncost += cost;
			
			if (!visited[next])
				pq.push(make_pair(ncost, next));
		}
	}

	cout << ans << endl;
}