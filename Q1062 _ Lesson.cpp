// Q1062 가르침
// 완전탐색문제.
// 백준을 풀다보니 N이 50이하이면 완전탐색을 충분히 고려할만한 것 같다.
//
// 완전탐색만 하면 풀리는 문제이기 때문에 설명은 생략.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX = 10e+8;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int each_alp[50][26] = { 0, };
bool visited[26] = { 0, };

int DFS(int cur, int k, int& total_n, int& total_k) {
	int ans = 0;
	if (k == total_k) {

		for (int i = 0; i < total_n; ++i) {
			bool canRead = true;
			for (int j = 0; j < 26; ++j) {
				if (each_alp[i][j] && !visited[j]) {
					canRead = false;
					break;
				}
			}
			if (canRead) ans++;
		}
		return ans;
	}



	for (int next = cur; next < 26; ++next) {
		if (!visited[next]) {
			visited[next] = true;
			ans = max(ans, DFS(next, k + 1, total_n, total_k));
			visited[next] = false;
		}
	}

	return ans;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < str.size(); ++j) {
			each_alp[i][str[j] - 'a'] = true;
		}
	}

	if (k < 5) { // 5개 미만이면 기본적으로 읽어야하는 알파벳조차 못읽는다.
		cout << 0 << '\n';
		return 0;
	}
	else if (k == 26) {
		cout << n << '\n';
		return 0;
	}

	visited[0] = visited['c' - 'a'] = visited['i' - 'a'] = visited['n' - 'a'] = visited['t' - 'a'] = true;

	k -= 5;
	cout << DFS(0, 0, n, k);


	return 0;
}