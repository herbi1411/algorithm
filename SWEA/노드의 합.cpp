#include <iostream>
#define endl '\n'
using namespace std;

int postorder(const int now, int arr[], const int N) {
	int rt = 0;
	if (now > N)
		return 0;
	rt += postorder(now * 2, arr, N);
	rt += postorder(now * 2 + 1, arr, N);
	arr[now] += rt;

	return arr[now];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M, L;
		int *arr;
		int num, val;
		
		cin >> N >> M >> L;
		arr = new int[N + 1];

		for (int i = 0; i <= N; i++)
			arr[i] = 0;

		for (int i = 0; i < M; i++) {
			cin >> num >> val;
			arr[num] = val;
		}
		postorder(1, arr, N);
		cout << "#" << t << " " << arr[L] << endl;
		delete[] arr;
	}

}