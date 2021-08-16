#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;

int arr[MAX] = { 0 };
int arr2[MAX] = { 0 };

int search(int s, int e, const int arr[], const int number) {
	
	int mid = (s + e) / 2;

	if (arr[mid] == number)
		return 1;
	else if (s > e)
		return 0;

	if (arr[mid] > number)
		e = mid - 1;
	else if (arr[mid] < number)
		s = mid + 1;

	return search(s, e, arr, number);
}


int main(void) {
	int N, M;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) scanf("%d", &arr2[i]);

	sort(arr, arr + N);

	for (int i = 0; i < M; i++) {
		printf("%d\n", search(0,N-1,arr, arr2[i]));
	}

}