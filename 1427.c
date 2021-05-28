#include <stdio.h>
#include <string.h>

int arr[11];
int k = 1;
void calc(int n) {
	int num = n;
	while (num != 0) {
		arr[k++] = num % 10;
		num /= 10;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	calc(n);
	int temp;
	for (int i = 0; i < k-1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < k-1; i++) {
		printf("%d", arr[i]);
	}
}