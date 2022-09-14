#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

void kmp(string &p, int arr[], const int size) {
	int i, j;
	
	i = 0;
	j = 1;
	arr[0] = 0;
	while (j < size) {
		if (p[i] == p[j]) {
			arr[j] = i + 1;
			++i;
			++j;
		}
		else {
			if (i != 0)
				i = arr[i - 1];
			else {
				arr[j] = 0;
				++j;
			}
		}
	}

}

int main(void) {
	string t, p;
	int cnt = 0;
	int *match;
	int i, j;
	int len;
	vector<int> idx;

	getline(cin, t);
	getline(cin, p);
//	cout << t << endl;
//	cout << p << endl;

	match = new int[p.length()];
	memset(match, 0, sizeof(int) * p.length());

	kmp(p, match, p.length());
	
//	for (int i = 0; i < p.length(); i++)
//		cout << match[i] << " ";
//	cout << endl;

	i = 0;
	j = 0;
	len = t.length();
	while (i < len) {
		if (t[i] == p[j]) {
			i++;
			j++;
			if (j == p.length()) {
				cnt++;
				idx.push_back(i - p.length() + 1);
				j = match[j - 1];
			}
		}
		else {
			if (j == 0)
				i++;
			else {
				j = match[j - 1];
			}
		}
	}

	cout << cnt << endl;
	for (auto num : idx)
		cout << num << " ";
	cout << endl;
	delete[] match;
}