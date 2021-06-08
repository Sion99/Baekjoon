#include <stdio.h>

int getF(int n) {
	if (n == 0)
		return 1;
	int f = 1;
	int num = 1;
	while (num != n) {
		f *= num++;
	}
	f *= n;
	return f;
}
int calc(int n, int k) {
	return getF(n) / (getF(k) * getF(n - k));
}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
//	printf("%d %d\n", getF(n), getF(k));
	printf("%d",calc(n, k));
}
