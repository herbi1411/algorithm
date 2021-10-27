#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define SMAX 9
using namespace std;

int main(void) {
	char matrix[SMAX][SMAX] = { 0 };
	char warr[SMAX][SMAX] = { 0 };
	char harr[SMAX][SMAX] = { 0 };
	char barr[SMAX][SMAX] = { 0 };
	char test[SMAX] = { 0 };
	queue<pair<int, int>> v;
	int ip;

	for (int i = 0; i < SMAX; i++) {
		for (int j = 0; j < SMAX; j++) {
			scanf("%d",&ip);
			matrix[i][j] = ip;
			if (ip == 0) {
				v.push(make_pair(i, j));
			}
			else {
				warr[i][ip - 1] = 1;
				harr[j][ip - 1] = 1;
				barr[(i / 3) * 3 + (j / 3)][ip - 1] = 1;
			}		
		}
	}
	while (!v.empty()) {
		int w = v.front().first;
		int h = v.front().second;
		int b = (w / 3) * 3 + (h / 3);
		int num3 = 0;
		bool flag = false;

		memset(test, 0, SMAX);

		for (int i = 0; i < SMAX; i++) {
			if (warr[w][i] == 0)
				test[i] += 1;
		}
		for (int i = 0; i < SMAX; i++) {
			if (harr[h][i] == 0)
				test[i] += 1;
		}
		for (int i = 0; i < SMAX; i++) {
			if (barr[b][i] == 0)
				test[i] += 1;
		}

		flag = false;
		num3 = 0;

		for (int i = 0; i < SMAX; i++) {
			if (test[i] == 3) {
				if (num3 == 0) {
					num3 = i;
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		
		if (!flag)
			continue;
		else {
			warr[w][num3] = 1;
			harr[h][num3] = 1;
			barr[b][num3] = 1;
			matrix[w][h] = num3 + 1;
			v.pop();
		}
	}
	for (int i = 0; i < SMAX; i++) {
		for (int j = 0; j < SMAX; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

}