#include <cstdio>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int dp[MAX] = { 0 };

int main(void) {
	int N, K;
	int temp, tempv;
	queue<int> q;
	vector<int> rt;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < MAX; i++)dp[i] = -1;

	dp[N] = 0;
	q.push(N);
	
	while (!q.empty()) {
		const int cur = q.front();
		const int curValue = dp[cur];
		const int nValue = curValue + 1;
		q.pop();

		if (cur == K) {
			break;
		}

		if (cur - 1 >= 0 && dp[cur - 1] == -1) {
			q.push(cur - 1);
			dp[cur - 1] = nValue;
		}
		if (cur + 1 < MAX && dp[cur + 1] == -1) {
			q.push(cur + 1);
			dp[cur + 1] = nValue;
		}
		if (cur * 2 < MAX && dp[cur * 2] == -1) {
			q.push(cur * 2);
			dp[cur * 2] = nValue;
		}
	}

	printf("%d\n", dp[K]);

	temp = K;
	tempv = dp[K];

	while (1) {
		rt.push_back(temp);
		if (temp == N) break;

		if (temp - 1 >= 0 && dp[temp - 1] == tempv - 1) {
			temp -= 1;
		}
		else if (temp + 1 < MAX && dp[temp + 1] == tempv - 1) {
			temp += 1;
		}
		else if (temp % 2 == 0 && temp / 2 > 0 && dp[temp / 2] == tempv - 1) {
			temp /= 2;
		}
		tempv--;
	}

	for (int i = rt.size()-1; i >= 0; i--) printf("%d ", rt[i]);
	printf("\n");
}
