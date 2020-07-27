#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	int first_x, first_y, first_r, second_x, second_y, second_r;
	int d, r;
	//double d_d, d_r;
	while (T--) {
		cin >> first_x >> first_y >> first_r >> second_x >> second_y >> second_r;

		if (first_r < second_r) {
			swap(first_x, second_x);
			swap(first_y, second_y);
			swap(first_r, second_r);
		}

		d = (first_x - second_x) * (first_x - second_x) + (first_y - second_y) * (first_y - second_y);
		r = first_r + second_r;

		if (d == 0) {
			if (first_r == second_r) {
				cout << -1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		else {
			if ((first_r + second_r) * (first_r + second_r) < d || d < (first_r - second_r) * (first_r - second_r) ) {
				cout << 0 << '\n';
			}
			else if ((first_r + second_r) * (first_r + second_r) == d || (first_r - second_r) * (first_r - second_r) == d) {
				cout << 1 << '\n';
			}
			else if ((first_r - second_r) * (first_r - second_r) < d && d < (first_r + second_r) * (first_r + second_r) ){
				cout << 2 << '\n';
			}
		}
	}




	return 0;
}