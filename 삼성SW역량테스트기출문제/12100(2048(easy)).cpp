#include <iostream>
#include <malloc.h>
#include <algorithm>
#define maxSize 20
using namespace std;

struct block {
	int val;
	bool stack;
};

int ans = 0;

int getMaxVal(struct block arr[maxSize][maxSize], int N) {
	int rt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rt = max(rt, arr[i][j].val);
		}
	}
	if (rt == 24)
		cout << "hello" << endl;
	return rt; 
}

void arrcpy(struct block target[maxSize][maxSize], struct block source[maxSize][maxSize], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			target[i][j] = source[i][j];
		}
	}
}

void move_north(struct block arr[maxSize][maxSize], int N) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (arr[i][j].val == 0)
				continue;
			else {
				int ti = i;
				while (ti > 0) {
					if (arr[ti - 1][j].val == 0) {

						arr[ti - 1][j].val = arr[ti][j].val;
						arr[ti][j] = { 0, 0 };
						ti--;
						continue;
					}
					else {
						if (arr[ti - 1][j].val == arr[ti][j].val && arr[ti - 1][j].stack == false) {
							arr[ti - 1][j].val += arr[ti][j].val;
							arr[ti - 1][j].stack = true;
							arr[ti][j] = { 0, 0 };
						}
						break;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			arr[i][j].stack = false;
		}
	}
}

void move_east(struct block arr[maxSize][maxSize], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (arr[i][j].val == 0)
				continue;
			else {
				int tj = j;
				while (tj < N - 1) {
					if (arr[i][tj + 1].val == 0) {

						arr[i][tj + 1].val = arr[i][tj].val;
						arr[i][tj] = { 0, 0 };
						tj++;
						continue;
					}
					else {
						if (arr[i][tj + 1].val == arr[i][tj].val && arr[i][tj + 1].stack == false) {
							arr[i][tj + 1].val += arr[i][tj].val;
							arr[i][tj + 1].stack = true;
							arr[i][tj] = { 0, 0 };
						}
						break;
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			arr[i][j].stack = false;
		}
	}
}

void move_south(struct block arr[maxSize][maxSize], int N) {
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i][j].val == 0)
				continue;
			else {
				int ti = i;
				while (ti < N - 1) {
					if (arr[ti + 1][j].val == 0) {

						arr[ti + 1][j].val = arr[ti][j].val;
						arr[ti + 1][j] = arr[ti][j];
						arr[ti][j] = { 0, 0 };
						ti++;
						continue;
					}
					else {
						if (arr[ti + 1][j].val == arr[ti][j].val && arr[ti + 1][j].stack == false) {
							arr[ti + 1][j].val += arr[ti][j].val;
							arr[ti + 1][j].stack = true;
							arr[ti][j] = { 0, 0 };
						}
						break;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			arr[i][j].stack = false;
		}
	}
}

void move_west(struct block arr[maxSize][maxSize], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j].val == 0)
				continue;
			else {
				int tj = j;
				while (tj > 0) {
					if (arr[i][tj - 1].val == 0) {

						arr[i][tj - 1].val = arr[i][tj].val;
						arr[i][tj] = { 0, 0 };
						tj--;
						continue;
					}
					else {
						if (arr[i][tj - 1].val == arr[i][tj].val && arr[i][tj - 1].stack == false) {
							arr[i][tj - 1].val += arr[i][tj].val;
							arr[i][tj - 1].stack = true;
							arr[i][tj] = { 0, 0 };
						}
						break;
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			arr[i][j].stack = false;
		}

	}
}

void recur(int depth, struct block arr[maxSize][maxSize], int N) {
	struct block tarr[maxSize][maxSize] = { 0 };
	void (*fp[4])(struct block arr[][maxSize], int) = { move_north, move_east, move_south, move_west};

	if (depth == 5) {
		ans = max(ans, getMaxVal(arr, N));
		return;
	}

	for (int i = 0; i < 4; i++) {
		arrcpy(tarr, arr, N);
		fp[i](tarr, N);
		recur(depth + 1, tarr, N);
	}
}

int main(void) {
	int N;
	struct block arr[maxSize][maxSize] = { 0 };
	int val;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> val;
			arr[i][j] = { val, 0 };
		}
	}

	recur(0, arr, N);
	cout << ans << endl;
}