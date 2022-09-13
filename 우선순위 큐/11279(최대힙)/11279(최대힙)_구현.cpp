#include <iostream>
#define endl '\n'
#define HSIZE 100001
using namespace std;

template <typename T>
class priority_queue {
private:
	T bucket[HSIZE] = { 0 };
	unsigned int size = 0;

	void push_restruct() {
		unsigned int temp = size;
		while (temp > 1) {
			unsigned int head = temp / 2;
			if (!compare(bucket[head], bucket[temp]))
				swap(bucket[head], bucket[temp]);
			temp = head;
		}
	}
	bool compare(const T& a, const T& b) {
		return a > b;
	}
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

public:

	void push(T val) {
		bucket[++size] = val;
		push_restruct();
	}

	bool empty() {
		return size == 0;
	}

	T top() {
		if (empty())
			return NULL;
		return bucket[1];
	}

	T pop() {
		T rt;
		unsigned int temp = 1;

		if (empty())
			return NULL;
		
		rt = top();
		bucket[1] = bucket[size--];

		while (temp * 2 <= size) {
			if (temp * 2 + 1 <= size) {
				unsigned int left = temp * 2;
				unsigned int right = temp * 2 + 1;
				unsigned int target;

				if (compare(bucket[left], bucket[right]))
					target = left;
				else
					target = right;

				if (!compare(bucket[temp], bucket[target]))
					swap(bucket[temp], bucket[target]);
				else
					break;
				temp = target;
			}
			else {
				unsigned int left = temp * 2;
				if (!compare(bucket[temp], bucket[left]))
					swap(bucket[temp], bucket[left]);
				else
					break;
				temp = left;
				
			}
		}

	}

};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<int> pq;
	register int temp;
	
	cin >> N;
	for (register int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}
}