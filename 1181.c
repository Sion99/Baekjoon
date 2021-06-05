#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word[20000][51];

void printArr(int n) {
	for (int i = 0; i < n; i++) {
		int result = strcmp(word[i], word[i + 1]);
		if (result != 0) {
			printf("%s\n", word[i]);
		}
	}
}
int compare(const void* A, const void* B) {
	if (strlen((char*)A) > strlen((char*)B)) {
		return 1;
	}
	else if (strlen((char*)A) < strlen((char*)B)) {
		return -1;
	}
	return strcmp((char*)A, (char*)B);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}
	qsort(word, n, sizeof(word[0]), compare);
	printArr(n);
}
