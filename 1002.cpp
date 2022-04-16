#include <iostream>
using namespace std;


int main() {
	int t, x1, x2, y1, y2, r1, r2;
	int d, a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		a = (r1 - r2) * (r1 - r2);
		b = (r1 + r2) * (r1 + r2);

		if (d == 0) {
			if (a == 0)
				cout << "-1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (d == a || d == b)
			cout << "1" << "\n";
		else if (a < d && d < b)
			cout << "2" << "\n";
		else
			cout << "0" << "\n";
	}
}
