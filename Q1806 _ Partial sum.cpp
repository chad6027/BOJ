// Q1806 _ �κ� ��
// �������� �� ������ �����̴�.
// �ʹ� �������� �� �����Ͷ� �ڼ��� �ؼ��� ����.
// Ǯ ���� ������ Ǯ �� �־���.


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX_N = 10e+5 + 1;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int num[100001] = { 0 , };

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)cin >> num[i];
	int ans = INF, sum = 0;
	int start = 0, end = 0;
	while (end < n) {
		while (end < n && sum < s) {
			sum += num[end++];
		}
		while (start < end && sum >= s) {
			ans = min(ans, end - start);
			sum -= num[start++];
		}
	}
	if (ans == INF) cout << 0;
	else cout << ans;

	return 0;
}