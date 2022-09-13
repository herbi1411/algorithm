#include <iostream>
#include <string>
#define ALNUM 26
#define endl '\n'
using namespace std;

class Trie {
public:
	Trie* arr[ALNUM];
	bool end;

	Trie() {
		end = false;
		for (int i = 0; i < ALNUM; i++)
			arr[i] = NULL;
	}

	~Trie() {
		for (int i = 0; i < ALNUM; i++)
			if (arr[i])
				delete arr[i];
	}

	void insert(const char *c) {
		if (!*c) {
			this->end = true;
			return;
		}
		int now = *c - 'a';
		if (!arr[now])
			arr[now] = new Trie;
		arr[now]->insert(c + 1);
	}

	bool find(const char *c) {
		if (!*c) {
			//return this->end;
			return true;
		}
		
		int now = *c - 'a';
		if (!arr[now])
			return false;
		else
			return arr[now]->find(c + 1);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int cnt = 0;
	Trie t;
	string s;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		t.insert(s.c_str());
	}

	for (int j = 0; j < M; j++) {
		cin >> s;

		if (t.find(s.c_str()))
			++cnt;
	}

	cout << cnt << endl;
}