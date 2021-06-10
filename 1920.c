#include <stdio.h>
#include <stdlib.h>

int arr[100001];

int binsearch(int n, int k) {
	int start = 0;
	int end = n-1;
	int mid = (end + start) / 2;

	while (end - start >= 0) {
		if (arr[mid] == k) {
			return 1;
		}
		else if (arr[mid] <= k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = (end + start) / 2;
	}
	return 0;
}
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

int main() {
	int n, m, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		printf("%d\n", binsearch(n, k));
	}
}
