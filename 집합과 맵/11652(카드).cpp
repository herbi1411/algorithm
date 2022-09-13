#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	long long v;
	long long maxNum = 0;
	long long maxVal = 0;
	map<long long, long long> m;
	
	cin >> N;
	for (long long i = 0; i < N; i++) {
		cin >> v;
		if (m.find(v) == m.end())
			m[v] = 1;
		else
			m[v] += 1;
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (maxNum < iter->second) {
			maxVal = iter->first;
			maxNum = iter->second;
		}
	}

	cout << maxVal << endl;
}