// Q1039 _ ��ȯ

// ����Ž������.
// N�� ������ 1,000,000���� ����Ͽ� �ߺ��� �����ϸ� 2�ʶ�� �ð��ȿ� ����� �� �� �ִ� �����̴�.
// x������ x + 1������ �Ѿ �� �ߺ��� �������ִ°� �ٽ��̴�.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 2147483647;
const int MAX_N = 10e+4 + 1;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int stringToi(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); ++i) {
		sum += (s[i] - '0');
		if (i != s.size() - 1) sum *= 10;
	}
	return sum;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string n;
	int k;
	cin >> n >> k;
	int start = stringToi(n);
	if (start == 1000000) {
		cout << 1000000 << '\n';
		return 0;
	}
	if (n.size() == 1 || (n.size() == 2 && start % 10 == 0)) {
		cout << -1 << '\n';
		return 0;
	}
	queue<string> que;
	set<string> s;
	que.push(n);
	for (int i = 1; i <= k; ++i) {
		int que_sz = que.size();
		s.clear();
		while (que_sz--) {
			string num = que.front();
			que.pop();

			if (s.find(num) == s.end()) s.insert(num);
			else continue;

			for (int front = 0; front < n.size(); ++front) {
				for (int back = front + 1; back < n.size(); ++back) {
					if (front == 0 && num[back] == '0') continue;
					swap(num[front], num[back]);
					que.push(num);
					swap(num[front], num[back]);
				}
			}
		}
	}
	string ans = "";
	while (!que.empty()) {
		ans = max(ans, que.front());
		que.pop();
	}
	cout << ans;

	return 0;
}