#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<int> pq;
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