#include <stdio.h>
#include <stdlib.h>

typedef struct size {
	int height;
	int weight;
}size;

size arr[55];
int rank[55];

void grade(int n) {	//자기 위에 몇명이 있나?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].height > arr[j].height && arr[i].weight > arr[j].weight) {	//i보다 j의 덩치가 더 클때
				rank[j]++;
			}
		}
	}
}

void printArr(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", rank[i]);
	}
}


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].weight, &arr[i].height);
		rank[i] = 1;
	}
	grade(n);
	printArr(n);
}
