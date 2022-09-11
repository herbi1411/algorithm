#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	long long  N;
	long long B, C;
	vector<long long> v;
	long long num;
	long long ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		num = v[i];
		ans += 1;
		num -= B;
		if (num > 0) {
			if (num % C == 0)
				ans += num / C;
			else
				ans += num / C + 1;
		}
	}
	cout << ans << endl;
}