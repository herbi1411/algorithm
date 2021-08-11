#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 0X7FFFFFFF
using namespace std;

int main(void) {
	int N, S;
	int* arr = NULL;
	int rt;
	int fp, bp;
	int temp;

	scanf("%d %d", &N, &S);
	arr = (int*)malloc(sizeof(int)*N+1);
	rt = INF;

	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
	
	fp = 0;
	bp = 0;
	rt = INF;
	temp = 0;

	while (bp <= N) {
		if (temp < S) {
			temp += arr[bp++];
		}
		else{
			rt = min(rt, bp - fp);
			if (rt == 1)
				break;
			temp -= arr[fp++];
		}
	}

	if (rt == INF)
		printf("0\n");
	else
		printf("%d\n", rt);

	free(arr);
}
