#include <cstdio>
#include <queue>
#include <vector>
#define INF 2147483647
#define VMAX 20001
using namespace std;

int main(void)
{
	int v, e, s;
	int ts, te, tc;
	vector<pair<int, int>> path[VMAX];
	int cost[VMAX];
	priority_queue<pair<int, int>>pq;

	scanf("%d %d", &v, &e);
	scanf("%d", &s);
	s -= 1;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &ts, &te, &tc);
		ts -= 1;
		te -= 1;
		path[ts].push_back(make_pair(te, tc));
	}
	for (int i = 0; i < v; i++)
	{
		cost[i] = INF;
	}
	pq.push(make_pair(0, s));
	cost[s] = 0;

	while (!pq.empty())
	{
		pair<int, int> entry;
		int now;
		int ccost;

		entry = pq.top();
		pq.pop();
		ccost = -entry.first;
		now = entry.second;
		for (pair<int,int> e: path[now])
		{
			int next;
			int ncost;

			next = e.first;
			ncost = e.second;
			if (ccost + ncost < cost[next])
			{
				cost[next] = ccost + ncost;
				pq.push(make_pair(-(ccost + ncost), next));
			}
		}
	}
	for (int i = 0; i < v; i++)
	{
		if (cost[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", cost[i]);
	}


}