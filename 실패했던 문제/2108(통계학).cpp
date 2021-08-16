#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 8001
#define AMAX 500000
using namespace std;

int arr[AMAX] = { 0 };
int snum[MAX] = { 0 };

int main(void) {
	int N;
	int nmax, nmin;
	int median, range, most;
	double avg;
	int most_max;
	int most_count;
	median = 0;
	avg = 0;
	range = 0;
	most = 0;
	most_max = 0;
	most_count = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
	{
		scanf("%d", &arr[i]);
		avg += arr[i];
		snum[arr[i] + 4000] += 1;
		most_max = max(most_max, snum[arr[i] + 4000]);
	}

	sort(arr, arr + N);

	avg /= N;
	median = arr[N / 2];
	range = arr[N - 1] - arr[0];

	for (int i = 0; i < MAX; i++) {
		if (snum[i] == most_max) {
			most = i - 4000;
			most_count++;
			if (most_count == 2)
				break;
		}
	}
	printf("%d\n", (int)round(avg));
	printf("%d\n", median);
	printf("%d\n", most);
	printf("%d\n", range);
}
