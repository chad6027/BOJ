#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INT_INF = 2147483647;
const int INF = 987654321;
const int MAX_N = 1e6 + 1;
const int MOD = 1e5;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll memo[101] = { 0, };
ll cost[101] = { 0, };
ll dp[10001] = { 0, };

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, m, MAX = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> memo[i];
	for (int i = 1; i <= n; ++i) cin >> cost[i];


	for (int i = 1; i <= n; ++i) {
		for (int j = 10001; j >= cost[i]; --j) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memo[i]);
		}
	}
	for (int i = 0; i < 10001; ++i) {
		if (dp[i] >= m) {
			cout << i << '\n';
			break;
		}
	}


	return 0;
}