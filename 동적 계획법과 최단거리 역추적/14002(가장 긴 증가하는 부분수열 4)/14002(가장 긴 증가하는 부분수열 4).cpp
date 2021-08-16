#include <cstdio>
#include <vector>
#define MAX 1000
using namespace std;

int main(void) {
	int arr[MAX] = { 0 };
	int dp[MAX] = { 0 };
	int dmax;
	int temp;
	vector<int> v;
	int N;

	scanf("%d",&N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dmax = 1;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] >= dp[i]) {
				dp[i] = dp[j] + 1;
				if (dmax < dp[i])
					dmax = dp[i];
			}
				
		}
	}
	temp = dmax;
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == temp) {
			v.push_back(arr[i]);
			temp--;
		}
	}
	printf("%d\n", dmax);
	for (int i =v.size()-1; i>=0; i--)
		printf("%d ", v[i]);
	printf("\n");

}