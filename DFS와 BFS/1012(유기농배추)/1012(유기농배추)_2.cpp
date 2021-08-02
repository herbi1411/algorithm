#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 50

using namespace std;

bool matrix[MAX][MAX];
bool visit[MAX][MAX];
int M, N;
int counter = 0;

void DFS(int w, int h) {
	if (visit[w][h] == true || matrix[w][h] == false)
		return;
	visit[w][h] = true;

	if (w > 0)
		DFS(w - 1, h);
	if (h > 0)
		DFS(w, h - 1);
	if (w < N - 1)
		DFS(w + 1, h);
	if (h < M - 1)
		DFS(w, h + 1);
}

int main(void) {
	int T;
	int K;
	int a, b;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &M, &N, &K);

		memset(visit, 0, MAX*MAX);
		memset(matrix, 0, MAX*MAX);

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			matrix[b][a] = true;
		}


		counter = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visit[i][j] == false && matrix[i][j] == true)
				{
					DFS(i, j);
					counter++;
				}
			}
		}
		printf("%d\n", counter);
	}
}