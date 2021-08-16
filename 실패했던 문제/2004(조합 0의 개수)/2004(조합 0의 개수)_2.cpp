#include <cstdio>
#include <algorithm>
using namespace std;

long long getSum(const long long  n, const int base) {
	long long  divNum = base;
	long long rt = 0;

	while (divNum <= n) {
		rt += n / divNum;
		divNum *= base;
	}
	return rt;
}

void solve(const long long  a, const int order, long long num2[], long long num5[]) {
	num2[order] = getSum(a ,2);
	num5[order] = getSum(a,5);
}

int main(void) {
	long long  n, m, o;
	long long num5[3] = { 0 };
	long long num2[3] = { 0 };
	scanf("%lld %lld", &n, &m);
	o = n - m;

	solve(n, 0, num2, num5);
	solve(m, 1, num2, num5);
	solve(o, 2, num2, num5);

	printf("%d\n", min(num2[0] - num2[1] - num2[2], num5[0] - num5[1] - num5[2]));
}