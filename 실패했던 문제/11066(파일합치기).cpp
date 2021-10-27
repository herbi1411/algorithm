//∫£≥¶ √‚√≥: https://js1jj2sk3.tistory.com/3
#include <cstdio>
#include <algorithm>

#define NMAX 501
#define INF 0x7FFFFFFF
using namespace std;

int dp[NMAX][NMAX] = { 0 };
int sum[NMAX] = { 0 };

int main(void) {
	int T, N;
	int curCost;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &curCost);
			sum[i] = sum[i - 1] + curCost;
		}
		for (int i = 1; i < N; i++) {
			for (int x = 1; x + i <= N; x++) {
				int y = x + i;
				dp[x][y] = INF;
				for (int mid = x; mid < y; mid++) {
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
				}
			}
		}
		printf("%d\n", dp[1][N]);
	}
}