#include <stdio.h>

long long min(long long  a, long long b) { return a < b ? a : b; }
int main(void) {
	
	long long N, K;
	long long left, right, mid;
	long long start,cnt;
	
	scanf("%lld %lld", &N, &K);
	left = 1;
	right = N*N;
	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (K <= cnt)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%lld\n", left);
};