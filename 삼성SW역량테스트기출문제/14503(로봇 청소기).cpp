#include <iostream>
#define maxSize 50
using namespace std;

int main(void) {
	int N, M;
	int arr[maxSize][maxSize] = { 0 };
	int r, c, d;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int ans = 0;

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		int tr, tc;
		bool flag = false;

		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			ans += 1;
		}
		for (int i = 1; i <= 4; i++) {
			tr = r + dx[(d - i + 4) % 4];
			tc = c + dy[(d - i + 4) % 4];

			if (arr[tr][tc] == 0) {
				r = tr;
				c = tc;
				d = (d - i + 4) % 4;
				flag = true;
				break;
			}
		}
		if (!flag) {
			if (arr[r - dx[d]][c - dy[d]] == 1)
				break;
			else {
				r = r - dx[d];
				c = c - dy[d];
			}
		}
	}

	cout << ans << endl;
}