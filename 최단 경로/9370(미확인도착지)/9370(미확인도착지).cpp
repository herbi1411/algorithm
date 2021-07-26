#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2001
using namespace std;


int T;

int main(void){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		vector<pair<int, int>>path[MAX];
		priority_queue<pair<int, int>>pq;
		int dist[MAX];
		bool isPath[MAX];
		int n, m, t;
		int s, g, h;
		int a, b, d;
		int* arr = NULL;

		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b, &d);
			path[a].push_back(make_pair(b, d));
			path[b].push_back(make_pair(a, d));
		}

		arr = (int*)malloc(sizeof(int) * t);
		for (int j = 0; j < t; j++) {
			scanf("%d", &arr[j]);
		}

		for (int j = 1; j <= n; j++) { 
			dist[j] = 0x7fffffff; 
			isPath[j] = 0;
		}
		
		dist[s] = 0;
		pq.push(make_pair(0, s));
		while (!pq.empty()) {
			int cur = pq.top().second;
			int pathCost = -pq.top().first;

			pq.pop();
			for (int j = 0; j < path[cur].size(); j++) {
				int nCur = path[cur][j].first;
				int nCost = path[cur][j].second + pathCost;
				if (dist[nCur] > nCost) {
					if (!isPath[cur] && (((cur == g) && (nCur == h) || (cur == h) && (nCur == g)))){
							isPath[nCur] = true;
					}
					else
						isPath[nCur] = isPath[cur];
					dist[nCur] = nCost;
					pq.push(make_pair(-nCost, nCur));
				}
			}
		}
		sort(arr, arr + t);
		for (int j = 0; j < t; j++) {
			if (isPath[arr[j]])
				printf("%d ", arr[j]);
		}
		printf("\n");

		free(arr);
	}
}