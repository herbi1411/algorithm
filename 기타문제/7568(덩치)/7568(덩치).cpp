#include <cstdio>
#include <vector>

using namespace std;
int main(void) {
	int n;
	vector<pair<int, int>> v;
	vector<int> rank;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		pair<int, int> temp;
		scanf("%d %d", &temp.first, &temp.second);
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		int cur_rank = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				cur_rank += 1;
		}
		rank.push_back(cur_rank);
	}

	for (int a : rank) {
		printf("%d ", a);
	}

}