// Q1004 터렛

// 어렵지 않은 문제였다.

// 입력 받은 각 원에 대하여 출발점과 도착점이 그 원 안에 동시에 존재하거나, 그 밖에 있다면 원을 지나치지 않아도 되기 때문에
// 출발점과 도착점이 각각 하나는 원 안에, 하나는 원 밖에 존재하는 경우만 count해서 출력해준다.

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, n;
	cin >> T;
	int start_x, start_y, des_x, des_y;
	int x, y, r, ans;
	bool start, des;
	while (T--) {
		ans = 0;

		cin >> start_x >> start_y >> des_x >> des_y;
		cin >> n;
		for (int i = 0; i < n; i++) {
			start = false;
			des = false;
			cin >> x >> y >> r;
			if ((start_x - x) * (start_x - x) + (start_y - y) * (start_y - y) < r * r)
				start = true;
			if ((des_x - x) * (des_x - x) + (des_y - y) * (des_y - y) < r * r)
				des = true;

			if ((start && !des) || (!start && des)) {
				ans++;
			}

		}

		cout << ans << '\n';



	}

	return 0;
}