// merge sort
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 1000000
using namespace std;

int arr[MAX];

bool compare(int a, int b) { return a < b; }

int* mergeSort(const int s, const int e, const int arr[]) {
	int* a1 = NULL;
	int* a2 = NULL;
	int* rt = NULL;
	const int mid = (s + e) / 2;
	const int a1Size = mid - s + 1;
	const int a2Size = e - mid;
	const int rtSize = (e - s) + 1;
	int a1Index = 0;
	int a2Index = 0;

	if (s >= e) {
		rt = (int*) malloc(sizeof(int));
		*rt = arr[s];
		return rt;
	}

	a1 = mergeSort(s, mid, arr);
	a2 = mergeSort(mid + 1, e, arr);

	rt = (int*)malloc(sizeof(int) * (e - s + 1));

	for (int i = 0; i < rtSize; i++) {
		if (a1Index == a1Size)
			rt[i] = a2[a2Index++];
		else if (a2Index == a2Size)
			rt[i] = a1[a1Index++];
		else
		{
			if (compare(a1[a1Index], a2[a2Index]))
				rt[i] = a1[a1Index++];
			else
				rt[i] = a2[a2Index++];
		}
	}
	free(a1);
	free(a2);
	return rt;
}


int main(void) {
	int N;
	int* rt = NULL;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	rt = mergeSort(0, N - 1, arr);
	
	for (int i = 0; i < N; i++) printf("%d\n", rt[i]);
	free(rt);
}