// Q20040 _ Cycle Game
// union find를 이용해서 해결하는 문제
// 구현 자체는 간단해서 해설은 생략
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e5 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int anc[500001];

int find_root(int cur) {
	if (cur == anc[cur]) return cur;
	else return anc[cur] = find_root(anc[cur]);
}

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) anc[i] = i;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		int root_a = find_root(a);
		int root_b = find_root(b);

		if (root_a == root_b) {
			ans = i;
			break;
		}
		anc[root_a] = min(root_a, root_b);
		anc[root_b] = min(root_a, root_b);
	}
	cout << ans;
	return 0;
}