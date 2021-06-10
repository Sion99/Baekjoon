#include <stdio.h>
#include <stdlib.h>

int maxheap[100001];
int maxsize = 0;
int minheap[100001];
int minsize = 0;

void mininsert(int n) {
	int i;
	i = ++minsize;
	while ((i != 1) && n <= minheap[i / 2]) {
		minheap[i] = minheap[i / 2];
		i /= 2;
	}
	minheap[i] = n;
}

void maxinsert(int n) {
	int i;
	i = ++maxsize;
	while ((i != 1) && n >= maxheap[i / 2]) {
		maxheap[i] = maxheap[i / 2];
		i /= 2;
	}
	maxheap[i] = n;
}

int minpop() {
	int parent, child;
	int item, temp;
	if (minsize == 0) {
		if (maxsize != 0) {
			return maxpop();
		}
		return 0;
	}
	item = minheap[1];
	temp = minheap[minsize--];
	parent = 1;
	child = 2;
	while (child <= minsize) {
		if ((child < minsize) && (minheap[child] > minheap[child + 1]))
			child++;
		if (temp <= minheap[child])
			break;
		minheap[parent] = minheap[child];
		parent = child;
		child *= 2;
	}
	minheap[parent] = temp;
	return item;
}

int maxpop() {
	int parent, child;
	int item, temp;
	if (maxsize == 0) {
		if (minsize != 0) {
			return minpop();
		}
		return 0;
	}
	item = maxheap[1];
	temp = maxheap[maxsize--];
	parent = 1;
	child = 2;
	while (child <= maxsize) {
		if ((child < maxsize) && (maxheap[child] < maxheap[child + 1]))
			child++;
		if (temp >= maxheap[child])
			break;
		maxheap[parent] = maxheap[child];
		parent = child;
		child *= 2;
	}
	maxheap[parent] = temp;
	return item;
}

int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x > 0) {
			mininsert(x);
		}
		else if (x < 0) {
			maxinsert(x);
		}
		else {
			if (abs(maxheap[1]) < abs(minheap[1])) {

				printf("%d\n", maxpop());
			}
			else if (abs(maxheap[1]) > abs(minheap[1])) {
				printf("%d\n", minpop());
			}
			else {
				printf("%d\n", maxpop());
			}
		}
	}
}
