#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

vector<pair<int, int>> path[MAX]; // destination, cost
int global_max = 0;

int DFS(const int num, const int from, const int cost) {
	int local_max = 0;
	int best2 = 0;
	int rt = 0;
	vector<int> local_val;

	if (path[num].size() == 1) rt = cost;
	else if (path[num].size() == 2) {
		if (path[num][0].first == from) {
			rt = DFS(path[num][1].first, num, path[num][1].second) + cost;
		}
		else {
			rt = DFS(path[num][0].first, num, path[num][0].second) + cost;
		}
	}
	else {
		for (int i = 0; i < path[num].size(); i++) {
			int val = path[num][i].first;
			int pcost = path[num][i].second;

			if (val == from) continue;

			local_val.push_back(DFS(val, num, pcost));
		}

		sort(local_val.begin(), local_val.end());

		best2 = local_val[local_val.size() - 1] + local_val[local_val.size() - 2];
		global_max = max(global_max, best2);
		rt = cost + local_val[local_val.size() - 1];
	
	}

	global_max = max(global_max, rt);
	return rt;
}

int main(void) {
	int V;
	int a, b, c;
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		scanf("%d", &a); //start
		while (1) {
			scanf("%d", &b); 
			if (b == -1) break;
			scanf("%d", &c);
			path[a].push_back(make_pair(b, c));
		}
	}
	global_max = 0;
	path[1].push_back(make_pair(0, 0));
	//global_max = max(DFS(1,0,0),global_max);
	DFS(1, 0, 0);
	printf("%d\n", global_max);
}