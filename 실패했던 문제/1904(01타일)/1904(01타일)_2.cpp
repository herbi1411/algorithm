#include <cstdio>
#define MAX 1000001
int dp[MAX] = { 0 };

using namespace std;

int main(void) {
	int N;
	dp[1] = 1;
	dp[2] = 2;
	
	scanf("%d", &N);

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	printf("%d\n", dp[N]);
}