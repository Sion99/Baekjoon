#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int stack[100001];
int arr[100001];
int ans[100001];
char sign[1000000];

int top = -1;

void push(int n) {
	if (top > 100001) {
		printf("NO");
		exit(EXIT_SUCCESS);
	}
	stack[++top] = n;
}

int pop() {
	return stack[top--];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int j = 0;
	int k = 0;
	int i = 1;

	while (j < n) {
		if (arr[j] == stack[top]) {
			ans[j++] = pop();
			sign[k++] = '-';
		}
		else {
			push(i++);
			sign[k++] = '+';
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != ans[i]) {
			result = 1;
			printf("NO");
			return 0;
		}
	}
	
	if (result == 0) {
		for (int i = 0; i < k; i++) {
			printf("%c\n", sign[i]);
		}
	}
}
