#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int* arr = NULL;
	int fp, bp, aw;
	int tg;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &tg);

	fp = 0;
	bp = n - 1;
	aw = 0;

	sort(&arr[0], &arr[n]);

	while (bp > fp) {
		int temp = arr[bp] + arr[fp];
		if (temp > tg)
			bp--;
		else {
			if (temp == tg)
				aw++;
			fp++;
		}
	}
	printf("%d\n", aw);
	free(arr);
}