#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define MAXN 32001
using namespace std;

int todo[MAXN] = { 0 };
vector<int> edge[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	int a, b;
	queue<int> q;
	vector<int> result;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		todo[b]++;
		edge[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		if (todo[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		result.push_back(cur);

		for (int v : edge[cur]) {
			todo[v]--;
			if (todo[v] == 0)
				q.push(v);
		}
	}
	
	for (int v : result)
		cout << v << " ";
	cout << endl;
}