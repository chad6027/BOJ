// 1799번 비숍

// N-Queen 문제처럼 백트래킹하는 문제이다.
// 핵심은 대각선을 기준으로 하나씩 채워넣어주면 되는데, 한가지 걸림돌이 있다.
// 임의의 x번 대각선에서 비숍을 채우지 못하는 경우엔, x+1번 대각선으로 갈 일이 없다.
// 해결책으로 (현재까지 놓은 비숍 개수 + 남은 대각선의 개수)가 현재 내가 갖고 있는 답보다 크다면,
// 더 탐색해볼 필요가 있다고 판단하고 x+1번 대각선으로 넘어간다.


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 1e5;
const int MOD = 1e9 + 3;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool diag_l[31];
bool diag_r[31];
int board[11][11];
int n;
int ans = 0;

void setFlag(int& x, int& y, bool flag) {
	// /방향 \방향 대각선들 플레그 설정
	diag_l[x + y] = diag_r[y - x + 10] = flag;
}

void recur(int sum, int& cnt) {

	ans = max(ans, cnt);
	if (sum == 2 * n) {
		return;
	}

	for (int x = 0; x < n; ++x) {
		int y = sum - x;
		if (y < 0 || y >= n) continue;

		if (!board[x][y] || diag_l[x + y] || diag_r[y - x + 10]) continue;

		setFlag(x, y, true);
		cnt++;
		recur(sum + 1, cnt);
		setFlag(x, y, false);
		cnt--;
	}

	if (cnt + (2 * n - 1 - (sum + 1)) > ans) recur(sum + 1, cnt);
}


int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j];

	recur(0, cnt);

	cout << ans;

	return 0;
}