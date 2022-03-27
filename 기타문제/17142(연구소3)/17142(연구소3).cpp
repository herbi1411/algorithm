#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#define NMAX 50
#define MMAX 10
#define CLENGTH 252
using namespace std;

int matrix[NMAX][NMAX];
vector<vector<pair<int,int>>> combination;
vector<pair<int, int>> vcandidate;
vector<bool> check(MMAX, false);

void printCombination();
void printMatrix(int matrix[], int size);

void setCombination(const int M, const int fillNum, const int sIdx)
{
	if (M == fillNum)
	{
		vector<pair<int,int>> &newvec = *(new vector<pair<int,int>>);
		newvec.reserve(MMAX);

		for (int i = 0; i < vcandidate.size(); i++)
		{
			if (check[i] == true)
				newvec.push_back(vcandidate[i]);
		}
		combination.push_back(newvec);
	}

	else
	{
		for (int i = sIdx; i < vcandidate.size(); i++)
		{
			if (check[i] == false) 
			{
				check[i] = true;
				setCombination(M, fillNum + 1, i + 1);
				check[i] = false;
			}
		}
	}
}

int main(void) {
	int N, M;
	int zeroNum;
	int answer;

	combination.reserve(CLENGTH);
	vcandidate.reserve(MMAX);

	zeroNum = 0;
	answer = INT_MAX;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			if (temp == 1)
				matrix[i][j] = -1;
			else if (temp == 0)
			{
				zeroNum++;
				matrix[i][j] = INT_MAX;
			}
			else if (temp == 2)
			{
				vcandidate.push_back(make_pair(i, j));
				matrix[i][j] = -2;
			}
		}
	setCombination(M, 0, 0);

	for (vector<pair<int, int>> cVal : combination)
	{
		int tMatrix[NMAX][NMAX];
		queue<pair<pair<int, int>, int>> q;
		int xarr[4] = { -1,1,0,0 };
		int yarr[4] = { 0,0,-1,1 };
		int fillZero = 0;
		int costMax = -1;

		memcpy(tMatrix, matrix, sizeof(int) * NMAX * NMAX);
		for (pair<int, int> pVal : cVal)
			q.push(make_pair(pVal, 0));

		while (!q.empty()) 
		{
			int x, y, cost;

			x = q.front().first.first;
			y = q.front().first.second;
			cost = q.front().second;
			q.pop();

			if (tMatrix[x][y] == -1 || (tMatrix[x][y] >= 0 && tMatrix[x][y] <= cost))
				continue;
			if (tMatrix[x][y] > 0)
				fillZero++;
			tMatrix[x][y] = cost;
			
			if (fillZero == zeroNum)
			{
				costMax = cost;
				break;
			}

			for(int i=0; i<4; i++)
			{
				if (x + xarr[i] >= 0 && x + xarr[i] < N && y + yarr[i] >= 0 && y + yarr[i] < N)
				{
					q.push(make_pair(make_pair(x + xarr[i], y + yarr[i]), cost + 1));
				}
			}
		}
		if (costMax != -1)
			answer = min(answer, costMax);
	}
	if (answer == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", answer);
}

void printMatrix(int matrix[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[NMAX* i + j]);
		printf("\n");
	}
}

void printCombination()
{
	for (vector<pair<int, int>> temp : combination)
	{
		for (pair<int, int> val : temp)
			printf("(%d, %d) ", val.first, val.second);
		printf("\n");
	}
}