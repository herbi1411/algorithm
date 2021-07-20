#include <stdio.h>
#include <stdlib.h>
#define HEAP_SIZE 100001

int compare(int a, int b) { //a가 b보다 우선순위가 작으면(뒤로가면) 1, 아니면 0 return
	int x = abs(a);
	int y = abs(b);
	if (x > y)
		return 1;
	else if (y > x)
		return 0;
	else
		return a > b;
}
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int popValue(int* heap, int* arrSize) {
	int rt;
	int index;
	int left, right;
	if (*arrSize == 1)
		return 0;
	
	rt = heap[1];
	heap[1] = heap[*arrSize - 1];
	heap[*arrSize - 1] = -100;
	index = 1;
	while (index < *arrSize / 2) {
		left = index * 2;
		right = index * 2 + 1;
		if (right >= *arrSize - 1) { //left만존재
			if (compare(heap[index], heap[left])) {
				swap(&heap[index], &heap[left]);
				index = left;
			}
			else
				break;
		}
		else {
			if (compare(heap[left], heap[right])){
				if (compare(heap[index], heap[right])) {
					swap(&heap[index], &heap[right]);
					index = right;
				}
				else
					break;
			}
			else {
				if (compare(heap[index], heap[left])) {
					swap(&heap[index], &heap[left]);
					index = left;
				}
				else
					break;
			}
		}
	}
	*arrSize -= 1;
	return rt;
}

void insertValue(int* heap, int value, int* arrSize) {
	int index = *arrSize;
	int parent;
	while (index > 1) {
		parent = index / 2;
		if (compare(heap[parent], value)) {
			heap[index] = heap[parent];
			index = parent;
		}
		else
			break;
	}
	heap[index] = value;
	*arrSize+=1;
}

int main(void) {
	int N;
	int* arr = NULL;
	int* heap = NULL;
	int arrSize = 1;
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);
	heap = (int *)malloc(sizeof(int)*HEAP_SIZE);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0)
			printf("%d\n", popValue(heap,&arrSize));
		else
			insertValue(heap, arr[i], &arrSize);
	}
	free(arr);
	free(heap);
}