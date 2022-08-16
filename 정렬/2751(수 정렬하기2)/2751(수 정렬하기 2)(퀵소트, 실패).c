#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quickSort(int st, int end, int* lst){
	int pivot;
	int sp, ep;
	int temp;

	if (st >= end)
		return;

	pivot = lst[(st + end) / 2];
	sp = st;
	ep = end;
	while (sp <= ep) {
		while (lst[sp] < pivot)
			sp++;
		while (lst[ep] > pivot)
			ep--;
		if (sp > ep)
			break;
		temp = lst[sp];
		lst[sp] = lst[ep];
		lst[ep] = temp;
		sp += 1;
		ep -= 1;
	}
	quickSort(st, ep, lst);
	quickSort(sp, end, lst);
}


int main(void) {
	int N;
	int* lst;

	scanf("%d", &N);
	lst = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &lst[i]);
	quickSort(0, N - 1, lst);
	for (int i = 0; i < N; i++)
		printf("%d\n", lst[i]);
	free(lst);
	return 0;
}