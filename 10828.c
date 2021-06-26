#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[10001];
int top = -1;

void push(int x) {
	stack[++top] = x;
}

int pop() {
	if (top == -1) {
		return -1;
	}
	return stack[top--];
}

int size() {
	return top + 1;
}

int empty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int topp() {
	if (top == -1)
		return -1;
	else 
		return stack[top];
}

int main() {
	int n, x;
	scanf("%d", &n);
	char ch[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		if (strcmp(ch, "push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(ch, "top") == 0) {
			printf("%d\n", topp());
		}
		else if (strcmp(ch, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(ch, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(ch, "pop") == 0) {
			printf("%d\n", pop());
		}
	}
}
