#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#define MAX 1000001
using namespace std;
int arr[MAX];

int main(void) {
	vector<int> v;
	queue<int> q;
	int N;
	int counter;
	int temp;
	int tnum;

	scanf("%d", &N);
	counter = 0;

	//
	if (N == 1) {
		printf("0\n1\n");
		exit(0);
	}

	//
	q.push(1);
	arr[1] = 1;
	while (true) {
		int temp = q.front();
		int mul3 = temp * 3;
		int mul2 = temp * 2;
		int add1 = temp + 1;
		q.pop();


		if (mul3 < MAX && arr[mul3] == 0) {
			arr[mul3] = arr[temp] + 1;
			q.push(mul3);
		}
		if (mul2 < MAX && arr[mul2] == 0) {
			arr[mul2] = arr[temp] + 1;
			q.push(mul2);
		}
		if (add1 < MAX && arr[add1] == 0) {
			arr[add1] = arr[temp] + 1;
			q.push(add1);
		}
		if (mul3 == N || mul2 == N || add1 == N)
			break;
	}
	
	temp = N;
	while (temp > 0) {
		v.push_back(temp);
		tnum = arr[temp];
		if (temp % 3 == 0 && arr[temp / 3] == tnum - 1)
			temp /= 3;
		else if (temp % 2 == 0 && arr[temp / 2] == tnum - 1)
			temp /= 2;
		else if (arr[temp - 1] == tnum - 1)
			temp -= 1;
		else {
			printf("?\n");
			exit(0);
		}
	}
	printf("%d\n", arr[N] - 1);
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}
