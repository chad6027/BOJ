#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int T,x,y;
	long long d, tmp, mid;
	cin >> T;

	while (T--) {
		cin >> x >> y;
		d = long long(y - x);
		tmp = sqrt(d);
		
		mid = (pow(tmp + 1, 2) + pow(tmp, 2)) / 2;
		tmp = pow(tmp, 2);
		if (d == tmp) {
			tmp = sqrt(d);
			cout << 2 * tmp - 1 << '\n';
		}
		else if (d <= mid) {
			tmp = sqrt(d);
			cout << tmp * 2 << '\n';
		}
		else {
			tmp = sqrt(d);
			cout << tmp * 2 + 1 << '\n';
		}

	}

	return 0;
}