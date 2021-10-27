//∫£≥¶ √‚√≥: https://yabmoons.tistory.com/88
#include <cstdio>
#include <cstdlib>
#define SMAX 9
using namespace std;

char matrix[SMAX][SMAX] = { 0 };
char warr[SMAX][SMAX] = { 0 };
char harr[SMAX][SMAX] = { 0 };
char barr[SMAX][SMAX] = { 0 };

void printArr() {
	for (int i = 0; i < SMAX; i++) {
		for (int j = 0; j < SMAX; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


void dfs(int num) {

	int w = num / 9;
	int h = num % 9;
	int b = (w / 3) * 3 + (h / 3);
	if (num == SMAX*SMAX) {
		printArr();
		exit(0);
	}
	if (matrix[w][h] != 0)
		dfs(num + 1);
	else {
		int temp[SMAX] = { 0 };
		for (int i = 0; i < SMAX; i++)
			if (warr[w][i] != 0) temp[i] += 1;
		for (int i = 0; i < SMAX; i++)
			if (harr[h][i] != 0) temp[i] += 1;
		for (int i = 0; i < SMAX; i++)
			if (barr[b][i] != 0) temp[i] += 1;

		for (int i = 0; i < SMAX; i++) {
			if (temp[i] == 0) {
				warr[w][i] = 1;
				harr[h][i] = 1;
				barr[b][i] = 1;
				matrix[w][h] = i+1;

				dfs(num + 1);

				warr[w][i] = 0;
				harr[h][i] = 0;
				barr[b][i] = 0;
				matrix[w][h] = 0;
			}
		}
	}

}

int main(void) {

	int ip;
	for (int i = 0; i < SMAX; i++) {
		for (int j = 0; j < SMAX; j++) {
			scanf("%d", &ip);
			matrix[i][j] = ip;
			if (ip != 0) {
				warr[i][ip - 1] = 1;
				harr[j][ip - 1] = 1;
				barr[(i / 3) * 3 + (j / 3)][ip - 1] = 1;
			}
		}
	}
	dfs(0);
}