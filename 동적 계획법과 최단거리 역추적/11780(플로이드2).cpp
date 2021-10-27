#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 101
#define INF 987654321
using namespace std;

int cost[MAX][MAX];
int route[MAX][MAX] = { 0 };
vector<int> get_route;

void cal_route(int a, int b, int arr[][MAX]) {
	const int val = arr[a][b];

	if (val == 0)
		return;
	cal_route(a, val,arr);
	get_route.push_back(val);
	cal_route(val, b, arr);
}


int main(void) {
	int n, m;
	int a, b, c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cost[i][j] = INF;
	for (int i = 1; i <= n; i++)cost[i][i] = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = min(cost[a][b],c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || k == j)
					continue;
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					route[i][j] = k;
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF)
				printf("0 ");
			else 
				printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("(%d, %d): ", i, j);
			for (int k = 0; k < route[i][j].size(); k++)
				printf("%d ", route[i][j][k]);
			printf("\n");
		}
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || cost[i][j] == INF) {
				printf("0\n");
				continue;
			}
			get_route.clear();
			get_route.push_back(i);
			cal_route(i, j, route);
			get_route.push_back(j);
			printf("%d ", get_route.size());
			for (int a : get_route) printf("%d ", a);
			printf("\n");
		}
	}

}