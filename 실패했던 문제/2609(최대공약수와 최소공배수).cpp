#include <cstdio>
using namespace std;

int sgcd(int a, int b) {
	if (b > a)
		return sgcd(b, a);
	if (b == 0)
		return a;
	return sgcd(b, a % b);
}


int main(void) {
	int A, B;
	int gcd;
	int lcm;
	
	scanf("%d %d", &A, &B);
	gcd = sgcd(A, B);
	lcm = gcd * (A / gcd) * (B / gcd);
	printf("%d\n%d\n", gcd, lcm);

}