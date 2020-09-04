#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, N, M;
	long long ans;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		ans = 1;
		for (int i = 1; i <= N; i++) {
			ans *= M--;
			ans /= i;
		}

		cout << ans << '\n';
	}
	return 0;
}