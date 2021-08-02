#include <cstdio>
#include <queue>
#define MAX 100001
#define INF 0x7FFFFFFF
using namespace std;

int matrix[MAX];
queue<pair<int,int>> q;
int N, K;

int main(void) {
	int rt = -1;
	scanf("%d %d", &N, &K);
	q.push(make_pair(N,0));

	for (int i = 0; i < MAX; i++)
		matrix[i] = INF;
	while (!q.empty()) {
		int cur = q.front().first;
		int curCost = q.front().second;
		q.pop();

		if (cur == K) {
			rt = curCost;
			break;
		}
		if (matrix[cur] > curCost) {
			matrix[cur] = curCost;
			
			//3¹ø
			if (cur > 0)
				q.push(make_pair(cur - 1, curCost + 1));
			if (cur < MAX - 1)
				q.push(make_pair(cur + 1, curCost + 1));
			if (cur * 2 < MAX)
				q.push(make_pair(cur * 2, curCost + 1));
		}
	}

	printf("%d\n", rt);
}