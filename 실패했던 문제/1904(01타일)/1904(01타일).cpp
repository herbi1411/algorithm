#include <cstdio>
#define MAX 1000001
using namespace std;

int dp[MAX] = { 0 };

int main(void) {
	int N;
	int rt;
	scanf("%d", &N);

	rt = 1;
	for (int i = 2; i <= N; i++) {
		rt += i / 2;
	}

	printf("%d\n", rt);
}