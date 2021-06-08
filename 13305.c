#include <stdio.h>

long long price[100001];
long long distance[100001];

int main() {
	int n;
	long long totalp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &distance[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}
	int min = 1000000000;
	for (int i = 0; i < n-1; i++) {	//price 기준으로 보기!
		if (price[i] < min) {
			min = price[i];
		}
		totalp += min * distance[i];
	}
	printf("%lld", totalp);
}
