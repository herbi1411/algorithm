#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define INF 0x7FFFFFFF
using namespace std;

int main(void) {
	int N;
	int* arr = NULL;
	int fp, bp;

	int a, b;
	int rt;
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);

	fp = 0;
	bp = N - 1;
	rt = INF;
	while (bp > fp) {
		int temp = arr[fp] + arr[bp];
		if (rt > abs(temp)) {
			a = arr[fp];
			b = arr[bp];
			rt = abs(temp);
		}
		if (temp > 0)
			bp--;
		else if (temp < 0)
			fp++;
		else
			break;
	}
	printf("%d %d", a, b);
	free(arr);
}