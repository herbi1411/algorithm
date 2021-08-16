#include <cstdio>
#include <algorithm>
using namespace std;

long long getSum(int n) {
	long long temp = (long long)n;
	return temp / 2 * (temp - 1);
}

void solve(int a, int order, long long num2[], long long num5[]) {
	int d2, d5;

	d2 = a / 2;
	d5 = a / 5;

	num2[order] = getSum(d2);
	num5[order] = getSum(d5);
}

int main(void) {
	int n, m, o;
	long long num5[3] = { 0 };
	long long num2[3] = { 0 };
	scanf("%d %d", &n, &m);
	o = n - m;

	solve(n, 0, num2, num5);
	solve(m, 1, num2, num5);
	solve(o, 2, num2, num5);

	printf("%d\n", min(num2[0] - num2[1] - num2[2], num5[0] - num5[1] - num5[2]));
}