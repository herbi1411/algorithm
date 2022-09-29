#include <iostream>
#define MAXN 20
//#include <unordered_set>
using namespace std;

int ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int R, C;

//void DFS(int depth, int x, int y, unordered_set<char> & uset, char matrix[MAXN][MAXN], bool visited[MAXN][MAXN]) {
void DFS(int depth, int x, int y, bool bucket[], char matrix[MAXN][MAXN], bool visited[MAXN][MAXN]) {

	//uset.insert(matrix[x][y]);
	bucket[matrix[x][y] - 'A'] = true;
	ans = ans > depth + 1 ? ans : depth + 1;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < R and 0 <= ny && ny < C && visited[nx][ny] == false) {
			//if (uset.find(matrix[nx][ny]) == uset.end())
			if (bucket[matrix[nx][ny] - 'A'] == false)
				//DFS(depth + 1, nx, ny, uset, matrix, visited);
				DFS(depth + 1, nx, ny, bucket, matrix, visited);

		}
	}
	//uset.erase(matrix[x][y]);
	bucket[matrix[x][y] - 'A'] = false;
	visited[x][y] = false;
}

int main(void) {

	//unordered_set<char> uset;
	bool bucket[26] = { false };
	char matrix[MAXN][MAXN];
	bool visited[MAXN][MAXN] = { false };
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> matrix[i][j];
	

	//DFS(0, 0, 0, uset, matrix, visited);
	DFS(0, 0, 0, bucket, matrix, visited);
	cout << ans << endl;
}