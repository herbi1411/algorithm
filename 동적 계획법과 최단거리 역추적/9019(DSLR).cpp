#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 10000
using namespace std;

int dp[MAX] = { 0 };
int parent[MAX] = { 0 };
char command[MAX] = { 0 };


void dslr(const int idx, const int val, queue<int>& q) {
	int temp;
	int remainder;
	int arr[4] = { 0 };
	
	//d
	temp = (idx * 2) % MAX;
	arr[0] = temp;

	//s
	temp = (idx - 1 + MAX) % MAX;
	arr[1] = temp;

	//l
	temp = idx * 10;   //ex) 1234 => 12340
	temp += temp / MAX; // 12341
	temp %= MAX; // 2341
	arr[2] = temp;

	//r
	remainder = idx % 10; //ex) 1234 => remainder = 4
	temp = idx / 10; // 123
	temp += remainder * (MAX / 10); // 123 + 4 * 1000 = 4123
	arr[3] = temp;

	//push
	for (int i = 0; i < 4; i++) {
		int a = arr[i];
		if (dp[a] == -1) {
			dp[a] = val + 1;

			if (i == 0) command[a] = 'D';
			else if (i == 1) command[a] = 'S';
			else if (i == 2) command[a] = 'L';
			else if (i == 3) command[a] = 'R';

			parent[a] = idx;
			q.push(a);
		}
	}
}


int main(void) {
	int T;
	vector<int> routeVector;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		int route;
		queue<int> q;

		routeVector.clear();
		scanf("%d %d", &a, &b);
		memset(dp, -1, sizeof(dp));
		memset(parent, -1, sizeof(parent));
	//	for (int i = 0; i < MAX; i++)dp[i] = -1;
	//	for (int i = 0; i < MAX; i++)parent[i] = -1;
		
		dp[a] = 0;
		q.push(a);

		while (!q.empty()) {
			const int idx = q.front();
			const int val = dp[idx];

			q.pop();

			if (idx == b) break;

			dslr(idx, val, q);
		}

//		printf("%d\n", dp[b]);
		route = b;
		while (parent[route] != -1) {
			routeVector.push_back(route);
			route = parent[route];
		}
		for (int i = routeVector.size() - 1; i >= 0; i--) {
			printf("%c", command[routeVector[i]]);
		}
		printf("\n");
	}

}

