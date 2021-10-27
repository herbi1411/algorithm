#include <cstdio>
#include <vector>
#include <cmath>

#define MAX 1001
using namespace std;

typedef struct _entry {
	int cost;
	int x1;
	int y1;
	int x2;
	int y2;

	_entry(int X1, int Y1, int X2, int Y2, int Cost) : x1(X1), y1(Y1), x2(X2), y2(Y2), cost(Cost) {};
}entry;

entry dp[MAX][2];

int main(void) {
	int N, W;
	int a, b;
	vector<pair<int,int>> v;

	scanf("%d", &N);
	scanf("%d", &W);
	for (int i = 0; i < W; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}

	dp[0][0] = entry(1, 1, N, N, 0);
	dp[0][1] = entry(1, 1, N, N, 0);

	dp[1][0] = entry(v[0].first, v[0].second, N, N, abs(v[0].first - dp[0][0].x1) + abs(v[0].second - dp[0][0].y1));
	dp[1][1] = entry(1, 1, v[0].first, v[0].second, abs(v[0].first - dp[0][1].x2) + abs(v[0].second - dp[0][1].y2));

	for (int i = 1; i < W; i++) {
		int tx = v[i].first;
		int ty = v[i].second;
		int cost1;
		int cost2;

		cost1 = dp[i - 1][0].cost + abs(dp[i - 1][0].x1 - tx) + abs(dp[i - 1][0].y1 - ty);
		cost2 = dp[i - 1][1].cost + abs(dp[i - 1][1].x1 - tx) + abs(dp[i - 1][1].y1 - ty);

		if (cost1 > cost2) {
		
		}
		
		


	}
}