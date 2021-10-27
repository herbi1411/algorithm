#include <cstdio>
#include <algorithm>

#define AMAX 20000001
#define MID  10000000
using namespace std;

int hashmap[AMAX] = { 0 };

int main(void) {
	int N, M;
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		hashmap[a+MID]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		printf("%d ", hashmap[a+MID]);
	}
	printf("\n");
}