// Q1976 여행 가자

// 평범한 union find 문제다
// 여행을 가고자 하는 도시가 모두 이어져 있는지만 확인하면 된다. 물론 union find를 이용해서

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int MAX_N = 1e5 + 1;
const int MOD = 1e+9;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool isConnected[201][201] = { 0 , };
int anc[201] = { 0, };
set<int> plan;

int find_root(int cur) {
	if (cur == anc[cur]) return cur;
	else return anc[cur] = find_root(anc[cur]);
}

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) anc[i] = i;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		cin >> isConnected[i][j];
		if (isConnected[i][j]) {
			int root_i = find_root(i);
			int root_j = find_root(j);
			anc[root_i] = min(root_i, root_j);
			anc[root_j] = min(root_i, root_j);
		}
	}

	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		plan.insert(tmp);
	}
	int ans = find_root(*plan.begin());
	for (auto& city : plan) {
		if (ans != find_root(city)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}