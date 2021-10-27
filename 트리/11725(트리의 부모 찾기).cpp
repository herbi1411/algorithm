#include <cstdio>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;

vector<int> edge[MAX];
queue<int> q;
int parent[MAX] = { 0 };
bool visit[MAX] = { 0 };

int main(void) {
	int N;
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int val = q.front();
		q.pop();

		for (int i = 0; i < edge[val].size(); i++) {
			int val2 = edge[val][i];
			if (visit[val2] == false) {
				visit[val2] = true;
				parent[val2] = val;
				q.push(val2);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
}