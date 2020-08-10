// Q1002 Turret

// 두 원이 만나는 조건을 알아야 해결할 수 있는 문제였다.
// 내 생각대로 했다가 두번정도 틀리고 구글에 두 원이 만나는 조건 검색하고 correct 받아냄.
// 수학에 관한 코딩을 검색해서 풀었다는 점이 너무 짜증나지만 나의 부족함이었기 때문에 인정하고 넘겼다.

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
	
	while (T--) {
		cin >> first_x >> first_y >> first_r >> second_x >> second_y >> second_r;
		
		// first가 더 큰 원이 되게 swap
		if (first_r < second_r) {
			swap(first_x, second_x);
			swap(first_y, second_y);
			swap(first_r, second_r);
		}
		// d = 두 원의 중심 사이의 거리의 제곱
		d = (first_x - second_x) * (first_x - second_x) + (first_y - second_y) * (first_y - second_y);
		// r = 두 원의 반지름의 합
		r = first_r + second_r;

		// 중심이 같을 때
		if (d == 0) {
			if (first_r == second_r) {
				cout << -1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		// 중심이 같지 않을 때
		else {
			// 중심 사이의 거리가 반지름의 합보다 크거나 반지름의 차보다 작을 때, 두 원은 만나지 않는다.
			if ((first_r + second_r) * (first_r + second_r) < d || d < (first_r - second_r) * (first_r - second_r) ) {
				cout << 0 << '\n';
			}
			// 중심 사이의 거리가 반지름의 합과 같거나 반지름의 차와 같을 때, 두 원은 한 점에서 만난다.
			else if ((first_r + second_r) * (first_r + second_r) == d || (first_r - second_r) * (first_r - second_r) == d) {
				cout << 1 << '\n';
			}
			// 중심 사이의 거리가 반지름의 합보다 작거나 반지름의 차보다 클 때, 두 원은 두 점에서 만난다.
			else if ((first_r - second_r) * (first_r - second_r) < d && d < (first_r + second_r) * (first_r + second_r) ){
				cout << 2 << '\n';
			}
		}
	}




	return 0;
}