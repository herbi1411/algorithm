#include <iostream>
#define maxN 1002
#include <vector>
#define endl '\n'
using namespace std;


int traversal(int now, vector<int>node[]) {
	int rt = 0;

	for (auto next : node[now]) {
		rt += traversal(next, node);
	}
	return rt + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {

		int E, N;
		int p, c;
		vector<int> node[maxN];
		int cnt = 0;

		cin >> E >> N;
		for (int k = 0; k < E; k++) {
			cin >> p >> c;
			node[p].push_back(c);
		}

		cnt = traversal(N, node);
		cout << "#" << t << " " << cnt << endl;
	}
}