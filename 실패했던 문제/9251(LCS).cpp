//∫£≥¶ √‚√≥: https://st-lab.tistory.com/139
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX] = { 0 };
char arr1[MAX] = { 0 };
char arr2[MAX] = { 0 };

int main(void) {
	
	int len1, len2;

	scanf("%s", arr1);
	scanf("%s", arr2);
	
	len1 = strlen(arr1);
	len2 = strlen(arr2);
	

	for (int i = 0; i < len2; i++) {
		if (arr1[0] == arr2[i]) {
			for (int j = i; j < len2; j++)
				dp[0][j] = 1;
			break;
		}
	}

	for (int i = 1; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (arr1[i] == arr2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	printf("%d\n", dp[len1-1][len2-1]);
}