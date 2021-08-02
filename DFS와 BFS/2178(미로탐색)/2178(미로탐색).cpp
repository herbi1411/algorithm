#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAX 101

using namespace std;
char matrix[MAX][MAX];
char visit[MAX][MAX];
int N, M;

int DFS(int x, int y) {
	queue<pair<pair<int, int>,int>> q;

	q.push(make_pair(make_pair(x, y), 1));

	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int curc = q.front().second;
		
		if (curx == N && cury == M)
			return curc;
		q.pop();
		if (visit[curx][cury] == false && matrix[curx][cury] == '1') {
			visit[curx][cury] = true;
			if (curx > 1)
				q.push(make_pair(make_pair(curx - 1, cury), curc + 1));
			if (cury > 1)
				q.push(make_pair(make_pair(curx, cury - 1), curc + 1));
			if (curx < N)
				q.push(make_pair(make_pair(curx + 1, cury), curc + 1));
			if (cury < M)
				q.push(make_pair(make_pair(curx, cury + 1), curc + 1));
		}
		
	}
	return -1;
}

int main(void) {
	int a, b, c;
	char* line = NULL;
	scanf("%d %d", &N, &M);
	line = (char*)malloc(sizeof(char) * M+1);
	for (int i = 1; i <= N; i++) {
		scanf("%s", line);
		for (int j = 1; j <= M; j++) {
			matrix[i][j] = line[j-1];
			visit[i][j] = false;
		}
	}
	
	printf("%d\n", DFS(1, 1));
	free(line);
}