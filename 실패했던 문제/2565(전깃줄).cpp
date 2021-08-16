#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;

int main(void) {
	vector<pair<int, int>> v;
	int arr[MAX] = { 0 };
	int dp[MAX] = { 0 };

	int N;
	int a, b;
	int rrt;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		arr[i] = v[i].second;

	rrt = 0;
	for (int i = 0; i < N; i++) {
		int temp = 1;
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				temp = max(temp, dp[j]+1);
			}
		}
		rrt = max(rrt,temp);
		dp[i] = temp;
	}
	printf("%d\n", N - rrt);
}
