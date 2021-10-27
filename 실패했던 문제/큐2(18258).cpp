#include <cstdio>
#include <cstring>

#define MAX 2000000

class queue {
private:
	int arr[MAX] = { 0 };
	int findex;
	int rindex;
	int size;

public:
	queue() {
		findex = 0;
		rindex = 0;
		size = 0;
	}

	void push(int e) {
		arr[rindex++] = e;
		size++;
	}
	int pop() {
		if (isEmpty()) return -1;

		size--;
		return arr[findex++];
	}
	int getSize() {return size;}
	bool isEmpty() { return size == 0; }
	int front() {
		if (isEmpty()) return -1;
		return arr[findex];
	}
	int back() {
		if (isEmpty()) return -1;
		return arr[rindex - 1];
	}
};

int main(void) {
	int N;
	char command[10] = { 0 };
	int e;
	queue q;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", command);
		if (0 == strcmp(command, "push")) {
			scanf("%d", &e);
			q.push(e);
		}
		else if (0 == strcmp(command, "pop")) {
			printf("%d\n", q.pop());
		}
		else if (0 == strcmp(command, "size")) {
			printf("%d\n", q.getSize());
		}
		else if (0 == strcmp(command, "empty")) {
			printf("%d\n", q.isEmpty());
		}
		else if (0 == strcmp(command, "front")) {
			printf("%d\n", q.front());
		}
		else if (0 == strcmp(command, "back")) {
			printf("%d\n", q.back());
		}
	}
}