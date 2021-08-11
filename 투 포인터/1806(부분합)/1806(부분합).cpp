#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 0X7FFFFFFF
using namespace std;

int main(void) {
	int N, S;
	int* arr = NULL;
	int fp, bp;
	int rt;
	int temp;
	scanf("%d %d", &N, &S);
	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	fp = 0;
	bp = 0;
	rt = INF;
	temp = 0;

	while (bp < N) {
		temp += arr[bp];
		if (temp >= S) {
			rt = min(rt, bp - fp + 1);
			fp = bp;
			temp = 0;
			if (rt == 1)
				break;
		}
		else
			bp++;
	}
	if (rt == INF)
		printf("0\n");
	else
		printf("%d\n", rt);
	free(arr);
}
