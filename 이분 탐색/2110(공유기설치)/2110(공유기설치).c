#include<stdio.h>
#include<stdlib.h>
int* quickSort(const int start, const int end, int* arr) {
	int a, b, pivot;
	int temp;
	if (start >= end)
		return arr;

	a = start;
	b = end;
	pivot = arr[(end + start) / 2];

	while (1) {
		while (arr[a] < pivot) {
			a += 1;
		}
		while (arr[b] > pivot) {
			b -= 1;
		}

		if (a > b)
			break;

		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
		a += 1;
		b -= 1;

		if (a > b)
			break;
	}

	arr = quickSort(start, b, arr);
	arr = quickSort(a, end, arr);
	return arr;
}
int main(void) {
	int N, M;
	int* arr = NULL;
	int right, left, ans, mid, d;
	int start, cnt;
	scanf("%d %d", &N, &M);
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	arr = quickSort(0, N - 1, arr);

	left = 1;
	right = arr[N - 1] - arr[0];
	ans = 0;

	while(right >= left) {
		start = arr[0];
		mid = (right + left) / 2;
		cnt = 1;
		for (int i = 1; i < N; i++) {
			d = arr[i] - start;
			if (d >= mid) {
				start = arr[i];
				cnt++;
			}
		}
		if (M <= cnt) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
//	printf("%d\n", ans);
	printf("%d\n", right);
	free(arr);
	return 0;
}