#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 100000
#define INF 987654321
using namespace std;

int dp[MAX] = { 0 };

int main(void) {
	int N, M;
	int a, b;
	int vindex;
	int temp;
	vector<pair<int, int>> v;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}


	vindex = 0;

	for (int i = 1; i < MAX; i++) dp[i] = INF;

	for (int k = 0; k < v.size(); k++) {
		int curv = v[k].second;
		vindex += v[k].second;
		
		for (int i = vindex; i > curv; i--) {
				dp[i] = min(dp[i],v[k].first + dp[i - curv]);
		}
		for (int i = 1; i <= curv; i++) {
				dp[i] = min(dp[i], v[k].first);
		}
		
	}
	temp = 1;
	while (dp[temp] <= M) temp++;
	temp--;

	printf("%d\n", temp);
}