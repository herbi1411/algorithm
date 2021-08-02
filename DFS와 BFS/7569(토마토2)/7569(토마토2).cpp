#include <cstdio>
#include <queue>
#define MAX 100
using namespace std;

typedef struct ZYX {
	int z; //높이
	int y; //세로
	int x; //가로
	int cost; //날짜
	ZYX(int Z, int Y, int X, int COST) :z(Z), y(Y), x(X), cost(COST) {}
}zyx;

int M, N, H; // M:가로 N:세로 H:높이, x:가로 y:세로 z:높이 matirx[H][N][M], matrix[z][y][x]
int matrix[MAX][MAX][MAX];
queue<zyx> v;
int tnum = 0;
int rt = -1;

void DFS() {
	while (!v.empty()) {
		zyx cur = v.front();
		v.pop();

		if (matrix[cur.z][cur.y][cur.x] == 1)
			continue;

		matrix[cur.z][cur.y][cur.x] = 1;
		tnum--;
		if (tnum == 0) {
			rt = cur.cost;
			return;
		}

		//6번
		if (cur.x > 0)
			v.push(ZYX(cur.z, cur.y, cur.x - 1, cur.cost + 1));
		if (cur.y > 0)
			v.push(ZYX(cur.z, cur.y - 1, cur.x, cur.cost + 1));
		if (cur.z > 0)
			v.push(ZYX(cur.z - 1, cur.y, cur.x, cur.cost + 1));
		if (cur.x < M - 1)
			v.push(ZYX(cur.z, cur.y, cur.x + 1, cur.cost + 1));
		if (cur.y < N - 1)
			v.push(ZYX(cur.z, cur.y + 1, cur.x, cur.cost + 1));
		if (cur.z < H - 1)
			v.push(ZYX(cur.z + 1, cur.y, cur.x, cur.cost + 1));
	}
}

int main(void) {
	int temp = 0;
	tnum = 0;
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &temp);
				switch (temp) {
				case 1:
					v.push(ZYX(i, j, k,0));
				case 0:
					matrix[i][j][k] = 0;
					tnum++;
					break;
				case -1:
					matrix[i][j][k] = 1;
					break;
				default:
					return -1;
				}

			}
		}
	}
	rt = -1;
	DFS();
	printf("%d", rt);
}