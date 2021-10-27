#include <cstdio>
#include <cstring>
#define MAX 10000
using namespace std;

class Stack {
private:
	int arr[MAX] = { 0 };
	int index;

public:
	Stack() {
		index = 0;
	}
	void push(int e) {
		arr[index++] = e;
	}
	int pop() {
		if (isEmpty()) return -1;
		return arr[--index];
	}
	int getSize() { return index; }
	bool isEmpty() { return index == 0;}
	int top() 
	{
		if (isEmpty()) return -1;
		return arr[index-1]; 
	}
};

int main(void) {
	int N;
	int num;
	char command[10] = { 0 };
	Stack s;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (0 == strcmp(command, "push")) {
			scanf("%d", &num);
			s.push(num);
		}
		else if (0 == strcmp(command, "top")) {
			printf("%d\n", s.top());
		}
		else if (0 == strcmp(command, "size")) {
			printf("%d\n", s.getSize());
		}
		else if (0 == strcmp(command, "empty")) {
			printf("%d\n", s.isEmpty());
		}
		else if (0 == strcmp(command, "pop")) {
			printf("%d\n", s.pop());
		}
	}
}