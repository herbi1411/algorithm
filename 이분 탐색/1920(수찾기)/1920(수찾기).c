#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Æ²¸²
int* quickSort(const int start, const int end, int* arr) {
	int a, b, pivot;
	int temp;
	if (start >= end)
		return arr;

	a = start;
	b = end;
	pivot = arr[(end+start) / 2];

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
int findNum(const int target, const int start, const int end, int* arr) {
	int temp;
	if (end - start < 0)
		return 0;
	temp = arr[(end + start) / 2];
	if (target == temp)
		return 1;
	else if (target >= temp)
		return findNum(target, (end + start) / 2 + 1, end, arr);
	else if (target < temp)
		return findNum(target, start, (end + start) / 2 - 1, arr);
}
int main(void) {
	int num,num2;
	int* arr = NULL;
	int* arr2 = NULL;
	scanf("%d", &num);
//	num = 5;
	arr = (int *)malloc(num * sizeof(int));
	arr2 = (int *)malloc(num * sizeof(int));
	srand(time(NULL));
//	printf("arr1: ");
	for (int i = 0; i < num; i++) {
//		arr[i] = rand() % 10;
//		printf("%d ", arr[i]);
		scanf("%d", &arr[i]);
	}
//	printf("\narr1 sorted: ");

	arr = quickSort(0, num - 1, arr);
//	for (int i = 0; i < num; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\narr2: ");
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++) {
		scanf("%d", &arr2[i]);
//		arr2[i] = rand() % 10;
//		printf("%d ", arr2[i]);
	}
//	printf("\n");

	for (int i = 0; i < num2; i++) {
		printf("%d\n", findNum(arr2[i],0, num2-1, arr));
	}

	free(arr);
	free(arr2);
}