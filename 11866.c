#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

int queue[SIZE];
int front = 0, rear = 0;



int qfull() {
	if ((rear + 1) % SIZE == front)
		return 1;	//가득 차면 1
	return 0;
}

int qempty() {
	if (rear == front)
		return 1;	//비어있으면 1
	return 0;
}

void enqueue(int n) {	//삽입
	if (qfull() == 1) {
		return;
	}
	rear = (rear + 1) % SIZE;
	queue[rear] = n;
}

int dequeue() {			//삭제
	if (qempty() == 1) {
//		return -1;
	}
	front = (front + 1) % SIZE;
	return queue[front];
}

int main() {
	int n, k;
	int count = 0;
	int josephus[1001];
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		enqueue(i);	//front = 1 부터 들어감 (1~n까지)
	}
	while (count < n) {
		for (int j = 0; j < k - 1; j++) {
			enqueue(dequeue());
		}
		josephus[count++] = dequeue();
	}
	printf("<");
	for (int i = 0; i < count-1; i++) {
		printf("%d, ", josephus[i]);
	}
	printf("%d>", josephus[count-1]);
	return 0;
}
