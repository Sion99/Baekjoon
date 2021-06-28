#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int x;
	int y;
}element;
element arr[100001];

int compare(const void* a, const void* b) {
	element num1 = *(element*)a;
	element num2 = *(element*)b;

	if (num1.y < num2.y)
		return -1;
	if (num1.y > num2.y)
		return 1;
	if (num1.x < num2.x)
		return -1;
	if (num1.x > num2.x)
		return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(element), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}
