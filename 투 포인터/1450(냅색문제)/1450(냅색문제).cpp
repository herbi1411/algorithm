#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;

void dfs(int s, const int e, vector<int> &v, int cost, const int* arr) {
	if (cost > C)
		return;
	if (s > e) {
		v.push_back(cost);
		return;
	}
	dfs(s + 1, e, v, cost, arr);
	dfs(s + 1, e, v, cost + arr[s], arr);
}

int upper_bound(int s, int e, const int cost, const vector<int> & v) {
	int mid = (s + e) / 2;
	if (s > e)
		return e;
	
	if (v[mid] > cost)
		e = mid - 1;
	else
		s = mid + 1;
	
	return upper_bound(s, e, cost, v);
}


int main(void) {

	int* arr = NULL;
	int rt = 0;

	vector<int> v1, v2;
	scanf("%d %d", &N, &C);
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dfs(0, N / 2 - 1, v1, 0, arr);
	dfs(N / 2, N - 1, v2, 0, arr);

	sort(v2.begin(), v2.end());
	
	rt = 0;
	for (int i = 0; i < v1.size(); i++) {
		rt += upper_bound(0, v2.size() - 1, C - v1[i], v2) + 1;
	}
	printf("%d\n", rt);
	free(arr);
}