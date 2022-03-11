#include <cstdio>
#include <cstdlib>
#define HSIZE 1000001
using namespace std;



class MyHeap {
private:
	int	*heap;
	size_t tsize;
	size_t length;
	int (*compare)(int, int);

	static int init_compare(int a, int b)
	{
		return (a > b);
	}

	static void swap(int& a, int& b)
	{
		int temp;
		
		temp = a;
		a = b;
		b = temp;
	}

	void down_top()
	{
		size_t temp;
		size_t parent;

		temp = length;
		while (temp > 1)
		{
			parent = temp / 2;
			if (compare(heap[parent], heap[temp]))
				swap(heap[temp], heap[parent]);
			temp = parent;
		}
	}

	void top_down()
	{
		size_t temp;
		size_t left;
		size_t right;

		temp = 1;
		while (temp <= length / 2)
		{
			left = temp * 2;
			right = temp * 2 + 1;
			if (right <= length)
			{
				if (compare(heap[left], heap[right]))
				{
					if (compare(heap[temp], heap[right]))
					{
						swap(heap[temp], heap[right]);
						temp = right;
					}
					else
						break;
				}
				else 
				{
					if (compare(heap[temp], heap[left]))
					{
						swap(heap[temp], heap[left]);
						temp = left;
					}
					else
						break;
				}
			}
			else
			{
				if (compare(heap[temp], heap[left]))
				{
					swap(heap[temp], heap[left]);
					temp = left;
				}
				else
					break;
			}
		}
	}
public:
	MyHeap(size_t hsize = HSIZE, int (*cmp)(int,int) = init_compare)
	{
		this->tsize = hsize;
		this->length = 0;
		this->compare = cmp;
		heap = (int *)malloc(sizeof(int) * this->tsize);
	}
	~MyHeap()
	{
		free(heap);
	}

	int isEmpty()
	{
		return (this->length <= 0);
	}

	void push(int e)
	{
		heap[++length] = e;
		down_top();
	}

	int pop()
	{
		int rt;

		if (isEmpty())
		{
			printf("pop Error: empty heap\n");
			return -1;
		}
		rt = heap[1];
		heap[1] = heap[length--];
		top_down();
		return rt;
	}
	int top() 
	{
		if (isEmpty())
		{
			printf("top Error: empty heap\n");
			return -1;
		}
		return heap[length];
	}
};

int main(void)
{
	int n;
	int val;
	MyHeap h;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		h.push(val);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", h.pop());
}