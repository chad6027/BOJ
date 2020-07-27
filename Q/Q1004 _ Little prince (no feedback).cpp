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