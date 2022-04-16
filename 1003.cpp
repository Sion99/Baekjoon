#include <iostream>
using namespace std;

typedef struct fibo {
	int zero;
	int one;
}fibo;

int main() {
	int t, n;
	cin >> t;
	fibo arr[41];
	arr[0].zero = 1;
	arr[0].one = 0;
	arr[1].zero = 0;
	arr[1].one = 1;
	arr[2].zero = 1;
	arr[2].one = 1;
	for (int i = 3; i < 41; i++) {
		arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
		arr[i].one = arr[i - 1].one + arr[i - 2].one;
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n].zero << " " << arr[n].one << "\n";
	}
}
