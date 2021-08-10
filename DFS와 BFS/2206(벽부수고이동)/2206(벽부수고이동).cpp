#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAX 1001
#define INF 0x7FFFFFFF
using namespace std;


char matrix[MAX][MAX];
int cost[MAX][MAX];

int main(void) {
	int N, M;
	int a;
	char* line = NULL;
	int rt;
	queue<pair<pair<int, int>,pair<int,bool>>> q; // <x,y> <cost,isDestroy>
	scanf("%d %d", &N, &M);

	memset(matrix, 0, MAX*MAX);


	line = (char *)malloc(sizeof(char)*(M + 1));
	for (int i = 1; i <= N; i++) {
		scanf("%s", line);
		for (int j = 0; j < M; j++) {
			if (line[j] == '1')
				matrix[i][j+1] = 1;
			else if (line[j] == '0')
				matrix[i][j+1] = 0;

			cost[i][j+1] = INF;
		}
	}

	q.push(make_pair(make_pair(1, 1), make_pair(1, 0)));
	rt = -1;
	while (!q.empty()) {
		char curX = q.front().first.first;
		char curY = q.front().first.second;
		char curCost = q.front().second.first;
		bool curDestroy = q.front().second.second;

		q.pop();

		if (curX == N && curY == M) {
			rt = curCost;
			break;
		}

		if (matrix[curX][curY] != -1 && ((((curDestroy==true && matrix[curX][curY] == 0) || curDestroy == false) && curCost < cost[curX][curY]) || (cost[curX][curY] != INF && curDestroy == false))) 
		{
			bool nDestroy = (curDestroy || matrix[curX][curY]);
			if(matrix[curX][curY] == 0 && curDestroy == false)
				matrix[curX][curY] = -1;

			if (curX > 1) {
				q.push(make_pair(make_pair(curX - 1, curY), make_pair(curCost + 1, nDestroy)));
			}
			if (curY > 1) {
				q.push(make_pair(make_pair(curX, curY - 1), make_pair(curCost + 1, nDestroy)));
			}
			if (curX < N) {
				q.push(make_pair(make_pair(curX + 1, curY), make_pair(curCost + 1, nDestroy)));
			}
			if (curY < M) {
				q.push(make_pair(make_pair(curX, curY + 1), make_pair(curCost + 1, nDestroy)));
			}
		}
	}
	printf("%d\n", rt);
	free(line);
}