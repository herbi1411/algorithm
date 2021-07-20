#include <stdio.h>
//Æ²¸²
long long func(long long a, long long b, long long c) {
	
	int temp;
	if (b == 0) return 1;
	

	temp = func(a, b / 2, c);
	if (b % 2 == 0)
		return (temp * temp) % c;
	else
		return (((temp * temp) % c) * a) % c;
}


int main(void) {
	long long  a, b, c,result;
	scanf("%lld %lld %lld", &a, &b, &c);
		result = func(a, b, c);
	printf("%lld\n", result);
}