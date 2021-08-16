#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int N;
	int counter;

	scanf("%d", &N);
	counter = 0;

	while (N > 0) {
		v.push_back(N);
		if (N % 3 != 0)
			N -= 1;
		else 
			N /= 3;
		counter++;
	}
	counter--;
	printf("%d\n", counter);
	for (int s : v) printf("%d ", s);
	printf("\n");
}
