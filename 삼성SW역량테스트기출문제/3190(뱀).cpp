#include <iostream>
#include <queue>
#include <tuple>
#define maxSize 100
using namespace std;

int main(void) {
	int N, K, L;
	int x, y;
	int t;
	int direction; //0:north 1:east 2:south 3:west
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	char d;
	bool apple[maxSize][maxSize] = { 0 };
	bool matrix[maxSize][maxSize] = { 0 };
	queue<pair<int, char>> dir;
	queue<pair<int, int>> snake;

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		apple[x - 1][y - 1] = true;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> t >> d;
		dir.push(make_pair(t, d));
	}

	matrix[0][0] = true;
	snake.push(make_pair(0, 0));
	x = 0;
	y = 0;
	t = 1;
	direction = 1;
	while (!snake.empty()) {
		int tx, ty;
		tx = x + dx[direction];
		ty = y + dy[direction];
		if (0 > tx || tx >= N || 0 > ty || ty >= N)
			break;
		x = tx;
		y = ty;
		if (matrix[x][y] == true)
			break;
		matrix[x][y] = true;
		if (apple[x][y] == false) {
			tie(tx, ty) = snake.front();
			snake.pop();
			matrix[tx][ty] = false;
		}
		else
			apple[x][y] = false;
		snake.push(make_pair(x, y));
		if (!dir.empty() && dir.front().first == t) {
			if (dir.front().second == 'L')
				direction = (direction - 1 + 4) % 4;
			else if (dir.front().second == 'D')
				direction = (direction + 1) % 4;
			dir.pop();
		}
		t++;
	}
	cout << t << endl;
}