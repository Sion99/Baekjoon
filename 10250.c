#include <stdio.h>

void calc(h, w, n) {
	int count = 0;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			count++;
			if (n == count) {
				printf("%d%02d\n", j, i);
			}
		}
	}
}

int main() {
	int t, h, w, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		calc(h, w, n);
	}

}