#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1001];

int main() {
	int n, min, index, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		min = 9999;
		for (int j = i; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}
