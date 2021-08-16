#include <cstdio>
#include <algorithm>
#define MAX 1001
#define COLNUM 3
#define INF 0x7FFFFFFF
using namespace std;

int arr[MAX][COLNUM] = { 0 };
int dp[COLNUM] = { 0 };
int ndp[COLNUM] = { 0 };

int main(void) {
	int N;
	int rt;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < COLNUM; j++) {
			int temp = INF;
			scanf("%d", &arr[i][j]);
			for (int k = 0; k < COLNUM; k++) {
				if (k == j)
					continue;
				else
					temp = min(temp, dp[k]);
			}
			ndp[j] = arr[i][j] + temp;
		}
		for (int j = 0; j < COLNUM; j++)
			dp[j] = ndp[j];
	}

	rt = INF;
	for (int i = 0; i < COLNUM; i++)
		rt = min(rt, dp[i]);
	printf("%d\n", rt);
}
