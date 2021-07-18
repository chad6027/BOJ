// Q1062 ����ħ
// ����Ž������.
// ������ Ǯ�ٺ��� N�� 50�����̸� ����Ž���� ����� ����Ҹ��� �� ����.
//
// ����Ž���� �ϸ� Ǯ���� �����̱� ������ ������ ����.

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

	if (k < 5) { // 5�� �̸��̸� �⺻������ �о���ϴ� ���ĺ����� ���д´�.
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