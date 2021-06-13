#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
if(!((p) = malloc(s))){\
fprintf(stderr, "insufficient memory");\
exit(EXIT_FAILURE);\
}
typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};

int tmp = 0;
int* arr1;
listPointer* arr;
listPointer ans;
void put(int a, listPointer* first) {
	listPointer tmpP2, tmpP = *first;
	if (tmpP == NULL || a < (*first)->data) {
		MALLOC(tmpP2, sizeof(*tmpP2));
		tmpP2->link = *first;
		tmpP2->data = a;
		*first = tmpP2;
	}
	else {
		while (tmpP->link != NULL && tmpP->link->data < a) {
			tmpP = tmpP->link;
		}
		if (tmpP->link == NULL) {
			MALLOC(tmpP2, sizeof(*tmpP2));
			tmpP->link = tmpP2;
			tmpP2->link = NULL;
			tmpP2->data = a;
		}
		else {
			MALLOC(tmpP2, sizeof(*tmpP2));
			tmpP2->link = tmpP->link;
			tmpP->link = tmpP2;
			tmpP2->data = a;
		}
	}
}
void dfs(listPointer first) {
	while (first) {
		if (arr1[first->data] == 0) {
			printf("%d ", first->data + 1);
			arr1[first->data] = 1;
			dfs(arr[first->data]);
		}
		if (first->link) {
			first = first->link;
		}
		else {
			break;
		}
	}
}
int queue[1001];
int front = 0;
int rear = 0;
void bfs(listPointer first) {
	while (first) {
		if (arr1[first->data] == 0) {
			printf("%d ", first->data + 1);
			arr1[first->data] = 1;
			queue[rear++] = first->data;
		}
		if (first->link) {
			first = first->link;
		}
		else {
			break;
		}
	}
}
int main() {
	int n, m, v;
	int v1, v2, firN;
	scanf("%d %d %d", &n, &m, &v);
	MALLOC(arr, sizeof(listPointer) * n);
	MALLOC(arr1, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = NULL;
		arr1[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		firN = v2 - 1;
		put(v2 - 1, &arr[v1 - 1]);
		put(v1 - 1, &arr[v2 - 1]);
	}
	arr1[v-1] = 1;
	printf("%d ", v);
	dfs(arr[v-1]);
	printf("\n");

	for (int i = 0; i < n; i++) {
		arr1[i] = 0;
	}
	queue[rear++] = v-1;
	arr1[v-1] = 1;
	printf("%d ", v);
	while (front < rear) {
		bfs(arr[queue[front++]]);
	}
	for (int i = 0; i < n; i++) {
		while (arr[i] != NULL) {
			listPointer fr = arr[i];
			arr[i] = arr[i]->link;
			free(fr);
		}
	}
	free(arr);
}
