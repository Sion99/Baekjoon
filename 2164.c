#include <stdio.h>
#define MAX_SIZE 1000000
int queue[MAX_SIZE];

int front = 0;
int rear = 0;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		queue[i] = i;
	}
	front = 1;
	rear = n+1;
}
void push(int n) {
	queue[rear++] = n;
}
int pop() {
	return queue[front++];
}
void calc() {
	while (rear - front>1) {
		pop();
		if (rear - front == 1)
			break;
		int a = pop();
		push(a);
	}
	printf("%d", pop());
}

int main() {
	int n;
	scanf("%d", &n);
	init(n);
	calc();
}
