#include <cstdio>

#define NMAX 30
#define MMAX 7
#define AMAX 15001
using namespace std;

char arr[AMAX] = { 0 };
char arr2[AMAX] = { 0 };

int main(void) {
	int N, M;
	int narr[NMAX] = { 0 };
	int marr[MMAX] = { 0 };
	char* arrp = NULL;
	char* arr2p = NULL;
	char* temp = NULL;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &narr[i]);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) scanf("%d", &marr[i]);

	arr[0] = 1;
	arr2[0] = 1;

	arrp = arr;
	arr2p = arr2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= AMAX - narr[i]; j++) {
			if (arrp[j] == 1) {
				arr2p[j] = 1;
				if(j + narr[i] < AMAX)
					arr2p[j + narr[i]] = 1;
				if (j - narr[i] > 0)
					arr2p[j - narr[i]] = 1;
				if (narr[i] - j > 0)
					arr2p[narr[i] - j] = 1;
			}
		}
		temp = arrp;
		arrp = arr2p;
		arr2p = temp;
	}
	
	for (int i = 0; i < M; i++) {
		if (marr[i] > AMAX - 1) {
			printf("N ");
		}
		else if (arrp[marr[i]] == 1)
			printf("Y ");
		else
			printf("N ");
	}
	printf("\n");
}