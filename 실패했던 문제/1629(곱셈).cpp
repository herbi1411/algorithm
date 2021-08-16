#include <cstdio>

using namespace std;

long long solve(long long a, int b, const int c) {
	long long temp;
	long long rt;
	if (b == 1)
		return a % c;

	temp = solve(a, b / 2, c);
	rt = (temp*temp) % c;
	if (b % 2 == 0)
		return rt;
	else
		return (rt * a) % c;

}


int main(void) {
	long long A;
	int B, C;
	long long rt;
	scanf("%lld %d %d", &A, &B, &C);

	rt = solve(A, B, C);
	printf("%d\n", rt);
}