#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#define endl '\n'
#define maxV 10001
using namespace std;

void union_head(int head[], const int a, const int target) {
	if (head[a] != a) 
		union_head(head, head[a], target);
	head[a] = target;
}

int get_head(int head[], const int a) {
	if (head[a] != a) {
		int rt = get_head(head, head[a]);
		head[a] = rt;
		return rt;
	}

	return a;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	int a, b, c;
	int cnt = 0;
	int ans = 0;
	int head[maxV] = { 0 };
	vector<tuple<int, int, int>> v;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v.push_back(make_tuple(c, a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++)
		head[i] = i;

	for (auto &val : v) {
		tie(c, a, b) = val;
		int ahead = get_head(head, a);
		int bhead = get_head(head, b);

		if (ahead != bhead) {
			if (ahead < bhead)
				union_head(head, bhead, ahead);
			else
				union_head(head, bhead, ahead);
			cnt += 1;
			ans += c;
		}
		if (cnt == V - 1)
			break;
	}
	cout << ans << endl;
}