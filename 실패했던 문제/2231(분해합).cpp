#include <cstdio>
using namespace std;

int main(void) {
	int N;
	int i;
	int temp, sum;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		sum = i;
		temp = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N)
			break;
	}
	if (i > N)
		printf("0\n");
	else
		printf("%d\n", i);
}