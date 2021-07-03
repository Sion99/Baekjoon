#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10001

int deque[MAX];
int front = 0;
int rear = 1;
int size = 0;

void pushf(int x) {
	deque[front] = x;
	front = ((front - 1) + MAX) % MAX;
	size++;
}

void pushb(int x) {
	deque[rear] = x;
	rear = (rear + 1) % MAX;
	size++;
}

int dfront() {
	if (size == 0) {
		return -1;
	}
	int temp = (front + 1) % MAX;
	return deque[temp];
}

int dback() {
	if (size == 0) {
		return -1;
	}
	int temp = ((rear - 1) + MAX) % MAX;
	return deque[temp];
}

int popf() {
	if (size == 0) {
		return -1;
	}
	int f = dfront();
	front = (front + 1) % MAX;
	size--;
	return f;
}

int popb() {
	if (size == 0)
		return -1;
	int b = dback();
	rear = ((rear - 1) + MAX) % MAX;
	size--;
	return b;
}

int dsize() {
	return size;
}

int dempty() {
	if (size == 0)
		return 1;
	return 0;
}

int main() {
	int n, x;
	char order[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", order);
		if (strcmp(order, "push_front") == 0) {
			scanf("%d", &x);
			pushf(x);
		}
		else if (strcmp(order, "push_back") == 0) {
			scanf("%d", &x);
			pushb(x);
		}
		else if (strcmp(order, "front") == 0) {
			printf("%d\n", dfront());
		}
		else if (strcmp(order, "back") == 0) {
			printf("%d\n", dback());
		}
		else if (strcmp(order, "size") == 0) {
			printf("%d\n", dsize());
		}
		else if (strcmp(order, "empty") == 0) {
			printf("%d\n", dempty());
		}
		else if (strcmp(order, "pop_front") == 0) {
			printf("%d\n", popf());
		}
		else if (strcmp(order, "pop_back") == 0) {
			printf("%d\n", popb());
		}
	}
	return 0;
}
