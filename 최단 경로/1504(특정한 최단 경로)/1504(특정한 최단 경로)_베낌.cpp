#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 801
using namespace std;
vector<pair<int, int>> path[MAX];
priority_queue<pair<int, int>> pq;
int minCost[MAX];
int N, E;
int V, W;

void cal(int a) {
	pq.push(make_pair(0,a));
	minCost[a] = 0;
	while (!pq.empty()) {
		int pathCost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < path[cur].size(); i++) {
			int nCur = path[cur][i].first;
			int nCost = path[cur][i].second  + pathCost;

			if (minCost[nCur] > nCost) {
				minCost[nCur] = nCost;
				pq.push(make_pair(-nCost, nCur));
			}
		}
	}
}

int main(void) {
	//선언
	int a, b, c;
	int totalCost1, totalCost2;
	char flag1, flag2; 
	flag1 = flag2 = 1;
	totalCost1 = totalCost2 = 0;

	//입력
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a].push_back(make_pair(b, c));
		path[b].push_back(make_pair(a, c));
	}
	scanf("%d %d", &V, &W);

	//해결
	//case 1:
	for (int i = 0; i <= N; i++) minCost[i] = 0x7FFFFFFF;
	cal(1);

	if (minCost[V] != 0) totalCost1 += minCost[V];
	else flag1 = 0;
	
	if (minCost[W] != 0) totalCost2 += minCost[W];
	else flag2 = 0;

	//case V:
	for (int i = 0; i <= N; i++) minCost[i] = 0x7FFFFFFF;
	cal(V);

	if (minCost[W] == 0) {
		flag1 = flag2 = 0;
	}
	else {
		totalCost1 += minCost[W];
		totalCost2 += minCost[W];
	}
	if (minCost[N] != 0) {
		totalCost2 += minCost[N];
	}
	else flag2 = 0;

	//case W:
	for (int i = 0; i <= N; i++) minCost[i] = 0x7FFFFFFF;
	cal(W);

	if (minCost[N] != 0) totalCost1 += minCost[N];
	else flag1 = 0;

	//출력
	if (flag1) {
		if (flag2)
		{
			printf("%d\n", min(totalCost1, totalCost2));
		}
		else
			printf("%d\n", totalCost1);
	}
	else if (flag2) {
		printf("%d\n", totalCost2);
	}
	else {
		printf("-1\n");
	}



}
