#include <stdio.h>

#define MSIZE 2001

int input[MSIZE] = { 0 };
int matrix[MSIZE][MSIZE] = { 0 };

int main(void)
{
	int N;
	int M;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &input[i]);
	scanf("%d", &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 1; i + j<= N; j++)
		{
			if (matrix[j + 1][i + j - 1] == 0 && input[j] == input[i + j])
				matrix[j][i + j] = 0;
			else
				matrix[j][i + j] = -1;
		}
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", matrix[s][e] == 0);
	}
}