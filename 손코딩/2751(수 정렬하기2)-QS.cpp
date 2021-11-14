#include <cstdio>
#define AMAX 1000000
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(const int s, const int e, int arr[]) {
	int pivot = arr[(s + e) / 2];
	int start = s;
	int end = e;

	if (s >= e)
		return;

	while (start <= end) {
		while (start <= end && arr[start] < pivot) start++;
		while (end >= start && arr[end] > pivot) end--;

		if (start <= end) {
			swap(arr[start], arr[end]);
			start++;
			end--;
		}
	}

	quickSort(s, end, arr);
	quickSort(start, e, arr);
}


int main(void) {
	int arr[AMAX] = { 0 };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quickSort(0, n - 1, arr);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}