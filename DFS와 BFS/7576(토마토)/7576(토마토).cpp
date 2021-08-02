#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 1000
using namespace std;
int M, N;
char visit[MAX][MAX];
queue <pair<pair<int, int>, int>> q;
int tnum = 0;


int main(void) {
	int rt = -1;
	scanf("%d %d", &M, &N);
	tnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = 0;
			scanf("%d", &a);
			switch (a) {
			case 1:
				q.push(make_pair(make_pair(i, j), 0));
			case 0:
				tnum += 1;
				visit[i][j] = 0;
				break;
			case -1:
				visit[i][j] = 1;
				break;
			default:
				return -1;
			}
		}
	}
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int curc = q.front().second;

		q.pop();
		if (visit[curx][cury] == 0) {
			visit[curx][cury] = 1;
			tnum--;
			if (tnum == 0) {
				rt = curc;
				break;
			}
			if (curx > 0)
				q.push(make_pair(make_pair(curx - 1, cury), curc + 1));
			if (cury > 0)
				q.push(make_pair(make_pair(curx, cury - 1), curc + 1));
			if (curx < N-1)
				q.push(make_pair(make_pair(curx + 1, cury), curc + 1));
			if (cury < M-1)
				q.push(make_pair(make_pair(curx, cury + 1), curc + 1));
		}
	}

	printf("%d\n", rt);
}