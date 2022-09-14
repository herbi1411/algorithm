#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

struct cmp {
	bool operator() (int a, int b) const{
		if (a >= 0 && b >= 0)
			return a > b;
		else if (a >= 0 && b < 0)
			return a >= -b;
		else if (a < 0 && b >= 0)
			return -a > b;
		else if (a < 0 && b < 0)
			return -a > -b;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<int, vector<int>, cmp> pq;
	register int temp;

	cin >> N;
	for (register int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}
}