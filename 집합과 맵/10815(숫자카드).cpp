#include <iostream>
#include <unordered_set>
#define endl '\n'
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int val;
	unordered_set<int> uset;
	uset.bucket_size(999983);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		uset.insert(val);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> val;
		if (uset.find(val) == uset.end())
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}
	cout << endl;
}