#include <stdio.h>
#include <stdlib.h>
#define HEAPSIZE 100001

int compare(short a, short b, int flag) { //flag 0: 최대힙, 1:최소힙
	if (flag)
		return a > b;
	else
		return a < b;
} // rt가 0이면 A가 우선순위높음(부모로 가야함)
void swap(short*a, short*b){
	short temp = *a;
	*a = *b;
	*b = temp;
}
short popValue(int* heap, int* heapSize, int flag) {
	short rt;
	int index = 0;
	int left, right;
	if (*heapSize < 0)
		return -1;
	rt = heap[0];
	heap[0] = heap[--(*heapSize)];
	while (index < *heapSize / 2) {
		left = index * 2 + 1;
		right = index * 2 + 2;

		if (right >= *heapSize) {
			if (compare(heap[index], heap[left], flag)) {
				swap(&heap[index], &heap[left]);
				index = left;
			}
			else
				break;
		}
		else{
			if (compare(heap[left], heap[right], flag)) {
				if (compare(heap[index], heap[right], flag)) {
					swap(&heap[index], &heap[right]);
					index = right;
				}
				else
					break;
			}
			else {
				if (compare(heap[index], heap[left], flag)) {
					swap(&heap[index], &heap[left]);
					index = left;
				}
				else
					break;
			}
		}
	}
	return rt;
}

void insertValue(short value, int* heap, int* heapSize, int flag) {
	int index = *heapSize;
	int parent;
	while (index > 0) {
		parent = index / 2;
		if (compare(heap[parent], value ,flag)) {
			heap[index] = heap[parent];
			index = parent;
		}
		else break;
	}
	heap[index] = value;
	*heapSize += 1;
}


int main(void) {
	short N;
	short* arr = NULL;
	short* heap1 = NULL;
	short* heap2 = NULL;
	short* heap1Size = 0;
	short* heap2Size = 0;
	short mid = 0;
	short pt = 0;
	scanf("%hd",&N);
	arr = (short *)malloc(sizeof(short)*N);
	heap1 = (short *)malloc(sizeof(short)*HEAPSIZE);
	heap2 = (short *)malloc(sizeof(short)*HEAPSIZE);

	for (int i = 0; i < N; i++) {
		scanf("%hd", &arr[i]);
	}
	mid = arr[0];
	pt = arr[0];
	printf("%hd\n", pt);
	for (int i = 1; i < N; i++) {
		if (i % 2 == 1) {
			if (mid <= arr[i]) {
				insertValue(arr[i], heap2, &heap2Size,1);
			}
			else {
				insertValue(arr[i], heap1, &heap1Size,0);
				insertValue(mid, heap2, &heap2Size,1);
				pt = popValue(heap1, &heap1Size,0);
			}
		}
		else {
			if (mid < arr[i]) {
				insertValue(mid, heap1, &heap1Size,0);
				insertValue(arr[i], heap2, &heap2Size,1);
				pt = popValue(heap2, &heap2Size,1);
			}
			else {
				insertValue(arr[i], heap1, &heap1Size,0);
			}
		}
		printf("%hd\n", pt);
	}

	free(arr);
	free(heap1);
	free(heap2);
}