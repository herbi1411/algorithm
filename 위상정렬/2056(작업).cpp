#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;


int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> *path;
	int *linked;
	int *time;
	int *actime;
	int a, b, c;
	queue<int> q;

	cin >> N;
	path = new vector<int>[N + 1];
	linked = new int[N + 1];
	time = new int[N + 1];
	actime = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		time[i] = a;
		linked[i] = b;
		actime[i] = 0;
		for (int j = 0; j < b; j++) {
			cin >> c;
			path[c].push_back(i);
		}
		if (b == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
	
		actime[cur] += time[cur];
		for (int v : path[cur]) {
			linked[v]--;
			if (linked[v] == 0)
				q.push(v);
			actime[v] = actime[v] > actime[cur] ? actime[v] : actime[cur];
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = ans > actime[i] ? ans : actime[i];

	cout << ans << endl;

	delete[] linked;
	delete[] path;
	delete[] time;
	delete[] actime;
}