#include <stdio.h>
void swap(int*a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int popValue(int* arr, int* arrSize) {
	int rt = 0;
	int i = 1;
	int left, right;
	if (*arrSize == 1) {
		return 0;
	}
	else {
		rt = arr[1];
		arr[1] = arr[*arrSize - 1];
		arr[*arrSize - 1] = -1;
		*arrSize -= 1;

		while (i <= *arrSize / 2) {
			left = arr[i * 2];
			right = arr[i * 2 + 1];
			if (left >= right) {
				if (left > arr[i]) {
					swap(&arr[i], &arr[i * 2]);
					i = i * 2;
				}
				else break;
			}
			else {
				if (right > arr[i]) {
					swap(&arr[i], &arr[i * 2 + 1]);
					i = i * 2 + 1;
				}
				else break;
			}
		}
	}
	return rt;
}

void insertValue(int* arr, int* arrSize, const int value) {
	int i;
	arr[*arrSize] = value;
	i = *arrSize;
	*arrSize += 1;

	while (i / 2 >= 1) {
		if (arr[i / 2] < arr[i]) {
			swap(&arr[i], &arr[i / 2]);
			i /= 2;
		}
		else
			break;
	}
}

int main(void) {
	int* arr = NULL;
	int* arr2 = NULL;
	int arrSize = 1;
	int N;
	
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * 1000001);
	arr2 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < N; i++) {
		if (arr2[i] == 0) {
			printf("%d\n",popValue(arr,&arrSize));
		}
		else {
			insertValue(arr, &arrSize, arr2[i]);
		}
	}
	free(arr);
	free(arr2);
}