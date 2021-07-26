#include <cstdio>
#include <vector>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#define MAX 801
using namespace std;

vector<pair<int,int>>path[MAX];
unsigned int minCost[MAX][MAX];
int visit[MAX];
int N, E;
int v, w;

void search(int start, int cur, int cost) {
	int nextCur;
	int nextCost;
	if (visit[cur] == 1)
		return;
	visit[cur] = 1;
	minCost[start][cur] =  min(minCost[start][cur],(unsigned int) cost);
	for (int i = 0; i < path[cur].size(); i++) {
		nextCur = path[cur][i].first;
		nextCost = path[cur][i].second;
		search(start, nextCur, cost + nextCost);
	}
	visit[cur] = 0;
}

int main(void) {
	int a, b, c;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		path[a].push_back(make_pair(b, c));
		path[b].push_back(make_pair(a, c));
	}
	memset(minCost,0xFF, MAX*MAX);
	scanf("%d %d", &v, &w);

	for (int i = 1; i <= N; i++) {
		minCost[i][i] = 0;
		search(i, i, 0);
	}


	printf("%d\n", min(minCost[1][v] + minCost[v][w] + minCost[w][N], minCost[1][w] + minCost[w][v] + minCost[w][N]));
}