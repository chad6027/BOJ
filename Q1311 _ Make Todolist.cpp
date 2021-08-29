// Q1311 _ 할 일 정하기1

// 비트 마스킹 + dp 로 해결하는 문제다.
// dp배열이 20 * 2^20 이라 메모리가 터질까 걱정했는데 그런 상황은 발생하지 않았다.
// 최근에 트리 dp 문제들을 많이 풀어서 그런지 손쉽게 해결할 수 있었다.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 1e4 + 1;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int work[21][21] = { 0, };
int dp[21][1 << 20] = { 0, };
int n;

int dfs(int cur, int state) {

	int& ret = dp[cur][state];
	if (ret != -1) return ret;
	if (cur == n) return 0;
	ret = INF;
	for (int i = 0; i < n; ++i) {
		if (!(state & (1 << i))) {
			ret = min(ret, dfs(cur + 1, state | (1 << i)) + work[cur][i]);
		}
	}
	return ret;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> work[i][j];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0);

	return 0;
}