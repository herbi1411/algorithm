#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define PNSIZE 283146
#define MAX 4000001
using namespace std;
int setPrime(int* pn);
bool chae[MAX];

int main(void) {
	int N;
	int* pn = NULL;
	int pnSize;
	int fp, bp;
	int rt;
	int temp;
	scanf("%d", &N);
	pn = (int*)malloc(sizeof(int) * PNSIZE);
	pnSize = setPrime(pn);

	fp = 0;
	bp = 0;
	rt = 0;
	temp = 0;

	while (bp < PNSIZE) {
		if (temp > N) {
			temp -= pn[fp++];
		}
		else {
			if (temp == N)
				rt += 1;
			temp += pn[bp++];
		}
	}

	printf("%d\n", rt);
	free(pn);
}

int setPrime(int* pn) {

	int pnIndex = 0;
	int tnum = sqrt(4000000) + 1;



	memset(chae, 0, MAX);
	for (int i = 2; i <= tnum; i++) {
		if (chae[i])
			continue;
		else {
			for (int j = i + i; j < MAX; j += i) {
				chae[j] = true;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (!chae[i]) {
			pn[pnIndex++] = i;
		}
	}
	//printf("pnIndex = %d\n", pnIndex);
	//for (int i = 0; i < pnIndex; i++) {
	//	printf("%d ", pn[i]);
	//}
	//printf("\n");

	return pnIndex;
}