#include <cstdio>
#include <vector>
#define MAX 1000000
using namespace std;

int arr[MAX] = { 0 };
int dp[MAX] = { 0 };

int upper_bound(int s, int e, const int targ, vector<int>& v) {
	int mid = (s + e) / 2;
	if (s > e) {
		if (s >= v.size())
			v.push_back(targ);
		else
			v[s] = targ;
		return s;
	}

	if (v[mid] >= targ) {
		e = mid - 1;
	}
	else {
		s = mid + 1;
	}

	return upper_bound(s, e, targ, v);
}


int main(void){

	vector<int> v;
	vector<int> rt;
	int N;
	int temp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	v.push_back(arr[0]);
	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		dp[i] = upper_bound(0, v.size()-1, arr[i], v) + 1;
	}

	temp = v.size();
	printf("%d\n", temp);
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == temp) {
			rt.push_back(arr[i]);
			temp--;
		}
	}
	for (int i = rt.size() - 1; i >= 0; i--) {
		printf("%d ", rt[i]);
	}
	printf("\n");
}