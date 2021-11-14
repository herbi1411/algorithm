#include <cstdio>
#define AMAX 1000
using namespace std;


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	int arr[AMAX] = { 0 };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-j-1; j++) {
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}