#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INT_INF = 2147483647;
const int INF = 987654321;
const int MAX_N = 2 * 1e3 + 1;
const int MOD = 1e5;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int dp[4001][4001] = { 0, };

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	cin >> a >> b;

	int ans = 0;
	for (int i = 1; i <= a.size(); ++i) {
		for (int j = 1; j <= b.size(); ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;


	return 0;
}