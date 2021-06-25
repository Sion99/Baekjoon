#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char stack[101];
int top = -1;

void push(char a) {
	if (top < 101) {
		stack[++top] = a;
	}
}

char pop() {
	if(top >=-1)
		return stack[top--];
}

int main() {
	char str[101];
	int result = 0;
	while (1) {
		scanf("%[^\n]s", str);
		getchar();
		if (strcmp(str, ".") == 0) {
			break;
		}
		result = 0;
		top = -1;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '[') {
				push(str[i]);
			}
			else if (str[i] == '(') {
				push(str[i]);
			}
			else if (str[i] == ')') {
				if (pop() != '(') {
					result = 1;
					break;
				}
			}
			else if (str[i] == ']') {
				if (pop() != '[') {
					result = 1;
					break;
				}
			}
		}
		if (top != -1) {
			result = 1;
		}
		if (result == 0) {
			printf("yes\n");
		}
		else if (result == 1) {
			printf("no\n");
		}
	}
	return 0;
}
