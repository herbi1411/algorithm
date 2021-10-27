//∫£≥¶ √‚√≥: https://jow1025.tistory.com/245

#include <cstdio>
#include <algorithm>
#include <vector>

#define NMAX 100
using namespace std;


int sgcd(int a, int b) {
	if (b > a)
		return sgcd(b, a);
	if (b == 0)
		return a;
	return sgcd(b, a % b);
}


int main(void) {
	int arr[NMAX] = { 0 };
	int N;
	int gcd;
	vector<int> rt;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	sort(arr, arr + N);

	gcd = arr[1] - arr[0];
	for (int i = 1; i < N - 1; i++) {
		gcd = sgcd(gcd, arr[i + 1] - arr[i]);
	}

	rt.push_back(gcd);
	for (int i = 2; i*i <= gcd; i++) {
		if (gcd % i == 0) {
			rt.push_back(i);
			if ((gcd / i) != i)
				rt.push_back(gcd / i);
		}
	}
	sort(rt.begin(), rt.end());

	for (int a : rt)printf("%d ", a);
	printf("\n");

}