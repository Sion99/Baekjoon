#include <stdio.h>
#include <stdlib.h>

int heap[1000001];
int size = 0;

void push(int n) {
	int i = 0;
	i = ++size;
	while ((i != 1) && (n < heap[i / 2])) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = n;
}

int pop() {
	int parent, child;
	int item, temp;
	item = heap[1];
	temp = heap[size--];
	parent = 1;
	child = 2;
	while (child <= size) {
		if ((child < size) && (heap[child] > heap[child + 1]))
			child++;
		if (temp <= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		push(m);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", pop());
	}
}
