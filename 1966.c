#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct element{
	int data;
	int index;
}element;
element queue[10000];
int front = 0;
int rear = 0;

void push(element n) {
	queue[front++] = n;
}

element pop() {
	return queue[rear++];
}

void clear() {
	memset(&queue, 0, sizeof(element));
	front = 0;
	rear = 0;
}

int calc(int n, int m) {
	element memory = queue[m];
	int count = 1;
	int num = n;
	int collision = 0;
	while (1) {
		int result = 0;
		for (int j = rear + 1; j < num; j++) {
			if (queue[rear].data < queue[j].data) {	//큰 값이 있는지 체크
				push(pop());
				collision++;
				result = 1;
				break;
			}
		}
		num += collision;
		collision = 0;
		if (result == 0) {
			if (memory.data == queue[rear].data && memory.index == queue[rear].index) {
				return count;
			}
			else {
				pop();
				count++;
			}
		}
	}
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			element temp;
			int doc;
			scanf("%d", &doc);
			temp.data = doc;
			temp.index = j;
			push(temp);
		}
		printf("%d\n", calc(n, m));
		clear();
	}
}
