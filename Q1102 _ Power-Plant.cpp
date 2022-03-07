// 1102 발전소
// dp, bit마스킹

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INT_INF = 2147483647;
const int INF = 987654321;
const int MAX_N = 1e5 + 1;
const int MOD = 1e5;
int dp[1 << 17] = { 0, };
int cost[17][17] = { 0, };
int n, atLeast, total;

int turnOn(int visited) {

	if (bitset<17>(visited).count() >= atLeast) {
		return 0;
	}

	if (dp[visited] != -1) return dp[visited];

	dp[visited] = INF;

	for (int off = 0; off < n; ++off) {

		if ((visited & (1 << off))) {
			for (int j = 0; j < n; ++j) {
				if (!(visited & (1 << j))) {
					dp[visited] = min(dp[visited], turnOn(visited | (1 << j)) + cost[off][j]);
				}
			}
		}
	}

	return dp[visited];
}




int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	total = 1 << n - 1;
	for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) cin >> cost[i][j];

	string str;
	cin >> str;
	cin >> atLeast;
	int startState = 0;
	for (int i = 0; i < str.size(); ++i) if (str[i] == 'Y') startState |= (1 << i);

	if (atLeast == 0) cout << 0;
	else {
		int result = turnOn(startState);

		if (result == INF) cout << -1;
		else cout << result;

	}

	return 0;
}