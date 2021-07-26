#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 25
using namespace std;

bool visit[MAX][MAX];
bool matrix[MAX][MAX];
vector<int> vc;
int N;

void DFS(int a, int b) {
	if (visit[a][b] == true || matrix[a][b] == false)
		return;
	visit[a][b] = true;
	vc[vc.size() - 1] += 1;
	if (a > 0)
		DFS(a - 1, b);
	if (b > 0)
		DFS(a, b - 1);
	if (a < N-1)
		DFS(a + 1, b);
	if (b < N-1)
		DFS(a, b + 1);
}
int main(void) {
	char* temp = NULL; 
	scanf("%d", &N);
	temp = (char*)malloc(sizeof(char)*(N + 1));
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		for (int j = 0; j < N; j++) {
			if (temp[j] == '1')
				matrix[i][j] = 1;
			else if(temp[j] == '0')
				matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == true && visit[i][j] == false) {
				vc.push_back(0);
				DFS(i, j);
			}
		}
	}
	sort(vc.begin(), vc.end());
	printf("%d\n", vc.size());
	for (int i : vc) {
		printf("%d\n", i);
	}
	free(temp);
}