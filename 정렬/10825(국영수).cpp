#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
#define maxSize 100000
using namespace std;

struct student {
	int korean;
	int english;
	int math;
	string name;
};

void insertStruct(struct student arr[maxSize], const int idx, const int korean, const int english, const int math, const string& name) {
	arr[idx].korean = korean;
	arr[idx].english = english;
	arr[idx].math = math;
	arr[idx].name = name;
}

bool cmp(struct student &a, struct student &b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.english < b.english;
	}
	return a.korean > b.korean;
}

//struct student arr[maxSize] = { 0 };

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int korean, english, math;
	string name;
	struct student *arr;

	cin >> N;
	arr = new struct student[N];
	for (register int i = 0; i < N; i++) {
		cin >> name >> korean >> english >> math;
		insertStruct(arr, i, korean, english, math, name);
	}
	sort(arr, arr + N, cmp);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i].name << endl;
	}

	delete[] arr;
}