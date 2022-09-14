#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#define endl '\n'
#define maxN 101
using namespace std;


void inorder(const int now, const int N, const char alpha[], const vector<int> v[]) {
	if (now > N)
		return;
	if (v[now].size() >= 1)
		inorder(v[now][0], N, alpha, v);
	cout << alpha[now];
	if (v[now].size() >= 2)
		inorder(v[now][1], N, alpha, v);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 10;
	int N;
	string s;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin.ignore(); //입력버퍼 비우기(cin은 끝의 개행문자를 버퍼에 남겨놓음 (cin을 할때 문자앞에 오는 개행은 무시))
		char alpha[maxN] = { 0 };
		int temp;
		vector<int> v[maxN];

		for (int k = 0; k < N; k++) {
			getline(cin, s);

			int idx = 0;
			istringstream iss(s);
			string buffer;
			int vnum = 0;

			while (getline(iss, buffer, ' ')) {
				if (idx == 0)
					// buffer >> vnum;
					vnum = stoi(buffer);
				else if (idx == 1)
					alpha[vnum] = buffer.at(0);
				else
					v[vnum].push_back(stoi(buffer));
				++idx;
			}	
		}
		cout << "#" << t << " ";
		inorder(1, N, alpha, v);
		cout << endl;
	}
}