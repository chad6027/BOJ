// 1799�� ���

// N-Queen ����ó�� ��Ʈ��ŷ�ϴ� �����̴�.
// �ٽ��� �밢���� �������� �ϳ��� ä���־��ָ� �Ǵµ�, �Ѱ��� �ɸ����� �ִ�.
// ������ x�� �밢������ ����� ä���� ���ϴ� ��쿣, x+1�� �밢������ �� ���� ����.
// �ذ�å���� (������� ���� ��� ���� + ���� �밢���� ����)�� ���� ���� ���� �ִ� �亸�� ũ�ٸ�,
// �� Ž���غ� �ʿ䰡 �ִٰ� �Ǵ��ϰ� x+1�� �밢������ �Ѿ��.


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
	// /���� \���� �밢���� �÷��� ����
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