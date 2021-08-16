#include <cstdio>
#define MAX 100001
using namespace std;

int min_heap[MAX] = { 0 };
int max_heap[MAX] = { 0 };
int arr[MAX] = { 0 };
int min_heap_size = 0;
int max_heap_size = 0;
int median = 0;

bool compare(int a, int b, bool mode) {
	return !((a > b) ^ mode);
}

void swap(int& a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void heap_push(const int value, int heap[], int & heapSize, bool mode) {
	int temp;
	temp = ++heapSize;

	while (temp > 1) {
		int parent = temp / 2;
		if (compare(heap[parent], value, mode)) {
			heap[temp] = heap[parent];
			temp = parent;
		}
		else
			break;
	}
	heap[temp] = value;
}

int heap_pop(int heap[], int & heapSize, bool mode) {
	int rt = heap[1];
	int temp;
	
	heap[1] = heap[heapSize--];
	temp = 1;

	while (temp < heapSize) {
		int right = temp * 2 + 1;
		int left = temp * 2;

		if (right <= heapSize) {
			if (compare(heap[right], heap[left], mode)) {
				if (compare(heap[temp], heap[left], mode)) {
					swap(heap[temp], heap[left]);
					temp = left;
				}
				else
					break;
			}
			else {
				if (compare(heap[temp], heap[right], mode)) {
					swap(heap[temp], heap[right]);
					temp = right;
				}
				else
					break;
			}
		}
		else {
			if (compare(heap[temp], heap[left], mode)) {
				swap(heap[temp], heap[left]);
				temp = left;
			}
			else
				break;
		}
	}
	return rt;
}


int main(void) {
	int N;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	median = arr[0];
	printf("%d\n", median);

	for (int i = 1; i < N; i++) {
		int temp = arr[i];

		if (min_heap_size == max_heap_size) {
			if (temp >= median) {
				heap_push(temp,max_heap,max_heap_size, true);
			}
			else {
				heap_push(median, max_heap, max_heap_size, true);
				heap_push(temp, min_heap, min_heap_size, false);
				median = heap_pop(min_heap, min_heap_size, false);
			}
		}
		else {
			if (temp <= median) {
				heap_push(temp, min_heap, min_heap_size, false);
			}
			else {
				heap_push(median, min_heap, min_heap_size, false);
				heap_push(temp, max_heap, max_heap_size, true);
				median = heap_pop(max_heap, max_heap_size, true);
			}
		}
		printf("%d\n", median);
	}
}