#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX] = { 0 };
char arr1[MAX] = { 0 };
char arr2[MAX] = { 0 };
char rt[MAX] = { 0 };

int main(void) {
	int arr1Size;
	int arr2Size;
	int strindex;
	int rtindex;
	scanf("%s", arr1);
	scanf("%s", arr2);

	arr1Size = strlen(arr1);
	arr2Size = strlen(arr2);

	for (int i = 0; i < arr1Size; i++) {
		for (int j = 0; j < arr2Size; j++) {
			if (arr1[i] == arr2[j]) 
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}


	strindex = dp[arr1Size][arr2Size];
	rtindex = 0;
	printf("%d\n", strindex);

	for (int i = arr1Size; i > 0; i--) {
		for (int j = arr2Size; j > 0; j--) {
			if (dp[i][j] == strindex && (dp[i - 1][j] + 1) == dp[i][j] && (dp[i][j - 1] + 1) == dp[i][j]) {
				strindex--;
				rt[strindex] = arr1[i - 1];
				break;
			}
		}
	}

	printf("%s", rt);
}