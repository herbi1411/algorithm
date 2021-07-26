#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAX 50

using namespace std;

char matrix[MAX][MAX];
char visit[MAX][MAX];
int counter = 0;
int width;
int height;


void DFS(int x, int y) {
	if (matrix[x][y] == 0 || visit[x][y] == 1)
		return;
	visit[x][y] = 1;

	if (x > 1)
		DFS(x - 1, y);
	if (y > 1)
		DFS(x, y - 1);
	if (x < height - 1)
		DFS(x + 1, y);
	if (y < width - 1)
		DFS(x, y + 1);
}

int main(void) {
	int N;
	int cnum;
	int x, y;
	int* rt;
	scanf("%d", &N);
	rt = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		counter = 0;
		memset(matrix, 0, MAX * MAX);
		memset(visit, 0, MAX * MAX);

		scanf("%d %d %d", &width, &height, &cnum);
		for (int j = 0; j < cnum; j++) {
			scanf("%d %d", &x, &y);
			matrix[y][x] = 1;
		}
		for(int j=0; j<height; j++)
			for (int k = 0; k < width; k++) {
				if (matrix[j][k] == 1 && visit[j][k] == 0) {
					DFS(j, k);
					counter += 1;
				}		
			}
		rt[i] = counter;
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", rt[i]);
	free(rt);
}