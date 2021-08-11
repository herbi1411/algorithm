#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 0X7FFFFFFF
using namespace std;

int main(void) {
	int N, S;
	int* arr = NULL;
	int* aw = NULL;
	int rt;
	bool flag = false;
	scanf("%d %d", &N, &S);
	arr = (int*)malloc(sizeof(int)*N);
	aw = (int*)malloc(sizeof(int)*N);
	rt = INF;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		aw[i] = 0;
	}

	flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			aw[j] += arr[j+i];
			if (aw[j] >= S) {
				flag = true;
				break;
			}
		}
		if (flag) {
			rt = i + 1;
			break;
		}
	}

	if (rt == INF)
		printf("0\n");
	else
		printf("%d\n", rt);

	free(arr);
	free(aw);
}
