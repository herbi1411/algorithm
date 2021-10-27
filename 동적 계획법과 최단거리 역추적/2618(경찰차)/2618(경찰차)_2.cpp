//º£³¦ ÃâÃ³: https://yabmoons.tistory.com/644
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAX 1001
using namespace std;

int dp[MAX][MAX] = { 0 };
int incidentX[MAX] = { 0 };
int incidentY[MAX] = { 0 };
int N, W;

int getDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}


int solve(int p1, int p2) {
	int dist1;
	int dist2;
	int rt1;
	int rt2;
	int nd;
	int rt;

	if (p1 == W || p2 == W)
		return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];

	nd = max(p1, p2) + 1;

	if (p1 == 0) dist1 = getDistance(incidentX[nd], incidentY[nd], 1, 1);
	else dist1 = getDistance(incidentX[nd], incidentY[nd], incidentX[p1], incidentY[p1]);

	if (p2 == 0) dist2 = getDistance(incidentX[nd], incidentY[nd], N, N);
	else dist2 = getDistance(incidentX[nd], incidentY[nd], incidentX[p2], incidentY[p2]);

	rt1 = dist1 + solve(nd, p2);
	rt2 = dist2 + solve(p1, nd);

	rt = min(rt1, rt2);
	dp[p1][p2] = rt;

	return rt;
}
void route(int p1, int p2, vector<int>& v) {
	int dist1;
	int dist2;
	int rt1;
	int rt2;
	int nd;
	if (p1 == W || p2 == W) return;

	nd = max(p1, p2) + 1;

	if (p1 == 0) dist1 = getDistance(incidentX[nd], incidentY[nd], 1, 1);
	else dist1 = getDistance(incidentX[nd], incidentY[nd], incidentX[p1], incidentY[p1]);

	if (p2 == 0) dist2 = getDistance(incidentX[nd], incidentY[nd], N, N);
	else dist2 = getDistance(incidentX[nd], incidentY[nd], incidentX[p2], incidentY[p2]);

	rt1 = dist1 + dp[nd][p2];
	rt2 = dist2 + dp[p1][nd];

	if (rt1 <= rt2) {
		v.push_back(1);
		route(nd, p2,v);
	}
	else {
		v.push_back(2);
		route(p1, nd, v);
	}

}

int main(void) {

	vector<int> v;
	
	scanf("%d", &N);
	scanf("%d", &W);

	for (int i = 1; i <= W; i++) {
		scanf("%d %d", &incidentX[i], &incidentY[i]);
	}
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			dp[i][j] = -1;
	solve(0, 0);

	printf("%d\n", dp[0][0]);

	route(0, 0, v);
	for (int i = 0; i < v.size(); i++) printf("%d\n", v[i]);
}