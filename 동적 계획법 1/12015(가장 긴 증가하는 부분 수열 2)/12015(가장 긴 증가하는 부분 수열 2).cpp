#include <cstdio>
#include <vector>
#define MAXSIZE 1000000
using namespace std;

int input[MAXSIZE] = { 0 };

int main(void)
{
	vector<int> answer;
	int N;

	answer.reserve(MAXSIZE);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &input[i]);
	for (int i = 0; i < N; i++) 
	{
		int s, e;
		int val = input[i];

		s = 0;
		e = answer.size() - 1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			
			if (answer[mid] < val)
				s = mid + 1;
			else if (answer[mid] > val)
				e = mid - 1;
			else
				break;
		}
		if (s >= answer.size())
			answer.push_back(val);
		else
			answer[s] = val;
	}
	printf("%d\n", answer.size());
	return 0;
}