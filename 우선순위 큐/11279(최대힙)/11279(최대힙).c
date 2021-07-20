#include <stdio.h>
//실패(시간초과)
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
	int* arr = NULL;
	int* arr2 = NULL;
	int arrSize = 0;
	int N;
	
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * 1000000);
	arr2 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < N; i++) {
		if (arr2[i] == 0) {
			if (arrSize == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", arr[--arrSize]);
			}
		}
		else {
			arr[arrSize++] = arr2[i];
			quickSort(0, arrSize - 1, arr);
		}
	}
	free(arr);
	free(arr2);
}