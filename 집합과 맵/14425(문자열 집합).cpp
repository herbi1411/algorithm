#include <iostream>
#include <string>
#include <unordered_set>
#define endl '\n'
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	int cnt = 0;
	string s;
	unordered_set<string> uset;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		uset.insert(s);
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (uset.find(s) != uset.end())
			++cnt;
	}
	cout << cnt << endl;
}