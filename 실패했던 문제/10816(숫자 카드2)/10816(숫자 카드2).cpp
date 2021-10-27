#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 500001
using namespace std;

int matrix[MAX] = { 0 };
int target[MAX] = { 0 };	
int N, M;



int findNum(const int index, const int target, const int arr[]) {
	int rt = 0;
	int l_index = index;
	int h_index = index + 1;

	while (l_index >= 0) {
		if (arr[l_index] == target)
			rt++;
		l_index--;
	}

	while (h_index < N) {
		if (arr[h_index] == target)
			rt++;
		h_index++;
	}

	return rt;
}

int search(int a, int b, const int target, const int arr[]) {
	int mid = (a + b) / 2;
	if (a > b)
		return 0;
	if (arr[mid] == target)
		return findNum(a, arr[mid],arr);

	else if (arr[mid] < target)
		a = mid + 1;
	else
		b = mid - 1;

	return search(a, b, target, arr);
}


int main(void) {
	vector<int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &matrix[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)scanf("%d", &target[i]);

	sort(matrix, matrix + N);
	for (int i = 0; i < M; i++) {
		v.push_back(search(0, matrix[N - 1], target[i],matrix));
	}

	for (int a : v) printf("%d ", a);
	printf("\n");
}