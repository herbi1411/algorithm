#include <cstdio>
#define NMAX 10000

int main(void) {
	
	int arr[NMAX + 1] = { 0 };
	int target;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &target);
		arr[target] += 1;
	}

	for (int i = 1; i <= NMAX; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

}